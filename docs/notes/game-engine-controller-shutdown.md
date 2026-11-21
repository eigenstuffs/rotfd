# Global controller shutdown

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated ordinary C++ source in `src/Game/engine_controller_shutdown.cpp` matches fn8020B078 at `8020B078..8020B774`, all 1,788 text bytes. GC 1.3.2 with the default Game compiler flags emits one strong function, no other allocated section, and no weak backup. All 97 actual relocations resolve to the original targets. Full production executable acceptance remains with the root integrator.

The entry shuts down the global services rooted at lbl801E9D24. It invokes the observed virtual cleanup slots, destroys the three pool owners at offsets 128, 12C and 130, destroys the four-handle owner at 13C and the paired handle at 138, frees the buffer at 168, and finally destroys the controller at 118. The owner at 158 receives its slot44 call only when the controller's signed byte at C8 is zero. Each destroyed service pointer is cleared at its original point in the sequence.

The dedicated header provides partial global storage, virtual-slot and member-owner views. The virtual declarations model the observed dispatch offsets without emitting tables or out-of-line implementations. Ordinary `delete` expressions preserve the original virtual deletion calls. Nested pool and array destructor layers reproduce the original null checks and member cleanup order; the backing allocation for each reserved pointer begins sixteen bytes before its element pointer. The array contains twelve-byte records with the existing native Handle destructor. The four actual Handle_801FFE58 members cause the compiler's normal `__destroy_arr` call with stride four and count four, rather than a manually declared runtime destruction call. The paired and dynamically stored handles use the existing Handle_801F7F10 destructor. Inline layer names express observed cleanup structure and do not claim the original class names.

The retained C entry identity, both native Handle identities and all global/runtime/allocator symbols are unchanged. The accepted caller `src/Game/engine_frame_gate.cpp` and its header remain untouched. No consumer, function, table or global identity migration is proposed. `consumer_inventory.txt` records the current direct entry references.

The frozen manifest is `scratch/engine_controller_lists_destructor_20261011ei/final_integration.json`. Its verifier recompiles the production source and checks every allocated byte, exact symbol extent, the complete actual relocation sequence, original table ownership and frozen source/research hashes. The complete original extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, including descriptors, padding and terminators, contain no reference to the retained range. This source emits no initialized data, BSS, padding, exception table or startup allocation.

This is a partial text split. Referenced globals, allocator/runtime functions, other services, adjacent routines and original translation-unit data retain their current owners. Register this unit as NonMatching first and promote only after the full original DOL hash and standard acceptance checks pass. The initial and intermediate probes remain preserved without credit.
