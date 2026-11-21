# Engine menu array cleanup

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete ordinary C routines reconstruct 628 text bytes in independent
partial text splits:

| Source | Function | Original text | Additional flags |
| --- | --- | --- | --- |
| `src/Game/engine_menu_nested_cleanup.c` | `fn_8021B4B0` (324 bytes) | `8021B4B0..8021B5F4` | `-use_lmw_stmw on` |
| `src/Game/engine_menu_flat_cleanup.c` | `fn_8021B688` (304 bytes) | `8021B688..8021B7B8` | none |

Both functions require global scope and standard Game GC/1.3.2 flags with the
listed addition. The dedicated new header is
`include/Game/engine_menu_array_cleanup.h`; no existing declarations change.

The nested owner restores external original vtable 802EB2F0 at offset 8, cleans
wrapped handles at 0x5C and 0x58, then its 156-byte record array at 0x4C. Each
record cleans wrapped handles at 0x98 and 0x90 in that order. Ordinary item and
wrapped-handle cleanup helpers preserve the native two null checks before the
existing 801F7F10 handle destructor, called with deleting zero. The flat owner
restores external original vtable 802EB348 at offset 8, cleans its 144-byte
record array at 0x78, then its wrapped handles at 0x50 and 0x4C. Flat records
have trivial cleanup; an ordinary empty loop reproduces the native count loop.

Both arrays store signed count, capacity and items pointer at offsets zero,
four and eight. Storage is freed through existing 8028FD50 and original allocator
8028F698, using capacity times record size, with both observed pointer resets.
The routines then call existing MenuBase destructor 8021D7E4 with deleting zero,
optionally delete the owner through 801EF610 and original allocator 801EF5C8
when the signed short deleting argument is positive, and return the owner.
All logical helpers inline without emitting additional functions.

`scratch/engine_menu_array_cleanup_20261010v/final_integration.json` records
full extents, bindings, flags and all 24 actual address relocations. Fresh
production compilation and strict verification pass: all relocated bytes equal
the protected original DOL without masking; additional functions and unexpected
allocated sections are rejected. Complete original extents and the full
3,141-entry extabindex, 24-entry ctor and 8-entry dtor scans pass with no records
referencing the selected text. Source data, BSS, exception and startup ownership
are zero. Original vtables, allocator data, callees, neighboring text and other
original sections retain their owners. Central NonMatching registration and
final DOL/native regression acceptance remain the integrator's promotion steps.
All research artifacts are preserved.
