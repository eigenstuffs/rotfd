# Dolphin GX lighting

Two C fragments are exact under GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off`:

| Source | Range | Functions | Code bytes |
| --- | --- | --- | --- |
| GXLight_init.c | 0x801147DC..0x80114830 | GXInitLightAttn, GXInitLightPos, GXInitLightDir, GXInitLightColor | 84 |
| GXLight_control.c | 0x80114A94..0x80114BA4 | GXSetNumChans, GXSetChanCtrl | 272 |

The [Melee GXLight reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXLight.c) supplies the basic algorithms and layout. [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXLight.c) corroborates the target's direct GXColor copy, channel-index masking and grouped light-mask fields. The target stores `bpSent` after the optional paired alpha-channel command. All 356 C bytes match the original DOL after relocation. These fragments own no initialized data or BSS, and the shared GX headers are unchanged. Full-DOL SHA-1 and native objdiff remain integration checks.

`GXLoadLightObjImm`, `0x80114830..0x801148AC` (124 bytes), remains original assembly fallback. Its inline PushLight implementation loads and writes paired-single values explicitly, as shown in the Pikmin 2 reference. No assembly body is substituted into recovered C or included in C coverage.

`GXLight_colors.c` preserves the coherent ambient/material color-setter reconstruction at `0x801148AC..0x80114A94` (488 bytes), but is **not accepted for matching coverage**. Both function lengths and all behavior match, while four color-merge blocks differ in whether `mr` occurs before or after `rlwimi`: target copies the masked RGB word into r7 first; the candidate inserts alpha in r0 and then copies. The eight differing instructions account for 32 bytes. This source stays unconfigured pending a source-level register-lifetime match. There is no accepted colors manifest. Isolated probes and the full near-match are preserved under `scratch/GXLight`; no dummy code or inline assembly was added to force a match.
