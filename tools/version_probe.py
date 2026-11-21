#!/usr/bin/env python3
"""Compiler version probe (verified 2026-08-10).

Compiles the verbatim CPython 1.5.2 `tuplehash` (found byte-for-byte at
0x801647AC in main.dol) with each CodeWarrior GC version in build/compilers/
and compares instruction words against the original (bl relocations masked).

Result:
  GC/1.1, GC/1.2.5        -> different codegen (ruled out)
  GC/1.3.2 .. GC/2.6      -> byte-identical with: -opt level=4,nopeephole
  GC/2.7, GC/3.0a3, ...   -> different again (ruled out)
Required flags found by eliminating the `subi;cmpwi` -> `subic.` peephole
fusion: -proc gekko -fp hardware -enum int -str reuse -common off
        -opt level=4,nopeephole -inline auto

Usage: python3 tools/version_probe.py [GC/x.y ...]
"""
import subprocess, struct, os, re, sys, tempfile

TUPLEHASH_C = r'''
typedef struct _typeobject PyTypeObject;
typedef struct _object { int ob_refcnt; PyTypeObject *ob_type; } PyObject;
typedef struct { int ob_refcnt; PyTypeObject *ob_type; int ob_size; PyObject *ob_item[1]; } PyTupleObject;
extern long PyObject_Hash();

static long
tuplehash(v)
	register PyTupleObject *v;
{
	register long x, y;
	register int len = v->ob_size;
	register PyObject **p;
	x = 0x345678L;
	p = v->ob_item;
	while (--len >= 0) {
		y = PyObject_Hash(*p++);
		if (y == -1)
			return -1;
		x = (1000003*x) ^ y;
	}
	x ^= v->ob_size;
	if (x == -1)
		x = -2;
	return x;
}
'''

FLAGS = ["-c","-proc","gekko","-fp","hardware","-enum","int","-str","reuse",
         "-common","off","-opt","level=4,nopeephole","-inline","auto"]
FN_RAM, FN_SIZE = 0x801647AC, 0x94

def orig_words():
    o = open("orig/GSQE78/main.dol","rb").read()
    fo = 0x2620 + (FN_RAM - 0x8001F2C0)
    return [struct.unpack('>I', o[fo+i:fo+i+4])[0] for i in range(0, FN_SIZE, 4)]

def compile_and_words(cc, src, tmp):
    out = os.path.join(tmp, "a.o")
    r = subprocess.run(["build/tools/wibo", cc, *FLAGS, "-o", out, src],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None
    subprocess.run(["tools/dtk","elf","disasm",out,os.path.join(tmp,"a.dis")],
                   capture_output=True)
    txt = open(os.path.join(tmp,"a.dis"), errors="replace").read()
    in_fn, ws = False, []
    for line in txt.splitlines():
        if line.startswith('.fn tuplehash'): in_fn = True; continue
        if line.startswith('.endfn'): in_fn = False; continue
        m = re.match(r'/\* [0-9A-F]{8} [0-9A-F]{8}  ((?:[0-9A-F]{2} )+)', line)
        if in_fn and m:
            bs = bytes(int(x,16) for x in m.group(1).split())
            ws += [struct.unpack('>I', bs[i:i+4])[0] for i in range(0,len(bs),4)]
    return ws

def main():
    O = orig_words()
    versions = sys.argv[1:] or ["GC/1.1","GC/1.2.5","GC/1.3.2","GC/2.0","GC/2.5","GC/2.6","GC/2.7","GC/3.0a3","GC/3.0a5.2"]
    with tempfile.TemporaryDirectory() as tmp:
        src = os.path.join(tmp, "tuplehash.c")
        open(src,"w").write(TUPLEHASH_C)
        for v in versions:
            cc = f"build/compilers/{v}/mwcceppc.exe"
            if not os.path.exists(cc):
                print(f"{v:10s} missing"); continue
            N = compile_and_words(cc, src, tmp)
            if N is None:
                print(f"{v:10s} compile failed"); continue
            mism = sum(1 for o,n in zip(O,N) if o!=n and (o>>26)!=0x12)
            status = "MATCH" if mism==0 and len(N)==len(O) else f"mismatch={mism}"
            print(f"{v:10s} words={len(N)} {status}")

if __name__ == "__main__":
    main()
