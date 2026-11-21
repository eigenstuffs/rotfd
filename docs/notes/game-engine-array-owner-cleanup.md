# Engine array owner cleanup

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three complete ordinary C routines reconstruct 1,116 text bytes in independent
partial text splits, using standard Game GC/1.3.2 flags without additions:

| Source | Function | Original text |
| --- | --- | --- |
| `src/Game/engine_array_owner_pair.c` | `fn_8020C5CC` (376 bytes) | `8020C5CC..8020C744` |
| `src/Game/engine_array_owner_triple.c` | `fn_80231B28` (504 bytes) | `80231B28..80231D20` |
| `src/Game/engine_array_owner_handles.c` | `fn_8023AC94` (236 bytes) | `8023AC94..8023AD80` |

All functions require global scope. Their new dedicated header is
`include/Game/engine_array_owner_cleanup.h`; no existing shared declarations change.

The pair owner restores external original vtable 802EAFF0 at offset zero, then
cleans the 140-byte record array at 0x28 before the 24-byte record array at 0x1C.
The triple owner cleans the two-byte record array at 0x18, 16-byte record array
at 0xC and eight-byte record array at zero. Each array contains signed count,
capacity and items pointer at offsets zero, four and eight. Their trivial
element cleanup is expressed as ordinary empty loops, which reproduce the
compiler's native unrolled count loops. Storage is freed through existing
8028FD50 using original allocator 8028F698 and capacity times element size.
The repeated items-pointer resets preserve the original destructor behavior.

The handle owner restores external original vtable 802EC020 at offset 0x10,
then cleans its four-byte handle array at zero. Ordinary nested item and handle
cleanup helpers preserve the two null checks preceding existing handle destructor
801F7F10, called with deleting zero. All three routines conditionally delete
the owner through existing 801EF610 and original allocator 801EF5C8 when their
signed short deleting argument is positive, returning the original owner pointer.
The inline helpers emit no additional functions.

`scratch/engine_array_owner_cleanup_20261010u/final_integration.json` records
full extents, bindings, flags and all 32 actual address relocations. Fresh
production compilation and strict verification pass: every relocated byte
equals the protected original DOL without masking, and additional functions or
unexpected allocated sections are rejected. Complete original extents and the
full 3,141-entry extabindex, 24-entry ctor and 8-entry dtor scans pass with no
records referencing these functions. Source data, BSS, exception and startup
ownership are zero. Original vtables, allocator data, callees, neighboring text
and other original sections retain their current owners. Central NonMatching
registration and final DOL/native regression acceptance remain the integrator's
promotion steps. All research artifacts are preserved.
