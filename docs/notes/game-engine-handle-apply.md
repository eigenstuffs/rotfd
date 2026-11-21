# Engine handle array updates

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three complete ordinary C++ routines reconstruct 952 text bytes in independent
partial text splits, using standard Game GC/1.3.2 options without additions:

| Source | Function | Original text |
| --- | --- | --- |
| `src/Game/engine_handle_apply_primary.cpp` | `fn_802460F8` (232 bytes) | `802460F8..802461E0` |
| `src/Game/engine_handle_apply_secondary.cpp` | `fn_8024877C` (232 bytes) | `8024877C..80248864` |
| `src/Game/engine_handle_apply_fixed.cpp` | `fn_802433C4` (488 bytes) | `802433C4..802435AC` |

All three functions require global scope. Their dedicated new header is
`include/Game/engine_handle_apply.h`; no existing shared declaration changes.
Each routine first calls the existing root predicate at 80207414. A false
signed-byte result returns zero. Otherwise each valid packed handle resolves
through the original context manager at offset 0x118 and dispatches virtual
slot 0x1C on its resolved object; the routine then returns one.

The primary owner stores count at 0x20 and its handle pointer at 0x28. The
secondary owner stores count at 0xBC and its pointer at 0xC4. The third routine
visits ten inline handles at 0x88, then the dynamic arrays with counts at 0xD8
and 0xE4 and pointers at 0xE0 and 0xEC. Reusing the logical loop variable in
its three loops preserves the original register allocation. Handles contain
signed eight-bit generation and signed 24-bit index fields. The original
validity function 801F7EB8 returns unsigned int. Resolution compares the signed
generation byte at entry offset 0xC, then reads the object at offset zero from
the manager's 16-byte entries. An ordinary declaration-only C++ virtual class
places the object's vptr at offset 8 without emitting a table or extra method.

`scratch/engine_handle_apply_20261010p/final_integration.json` records full
extents, bindings, flags, and all 14 actual address relocations. Fresh production
compilation and strict verification pass: all relocated bytes equal the
protected original DOL without masking, and unexpected allocated sections or
functions are rejected. Original complete extents and the entire 3,141-entry
extabindex, 24-entry ctor, and 8-entry dtor scans pass with no references to
these functions. Source data, BSS, exception, and startup ownership are zero.
Original manager/context data, callees, neighboring text and other original
sections retain their owners. Central NonMatching registration and final
DOL/native regression acceptance remain the integrator's promotion steps.

The paired refresh probes for 802431F8/802432A8 and notification probe for
80246F94 remain private and uncredited because their register allocation and
some indexed loads differ. All probes and diagnostic results are preserved.
