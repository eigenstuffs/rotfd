# Platform pool vacant-slot acquisition

`src/Game/platform_pool_growth.cpp` reconstructs **712 matching code bytes**
in `80281BD8..80281EA0`. The routine searches the occupancy bitset for a
vacant slot and increments the used count. A reusable slot is marked occupied
and returned. If no slot is available, backing record capacity grows in
blocks of eight, the record count advances, the bitset grows as needed, the
new slot is marked, and the old limit is returned while the limit advances.

Records are 84 bytes with trivial default construction. Appending therefore
emits no record initialization stores; reused records are not reconstructed.
Bitset storage uses four-byte words and `(bitCount >> 5) + 1` sizing, including
the original extra word at multiples of 32. Normal scalar construction and
pseudo-destruction generate the original empty counted loops. Allocation,
reallocation and freeing use the existing arena objects and native helpers.
The private helper templates preserve the storage branches and count/capacity
updates without changing any shared header or earlier source file.

GC/1.3.2 uses the recorded optimized flags with automatic inlining. The strict
production proof accounts for all 712 allocated text bytes and **28 actual
relocations**, with no data, BSS, weak helpers, metadata, padding or assembly
credit. Linked native bytes and symbol addresses are exact. The adjacent
[texture initialization/binding routine and its jump table](game-platform-texture-binding.md)
are now also reconstructed in a later verified increment.

The full DOL is byte-identical, all 677 source units remain exact, all 23
tooling tests pass, and progress, source extents and source assembly audits
pass. The original baseline is unchanged. Evidence is in
`scratch/platform_pool_growth_checkpoint.json` and the strict/link proofs
under `scratch/game_platform_pool_growth/`.
