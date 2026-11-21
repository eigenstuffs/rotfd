# Native record-pool destruction, release, and reset

Four routines have exact, integrated C++ in three bounded fragments, totaling
**1,028 code bytes**:

| Source | Original range | Code |
| --- | --- | ---: |
| `src/Game/record_pool_destructor.cpp` | `80209D30..80209DF8` | 200 bytes |
| `src/Game/record_pool_release.cpp` | `80209DF8..80209EA0` | 168 bytes |
| `src/Game/record_lifecycle.cpp` | `80209EA0..8020A134` | 224-byte destructor and 436-byte reset |

The private names describe the observed layouts, not established original
class names. Each pool record occupies `0xA8` bytes. The pool stores an array
prefix, an occupancy bitset at `+0xC`, a slot limit at `+0x1C`, and a live count
at `+0x20`. Its native destructor calls the release operation for every slot
below the limit, destroys the bitset, and frees the array allocation using its
capacity. Native deletion uses the shared game allocator.

The record destructor calls its reset method before native destruction of four
owned handles. The handle at `+0x40` has two observed zeroing layers; handles
at `+0x44`, `+0x48`, and `+0x4C` have three. Ordinary inherited handle classes
produce the native destructor null checks and flag arguments. The reset method
assigns empty handles in the original `40,48,44,4C` order, copies the shared zero
vector into its first two vectors, assigns the external scalar defaults at
`+0x18`, `+0x24`, and `+0x28`, and clears `+0x50`.

The original vector and scalar constants remain external. These fragments own
no data, BSS, exception records, or padding. The three unused weak handle
destructors total 264 bytes and six relocations in the lifecycle object; ordinary
dead stripping removes them without credit. The pool destructor emits only its
200 retained bytes; the release object emits only its 168 retained bytes.

Run `python3 scratch/game_record_pool/verify.py record_pool_destructor` and
`python3 scratch/game_record_pool/verify.py record_lifecycle`. Both compile the
production sources with GC/1.3.2 and standard game flags, check strong native
identities, physical function order, all allocated-section extents, and each
actual relocation against the protected original DOL. The 200-byte fragment
has eight retained relocations; the 660-byte fragment has thirty. Every retained
byte matches, and excluded weak-body relocations are checked explicitly.

The intervening 168-byte release operation at `80209DF8..80209EA0` is now exact
and integrated. It tests the occupancy bit, destroys that record, clears the
bit, decrements the live count, and returns success; an unoccupied slot returns
zero. A const word-reference accessor with an ordinary local base pointer
reproduces the initial bitset lookup ordering that remained unresolved in the
older probe. `python3 scratch/game_record_release/verify.py` checks all 168 bytes
and its single actual relocation. The [release note](game-record-pool-release.md)
records the source discriminator; earlier probe history remains in
`scratch/game_record_pool/`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records all **200 + 168 + 224 + 436 = 1,028 code bytes**
and all four functions as exact, with zero owned data. The source-section extent
guard and generated progress checks pass. Weak duplicates remain excluded, and
the documented baseline accounting corrections remain preserved.
