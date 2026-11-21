# Engine dispatch, viewport selection, and record setup

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Ten ordinary functions reconstruct 1,588 text bytes under
`src/Game/engine_dispatch_*`. The frozen handoff is
`scratch/game_engine_dispatch_continuation/final_integration.json`, with exact
split and configure snippets in `final_splits.txt` and `final_config.txt`.
These are provisional partial text units; neighboring original functions and
data retain their existing ownership. Whole-DOL integration remains with the
integrator.

All units use GC/1.3.2 and the standard game flags with exceptions off.
`fn_801C9F00` and `fn_801D890C` additionally require `-use_lmw_stmw on` and
`-opt nocse`. Seven units are C and three are C++.

| Entry point | Text bytes | Recovered behavior |
| --- | ---: | --- |
| `fn_801B3AD8` | 268 | Require a suitable state, set the manager's loading byte, hash the selected name, invoke its load slot, and update the state if the manager is active. |
| `fn_801B5C20` | 224 | Initialize manager records and its embedded bitset, register two existing callbacks, and clear status fields. |
| `fn_801C0B48` | 124 | Append a four-float vector to a ten-element array; replace its final element when full. |
| `fn_801C3D98` | 116 | Dispatch two virtual update methods according to the low two flag bits. |
| `fn_801C9F00` | 164 | Release each matrix bank, destroy the embedded bitset, and conditionally release the object. |
| `fn_801CF9A0` | 144 | Initialize a resource record, copy its vector prefix, set its final vtable, and assign the invalid identifier. |
| `fn_801D890C` | 116 | Transform a counted source-record array into destination records with observed strides 104 and 144 bytes. |
| `fn_801DC718` | 108 | Transform the remaining 40-byte records from a requested index, including the original special index case. |
| `fn_801E12E8` | 144 | Check command state and its enabled byte, convert the requested viewport count, and call the existing setup routine. |
| `fn_801E15A4` | 180 | Select a viewport and cache its dimensions and integer center coordinates. |

Private declarations retain observed offsets. C++ base prefixes place virtual
pointers at offsets 8, 36, and 2,832 without defining or taking ownership of
their vtables. The bounded vector insertion uses an ordinary placement copy
constructor, preserving the original destination check. The record suffix
routine forwards its third context argument to `fn_801DC5E8`; that callee's
original assembly establishes this argument even though the caller does not
otherwise inspect it. The separately owned transform, bit-search, allocator,
and runtime conversion implementations are not claimed by this tranche.

## Verification and ownership

`python3 scratch/game_engine_dispatch_continuation/verify.py` recompiles all
ten production sources and checks their complete allocated sections, function
names/bindings/offsets/sizes, and **63 actual relocations** against the normalized
reference DOL. No relocation bits are masked and no unexpected allocated
section is accepted. Verification was repeated after formatting and private
type-name cleanup.

`ownership_audit.json` records every original unit section and verifies each
function's complete original assembly extent. Independent scans of the full
original `.extabindex` and `.ctors` found **no exception records or startup
references for these ten functions**. Each source owns exactly its emitted
text. The handoff changes no shared symbols, splits, build registration,
progress totals, or expected hash; whole-DOL hash and regression checks are
required before acceptance.

## Preserved research

Unmatched probes for `fn_801C97B8` and `fn_801D0518` remain in the scratch
directory. Their handle-copy lifetime and register emission still differ from
the original; they are excluded from the frozen manifest and receive no
matching credit.
