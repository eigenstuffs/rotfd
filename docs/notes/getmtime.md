# Platform file modification time

`src/Python/getmtime.c` reconstructs the target-specific implementation of CPython's `PyOS_GetLastModificationTime` interface at `0x801AC730..0x801AC738`. The original two instructions return the constant `1`, regardless of the pathname and stream. This is the observed GSQE78 behavior; the Unix `fstat` implementation in upstream CPython 2.1 is not present in this function.

GC/2.0 with the project's verified CPython flags produces the exact original eight bytes. `scratch/getmtime/verify.py` compares the compiled instructions against the DOL and reports `TEXT 8 8`. No data or relocations are owned by this unit. Whole-DOL linking and SHA-1 verification remain the integration check.
