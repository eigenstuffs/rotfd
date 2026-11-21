# Hierarchy reset and member dispatch

`src/Game/hierarchy_reset.cpp` reconstructs the complete 764-byte method at
`0x80201C14..0x80201F10`. It calls the owner reset helper, invokes vtable slot 11
on the root handle, invokes slot 12 across four member lists, and sends command
`(15, 82)` with the existing float constant at `0x8037A900`.

The three first list walks check handle validity before resolving a pointer.
The fourth walk directly resolves each handle, as in the original instructions.
The secondary list's iteration count is the field at offset `0xDC`, rather than
the adjacent list count. The source preserves both details.

The existing generation-checked `Handle` resolver and virtual object layout are
reused without editing their shared header. One local loop variable is reused
across all four walks: separate loop-local declarations emit three `li`
instructions where the original uses `mr` to initialize the scaled counter.

`scratch/game_hierarchy_reset/verify.py` compiles with GC/1.3.2, `-O4,p`,
`-inline auto`, and `-use_lmw_stmw on`. It verifies all 764 allocated text bytes
and all eight ELF relocations against the SHA-1-checked original DOL. There are
no owned data, BSS, exception tables, or emitted helper functions. The four-byte
float constant remains externally owned. The complete candidate is
`config/GSQE78/candidates/game_hierarchy_reset.json`; the full-DOL SHA-1, direct byte comparison, and native objdiff code/data checks
pass after central integration.
