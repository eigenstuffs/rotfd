# Platform ARAM lifetime and native bitset construction

Three new source units reconstruct **484 code bytes / three functions** and
**52 data bytes**. The existing 24-byte initializer remains matching source
under its recovered C++ constructor identity, without additional code credit.

| Entry / storage | Native range | Bytes |
| --- | --- | ---: |
| `fn_802859F0`, owner initialization | `802859F0..80285A6C` | 124 |
| Pool startup initializer | `80285B0C..80285B78` | 108 |
| `PlatformAramPool` destructor | `80285B78..80285C74` | 252 |
| Startup constructor pointer | `80299964..80299968` | 4 |
| Global destructor-registration record | `8035DE28..8035DE34` | 12 |
| Global byte/token pool | `8035DE34..8035DE58` | 36 |
| Existing `BitSet_80207EE8` constructor | `80207FC4..80207FDC` | 24 |

The owner initializer conditionally reconstructs the global pool when the
signed-byte guard at `80377FB4` is nonzero, clears the owner's pointer at `8`,
and returns the owner. The native placement-construction null check remains.
The pool destructor clears occupied bits across the limit, updates the used
count, destroys the bitset and byte storage, and honors the native deleting
parameter. The C++ global definition generates the exact startup routine,
constructor pointer and 12-byte destructor-registration record.

`include/Game/platform_aram_lifetime_internal.h` shares the actual storage
base and bitset member. `PlatformAramBytePool` is now an alias for this same
36-byte pool, preserving the earlier ARAM interfaces. The earlier flattened
bitset fields now use the actual member; the bounds-checked query has the name
`isOccupied` to distinguish it from the member. Earlier ARAM instruction and
data bytes are unchanged after this declaration recovery.

The final two owner-initialization scheduling differences were caused by an
inlined C-helper wrapper around bitset construction. Declaring and calling the
native C++ constructor recovers both instructions. Its compiled definition
still zeros the same four words and preserves every native byte. The existing
`hash_init.cpp` path is retained, but it now defines this constructor instead
of treating the shared zero initializer as a hash-specific function. Other
four-word initializer users retain explicit ABI entry declarations under the
recovered symbol. Their caller code and data are individually reverified.
Class and field names remain inferred; matching does not prove the original
class spelling or every caller's high-level type.

GC/1.3.2 with the recorded optimized flags matches all retained bytes after
actual relocation application. The three new units use **20 retained
relocations**. Source-owned startup data comprises the exact four-byte pointer
and 48 zero-initialized BSS bytes. No alignment bytes are added or credited.
The owner and startup units each emit an unused 124-byte storage cleanup;
the recovered bitset constructor emits an unused 208-byte word-array cleanup.
All are absent from the linked ELF and excluded from code/function progress.

Thirteen other affected units and all nine earlier ARAM units are recompiled
and compared against the original code/data. All source, object and mapped
header hashes are current. The source extent and source assembly audits,
full DOL comparison, progress export, original-baseline preservation and 23
unit tests pass. See `scratch/platform_aram_lifetime_checkpoint.json`,
`scratch/platform_aram_lifetime_link_proof.json`, and strict scripts in
`scratch/game_platform_aram_lifetime/`.

This finishes the identified ARAM range `8028531C..80285C74`: all code in
that range now comes from matching source. The earlier item destructor at
`802859A8` also remains matching source. The original guard and borrowed ARAM
strings remain uncredited. These splits do not establish the original file
boundaries; adjacent list-pool code is partially recovered in [object-list evidence](game-object-list-pool.md), with other platform routines still original.
