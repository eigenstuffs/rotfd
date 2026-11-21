# Engine nested-array resize and cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two units/functions, 916 retained text bytes, zero data bytes, and 31 actual relocations. Both preserve the existing fn symbols and use GC/1.3.2 ordinary hardware Gekko flags plus `-use_lmw_stmw on`, with exceptions off. No native symbol renames are needed.

- `fn_801D4A1C`: 448 bytes and 19 actual relocations, 0x801D4A1C..0x801D4BDC. Resizes an array of 16-byte records with an untouched leading word and a nested array header at +4. Growth placement-constructs the three zeroed header words; shrink calls the existing record cleanup `fn_801D4BDC`. The keep flag controls whether storage capacity is retained.
- `fn_801D4C3C`: 468 bytes and 12 actual relocations, 0x801D4C3C..0x801D4E10. Cleans an array of 28-byte records. Each has an untouched leading word and two arrays of opaque 8-byte elements at +4 and +0x10. Elements have no observable destructor body; original empty traversal loops, data null checks, free sizes, and repeated clears are reproduced by ordinary private C++ lifetimes. A positive signed-short release flag returns the owner block to `fn_801EF610`.

The already accepted `fn_801D4BDC` passes its +4 member to `fn_801D4C3C`, establishing that the nested array in the 16-byte row contains the 28-byte row type. The resize source therefore uses a private constructor-only header view with opaque 28-byte records; its actual deletion remains the observed external call. An initial probe gave that header an unnecessary inline destructor with the wrong opaque-element size, producing an unused 208-byte weak helper. Before freezing, the constructor-only view was corrected and the unused helper eliminated. The retained resize bytes stay exact. No weak or helper bytes are emitted in either production object.

Strict production recompile verifies all allocated sections, all symbol extents, exact retained bytes, and every actual relocation. Source SHA256 and empty recursive quoted-header inventories are frozen in `scratch/game_engine_nested_arrays_continuation/final_integration.json`. Proposed central edits are in `final_splits.txt` and `final_config.txt`; `ownership_audit.json` preserves original ranges. The full extabindex, constructor, and destructor tables contain no records for either function. There is no emitted data, BSS, or padding.

These are partial text splits. The original 4-byte function at 0x801D4E10..0x801D4E14 remains original assembly. Existing external cleanup callers stay compatible, and parent integration must still pass the final DOL hash and regression checks.
