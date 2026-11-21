# Dolphin GX performance counters

`src/dolphin/gx/GXPerf.c` recovers GXSetGPMetric (0x801172DC, 0x848 bytes) and GXClearGPMetric (0x80117B24, 0x10 bytes), covering 2,136 code bytes through 0x80117B34. The other performance-counter APIs from the SDK reference are unlinked in this target.

The [Melee reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXPerf.c) supplies register updates and counter selection. This target's triangle counters use the 0x2300xxxx constants and its clock/miss cases appear earlier in the switches, as independently corroborated by [Pikmin 2's GXPerf](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXPerf.c). These source-level changes reproduce the target switches and both jump tables exactly. Shared GX headers remain unchanged.

Two compiler-local jump tables own .data:0x802CFC70..0x802CFD5C (236 bytes, alignment 8): 92 bytes for perf1 and 144 bytes for perf0. Four external alignment bytes follow. All entries, object names, sizes, scopes and target addresses are in the candidate manifest. There are no other owned data or BSS objects.

GC/1.2.5n with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off` reproduces all 2,136 relocated code bytes and 236 data bytes against the original DOL. Verification is under `scratch/GXPerf`; reference hashes are recorded under `reference/`. No native assembly is introduced. Full-DOL and native objdiff remain integration checks.

The central build now passes the original DOL SHA-1 and native objdiff code/data audit for these owned source fragments. All previously linked source units retain their matches.
