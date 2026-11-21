# LOD and split argument pool at 802ACD70

The original-only `802ACD70..802ACE98` interval contains 15
NUL-terminated strings used by LOD, split, and resource argument handling.
Six preceding bytes at `802ACD6A..802ACD70` were a separate padding unit.
Both intervals now belong to `src/Game/engine_game_strings_802ACD08.cpp`,
along with the accepted strings before and after them. Its compiler-owned
`.rodata` extent is `802ACD08..802ACEBA` (434 bytes). This remains a partial
data split: the original `802ACEBA..802ACED0` interval and other neighboring
data remain outside it.

GC/1.3.2 emits the exact original bytes with no code or relocations. The 15
new global names retain their original addresses and sizes in the final ELF.
Native alignment on the first recovered string and the following accepted
array accounts for the boundary bytes. `#pragma force_active` retains names
without direct relocation consumers. The retired `802ACE98` source is
preserved in `scratch/game_lod_split_strings_20261020/`.

The transfer adds 302 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
