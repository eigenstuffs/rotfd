# Dolphin GX miscellaneous controls

`src/dolphin/gx/GXMisc.c` recovers eighteen linked C functions and 1,348 code bytes at `0x80113404..0x80113948`.

| Function | Address | Size |
| --- | --- | --- |
| GXSetMisc | 0x80113404 | 0x6C |
| GXFlush | 0x80113470 | 0x5C |
| GXResetWriteGatherPipe | 0x801134CC | 0x34 |
| GXAbortFrame | 0x80113500 | 0xB4 |
| GXDrawDone | 0x801135B4 | 0x80 |
| GXPixModeSync | 0x80113634 | 0x24 |
| GXTexModeSync | 0x80113658 | 0x24 |
| GXPokeAlphaMode | 0x8011367C | 0x14 |
| GXPokeAlphaRead | 0x80113690 | 0x14 |
| GXPokeAlphaUpdate | 0x801136A4 | 0x1C |
| GXPokeBlendMode | 0x801136C0 | 0x88 |
| GXPokeColorUpdate | 0x80113748 | 0x1C |
| GXPokeDstAlpha | 0x80113764 | 0x14 |
| GXPokeDither | 0x80113778 | 0x1C |
| GXPokeZMode | 0x80113794 | 0x28 |
| GXTokenInterruptHandler | 0x801137BC | 0x88 |
| GXFinishInterruptHandler | 0x80113844 | 0x84 |
| __GXPEInit | 0x801138C8 | 0x80 |

The [Melee GXMisc reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXMisc.c) supplies the controls, flush, abort, completion wait, pixel pokes and interrupt handlers. The target's abort routine uses the absolute `__PIRegs` hardware array, also corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXMisc.c); CodeWarrior's absolute-array declaration preserves the original register lifetime. The target clears `bpSent` after texture mode synchronization. Draw-done setters/waiters are inlined into GXDrawDone; unlinked sync-token APIs, callback setters, pixel reads/writes and depth compression APIs are omitted. Callback state is still retained because the linked interrupt handlers read it. Shared GX headers are unchanged.

Four private objects own `.sbss:0x80377CD0..0x80377CE4` (20 bytes, alignment 8): TokenCB and DrawDoneCB are four bytes each, DrawDone is one byte with three bytes of internal padding, and FinishQueue is eight bytes. Four external alignment bytes follow. There is no initialized data or large BSS.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` matches every code byte after relocation against the original DOL. Isolated scripts are under `scratch/GXMisc`; original source hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
