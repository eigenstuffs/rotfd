# Pause and menu string pool at 8029A353

The former original-only `8029A353..8029A4D8` interval contains one initial
alignment byte and 21 NUL-terminated strings for pause options, menu events,
and agent type names. It is now part of
`src/Game/native_readable_pools_8029A0C0.cpp`, with the accepted strings on
both sides. The full compiler-owned `.rodata` extent is
`8029A0C0..8029A4E8` (1,064 bytes). This remains a partial data split.

GC/1.3.2 emits all original bytes without relocations or code. The final ELF
retains each new global string at its original address and size, and
`symbols.txt` records the individual identities in place of the broad
provisional object. Natural compiler alignment accounts for the previous
boundary bytes. `#pragma force_active` retains names without direct
relocation consumers. The accepted movement-type source consolidated into
this unit is preserved in `scratch/game_pause_menu_string_pool_20261020/`.

The transfer adds 389 matched data bytes while preserving the 1,030,936-byte
data denominator. The DOL matches its original SHA-1; `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
