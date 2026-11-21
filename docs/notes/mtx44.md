# Dolphin SDK projection matrices

`src/dolphin/mtx/mtx44.c` recovers the two linked C functions from the SDK projection-matrix unit:

| Function | Address | Size |
| --- | --- | --- |
| MTXPerspective | 0x800F6E5C | 0xD0 |
| MTXOrtho | 0x800F6F2C | 0x98 |

The [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/mtx/mtx44.c) supplies the exact perspective and orthographic projection algorithms. The local matrix type describes all four rows actually written by these functions. Debug assertions and the unlinked frustum function are omitted. `tanf` resolves to the original function at `0x8012DAAC`.

The original unit's six float constants occupy `.sdata2` `0x80379888..0x803798A0` (24 bytes), in order 1, 2, 0, -1, 0.5, and degrees-to-radians. The first constants were pooled while compiling the earlier unlinked frustum routine. This reconstruction uses explicitly named constant objects to preserve the original pool order without adding an unlinked function. Their `Mtx*` names and global linkage are reconstruction choices; original compiler-local literal names are not known. The manifest records six separate four-byte objects. Their 8-byte-aligned section has no trailing gap.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/mtx -Cpp_exceptions off` matches all 360 text bytes and all 24 initialized data bytes after applying the `tanf` and small-data relocations. `scratch/mtx44/compile.py` and `scratch/mtx44/verify.py` reproduce this isolated check. Whole-DOL SHA-1 and native objdiff verification remain integration checks.

The preceding matrix functions are native paired-single assembly from a separate SDK matrix unit, corroborated by [Melee mtx.c](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/mtx/mtx.c): `PSMTXIdentity` at `0x800F6D0C` (0x2C), `PSMTXCopy` at `0x800F6D38` (0x34), `PSMTXInvXpose` at `0x800F6D6C` (0xC8), and `PSMTXScale` at `0x800F6E34` (0x28). These 336 bytes and their two float constants at `0x80379880..0x80379888` remain original fallback, excluded from this C candidate.
