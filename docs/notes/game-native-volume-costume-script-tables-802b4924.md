# Costume and Script volume method tables

The matching five-base runtime lists at `0x802B48F8` and `0x802B49C0`
now own their adjacent 156-byte method tables at `0x802B4924` and
`0x802B49EC`. These are the `Volume_ChangeCostume` and `Volume_Script`
interfaces. Referenced methods and type records remain in their existing
units; the enclosing source is still a partial original translation unit.

Isolated GC/1.3.2 compiles reproduce both 200-byte `.data` sections, all
four symbol extents, and all 43 relocations per section. Native objdiff
reports 100% for both sections. The original DOL SHA1, `ninja changes`,
generated progress check, and all 66 tests pass. This adds 312 verified
data bytes without changing the original denominator.

The adjacent input getter at `0x800B7214` was separately probed. Its C++
switch reproduces the original function and jump-table sizes, case order,
and all 64 jump-table bytes, but 98 text words still differ because the
compiler chooses a different byte-load addressing sequence. This getter
remains original and receives no matching credit.
