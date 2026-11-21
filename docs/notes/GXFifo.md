# Dolphin GX FIFO management

`src/dolphin/gx/GXFifo.c` recovers seventeen linked C functions and 2,036 code bytes at `0x801114E8..0x80111CDC`.

| Function | Address | Size |
| --- | --- | --- |
| GXCPInterruptHandler | 0x801114E8 | 0x134 |
| GXInitFifoBase | 0x8011161C | 0x6C |
| GXInitFifoPtrs | 0x80111688 | 0x70 |
| GXInitFifoLimits | 0x801116F8 | 0xC |
| GXSetCPUFifo | 0x80111704 | 0x110 |
| GXSetGPFifo | 0x80111814 | 0x178 |
| GXSaveCPUFifo | 0x8011198C | 0x20 |
| __GXSaveCPUFifoAux | 0x801119AC | 0xDC |
| __GXFifoInit | 0x80111A88 | 0x4C |
| __GXFifoReadEnable | 0x80111AD4 | 0x24 |
| __GXFifoReadDisable | 0x80111AF8 | 0x20 |
| __GXFifoLink | 0x80111B18 | 0x3C |
| __GXWriteFifoIntEnable | 0x80111B54 | 0x3C |
| __GXWriteFifoIntReset | 0x80111B90 | 0x3C |
| __GXCleanGPFifo | 0x80111BCC | 0x100 |
| GXGetCPUFifo | 0x80111CCC | 0x8 |
| GXGetGPFifo | 0x80111CD4 | 0x8 |

The [Melee GXFifo reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXFifo.c) supplies the CPU/GPU FIFO state, watermarks, interrupt handling and cleanup algorithms, corroborated by [Pikmin 2](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXFifo.c). The target adds the observed null check at the start of __GXCleanGPFifo, and invokes the external PPCSync wrapper in FIFO setters. Handler helpers are inline while all linked functions retain their observed standalone bodies.

Only linked APIs are included. Gather-pipe redirection/restoration and their reference assembly variants are absent from this range and omitted. Saving FIFO state is ordinary C reading hardware register pointers. This unit uses normal peephole optimization, unlike the adjacent GXInit unit. The shared GX headers are unchanged; the source-local OSContext layout matches the already recovered OS declarations.

No initialized data or large BSS is owned. Seven private objects occupy `.sbss:0x80377CB0..0x80377CCC` (28 bytes, alignment 8): CPUFifo, GPFifo and __GXCurrentThread are four bytes each; CPGPLinked is one byte plus three padding bytes; GXOverflowSuspendInProgress, BreakPointCB and __GXOverflowCount are four bytes each. Four external padding bytes follow the section. The manifest lists exact sizes and private scopes.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` matches every text byte after relocation against the original DOL. Isolated scripts are under `scratch/GXFifo`; original source hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.
