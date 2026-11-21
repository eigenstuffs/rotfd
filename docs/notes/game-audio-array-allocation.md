# Audio record array allocation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80287CA8` (`0x80287CA8`, 336 bytes) allocates two arrays of 256
44-byte records and two arrays of 256 48-byte voice records, using the
original heap diagnostics and per-call line values. It initializes each
array through the existing compiler runtime constructor service and clears
the corresponding owner counts in the original order.

The source uses ordinary C++ calls to the heap and array construction
runtime, with the already matching original record constructors. This
preserves their existing identities and consumers. It does not claim a
reconstruction of the original class names or source-level allocation
expression. The partial owner layout includes only observed fields.

`src/Game/audio_array_allocation.cpp` emits exactly 336 text bytes and 40
actual external relocations, with no other allocations, weak helpers,
exception metadata, or startup-table references. The frozen strict proof
and complete original metadata scans are in
`scratch/game_audio_runtime_controls/allocator_final_integration.json`.
The central production build and original DOL hash check remain pending.
Original shared literals and heap state remain with their existing owners.
