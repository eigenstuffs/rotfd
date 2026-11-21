# Native method pair at 0x802B5EC0

`src/Game/native_method_pair_802B5EC0.cpp` owns the two 180-byte method tables at `0x802B5EC0` and `0x802B5F74`, followed by two 12-byte member-function records at `0x802B6028` and `0x802B6034`. The tables share most targets but retain their distinct runtime type pointers, destructors and overrides. The records encode virtual slots `0xD8` and `0xDC` with table offset eight. This is an ABI view of the four data objects; neighboring data and the target functions remain with their existing owners.

A private GC/1.3.2 C++ compile produced one 384-byte `.data` section with all four symbols at their original offsets. Native objdiff reports 100% for the data and 88 `R_PPC_ADDR32` relocations on each side. The standard DOL hash passes, `ninja changes` reports no regression, the progress/source-extent check passes, and all 66 tests pass.
