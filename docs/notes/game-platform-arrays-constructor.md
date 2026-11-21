# Platform record/link array construction

Verified source: `src/Game/platform_arrays_constructor.cpp`, GC/1.3.2 with
standard `-O4,p` / `-inline auto`. The native constructor
`__ct__23PlatformArrays_802EA884Fi` owns `0x801EC8CC..0x801ECA54`:
392 matching text bytes and 17 actual relocations, with no owned data.

The explicit vtable initializer precedes member array construction. Both
arrays begin empty; the body records its supplied 04 word, initializes the
clock/threshold from borrowed native scalar objects, resizes link storage to
two entries, initializes the free list, sets flag 1A and clears short 18.
Readonly scalar declarations and the member initializer reproduce the native
load/store scheduling. The 18/1A/1B field refinement preserves total size
0x34. All eight earlier related source units were recompiled and retain their
exact function hashes and allocated bytes, without source edits. See
`scratch/platform_arrays_constructor_header_proof.json`.

The compiler additionally emits two unreferenced weak array cleanup helpers
(152 + 208 = 360 bytes). Their exact symbol ranges and relocations are
accounted for in the isolated proof, but they are absent from the linked ELF
and receive no progress credit. Borrowed vtable/scalar data remains original;
this is a partial text split, not a complete original translation unit.

Evidence: `scratch/game_platform_arrays_constructor/verify.py --production`,
`scratch/platform_arrays_constructor_link_proof.json` and
`scratch/platform_arrays_constructor_checkpoint.json`. The DOL is
byte-identical; 684 source units/681 candidate hashes and 295 mapped header
hashes pass. All source/progress audits and 23 tests pass. The original
baseline and all prior source files remain unchanged.

This increment reaches 946,120 / 2,607,744 code bytes (36.2812%),
3,057 / 8,802 functions and 301,600 / 1,030,936 data bytes.
