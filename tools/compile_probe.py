#!/usr/bin/env python3
"""Compile a C source with a given CodeWarrior GC version+flags and compare a
chosen function's bytes against the original main.dol. The iteration primitive
for LLM-assisted function matching (see blog: one function at a time).

Usage:
  python3 tools/compile_probe.py <src.c> <fn_ram_hex> <fn_size_hex> \
      [--ver GC/2.0] [--flags "..."] [--func NAME]

Prints a per-instruction diff between the freshly compiled function and the
bytes in orig/GSQE78/main.dol. Branch instructions are annotated as possible
relocations, but this tool does not resolve or verify relocation targets.
Its raw word-equality score is exploratory; accept a source match only after
objdiff comparison and the complete rebuilt DOL hash check.
"""
import argparse, subprocess, struct, os, re, tempfile

os.chdir(os.path.join(os.path.dirname(__file__), ".."))

ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("addr", help="function RAM start, hex e.g. 0x801647AC")
ap.add_argument("size", help="function size, hex e.g. 0x144")
ap.add_argument("--ver", default="GC/2.0")
ap.add_argument("--flags", default="-proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole -inline auto")
ap.add_argument("--func", default=None, help="function symbol to locate in the object disasm")
ap.add_argument("--include", default="include")
a = ap.parse_args()

ram = int(a.addr,16); size = int(a.size,16)

# original bytes
dol = open(f"orig/GSQE78/main.dol","rb").read()
def dol_off(ram): return 0x2620 + (ram - 0x8001F2C0)
O = [struct.unpack('>I', dol[dol_off(ram)+i:dol_off(ram)+i+4])[0] for i in range(0,size,4)]

with tempfile.TemporaryDirectory() as tmp:
    out = os.path.join(tmp,"a.o")
    cc = f"build/compilers/{a.ver}/mwcceppc.exe"
    cmd = ["build/tools/wibo", cc, "-c", *[f for f in a.flags.split()],
           "-i", a.include, "-o", out, a.src]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0 or not os.path.exists(out):
        print("COMPILE FAILED:\n", r.stdout, r.stderr); raise SystemExit(1)
    subprocess.run(["tools/dtk","elf","disasm",out,os.path.join(tmp,"a.dis")],capture_output=True)
    txt = open(os.path.join(tmp,"a.dis"),errors="replace").read()
    # gather words, optionally for one function
    words=[]; infn = a.func is None
    for line in txt.splitlines():
        if line.startswith('.fn'):
            nm=line.split()[1].rstrip(',')
            infn = (a.func is None) or (nm==a.func)
        elif line.startswith('.endfn'):
            infn = a.func is None
        m=re.match(r'/\* [0-9A-F]{8} [0-9A-F]{8}  ((?:[0-9A-F]{2} )+)',line)
        if infn and m:
            bs=bytes(int(x,16) for x in m.group(1).split())
            words+=[struct.unpack('>I',bs[i:i+4])[0] for i in range(0,len(bs),4)]

n=min(len(O),len(words)); match=sum(1 for i in range(n) if O[i]==words[i])
print(f"original words={len(O)} compiled words={len(words)} equal={match}/{n} "
      f"({100*match/max(n,1):.1f}%)")
for i in range(max(len(O),len(words))):
    o=O[i] if i<len(O) else None
    w=words[i] if i<len(words) else None
    if o==w: 
        print(f"  {ram+i*4:08x}: {o:08x}  ==")
    else:
        ob=f"{o:08x}" if o is not None else "--------"
        wb=f"{w:08x}" if w is not None else "--------"
        note=""
        if o is not None and (o>>26)==0x12: note=" [orig bl->reloc]"
        if w is not None and (w>>26)==0x12: note+=" [mine bl->reloc]"
        print(f"  {ram+i*4:08x}: {ob} != {wb}{note}")
