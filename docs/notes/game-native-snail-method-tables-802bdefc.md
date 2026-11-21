# Snail-family method and runtime-base records

Seven adjacent 460-byte groups at `0x802BDEFC..0x802BEDB8` now belong to
their preceding matching `native_rtti_base_lists_*.cpp` sources. Each group
contains a 184-byte method table, a 92-byte eleven-base runtime list, and a
second 184-byte method table. The first enclosing source grows to 712 bytes;
the other six grow to 552 bytes each. Together they add 3,220 verified data
bytes. Referenced functions and type descriptors remain with their existing
owners, and these sources remain partial views of the original translation
units.

The original groups begin at `0x802BDEFC`, `0x802BE124`, `0x802BE34C`,
`0x802BE574`, `0x802BE79C`, `0x802BE9C4`, and `0x802BEBEC`. Isolated GC/1.3.2
compiles reproduce every enlarged section byte, all 21 new symbol extents, and
all real relocations. The seven native objdiff reports each show 100% `.data`
matches; the first records 131 matching relocations, and the other six record
112 each. Evidence is retained in
`scratch/native_snail_method_tables_802BDEFC/`.

The standard full-DOL build retains the expected SHA1. `ninja changes`, the
generated progress check, and all 66 tests pass. The original unknown-unit
denominator remains in the report.
