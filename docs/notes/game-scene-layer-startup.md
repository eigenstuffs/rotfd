# Scene layer startup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`scene_layer_startup_800C4BE4.cpp` reconstructs original `800C4BE4..800C4CD0`,
236 code bytes with its complete eight-byte exception record and twelve-byte
exception index. It resets the original global, invokes the existing setup
routine, and constructs and destroys a temporary scene layer.

Ordinary inheritance and member destructors recover both scene-layer vtable
stores, the base vtable restoration, the three-layer and two-layer Handle
cleanup, the empty-element array loop, allocator release and original Object
base destruction. The observed layer extent is `0x70`; opaque fields preserve
the original layout. Existing constructors, base destructors, allocators,
vtable records and the reset global retain their original owners and names.

All seventeen retained actual relocations and retained allocated bytes match.
The compiler emits an unused 300-byte ContainerLayer destructor with 52
exception/index bytes and sixteen relocations. Its complete allocation and
relocation inventory is frozen under the existing strict weak-EH schema with
no strong overrides; it receives no credit and requires native-link discard.
The complete original exception/startup table scan finds one exception entry
and no startup references. No data ownership or consumer identity changes
are required. Evidence is in `scratch/game_scene_layer_startup/`; this is a
partial original translation unit.

Full native acceptance passed, including the complete unused destructor and
exception/index allocation discard.
