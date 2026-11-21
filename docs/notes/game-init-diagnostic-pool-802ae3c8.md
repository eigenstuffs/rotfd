# Game initialization diagnostics at 802AE3C8

The original-only `802AE3C8..802AE440` interval contains eight
NUL-terminated strings for startup resources and performance counters. It is
now part of `src/Game/native_readable_pools_802AE328.cpp`, immediately after
the accepted initialization string array. The resulting compiler-owned
`.rodata` extent is `802AE328..802AE440` (280 bytes). This remains a partial
data split; later strings and code from the original region remain outside it.

GC/1.3.2 emits the exact original bytes without code or relocations. The
eight new global names have their original addresses and sizes in the final
ELF. `#pragma force_active` retains names without direct relocation consumers.

The transfer adds 120 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
