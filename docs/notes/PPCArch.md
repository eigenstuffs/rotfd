# PPC speculation control C fragment

`PPCDisableSpeculation` at `800F0E60..800F0E88` is a 40-byte C wrapper. It reads HID0 through `PPCMfhid0`, sets bit `0x200`, and writes the result through `PPCMthid0`. The original call instructions establish these operations directly; the matching SDK register-accessor identities are corroborated by the retained Melee `PPCArch.c` reference. The older Melee source does not contain this later wrapper, so its body is reconstructed from the target's operations rather than claimed as a verbatim reference copy.

The wrapper compiles exactly with GC/1.2.5n, `-O4,p -opt nopeephole -inline auto`. Every instruction and both call relocations are checked against the original DOL by the isolated `scratch/db` probe. It owns no data. `PPCMthid0` is the original native register writer at `800F0DB8`, previously named `fn_800F0DB8`.

All other register-access and CPU-mode routines in the surrounding `800F0DA0..800F0E90` range remain native fallback. No assembly source or substituted machine instructions receive recovered C credit.

The integrated C wrapper passes full-DOL byte equality, native objdiff code checks, and the original-source regression audit.
