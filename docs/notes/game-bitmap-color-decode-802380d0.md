# Bitmap color decode research

`fn_802380D0`, `802380D0..80238180` (176 original text bytes), now matches
ordinary C++ in `src/Game/engine_bitmap_convert.cpp`. The existing bitmap
conversion source split extends through the decoder; the adjacent 400-byte
line-drawing routine at `0x80238180` remains original.

The observed bitmap view has a pixel pointer at +10 and a byte format at +3E.
Format 3 reads RGBA8 pixels. Format 2 expands RGB565 to byte values with masks
F8/FC/F8 and uses alpha FF. Format 1 expands RGB4A3 to F0/F0/F0/E0 without bit
replication. The return value packs red in bits 16..23, green in bits 8..15,
blue in bits 0..7, and alpha in bits 24..31.

Earlier private sources and actual-relocation comparisons are retained in
`scratch/game_frontier_20261012_b/bitmap_*`, with the `probe_bitmap_*.py`
generators. An ordinary inline helper with byte component temporaries and
word outputs approaches the native component-copy shape but emits 172 bytes
with 23 differing words (`bitmap_mixed_BitmapWord_BitmapByte.cpp`). A byte
output variant has the original 176-byte extent but 36 differing words. Typed
component objects, parameterized packing helpers, expression trees, and
supported compiler/optimizer variants remained nonmatching. The accepted
source uses byte channel temporaries and a shared indexed pixel pointer in
format 3; this makes the compiler retain the original indexed first-byte
load and register allocation. The isolated GC/1.3.2 compile matches all
176 text bytes and emits no relocation or additional data. Native objdiff
reports 100% for the enlarged 1,248-byte text and retained 56-byte switch
table. The full DOL hash, `ninja changes`, generated progress check, and all
66 tests pass.
