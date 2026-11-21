#!/usr/bin/env python3
"""Map source-filename strings left in the binary (__FILE__ from asserts,
debug macros, error messages) to the functions that reference them.

The dev disc's DOL contains the original translation-unit names as plain
strings (e.g. "ceval.c", "GCRenderer_Z.cpp"). Every function compiled from
such a file that still has an assert()/debug reference emits a relocation to
that string, which lets us recover TU membership without a map file.

Requires a completed build (build/<version>/asm/ must exist).

Usage:
    python3 tools/map_source_strings.py [GAMEID] [--out config/GSQE78/filemap.json]
"""
import argparse
import glob
import json
import os
import re
import struct
import sys

DOL_SECTIONS = [
    (0x100, 0x80003100, 0x2520),
    (0x2620, 0x8001F2C0, 0x27A660),
    (0x27CC80, 0x80005620, 0x10940),
    (0x28D5C0, 0x80015F60, 0x9360),
    (0x296920, 0x80299920, 0x60),
    (0x296980, 0x80299980, 0x20),
    (0x2969A0, 0x802999A0, 0x16200),
    (0x2ACBA0, 0x802AFBA0, 0x438C0),
    (0x2F0460, 0x80373E40, 0x3700),
    (0x2F3B60, 0x803781C0, 0x37E0),
]

NAME_RE = re.compile(rb"[A-Za-z_][A-Za-z0-9_]+(?:/[A-Za-z0-9_]+)*\.(?:c|cpp|h)\x00")


def ram_of(off):
    for f, a, s in DOL_SECTIONS:
        if f <= off < f + s:
            return a + (off - f)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("version", nargs="?", default="GSQE78")
    ap.add_argument("--out", default=None)
    args = ap.parse_args()

    dol = open(f"orig/{args.version}/main.dol", "rb").read()

    names = {}
    for m in NAME_RE.finditer(dol):
        ram = ram_of(m.start())
        if ram is None:
            continue
        s = m.group(0)[:-1].decode("latin1")
        if len(s) > 64 or s.count(".") != 1:
            continue
        names.setdefault(s, []).append(ram)

    sym_at = {}
    for line in open(f"config/{args.version}/symbols.txt"):
        m = re.match(r"(\S+) = (?:\.data|\.rodata|\.sdata2?|\.sdata):0x([0-9A-F]+)", line)
        if m:
            sym_at[int(m.group(2), 16)] = m.group(1)

    refs = {}
    for s, rams in sorted(names.items()):
        syms = {sym_at.get(r, f"lbl_{r:08X}") for r in rams}
        refs[s] = sorted(syms)

    fn_of_line = None
    fnrefs = {}
    ref_re = re.compile(
        r"\b(" + "|".join(re.escape(v) for vs in refs.values() for v in vs) + r")@"
    ) if any(refs.values()) else None

    asm_files = sorted(glob.glob(f"build/{args.version}/asm/*.s"))
    for path in asm_files:
        for line in open(path, errors="replace"):
            if line.startswith(".fn "):
                fn_of_line = line[4:].split(",")[0]
                fnrefs.setdefault(fn_of_line, set())
                continue
            if line.startswith(".endfn"):
                fn_of_line = None
                continue
            if fn_of_line is not None and ref_re is not None:
                for sym in ref_re.findall(line):
                    fnrefs[fn_of_line].add(sym)

    file_to_fns = {}
    for fn, syms in fnrefs.items():
        for s, slist in refs.items():
            if syms.intersection(slist):
                file_to_fns.setdefault(s, []).append(fn)

    fn_addr = {}
    for line in open(f"config/{args.version}/symbols.txt"):
        m = re.match(r"(\S+) = \.text:0x([0-9A-F]+);.*size:(0x[0-9A-F]+)", line)
        if m:
            fn_addr[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))

    result = {}
    for s, fns in sorted(file_to_fns.items()):
        info = []
        for fn in fns:
            a, sz = fn_addr.get(fn, (0, 0))
            info.append({"name": fn, "addr": a, "size": sz})
        info.sort(key=lambda e: e["addr"])
        result[s] = {
            "string_addrs": refs[s],
            "functions": info,
            "addr_min": info[0]["addr"] if info else None,
            "addr_max": (info[-1]["addr"] + info[-1]["size"]) if info else None,
        }

    out = args.out or f"config/{args.version}/filemap.json"
    json.dump(result, open(out, "w"), indent=1)
    print(f"{len(result)} source filenames mapped by {sum(len(v['functions']) for v in result.values())} functions -> {out}")
    for s, v in list(result.items())[:40]:
        if v["addr_min"]:
            print(f"  {s:32s} {v['addr_min']:#010x}..{v['addr_max']:#010x}  ({len(v['functions'])} fns)")


if __name__ == "__main__":
    sys.exit(main())
