# Voice-over and HUD trailing names at 802A0108

The former original-only interval `8029F0DC..802A0171` begins with three
readable strings, followed by 4,096 zero bytes at `8029F108..802A0108`.
The meaning of that zero region remains unresolved, so it stays with the
original assembly. This continuation splits at `802A0108` and transfers only
the eight trailing NUL-terminated names plus seven boundary bytes through
`802A0178` into `src/Game/voiceover_hud_names_802A0108.cpp`. The accepted
WaterBall and HUD names after that boundary are in the same compiler-owned
`.rodata` extent, `802A0108..802A024E` (326 bytes). This is a partial data
split, not a claim on the original zero region or a complete translation unit.

GC/1.3.2 emits the exact 326 original bytes with no code or relocations. The
eight new global names have their original addresses and sizes in the final
ELF. Natural string alignment and the following array's eight-byte alignment
account for the seven boundary bytes. `#pragma force_active` retains the
unreferenced names. The retired `802A0178` source is preserved in
`scratch/game_voiceover_trailing_names_20261020/`.

This transfer adds 112 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
