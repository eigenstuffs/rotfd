# Native root-derived method tables at 0x802B23EC, 0x802B2518 and 0x802B2694

Three related original 39-slot method tables now come from C++ source. The
paired tables at `0x802B2518..0x802B2650` are in
`src/Game/native_root_method_pair_802B2518.cpp`. The tables at
`0x802B23EC..0x802B2488` and `0x802B2694..0x802B2730` are in their
respective preceding runtime-base-list units,
`src/Game/native_rtti_base_lists_802B23A8.cpp` and
`src/Game/native_rtti_base_lists_802B2650.cpp`. This preserves the original
eight-byte alignment of those enclosing sections and the four-byte offsets
of the method tables. The pointer targets retain their existing owners.

Private GC/1.3.2 compiles gave each table its original 156-byte extent and
38 address relocations. Standalone linking of the two tables beginning at
four modulo eight moved their addresses, so those rejected objects remain in
`scratch/native_root_method_table_alignment/`. Extending the two aligned base
list units restored the exact original addresses. Native objdiff reports
100% for both 224-byte merged sections, each with 46 matching relocations,
and 100% for the 312-byte paired-table unit with 76 matching relocations.
The three tables add 624 verified data bytes and 152 matching relocations;
the two previously source-owned 68-byte base lists retain their original
bytes and relocations.

The standard DOL SHA-1, `ninja changes`, generated progress check and all 66
tests pass. The original data denominator remains complete; the two old
standalone assembly units were merged into their enclosing source units.
