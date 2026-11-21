# Platform path getters

`src/Modules/getpath.c` reconstructs the GSQE78 platform variant of CPython's path configuration. The four public getters retain the CPython 2.1 interface and conditional initialization. The original executable uses pointer globals for prefix, execution prefix, program path, and module search path. Its initialization assigns all four to the same empty string; it performs none of the Unix filesystem search from upstream `Modules/getpath.c`.

The four 40-byte getters occupy `0x801AC738..0x801AC7D8` (160 bytes). The owned empty string and padding occupy `.sdata` `0x803774F0..0x803774F4` (4 bytes). The four zero-initialized pointers occupy `.sbss` `0x80377F80..0x80377F90` (16 bytes). Their order is `module_search_path`, `progpath`, `exec_prefix`, `prefix`.

This empty-path behavior is recovered from every original getter, rather than an approximation of the general CPython path search. GC/2.0 compiles the reconstructed `calculate_path` inline into all four functions with matching stores and target addresses. Flags are `-proc gekko -fp hardware -enum int -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -pool off -Cpp_exceptions off`.

`scratch/getpath/verify.py` resolves relocations and compares bytes directly against the DOL: `TEXT 160 160`, `.sdata 4 EXACT`. The manifest includes local scopes for the pointer globals. Whole-DOL linking and SHA-1 verification remain the integration check.

The source distinguishes its target-specific behavior from the upstream interface and records CPython provenance and licensing.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/getpath.c` | `.sdata` | `0x803774F0..0x803774F1` (1 byte) | `0x803774F1..0x803774F4` (3 bytes) |

Current native objdiff credits `Modules/getpath.c`: 17 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
