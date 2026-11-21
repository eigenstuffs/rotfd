# Engine child start and handle rebinding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: one original function, 240 text bytes, zero data bytes, four actual relocations. `fn_801D9ED0` retains its external symbol and address range 0x801D9ED0..0x801D9FC0. The production C++ source is `src/Game/engine_handle_rebind_801D9ED0.cpp`, using the ordinary GC/1.3.2 hardware Gekko optimization flags with exceptions off.

The routine calls the original root slot1C directly. Failure returns zero. On success it visits records of stride 0x90 in the owner's array (count at 0xA4, pointer at 0xAC), checks each handle at record offset 0x88 using `fn_801F7EB8`, resolves matching signed 8-bit generation and signed 24-bit index against 16-byte manager entries, and dispatches the child's virtual slot 0x1C. It returns one after visiting all records. The private declarations only assert observed fields and virtual offsets. The native root method name is preserved.

`final_integration.json` freezes source SHA256 and the empty quoted-header inventory, every emitted allocated byte and symbol extent, and all actual relocation targets. `final_splits.txt` and `final_config.txt` contain proposed central edits. The source recompiles and strictly verifies through `verify.py`. There are no emitted data, BSS, padding, helper, or weak cleanup sections. The ownership audit finds no extabindex or constructor references. The remaining original fragment 0x801D8980..0x801DA800 stays original assembly: this is a partial text split, not a complete original translation unit. Parent integration and final DOL/regression checks remain required.

Uncredited research in the same scratch directory preserves `fn_801D0518` (192 bytes), a loop assigning each handle its resolved child's replacement handle, and `fn_801D8580` (164 bytes), invalidation of object and child registry-owner indices. The first still has 12 instruction register differences despite an exact extent. Raw byte registry storage gives the second the exact extent with three genuine address-formation differences; typed storage folds the sentinel offset and changes the extent. Ordinary accessors, reference/base-assignment shapes and bounded optimizer variations did not resolve these differences. Neither function has a production source or progress credit, and both reservations are released.
