#!/usr/bin/env python3
"""Infer translation-unit groupings from shared compiler-local data.

Usage:
  python3 tools/tu_infer.py <fn_name|0xADDR> [...] [--json out.json] [--max-text N]

CodeWarrior emits literal constants (floats, int->float bias doubles), string
pools and switch tables into the data sections of the file that uses them,
in link order.  A function referencing such data can only match in a unit
that owns that data, and every other function using the same bytes must be in
that unit too.  Starting from the given functions, this closes over:
  function -> referenced local-looking data (.sdata2/.rodata/.data/.sdata)
  data label -> every function referencing it
  text/data ranges -> contiguous spans (everything in between joins)
and reports the resulting text range, data ranges, the current units that
would be merged, and which functions are still unmatched.  Labels referenced
from very distant code (true globals) can be excluded with --max-text.
"""
import argparse, json, os, re, sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)

ap = argparse.ArgumentParser()
ap.add_argument("seeds", nargs="*")
ap.add_argument("--all-remaining", action="store_true",
                help="report the closure of every unmatched function (JSON lines)")
ap.add_argument("--json", default=None)
ap.add_argument("--max-text", type=lambda x: int(x, 0), default=0x8000,
                help="ignore labels whose users span more text than this")
ap.add_argument("--sections", default=".sdata2,.rodata,.data,.sdata")
ap.add_argument("--must-own", action="store_true",
                help="follow only data a unit cannot reference by name: switch "
                     "tables and int->float bias doubles")
ap.add_argument("--no-data-span", action="store_true",
                help="do not pull in labels lying between shared labels")
a = ap.parse_args()
DATA_SECS = a.sections.split(",")

# symbols
syms = {}
for line in open("config/GSQE78/symbols.txt"):
    m = re.match(r"(\S+) = (\S+):0x([0-9A-Fa-f]+);(?:.*?size:0x([0-9A-Fa-f]+))?", line)
    if m:
        syms[m.group(1)] = (m.group(2), int(m.group(3), 16), int(m.group(4), 16) if m.group(4) else 0)

# current units and their asm
report = json.load(open("build/GSQE78/report.json"))
unit_names = [u["name"][5:] for u in report["units"]]
splits = []
cur = None
for line in open("config/GSQE78/splits.txt").read().splitlines():
    if line and not line[0].isspace() and line.endswith(":") and not line.startswith("Sections"):
        cur = line[:-1]
    m = re.match(r"\s+(\S+)\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+)", line)
    if m and cur:
        splits.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16), cur))

fn_addr, fn_size, fn_refs, fn_unit = {}, {}, {}, {}
label_users = {}
for un in unit_names:
    path = f"build/GSQE78/asm/{un}.s"
    if not os.path.exists(path):
        continue
    curfn = None
    for line in open(path, errors="replace"):
        m = re.match(r"# \.text:0x[0-9A-F]+ \| (0x[0-9A-F]+) \| size: (0x[0-9A-F]+)", line)
        if m:
            pend = (int(m.group(1), 16), int(m.group(2), 16))
            continue
        m = re.match(r"\.fn (\S+?),", line)
        if m:
            curfn = m.group(1)
            fn_addr[curfn], fn_size[curfn] = pend
            fn_refs.setdefault(curfn, set())
            fn_unit[curfn] = un
            continue
        if line.startswith(".endfn"):
            curfn = None
            continue
        if curfn and "/*" in line:
            body = line.split("*/", 1)[-1]
            for nm in re.findall(r"([A-Za-z_@.$][\w@.$<>,]*)(?:\+0x[0-9A-Fa-f]+)?@(?:ha|l|h|sda21)", body):
                info = syms.get(nm)
                if info and info[0] in DATA_SECS:
                    fn_refs[curfn].add(nm)
                    label_users.setdefault(nm, set()).add(curfn)
            for nm in re.findall(r"\b(jumptable_[0-9A-F]{8})\b", body):
                fn_refs[curfn].add(nm)
                label_users.setdefault(nm, set()).add(curfn)

matched = set()
for u in report["units"]:
    for f in u.get("functions", []):
        if f.get("fuzzy_match_percent", 0) == 100.0 and u.get("metadata", {}).get("complete") is not False:
            pass
