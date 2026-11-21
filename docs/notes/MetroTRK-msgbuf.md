# MetroTRK message buffers

`src/MetroTRK/msgbuf.c` recovers all 19 linked message-buffer functions at 0x801181C0..0x80118BEC (2,604 code bytes). They manage three fixed buffers, bounds-checked reads/appends, positions and endian conversion for 8-, 16-, 32- and 64-bit values. Function sizes and identities are individually recorded in the candidate manifest.

The [Melee source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/msgbuf.c) supplies the algorithms and inline byte append. The target retains a 4-byte mutex before fInUse, so each MessageBuffer is 0x890 bytes, with length at +8, position at +0xC and its 0x880-byte data array at +0x10. The additional exhausted-buffer diagnostic agrees with [Pikmin 2's reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/msgbuf.c). No unlinked placeholder functions from that reference are used.

GC/1.3.2 uses `-inline auto,deferred` for this unit. Deferred generation produces the original reversed function order and makes the single read/conversion implementations available to their callers. TRKAppendBuffer is explicitly kept out of line with the compiler's `dont_inline` pragma, preserving its original callers; this is the only inlining exception. Other flags are `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off`.

The 29-byte diagnostic owns .rodata:0x802AB910..0x802AB92D, alignment 8, followed by three external alignment bytes. gTRKMsgBufs owns .bss:0x803390A8..0x8033AA58 (6,576 bytes, alignment 8), with no following padding before gTRKInputPendingPtr.

The isolated verifier proves all 2,604 relocated code bytes and all 29 initialized bytes against the original DOL. All previously handed-off TRK units were recompiled against the extended ABI and remained exact. No assembly is introduced. Full-DOL and native objdiff remain integration checks.
