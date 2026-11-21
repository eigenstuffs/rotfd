# Resource slot callback dispatcher

`src/Game/resource_slot_callbacks.cpp` owns `fn_801E6D24`, the partial text
range `801E6D24..801E6EA8` (388 bytes). It owns no data or weak helpers.

The dispatcher iterates occupied records using `fn_80207B94`. A zero slot
limit produces the -1 sentinel without searching; subsequent searches stop
when the next index reaches that limit. For every occupied record, it resolves
each stored handle and invokes virtual slot 1C. It then performs the same
callback on the separate handle array at manager offset 24. The original
assumes these stored handles resolve; it has no added null-object guard.

The partial callback view extends the verified 36-byte manager prefix with
its 12-byte handle array. A reference-returning record accessor and reuse of
the outer iteration variable reproduce the observed address computations
and register allocation. The view is not a claim about the full original
class or its vtable ownership.

The strict probe applies all four actual relocations and verifies every
allocated byte. Final ELF verification and the full original DOL check pass.
All 653 source units remain exact, all current candidate/source/object/header
hashes agree, and all 23 tests, generated-progress, extent and assembly checks
pass. The initial baseline remains unchanged. The documented fallback/native
and padding warnings from `ninja changes` are unchanged; no source matches
regressed. Evidence: `scratch/resource_slot_callbacks_checkpoint.json`.

The native pool destructor at 801E6FB0 remains an uncredited 412-byte private
candidate with 13 instruction differences. Its verified behavior is to destroy
occupied records, clear their bits and decrement the live count, then destroy
the manager bitset and free record storage. The differences are register
allocation and loop increment scheduling; no masked score earns credit.
See `scratch/game_resource_slot_lifetime/resource_slot_lifetime_diagnostic.json`.
The [acquisition/setup](game-resource-slot-acquire.md),
[growth](game-resource-slot-growth.md), and
[slot-resource lifetime](game-resource-slot-destructor.md) now have separate
verified splits; other original shared data remains outside their ownership.
