# Early scalar and record initializer continuation

The accepted batch contains **106 partial source fragments, 108 complete
original functions, 12,028 text bytes and 1,880 native exception bytes** in
`80020000..800F0000`. The canonical manifest is
`config/GSQE78/candidates/game-scalar-early-more.json`. The complete native
DOL passes its original SHA-1 check; source extent and regression audits pass.
These fragments do not claim complete original translation units.

The recovered behavior includes validated signed 24-bit index / signed
8-bit generation handles, resolved flag clears and state queries, ordered
color copies, record selection and initialization. The lookup initializer
retains the original consecutive writes to `+254`. The previous/next
selection functions at `800B3E58..800B3FC8` shift six indices through active
80-byte records, leave unfilled slots unchanged and return the first search
result. Ninety-four complete record initializers occupy 93 source fragments;
they call `fn_80090084`, assign original external table pointers and initialize
observed fields. The table contents remain in their existing original owners.

## Reproduction and compiler choices

Run `python3 scratch/continuation_20261010/verify_early_more.py` for the final
current-source audit. It compiles all 106 sources using the exact canonical
flags, checks every allocated section and function/object extent, applies
all **711 actual relocations** and compares complete owned bytes against the
normalized original DOL. Address bits are not masked.

The two-stage queries at `8005E90C` and `8009FD38` require `-opt nocse` to
retain repeated manager-table loads. Previous/next selection uses `-opt space`
for its counted loops. The 93 initializer fragments use `-use_lmw_stmw on
-opt space -Cpp_exceptions on`; they emit the original combined register
saves/restores and native unwind metadata. Only adjacent functions with
identical flags are grouped. The handle initializer at `800AB190` and state
function at `800AB1FC` remain separate because their flags differ.

## Original data and exception ownership

Each of the 94 record initializers owns an eight-byte `extab` record and a
12-byte `extabindex` record. Those **1,880 bytes are reproduced by the native
compiler**, with its local record identities mapped to the same original
addresses. They receive complete-allocation verification alongside the text.
There are no owned constructor entries. External tables, constants and
neighboring original functions remain with their recorded owners.

The original agent handoff in
`scratch/game_scalar_early_more_continuation/final_integration.json` and its
verifier describe a superseded text-only stage. DTK transfers exception-index
ownership to the function's new unit and rejects separate index/function
owners. An exceptions-disabled trial omitted the records and failed the
original hash; it was not accepted. Enabling native exception generation
reproduced every original record without changing the matching text. The
canonical manifest above records this final implementation.

## Remaining probes

The selection initializer at `800B3FC8`, neighboring-grid query at `80072468`,
and several float/global-array routines still differ in allocation or
scheduling. Their probes remain uncredited. The startup array initializer at
`800AE2B8` preserves its original constructor reference in isolation but its
text does not match. Float normalization and distance routines still need
vector-temporary reconstruction. Failed probes and relocation-masked scores
are excluded from matching source.
