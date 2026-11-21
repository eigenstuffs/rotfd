# Audio bigfile diagnostic strings at 802AF660

The original `.rodata` interval `802AF660..802AF6A0` is three fixed-width
NUL-terminated diagnostics: 28, 16, and 20 bytes. The matching C++ source is
`src/Game/audio_bigfile_messages_802AF660.cpp`, with a single 64-byte typed
object `lbl_802AF660`. GC/1.3.2 emits the exact original bytes, one global
object, and no relocations. The original interval had been retained by
`original/readable_pool_neighbor_802AF660.s`; that one-to-one split is now
source-owned without removing it from the progress denominator.

The diagnostics have no direct relocation consumer. The native linker drops
the source object unless its original global identity is listed in
`config/GSQE78/config.yml` `force_active`. With that retention, the built DOL
passes the original SHA-1 check. `ninja changes` reports no regressions;
source extents and all 66 repository tests pass. This is 64 verified data
bytes only. Adjacent original data and audio functions remain under their
existing owners; no code or whole original translation unit is claimed.
