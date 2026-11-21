# BalancingBall method and jump-table records

The existing matching base-list source at `0x802B7700` now also owns the
adjacent `0x802B7754..0x802B7998` data interval: 580 original bytes. It
contains two method tables, two arrays of three-word callback records, two
jump tables targeting interior labels of `fn_80071A64`, and a final array of
three-word records. The source preserves all seven new symbol extents and the
real relocation addends. Referenced functions and type descriptors remain
with their existing owners; this is a partial original translation unit.

Isolated GC/1.3.2 source reproduced all 664 bytes of the enlarged `.data`
section and its 116 real relocations. On the first full link, CodeWarrior's
linker discarded the unreferenced constant tail after the jump tables, moving
later data and failing the DOL hash. `#pragma force_active on` around that
single tail array retains its original 60 bytes without changing the emitted
section bytes or relocations. The standard build then matches the expected
DOL SHA1. Native objdiff reports 100% `.data` with 116 matching relocations;
`ninja changes`, the progress check, and all 66 tests pass. Private probes,
the failed-link evidence, and the accepted native report are retained in
`scratch/native_balancing_jump_tables_802B7754/`.
