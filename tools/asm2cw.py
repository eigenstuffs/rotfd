#!/usr/bin/env python3
"""Draft CodeWarrior asm functions from a dtk disassembly unit.

Usage: python3 tools/asm2cw.py build/GSQE78/asm/<unit>.s [fn ...]

Prints `asm` function definitions (nofralloc) for the selected functions,
translating dtk-only syntax: local labels, interior `.sym` labels as `entry`
points, simplified mnemonics CodeWarrior's assembler lacks, and SPR names.
The output is a starting point for SDK/runtime routines whose original
source is written in assembly; verify every function with tools/fdiff.py.
"""
import re
import sys

SPR = {"HID2": 920, "WPAR": 921, "DMA_U": 922, "DMA_L": 923,
       **{f"GQR{i}": 912 + i for i in range(8)},
       "UMMCR0": 936, "UPMC1": 937, "UPMC2": 938, "USIA": 939,
       "UMMCR1": 940, "UPMC3": 941, "UPMC4": 942, "USDA": 943,
       "MMCR0": 952, "PMC1": 953, "PMC2": 954, "SIA": 955,
       "MMCR1": 956, "PMC3": 957, "PMC4": 958, "SDA": 959,
       "IABR": 1010, "DABR": 1013, "L2CR": 1017, "ICTC": 1019,
       "THRM1": 1020, "THRM2": 1021, "THRM3": 1022, "PVR": 287,
       "HID0": 1008, "HID1": 1009, "EAR": 282, "DSISR": 18, "DAR": 19,
       "DEC": 22, "SDR1": 25, "SRR0": 26, "SRR1": 27}


def conv_insn(line):
    line = line.strip()
    ill = re.search(r"/\* illegal: (.*?) \*/", line)
    if ill:
        line = ill.group(1)
    if line.startswith("twui "):
        line = "twi 31, " + line[5:]
    m = re.match(r"(\S+)\s*(.*)", line)
    op, args = m.group(1), m.group(2)
    a = [x.strip() for x in args.split(",")] if args else []
    if op in ("extrwi", "extrwi."):
        rd, rs, n, b = a[0], a[1], int(a[2], 0), int(a[3], 0)
        return f"rlwinm{op[6:]} {rd}, {rs}, {b + n}, {32 - n}, 31"
    if op in ("clrlslwi", "clrlslwi."):
        rd, rs, b, n = a[0], a[1], int(a[2], 0), int(a[3], 0)
        return f"rlwinm{op[8:]} {rd}, {rs}, {n}, {b - n}, {31 - n}"
    if op in ("extlwi", "extlwi."):
        rd, rs, n, b = a[0], a[1], int(a[2], 0), int(a[3], 0)
        return f"rlwinm{op[6:]} {rd}, {rs}, {b}, 0, {n - 1}"
    if op in ("rotlwi", "rotlwi."):
        return f"rlwinm{op[6:]} {a[0]}, {a[1]}, {int(a[2], 0)}, 0, 31"
    if op.startswith("psq_") and a and a[-1].startswith("qr"):
        a[-1] = a[-1][2:]
        return f"{op} {', '.join(a)}"
    if op in ("mfspr", "mtspr"):
        a = [str(SPR.get(x, x)) for x in a]
        return f"{op} {', '.join(a)}"
    if op == "mtfsb1" or op == "mtfsb0":
        bits = {"cr7gt": 29, "cr7lt": 28, "cr7eq": 30, "cr7so": 31}
        return f"{op} {bits.get(a[0], a[0])}"
    out = f"{op} {', '.join(a)}" if a else op
    out = re.sub(r"\.L_([0-9A-F]+)", r"L_\1", out)
    out = re.sub(r"(\w+)@sda21\(r0\)", r"\1(r13)", out)
    return out


def main():
    path = sys.argv[1]
    want = set(sys.argv[2:])
    lines = open(path).read().splitlines()
    cur = None
    body = []
    entries = []
    for raw in lines:
        m = re.match(r"\.fn (\S+?), (\w+)", raw)
        if m:
            cur, scope = m.group(1), m.group(2)
            body = []
            continue
        if cur is None:
            continue
        if raw.startswith(".endfn"):
            if not want or cur in want:
                st = "static " if scope == "local" else ""
                print(f"{st}asm void {cur}(void) {{\n    nofralloc")
                for b in body:
                    print(b)
                print("}\n")
            cur = None
            continue
        m = re.match(r"\.sym (\S+?), (\w+)", raw)
        if m:
            entries.append(m.group(1))
            body.append(f"entry {m.group(1)}")
            continue
        m = re.match(r"\.L_([0-9A-F]+):", raw)
        if m:
            body.append(f"L_{m.group(1)}:")
            continue
        m = re.match(r"/\* [0-9A-F]{8} [0-9A-F]{8}  (?:[0-9A-F]{2} ?)+ \*/\s*(.*)", raw)
        if m:
            body.append("    " + conv_insn(m.group(1)))
    if entries:
        sys.stderr.write("declare entry labels: " +
                         " ".join(f"void {e}(void);" for e in entries) + "\n")


main()
