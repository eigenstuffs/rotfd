"""Minimal big-endian ELF32 reader for PowerPC relocatable objects.

Provides sections, symbols and RELA relocations; enough for comparing
exception-table records and data ranges between objects.
"""
import struct


class Elf:
    def __init__(self, path):
        d = open(path, "rb").read()
        self.d = d
        (self.shoff,) = struct.unpack(">I", d[0x20:0x24])
        shentsize, shnum, shstrndx = struct.unpack(">HHH", d[0x2E:0x34])
        raw = [struct.unpack(">IIIIIIIIII", d[self.shoff + i * shentsize:
                                             self.shoff + (i + 1) * shentsize])
               for i in range(shnum)]
        strsec = raw[shstrndx]
        self.sections = []
        for r in raw:
            name = d[strsec[4] + r[0]:].split(b"\0")[0].decode()
            self.sections.append(dict(name=name, type=r[1], flags=r[2],
                                      offset=r[4], size=r[5], link=r[6],
                                      info=r[7], align=r[8], entsize=r[9]))
        self.symbols = []
        for s in self.sections:
            if s["type"] == 2:  # SYMTAB
                strtab = self.sections[s["link"]]
                for i in range(s["size"] // 16):
                    o = s["offset"] + i * 16
                    nm, val, size, info, other, shndx = struct.unpack(">IIIBBH", d[o:o + 16])
                    name = d[strtab["offset"] + nm:].split(b"\0")[0].decode(errors="replace")
                    self.symbols.append(dict(name=name, value=val, size=size,
                                             bind=info >> 4, type=info & 15,
                                             shndx=shndx))
        self.relocs = {}
        for s in self.sections:
            if s["type"] == 4:  # RELA
                target = s["info"]
                lst = []
                for i in range(s["size"] // 12):
                    o = s["offset"] + i * 12
                    off, info, add = struct.unpack(">IIi", d[o:o + 12])
                    sym = self.symbols[info >> 8] if (info >> 8) < len(self.symbols) else None
                    lst.append(dict(offset=off, type=info & 0xFF, sym=sym, addend=add))
                self.relocs[target] = lst

    def section_index(self, name):
        for i, s in enumerate(self.sections):
            if s["name"] == name:
                return i
        return None

    def data(self, idx):
        s = self.sections[idx]
        if s["type"] == 8:  # NOBITS
            return b"\0" * s["size"]
        return self.d[s["offset"]:s["offset"] + s["size"]]

    def reloc_at(self, idx, offset):
        for r in self.relocs.get(idx, []):
            if r["offset"] == offset:
                return r
        return None

    def symbol_at(self, idx, value):
        best = None
        for s in self.symbols:
            if s["shndx"] == idx and s["value"] == value and s["name"]:
                if best is None or s["type"] != 3:
                    best = s
        return best

    def func(self, name):
        for s in self.symbols:
            if s["name"] == name and s["type"] == 2:
                return s
        return None

    def extab_record(self, fname):
        """Return (bytes, [(offset, symname)]) of fname's extab record."""
        xi = self.section_index("extabindex")
        xt = self.section_index("extab")
        if xi is None or xt is None:
            return None
        data = self.data(xi)
        for off in range(0, len(data), 12):
            r0 = self.reloc_at(xi, off)
            if not r0 or not r0["sym"]:
                continue
            sym = r0["sym"]
            fn = sym["name"]
            if sym["type"] == 3 or not fn:  # section-relative
                s = self.symbol_at(sym["shndx"], sym["value"] + r0["addend"])
                fn = s["name"] if s else None
            if fn != fname:
                continue
            r8 = self.reloc_at(xi, off + 8)
            ext_off = r8["sym"]["value"] + r8["addend"]
            # record extends to the next extab symbol or section end
            ends = sorted(s["value"] for s in self.symbols
                          if s["shndx"] == xt and s["value"] > ext_off and s["type"] != 3)
            ext = self.data(xt)
            end = ends[0] if ends else len(ext)
            # prefer the next record start referenced by another index entry
            starts = []
            for o2 in range(0, len(data), 12):
                rr = self.reloc_at(xi, o2 + 8)
                if rr:
                    v = rr["sym"]["value"] + rr["addend"]
                    if v > ext_off:
                        starts.append(v)
            if starts:
                end = min(end, min(starts))
            rel = []
            for r in self.relocs.get(xt, []):
                if ext_off <= r["offset"] < end:
                    nm = r["sym"]["name"] if r["sym"] else "?"
                    rel.append((r["offset"] - ext_off, nm))
            length = struct.unpack(">I", data[off + 4:off + 8])[0]
            return ext[ext_off:end], rel, length
        return None
