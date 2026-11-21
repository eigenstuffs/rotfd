# Menu RTTI names and named-mode scalar pool

Two existing source owners now include their adjacent typed data. The change
adds 209 matching bytes while preserving every earlier GLOBAL symbol and byte.

`menu_parser_literal_pools_802A0400.cpp` extends its readonly section from
802A0519 to 802A054A. Three complete RTTI names (`Activable_Z`, `Manipulator_Z`,
`ManipulatorDraw_Z`) and five bytes of natural alignment add 49 bytes. The
following six bytes remain in the original object under an explicit GLOBAL
align1 symbol.

`scalar_constant_80378800.c` extends its small readonly section from 80378804
to 803788A4, adding 160 bytes. Its original 100.0f constant is unchanged. The
new declarations contain -1612.0f, the signed integer conversion double,
a fixed four-byte empty name, and eighteen eight-byte `HIDE_01`/`SHOW_01`
through `HIDE_09`/`SHOW_09` arrays. Existing callers establish the array types;
the original conversion instruction sequence establishes the double. The
following four bytes retain explicit original ownership.

The complete native input census found 61 relevant relocations in 14 consumers,
including 39 direct references to the new names. Three RTTI pointers also agree
with their original DOL bytes. No caller source or object changed. Both complete
source objects contain only initialized data, with no relocations, code, weak
definitions, or undefined symbols. Their existing compiler versions and flags
are unchanged.

The frozen evidence is in
`scratch/menu_and_named_mode_strings_20261020_parallel/`.
`scratch/menu_named209_integration_20261020/verify_production.py --linked`
checks 494 complete native bytes, all GLOBAL extents, unchanged consumers and
the ten bytes of original residual ownership. The full DOL hash,
`ninja changes`, source extent audit and all 66 tests pass. Bounded operational
history routes preserve the earlier source, object and ownership receipts.
