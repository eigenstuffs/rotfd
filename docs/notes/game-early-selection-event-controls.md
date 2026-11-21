# Early selection and event controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 1,460 text bytes and
100 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80024A5C | 368 | 80005F50..80005F58 | 80016368..80016374 | 13 |
| fn_800370F8 | 204 | 80007984..8000798C | 80016EA8..80016EB4 | 7 |
| fn_800371C4 | 248 | 8000798C..80007994 | 80016EB4..80016EC0 | 8 |
| fn_800E39F0 | 320 | 800149E4..800149EC | 8001E8A0..8001E8AC | 8 |
| fn_800E3B30 | 320 | 800149EC..800149F4 | 8001E8AC..8001E8B8 | 12 |

24A5C marks the actor owner flags and selection index, allocates and constructs
a 20-byte selection record, copies the resolved origin, disables its control
and increments the unsigned-byte count. Its in-place pointer array covers
all 256 unsigned-byte indices. The placement constructor initializes position,
actor and enabled fields directly. It emits no helper or data allocation.

370F8 resolves and caches the actor, tests its unsigned state byte 415, marks
the owner and sends the two native event commands before setting actor time
and state. 371C4 constructs the original motion vector, invokes virtual slot
18C, clears state 415 and forwards the reset/event commands. E39F0 runs base
setup, binds the current owner in the scene and updates related actor flags.
E3B30 handles the two event queries, toggles the owner flag and updates the
resolved actor record. Correct unsigned-byte and virtual-slot declarations
resolved the only initial diagnostic differences.

The new `early_selection_event_control_views.h` has five inventoried consumers.
It contains partial observed layouts and declaration-only virtual interfaces,
ordinary signed handle bitfields and inline component copies. All constants,
allocator, strings and context globals retain their original borrowed owners.
No weak helpers, new data, BSS, padding, aliases or native identity migrations
are emitted. Five independent contiguous section mappings are in
`scratch/game_engine_batch129/manifest-list.json`.

Fresh strict production recompilation verifies every allocated byte, real
relocation target, compiler local EH name and extent, and original DOL hash.
The complete 3,141-entry exception index plus descriptor and all ctor/dtor
entries establish original table ownership. All source/header/evidence hashes
are frozen. Full native link/hash, regression checks and progress acceptance
remain with the central integrator.
