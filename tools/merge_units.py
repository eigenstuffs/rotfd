#!/usr/bin/env python3
"""Merge several adjacent source units into one translation unit candidate.

Usage:
  python3 tools/merge_units.py <out.cpp> <section:start-end> [...]
      [--part ADDR=path/to/candidate.cpp ...] [--ver GC/1.3.2] [--flags="..."]
      [--target build/proposed.o] [--apply] [--name Game/x.cpp]

The first range must be the .text range.  Every current split unit that owns
part of the ranges contributes its source (in .text address order; data-only
units in data address order before the code that follows them).  Units with
no source yet (automatic splits) must be supplied with --part ADDR=file,
where ADDR is the unit's first function address.  Each part is wrapped in its
own namespace unless its object defines C++-mangled symbols (namespaces would
change their names); extern "C" names are unaffected by namespaces.

The merged file is compiled and compared (tools/fdiff.py) against a target
built by tools/mkunit_target.py for the same ranges.  With --apply and an
EXACT* verdict, the merged unit replaces the parts via tools/absorb_data.py.
"""
import argparse, os, re, shlex, subprocess, sys, tempfile

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, "tools"))
from elfmini import Elf  # noqa: E402

GAME_CXX = ("-proc gekko -fp hardware -enum int -str reuse -common off -O4,s "
            "-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on "
            "-fp_contract on -i include")
ap = argparse.ArgumentParser()
ap.add_argument("out")
ap.add_argument("ranges", nargs="+")
ap.add_argument("--part", action="append", default=[])
ap.add_argument("--ver", default="GC/1.3.2")
ap.add_argument("--flags", default=GAME_CXX)
ap.add_argument("--target", default=None)
ap.add_argument("--apply", action="store_true")
ap.add_argument("--name", default=None)
ap.add_argument("--no-namespace", action="append", default=[],
                help="part address whose source must stay at global scope")
a = ap.parse_args()

want = []
for r in a.ranges:
    m = re.match(r"(\.?\w+):0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)$", r)
    want.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))
extra = {}
for p in a.part:
    k, v = p.split("=", 1)
    extra[int(k, 16)] = v

units = {}
cur = None
for line in open("config/GSQE78/splits.txt").read().splitlines():
    if line and not line[0].isspace() and line.endswith(":") and not line.startswith("Sections"):
        cur = line[:-1]
    m = re.match(r"\s+(\S+)\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", line)
    if m and cur:
        units.setdefault(cur, []).append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))

parts = []  # (sort key, label, path)
tsec, t0, t1 = want[0]
covered = []
for u, secs in units.items():
    for sec, s0, e0 in secs:
        for w in want:
            if w[0] == sec and s0 < w[2] and w[1] < e0:
                text = [x for x in secs if x[0] == ".text"]
                key = text[0][1] if text else None
                path = os.path.join("src", u)
                if key is not None and sec == ".text":
                    covered.append((s0, e0))
                parts.append((key, sec, s0, u, path))
                break
# gaps in .text are automatic units that need --part
covered.sort()
pos = t0
gaps = []
for s0, e0 in covered:
    if s0 > pos:
        gaps.append((pos, s0))
    pos = max(pos, e0)
if pos < t1:
    gaps.append((pos, t1))
for g0, g1 in gaps:
    if g0 not in extra:
        sys.exit(f"text 0x{g0:08X}-0x{g1:08X} has no source; pass --part 0x{g0:08X}=file")
    parts.append((g0, ".text", g0, f"part_{g0:08X}", extra[g0]))

# order: code parts by text address; data-only parts placed before the first
# code part whose data follows them (simple heuristic: by data address relative
# to the code parts' own data is not known, so data-only parts go first)
seen = set()
ordered = []
for key, sec, s0, u, path in sorted(parts, key=lambda p: (p[0] if p[0] is not None else -1, p[2])):
    if u in seen:
        continue
    seen.add(u)
    ordered.append((key, u, path))

tmp = tempfile.mkdtemp(prefix="merge")


def compile_part(path, idx):
    out = os.path.join(tmp, f"p{idx}.o")
    flags = shlex.split(a.flags)
    lang = ["-lang=c++"] if path.endswith((".cpp", ".cc", ".cp")) else []
    r = subprocess.run(["build/tools/wibo", "build/tools/sjiswrap.exe",
                        f"build/compilers/{a.ver}/mwcceppc.exe", *flags, *lang,
                        "-c", path, "-o", out], capture_output=True, text=True,
                       env={**os.environ, "MWCIncludes": "include"})
    return Elf(out) if r.returncode == 0 and os.path.exists(out) else None


MANGLED = re.compile(r"__\w*F|^__\w+__\d|^\w+__\d+\w+|^@\d+@")
chunks = ["/* Merged translation unit: " + ", ".join(u for _, u, _ in ordered) + ". */\n"]
for i, (key, u, path) in enumerate(ordered):
    if not os.path.exists(path):
        sys.exit(f"missing source {path} for {u}")
    src = open(path).read()
    e = compile_part(path, i)
    mangled = []
    if e:
        mangled = [s["name"] for s in e.symbols if s["bind"] in (1, 2) and s["shndx"] not in (0,)
                   and ("__" in s["name"][1:] and re.search(r"__\d|F[vicfdPRC]", s["name"]))]
    ns_ok = not mangled and key not in [int(x, 16) for x in a.no_namespace] and "#include" not in src
    is_c = path.endswith(".c")
    label = re.sub(r"\W", "_", os.path.splitext(os.path.basename(u))[0])
    body = src
    if is_c:
        body = 'extern "C" {\n' + body + "\n}\n"
    if ns_ok:
        body = f"namespace {label} {{\n{body}\n}}\n"
    chunks.append(f"/* ---- {u} ---- */\n{body}\n")
    print(f"part {u:<60} {'ns' if ns_ok else 'global'}{' (mangled: ' + ','.join(mangled[:3]) + ')' if mangled else ''}")
open(a.out, "w").write("".join(chunks))

target = a.target or os.path.join(tmp, "target.o")
if not a.target:
    p = subprocess.run(["python3", "tools/mkunit_target.py", target, *a.ranges], capture_output=True, text=True)
    if p.returncode:
        sys.exit("mkunit_target failed: " + p.stdout[-500:] + p.stderr[-500:])
p = subprocess.run(["python3", "tools/fdiff.py", a.out, target, "--ver", a.ver, "--flags=" + a.flags, "-q"],
                   capture_output=True, text=True)
print(p.stdout[-3000:])
verdict = p.stdout.split("RESULT:")[-1].strip() if "RESULT:" in p.stdout else "COMPILE FAILED"
if a.apply and verdict.startswith("EXACT") and "DATA" not in verdict:
    name = a.name or sys.exit("--apply needs --name")
    dst = os.path.join("src", name)
    open(dst, "w").write(open(a.out).read())
    r = subprocess.run(["python3", "tools/absorb_data.py", dst, *a.ranges, "--create",
                        "--ver", a.ver, "--flags", a.flags], capture_output=True, text=True)
    print(r.stdout[-2000:], r.stderr[-1000:])
