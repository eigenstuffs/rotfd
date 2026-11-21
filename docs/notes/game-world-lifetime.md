# World-record resource lifetime

Five native C++ routines reconstruct 1,688 code bytes:

| Source | Original address | Bytes |
| --- | --- | ---: |
| `world_destructor.cpp` | `0x801E4C54` | 840 |
| `world_array50_destructor.cpp` | `0x801E4F9C` | 208 |
| `world_array4c_destructor.cpp` | `0x801E506C` | 208 |
| `world_array3c_destructor.cpp` | `0x801E513C` | 208 |
| `world_constructor.cpp` | `0x801E520C` | 224 |

The 120-byte object derives from Resource, which derives from Root. Its
existing factory references `Rtc_Z.h:44`; `World_802EA7F0` and the earlier
world-record source names remain provisional role/address names, not recovered
original identifiers. The lifetime code confirms the five record arrays at
`0x0C`, `0x18`, `0x24`, `0x30` and `0x3C`. A four-byte-element array at `0x48`,
a 20-byte action curve at `0x54`, a 128-byte-element array at `0x68` and a
word at `0x74` complete the observed layout. The element contents of the two
additional arrays are unresolved.

Construction initializes the Resource/Root chain, each array, and the action
curve. It leaves the final word untouched, as the original does. Destruction
releases members in reverse order. The two small-record arrays inline their
handle-member destruction; the three larger curve-record arrays use separate
native destructors. Each array destroys elements in ascending order before
freeing storage using its capacity and element size. Deleting forms release
the object itself through the arena allocator.

The original World and Resource tables remain outside these text splits.
The original Resource destructor receives its confirmed native ABI name but
still uses original code. The world constructor/destructor objects emit weak
Resource table/destructor copies; original strong symbols override them.
Other unused array helpers are discarded. None of these emitted-but-unlinked
bytes are credited as source. The strict proof accounts for 59 retained
relocations and every allocated symbol and section, including the weak table
bytes. The final ELF proof verifies all overrides and exclusions.

The factory's only source change is the native constructor identifier; its
84 bytes remain exact. Earlier record loader/query/resize source is unchanged.

```
python3 scratch/game_world_lifetime/verify.py --production
python3 scratch/game_world_lifetime/link_proof.py
```

Full validation is recorded in `scratch/world_lifetime_checkpoint.json`.
Later resource callbacks, owned tables, the Resource destructor body, and
unresolved record fields remain outside this partial recovery.