import csv
for row in csv.DictReader(open("progress/GSQE78-functions.csv")):
    if row["unit_status"] == "linked":
        matched.add(row["symbol"])

def resolve_seed(s):
    if s.startswith("0x"):
        v = int(s, 16)
        for n, ad in fn_addr.items():
            if ad == v:
                return n
        sys.exit(f"no function at {s}")
    return s

text_fns = sorted(fn_addr, key=lambda n: fn_addr[n])
import struct as _st
_dol = open("orig/GSQE78/main.dol", "rb").read()
_o = _st.unpack(">18I", _dol[0:72]); _ad = _st.unpack(">18I", _dol[72:144]); _sz = _st.unpack(">18I", _dol[144:216])


def _bytes(addr, n):
    for o, ad, sz in zip(_o, _ad, _sz):
        if sz and ad <= addr < ad + sz:
            return _dol[o + addr - ad:o + addr - ad + n]
    return b""


BIAS = (bytes.fromhex("4330000080000000"), bytes.fromhex("4330000000000000"))


def must_own(lab):
    if lab.startswith("jumptable_"):
        return True
    info = syms.get(lab)
    return bool(info and info[0] == ".sdata2" and _bytes(info[1], 8) in BIAS)


if a.must_own:
    for f in fn_refs:
        fn_refs[f] = {l for l in fn_refs[f] if must_own(l)}
    a.no_data_span = True


def closure(seeds):
    T = set(seeds)
    D = set()
    changed = True
    while changed:
        changed = False
        for f in list(T):
            for lab in fn_refs.get(f, ()):
                users = label_users.get(lab, set())
                span = max(fn_addr[u] for u in users) - min(fn_addr[u] for u in users)
                if span > a.max_text:
                    continue
                if lab not in D:
                    D.add(lab)
                    changed = True
                for u in users:
                    if u not in T:
                        T.add(u)
                        changed = True
        lo = min(fn_addr[f] for f in T)
        hi = max(fn_addr[f] + fn_size[f] for f in T)
        for f in text_fns:
            if lo <= fn_addr[f] < hi and f not in T:
                T.add(f)
                changed = True
        for sec in ([] if a.no_data_span else DATA_SECS):
            labs = [l for l in D if syms.get(l, ("",))[0] == sec]
            if not labs:
                continue
            dlo = min(syms[l][1] for l in labs)
            dhi = max(syms[l][1] + max(syms[l][2], 1) for l in labs)
            for l, users in label_users.items():
                info = syms.get(l)
                if info and info[0] == sec and dlo <= info[1] < dhi and l not in D:
                    span = max(fn_addr[u] for u in users) - min(fn_addr[u] for u in users)
                    if span <= a.max_text:
                        D.add(l)
                        changed = True
    lo = min(fn_addr[f] for f in T)
    hi = max(fn_addr[f] + fn_size[f] for f in T)
    res = {"text": [hex(lo), hex(hi)], "functions": [], "data": {}, "units": [], "unmatched": []}
    for f in sorted(T, key=lambda n: fn_addr[n]):
        res["functions"].append(f)
        if f not in matched:
            res["unmatched"].append(f)
    for sec in DATA_SECS:
        labs = [l for l in D if syms.get(l, ("",))[0] == sec]
        if labs:
            dlo = min(syms[l][1] for l in labs)
            dhi = max(syms[l][1] + max(syms[l][2], 1) for l in labs)
            res["data"][sec] = [hex(dlo), hex(dhi)]
    owners = set()
    for sec, s0, e0, u in splits:
        if sec == ".text" and s0 < hi and lo < e0:
            owners.add(u)
        if sec in res["data"]:
            d0, d1 = (int(x, 16) for x in res["data"][sec])
            if s0 < d1 and d0 < e0:
                owners.add(u)
    res["units"] = sorted(owners)
    return res


if a.all_remaining:
    seen = set()
    out = open(a.json, "w") if a.json else sys.stdout
    for f in text_fns:
        if f in matched or f in seen:
            continue
        r = closure({f})
        seen.update(r["functions"])
        out.write(json.dumps(r) + "\n")
    sys.exit(0)

res = closure({resolve_seed(s) for s in a.seeds})
print(json.dumps(res, indent=1))
if a.json:
    json.dump(res, open(a.json, "w"), indent=1)
