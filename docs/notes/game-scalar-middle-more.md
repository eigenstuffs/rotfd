# Engine setup and record continuation

This handoff contains **35 partial source fragments, 44 original functions,
and 3,728 text bytes** in `801B3028..801E23A0`. The functions are ordinary C
with private layouts inferred from the original field offsets, record strides,
loads, stores, branches, and calls. Versioned names preserve all existing ABI
entry points. No new central symbols, shared declarations, or build metadata
have been changed by this handoff.

The accepted canonical manifest is
`config/GSQE78/candidates/game-scalar-middle-more.json`. The original frozen
handoff and compiler/split/ownership evidence remain in
`scratch/game_scalar_middle_more_continuation/`. Every fragment was compiled
and strictly verified as NonMatching before promotion and full-DOL acceptance.

## Recovered behavior

- Visits of record arrays with verified strides 80 and 140, including two
  consecutive arrays owned by the same object.
- Mapped word updates, nullable name copying, lookup record removal using the
  original `memcpy`, and format-dependent copying with the original switch.
- Signed 24-bit index / signed 8-bit generation handle validation, comparison,
  vector copying through a resolved handle, reference assignment, and refresh/lookup
  visits of embedded handles and several arrays of handles.
- Root/resource setup, callback registration, conditional object release,
  buffer release, and nested setup/update forwarding.
- Construction of two vectors and copying/transforming a node's sixteen-vector
  buffer through the original compiler array-construction helper.
- Indexed resource visits, embedded state setup, and argument-order forwarding.

Only physically adjacent functions with identical verified compiler flags are
grouped. The source does not cover any intervening unmatched function or data.
The initial search in `800F0000..801B252C` found mostly SDK/runtime code and
native exception cleanup paths; this tranche instead uses the ordinary engine
range specified above. Native ABI, cache, paired-single, and runtime cleanup
routines are not credited.

## Strict verification

`python3 scratch/game_scalar_middle_more_continuation/verify.py` recompiles all
35 current production sources with GC/1.3.2 and verifies every emitted allocated
section and each function's binding, complete size, and section offset. The
verifier applies all **114 actual relocations** to their versioned addresses and
compares the complete resulting bytes against the normalized original DOL.
SDA21, ADDR16_HA/LO, and REL24 targets are resolved without masking instruction
bits. Unexpected nonempty allocated sections and unknown relocation targets
are rejected.

Every function's full original `.fn`/`.endfn` range was checked. The independent
ownership audit reads the original DOL's complete `extabindex` and `.ctors`
tables, rather than relying only on the current provisional text owner. None
of these 44 functions has an exception record or constructor-table reference.
The new fragments emit and claim **zero data bytes**. Original external tables,
constants, and unrelated neighboring functions remain in their original owners.

All fragments use the standard Game isolated flags except the handle comparison
at `801C0AB0`, which requires `-opt nocse` to preserve the original repeated
entry-table load through the cached manager. Exact flags and every relocation
are recorded in the manifest.

## Integration ownership caution

The previous early initializer batch demonstrated that DTK automatically moves
associated exception records when their function's text split moves. Text-only
handoffs with such records must either emit and strictly match the records
(using `-Cpp_exceptions on` where appropriate), or establish a linker-supported
original owner. Simply leaving metadata out of a proposed text split can drop
it during linking. This tranche's independent audit establishes that none of
its selected functions has such metadata; no exception ownership transfer is
needed here.

## Remaining probes

The preserved probes include a created-key lookup and parent-chain lookup,
bounded vector append, several constructors, handle-list search/acquire,
resource-resolution loops, and record-tail removal. Their semantics are
understood but register allocation, redundant induction variables, or control
flow still differs. None is in the canonical handoff. No failed or
relocation-masked probe score counts as reconstructed source.

## Accepted integration

Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.

`fn_801B3E54` refreshes a handle through key construction and map lookup; it
then retains the resolved object or clears the handle. Calls to that helper
are refresh/lookup visits. Earlier provisional release labels are superseded.
