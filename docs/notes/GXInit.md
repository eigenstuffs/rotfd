# Dolphin GX initialization

`src/dolphin/gx/GXInit.c` recovers four C functions and 4,560 code bytes at `0x80110318..0x801114E8`.

| Function | Address | Size |
| --- | --- | --- |
| __GXDefaultTexRegionCallback | 0x80110318 | 0x7C |
| __GXDefaultTlutRegionCallback | 0x80110394 | 0x24 |
| GXInit | 0x801103B8 | 0x86C |
| __GXInitGX | 0x80110C24 | 0x8C4 |

The [Melee GX reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXInit.c) supplies the older texture-region model and baseline initialization. The [Pikmin 2 source](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXInit.c) corroborates later additions found in this Nov 7 2002 target: SDK version registration, GXSetMisc, the tevTcEnab graphics-state word, default vertex-array and attribute formats, the projection table, and the European 60 Hz render mode. The target lacks the newer default texture-object initialization. Each inclusion is verified against the original instructions.

The decisive compiler setting is `-opt nopeephole` with GC/1.2.5n. It preserves the target's separate mask/shift instructions and branches to subsequent basic blocks. The graphics-state pointer gx is const and lives in `.sdata2`; the state itself remains mutable. The extra word shifts the final state fields by four bytes and makes gxData 0x4F8 bytes. Register-pointer declaration order follows the compiler's reversed emission of these uninitialized globals.

The private GX headers preserve the public Melee enums, layouts, prototypes and FIFO access macros, with local include paths and only needed target platform declarations. The graphics-state layout is adjusted by the proven additional word. Header and source references, including unchanged downloads, have SHA-256 provenance records. The assembly write-gather helper from the reference is unlinked here and omitted; EnableWriteGatherPipe is ordinary inline C calling the existing PPC access functions. No native assembly or fixed instruction words are introduced.

Owned `.data` is `0x802CF618..0x802CF748` (304 bytes): the 68-byte version text, 208-byte default vertex-format table and 28-byte projection table. BSS is `0x803385E0..0x80338B58` (1,400 bytes): gxData 0x4F8 and FifoObj 0x80. The four register pointers occupy `.sbss:0x80377CA0..0x80377CB0`. The version pointer occupies `.sdata:0x80375DB8..0x80375DBC`, followed by four external padding bytes. `.sdata2:0x803798A8..0x803798D0` contains gx, three packed colors, three float constants, four alignment bytes and a double conversion constant. All owned non-text sections require alignment 8. The manifest records each object's exact size, including compiler-local colors and constants.

`-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -opt nopeephole -i src/dolphin/gx -Cpp_exceptions off` reproduces every one of the 4,560 text bytes and 348 initialized data bytes after relocation directly against the original DOL. Scripts are under `scratch/GXInit`. Full-DOL SHA-1 and native objdiff remain integration checks.
