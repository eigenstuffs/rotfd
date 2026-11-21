# Camera and music strings at 802AEA3A and 802AEA99

Two former original-only intervals, `802AEA3A..802AEA90` and
`802AEA99..802AEAE8`, contain nine NUL-terminated strings for camera
capture, bitmap allocation, and music definition paths. They now belong to
`src/Game/native_readable_pools_802AE9E8.cpp` with the accepted names between
and around them. The compiler-owned `.rodata` extent is
`802AE9E8..802AEAF1` (265 bytes). This remains a partial data split; the
following original-only interval at `802AEAF1..802AEAF8` and later data
remain outside it.

GC/1.3.2 emits the exact original bytes without code or relocations. All
nine new global names retain their original addresses and sizes in the final
ELF. Eight-byte alignment on selected arrays accounts for the original zero
bytes between strings. `#pragma force_active` retains names without direct
relocation consumers. The two retired accepted source files are preserved
in `scratch/game_camera_music_string_pools_20261020/`.

The transfer adds 165 matched data bytes without changing the 1,030,936-byte
data denominator. The DOL matches its original SHA-1, `ninja changes` has no
match regressions, the source extent audit passes, and all 66 repository
tests pass.
