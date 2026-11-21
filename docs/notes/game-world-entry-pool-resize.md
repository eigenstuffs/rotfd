# World entry-pool resizing

`src/Game/world_entry_pool_resize.cpp` owns the complete 768-byte routine
at `801E9A24..801E9D24`. The loader calls it for the pool at world offset
`C170`. It grows or shrinks an array of 16-byte records, initializes new
records with a zero first word and `-1` second word, expands the occupancy
bitset as needed, clears the newly exposed range, and updates the limit.
The last two words of each record remain unidentified and uninitialized
by this routine. Shrinking records performs no element cleanup.

The 32-byte pool contains the record array, a 16-byte bitset and the limit.
Unsigned-word bitset resizing retains the original compiler-generated
empty construction/destruction loops. The bounded source view and record
size have compile-time checks. No initialized data or weak helpers are
emitted. Strict verification compares all 768 bytes after 37 actual
relocations, followed by final ELF ownership and full-DOL checks.

The split exposes `801E9D24..801E9F40` as leading original bytes of the next
fallback unit. Native objdiff now counts that 540-byte region as the
unmatched function `pad_03_801E9D24_text`; previously it was an interior
hidden gap. Accordingly the unmodified native report's denominator grows
from 2,607,204 to 2,607,744 code bytes and from 8,801 to 8,802 functions.
Those original bytes contain global storage, remain unclassified, and
receive no source credit. Progress exports preserve the native report
rather than hiding this region or editing its counts.

Evidence: `scratch/game_world_entry_pool_resize/verify.py`,
`scratch/world_entry_pool_resize_link_proof.json`, and
`scratch/world_entry_pool_resize_checkpoint.json`. All 666 source units
remain exact, the complete DOL is byte-identical, all 23 tests and progress,
extent and assembly audits pass, and the original baseline is unchanged.
