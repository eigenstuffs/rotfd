# Six-handle resource construction

`src/Game/six_handle_resource_constructor.cpp` owns the native resource
constructor at `80267EFC..80267F90` (148 bytes) and the native typed-handle
constructor at `80267F90..80267FCC` (60 bytes). Both match exactly.

The resource constructor initializes its Resource base and native virtual
table, constructs six typed handles at offset `10`, and constructs eight
12-byte vectors at offset `28`. The shared lifetime header now represents
the former opaque 96-byte block as an eight-element `Vector3_801D5330`
array. The resource remains 136 bytes. The vector's empty constructor at
`801D5330` is still original and receives no credit from this split.

The typed-handle constructor reproduces native base construction and the
two zero assignments in its inline inheritance layers. Ordinary C++ array
construction emits the original runtime helper calls and constructor
references. No synthesized assembly or relocation masking is used.

Strict verification checks 208 retained bytes and 14 actual relocations.
The object also emits 188 weak helper bytes and a 32-byte weak Resource
table; these are excluded from source credit. Final ELF checks verify the
original strong Resource definitions and vector constructor and the
absence of the unused weak handle-layer constructor. Existing lifetime,
loader and status source units were reverified after the header change.

Evidence: `scratch/game_six_handle_resource_constructor/verify.py`,
`scratch/six_handle_resource_constructor_link_proof.json`, and
`scratch/six_handle_resource_constructor_checkpoint.json`. All 664 source
units matched at that checkpoint, the DOL remained byte-identical, and
all 23 tests and progress/extent/assembly audits passed. The baseline is
unchanged.
