# Actor motion basis constant retry

This is private, uncredited research for `fn_8009DC60`, original text
`8009DC60..8009DF78` (792 bytes). It retries the preserved 19 probes in
`scratch/game_early_actor_motion_output` in a distinct directory,
`scratch/engine_actor_motion_basis_retry_20261011kl`. All 99 prior frozen files
and their frozen manifest remain unchanged. No production source or central
configuration changed.

The routine selects a motion calculation using the resolved resource state and
actor flags. Its fallback computes `input + velocity * delta`, and transforms a
forward vector by the resolved resource's 3-by-3 basis. The disabled-state path
first clears the actor velocity. The partial actor/resource views and the
generation-checked handle lookup are inherited from the verified old research.

The new structural result is ordinary numeric construction of the forward
vector: `basis * Vec3(0.0f, 0.0f, 1.0f)`. This closes all 18 floating-point
operand differences in the old best probe. The entire 792-byte instruction
sequence, including its frame, calls, branching and all floating-point
registers, agrees except four actual SDA operands selecting the constants.
The natural compiler pool contains `1.0f` followed by `0.0f`; the original
references require `0.0f` at `80378DD8` and `1.0f` at `80378DDC`. Therefore this
is not an exact object and cannot be credited independently.

The bounded source-definition experiment defines the original GLOBAL names as
ordinary `extern "C" const float` objects initialized to zero and one. Both
the named-variable and numeric-expression forms emit those two correct GLOBAL
objects followed by two additional compiler LOCAL objects, one and zero. All
four text SDA references still select the LOCAL duplicates. The compiler does
not merge these literals into the defined GLOBAL objects. Those variants also
remain uncredited; no pool was relabeled or patched.

Scalar dot helpers, strided dot helpers, column views, member multiplication,
named arguments and nested forward-vector helpers did not improve the 18-word
extern-constant result. A by-value input and a const temporary changed the
frame or code size. An aggregate row view emitted an extra read-only pool and
was discarded as a source shape. Every attempted source and compiler output is
preserved.

GC 1.3.2 with `-proc gekko -O4,s -Cpp_exceptions on -use_lmw_stmw on` reproduces
the expected text extent and native exception header. Seven representative
fresh compiles reproduce their original ELF bytes, complete symbol inventory,
all 12 actual relocations and all allocated sections. The only original
exception-table reference is index `8001B234`, covering the 792-byte function
and pointing to the eight-byte record at `8000FBA4`. All 3,144 original index
slots, 24 constructor slots and eight destructor slots were audited; this
function has no startup or shutdown table ownership.

The parent investigation identified a possible coherent original translation
unit beginning with the already matched initializer at `8009D964`. Its genuine
numeric field initializers may establish the original twelve-float pool order
before this routine and the adjacent unsigned conversion bias. That broader
recovery requires independent complete source, ownership, active-consumer and
actual-relocation proof, plus zero-credit preservation of existing owners.
This retry owns and credits none of that shared pool.

Reproducibility evidence is `private_verification.json`; the numeric result is
`numeric_literals.cpp` and `numeric_literals.json`. `preflight_v2.py` and
`verify_private_v2.py` preserve and document two private verifier bookkeeping
failures without changing any compiler input or accepted verifier core.
