# Checkpoint and Force volume method tables

`src/Game/native_rtti_base_lists_802B4608.cpp` and
`src/Game/native_rtti_base_lists_802B4780.cpp` now each extend an already
matching five-base runtime list with two 144-byte method tables and an
interleaved 44-byte five-base list. The newly sourced intervals are
`0x802B4634..0x802B4780` and `0x802B47AC..0x802B48F8`, covering the
Checkpoint, Cannon, Force and Springboard volume interfaces. Referenced
methods and runtime type records retain their existing owners.

Private GC/1.3.2 compiles placed all six new symbols at their original
offsets. Native objdiff reports 100% for both enlarged 376-byte sections,
with 80 matching relocations per section. The new records add 664 verified
data bytes and 150 matching relocations. The standard DOL hash,
`ninja changes`, generated progress check and all 66 tests pass; the
original data denominator remains complete.
