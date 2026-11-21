# Eight root-derived native method tables

Eight related 39-slot method tables are now reconstructed at
`0x802B1EAC`, `0x802B1F8C`, `0x802B206C`, `0x802B214C`, `0x802B222C`,
`0x802B230C`, `0x802B2774`, and `0x802B2854`. They cover delivery-bag,
stick, jar, bag, acorn, pearlball, ironball, and beachball runtime types. Each
table contains its original runtime type pointer, zero metadata word,
destructor and 36 additional method targets. The methods themselves retain
their existing owners.

Every table begins four bytes past an eight-byte boundary. Each is therefore
placed immediately after its preceding, already matching runtime-base list
in the same C++ `.data` section. The eight source units are
`src/Game/native_rtti_base_lists_802B1D78.cpp`,
`src/Game/native_rtti_base_lists_802B1F48.cpp`,
`src/Game/native_rtti_base_lists_802B2028.cpp`,
`src/Game/native_rtti_base_lists_802B2108.cpp`,
`src/Game/native_rtti_base_lists_802B21E8.cpp`,
`src/Game/native_rtti_base_lists_802B22C8.cpp`,
`src/Game/native_rtti_base_lists_802B2730.cpp`, and
`src/Game/native_rtti_base_lists_802B2810.cpp`. This extends existing split
ranges without shifting any original symbol.

Private GC/1.3.2 compiles gave each new table its exact 156-byte extent and
38 address relocations. Native objdiff reports 100% for all eight enlarged
sections and their 395 combined relocations; 304 relocations belong to the
new tables. The standard DOL hash, `ninja changes`, progress check and all 66
tests pass. This adds 1,248 verified data bytes while preserving the original
total data denominator.
