# Dolphin GX vertex attributes

`src/dolphin/gx/GXAttr.c` recovers fifteen linked C functions and 5,928 code bytes at `0x80111CDC..0x80113404`.

| Function | Address | Size |
| --- | --- | --- |
| __GXXfVtxSpecs | 0x80111CDC | 0x158 |
| GXSetVtxDesc | 0x80111E34 | 0x350 |
| GXSetVtxDescv | 0x80112184 | 0x374 |
| __GXSetVCD | 0x801124F8 | 0x54 |
| __GXCalculateVLim | 0x8011254C | 0x124 |
| GXGetVtxDesc | 0x80112670 | 0x1B4 |
| GXGetVtxDescv | 0x80112824 | 0x90 |
| GXClearVtxDesc | 0x801128B4 | 0x38 |
| GXSetVtxAttrFmt | 0x801128EC | 0x358 |
| GXSetVtxAttrFmtv | 0x80112C44 | 0x378 |
| __GXSetVAT | 0x80112FBC | 0x9C |
| GXSetArray | 0x80113058 | 0x8C |
| GXInvalidateVtxCache | 0x801130E4 | 0x10 |
| GXSetTexCoordGen2 | 0x801130F4 | 0x2D0 |
| GXSetNumTexGens | 0x801133C4 | 0x40 |

The [Melee GXAttr reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXAttr.c) supplies vertex descriptor, attribute format, array and texture coordinate generation algorithms. The target separates `__GXCalculateVLim` from `__GXSetVCD`; it computes the normal multiplier from VAT format zero, corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXAttr.c). Descriptor enumeration visits position-matrix through texture-coordinate seven, then the NBT descriptor separately, before the null terminator. Both changes follow the original instructions. Unlinked attribute-format getters are omitted. Shared GX headers are unchanged.

Seven compiler-generated jump tables own `.data:0x802CF748..0x802CF978` (560 bytes, alignment 8). Their individual addresses, sizes and private scopes are in the manifest. Three four-byte static lookup arrays own `.sdata:0x80375DC0..0x80375DCC` (12 bytes, alignment 8); four external alignment bytes follow. No BSS is owned.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 5,928 code bytes and 572 initialized data bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXAttr`; original source hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
