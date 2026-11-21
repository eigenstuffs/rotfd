# Object and material string pool at 802AEF52

The original-only `802AEF52..802AEFD0` interval contains two initial
alignment bytes and six NUL-terminated strings for object loading and
materials. It is now part of `src/Game/native_readable_pools_802AEF48.cpp`
with accepted strings on both sides. The compiler-owned `.rodata` extent is
`802AEF48..802AF062` (282 bytes). This remains a partial data split; the
following boundary padding and other neighboring data stay outside it.

GC/1.3.2 emits exact original bytes without code or relocations. All six new
global names have their original addresses and sizes in the final ELF.
Compiler alignment accounts for the two former boundary bytes, and `#pragma
force_active` retains names without direct relocation consumers. The retired
`802AEFD0` source is preserved in
`scratch/game_object_material_string_pool_20261020/`.

The transfer adds 126 matched data bytes while preserving the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
