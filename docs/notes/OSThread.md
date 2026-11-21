# Dolphin SDK thread scheduler

`src/dolphin/os/OSThread.c` recovers all 21 linked C functions at `0x800F5998..0x800F6BF4` (4700 bytes). The local ABI header describes the complete target thread and mutex layouts. This unit contains no assembly; original external context-save, context-restore, interrupt, and stack-pointer primitives remain in their own fallback ranges.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| DefaultSwitchThreadCallback | 0x800F5998 | 0x4 | local |
| __OSThreadInit | 0x800F599C | 0x158 | global |
| OSInitThreadQueue | 0x800F5AF4 | 0x10 | global |
| OSGetCurrentThread | 0x800F5B04 | 0xC | global |
| OSDisableScheduler | 0x800F5B10 | 0x40 | global |
| OSEnableScheduler | 0x800F5B50 | 0x40 | global |
| UnsetRun | 0x800F5B90 | 0x68 | local |
| __OSGetEffectivePriority | 0x800F5BF8 | 0x3C | global |
| SetEffectivePriority | 0x800F5C34 | 0x1C0 | local |
| __OSPromoteThread | 0x800F5DF4 | 0x50 | global |
| SelectThread | 0x800F5E44 | 0x228 | local |
| __OSReschedule | 0x800F606C | 0x30 | global |
| OSYieldThread | 0x800F609C | 0x3C | global |
| OSCreateThread | 0x800F60D8 | 0x1E8 | global |
| OSExitThread | 0x800F62C0 | 0xE4 | global |
| OSCancelThread | 0x800F63A4 | 0x1BC | global |
| OSResumeThread | 0x800F6560 | 0x288 | global |
| OSSuspendThread | 0x800F67E8 | 0x170 | global |
| OSSleepThread | 0x800F6958 | 0xEC | global |
| OSWakeupThread | 0x800F6A44 | 0x104 | global |
| OSClearStack | 0x800F6B48 | 0xAC | global |

The [Pikmin 2 SDK reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/os/OSThread.c) supplies the matching scheduler, priority inheritance, queues, cancellation, stack clearing, and floating-point exception initialization algorithms. The [Melee reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/os/OSThread.c) corroborates the lineage but represents an earlier variant. Reference files and hashes are recorded in their respective `reference/*-sdk/PROVENANCE.md` files; these are public decompilation reconstructions, not claimed original Nintendo source.

Target-specific evidence:

- `OSThread` is 0x318 bytes, including `error` at 0x30C and two `specific` pointers at 0x310. The embedded context is 0x2C8 bytes. The older shorter layout cannot reproduce the original BSS extents.
- `SelectThread` calls the switch callback and clears the current-thread pointer before testing whether the run queue is empty. This differs from the later reference, which performs these operations only inside the empty-queue branch. The earlier Melee code corroborates clearing the current thread before the queue test.
- `OSSaveContext` returns an unsigned word, producing the target unsigned comparison. Queue bits, queue hint, and scheduler suspension state retain volatile types.
- The default switch callback is intentionally empty in the reference and target and is referenced by the initialized callback pointer. Its four-byte function is original behavior.
- `OSCreateThread` retains two reserved local words found in the reference, reproducing the target 0x50-byte frame. Their original source-level purpose is unknown.
- The source includes only linked APIs. Reference `OSIsThreadTerminated`, `OSDetachThread`, and `OSGetThreadPriority` are absent from this original group. Queue and priority helpers inline rather than emitting additional functions.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| RunQueue | .bss | 0x80318B98 | 0x100 |
| IdleThread | .bss | 0x80318C98 | 0x318 |
| DefaultThread | .bss | 0x80318FB0 | 0x318 |
| IdleContext | .bss | 0x803192C8 | 0x2C8 |
| SwitchThreadCallback | .sdata | 0x80375CE8 | 0x4 |
| RunQueueBits | .sbss | 0x80377960 | 0x4 |
| RunQueueHint | .sbss | 0x80377964 | 0x4 |
| Reschedule | .sbss | 0x80377968 | 0x4 |

All eight objects have local linkage. The 32 run queues occupy 0x100 bytes; the idle thread is retained in the original BSS even though its idle-management APIs are not linked. `.bss` covers `0x80318B98..0x80319590` (2552 bytes), `.sdata` covers `0x80375CE8..0x80375CEC` (4 bytes), and `.sbss` covers `0x80377960..0x8037796C` (12 bytes). Each compiled section has 8-byte alignment. The following alignment gaps are not part of the final objects. There are no strings, jump tables, or other initialized data.

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/os -Cpp_exceptions off`; peephole optimization remains enabled. `scratch/OSThread/compile.py` compiles the isolated object and `scratch/OSThread/verify.py` applies original call, address, small-data, and initialized-pointer relocations, comparing every emitted byte against the original DOL. It reports `TEXT 4700 4700` and `.sdata 4 EXACT`.

The verifier resolves `_stack_addr` as `0x8046B990` and `_stack_end` as `0x8037B990`, corroborated by the original instructions and generated linker script. These are existing linker-defined stack symbols; integration must not replace them with independent object definitions. The candidate manifest records all object sizes, scopes, and external function mappings. The whole-DOL SHA-1 and native objdiff report remain the integration checks.
