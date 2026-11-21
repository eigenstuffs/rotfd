# Callback tail cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The native C++ destructor `CallbackTailOwner::~CallbackTailOwner()`
reconstructs the complete 392-byte function originally labeled
`fn_80259C64` at `0x80259C64..0x80259DEC`. Ordinary C++ destruction reproduces
the entry null check, vtable transitions, member cleanup, signed deletion
flag, allocator call and returned object pointer.

The observed cleanup phases install tables `802EC958`, `802EC798`,
`802ED000` and `802EC720`. The handle at `0x64` has three empty wrapper
destructors, and those at `0x60` and `0x58` each have two. A pool at `0x48`
destroys its four-byte elements before releasing its allocation and
clearing its pointer twice. The final base cleanup calls the original
`Object_8025F0D8` destructor with deletion disabled. The static delete
operator uses the original allocator.

These are isolated partial class views. The opaque tail through `0x60`
establishes the next member offset for this fragment; it does not claim the
complete size or identity of the original base class. No shared class
declarations are changed. Provisional class names describe the observed
destruction layers, and the original function symbol must be replaced by
the compiler's genuine destructor name only after confirming that no
compiled source references the old name.

`scratch/game_callback_tail_destroy/verify.py` checks the exact global
destructor extent, every allocated byte and all actual relocations without
masks. The compiler emits no extra allocated helpers or data. Original
tables, allocator storage and neighboring methods retain their owners.
Full executable and baseline acceptance is required before matching credit.
