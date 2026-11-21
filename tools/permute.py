#!/usr/bin/env python3
"""Random source permuter for near-miss CodeWarrior matches.

Usage:
  python3 tools/permute.py <src.cpp> <target.o> <function> [--ver V]
      [--flags="..."] [--extra="..."] [--iters N] [--jobs J] [--out DIR]
      [--region START_MARK END_MARK] [--seed S]

Repeatedly applies small token-level mutations to the body of <function>
(or to the text between two marker comments given with --region), compiles
each variant, and scores it with objdiff's match percent for <function>.
Hill-climbs from the best variant found so far; any variant scoring 100% is
written to <out>/match_<n>.cpp and reported.  Because acceptance is
byte-exact against the original, a 100% variant is semantically equivalent
to the original code; still review it for readability before use.

Mutations: swap adjacent statements in a block, reorder adjacent local
declarations, swap operands of commutative operators (+ * & | ^ == !=),
invert if/else, split `a = b op c` through a temporary of the same declared
type, toggle `const` on locals, and move a local declaration to first use.
"""
import argparse, json, os, random, re, shlex, subprocess, sys, tempfile, time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
os.chdir(ROOT)

GAME_CXX = ("-proc gekko -fp hardware -enum int -str reuse -common off -O4,s "
            "-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on "
            "-fp_contract on -i include")
ap = argparse.ArgumentParser()
ap.add_argument("src")
ap.add_argument("target")
ap.add_argument("function")
ap.add_argument("--ver", default="GC/1.3.2")
ap.add_argument("--flags", default=GAME_CXX)
ap.add_argument("--extra", default="")
ap.add_argument("--iters", type=int, default=400)
ap.add_argument("--jobs", type=int, default=4)
ap.add_argument("--out", default=None)
ap.add_argument("--region", nargs=2, default=None)
ap.add_argument("--seed", type=int, default=None)
a = ap.parse_args()
rng = random.Random(a.seed)
out_dir = a.out or tempfile.mkdtemp(prefix="permute")
os.makedirs(out_dir, exist_ok=True)
flags = shlex.split(a.flags) + shlex.split(a.extra)
lang = ["-lang=c++"] if a.src.endswith((".cpp", ".cc", ".cp")) else []

TOK = re.compile(r"""\s+|//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'|"""
                 r"""0[xX][0-9a-fA-F]+[uUlL]*|\d+\.?\d*(?:[eE][-+]?\d+)?[fFuUlL]*|"""
                 r"""[A-Za-z_]\w*|->|\+\+|--|<<=|>>=|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^]=|::|.""", re.S)


def lex(s):
    return [m.group(0) for m in TOK.finditer(s)]


