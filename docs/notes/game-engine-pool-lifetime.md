# Engine nested record-pool lifetimes

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Four ordinary C++ functions reconstruct **1,740 text bytes**, with no owned
non-text data. The frozen handoff is
`scratch/game_engine_pool_lifetime_continuation/final_integration.json`, with
exact split/configure snippets in `final_splits.txt` and `final_config.txt`.
Every source uses GC/1.3.2 and the standard game flags with exceptions off.

| Original entry | Compiler entry | Bytes | Extra flags | Recovered behavior |
| --- | --- | ---: | --- | --- |
| `fn_801CA4C8` | unchanged | 496 | `-use_lmw_stmw on` | Install the camera-zone table, destroy the nested short-record pool at 0xE4 and the 0x44-byte record pool at 0xD8, then destroy the existing base. |
| `fn_801CA954` | `__dt__13Pool_801CA954Fv` | 468 | `-use_lmw_stmw on` | Destroy an array of 0x20-byte elements, each with two short-record pools, then conditionally free the outer allocation. |
| `fn_801CFB08` | unchanged | 388 | none | Destroy pools at 0x80 and 0x74 with element strides 4 and 12, then destroy the existing resource base. |
| `fn_801D4E14` | unchanged | 388 | none | Destroy pools at 0x80 and 0x74 with element strides 0xF8 and 12, then destroy the existing resource base. |

The private pool template describes the observed count/capacity/data layout at
0/4/8. Ordinary C++ destructors reproduce the original empty element loops and
nested lifetime checks. The nested camera-zone elements retain an additional
inline type layer. Private helper types are address-suffixed and define no
vtable or owned data. Conditional deallocation uses the existing game heap API.

## Native name and dependencies

Only `0x801CA954` requires a compiler-native definition rename. Its manifest
record contains `original_symbol=fn_801CA954`; the accepted-source caller audit
is empty. Rename that versioned definition to the native destructor symbol at
the same address. Original assembly callers and data retain the same targets.
No alias or assembly thunk is involved. Every dependency is recorded with its
versioned target address and section. The other three entry names remain fixed.

All four sources include frozen `source_sha256` hashes and recursive
`header_sha256` mappings in the manifest. They contain no quoted includes, so
the header mappings are empty.

## Verification and ownership

The strict verifier recompiles the production sources and compares complete
allocated sections, exact function bindings/offsets/sizes and **51 actual
relocations** against the normalized original DOL. No bits are masked; every
allocated byte is accounted for. The accepted objects emit no additional weak
functions, helper functions, data or exception records. The finalizer and strict
verifier passed after formatting and private type-name cleanup.

`ownership_audit.json` checks true original assembly function extents and
records each original unit's complete section ranges. Complete original
`.extabindex` and `.ctors` scans found no records or startup references for these
functions. This handoff owns partial text splits. Remaining original functions,
tables and other data remain with their original owners. Native whole-DOL hash,
source extent and regression checks remain with the integrator. This work did
not change shared metadata, progress or expected hashes.

## Uncredited probes

The scratch directory preserves bounded probes for `fn_801D4C3C`, `fn_801EB89C`
and `fn_801CA6B8`; none is in the manifest. The last now retains the correct
0xA0 native pool dependency and 0xAC nested component, but compiler common
subexpression choices retain two member pointers where the original reloads
through the containing object. Earlier probes used an incorrect 0xAC address
for the 0xA0 native pool, which the original assembly audit exposed and corrected.
Existing accepted callers of the other provisional entries keep their names.
These diagnostics receive no matching credit.
