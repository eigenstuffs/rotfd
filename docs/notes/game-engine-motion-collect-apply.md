# Motion owner collection and position application

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

## Exact isolated handoff

`src/Game/engine_motion_collect_apply.cpp` reconstructs the complete original
`fn_80221A0C` extent at `0x80221A0C..0x80221EEC` (1,248 bytes). The original C
entry identity and every existing caller remain unchanged. Production integration
and original-DOL acceptance are pending with the integrator.

The routine clears the linked motion state when requested. Otherwise it resolves
the linked owner, transforms the two owner points by the linked matrix, offsets
the resource sphere and collects contacts. A nonempty collection returns zero.
The empty case clears two state bits, dispatches the contact and displacement,
queries the current point, applies the updated position and records its delta,
then completes the context callback and returns one.

## Ordinary source details

The collector takes two 64-bit masks, `0x00008FE000000002` and `0x68`.
The original `r6` holds only the intermediate high constant used to form
`0x8FE0` in `r7`; the ABI leaves that argument register unused before the two
64-bit arguments in `r7/r8` and `r9/r10`. A sixth source argument incorrectly
created a stack argument and shifted the vector locals.

The vector has an implicit trivial copy constructor. The inline matrix transform
returns a local vector assigned one coordinate at a time. In-place addition of
the transformed point to the copied sphere center preserves the original float
register lifetimes. Ordinary `fp_contract on` reproduces the matrix FMAs.
The contact view retains its complete 72-byte extent, including the unaccessed
last eight bytes; the result array holds 256 ordinary 40-byte records in 10,240
bytes and a signed count. Its empty element destructors naturally retain the
original two cleanup loops and large `0x2900` stack frame.

## Complete allocation and relocation evidence

Compile with GC/1.3.2, standard Game `-O4,p` / exceptions-off flags and
`-use_lmw_stmw on`. The unchanged compiler object emits only `.text` (1,388
bytes, alignment four): the exact strong entry (1,248 bytes) and one unused weak
`MotionCollectResults` destructor (140 bytes). The five retained real ELF
relocations resolve to the original targets; the weak backup has one delete
relocation. No retained allocation references that backup. No data, BSS,
exception tables, startup entries or vtables are emitted or claimed.

The full original extabindex `0x80015F60..0x8001F2C0`, ctors
`0x80299920..0x80299980` and dtors `0x80299980..0x802999A0` audits find no
references to the retained function. The shared global manager, float literal,
collector and adjacent functions retain their existing ownership.

Run `python3 scratch/engine_motion_collect_apply_20261011eu/verify.py` for the
strict complete allocation, actual relocation, original table and frozen-file
checks. `final_integration.json`, `allocation_discard_audit.json` and
`original_full_tables.json` preserve the evidence. All bounded diagnostic source
variants remain private in that isolated directory. No payload rewriting,
assembly, aliases, central configuration edits or consumer edits were used.
