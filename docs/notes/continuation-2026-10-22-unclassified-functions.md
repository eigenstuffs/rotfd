# Unclassified function continuation, 2026-10-21/22

This continuation matches previously unclassified functions one automatic
unit at a time. Each source was verified with `tools/fdiff.py` against the
original split object (`EXACT`/`EXACT-WEAK`), registered as `Matching` with a
split for exactly its automatic unit, and accepted only after the full build
reproduced the original DOL hash. Work files and worker reports live in
`scratch/claude_match/<unit>/`; the worker procedure is
`scratch/claude_match/GUIDE.md`.

## Source techniques that recur

- **Shared pooled float literals.** The original translation units pooled
  literals such as `0.0f`, so one constant (for example `lbl_8037899C`) is
  referenced by dozens of now-separate units and cannot be owned by any one
  of them. Sources reference the existing label. Where the original reloads
  the literal and an extern label would be reused by common-subexpression
  elimination, sources read it once through `*(const float*)&label`, copy it
  into a local at the original load point, or wrap a small function in
  `#pragma opt_common_subs off` / `reset`.
- **Engine square-root helpers.** `fastSqrt` (`frsqrte f4,x; fres r,f4`) and
  `reciprocalSqrt` (`frsqrte`) are two-instruction inline-asm helpers already
  used by many matched units; every original use keeps `f4` fixed and the
  compiler built-ins insert an extra `frsp`.
- **Dead stack copies of vectors** come from inline helpers that return or
  bind `*this` by reference (`const Vec3& get() const`).

## Adjustor thunks

Multiple-inheritance adjustor thunks (`subi r3,r3,N; b target`) are emitted
by the compiler after the code of the unit that defines the class's key
function. Units whose class view already defined that function now name the
class after the original destructor (`Object_80074D40`, `Agent_80062E18`,
...), so the compiler emits `@N@__dt__<class>Fv` exactly where the original
has it. The thunk symbols were renamed in `symbols.txt` (they are weak, and the
original virtual tables reference them), and each unit's `.text` split grew by
the thunk size. Where the function before a thunk is itself a virtual method
(`80097524`, `80098020`, `80098998`, `800970F8`), it is now defined as that
method, which makes it the key function. Renamed method symbols:
`accumulate_800970F8__15Object_800969F0FPCf`,
`control_80097524__15Object_8009731CFiPv`,
`control_80098020__15Object_8009798CFv`,
`control_80098998__15Object_80098518Fv`,
`method_80061DD8__14Agent_80061AC0Fv`. Callers that used the old C names
were updated. Thunks referenced only from C++ data tables (which cannot name
`@N@` symbols) remain original.

## Data

`src/dolphin/ax/DSPCode.c` now supplies the 0x1F20-byte AX DSP program
`axDspSlave` as the halfword array the SDK ships.

## Not yet accepted

- `fn_800E8130`: code, relocations and exception index match, but two bytes
  of the action-17 extab record are uninitialized compiler memory (`3701` in
  the original, `3c6c` under WiBo); dtk 1.8.3's `extab clean` cannot parse
  action 17.
- Functions that convert integers to floats and share one compiler-generated
  bias double across several now-separate units need their original
  translation unit rebuilt as one source file (`scratch/claude_match/MERGE.md`).
