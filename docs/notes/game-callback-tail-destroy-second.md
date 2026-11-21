# Second callback tail cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The native C++ destructor `CallbackTailOwnerSecond::~CallbackTailOwnerSecond()`
reconstructs the complete 392-byte function originally labeled
`fn_8025AB00` at `0x8025AB00..0x8025AC88`.

Its observed cleanup structure is the same as the isolated partial views
in [callback tail cleanup](game-callback-tail-destroy.md), with the first
vtable transition using `802ECAF8`. Ordinary C++ destruction generates the
native null checks, handle wrapper cleanup, pool element loop, pointer
clearing, original base destructor and optional allocator call. The class
name remains provisional, and no complete original base-class size is
claimed. Original shared declarations remain untouched.

`scratch/game_callback_tail_destroy_second/verify.py` checks all allocated
bytes, the exact global destructor extent and every actual relocation
without masks. No helpers or data are emitted. The original provisional
symbol can be replaced by the genuine compiler destructor name only after
checking that compiled sources do not depend on it. Original tables,
allocators and neighboring functions retain their ownership. Full
executable acceptance is required before matching credit.
