# Engine transform record traversal

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Four complete ordinary C++ functions are reconstructed in dedicated text-only
units, with new shared declarations in `include/Game/engine_transform_records.h`:

| Source suffix (`src/Game/engine_transform_record_`) | Function | Text range | Bytes | Extra flags |
| --- | --- | --- | ---: | --- |
| `dispatch.cpp` | `fn_8024C510` | `8024C510..8024C5D4` | 196 | None |
| `copy.cpp` | `fn_8024C5D4` | `8024C5D4..8024C708` | 308 | `-opt nocse` |
| `update.cpp` | `fn_8024C708` | `8024C708..8024C8CC` | 452 | None |
| `find.cpp` | `fn_8024BCA4` | `8024BCA4..8024BDA0` | 252 | `-use_lmw_stmw on -opt nocse` |

All use GC/1.3.2 with standard Game options plus the listed flags, require global
scope, and total 1,208 text bytes, zero data bytes, and 14 actual relocations.

The owner contains packed-handle arrays at 0x28, 0x38, and 0x6C with counts at
0x20, 0x30, and 0x64, a single handle at 0x2C, and group index at 0x3C. Handles
carry signed 8-bit generations and signed 24-bit indices. Resolution uses the
original context's manager at 0x118, its entry pointer at 8, and 16-byte entries
with object pointer at 0 and signed generation byte at 0xC. The observed object
virtual pointer is at 8.

The dispatch routine resolves each handle in the 0x6C array and invokes virtual
slot 0x54 for non-null objects. Copy resolves the corresponding group from the
original context's group manager at 0x144 and its 20-byte records at 0xB8. For
each non-null object in the owner's 0x28 array, it resolves the corresponding
group handle and copies position at 0xB8..0xC0, quaternion at 0xC8..0xD4, and
scale at 0xD8..0xE0, preserving separate component stores. It clears flag
0x40000 and sets flag 0x2000 in separate observed operations.

The update routine first calls the existing Root predicate and returns zero if
it fails. It validates the single 0x2C handle and each handle in the 0x38 array
through `fn_801F7EB8`, then resolves and dispatches virtual slot 0x1C. It also
resolves and dispatches the 0x6C array and returns one. A shared loop variable
preserves the original lifetime and register allocation across the two loops.
The find routine checks each 0x28-array handle, resolves both that handle and the
provided target through the same original manager, and returns the first index
whose object pointers compare equal, or -1 when none do.

Explicit manager reuse plus `-opt nocse` retains the original two entry-array
loads in copy and find. The group accessor inlines completely and preserves the
native register allocation without an additional helper. Declared virtual
methods have no bodies; no replacement methods or tables are emitted. All
original manager, group, table, context, and neighboring source-data ownership
remains unchanged. These source splits do not establish original whole
translation-unit boundaries.

`scratch/engine_transform_copy_20261010k/final_integration.json` records all four
complete extents, symbol bindings, exact flags, and real relocations. The final
production recompiles pass strict verification: all relocated bytes compare to
the protected original DOL without masking, and extra functions or unexpected
allocated sections are rejected. `audit.py` confirms complete original assembly
bounds and scans all 3,141 original extabindex entries, 24 ctor entries, and 8
dtor entries with no references into this text. Source data, BSS, exception,
and startup ownership are zero. Central NonMatching registration and original
DOL/native regression acceptance remain the integrator's promotion steps.

All initial C/C++ variants and near-match results are preserved in the new
scratch directory. Only the four exact production functions above receive
matching-source credit. No frozen previous handoff or shared central file was
modified.
