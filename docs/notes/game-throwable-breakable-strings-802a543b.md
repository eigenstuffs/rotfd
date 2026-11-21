# Throwable and Breakable binding strings at 802A543B

The original-only `802A543C..802A5488` interval contains three
NUL-terminated binding names, preceded by one external boundary byte at
`802A543B`. Both intervals now belong to
`src/Game/python_format_strings_802A51E8.cpp` with the accepted names on
both sides. The compiler-owned `.rodata` extent is `802A51E8..802A54B6`
(718 bytes). This remains a partial data split; the following two boundary
bytes and later binding names remain outside it.

GC/1.3.2 emits every original byte without code or relocations. The three
new global names retain their original addresses and sizes in the final ELF.
The leading colon in `:new_Breakable_Z` is preserved exactly. Natural
alignment accounts for the former boundary byte, and `#pragma force_active`
retains names without direct relocation consumers. The retired `802A5488`
source is preserved in `scratch/game_throwable_breakable_strings_20261020/`.

The transfer adds 77 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
