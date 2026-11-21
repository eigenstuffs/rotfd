# Platform trigonometric interpolation and table initialization

This partial native math unit owns `.text 0x80284E34..0x8028531C`
(**1,256 bytes / five functions**) and the eight-byte integer-conversion bias
at `.sdata2 0x8037B878..0x8037B880`. It reconstructs tangent, sine and cosine
interpolation, the two-argument angle calculation, and table initialization.
Addresses remain the identifiers where original names are unknown.

The cosine table is sampled in 32-step quadrants. The sine path shifts the
input by the native double-precision half-pi constant before scaling. Both
paths use absolute value, signed integer conversion, weighted adjacent samples,
quadrant reflection and sign correction. Tangent inlines these two paths and
divides their results. Fused multiply-add is enabled by `-fp_contract on`.
Keeping the phase-path fraction in its original temporary reproduces the
native floating-point register allocation.

The angle routine preserves the all-zero case, native float absolute values
promoted to double, subtraction-based axis tests, a call to `atan`, and pi
adjustments. Common-subexpression elimination is disabled locally for this
function to preserve the native zero-constant reloads while borrowing the
existing constant. Ordinary C++ code reconstructs every instruction; no source
assembly or relocation masking is used.

Initialization fills 33 cosine samples using the native double step, rounds
the argument to float before calling `cos`, then fills 64 inverse-cosine
samples using a union to reinterpret the original constructed float bits.
Its shared signed loop variable is required for the original register moves.
The [lookup arrays](game-platform-trig-tables.md) now have separate verified
source ownership: 64 inverse-cosine values and 33 cosine values (388 BSS bytes).
Four following alignment bytes and remaining shared constants retain original
ownership. This matching split is not a claim of a complete original TU.

The original conversion bias had consumers in tangent and initialization
outside the first two-function probe. The initial partial promotion failed
with unresolved compiler-local constant references and earned no credit.
Recovering all five functions together resolves those consumers naturally;
all 50 actual relocations and every emitted allocated byte are checked by
`scratch/game_platform_trig/verify.py --production`.

Acceptance evidence: `scratch/platform_trig_build.log`,
`scratch/platform_trig_changes.log`, `scratch/platform_trig_link_proof.json`,
`scratch/platform_trig_tests.log`, `scratch/platform_trig_checkpoint.json`,
and `config/GSQE78/candidates/game-platform-trig.json`. The full DOL must be
byte-identical, native objdiff must match all owned code/data, previous sources
and the original baseline must remain unchanged, and all 23 tooling tests
must pass before this increment is accepted.
