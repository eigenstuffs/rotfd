#!/usr/bin/env python3
"""Register a matched source file as the owner of an automatic split.

Usage:
  python3 tools/integrate_unit.py <src/Game/name.cpp> <auto_unit> \
      [--ver GC/1.3.2] [--flags "..."] [--status Matching|NonMatching]
      [--dry-run]

<auto_unit> is the generated object name (for example auto_fn_8002607C_text)
whose section ranges are read from build/GSQE78/asm/<auto_unit>.s.  The tool
adds a splits.txt entry for exactly those ranges, placed before the first
existing split with a later .text start, and appends an Object() entry to the
Game library in configure.py.  Run configure and ninja afterwards; the DOL
hash check remains the acceptance test.
"""
import argparse, os, re, sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)

GAME_CXX = ("-proc gekko -fp hardware -enum int -str reuse -common off -O4,s "
            "-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on "
            "-fp_contract on -i include")

ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("unit")
ap.add_argument("--ver", default="GC/1.3.2")
ap.add_argument("--flags", default=GAME_CXX)
ap.add_argument("--status", default="Matching")
ap.add_argument("--dry-run", action="store_true")
ap.add_argument("--after", default="",
                help="insert the Object() line after this registered source path "
                     "(default: end of the Game library)")
ap.add_argument("--no-ver", action="store_true",
                help="omit mw_version (use the library default)")
ap.add_argument("--functions", default="",
                help="comma-separated contiguous subset of a text-only unit")
a = ap.parse_args()

rel = a.src[len("src/"):] if a.src.startswith("src/") else a.src
if not os.path.exists(os.path.join("src", rel)):
    sys.exit(f"missing source src/{rel}")

asm = f"build/GSQE78/asm/{a.unit}.s"
text = open(asm).read()
sections = []
pending = None
for line in text.splitlines():
    m = re.match(r"# (0x[0-9A-F]+)\.\.(0x[0-9A-F]+) \| size: 0x[0-9A-F]+$", line)
    if m:
        pending = (int(m.group(1), 16), int(m.group(2), 16))
        continue
    m = re.match(r"\.section (\S+?),", line) or re.match(r"^(\.text|\.data|\.bss|\.rodata|\.sdata|\.sdata2|\.sbss|\.init|\.ctors|\.dtors)\s*$", line)
    if m and pending:
        sections.append((m.group(1), pending))
        pending = None
if not sections:
    sys.exit("no sections parsed from " + asm)
if a.functions:
    if any(name != ".text" for name, _ in sections):
        sys.exit("--functions supports text-only units; split extab by hand")
    want = a.functions.split(",")
    fns = {}
    lines = text.splitlines()
    for i, line in enumerate(lines):
        m = re.match(r"# \.text:0x[0-9A-F]+ \| (0x[0-9A-F]+) \| size: (0x[0-9A-F]+)$", line)
        if m and i + 1 < len(lines):
            j = i + 1
            if lines[j].startswith("# ") and j + 1 < len(lines):
                j += 1  # demangled-name comment for C++ symbols
            n = re.match(r"\.fn (\S+?),", lines[j])
            if n:
                fns[n.group(1)] = (int(m.group(1), 16), int(m.group(1), 16) + int(m.group(2), 16))
    missing = [w for w in want if w not in fns]
    if missing:
        sys.exit(f"functions not in unit: {missing}")
    rng = sorted(fns[w] for w in want)
    for (s0, e0), (s1, e1) in zip(rng, rng[1:]):
        if e0 != s1:
            sys.exit("requested functions are not contiguous")
    sections = [(".text", (rng[0][0], rng[-1][1]))]

splits = open("config/GSQE78/splits.txt").read()
if f"\n{rel}:\n" in splits:
    sys.exit(f"{rel} already has a split")
entry = f"{rel}:\n" + "".join(
    f"\t{name:<11} start:0x{s:08X} end:0x{e:08X}\n" for name, (s, e) in sections)

text_start = dict(sections).get(".text", (None,))[0]
blocks = splits.split("\n\n")
insert_at = None
if text_start is not None:
    for i, b in enumerate(blocks):
        m = re.search(r"\t\.text\s+start:0x([0-9A-Fa-f]+)", b)
        if m and int(m.group(1), 16) > text_start and not b.startswith("Sections:"):
            insert_at = i
            break
if insert_at is None:
    blocks.append(entry.rstrip("\n"))
else:
    blocks.insert(insert_at, entry.rstrip("\n"))
new_splits = "\n\n".join(blocks)

flags = a.flags.split()
ver = "" if a.no_ver else f"mw_version='{a.ver}', "
obj = (f"            Object({a.status}, '{rel}', {ver}"
       f"cflags={flags!r}),\n")
cfg = open("configure.py").read()
if f"'{rel}'" in cfg or f'"{rel}"' in cfg:
    sys.exit(f"{rel} already registered in configure.py")
if a.after:
    after = a.after[4:] if a.after.startswith("src/") else a.after
    m = re.search(r"^\s*Object\(\w+, ['\"]" + re.escape(after) + r"['\"]", cfg, re.M)
    if not m:
        sys.exit(f"--after object {after} not found")
    i = cfg.index("Object(", m.start())
    depth = 0
    while True:
        c = cfg[i]
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                break
        i += 1
    close = cfg.index("\n", i) + 1
else:
    marker = '        "lib": "Runtime.PPCEABI.H",'
    idx = cfg.index(marker)
    close = cfg.rindex("        ],\n", 0, idx)
new_cfg = cfg[:close] + obj + cfg[close:]

print(entry)
print(obj)
if not a.dry_run:
    open("config/GSQE78/splits.txt", "w").write(new_splits)
    open("configure.py", "w").write(new_cfg)
