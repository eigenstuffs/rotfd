#!/usr/bin/env python3
"""Compile one candidate source and diff it against an original split object.

Usage:
  python3 tools/fdiff.py <src.cpp|c> <unit|target.o> [symbol ...]
      [--ver GC/1.3.2] [--flags="..."] [--extra="..."] [--like src/x.c]
      [--all] [-q] [-o keep.o]

<unit> names the original object in build/GSQE78/obj (e.g. auto_fn_80020500_text,
or Game/foo for an existing split); a path ending in .o is used directly.
Without symbols, every function in the target object is compared.  The
default flags are the common game C++ set; --like copies the compiler and
flags build.ninja uses for an existing source.

Output: a side-by-side listing of differing target (left) and candidate
(right) instructions, a summary, the exact FLAGS used, and a verdict:

  EXACT            all functions and owned sections identical
  EXACT-WEAK       identical apart from weak out-of-line copies (e.g. inline
                   destructors referenced by exception actions) that the
                   linker discards because another unit owns them; each
                   function's own exception record is identical
  EXACT-DATA       code identical except that the candidate references its
                   own compiler-generated data (constants, string pools,
                   switch tables: DATA-MAP lines) where the target references
                   existing labels holding the same bytes (or, for tables,
                   the same code addresses); integration must move those
                   bytes into the unit
  EXACT-WEAK-DATA  both of the above
  NOT EXACT

This is an iteration aid; acceptance still requires the full DOL hash check
and `ninja changes`.
"""
import argparse, json, os, re, shlex, struct, subprocess, sys, tempfile

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, "tools"))
from elfmini import Elf  # noqa: E402

GAME_CXX = ("-proc gekko -fp hardware -enum int -str reuse -common off -O4,s "
            "-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on "
            "-fp_contract on -i include")
IGNORE = {".symtab", ".strtab", ".shstrtab", ".comment", ".note.split",
          ".mwcats.text", ".note"}

ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("unit")
ap.add_argument("symbols", nargs="*")
ap.add_argument("--ver", default="GC/1.3.2")
ap.add_argument("--flags", default=GAME_CXX)
ap.add_argument("--extra", default="")
ap.add_argument("--all", action="store_true", help="print matching rows too")
ap.add_argument("-q", action="store_true", help="summary only")
ap.add_argument("-o", default=None, help="keep compiled object here")
ap.add_argument("--like", default=None,
                help="use the compiler and flags build.ninja has for this source")
a = ap.parse_args()

if a.like:
    like = a.like[4:] if a.like.startswith("src/") else a.like
    stem = like.rsplit(".", 1)[0]
    nin = open("build.ninja").read().replace("$\n", " ")
    m = re.search(r"^build build/GSQE78/src/" + re.escape(stem) +
                  r"\.o: .*?\n((?:  .*\n)+)", nin, re.M)
    if not m:
        sys.exit(f"no build.ninja entry for {like}")
    body = m.group(1)
    a.ver = re.search(r"mw_version = (\S+)", body).group(1)
    fl = re.search(r"cflags = (.*)", body).group(1).split()
    a.flags = " ".join(f for f in fl if f not in ("-lang=c", "-lang=c++"))

target = a.unit if a.unit.endswith(".o") else f"build/GSQE78/obj/{a.unit}.o"
if not os.path.exists(target):
    sys.exit(f"no target object {target}")

tmp = tempfile.mkdtemp(prefix="fdiff")
out = a.o or os.path.join(tmp, "cand.o")
flags = shlex.split(a.flags) + shlex.split(a.extra)
if a.src.endswith((".cpp", ".cp", ".cc")) and "-lang=c++" not in flags:
    flags.append("-lang=c++")
cmd = ["build/tools/wibo", "build/tools/sjiswrap.exe",
       f"build/compilers/{a.ver}/mwcceppc.exe", *flags, "-c", a.src, "-o", out]
