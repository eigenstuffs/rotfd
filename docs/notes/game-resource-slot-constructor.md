# Native slot-resource construction

`src/Game/resource_slot_constructor.cpp` owns `801E714C..801E7544`,
1,016 matching code bytes. It initializes the pool storage and bitset,
resizes the additional handle array and bitset for 128 entries, clears the
bitset words, formats each entry name, and acquires retained named resources.
The format string, type string, virtual table and called routines keep their
existing ownership. Field offsets and provisional class identities are shared
with the already matched derived destructor.

Ordinary constructors preserve the separate handle conversion and temporary
cleanup layers. The array resize helpers share their loop variable across the
grow and shrink branches, reproducing the original register allocation.
The pool and extra bitsets use the original initialization call; their native
constructor identity is not inferred from that call alone.

`scratch/game_resource_slot_constructor/verify.py --production` verifies all
1,016 retained bytes with 52 actual relocations. The emitted 512 bytes of
unused weak destructors are excluded, and final ELF checks prove their
absence. No data or alignment credit is added. The shared declaration change
was checked against the native derived destructor and all source units.

The full DOL is byte-identical, all 657 source units were exact at acceptance,
and all 23 tests and progress/extent/assembly audits passed. The initial
baseline is unchanged; existing fallback/native-padding accounting warnings
remain without source regressions. Evidence:
`scratch/resource_slot_constructor_checkpoint.json`.
The original pool destructor remains an uncredited 412-byte near-match.
