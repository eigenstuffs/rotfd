# Group-count initializer and letter-tile names

`src/Game/actor_alignment_count_template_8029ECF0.cpp` now owns 253 `.rodata`
bytes at `8029ECF0..8029EDED`. Its original nine-word initializer remains
unchanged. The extension adds a 64-byte `const int[16]`, ten complete strings
totaling 139 bytes, and 14 bytes of natural compiler alignment: 217 new bytes.

The original routine at `800A6528` copies eight pairs of words from `8029ED14`
into a 16-word stack array, then indexes, compares, increments, and stores the
values as signed group counts. This establishes the initializer's full capacity
and type. It is not padding inferred from a run of zero bytes.

The following nine `LETTER_TILE_*` resource names retain their observed order
and complete NUL-terminated extents. No direct relocation or data-pointer
consumer was found for those names; `force_active` retains their storage.
`SUBTITLE` has a direct original consumer at `800A7930`. The frozen audit
checked 6,869 active linker objects and twenty relevant actual relocations
from seven unchanged objects. It found no raw data pointers into the group.

All twelve compiler definitions are GLOBAL. No text, relocation, exception
metadata, undefined symbol, or weak allocation is emitted. The original
three-byte tail at `8029EDED..8029EDF0` remains explicitly owned by the existing
GLOBAL, alignment-one padding fragment and receives no source credit.

Frozen source evidence and the instruction-level type proof are in
`scratch/actor_group_count_template_8029ED14_20261020_parallel/`. Integration
backups and complete production proofs are in
`scratch/group_counts_integration_20261020/`. The historical successor checks
the complete current owner and unchanged original tail before accepting the
exact former 208-byte provider and 253-byte original-fragment receipts.

Acceptance: original DOL SHA-1, no match regressions, complete source extents,
and all 66 tooling tests pass. Generated data progress is 976,493 bytes
(94.7191%); code remains 1,937,408 bytes and 7,989 functions.
