# Engine record, setup and heap continuation

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-engine-leaf.json`.

This independent handoff contains **16 partial C fragments, 22 original
functions, 2,172 text bytes, zero data bytes, and 80 real relocations**. The
sources use the new `engine_leaf_` prefix and preserve the original versioned
entry-point names. Earlier `engine_loop_` and scalar handoffs remain frozen.

The canonical handoff is
`scratch/game_engine_leaf_continuation/final_integration.json`. Exact proposed
central edits are in `final_splits.txt` and `final_config.txt`. Existing symbol
names suffice; no central symbols, splits, flags, or progress files were edited.
These fragments have passed integrator acceptance through the original
whole-DOL hash and regression checks.

## Recovered behavior

| Function(s) | Text bytes | Observed behavior |
| --- | ---: | --- |
| `801B5190` | 44 | Signed handle-index lookup of a linked 16-byte record |
| `801BAA54`, `801BBAF4` | 256 | Bounded eight-entry append to separate 44-byte vector/scalar record arrays |
| `801BC7DC` | 204 | Reset 16 records of stride 148, copy saved vector components and negate three components |
| `801C0DCC`, `801C0DE8` | 116 | Clear/query state and copy two vectors in indexed 168-byte records |
| `801C1790`, `801C17C0` | 76 | OR/query an indexed record's 64-bit mask |
| `801C2F5C` | 20 | Return the indexed 168-byte record's subobject at `+40` |
| `801EAC04` | 136 | Reset and resize the observed cache buffer through original allocation/release calls |
| `801EB3B4`, `801EB450` | 292 | Allocate derived resources, call their original base initializer and initialize observed fields |
| `801EB634` | 128 | Release sized buffer storage, clear three storage fields, optionally release the storage object |
| `801EBAD0`, `801EBB54` | 204 | Log invalid manager states and conditionally update the observed global float |
| `801EBE14` | 80 | Original ordinary-call reset sequence through video, graphics, pad and OS entry points |
| `801EC014` | 48 | Save/query the arena footer at the original `OSGetArenaHi()-FA00` address |
| `801ECBE0`, `801ECC44` | 184 | Manager/base destruction with original virtual-table stores and optional object release |
| `801ED9FC`, `801EDA54` | 176 | Conditional resource callbacks and exact 16-bit flag transitions |
| `801EF610` | 208 | Unlink an allocated header, insert/coalesce its free block, and update heap counters |

The coalescer uses the observed 12-byte used header (`size`, `previous`, `next`)
and 16-byte free header (`used-list anchor`, `size`, `previous`, `next`). The
heap free-list head/tail are at `+8/+C`, free-byte count at `+1C`, allocation
count at `+20`, and header-byte count at `+28`. It locates the next free block
by address, unlinks the used header, merges the preceding/following free blocks
when the original comparisons permit, and preserves all list writes and counter
updates. It is ordinary C with no inline assembly or register bindings. Local
declaration and assignment order reproduce the original register allocation and
load scheduling.

The record layouts are private to each fragment and assert only fields and
strides directly established by the original instructions. Provisional behavior
labels do not assert recovered original class names.

## Verification and ownership

`python3 scratch/game_engine_leaf_continuation/verify.py` recompiles all 16
current production sources with GC/1.3.2 and the standard Game isolated flags.
No extra flags are required. It checks all allocated sections and every global
function's binding, offset and full size, resolves all 80 SDA21, ADDR16_HA/LO and
REL24 relocations against their real versioned addresses, and compares every
claimed byte to the normalized original DOL. It rejects unknown relocation
targets, unexpected allocated sections, and additional functions. No bytes or
relocation fields are masked. The final grouped sources also pass this audit.

`ownership_audit.json` independently verifies each original assembly function's
complete extent and records its original unit's section ownership. It scans the
entire original `extabindex` and `.ctors` tables: **none of these 22 functions has
an exception record or constructor-table reference**. The fragments emit/claim
zero data bytes; all external data and neighboring original functions remain
with their existing owners. Only physically adjacent functions with identical
flags are grouped. These partial fragments do not claim their original complete
translation units.

## Preserved unmatched probes

The initialized 24-byte vector-record append at `801BA988` and nested buffer
resource factory at `801EB588` retain compiler-emission differences. All isolated
probe sources and failure reports remain in this tranche's scratch directory.
They are excluded from the canonical handoff and matching totals. Earlier
coalescer/accessor failures are preserved as research history; final production
sources passed the strict verifier.
