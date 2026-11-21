# Remaining SDK/runtime source boundaries

This audit covers the main SDK and pre-Python runtime span `0x800F0D90..0x80130084`, plus the separately split TRK native startup. It follows the CARD, GXTev fragments, `std::exception::what`, and inferred TPL getter handoffs. It is an attribution record, not a progress report or a denominator change. Previously verified source units are omitted.

The following extents contain explicit architectural register/cache/context operations or ABI assembly in the preserved SDK/runtime references. They remain native fallback and receive no recovered C/C++ credit. Individual linked notes retain source-family references and original instruction evidence.

| Original text range | Bytes | Native source family |
| --- | ---: | --- |
| `0x800F0D90..0x800F0E60` | 208 | [PowerPC register, cache-control and halt primitives](PPCArch.md) |
| `0x800F0E88..0x800F0E90` | 8 | [PPCSetFpNonIEEEMode](PPCArch.md) |
| `0x800F0F00..0x800F0F10` | 16 | [Debugger exception entry](db.md) |
| `0x800F1700..0x800F1728` | 40 | [OS debugger vector integrator and jump entry](OS.md) |
| `0x800F1758..0x800F1884` | 300 | [OS exception vector, default entry and paired-single setup](OS.md) |
| `0x800F1F24..0x800F1F74` | 80 | [DecrementerExceptionHandler ABI wrapper](OSAlarm.md) |
| `0x800F2228..0x800F23CC` | 420 | [Data/instruction cache instruction loops](OSCache.md) |
| `0x800F26B8..0x800F2968` | 688 | [FPU state save/load and current-context setup](OSContext.md) |
| `0x800F2974..0x800F2AD4` | 352 | [OS context save/load and stack-pointer access](OSContext.md) |
| `0x800F2AF8..0x800F2BB4` | 188 | [OSInitContext register initialization](OSContext.md) |
| `0x800F2E5C..0x800F2EE0` | 132 | [OSSwitchFPUContext entry](OSContext.md) |
| `0x800F362C..0x800F3678` | 76 | [MSR interrupt-bit access](OSInterrupt.md) |
| `0x800F3E48..0x800F3E98` | 80 | [ExternalInterruptHandler ABI wrapper](OSInterrupt.md) |
| `0x800F3F58..0x800F4070` | 280 | [BAT memory configuration and real-mode entry](OSMemory.md) |
| `0x800F43DC..0x800F43EC` | 16 | [Reboot entry transfer](OSReboot.md) |
| `0x800F47C8..0x800F4838` | 112 | [OSResetHardware register sequence](OSReset.md) |
| `0x800F5914..0x800F5934` | 32 | [System-call vector](OSSync.md) |
| `0x800F6BF4..0x800F6C14` | 32 | [Time-base register reads](OSTime.md) |
| `0x800F6D0C..0x800F6E5C` | 336 | [PSMTXIdentity, PSMTXCopy, PSMTXInvXpose, PSMTXScale](mtx44.md) |
| `0x800FF1E8..0x800FF240` | 88 | [Audio callback stack switch](AI.md) |
| `0x80114830..0x801148AC` | 124 | [GX paired-single light transfer](GXLight.md) |
| `0x80116EAC..0x80116F4C` | 160 | [GX position/normal matrix transfers](GXTransform.md) |
| `0x80116F84..0x80117038` | 180 | [GX texture matrix transfer](GXTransform.md) |
| `0x8011C2CC..0x8011C304` | 56 | [TRK cache-instruction loop](MetroTRK-support.md) |
| `0x8011C3C0..0x8011C754` | 916 | [TRK MSR, exception entries, protected copy and target swap](MetroTRK-targimpl.md) |
| `0x8011DC50..0x8011DD04` | 180 | [TRK target startup and serial-interrupt entry](MetroTRK-targimpl.md) |
| `0x8011DDB0..0x8011E120` | 880 | [TRK extended register save/load](MetroTRK-targimpl.md) |
| `0x8011E16C..0x8011E1F4` | 136 | [TRK context load](MetroTRK-dolphin_trk_glue.md) |
| `0x8011F460..0x8011FAC4` | 1636 | [EABI member-pointer, register save/restore and arithmetic primitives](runtime-native.md) |
| `0x8011FAC4..0x8011FACC` | 8 | [Native r2 accessor kept outside C++ registration](runtime-init-cpp-exceptions.md) |
| `0x8011FB40..0x8011FD88` | 584 | [Native exception entry and context restore](runtime-native.md) |

These explicitly listed main-text extents total **8,344 bytes**. The separate copied TRK interrupt-vector image at `0x800033FC..0x80005330` is also native fallback. Its special linker classification is documented centrally; this audit does not relabel it as C or as an ordinary callable function.

Ordinary C/C++ reconstruction remains pending in these smaller extents:

| Original text range | Bytes | Remaining issue |
| --- | ---: | --- |
| `0x801148AC..0x80114A94` | 488 | Ambient/material lighting color-copy ordering; eight differing instructions |
| `0x801162E8..0x801164C0` | 472 | TEV coordinate mask load/address ordering; two differing instructions |
| `0x80117FE4..0x801181C0` | 476 | TRK framed-message sender checksum/register and control-flow details |
| `0x80119044..0x801190E0` | 156 | TRK dispatcher command-byte register allocation |
| `0x8011A8B4..0x8011ACC4` | 1,040 | TRK read-memory handler final source match |
| `0x8011CBF4..0x8011CCEC` | 248 | TRK step helpers final source match |

These pending C/C++ extents total **2,880 bytes**. The isolated near-matches are diagnostics, never partial instruction coverage.

The audit found one earlier accepted source that embedded a native wrapper: `Runtime.PPCEABI.H/__init_cpp_exceptions.cpp` formerly defined `GetR2__Fv` at `0x8011FAC4..0x8011FACC` with `static asm`. The production body has now been removed and its C++ callers reverified as a C-only fragment; the eight native bytes remain fallback. The same correction excludes four old linker-alignment bytes from data credit. See [the exact source audit and ownership correction](runtime-init-cpp-exceptions.md).

Fresh exact handoffs identified during the audit are the twelve-byte `std::exception::what` fragment and its ten-byte literal ([details](runtime-exception.md)), the newly verified seventy-two-byte standard exception destructor with forty-four metadata bytes ([details](runtime-exception.md)), plus the sixteen-byte descriptor getter with explicitly inferred TPL attribution ([details](TPL.md)). The existing main SDK/runtime interval has no other uncovered ordinary-C function after these handoffs, based on the current split inventory and the preserved assembly/source-family evidence. This statement is bounded to this interval; it does not cover unsplit game and engine code elsewhere in the DOL.
