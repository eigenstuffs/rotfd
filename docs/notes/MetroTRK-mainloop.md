# MetroTRK main loop

`src/MetroTRK/mainloop.c` recovers TRKNubMainLoop at 0x80117B44..0x80117C3C (248 bytes). It dispatches request, breakpoint, exception and support events, handles shutdown, polls serial input and resumes a running target while idle. The [Melee reference](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/mainloop.c) supplies the algorithm; three helpers are retained as static inline C because only their inlined copies are linked here.

The private `trk_abi.h` records the 12-byte NubEvent layout (type byte, 32-bit ID and buffer ID) and integer Boolean representation. No initialized data or BSS is owned by this fragment.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline on,noauto -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces all 248 bytes after resolving every external relocation against the original DOL. GC/2.0 and 2.6 also generate the same instructions for this function, so this is a verified compiler choice, not a unique identification. Older 1.1p1 and 1.2.5n produce different prologues. Isolated trials and verification are under `scratch/MetroTRK`; reference provenance is under `reference/melee-trk`. There is no assembly in this source. Full-DOL and native objdiff remain integration checks.
