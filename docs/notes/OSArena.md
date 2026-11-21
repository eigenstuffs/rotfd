# Dolphin SDK arena bounds

`src/dolphin/os/OSArena.c` reconstructs all four linked arena getters/setters at `0x800F1F74..0x800F1F94` (32 bytes). The source follows the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSArena.c), with release assertions disabled and unlinked arena allocation helpers retained as unused static inline source.

The unit owns the initial low bound `(void *)-1` at `.sdata` `0x80375CD0..0x80375CD4` (4 bytes) and the zero-initialized high bound at `.sbss` `0x80377908..0x8037790C` (4 bytes). GC/1.2.5n with the same flags verified for `OSAlarm.c` reproduces all instructions and data. `scratch/OSArena/verify.py` resolves references and compares directly with the DOL: `TEXT 32 32`, `.sdata 4 EXACT`. Explicit local data scopes are included in the manifest; whole-DOL SHA-1 remains the integration check.