r = subprocess.run(cmd, capture_output=True, text=True,
                   env={**os.environ, "MWCIncludes": "include"})
if r.returncode != 0 or not os.path.exists(out):
    print("COMPILE FAILED\n" + r.stdout + r.stderr)
    sys.exit(1)
if r.stdout.strip():
    print(r.stdout.strip()[:2000])

p = subprocess.run(["tools/objdiff-cli", "diff", "-1", target, "-2", out,
                    "-o", "-", "--format", "json",
                    a.symbols[0] if a.symbols else ""],
                   capture_output=True, text=True)
if p.returncode != 0:
    sys.exit("objdiff failed: " + p.stderr)
d = json.loads(p.stdout)
lsyms, rsyms = d["left"]["symbols"], d["right"]["symbols"]
left = [s for s in lsyms if s.get("kind") == "SYMBOL_FUNCTION"]
right = {s["name"]: s for s in rsyms if s.get("kind") == "SYMBOL_FUNCTION"}
names = a.symbols or [s["name"] for s in left]
MARK = {"DIFF_REPLACE": "R ", "DIFF_DELETE": "D ", "DIFF_INSERT": "I ",
        "DIFF_OP_MISMATCH": "O ", "DIFF_ARG_MISMATCH": "A "}

summary = []
for s in left:
    if s["name"] not in names:
        continue
    mp = s.get("match_percent", 0.0)
    rs = right.get(s["name"])
    summary.append((s, rs, mp if rs else None))
    if a.q or rs is None:
        continue
    li, ri = s.get("instructions", []), rs.get("instructions", [])
    print(f"== {s['name']} target {s.get('size')}B cand {rs.get('size')}B match {mp:.2f}%")
    for i in range(max(len(li), len(ri))):
        lx = li[i] if i < len(li) else {}
        rx = ri[i] if i < len(ri) else {}
        lt = lx.get("instruction", {}).get("formatted", "") if lx else ""
        rt = rx.get("instruction", {}).get("formatted", "") if rx else ""
        kind = lx.get("diff_kind") or rx.get("diff_kind") or ""
        if not kind and not a.all:
            continue
        addr = lx.get("instruction", {}).get("address", "") if lx else ""
        try:
            addr = f"{int(addr or 0):5x}"
        except ValueError:
            pass
        print(f"{MARK.get(kind, '  ' if not kind else '? ')}{addr} {lt:<44} | {rt}")

print("-- summary")
for s, rs, mp in summary:
    if mp is None:
        print(f"  {s['name']:<40} {int(s.get('size', 0)):6d}B  MISSING in candidate")
    else:
        print(f"  {s['name']:<40} {int(s.get('size', 0)):6d}B cand "
              f"{int(rs.get('size', 0)):6d}B  {mp:7.3f}%")
lsec = {s["name"]: s for s in d["left"]["sections"]}
rsec = {s["name"]: s for s in d["right"]["sections"]}
for sec in d["left"]["sections"]:
    if "match_percent" in sec:
        print(f"  section {sec['name']:<12} {sec.get('size')}B {sec['match_percent']:.3f}%")

# ---- verdict ---------------------------------------------------------------
problems = []
te, ce = Elf(target), Elf(out)
dol = open("orig/GSQE78/main.dol", "rb").read()
dofs = struct.unpack(">18I", dol[0:72])
dads = struct.unpack(">18I", dol[72:144])
dszs = struct.unpack(">18I", dol[144:216])


def dol_bytes(addr, n):
    for o, ad, sz in zip(dofs, dads, dszs):
        if sz and ad <= addr < ad + sz:
            return dol[o + addr - ad:o + addr - ad + n]
    return None


symaddr = {}
for line in open("config/GSQE78/symbols.txt"):
    m = re.match(r"(\S+) = (\S+):0x([0-9A-Fa-f]+);(?:.*?size:0x([0-9A-Fa-f]+))?", line)
    if m:
        symaddr[m.group(1)] = (m.group(2), int(m.group(3), 16),
                               int(m.group(4), 16) if m.group(4) else None)
