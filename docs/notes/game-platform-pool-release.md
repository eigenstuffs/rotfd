# Platform pool release and sweep

`src/Game/platform_pool_release.cpp` reconstructs **352 code bytes**:

| Entry | Original range | Bytes |
| --- | --- | ---: |
| Occupied-record sweep | `802816D0..802817C8` | 248 |
| Explicit slot release | `802817C8..80281830` | 104 |

The sweep traverses occupied slots through the original bit search. Each
84-byte record has a signed byte flag at `+50`. A set flag is cleared and
the record retained. An unmarked record instead has its object-side slot at
`+2C` reset to -1 and its occupied bit cleared, decrementing the pool's used
count only if the bit was previously set. Explicit release performs the same
object/occupancy update for a supplied index. Both routines preserve the
original boolean conversion and backing-word reload before clearing the bit.
The flag's higher-level purpose and original names remain unconfirmed.

The shared pool header refines the former unknown word at `+50` into this
byte and three unidentified bytes. Record size, alignment, pointer offset and
lifetime remain unchanged. The earlier pool lifetime and shutdown routines
were recompiled and retain their exact bytes; all earlier sources are unchanged.
The larger [texture setup](game-platform-texture-binding.md) and
[vacant-slot growth](game-platform-pool-growth.md) routines now also match.

GC/1.3.2 uses the established optimized flags with automatic inlining. A normal
local record pointer reproduces the native indexed object-pointer load. The
strict production proof checks all 352 allocated text bytes and both actual
branch relocations. No data, BSS, weak helpers, metadata, padding or source
assembly is emitted or credited. Linked symbols retain their original addresses.

The full executable is byte-identical, all 676 source units remain exact,
all 23 tooling tests pass, and progress, source extent and source assembly
audits pass. The original baseline is unchanged. Evidence is in
`scratch/platform_pool_release_checkpoint.json`, its header/link proofs,
and `scratch/game_platform_pool_release/verify.py --production`.
