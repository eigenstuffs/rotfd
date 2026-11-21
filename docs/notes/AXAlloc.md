# Dolphin AX voice allocation

`src/dolphin/ax/AXAlloc.c` recovers 10 linked C functions and 1,224 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXGetStackHead | 0x801012D4 | 0x18 |
| __AXServiceCallbackStack | 0x801012EC | 0x74 |
| __AXAllocInit | 0x80101360 | 0xB4 |
| __AXAllocQuit | 0x80101414 | 0xB4 |
| __AXPushFreeStack | 0x801014C8 | 0x20 |
| __AXPushCallbackStack | 0x801014E8 | 0x10 |
| __AXPopCallbackStack | 0x801014F8 | 0x1C |
| __AXRemoveFromStack | 0x80101514 | 0x94 |
| AXFreeVoice | 0x801015A8 | 0x80 |
| AXAcquireVoice | 0x80101628 | 0x174 |

The Melee reconstruction supplies the priority-stack and allocation algorithms. The newer TTYD reconstruction independently confirms the target's callback service: it skips voices with priority zero and executes callback/free-list processing without the older reference's extra interrupt disable/restore calls. `AXVPB.priority` is unsigned, confirmed by the original compare instruction and the newer header. Internal free-list and priority-list helpers inline; unlinked `AXSetVoicePriority` and validation code are omitted. Pointer expressions for the head entries are written directly as pointer loads, preserving their original meaning and generated code.

`.bss` is `0x80319920..0x80319A20` (256 bytes), two 32-element pointer arrays. `.sbss` is `0x80377B48..0x80377B4C` (four bytes), the callback-stack head. Four subsequent alignment bytes remain outside this unit. Both sections have alignment 8. All state is private and the unit has no initialized data.

The direct references are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged reference files, file hashes and license information are preserved under `reference/`. Source differences described above are verified against the original game instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXStackHead | .bss | 0x80319920 | 0x80 |
| __AXStackTail | .bss | 0x803199A0 | 0x80 |
| __AXCallbackStack | .sbss | 0x80377B48 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/AXAlloc` resolve all applicable relocations and verify 1,224/1,224 code bytes and 0/0 initialized data bytes exactly against the original DOL. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