# candidate .text offset -> final address, via functions shared with the target
ctext = {}
for c in ce.symbols:
    if c["type"] == 2 and c["name"] in symaddr:
        ctext.setdefault(c["shndx"], []).append((c["value"], c["size"], symaddr[c["name"]][1]))


def final_addr(sym, addend):
    """Final address of a candidate relocation target, if determinable."""
    if sym["name"] in symaddr and sym["type"] != 3:
        return symaddr[sym["name"]][1] + addend
    for v, size, ad in ctext.get(sym["shndx"], []):
        off = sym["value"] + addend
        if v <= off < v + size:
            return ad + off - v
    return None


def data_matches(sym, tinfo):
    """Compare a candidate data symbol with the original bytes at tinfo."""
    size = sym["size"] or tinfo[2] or 4
    cb = bytearray(ce.data(sym["shndx"])[sym["value"]:sym["value"] + size])
    tb = dol_bytes(tinfo[1], size)
    for rr in ce.relocs.get(sym["shndx"], []):
        o = rr["offset"] - sym["value"]
        if 0 <= o < size:
            if rr["type"] != 1 or not rr["sym"]:  # R_PPC_ADDR32 only
                return False
            fa = final_addr(rr["sym"], rr["addend"])
            if fa is None:
                return False
            cb[o:o + 4] = struct.pack(">I", fa)
    return bytes(cb) == tb


data_map = {}
for s, rs, mp in summary:
    if mp is None:
        problems.append(f"{s['name']} missing")
        continue
    if mp == 100.0:
        continue
    li, ri = s.get("instructions", []), rs.get("instructions", [])
    if len(li) != len(ri):
        problems.append(f"{s['name']} {mp:.3f}%")
        continue
    for lx, rx in zip(li, ri):
        if not (lx.get("diff_kind") or rx.get("diff_kind")):
            continue
        lr = lx.get("instruction", {}).get("relocation")
        rr = rx.get("instruction", {}).get("relocation")
        strip = lambda ins: [q for q in ins["instruction"]["parts"]
                             if not ("arg" in q and q["arg"].get("reloc"))]
        if not (lr and rr and lr.get("type") == rr.get("type") and strip(lx) == strip(rx)):
            problems.append(f"{s['name']} {mp:.3f}%")
            break
        lname = lsyms[lr["target_symbol"]]["name"]
        rname = rsyms[rr["target_symbol"]]["name"]
        la, ra = int(lr.get("addend", 0)), int(rr.get("addend", 0))
        info = symaddr.get(lname)
        csym = next((c for c in ce.symbols if c["name"] == rname
                     and 0 < c["shndx"] < 0xFF00), None)
        if not info or not csym:
            problems.append(f"{s['name']}: reloc {lname} vs {rname}")
            break
        # compare the candidate bytes at symbol+addend with the target bytes
        # at label+addend (pooled literals are addressed with addends)
        sub = dict(csym)
        sub["value"] = csym["value"] + ra
        sub["size"] = max((csym["size"] or 0) - ra, 0) or (info[2] or 4)
        tinfo = (info[0], info[1] + la, sub["size"])
        if not data_matches(sub, tinfo):
            problems.append(f"{s['name']}: {rname}+{ra} contents differ from {lname}+{la}")
            break
        key = f"{rname}+{ra}" if ra else rname
        data_map[key] = (ce.sections[csym["shndx"]]["name"], sub["value"],
                         sub["size"], f"{lname}+0x{la:X}" if la else lname, info[1] + la)

tnames = {s["name"] for s in left}
weak_extras = []
for s in rsyms:
    if s.get("kind") == "SYMBOL_FUNCTION" and s["name"] not in tnames:
        if s.get("flags", {}).get("weak"):
            weak_extras.append(s["name"])
        elif not a.symbols:
            problems.append(f"candidate-only function {s['name']}")

