# BigFile and stream diagnostic pool at 802ACAEA

The former original-only `802ACAEA..802ACC58` interval contains two initial
alignment bytes and 13 NUL-terminated strings for animation, BigFile loading,
and stream diagnostics. It is now part of
`src/Game/native_readable_pools_802ACAD8.cpp`, along with the accepted strings
on both sides. The resulting source-owned `.rodata` extent is
`802ACAD8..802ACCB2` (474 bytes). This is a partial data split: the original
`802ACCB2..802ACCC0` interval and later neighboring data remain outside it.

GC/1.3.2 emits every original byte in that extent without code or relocations.
The 13 new global names have their original addresses and string sizes in the
final ELF. Natural compiler alignment accounts for the former boundary bytes;
the following accepted array retains eight-byte alignment. `#pragma
force_active` keeps the symbols when no direct relocation consumes them. The
retired `802ACC58` source is preserved in
`scratch/game_bigfile_string_pool_20261020/`.

The transfer adds 366 matched data bytes, with the 1,030,936-byte data
denominator unchanged. The DOL matches its original SHA-1; `ninja changes`
has no match regressions, the source extent audit passes, and all 66
repository tests pass.
