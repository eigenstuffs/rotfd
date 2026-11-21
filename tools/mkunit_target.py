#!/usr/bin/env python3
"""Build the original-side object for a proposed unit without touching config.

Usage:
  python3 tools/mkunit_target.py <out.o> <section:start-end> [...] [--keep DIR]

Copies config/GSQE78 to a temporary directory, replaces every split that
overlaps the requested ranges (overlapping splits are shrunk or dropped), adds
one unit `proposed/unit.cpp` owning exactly the requested ranges, runs
`dtk dol split`, and copies that unit's object to <out.o>.  Use it as the
fdiff target when merging several existing units into one translation unit,
then apply the real split change with tools/integrate_unit.py /
tools/absorb_data.py.
"""
import argparse, os, re, shutil, subprocess, sys, tempfile

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)

ap = argparse.ArgumentParser()
ap.add_argument("out")
ap.add_argument("ranges", nargs="+")
ap.add_argument("--keep", default=None)
a = ap.parse_args()

want = []
for r in a.ranges:
    m = re.match(r"(\.?\w+):0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)$", r)
    if not m:
        sys.exit(f"bad range {r}")
    want.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))

tmp = a.keep or tempfile.mkdtemp(prefix="mkunit")
cfgdir = os.path.join(tmp, "config")
os.makedirs(cfgdir, exist_ok=True)
for f in ("symbols.txt", "ldscript.tpl", "build.sha1"):
    if os.path.exists(f"config/GSQE78/{f}"):
        shutil.copy(f"config/GSQE78/{f}", cfgdir)
yml = open("config/GSQE78/config.yml").read()
yml = yml.replace("config/GSQE78/splits.txt", os.path.join(cfgdir, "splits.txt"))
yml = yml.replace("config/GSQE78/symbols.txt", os.path.join(cfgdir, "symbols.txt"))
yml = re.sub(r"^write_asm: .*$", "write_asm: false", yml, flags=re.M)
open(os.path.join(cfgdir, "config.yml"), "w").write(yml)

blocks = open("config/GSQE78/splits.txt").read().split("\n\n")
out_blocks = []
counter = 0
for b in blocks:
    lines = b.split("\n")
    if b.startswith("Sections:") or not lines[0].endswith(":"):
        out_blocks.append(b)
        continue
    name = lines[0][:-1]
    keep, extra = [], []
    for ln in lines[1:]:
        m = re.match(r"\t(\S+)\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)(.*)", ln)
        if not m:
            keep.append(ln)
            continue
        sec, s0, e0, attr = m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4)
        hit = [w for w in want if w[0] == sec and s0 < w[2] and w[1] < e0]
        if not hit:
            keep.append(ln)
            continue
        w = hit[0]
        if s0 < w[1]:
            keep.append(f"\t{sec:<11} start:0x{s0:08X} end:0x{w[1]:08X}{attr}")
        if w[2] < e0:
            counter += 1
            extra.append(f"proposed/rest_{counter}.s:\n\t{sec:<11} start:0x{w[2]:08X} end:0x{e0:08X}{attr}")
    if len(keep) > 0:
        out_blocks.append("\n".join([lines[0]] + keep))
    out_blocks.extend(extra)
out_blocks.append("proposed/unit.cpp:\n" + "\n".join(
    f"\t{s:<11} start:0x{s0:08X} end:0x{e0:08X}" for s, s0, e0 in want))
open(os.path.join(cfgdir, "splits.txt"), "w").write("\n\n".join(out_blocks) + "\n")

outdir = os.path.join(tmp, "out")
p = subprocess.run(["tools/dtk", "dol", "split", os.path.join(cfgdir, "config.yml"), outdir],
                   capture_output=True, text=True)
obj = os.path.join(outdir, "obj", "proposed", "unit.o")
if p.returncode != 0 or not os.path.exists(obj):
    print(p.stdout[-2000:], p.stderr[-3000:])
    sys.exit("dtk split failed")
shutil.copy(obj, a.out)
print(f"wrote {a.out}")
if not a.keep:
    shutil.rmtree(tmp, ignore_errors=True)