# function order: objdiff pairs functions by name, but the link places them in
# object order (weak copies are dropped), so the order must agree
def fn_order(elf, skip):
    t = [i for i, sec in enumerate(elf.sections) if sec["name"] == ".text"]
    fs = sorted((s["value"], s["name"]) for s in elf.symbols
                if s["type"] == 2 and s["shndx"] in t and s["name"] not in skip)
    return [n for _, n in fs]
torder = [n for n in fn_order(te, set()) if not a.symbols or n in names]
corder = [n for n in fn_order(ce, set(weak_extras)) if n in torder]
if corder != torder:
    problems.append("function order differs: target " + ",".join(torder[:6]) +
                    " candidate " + ",".join(corder[:6]))

ext_secs = [lsec[n] for n in ("extab", "extabindex") if n in lsec]
ext_bad = any(x.get("match_percent", 100.0) != 100.0 for x in ext_secs) or (
    not ext_secs and any(n in rsec and int(rsec[n].get("size", 0))
                         for n in ("extab", "extabindex")))
if ext_bad or (weak_extras and ext_secs):
    if not weak_extras and ext_bad:
        problems.append("exception tables differ")
    for s, rs, mp in summary:
        tr, cr = te.extab_record(s["name"]), ce.extab_record(s["name"])
        if (tr is None) != (cr is None):
            problems.append(f"extab record presence differs for {s['name']}")
        elif tr is not None:
            (tb, trel, tlen), (cb, crel, clen) = tr, cr
            n = min(len(tb), len(cb))
            same = (tb[:n] == cb[:n] and not tb[n:].strip(b"\0")
                    and not cb[n:].strip(b"\0") and trel == crel and tlen == clen)
            print(f"  extab record {s['name']}: {'identical' if same else 'DIFFERENT'}")
            if not same:
                problems.append(f"extab record {s['name']} differs")

for sec in d["left"]["sections"]:
    nm = sec["name"]
    if "match_percent" not in sec or nm in ("extab", "extabindex"):
        continue
    if sec.get("kind") == "SECTION_CODE" and (a.symbols or weak_extras or data_map):
        continue
    if sec["match_percent"] != 100.0:
        problems.append(f"section {nm} {sec['match_percent']:.3f}%")
mapped = {}
for v in data_map.values():
    mapped[v[0]] = mapped.get(v[0], 0) + v[2]
for nm, sec in rsec.items():
    if nm in IGNORE or nm.startswith((".rela", ".mwcats")) or nm in lsec or nm in ("extab", "extabindex"):
        continue
    if int(sec.get("size", 0)):
        if nm in mapped:
            print(f"  candidate-owned data {nm} {sec.get('size')}B, {mapped[nm]}B mapped (see DATA-MAP)")
        else:
            problems.append(f"candidate-only section {nm} {sec.get('size')}B")
for nm, sec in lsec.items():
    if nm in IGNORE or nm.startswith(".rela") or nm in rsec:
        continue
    if int(sec.get("size", 0)) and "match_percent" not in sec:
        problems.append(f"target section {nm} missing in candidate")

if weak_extras:
    print(f"  weak extras (discarded at link): {', '.join(weak_extras)}")
for rname, (sname, off, size, lname, addr) in sorted(data_map.items(), key=lambda x: x[1][4]):
    print(f"  DATA-MAP {sname}+0x{off:X} ({size}B, {rname}) -> {lname} 0x{addr:08X}")
for pr in problems[:12]:
    print(f"  problem: {pr}")
shown = " ".join(f'"{f}"' if " " in f else f for f in flags if f != "-lang=c++")
print(f"FLAGS: --ver {a.ver} --flags='{shown}'")
if problems:
    verdict = "NOT EXACT"
else:
    verdict = "EXACT" + ("-WEAK" if weak_extras else "") + ("-DATA" if data_map else "")
print("RESULT: " + verdict + (" (for the listed symbols only)" if a.symbols else ""))
