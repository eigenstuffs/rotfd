#!/usr/bin/env python3
"""Cut an address range out of a data-only source unit.

Usage:
  python3 tools/split_data_unit.py <src/Game/unit.c> <section:start-end> [--dry-run]

The unit must be registered, own exactly one section, and consist of simple
top-level definitions (constants, strings, arrays).  Definitions inside the
range are removed; definitions before it stay in the unit (its split shrinks);
definitions after it move to a new unit `<stem>_<END>.c` registered right
after the original with the same compiler settings.  A part that would be
empty is retired.  Each new part must start on its section's alignment.
Afterwards give the range to its new owner (tools/absorb_data.py) and rebuild.
"""
import argparse, os, re, shutil, subprocess, sys, tempfile

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, "tools"))
from elfmini import Elf  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("range")
ap.add_argument("--dry-run", action="store_true")
a = ap.parse_args()
rel = a.src[4:] if a.src.startswith("src/") else a.src
m = re.match(r"(\.?\w+):0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)$", a.range)
sec, b0, b1 = m.group(1), int(m.group(2), 16), int(m.group(3), 16)

splits = open("config/GSQE78/splits.txt").read()
blocks = splits.split("\n\n")
bi = next(i for i, b in enumerate(blocks) if b.split("\n")[0] == rel + ":")
lines = blocks[bi].split("\n")[1:]
if len(lines) != 1:
    sys.exit("unit must own exactly one section")
mm = re.match(r"\t(\S+)\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)(.*)", lines[0])
if mm.group(1) != sec:
    sys.exit("section mismatch")
us, ue, attr = int(mm.group(2), 16), int(mm.group(3), 16), mm.group(4)
if not (us <= b0 < b1 <= ue):
    sys.exit("range not inside unit")

# compile with the unit's own flags to map symbols to addresses
nin = open("build.ninja").read().replace("$\n", " ")
stem = rel.rsplit(".", 1)[0]
bm = re.search(r"^build build/GSQE78/src/" + re.escape(stem) + r"\.o: .*?\n((?:  .*\n)+)", nin, re.M)
ver = re.search(r"mw_version = (\S+)", bm.group(1)).group(1)
flags = re.search(r"cflags = (.*)", bm.group(1)).group(1)
tmp = tempfile.mkdtemp()
obj = os.path.join(tmp, "u.o")
import shlex
p = subprocess.run(["build/tools/wibo", "build/tools/sjiswrap.exe", f"build/compilers/{ver}/mwcceppc.exe",
                    *shlex.split(flags), "-c", a.src, "-o", obj], capture_output=True, text=True,
                   env={**os.environ, "MWCIncludes": "include"})
if p.returncode:
    sys.exit(p.stdout + p.stderr)
e = Elf(obj)
si = e.section_index(sec)
addr = {s["name"]: us + s["value"] for s in e.symbols if s["shndx"] == si and s["name"] and s["type"] != 3}
if e.sections[si]["size"] != ue - us:
    print(f"warning: compiled {sec} size 0x{e.sections[si]['size']:X} vs split 0x{ue - us:X}")

# split the source into top-level statements (with leading comments)
text = open(a.src).read()
stmts, cur, depth, i = [], "", 0, 0
while i < len(text):
    c = text[i]
    if text.startswith("//", i):
        j = text.find("\n", i)
        j = len(text) if j < 0 else j + 1
        cur += text[i:j]
        i = j
        continue
    if text.startswith("/*", i):
        j = text.find("*/", i) + 2
        cur += text[i:j]
        i = j
        continue
    if c == '"':
        j = i + 1
        while text[j] != '"':
            j += 2 if text[j] == "\\" else 1
        cur += text[i:j + 1]
        i = j + 1
        continue
    cur += c
    if c in "{(":
        depth += 1
    elif c in "})":
        depth -= 1
    elif c == ";" and depth == 0:
        stmts.append(cur)
        cur = ""
    i += 1
tail = cur

pre, mid, post, common = [], [], [], []
for st in stmts:
    code = re.sub(r"/\*.*?\*/", "", re.sub(r"//[^\n]*", "", st), flags=re.S)
    names = [n for n in re.findall(r"[A-Za-z_]\w*", code) if n in addr]
    if not names:
        common.append(st)
        continue
    ad = addr[names[0]]
    (pre if ad < b0 else mid if ad < b1 else post).append(st)

new_rel = re.sub(r"_[0-9A-F]{8}$", "", stem) + f"_{b1:08X}.c" if post else None
print(f"pre {len(pre)} defs, removed {len(mid)}, post {len(post)} -> {new_rel}")
for st in mid:
    print("  removed:", re.sub(r"\s+", " ", st.strip())[:120])
for part, start in ((pre, us), (post, b1)):
    if part and start % e.sections[si]["align"]:
        sys.exit(f"part starting at 0x{start:08X} is not {e.sections[si]['align']}-aligned")

cfg = open("configure.py").read()
om = re.search(r"^(\s*)Object\((\w+), (['\"])" + re.escape(rel) + r"\3(.*)\),\n", cfg, re.M)
if not om:
    sys.exit("configure entry not found (single-line Object expected)")
new_blocks = list(blocks)
new_obj = ""
if post:
    new_blocks.insert(bi + 1, f"{new_rel}:\n\t{sec:<11} start:0x{b1:08X} end:0x{ue:08X}{attr}")
    new_obj = f"{om.group(1)}Object({om.group(2)}, {om.group(3)}{new_rel}{om.group(3)}{om.group(4)}),\n"
if pre:
    new_blocks[bi] = f"{rel}:\n\t{sec:<11} start:0x{us:08X} end:0x{b0:08X}{attr}"
    cfg = cfg[:om.end()] + new_obj + cfg[om.end():]
else:
    del new_blocks[bi]
    cfg = cfg[:om.start()] + new_obj + cfg[om.end():]

if a.dry_run:
    sys.exit(0)
header = "".join(common)
if post:
    open(os.path.join("src", new_rel), "w").write(header + "".join(post) + tail)
if pre:
    open(a.src, "w").write(header + "".join(pre) + tail)
else:
    os.makedirs("scratch/retired_sources", exist_ok=True)
    shutil.move(a.src, os.path.join("scratch/retired_sources", rel.replace("/", "__")))
open("config/GSQE78/splits.txt", "w").write("\n\n".join(new_blocks))
open("configure.py", "w").write(cfg)
