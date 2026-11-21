# Native volume method tables at 0x802B414C and 0x802B435C

Two existing runtime-base-list units now also own their adjacent original
method tables. `src/Game/native_rtti_base_lists_802B40C0.cpp` extends through
`0x802B4338` with three method tables (144, 124 and 144 bytes) and two
interleaved runtime-base lists (36 and 44 bytes). The lists preserve their
four- and five-base hierarchies. `src/Game/native_rtti_base_lists_802B4338.cpp`
extends through `0x802B43D8` with a 124-byte method table. Referenced
methods and runtime type records retain their existing owners.

The newly sourced intervals total 616 bytes. Private GC/1.3.2 compiles
placed all six new symbols at their original offsets. Native objdiff reports
100% for the enlarged 632- and 160-byte sections and all 158 combined
relocations, including 139 relocations in the newly sourced records. The
standard DOL hash, `ninja changes`, generated progress check and all 66
tests pass. The original data denominator is unchanged.
