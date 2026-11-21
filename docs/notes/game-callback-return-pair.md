# Callback pair of typed-handle temporaries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80258E48` reconstructs the complete 280-byte entry at
`0x80258E48..0x80258F60`. It runs the original related-object helper,
constructs a returned typed handle from owner handle `0x70`, constructs a
second typed copy, destroys the first temporary with native flag 0, and
passes the surviving copy to the target resolved from owner handle `0x80`.
The surviving copy is then destroyed with native flag 0.

Actual C++ temporaries reproduce both lifetimes. The explicit source
reference to handle `0x70` preserves the observed member pointer across
construction calls. Each typed handle has three observed inline zeroing
layers before its retained word is copied. These private views record only
observed operations; full class identities remain unknown. Existing frozen
owner and related-target declarations are reused without edits.

An inline factory variant remains private: this compiler leaves its factory
call out of line, so it cannot represent the native function. The final
nested temporary expression needs no factory or extra strong helper.

The exact strong entry is followed by six unused weak destructors totaling
560 bytes. The frozen manifest records their complete extents, bindings and
raw hashes independently. They receive no progress credit, no retained
relocation references them, and central full-link acceptance requires every
weak symbol to be absent from the executable. The dedicated verifier at
`scratch/game_callback_return_pair/verify.py` recompiles and checks all
allocated bytes, actual relocations and complete function extents without
masks. Original exception/startup ownership and whole-DOL/regression checks
remain part of central acceptance.
