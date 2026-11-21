# Dolphin OS initialization C fragments

Nine C functions (2,036 bytes) are reconstructed in three fragments of the original `OS.c` translation unit. Isolated probes resolve every text relocation against the original GSQE78 DOL and compare all 527 initialized bytes. The full DOL matches byte for byte, and native objdiff confirms all code and 655 owned data/BSS bytes.

| Fragment | Original text | Functions | Bytes |
|---|---|---:|---:|
| `OS_init.c` | `800F0F7C..800F1700` | 5 | 1,924 |
| `OS_handlers.c` | `800F1728..800F1758` | 2 | 48 |
| `OS_version.c` | `800F1884..800F18C4` | 2 | 64 |

The first fragment contains `OSGetConsoleType`, `ClearArena`, `InquiryCallback`, `OSInit`, and `OSExceptionInit`. The other fragments contain the exception-table setter/getter and the DI configuration/version-report helpers. All use GC/1.2.5n, `-O4,p -opt nopeephole -inline auto`. Disabling peephole optimization reproduces original redundant branches, unrolled pointer increments, and register moves; enabling it changes all but two function sizes.

The pinned PrimeDecomp/prime SDK reconstruction is the direct source-family reference. Its newer version branch contains the exact November 5, 2002 OS version string, revision 60 banner, drive inquiry callback, and exception initialization algorithm. The older Melee SDK source provides corroborating context but lacks this callback and version reporting. References, URLs and hashes are retained under `reference/prime-sdk/PROVENANCE.md` and `reference/melee-sdk/PROVENANCE.md`. These are community reconstructions, not an asserted original source release.

Adaptations retain the original algorithms. The arena fallback uses `_stack_addr`, which the original address relocation identifies, rather than the Prime reference's `_db_stack_end`. Two erroneous integer casts on `memset` destinations in that reconstruction were removed. The console-type switch preserves the reference's comparison of its low sixteen bits to full console constants, as those comparisons are present in the original instructions. No hardware behavior was simplified.

`OSExceptionTable` was originally static. It is exported between the two reconstructed C fragments so the native gaps can remain fallback. Its definition is positioned to preserve the compiler's original small-BSS allocation order. The four-byte version-report format is a named `.sdata` string in the initialization fragment and is referenced by the trailing fragment. This retains the original shared data owner, eight-byte section alignment, and one instruction using an SDA relocation.

## Data and state ownership

The initialization fragment owns the following sections. The candidate includes each compiler-local string and its exact nonpadding size individually, along with the 15-entry exception-location table.

| Section | Original extent | Size | Alignment |
|---|---|---:|---:|
| `.data` | `802C9750..802C9957` | 519 | 8 |
| `.sdata` | `80375CC8..80375CD0` | 8 | 8 |
| `.bss` | `80318A80..80318AD0` | 80 | 32 |
| `.sbss` | `803778D0..80377900` | 48 | 8 |

The BSS objects are `DriveInfo` (32 bytes, aligned to 32) and `DriveBlock` (48 bytes). Small BSS contains four-byte boot/debug pointers, the weak `__OSIsGcam` flag, initialization flag, exception-table pointer, saved-region bounds, IPL flag, and eight-byte start time. `803778F4..803778F8` is internal alignment before that time object, not a separate recovered variable. The sole byte at `802C9957..802C9958` is external alignment before OSAudioSystem and is excluded from source ownership.

The external byte has its own original split and an explicit `pad_OS_init` object symbol, both with alignment one. A split annotation alone leaves decomp-toolkit's default object alignment at four, moving the subsequent DSP data and later sections. Explicit symbol alignment preserves the original layout while keeping the byte outside source credit.

## Native exclusions

`800F1700..800F1728` contains the OS debugger integrator and branch stub. `800F1758..800F1884` contains the native exception vector, default exception handler, and paired-single/GQR setup. They retain original fallback code. The C installer refers to their original entry labels and copies their code, but this gives no C completion credit for the copied native routines. `__sync()` within the installer is the compiler's intrinsic inside otherwise reconstructed C, as in the source reference.

The original `__OSDBJUMPEND` boundary shares address `800F1728` with `__OSSetExceptionHandler`. The linker template defines that zero-size boundary as an alias of the recovered C entry, retaining the native four-byte jump-image length without adding code or data.

## Reproduction

The scratch `compile.py` accepts a unit and source path. `verify.py` accepts the unit and emits its candidate only after all function sizes, resolved text words, and initialized data bytes match. `OS` additionally verifies a whole-reference probe by original per-function placement; the three production fragments are separately recompiled and verified at their contiguous original extents. Their production sources and private ABI header are stable at handoff.
