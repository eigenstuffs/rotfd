# Native slot-resource destructor and table

`src/Game/resource_slot_destructor.cpp` owns the native destructor at
`801E6EA8..801E6FB0` (264 bytes), and its 12-byte virtual table at
`802EA810..802EA81C`. The original four zero bytes at `802EA81C..802EA820`
remain an explicit original padding unit and receive no source credit.

The recovered 68-byte class has a 36-byte pool member at offset zero, a
12-byte handle array at 24, a 16-byte bitset at 30, and its native virtual
pointer at 40. Its ordinary empty C++ destructor emits the vtable store,
bitset cleanup, ascending destruction and freeing of the handle array, pool
member cleanup, and conditional arena deletion. The -1 pool destructor flag
establishes member cleanup; treating the pool as a base produces flag zero
and does not match. Names remain provisional original identities.

The pool destructor at 801E6FB0 is renamed to its native C++ identity so the
reference resolves, but its body remains original code. The private 412-byte
candidate still differs in 13 instructions and receives no credit. No other
existing source was changed for the identity updates.

The strict proof in `scratch/game_resource_slot_lifetime/verify_derived.py`
checks every code and table byte with all 12 actual relocations. There are no
weak helpers or unaccounted allocated bytes. Final ELF verification checks
native ownership, the separate padding symbol and the unchanged full DOL.
All 654 source units were exact at acceptance; all 23 tests and progress,
extent and assembly audits passed. The initial baseline is unchanged. Existing
fallback/native-padding accounting warnings in `ninja changes` remain, with
no source regressions. Evidence: `scratch/resource_slot_destructor_checkpoint.json`.

This is a partial text/data split. The larger manager interface and other original data remain outside its
ownership. The [constructor](game-resource-slot-constructor.md) is now
matched in a separate source unit.
