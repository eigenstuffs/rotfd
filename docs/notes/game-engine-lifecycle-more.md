# Engine owner-handle updates

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two ordinary C++ functions reconstruct 396 text bytes under
`src/Game/engine_lifecycle_more_*`. The frozen manifest is
`scratch/game_engine_lifecycle_more_continuation/final_integration.json`, with
exact split and configure snippets in `final_splits.txt` and `final_config.txt`.
Both use GC/1.3.2 and the standard game flags with exceptions off. The original
global entry-point names remain unchanged.

| Entry point | Text bytes | Recovered behavior |
| --- | ---: | --- |
| `fn_801C3854` | 212 | Replace the owner handle, verify it, invoke virtual slot 0x40, set an update flag and scalar field, and notify the existing services. |
| `fn_801DC3F4` | 184 | For a valid owner handle, resolve its object and replace the owner with the object's handle at offset 0xB8. |

Private address-suffixed declarations describe the verified eight-bit tag and
24-bit index, 16-byte registry entries, and manager record pointer at offset 8.
Replacement calls decrement the old reference and increment the new reference
through the existing manager API. The first function uses a private C++ base
prefix to place its virtual pointer at offset 8; it defines no vtable.

## Verification and ownership

The strict verifier recompiles both production sources and compares all
allocated section extents, function names/bindings/offsets/sizes, and **17 actual
relocations** against the normalized reference DOL. No relocation bits are
masked and no unexpected allocated section passes. The finalizer repeats this
verification after private type-name cleanup and source formatting.

`ownership_audit.json` records the original units' complete section ranges and
checks the true original assembly extents. Independent scans of the complete
original `.extabindex` and `.ctors` found no exception records or startup
references for either function. These are partial text units: all other
functions and data remain with their original owners. Whole-DOL hash and
regression checks remain with the integrator. Shared metadata, progress, and
the expected hash were not changed by this handoff.

## Uncredited research

The scratch directory preserves bounded probes for drawing-object constructors
`fn_801C822C` and `fn_801C9210`, factory `fn_801EB588`, image writer
`fn_801C932C`, closest-hit adapters `fn_801E04DC` and `fn_801E09E8`, and linked
resource query `fn_801D7CDC`. None belongs to the frozen manifest.

Genuine constructor AST probes for `0x801C9210` still coalesce the handle member
pointer rather than retaining the original register, including variants with
declared nontrivial handle destructors. The original external function names
were preserved; no aliases, assembly thunks, or metadata edits were introduced.
Several accepted source callers already depend on these provisional names.

For the image writer, `-use_lmw_stmw on -opt nostrength` preserves the original
per-row multiplication and leaves three loop-register assignments different.
The hit adapters preserve the original vector assignment operations but retain
different owner/context registers. Alternate compiler probes did not produce a
strict match. These diagnostic findings earn no matching credit.
