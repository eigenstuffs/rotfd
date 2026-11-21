# Platform record growth and activation

Verified C++ source: `src/Game/platform_record_growth.cpp`, GC/1.3.2 with
standard `-O4,p` / `-inline auto`. `fn_80283AA0` owns
`0x80283AA0..0x80283D5C`: 700 text bytes and 21 actual relocations. It emits
no owned data, padding, weak functions or extra allocated sections.

A nonnull status-2 record with a nonzero signed-short request first attempts
age-based record reclamation if the free list is too small. If still needed,
it grows link storage by the requested count plus 16, preserving the native
32,000-entry limit, and initializes/merges the added links. The ordinary resize
helper includes both growth and shrink branches and native empty construction
and destruction loops; their control flow is retained even though normal
positive requests grow the array.

The function clears the record's active-chain count/endpoints, transfers the
requested prefix from the free list into the other chain, marks the record
active and terminates its final successor with -1. An exhausted free list
resets both endpoints. The original signed-short decrement loop and narrowing
are preserved without adding new guards for negative requests.

Passing the original count-plus-growth expression directly to the inline
resize reproduces the native register allocation. No earlier source or
shared declaration changed in this increment. The native list initializer,
merge helper, selector and release routine now resolve through matching source.

Evidence: `scratch/game_platform_record_growth/verify.py --production`,
`scratch/platform_record_growth_link_proof.json` and
`scratch/platform_record_growth_checkpoint.json`. All retained allocated bytes
and strong linked symbol addresses are exact. The DOL is byte-identical,
683 source units/680 candidate hashes and 291 mapped header hashes pass,
source extent/assembly/progress audits pass, all 23 tests pass, all earlier
sources are unchanged, and the original baseline is immutable.

This adds 700 code bytes/one function/one unit, reaching 945,728 /
2,607,744 code bytes (36.2661%), 3,056 / 8,802 functions and 301,600 /
1,030,936 data bytes. Original array construction and tables remain outside
this partial text split.
