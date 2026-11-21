# Engine type registration

Three C++ routines at `80208C24..802092A8` recover 1,668 original text bytes.
Two routines call the observed manager enable/disable pairs and update their
console/resource flags. The third registers 61 type relationships with the
original registry API, including resource objects, animation, manipulators,
movement, particles, streaming and console interpretation. Its callbacks
refer to 50 distinct factory addresses, many already reconstructed. The two
additional registration hooks remain external.

The source owns the original 770-byte literal pool at
`802ADD20..802AE022`. Named character arrays retain both the registered type
names and the preceding command/help literals used by other engine routines.
The compiler's normal data pooling (`-pool on`) emits their shared base and
original offsets. Treating these as arithmetic into an external array caused
extra address hoisting and did not match. The two original trailing alignment
bytes remain an explicit fallback split. Twenty short type names and all
factory implementations remain external dependencies.

Names such as `RegistryGlobals` describe the observed layout rather than
claiming the original class identity. No manager implementations, factory
bodies or virtual tables are fabricated. The field offsets are established
by their original loads and stores.

`scratch/game_type_registry/verify.py` recompiles the production source with
GC/1.3.2, `-O4,p -inline auto -str reuse,readonly -pool on`, verifies every
allocated section and function extent, resolves all 225 relocations from
the original identities, and compares every byte to the protected DOL.

## Game and platform registration hooks

Three additional bounded hooks retain the original registration sequence:

| Source | Function | Code | Type registrations | Owned literal pool |
| --- | --- | ---: | ---: | --- |
| `game_type_registry.cpp` | `8007DD84` | 988 | 38 | `8029CD70..8029D05A`, 746 bytes |
| `platform_type_registry.cpp` | `801EB030` | 444 | 16 | `802ACF00..802AD053`, 339 bytes |
| `agent_type_registry.cpp` | `800B8308` | 3,384 | 119 | `802A06D8..802A0E78`, 1,952 bytes |

The game hook logs its registration message then installs SpongeBob movement,
projectile, jellyfish, snail, menu and other classes. The platform hook installs
GameCube-specific data and rendering classes. The agent hook interleaves 119
registrations with 119 original initialization-hook calls. Those hook bodies
remain external and receive no completion credit here.

Shared string arrays retain external linkage where other original routines
use them; the existing `lbl_802ACF20` allocation label remains available to
already reconstructed factories. Trailing two-byte and one-byte alignment
gaps remain original fallback data. Unused leading diagnostics remain in the
owned pools to preserve the compiler-generated base offsets.

The two early game hooks require `-O4,s`, exceptions enabled and
`-use_lmw_stmw on`: size optimization preserves their two-register multiple
save/restore sequences. Each has its original eight-byte exception record
and twelve-byte index entry. The platform hook uses `-O4,p`, exceptions off.
The `--more` and `--agents` strict verification modes cover every allocated
byte and all 125, 66 and 515 relocations respectively. No exception records
or instructions are patched.
