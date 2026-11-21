# MetroTRK bridge to MSL file and console I/O

`src/MetroTRK/mslsupp.c` recovers all nine C functions at 0x8011E648..0x8011EC7C (1,588 bytes), with no initialized data or BSS. The [Pikmin 2 MSL support source](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/mslsupp.c) supplies the same console wrappers and shared file-transfer logic. Its unlinked open, seek and mode-conversion bodies are incomplete, so those three algorithms were reconstructed directly from the original instructions. The existing, verified MSL stdio_internal.h provides file modes, handles, positions and callback types without modification.

The file bridge requires an active debugger connection. Read and write pass a temporary length to the native support trap and copy the returned length back to MSL. Close and seek preserve the original trap calling convention; seek passes position by value and does not overwrite the caller's position. Trap result byte 0 maps to success, 2 to end-of-file, and all other values to an I/O error. The console wrappers additionally require GetUseSerialIO; console input uses handle zero and output uses handle one. Console close follows the ordinary file close path.

Mode conversion reads the original open-mode, I/O-mode and binary bitfields before applying its two switches. It accumulates a 32-bit flag value and preserves the final 8-bit mask when adding the binary flag. The original mapping is:

| Input | Output bits added |
| --- | --- |
| open_mode 0 / 2 / 1 | 0x01 / 0x02 / 0x04 |
| io_mode 1 / 2 / 6 / 3 / 7 | 0x01 / 0x02 / 0x04 / 0x12 / 0x07 |
| binary_io 1 | 0x08, then mask to 8 bits |

The unsigned-int result type and explicit byte conversion at the open-trap boundary reproduce the observed allocation and mask instructions. The helper remains compiler-local and is not inlined; the shared access helper is ordinary inline C, producing the original separate exported read/write/console functions.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces all 1,588 text bytes and every relocation. The candidate records native TRKAccessFile, TRKOpenFile, TRKCloseFile and TRKPositionFile identities at 0x8011DC50, 0x8011DC58, 0x8011DC60 and 0x8011DC68; those four trap stubs remain assembly fallback. The complete manifest is config/GSQE78/candidates/MetroTRK-mslsupp.json. The integrated source passes whole-DOL byte equality, native objdiff code/data checks, and the original-source regression audit.
