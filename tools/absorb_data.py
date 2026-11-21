#!/usr/bin/env python3
"""Give a source unit ownership of original data ranges.

Usage:
  python3 tools/absorb_data.py <src/Game/name.cpp> <section:start-end> [...]
      [--dry-run]

The source must already have a split (e.g. from tools/integrate_unit.py).
Every existing split that owns part of a requested range must lie entirely
inside it: its section line is removed, and a split left with no sections is
retired (its configure.py Object() line is removed and its source file, if
any, is moved to scratch/retired_sources/).  The requested ranges are then
added to the unit's split.  Re-run configure and ninja afterwards: the DOL
hash check and `ninja changes` remain the acceptance tests.
"""
import argparse, os, re, shutil, sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)

ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("ranges", nargs="+")
ap.add_argument("--dry-run", action="store_true")
ap.add_argument("--create", action="store_true",
                help="create the unit's split and configure entry (merged units)")
ap.add_argument("--ver", default="GC/1.3.2")
ap.add_argument("--flags", default="-proc gekko -fp hardware -enum int -str reuse -common off -O4,s -inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on -fp_contract on -i include")
a = ap.parse_args()

rel = a.src[4:] if a.src.startswith("src/") else a.src
splits = open("config/GSQE78/splits.txt").read()
blocks = splits.split("\n\n")


def parse(block):
    lines = block.split("\n")
    return lines[0][:-1] if lines[0].endswith(":") else None, lines


want = []
for r in a.ranges:
    m = re.match(r"(\.?\w+):0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)$", r)
    if not m:
        sys.exit(f"bad range {r}")
    want.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))

own_idx = None
retired = []
new_blocks = []
extra_blocks = []
for b in blocks:
    name, lines = parse(b)
    if name == rel:
        own_idx = len(new_blocks)
    if name and not b.startswith("Sections:"):
        keep = [lines[0]]
        for ln in lines[1:]:
            m = re.match(r"\t(\S+)\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", ln)
            if m:
                sec, s0, e0 = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
                hit = [w for w in want if w[0] == sec and s0 < w[2] and w[1] < e0]
                if hit:
                    w = hit[0]
                    if name == rel:
                        sys.exit(f"{rel} already owns part of {sec} range")
                    if not (w[1] <= s0 and e0 <= w[2]):
                        fallback = name.endswith(".s") and not os.path.exists(os.path.join("src", name))
                        if not fallback:
                            sys.exit(f"{name} {sec} 0x{s0:08X}-0x{e0:08X} straddles the requested range")
                        attr = ln.split("end:0x%08X" % e0)[1] if ("end:0x%08X" % e0) in ln else ""
                        if s0 < w[1]:
                            keep.append(f"\t{sec:<11} start:0x{s0:08X} end:0x{w[1]:08X}{attr}")
                            print(f"  shrink {name} {sec} to 0x{s0:08X}-0x{w[1]:08X}")
                        if w[2] < e0:
                            stem = re.sub(r"_[0-9A-F]{8}$", "", name[:-2])
                            nn = f"{stem}_{w[2]:08X}.s"
                            extra_blocks.append((name, f"{nn}:\n\t{sec:<11} start:0x{w[2]:08X} end:0x{e0:08X}{attr}"))
                            print(f"  new fallback {nn} {sec} 0x{w[2]:08X}-0x{e0:08X}")
                        continue
                    print(f"  remove {sec} 0x{s0:08X}-0x{e0:08X} from {name}")
                    continue
            keep.append(ln)
        if len(keep) == 1:
            retired.append(name)
            print(f"  retire {name}")
            new_blocks.extend(eb for src_, eb in extra_blocks if src_ == name)
            continue
        b = "\n".join(keep)
    new_blocks.append(b)
    new_blocks.extend(eb for src_, eb in extra_blocks if src_ == name)
if own_idx is None and a.create:
    tstart = next((s0 for s, s0, e0 in want if s == ".text"), None)
    own_idx = len(new_blocks)
    for i, b in enumerate(new_blocks):
        m = re.search(r"\t\.text\s+start:0x([0-9A-F]+)", b)
        if tstart is not None and m and int(m.group(1), 16) > tstart and not b.startswith("Sections:"):
            own_idx = i
            break
    new_blocks.insert(own_idx, rel + ":")
elif own_idx is None:
    sys.exit(f"{rel} has no split; integrate it first or pass --create")
# coverage check: requested ranges must now be unowned
order = [".init", "extab", "extabindex", ".text", ".ctors", ".dtors", ".rodata",
         ".data", ".bss", ".sdata", ".sbss", ".sdata2"]
name, lines = parse(new_blocks[own_idx])
secs = lines[1:] + [f"\t{s:<11} start:0x{s0:08X} end:0x{e0:08X}" for s, s0, e0 in want]
secs.sort(key=lambda ln: order.index(ln.split()[0]) if ln.split()[0] in order else 99)
new_blocks[own_idx] = "\n".join([lines[0]] + secs)
print(new_blocks[own_idx])

cfg = open("configure.py").read()
for orig, eb in extra_blocks:
    nn = eb.split(":")[0]
    m = re.search(r"^(\s*)Object\((\w+), ['\"]" + re.escape(orig) + r"['\"]\),\n", cfg, re.M)
    if not m:
        sys.exit(f"cannot find configure entry for {orig}")
    line = f'{m.group(1)}Object(NonMatching, "{nn}"),\n'
    cfg = cfg[:m.end()] + line + cfg[m.end():]
    print(f"  register {nn}")
for r in retired:
    m = re.search(r"^\s*Object\(\w+, ['\"]" + re.escape(r) + r"['\"]", cfg, re.M)
    if not m:
        print(f"  (no configure entry for {r})")
        continue
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
    start = cfg.rindex("\n", 0, m.start()) + 1
    end = cfg.index("\n", i) + 1
    cfg = cfg[:start] + cfg[end:]
    print(f"  unregister {r}")

if a.create:
    if f"'{rel}'" in cfg or f'"{rel}"' in cfg:
        sys.exit(f"{rel} already registered")
    obj = (f"            Object(Matching, '{rel}', mw_version='{a.ver}', "
           f"cflags={a.flags.split()!r}),\n")
    marker = '        "lib": "Runtime.PPCEABI.H",'
    close = cfg.rindex("        ],\n", 0, cfg.index(marker))
    cfg = cfg[:close] + obj + cfg[close:]
    print("  register", rel)
if not a.dry_run:
    open("config/GSQE78/splits.txt", "w").write("\n\n".join(new_blocks))
    open("configure.py", "w").write(cfg)
    os.makedirs("scratch/retired_sources", exist_ok=True)
    for r in retired:
        p = os.path.join("src", r)
        if os.path.exists(p):
            dst = os.path.join("scratch/retired_sources", r.replace("/", "__"))
            shutil.move(p, dst)
            print(f"  moved {p} -> {dst}")
