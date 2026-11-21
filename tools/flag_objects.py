#!/usr/bin/env python3
"""Add a keyword option to existing Object() entries in configure.py.

Usage: python3 tools/flag_objects.py <option=value> <unit-or-source> [...]
Units may be given as report names (Game/foo) or source paths (Game/foo.cpp).
"""
import os, re, sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)
opt = sys.argv[1]
key = opt.split("=")[0]
cfg = open("configure.py").read()
n = 0
for name in sys.argv[2:]:
    pat = re.escape(name) + (r"" if "." in os.path.basename(name) else r"\.(?:c|cpp|cp|s)")
    m = re.search(r"Object\(\w+, ['\"]" + pat + r"['\"]", cfg)
    if not m:
        print("not found", name)
        continue
    i, depth = m.start() + len("Object"), 0
    while True:
        c = cfg[i]
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                break
        i += 1
    call = cfg[m.start():i]
    if re.search(r"\b" + key + r"=", call):
        continue
    cfg = cfg[:i] + f", {opt}" + cfg[i:]
    n += 1
open("configure.py", "w").write(cfg)
print(f"flagged {n}")
