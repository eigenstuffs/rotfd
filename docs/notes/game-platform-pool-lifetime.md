# Platform pool lifetime

The partial source unit `src/Game/platform_pool_lifetime.cpp` reconstructs
**528 code bytes in two native C++ functions**:

| Entry | Original range | Bytes |
| --- | --- | ---: |
| Pool destructor | `80281EA4..80282064` | 448 |
| Pool constructor | `80282064..802820B4` | 80 |

The pool stores 84-byte records. The observed object pointer is at record
`+4C`; its slot index is at object `+2C`. Storage count, capacity and pointer
occupy pool `0/4/8`, followed by the 16-byte occupancy bitset at `+C` and
limit/used counts at `+1C/+20`. Unknown record and object fields remain opaque.
The destructor visits occupied slots, resets their object-side slot indices
to -1, clears each occupied bit and decrements the used count. Normal base
and member destruction releases the bitset and backing record allocation.
The constructor initializes both storage bases and the counts to zero.

The shared bitset constructor delegates to the existing four-word initializer
`fn_80207FC4`. That 24-byte function already belongs to `hash_init.cpp`; it
receives no new credit. An attempted duplicate constructor split was rejected
by the toolkit before linking and removed. Its private probe remains historical
research. The production declarations retain the original initializer identity.

`include/Game/platform_pool_internal.h` and `include/Game/bitset_internal.h`
share the verified layouts. The previously matching bitset lifecycle and
shutdown source were refactored to these declarations and reverified exactly.
Their instruction bytes and all earlier source matches remain unchanged.
GC/1.3.2 uses the recorded optimized flags with readonly strings, scheduling
and deferred inlining for the bitset lifecycle unit.

The strict production proof applies all ten retained relocations and accounts
for all allocated bytes. Three unreferenced weak helpers total 584 emitted
text bytes; they are absent from the final ELF and excluded from credit.
Four compiler alignment bytes are also excluded. No new data, BSS, metadata
or original padding is claimed. The adjacent 592-byte bit search and other
pool operations still use original objects. Original class/file names remain
unknown; address names are provisional.

The full DOL is byte-identical to the protected reference. All 674 source
units match, all 23 tooling tests pass, and progress, source extent and source
assembly audits pass. The original baseline remains unchanged; old native
report/baseline padding warnings remain documented separately from source
regressions. Evidence: `scratch/platform_pool_lifetime_checkpoint.json`,
`scratch/game_platform_pool_hook/verify.py --production`, and the linked
byte/refactor proofs in the same research group.

## Current expanded split

The unit now also owns the four-byte empty hook at `80281EA0`, for 532 bytes
and three functions. Its original constructor/destructor ranges and bytes are
unchanged. The shared record now uses verified native GX texture/palette
structures; the new texture-binding unit owns its compiler jump table. All
678 source units remain exact. See [texture binding](game-platform-texture-binding.md)
and `scratch/platform_pool_hook_checkpoint.json` for the latest proof.

## Current constructor declaration

The common 24-byte initializer now has its recovered C++ constructor identity
`__ct__15BitSet_80207EE8Fv`, defined in the existing `hash_init.cpp` unit.
The shared bitset header declares it directly. This supersedes the earlier
inlined C-helper wrapper; all functions and data in this pool unit remain
byte-identical after strict reproof. See [ARAM lifetime](game-platform-aram-lifetime.md).
