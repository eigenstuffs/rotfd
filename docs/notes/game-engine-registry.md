# Engine registry lookups and factories

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Seven ordinary C++ functions reconstruct 1,532 text bytes under
`src/Game/engine_registry_*`. The frozen handoff is
`scratch/game_engine_registry_continuation/final_integration.json`, with exact
split and registration snippets in `final_splits.txt` and `final_config.txt`.
These are provisional partial text units, preserving the original global entry
points. Production integration and the whole-DOL checks remain with the
integrator.

All units use GC/1.3.2 and the standard game flags with exceptions off. Only
`fn_801B52EC` additionally requires `-use_lmw_stmw on`.

| Entry point | Text bytes | Recovered behavior |
| --- | ---: | --- |
| `fn_801B5054` | 316 | Find a live object's name, optionally constrain its registered type, and copy its handle to the caller; clear the handle on failure. |
| `fn_801B51BC` | 116 | Hash a type name and find its 16-byte registry record. |
| `fn_801B5230` | 188 | Follow the registered parent-key chain and query whether it reaches a requested parent. The original loop requires an index strictly greater than zero. |
| `fn_801B52EC` | 284 | Find a type by name, create an instance, generate its instance name, increment its reference counter, and register the resulting handle. Log a missing type. |
| `fn_801B5408` | 260 | Create a registered type with a name formatted from its current reference counter. |
| `fn_801B550C` | 216 | Create a registered type with an explicit name key. |
| `fn_801B57F8` | 152 | Visit occupied records through the existing bit-search API and clear their active byte. |

Private declarations describe only observed layouts. Type records have key,
parent key, factory pointer, and a 16-bit reference counter at offsets 0, 4, 8,
and 12. C++ key equality preserves the original comparison emission. Factory
results use the native four-byte handle return convention; the lookup entry
explicitly declares its observed output pointer. The handle contains an
eight-bit tag and a 24-bit index. The small generated-name format declaration
retains its observed eight-byte extent so CodeWarrior emits the original SDA
relocation. Names and behavior labels remain provisional.

## Verification and ownership

`python3 scratch/game_engine_registry_continuation/verify.py` recompiles all
seven production sources and verifies complete allocated-section extents,
function names/bindings/offsets/sizes, and **21 actual relocations** against the
normalized reference DOL. No relocation bits are masked and no unexpected
allocated section is accepted. The finalizer repeated verification after
formatting the source.

`ownership_audit.json` checks each function's complete original assembly extent
and records all sections of its original unit. Independent scans of the full
original `.extabindex` and `.ctors` found **no exception records or startup
references for these functions**. Each source owns exactly its emitted text;
all neighboring functions and data retain their existing ownership. The five
functions from `0x801B51BC` through `0x801B55E4` are physically contiguous, but
remain separate provisional sources to preserve their private declarations.
No shared symbols, splits, build registration, progress totals, or expected
executable hash were changed by this handoff.

## Preserved research

The scratch directory also preserves an unmatched 400-byte registry-append
probe for `fn_801B5664`. Its remaining initialization and loop-test emission
differs from the original, so it is excluded from the manifest and earns no
matching credit. The bit-search implementation called by `fn_801B57F8` is
separately owned and is not claimed by this tranche.
