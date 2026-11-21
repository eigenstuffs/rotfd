# Actor disable controls at 800384DC

`src/Game/actor_disable_controls_800384DC.cpp` reconstructs the original C entry
`fn_800384DC` (1,260 bytes), with its 144-byte exception record and 12-byte index.
It disables an actor, applies a point through virtual slot 18C, updates timing
and status fields, conditionally adjusts related actor flags and dispatches
virtual actions, then notifies the owner. Names describe observed behavior;
opaque storage remains private to this partial original translation unit.

The owner has an observed 64-bit flag field at 38, Handle fields at 58 and 70,
and a virtual table at 8. A 32-bit field loses the original `lis`/`or` sequence.
The resolved node view establishes Handle fields at C and 20, flags at 120,
time at 410, active at 414, and disabled at 415. Its virtual table is at 8.
The ordinary `Point(float,float,float)` constructor retains the original stack
stores without emitting an additional aggregate literal allocation.

GC 1.3.2, Gekko, `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`
reproduces all owned bytes with actual relocations. Three emitted weak native
Handle destructors (112/116/116 bytes) and their 156 bytes of exception metadata
remain uncredited. The accepted strong owners are Handle 8001FF78, 80020B90,
and 80027528. Each is independently recompiled and checked against its accepted
production object and original bytes; actual MWLD/map verification discards all
nine backup allocations and selects the original strong definitions.

The batch evidence is under `scratch/game_related_actor_reset_batch_20261011`.
There are 37 retained and 21 discarded actual relocations. The full original
exception-index, constructor, destructor, and initialized-word audits find only
the expected index pointer into this extent. External strings/constants and all
other original data remain externally owned. The C entry identity is unchanged.
Isolated verification passes; full original DOL hash, regression, production
extent and native original-placement acceptance remain the root integrator's
requirements before source credit.
