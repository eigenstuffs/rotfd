# Dolphin mixer

`src/dolphin/mix/mix.c` recovers seven linked C functions and 8,488 code bytes at `0x80103FE8..0x80106110`.

| Function | Address | Size |
| --- | --- | --- |
| __MIXSetPan | 0x80103FE8 | 0xBC |
| MIXInit | 0x801040A4 | 0xC8 |
| MIXInitChannel | 0x8010416C | 0xE74 |
| MIXReleaseChannel | 0x80104FE0 | 0x20 |
| MIXSetInput | 0x80105000 | 0x28 |
| MIXSetPan | 0x80105028 | 0x6C |
| MIXUpdateSettings | 0x80105094 | 0x107C |

[TTYD's mixer reconstruction](https://github.com/doldecomp/ttyd/blob/main/libs/dolsdk2004/src/mix/mix.c) provides the matching Dolby Pro Logic II channel structure, volume/pan tables, mixer control bits and interpolation algorithms. The original uses an attenuation of 60 in the surround mix calculations where the newer reference uses 30. During channel initialization, the main surround level instead uses the sum of the fader and back level without that attenuation. The update path applies 60 to the main surround level as well. These distinct initialization and update expressions are confirmed by every original instruction; they are preserved rather than normalized into one formula.

Only linked APIs remain. Volume lookup, reset and pan clamping inline; the pan setter remains a private function. No assembly or opaque generated instruction stream is introduced. The original DSP program data preceding these tables remains an external fallback asset: the target byte length is `0x1F20`, and its entry vectors differ from the available older Melee and newer TTYD DSP program references. That data is not claimed as recovered C code.

The five initialized lookup tables occupy `.data` `0x802CE440..0x802CF000` (3,008 bytes), alignment 8. The volume table has 1,930 bytes and two internal padding bytes; the AI volume table has 50 bytes and two final padding bytes. The 64 channel records occupy `.bss` `0x80332980..0x80334180` (6,144 bytes), alignment 8. Three private state words occupy `.sbss` `0x80377C08..0x80377C14` (12 bytes), alignment 8; four following zero bytes are outside the split. Tables preserve their reference global linkage, while channel state is private.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __MIXVolumeTable | .data | 0x802CE440 | 0x78A |
| __MIXPanTable | .data | 0x802CEBCC | 0x200 |
| __MIX_DPL2_front | .data | 0x802CEDCC | 0x100 |
| __MIX_DPL2_rear | .data | 0x802CEECC | 0x100 |
| __MIXAIVolumeTable | .data | 0x802CEFCC | 0x32 |
| __MIXChannel | .bss | 0x80332980 | 0x1800 |
| __MIXDvdStreamAttenCurrent | .sbss | 0x80377C08 | 0x4 |
| __MIXDvdStreamAttenUser | .sbss | 0x80377C0C | 0x4 |
| __MIXSoundMode | .sbss | 0x80377C10 | 0x4 |

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/mix -Cpp_exceptions off` matches all 8,488 text bytes and all 3,008 initialized data bytes after applicable relocations are resolved. The isolated compile/verify scripts are in `scratch/mix`. Reference hashes and the TTYD MIT license are retained under `reference/`. Full-DOL SHA-1 and native objdiff remain the integration checks.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `dolphin/mix/mix.c` | `.data` | `0x802CE440..0x802CEFFE` (3,006 bytes) | `0x802CEFFE..0x802CF000` (2 bytes) |

Current native objdiff credits `dolphin/mix/mix.c`: 9,162 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
