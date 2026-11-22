#!/usr/bin/env python3
"""Report-only normalization: resolve linker-script symbol aliases.

Usage:
  python3 tools/resolve_link_aliases.py --ldscript <ldscript.tpl> <in.o> <out.o>
  python3 tools/resolve_link_aliases.py --ldscript <ldscript.tpl> --list <pairs.txt>
      (pairs.txt lines: "<in.o> <out.o>")

Some names cannot be written in C or C++ source. CodeWarrior names adjustor
thunks "@N@target", for example, and "@" is not an identifier character. The
linker script therefore defines plain aliases, such as
    thunk96_foo__3BarFv = "@96@foo__3BarFv";
and C data refers to the thunk through the alias. MWLD resolves every
reference to the alias to the aliased symbol, so the linked executable holds
exactly the original pointer.

objdiff compares unlinked objects, and it matches a relocation against an
undefined symbol by name only. So it scores such a reference as different from
the original object's reference to "@96@foo__3BarFv", even though both resolve
to the same address. This tool writes a copy of the compiled object in which
every *undefined* symbol whose name is an exact alias in the linker script is
renamed to the alias target, which is what the linker does. Nothing else
changes: section contents, symbol values, relocations and defined symbols stay
the same. The object used for linking is never modified, and the DOL hash
check remains the acceptance test.

Only simple aliases are recognised: `NAME = TARGET;` or `NAME = "TARGET";`
where TARGET is one symbol name, not an expression.
"""
import re
import struct
import sys

ALIAS = re.compile(r'^\s*([A-Za-z_.$][A-Za-z0-9_.$]*)\s*=\s*("([^"]+)"|([A-Za-z_.$@][A-Za-z0-9_.$@<>,]*))\s*;')


def _write(path, data):
    with open(path, "wb") as f:
        f.write(data)


def load_aliases(path):
    aliases = {}
    with open(path) as f:
        lines = f.read().split("\n")
    for line in lines:
        line = line.split("//")[0]
        m = ALIAS.match(line)
        if not m:
            continue
        target = m.group(3) if m.group(3) is not None else m.group(4)
        if target.startswith("$"):  # template variable, not a symbol
            continue
        aliases[m.group(1)] = target
    return aliases


def resolve(src, out, aliases):
    with open(src, "rb") as f:
        raw = f.read()
    if raw[:4] != b"\x7fELF" or raw[4] != 1 or raw[5] != 2:
        raise SystemExit(f"{src}: expected a big-endian ELF32 object")
    (shoff,) = struct.unpack(">I", raw[0x20:0x24])
    shentsize, shnum, shstrndx = struct.unpack(">HHH", raw[0x2E:0x34])
    hdrs = [list(struct.unpack(">10I", raw[shoff + i * shentsize:shoff + (i + 1) * shentsize]))
            for i in range(shnum)]
    symtab = next((i for i, h in enumerate(hdrs) if h[1] == 2), None)
    if symtab is None:
        _write(out, raw)
        return 0
    strtab = hdrs[symtab][6]
    st_off, st_size = hdrs[strtab][4], hdrs[strtab][5]
    strdata = bytearray(raw[st_off:st_off + st_size])
    syms = bytearray(raw[hdrs[symtab][4]:hdrs[symtab][4] + hdrs[symtab][5]])
    added = {}
    renamed = 0
    for o in range(0, len(syms), 16):
        nm, val, size, info, other, shndx = struct.unpack(">IIIBBH", syms[o:o + 16])
        if shndx != 0 or not nm:  # only undefined references
            continue
        name = bytes(raw[st_off + nm:st_off + st_size]).split(b"\0")[0].decode("latin-1")
        target = aliases.get(name)
        if target is None or target == name:
            continue
        if target not in added:
            added[target] = len(strdata)
            strdata += target.encode("latin-1") + b"\0"
        struct.pack_into(">I", syms, o, added[target])
        renamed += 1
    if not renamed:
        _write(out, raw)
        return 0
    newdata = {symtab: bytes(syms), strtab: bytes(strdata)}
    # Rewrite: ELF header, section contents in header order, then section headers.
    body = bytearray(raw[:0x34])
    for i, h in enumerate(hdrs):
        if i == 0:
            continue
        content = newdata.get(i)
        if content is None:
            content = b"" if h[1] == 8 else raw[h[4]:h[4] + h[5]]
        align = max(h[8], 1)
        while len(body) % align:
            body += b"\0"
        h[4] = len(body)
        if h[1] != 8:
            h[5] = len(content)
            body += content
    while len(body) % 4:
        body += b"\0"
    new_shoff = len(body)
    for i, h in enumerate(hdrs):
        hdr = bytearray(raw[shoff + i * shentsize:shoff + (i + 1) * shentsize])
        if i:
            struct.pack_into(">II", hdr, 16, h[4], h[5])
        body += hdr
    struct.pack_into(">I", body, 0x20, new_shoff)
    _write(out, bytes(body))
    return renamed


def main(argv):
    if len(argv) < 4 or argv[0] != "--ldscript":
        raise SystemExit(__doc__)
    aliases = load_aliases(argv[1])
    rest = argv[2:]
    n = 0
    if rest[0] == "--list":
        with open(rest[1]) as f:
            pairs = f.read().split("\n")
        for line in pairs:
            parts = line.split()
            if len(parts) == 2:
                n += resolve(parts[0], parts[1], aliases)
    else:
        n = resolve(rest[0], rest[1], aliases)
    print(f"resolved {n} alias references")


if __name__ == "__main__":
    main(sys.argv[1:])
