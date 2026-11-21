# World record callbacks, loading and resizing

Two text-only partial units reconstruct `0x801E30E4..0x801E3AC4`:
`src/Game/world_record_callbacks.cpp` owns three functions / 1,328 bytes;
`src/Game/world_record_resize.cpp` owns two functions / 1,200 bytes.
Their shared partial layouts are in `world_records_internal.h`. World/record
names describe inferred roles, not established original class identifiers.

## Record operations

`fn_801E30E4` resolves two references in each 20-byte record and calls the
first object's virtual slot `0x20` with the second object and zero. Both
references are resolved before testing the callback object for null.

`fn_801E31EC` applies the external reference-fixup helper to three handles
per 28-byte record and two handles per 20-byte record. Between those loops
it invokes each 80-byte record's helper, then finally processes the action
list at offset `0x54`. The manager pointer is cached once. This is reference
fixup, not garbage-collection marking: the external helper maps stored values
to manager entries, updates generation/index bits, retains resolved objects,
and clears unresolved references.

`fn_801E3310` calls the qualified Root loading hook, advances the binary
cursor through word `0x74` and five record-array counts, and invokes the
original resize/read/fixup helpers. The five element strides are `0x50`,
`0x4C`, `0x3C`, `0x1C`, and `0x14`. The last two formats expose named keys,
scalar fields and handles directly. Each iteration reloads the current array
pointer after external calls, preserving the original aliasing behavior.
The action-list reader closes the routine. Unknown formats and helpers stay
external; no guessed validation or additional input checks are introduced.

## Native resize behavior

`fn_801E3614` and `fn_801E3868` resize 20-byte and 28-byte records. Growth
adjusts allocation when capacity is insufficient or the keep-capacity flag
is clear, then constructs new records in place. Shrinking destroys records
in reverse order. It preserves capacity when requested, otherwise adjusts
storage and capacity to the new size. Equal-size requests do nothing.

Both records own three handles with two observed typed layers. Their ordinary
C++ constructors/destructors reproduce the layer zero stores and null checks.
The 20-byte record initializes one key and a sentinel word; the 28-byte record
initializes two keys, a sentinel word and a byte flag. The allocator calls use
old/new capacities multiplied by the actual element size. Placement new and
explicit C++ destruction generate the lifetime code naturally.

The resize source's template-dependent definitions are emitted in reverse
order by this compiler; the final object and split retain original address
order. No object rewriting, instruction masks or padding are used.

## Ownership and verification

The callback object emits exactly 1,328 text bytes and 41 actual relocations.
The resize object retains 1,200 text bytes with 48 actual relocations and emits
260 additional weak destructor bytes that are absent from the final image.
All emitted sections and symbols are accounted for; no data, BSS, weak-code,
or alignment credit is claimed. Neighboring resizing, camera/projection,
world lifetime, tables and shared data remain outside these partial units.

Strict production checks:

```
python3 scratch/game_world_record_callbacks/verify.py --production
python3 scratch/game_world_record_callbacks/verify_resize.py --production
```

All five functions match the immutable DOL after their actual relocations are
applied. `scratch/world_records_link_proof.json` checks linked addresses,
sizes, byte hashes and discarded weak helpers. The full DOL is byte-identical,
all 636 source units match, and all 23 tests pass. The original baseline and
previously linked source files are unchanged. All 633 candidate source/object
hashes and 90 recorded header hashes are current; progress, source extent and
assembly audits pass. See `scratch/world_records_checkpoint.json` and the
corresponding build, changes and test logs.
