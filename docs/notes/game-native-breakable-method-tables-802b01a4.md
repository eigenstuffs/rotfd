# Breakable method tables beside the wood-crate base list

The matching `BRK_WoodCrate` nine-base list at `0x802B0158` now also owns
the adjacent records at `0x802B01A4..0x802B03D0`: three 160-byte method
tables and the interleaved 76-byte nine-base list. These source records
refer to methods and type descriptors in their existing units. This is a
partial original translation unit; surrounding records remain separate.

An isolated GC/1.3.2 compile reproduced all 632 `.data` bytes, all five
symbol extents, and 135 relocations. The native full-game link passed the
original DOL SHA1 check and added 556 verified data bytes. Native objdiff
reports 100% for the enlarged section. `ninja changes`, the generated
progress check, and all 66 tests pass. The original code and data
denominator remains complete.

The separate ScriptAnim records at `0x802B4AB4..0x802B4C48` remain in
original assembly. Both a full 404-byte isolated probe and a 300-byte
method-table prefix matched their original section bytes and relocations,
but full native links changed the DOL layout. Both candidate integrations
were rolled back and receive no matching credit. Evidence is retained in
`scratch/native_script_anim_method_tables_802B4AB4/`.
