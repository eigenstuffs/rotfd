# Game hash table

The diagnostic filename at `0x802ADD00` identifies `HashTable_Z.cpp`.
The names in reconstructed source describe observed behavior; original
class and member identifiers have not been recovered.

Six bounded C++ fragments recover all 26 functions and 3,168 text bytes in
`0x80207FC4..0x80208C24`. Original key vtables and allocator diagnostics remain
external:

| Source | Original text | Behavior |
| --- | --- | --- |
| `hash_resize.cpp` | `80207FDC..80208240` | Resize and reinsert live keys |
| `hash_insert.cpp` | `802083C8..802086C8` | Insert, clone and grow the table |
| `hash_keys.cpp` | `802088D0..80208C24` | Pointer/integer keys and lifetime |
| `hash_init.cpp` | `80207FC4..80207FDC` | Zero the four table fields |
| `hash_lookup.cpp` | `80208240..802083C8` | Advance/reset iteration and lookup |
| `hash_lifecycle.cpp` | `802086C8..802088D0` | Clear, destroy, sized/default initialization |

The table is sixteen bytes: signed cursor, capacity, count, and slot pointer.
A key has a four-byte prefix and its virtual table pointer at offset four.
Observed virtual calls use slots `0x08` for disposal, `0x0C` for the first
hash, `0x10` for the probing step, and `0x14` for signed-byte equality. The
unknown `0x18` slot and clone slot `0x1C` are declarations only. No invented
method bodies, virtual tables or original storage are emitted.

Lookup masks the hash by capacity minus one, makes the step odd, skips
`(HashKey*)-1` tombstones, and returns the occupied slot through an output
pointer on success. Clearing can dispose keys and preserves the original
count-zero fast path. The deleting-destructor ABI retains its signed-short
release flag. Sized initialization rounds upward to a power of two then
doubles it; the default initializes capacity 256. Shared allocator storage remains external; the resize calls now resolve to
the recovered resize fragment.

`scratch/game_hash/verify.py` compiles the production sources with GC/1.3.2,
`-O4,p -inline auto -use_lmw_stmw on`, resolves every relocation from the
configured original identities, checks complete allocated sections and the
function inventory, and compares against the protected DOL. There are no
masked instructions, assembly bodies or patched objects.

## Pointer and integer keys

`hash_keys.cpp` adds sixteen functions / 852 bytes at
`802088D0..80208C24`. It covers cloning, equality/inequality, two hash
combinations, disposal, construction, assignment and the pointer-key deleting
destructor. The twelve-byte storage views contain a tag, virtual-table
pointer, and payload. Pointer payload hashing uses logical shifts; integer
payload hashing uses arithmetic shifts. Both split the value into ten-bit
portions and combine them with XOR or addition. Construction sets the
observed tag `-888` and retains intermediate base/derived virtual-table
stores. Original virtual tables and allocation diagnostics remain external.
The same strict whole-object verifier covers every allocated byte and all
43 relocations in this contiguous fragment.

## Resize and insertion

The remaining resize (`0x80207FDC`, 612 bytes) and insertion
(`0x802083C8`, 768 bytes) now pass independent complete-object verification.
Separate fragments preserve their original placements around the lookup methods.
Both use normal `-inline auto,deferred,level=2` and two explicit inline helper
levels, ending in calls to the public recursive operations. This expresses the
original nested expansion while allowing each physical function to be emitted
alone. No object reordering, assembly substitution or binary editing is used.

The same algorithms are repeated in the helper levels because their call targets
represent successive expansion depths. Each public operation still terminates
those expansions through the original resize/insert interface. The load factor
is checked as `count * 5 > capacity * 3`; resizing doubles capacity and reinserts
live keys. Tombstone reuse retains the observed `deleted > 0` condition, including
its treatment of index zero. Signed `long` loop indices and declaration lifetime
preserve the original register allocation. Existing initialization, lookup,
lifetime and key operations retain their matches. The earlier whole-TU probe
remains useful evidence but is superseded by these independently compiled splits.

## Constructor identity refinement

The 24-byte entry previously named `fn_80207FC4` now has the recovered C++
identity `__ct__15BitSet_80207EE8Fv`. Its source remains in `hash_init.cpp`,
with identical native bytes. Actual bitset construction explains the ARAM
owner/startup scheduling; earlier four-word initializer callers retain their
verified ABI entry and matching bytes. This supersedes the earlier hash-specific
interpretation of this initializer without changing the other hash-unit
findings. See [ARAM lifetime](game-platform-aram-lifetime.md).
