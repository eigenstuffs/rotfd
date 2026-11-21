# Native agent tables at 0x802C8C80

`src/Game/native_agent_tables_802C8C80.cpp` owns `0x802C8C80..0x802C8DD8`: a 156-byte method table, a 52-byte six-base runtime list, and a second 136-byte method table. The tables retain distinct runtime type pointers, destructors and overrides while sharing many target functions. The source provides bounded ABI data views; the target methods and neighboring data stay with their existing owners.

A private GC/1.3.2 compile placed all three symbols at their original offsets. Native objdiff reports 100% for 344 data bytes and 76 `R_PPC_ADDR32` relocations on each side. The standard DOL hash, `ninja changes`, source extents, progress check and all 66 tests pass.
