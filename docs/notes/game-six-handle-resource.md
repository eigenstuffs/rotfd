# Six-handle resource lifetime, loading and status

`src/Game/six_handle_resource.cpp` owns four routines in
`801E7B98..801E7D1C` (388 bytes) and the 36-byte native virtual table at
`802EA840..802EA864`. Four original alignment bytes at `802EA864..802EA868`
remain separately owned original data and receive no source credit.
`src/Game/six_handle_resource_status.cpp` owns the 208-byte status callback
at `80267E2C..80267EFC`, referenced by the same table.

The 136-byte layout comprises the Resource base, an unknown word at C,
six native typed handles at 10, and 96 bytes at 28. The destructor uses
native array destruction for the six handles before base cleanup. The empty
slot20 hook, reference callback and loader match. The loader reads the word,
then six references, then the 96-byte block. The status callback checks Root
status, validates each handle and dispatches the referenced object's status
through an inline generation-checked resolution. It returns one after the
loop, regardless of individual callback results.

The [native constructor pair](game-six-handle-resource-constructor.md) now
also matches in its own 208-byte text split. Its calls identify the block
at 28 as eight 12-byte vectors; the shared declaration now records that
array. The vector constructor at `801D5330` remains original.
The neighboring large routine
at `801E7D1C` is a separate object traversal/render dispatch, not part of the
four-function lifetime/loading split.

Strict production proofs in `scratch/game_six_handle_resource/verify.py`
and `scratch/game_six_handle_resource_status/verify.py` verify every retained
byte with 27 and 4 actual relocations, respectively. The lifetime object
emits 104 weak Resource destructor bytes and a 32-byte weak Resource table;
original strong definitions override both and receive no new credit. The
status object emits no unused helpers or data. Final ELF checks prove the
source ownership, original padding and weak overrides.

All 660 source units remain exact, the complete DOL is byte-identical, and
all 23 tests and progress/extent/assembly audits pass. The initial baseline
is unchanged. Existing fallback/native-padding accounting warnings remain
without source regressions. Evidence:
`scratch/six_handle_resource_checkpoint.json` and
`scratch/six_handle_resource_status_checkpoint.json`.