def find_body(src):
    if a.region:
        i = src.index(a.region[0]) + len(a.region[0])
        j = src.index(a.region[1], i)
        return i, j
    m = re.search(r"\b" + re.escape(a.function) + r"\s*\([^;{]*\)\s*(?:const\s*)?\{", src)
    if not m:
        sys.exit("function definition not found")
    i = m.end()
    depth = 1
    j = i
    while depth:
        c = src[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        j += 1
    return i, j - 1


def statements(toks):
    """Return list of (start, end) token index ranges of statements at any depth,
    grouped by enclosing block: dict block_start -> [ranges]."""
    blocks = {}
    stack = [(-1, [])]
    start = 0
    depth_paren = 0
    i = 0
    while i < len(toks):
        t = toks[i]
        if t == "(":
            depth_paren += 1
        elif t == ")":
            depth_paren -= 1
        elif depth_paren == 0 and t == "{":
            stack.append((i, []))
            start = i + 1
        elif depth_paren == 0 and t == "}":
            bstart, rs = stack.pop()
            blocks[bstart] = rs
            if stack:
                stack[-1][1].append((start_of(toks, bstart), i + 1))
            start = i + 1
        elif depth_paren == 0 and t == ";":
            stack[-1][1].append((start, i + 1))
            start = i + 1
        i += 1
    blocks[-1] = stack[0][1]
    return blocks


def start_of(toks, brace):
    # walk back from a '{' to the start of its statement (if/for/while/else/do)
    j = brace - 1
    while j >= 0 and toks[j].isspace():
        j -= 1
    if j >= 0 and toks[j] == ")":
        depth = 0
        while j >= 0:
            if toks[j] == ")":
                depth += 1
            elif toks[j] == "(":
                depth -= 1
                if depth == 0:
                    break
            j -= 1
        j -= 1
        while j >= 0 and toks[j].isspace():
            j -= 1
        if j >= 0 and toks[j] in ("if", "for", "while", "switch"):
            k = j - 1
            while k >= 0 and toks[k].isspace():
                k -= 1
            if toks[j] == "if" and k >= 0 and toks[k] == "else":
                return k
            return j
    if j >= 0 and toks[j] in ("else", "do"):
        return j
    return brace


def is_decl(toks, r):
    s = "".join(toks[r[0]:r[1]]).strip()
    return bool(re.match(r"(const\s+)?(unsigned\s+|signed\s+)?[A-Za-z_]\w*(\s*::\s*\w+)*[\s*&]+[A-Za-z_]\w*\s*(=|;|\[)", s)) \
        and not re.match(r"(return|if|else|while|for|do|switch|case|goto|break|continue)\b", s)


def declared(toks, r):
    """Name introduced by a declaration statement, if any."""
    if not is_decl(toks, r):
        return None
    seg = [t for t in toks[r[0]:r[1]] if not t.isspace()]
    for k, t in enumerate(seg):
        if t in ("=", ";", "[", "(") and k > 0 and re.match(r"[A-Za-z_]\w*$", seg[k - 1]):
            return seg[k - 1]
    return None


def mutate(body):
    toks = lex(body)
    choice = rng.random()
    blocks = statements(toks)
    allr = [(b, rs) for b, rs in blocks.items() if len(rs) >= 2]
    if choice < 0.30 and allr:
        b, rs = rng.choice(allr)
        k = rng.randrange(len(rs) - 1)
        (s0, e0), (s1, e1) = rs[k], rs[k + 1]
        if e0 <= s1:
            seg0, mid, seg1 = toks[s0:e0], toks[e0:s1], toks[s1:e1]
            if any(x in ("case", "default", "return", "break", "goto", "continue") for x in seg0 + seg1):
                return None
            d0 = declared(toks, (s0, e0))
            d1 = declared(toks, (s1, e1))
            if (d0 and d0 in seg1) or (d1 and d1 in seg0):
                return None
            return "".join(toks[:s0] + seg1 + mid + seg0 + toks[e1:])
    if choice < 0.62:
        ops = [i for i, t in enumerate(toks) if t in ("+", "*", "&", "|", "^", "==", "!=")]
        if not ops:
            return None
        i = rng.choice(ops)
        # operand bounds: simple primary expressions (identifiers, member chains, literals, calls/parens)
        def left(i):
            j = i - 1
            while j >= 0 and toks[j].isspace():
                j -= 1
            end = j + 1
            depth = 0
            while j >= 0:
                t = toks[j]
                if t in (")", "]"):
                    depth += 1
                elif t in ("(", "["):
                    if depth == 0:
                        break
                    depth -= 1
                elif depth == 0 and not (re.match(r"\w", t) or t in (".", "->", "::") or t.isspace() and False):
                    break
                elif depth == 0 and t.isspace():
                    break
                j -= 1
            return j + 1, end
        def right(i):
            j = i + 1
            while j < len(toks) and toks[j].isspace():
                j += 1
            st = j
            depth = 0
            while j < len(toks):
                t = toks[j]
                if t in ("(", "["):
                    depth += 1
                elif t in (")", "]"):
                    if depth == 0:
                        break
                    depth -= 1
                elif depth == 0 and not (re.match(r"\w", t) or t in (".", "->", "::")):
                    break
                j += 1
            return st, j
        l0, l1 = left(i)
        r0, r1 = right(i)
        if l0 >= l1 or r0 >= r1:
            return None
        k = l0 - 1
        while k >= 0 and toks[k].isspace():
            k -= 1
        if k < 0 or toks[k] in (";", "{", "}", "const", ":", "unsigned", "signed"):
            return None  # statement-initial: likely a declaration like `T*x`
        if toks[l0 - 1:l0] and toks[l0 - 1] in ("-", "/", "%", "<<", ">>", "*", "&", "!", "~") and toks[i] in ("+", "|", "^"):
            return None
        if toks[i] == "*" and (l0 == 0 or not re.match(r"[\w)\]]", toks[l1 - 1])):
            return None  # pointer declaration or dereference
        if toks[i] == "&" and (not re.match(r"[\w)\]]", toks[l1 - 1])):
            return None
        return "".join(toks[:l0] + toks[r0:r1] + toks[l1:r0] + toks[l0:l1] + toks[r1:])
    if choice < 0.80:
        # reorder adjacent declarations
        cands = []
        for b, rs in blocks.items():
            for k in range(len(rs) - 1):
                if is_decl(toks, rs[k]) and is_decl(toks, rs[k + 1]):
                    n0 = declared(toks, rs[k])
                    if n0 and n0 in toks[rs[k + 1][0]:rs[k + 1][1]]:
                        continue
                    cands.append((rs[k], rs[k + 1]))
        if not cands:
            return None
        (s0, e0), (s1, e1) = rng.choice(cands)
        return "".join(toks[:s0] + toks[s1:e1] + toks[e0:s1] + toks[s0:e0] + toks[e1:])
    if choice < 0.90:
        # invert a simple if/else with brace blocks
        idx = [i for i, t in enumerate(toks) if t == "if"]
        rng.shuffle(idx)
        for i in idx:
            j = i + 1
            while toks[j].isspace():
                j += 1
            if toks[j] != "(":
                continue
            depth, k = 0, j
            while True:
                if toks[k] == "(":
                    depth += 1
                elif toks[k] == ")":
                    depth -= 1
                    if depth == 0:
                        break
                k += 1
            cond = "".join(toks[j + 1:k])
            m = k + 1
            while toks[m].isspace():
                m += 1
            if toks[m] != "{":
                continue
            d, n = 0, m
            while True:
                if toks[n] == "{":
                    d += 1
                elif toks[n] == "}":
                    d -= 1
                    if d == 0:
                        break
                n += 1
            p = n + 1
            while p < len(toks) and toks[p].isspace():
                p += 1
            if p >= len(toks) or toks[p] != "else":
                continue
            q = p + 1
            while toks[q].isspace():
                q += 1
            if toks[q] != "{":
                continue
            d, r = 0, q
            while True:
                if toks[r] == "{":
                    d += 1
                elif toks[r] == "}":
                    d -= 1
                    if d == 0:
                        break
                r += 1
            then_b = "".join(toks[m:n + 1])
            else_b = "".join(toks[q:r + 1])
            return "".join(toks[:i]) + f"if (!({cond})) {else_b} else {then_b}" + "".join(toks[r + 1:])
        return None
    # toggle const on a local declaration
    cands = []
    for b, rss in blocks.items():
        for rs in rss:
            nm = declared(toks, rs)
            seg = "".join(toks[rs[0]:rs[1]])
            if not nm or "[" in seg.split("=")[0] or "=" not in seg:
                continue
            after = "".join(toks[rs[1]:])
            if re.search(r"(\b%s\s*([-+*/%%&|^]?=(?!=)|\+\+|--))|((\+\+|--|&)\s*%s\b)" % (nm, nm), after):
                continue
            cands.append(rs)
    if not cands:
        return None
    s0, e0 = rng.choice(cands)
    seg = "".join(toks[s0:e0])
    lead = re.match(r"\s*", seg).group(0)
    rest = seg[len(lead):]
    if rest.startswith("const "):
        rest = rest[6:]
    else:
        rest = "const " + rest
    return "".join(toks[:s0]) + lead + rest + "".join(toks[e0:])


work = tempfile.mkdtemp(prefix="permw")


def score(src_text, tag):
    path = os.path.join(work, f"v{tag}{os.path.splitext(a.src)[1]}")
    obj = os.path.join(work, f"v{tag}.o")
    open(path, "w").write(src_text)
    r = subprocess.run(["build/tools/wibo", "build/tools/sjiswrap.exe",
                        f"build/compilers/{a.ver}/mwcceppc.exe", *flags, *lang,
                        "-c", path, "-o", obj], capture_output=True, text=True,
                       env={**os.environ, "MWCIncludes": "include"})
    if r.returncode or not os.path.exists(obj):
        return -1.0
    p = subprocess.run(["tools/objdiff-cli", "diff", "-1", a.target, "-2", obj,
                        "-o", "-", "--format", "json", a.function],
                       capture_output=True, text=True)
    try:
        d = json.loads(p.stdout)
    except Exception:
        return -1.0
    for s in d["left"]["symbols"]:
        if s["name"] == a.function:
            if not any(x["name"] == a.function for x in d["right"]["symbols"]):
                return -1.0
            return s.get("match_percent", 0.0)
    return -1.0


src = open(a.src).read()
b0, b1 = find_body(src)
pre, body, post = src[:b0], src[b0:b1], src[b1:]
best = score(src, "base")
print(f"base score {best:.3f}%")
cur_body, cur_score = body, best
seen = {body}
found = 0
stats = {"ok": 0, "fail": 0}
t0 = time.time()
with ThreadPoolExecutor(max_workers=a.jobs) as ex:
    it = 0
    while it < a.iters:
        batch = []
        for _ in range(a.jobs * 2):
            nb = cur_body
            for _ in range(rng.choice((1, 1, 1, 2, 3))):
                m = mutate(nb)
                if m:
                    nb = m
            if nb not in seen:
                seen.add(nb)
                batch.append(nb)
        if not batch:
            it += 1
            continue
        futs = [(nb, ex.submit(score, pre + nb + post, f"{it}_{k}")) for k, nb in enumerate(batch)]
        for nb, f in futs:
            sc = f.result()
            it += 1
            stats["ok" if sc >= 0 else "fail"] += 1
            if sc >= 100.0:
                found += 1
                path = os.path.join(out_dir, f"match_{found}{os.path.splitext(a.src)[1]}")
                open(path, "w").write(pre + nb + post)
                print(f"MATCH after {it} variants: {path}")
                sys.exit(0)
            if sc > cur_score or (sc == cur_score and rng.random() < 0.3):
                if sc > best:
                    best = sc
                    open(os.path.join(out_dir, "best" + os.path.splitext(a.src)[1]), "w").write(pre + nb + post)
                    print(f"[{it}] improved {sc:.3f}%  ({time.time() - t0:.0f}s)")
                cur_body, cur_score = nb, sc
print(f"no match; best {best:.3f}% (saved in {out_dir}); compiled {stats['ok']}, failed {stats['fail']}")
