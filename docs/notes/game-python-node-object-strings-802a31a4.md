# Game_Z binding strings at 802A31A4

The former original-only `802A31A4..802A31E8` interval contains three
NUL-terminated strings adjacent to the accepted Python argument formats. It
now belongs to `src/Game/python_remaining_formats_802A3088.cpp` along with
the accepted strings on both sides. The compiler-owned `.rodata` extent is
`802A3088..802A3226` (414 bytes). This is a partial data split; the following
boundary bytes and later names remain outside it.

GC/1.3.2 emits the exact original bytes without code or relocations. All
three new global names retain their original addresses and sizes in the final
ELF. The `:Game_Z_NewObject` leading colon is preserved exactly as stored;
`#pragma force_active` retains unreferenced names. The retired `802A31E8`
source is preserved in `scratch/game_python_node_object_strings_20261020/`.

The transfer adds 68 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
