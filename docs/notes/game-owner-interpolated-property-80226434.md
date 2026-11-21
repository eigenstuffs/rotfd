# Owner interpolated property at 80226434

The isolated ordinary C++ definition in `src/Game/owner_interpolated_property_80226434.cpp` exactly reproduces all196 bytes at80226434..802264F8 under GC1.3.2, Gekko, O4,p, C++ exceptions off, RTTI off and use_lmw_stmw on. A fresh compile passes the strict whole-allocated-section verifier. The only normal allocated section is196-byte text aligned4; no RELA, helper, literal, owned data, BSS, exception metadata, constructor, weak code or padding is emitted.

The virtual slotE0 takes `unsigned long long mask, int index`. Its EABI mask occupies r5/r6 and index remains r7; r4 is an unused alignment gap. The ordinary mask0xFFFFFFC0000001C0ULL produces the native low-word LI448 before high-word LI-64. An incorrect pointer-plus-two-int declaration left those two instructions reversed. All three native vtables that use the property function also use accepted fn80224B7C at slotE0, whose ordinary implementation clears one64-bit record flag field at record+38. The class declaration preserves the physical vptr at8 and records pointer at188; records haveA8 stride and a three-float position at0.

The original GLOBAL C function identity,196-byte extent, and incoming ABI remain unchanged: owner r3, input position r4, output r5, copied output r6, index r7, interpolation factor f1. It clears the flags, computes input + indexed record position * t, writes output and copies its three components. The vector operators retain the original independent multiplies and additions.

`audit_owner_interpolated_property.py` scanned3,109,410 original aligned and unaligned byte positions across every initialized DOL segment. The only initialized pointers into this extent are three aligned vtable references to its entry; there are no direct code branches, absolute materializations, extabindex entries, ctor or dtor records. The fresh active-input audit covered6205 link inputs and133510 actual RELAs, with source, active-object and central-input hashes stable throughout. All three active function references retain GLOBAL binding and zero addend. All vtables, record storage, preceding code and following fn802264F8 remain original.

Frozen evidence lives in `scratch/game_frontier_20261012_b/owner_interpolated_property_80226434.cpp`, `.o`, `.owned.json`, and `_fresh.o`. The ownership manifest contains the complete actual section, symbol, relocation, raw-byte, native-pointer and active-input census. Integration remains root-owned and must pass the unchanged original DOL hash and match-regression checks before credit.

Production acceptance: this routine is now Matching. The unchanged full DOL
SHA-1, baseline comparison, exact native allocations/symbols/actual RELAs,
complete original section coverage, source extents and all 66 tests pass.
Evidence: `scratch/continuation_20261012_b/build-screen-property-sort-promote.log`
and `changes-screen-property-sort-promote.log`.
