# Native volume method tables at 0x802B4404

`src/Game/native_rtti_base_lists_802B43D8.cpp` now owns the adjacent original
`0x802B4404..0x802B4608` data. This comprises three method tables (144, 132
and 160 bytes) and two interleaved four- and five-base runtime lists (36 and
44 bytes) for the LookAtIt, CarryInAndOut and Checklist volume interfaces.
The tables retain their original type pointers and method targets, which
remain owned by their existing code and runtime-type units.

Private GC/1.3.2 compilation placed all five symbols at their original
offsets. Native objdiff reports 100% for the resulting 560-byte section and
all 120 relocations; 115 relocations belong to the newly sourced records.
The standard DOL hash, `ninja changes`, generated progress check and all 66
tests pass. This adds 516 verified data bytes with no change to the total
data denominator.
