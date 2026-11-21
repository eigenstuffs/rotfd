# Engine resource records and lifetime continuation

Production integration is accepted under
`config/GSQE78/candidates/game-engine-records-more.json`. The original complete
DOL hash, regression checks, source extents, progress checks and all 26 unit
tests pass.

This distinct handoff contains **12 partial source fragments, 12 original
functions, 1,876 text bytes, zero data bytes, and 87 real relocations**. Sources
use the new `engine_records_more_` prefix. All preceding scalar, `engine_loop_`
and `engine_leaf_` handoffs remain frozen.

The canonical handoff is
`scratch/game_engine_records_more_continuation/final_integration.json`. Exact
proposed central edits are in `final_splits.txt` and `final_config.txt`;
`ownership_audit.json` records original section ownership and complete original
function extents. Existing versioned global symbols suffice. No central symbols,
splits, configure flags, or progress files were edited. Whole-DOL hash and
regression acceptance remain the integrator's responsibility.

## Recovered behavior

| Function | Text bytes | Observed behavior |
| --- | ---: | --- |
| `801C3780` | 212 | Reset 32-byte record storage for the original negative/positive count cases, including the original empty counted loops |
| `801C3CF0` | 168 | Check base readiness, validate/resolve an embedded handle, then call the observed virtual slot `+1C` |
| `801C9734` | 132 | Read the fixed resource field span and then two handle fields from a stream cursor |
| `801C99AC` | 112 | Install the original virtual table, invoke cleanup slot `+10`, and optionally release the object |
| `801C9B6C` | 148 | Read fixed resource fields, allocate the recorded byte count and copy the remaining payload while advancing the stream |
| `801C9C00` | 196 | Remove a registered resource through manager slot `+60`, invoke resource slot `+20`, destroy its base and optionally release it |
| `801CA30C` | 152 | Refresh/acquire eight observed embedded handles through `fn_801B3E54` |
| `801CDAC4` | 104 | Destroy a derived pool resource through its original base destructor and optional object release |
| `801CDBA4` | 148 | For flagged objects, remap the resource field in each 20-byte record using its queried key |
| `801CF8D4` | 204 | Detach the observed pool slot, destroy nested resource bases and optionally release the object |
| `801D3D54` | 124 | Remap the first field in each 16-byte resource record through the original key/query calls |
| `801E1870` | 176 | Destroy two embedded handles and seven 76-byte viewport records, then optionally release the owner |

Fields and strides are private observations. The stream routines preserve the
original integer address-difference calculation for the fixed span; their
existing copy helper remains separately owned. The resource pool uses 12-byte
records with the owner at `+4`, indexed through the original sentinel adjustment
`index+1`. Refresh calls are refresh/acquire operations, consistent with the
verified `801B3E54` helper, not release operations.

The C++ fragments use private storage bases and virtual declarations for the
observed dispatch offsets. This produces the original `r12` virtual-call sequence
without handwritten assembly or register bindings. These declarations emit no
new virtual tables or methods. Private type names include their fragment address
to avoid sharing provisional class definitions across translation units.

The two remapping loops use an ordinary private array `operator[]` returning a
record reference. This preserves the original destination evaluation before the
resource lookup call and reproduces the resulting compiler register allocation.
Raw C pointer probes retained emission differences and remain uncredited.

## Verification and ownership

`python3 scratch/game_engine_records_more_continuation/verify.py` recompiles every
current production source with GC/1.3.2. It checks every allocated section and
function's global binding, offset and full size, resolves all **87 actual** SDA21,
ADDR16_HA/LO and REL24 relocations against the versioned addresses, and compares
every claimed byte with the normalized original DOL. Unknown targets, unexpected
allocated sections, additional functions and shortened function extents are
rejected. No instruction/data bytes or relocation fields are masked.

Standard Game isolated flags suffice except:

- `801C3CF0`, `801C9B6C`, `801E1870`: `-opt nocse`.
- `801CDBA4`, `801D3D54`: `-use_lmw_stmw on -opt nocse`.

The independent original ownership audit scans the full DOL `extabindex` and
`.ctors` tables. **None of these 12 functions has an exception record or startup
constructor reference.** The fragments emit/claim zero data bytes. External
virtual tables, constants, native helper implementations, neighboring functions
and any other original data retain their existing owners. These partial text
fragments do not claim complete original translation units. No fragment spans a
disjoint text gap; the adjacent `801C9B6C`/`801C9C00` pair retains separate units
because its language/flags differ.

## Preserved research

Unmatched ownership-reset/update loops (`801D8580`, `801E1378`, `801D9ED0`) and
larger array/slot destructors (`801B252C`, `801C2F70`, `801E6FB0`, `801CFB08`,
`801D4E14`) retain their isolated probes and failure reports. They are excluded
from the canonical manifest and all matching totals. The scratch directory also
preserves earlier failed probes for functions subsequently verified here.
