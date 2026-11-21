# Dolphin SDK C startup fragment

`src/dolphin/os/init/__ppc_eabi_init.c` recovers the three linked startup/termination C functions from the [Melee SDK reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/init/__ppc_eabi_init.c).

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| __init_user | 0x800F6C78 | 0x20 | global |
| __init_cpp | 0x800F6C98 | 0x54 | local |
| _ExitProcess | 0x800F6CEC | 0x20 | global |

The constructor walker calls each non-null entry in the linker constructor list at `_ctors` (`0x80299920`). Process termination calls the existing original `PPCHalt` primitive. This split owns no constructor-list entries, initialized data, or BSS. `__init_cpp` retains the target's local linkage. The reference's unlinked finalizer and weak abort/exit alternatives are omitted; the game's linked C runtime termination implementation is owned separately.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -opt nopeephole -inline off -i src/dolphin/os -Cpp_exceptions off` reproduces all 148 text bytes including the constructor walker's unoptimized branch sequence. The isolated compiler and relocation verifier are in `scratch/ppc_eabi_init`; the candidate is `config/GSQE78/candidates/ppc_eabi_init.json`. The full-DOL SHA-1 remains the integration check.

The same original source's hardware initializer at `.init` `0x80003354..0x80003374` and cache flush at `.init` `0x80003374..0x800033A8` are native assembly in the reference and remain original fallback outside this C fragment.
