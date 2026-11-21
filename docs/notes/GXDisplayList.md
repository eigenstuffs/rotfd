# Dolphin GX display lists

`src/dolphin/gx/GXDisplayList.c` recovers three C functions and 524 code bytes at `0x80116B2C..0x80116D38`.

| Function | Address | Size |
| --- | --- | --- |
| GXBeginDisplayList | 0x80116B2C | 0xC8 |
| GXEndDisplayList | 0x80116BF4 | 0xD4 |
| GXCallDisplayList | 0x80116CC8 | 0x70 |

The [Melee GXDisplayList reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXDisplayList.c) supplies FIFO redirection, optional context snapshots/restoration, overflow handling and display-list invocation. The target has no separate local variable for the PI register read in GXEndDisplayList; reading its overflow bit directly removes an otherwise unused eight-byte compiler stack slot and reproduces the original frame. The reference's unused padding array is omitted. Shared GX headers remain unchanged, including the verified 0x4F8-byte GX context layout.

Two private objects own `.bss:0x80338B58..0x80339074` (1,308 bytes, alignment 8): DisplayListFifo is 36 bytes and __savedGXdata is 1,272 bytes. Four external alignment bytes follow. The private OldCPUFifo pointer owns `.sbss:0x80377CE8..0x80377CEC` (4 bytes, alignment 8), followed by four external alignment bytes. No initialized data is owned.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 524 code bytes after relocation against the original DOL. Isolated scripts are under `scratch/GXDisplayList`; reference hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL SHA-1 and native objdiff remain integration checks.

The central build now passes the original DOL SHA-1 and native objdiff code/data audit for these owned source fragments. All previously linked source units retain their matches.
