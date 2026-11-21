#!/usr/bin/env python3
"""Report-only normalization: drop weak functions the linker discards.

Usage:
  python3 tools/strip_discarded_weak.py <compiled.o> <target.o> <out.o>
  python3 tools/strip_discarded_weak.py --list <pairs.txt>   (lines: src target out)

CodeWarrior emits out-of-line weak copies of inline functions (typically
destructors named by exception actions) in every object that needs them.
MWLD keeps one definition and discards the others together with their
exception-table records, so the linked executable contains none of the
duplicate bytes.  objdiff compares unlinked objects, so a unit carrying such
a copy reports its extab/extabindex as different even though the linked
bytes are identical.

This tool writes a copy of the compiled object without the weak functions
that the original-side (target) object does not contain: their .text bytes,
the extabindex records pointing at them and the extab records those use are
removed, later offsets are shifted, and references to the removed functions
become references to undefined symbols of the same name (which is how the
linker resolves them).  The object used for linking is never modified; the
DOL hash check remains the acceptance test.
"""
import os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from elfmini import Elf  # noqa: E402


def strip(src, target, out):
    e = Elf(src)
    t = Elf(target)
    tnames = {s["name"] for s in t.symbols if s["type"] == 2}
    text_idx = [i for i, s in enumerate(e.sections) if s["name"] == ".text"]
    weak = [s for s in e.symbols if s["type"] == 2 and s["bind"] == 2 and s["shndx"] in text_idx
            and s["name"] not in tnames]
    if not weak:
        open(out, "wb").write(open(src, "rb").read())
        return 0
    removed = {}  # section index -> list of (start, end)

    def add(idx, a, b):
        removed.setdefault(idx, []).append((a, b))

    wnames = {w["name"] for w in weak}
    for w in weak:
        add(w["shndx"], w["value"], w["value"] + w["size"])
    xi = e.section_index("extabindex")
    xt = e.section_index("extab")
    if xi is not None:
        data = e.data(xi)
        for off in range(0, len(data), 12):
            r0 = e.reloc_at(xi, off)
            if not r0 or not r0["sym"]:
                continue
            sym = r0["sym"]
            hit = sym["name"] in wnames
            if not hit and sym["type"] == 3:
                tgt = sym["value"] + r0["addend"]
                hit = any(w["shndx"] == sym["shndx"] and w["value"] <= tgt < w["value"] + w["size"] for w in weak)
            if not hit:
                continue
            add(xi, off, off + 12)
            r8 = e.reloc_at(xi, off + 8)
            if r8 and xt is not None:
                start = r8["sym"]["value"] + r8["addend"]
                ends = []
                for o2 in range(0, len(data), 12):
                    rr = e.reloc_at(xi, o2 + 8)
                    if rr:
                        v = rr["sym"]["value"] + rr["addend"]
                        if v > start:
                            ends.append(v)
                ends += [s["value"] for s in e.symbols if s["shndx"] == xt and s["value"] > start and s["type"] != 3]
                end = min(ends) if ends else e.sections[xt]["size"]
                add(xt, start, end)

    def shift(idx, off):
        """Map an old offset to the new one; None if inside a removed range."""
        d = 0
        for a, b in sorted(removed.get(idx, [])):
            if a <= off < b:
                return None
            if off >= b:
                d += b - a
        return off - d

    def new_size(idx):
        return e.sections[idx]["size"] - sum(b - a for a, b in removed.get(idx, []))

    raw = e.d
    # symbols
    symtab_idx = next(i for i, s in enumerate(e.sections) if s["type"] == 2)
    st = e.sections[symtab_idx]
    nsyms = bytearray(raw[st["offset"]:st["offset"] + st["size"]])
    for i, s in enumerate(e.symbols):
        o = i * 16
        nm, val, size, info, other, shndx = struct.unpack(">IIIBBH", nsyms[o:o + 16])
        if shndx in removed and s["type"] != 3:
            nv = shift(shndx, val)
            if nv is None or s["name"] in wnames:
                if s["bind"] in (1, 2) and s["name"]:
                    # becomes an undefined global reference
                    struct.pack_into(">IIIBBH", nsyms, o, nm, 0, 0, (1 << 4) | 0, other, 0)
                else:
                    # removed local record symbol: neutral absolute no-type entry
                    struct.pack_into(">IIIBBH", nsyms, o, nm, 0, 0, (0 << 4) | 0, other, 0xFFF1)
            else:
                struct.pack_into(">IIIBBH", nsyms, o, nm, nv, size, info, other, shndx)
    # section data and relocations
    newdata = {}
    for idx in removed:
        d = e.data(idx)
        keep = bytearray()
        pos = 0
        for a, b in sorted(removed[idx]):
            keep += d[pos:a]
            pos = b
        keep += d[pos:]
        newdata[idx] = bytes(keep)
    for i, s in enumerate(e.sections):
        if s["type"] != 4:
            continue
        tgt_sec = s["info"]
        out_rel = bytearray()
        for k in range(s["size"] // 12):
            o = s["offset"] + k * 12
            off, info, add_ = struct.unpack(">IIi", raw[o:o + 12])
            symi = info >> 8
            sym = e.symbols[symi] if symi < len(e.symbols) else None
            if tgt_sec in removed:
                no = shift(tgt_sec, off)
                if no is None:
                    continue
                off = no
            if sym and sym["type"] == 3 and sym["shndx"] in removed:
                na = shift(sym["shndx"], add_)
                add_ = na if na is not None else 0
            out_rel += struct.pack(">IIi", off, info, add_)
        newdata[i] = bytes(out_rel)
    newdata[symtab_idx] = bytes(nsyms)

    # rewrite the file: ELF header, then sections in order, then headers
    ehdr = bytearray(raw[:0x34])
    shentsize, shnum, shstrndx = struct.unpack(">HHH", raw[0x2E:0x34])
    body = bytearray(raw[:0x34])
    offsets, sizes = [], []
    for i, s in enumerate(e.sections):
        if i == 0:
            offsets.append(0)
            sizes.append(0)
            continue
        content = newdata.get(i)
        if content is None:
            content = b"" if s["type"] == 8 else raw[s["offset"]:s["offset"] + s["size"]]
        size = len(content) if s["type"] != 8 else (new_size(i) if i in removed else s["size"])
        al = max(s["align"], 1)
        while len(body) % al:
            body += b"\0"
        offsets.append(len(body))
        sizes.append(size)
        if s["type"] != 8:
            body += content
    while len(body) % 4:
        body += b"\0"
    shoff = len(body)
    for i in range(shnum):
        o = e.shoff + i * shentsize
        hdr = bytearray(raw[o:o + shentsize])
        if i:
            struct.pack_into(">I", hdr, 16, offsets[i])
            struct.pack_into(">I", hdr, 20, sizes[i])
        body += hdr
    struct.pack_into(">I", body, 0x20, shoff)
    open(out, "wb").write(bytes(body))
    return len(weak)


if __name__ == "__main__":
    if sys.argv[1] == "--list":
        n = 0
        for line in open(sys.argv[2]):
            parts = line.split()
            if len(parts) == 3:
                n += strip(*parts)
        print(f"stripped {n} weak copies")
    else:
        print(f"stripped {strip(sys.argv[1], sys.argv[2], sys.argv[3])} weak copies")
