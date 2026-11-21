# InGame camera diagnostics at 802AE549

The original-only `802AE549..802AE588` interval contains two
NUL-terminated camera strings and their alignment bytes. It now belongs to
`src/Game/native_readable_pools_802AE538.cpp`, between the accepted camera
node name and menu item name array. The compiler-owned `.rodata` extent is
`802AE538..802AE6F0` (440 bytes). This is a partial data split: the
preceding unknown 104-byte table at `802AE4D0..802AE538` and data after
`802AE6F0` remain outside it.

GC/1.3.2 emits the exact original bytes without code or relocations. Both
new global names retain their original addresses and sizes in the final ELF.
Eight-byte alignment on the diagnostic message accounts for its preceding
zero bytes, and `#pragma force_active` retains unreferenced names. The
retired `802AE588` source is preserved in
`scratch/game_ingame_camera_strings_20261020/`.

The transfer adds 63 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
