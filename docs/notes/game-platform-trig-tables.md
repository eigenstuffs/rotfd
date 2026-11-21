# Platform trigonometric lookup-array ownership

`src/Game/platform_trig_tables.cpp` owns `.bss 0x8035D3A0..0x8035D524`,
**388 zero-initialized bytes**, with no code, constructors or relocations:

| Array | Address | Extent | Native accesses |
| --- | --- | --- | --- |
| `lbl_8035D3A0` | `8035D3A0` | 64 floats / 256 bytes | Initializer writes 64 inverse-cosine values |
| `lbl_8035D4A0` | `8035D4A0` | 33 floats / 132 bytes | Initializer writes indices 0..32; quadrant interpolation reads only 0..32 |

The earlier provisional cosine symbol had size `88` (136 bytes). The matching
initializer and interpolation establish 33 active samples. The last four bytes
at `8035D524..8035D528` remain in original unclassified BSS; they receive no
source credit. The next original object begins at the eight-byte-aligned
address `8035D528`. These bounds establish a sufficient source-owned array
extent, not the original declared array length or complete original TU boundary.

The compiler emits one 388-byte, eight-byte-aligned NOBITS section containing
exactly the two strong array symbols. The linked ELF retains both at their
original addresses with their verified sizes and NOBITS type. Native objdiff
reports all 388 bytes matched. The original DOL's BSS range covers these arrays;
no reference executable bytes are changed. Shared declarations now specify
33 cosine samples, and all 1,256 trig code bytes plus its eight-byte bias remain
unchanged under strict verification of all 50 actual relocations.

Acceptance: `scratch/game_platform_trig_tables/verify.py --production`,
`scratch/platform_trig_tables_link_proof.json`,
`scratch/platform_trig_link_proof.json`,
`scratch/platform_draw_tables_build.log`,
`scratch/platform_draw_tables_changes.log`,
`scratch/platform_draw_tables_tests.log` and
`scratch/platform_draw_tables_checkpoint.json`. The DOL is byte-identical,
all 690 source units and both new units fully match, all 23 tests pass, and
all other source files plus the initial baseline remain unchanged.
