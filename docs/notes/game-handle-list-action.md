# Handle list action

`src/Game/handle_list_action.cpp` reconstructs `fn_80268194`, the 464-byte
function at `80268194..80268364`. It inlines the established related-handle
lookup, creates a native handle, copies the found handle's word and adjusts
the manager reference through `fn_801F86C8`. If the local handle passes
`fn_801F7EB8`, it resolves that handle and invokes `fn_801EDAAC` with the three
original float arguments, returning one; otherwise it returns zero.

The source uses the read-only list layout and comparison helper from
`handle_list_operations_internal.h`. An empty derived handle layer preserves
the observed base-destructor flag zero on both returns. Construction and
destruction remain ordinary C++ operations. The original scalar constants
`8037B640/8037B644` are referenced through their existing global symbols and
retain original data ownership.

GC/1.3.2 with standard optimized Game flags reproduces all 464 retained text
bytes and all ten actual relocations, including the two SDA21 constant
references. The strict verifier accounts for the complete emitted object:

```
python3 scratch/game_handle_list_operations/verify_action.py
```

The compiler additionally emits the unused 84-byte weak destructor
`__dt__16ListActionHandleFv`. The verifier checks its exact raw-byte hash,
name, offset, size, binding and two external call relocations. These bytes
are explicitly unlinked and earn no progress credit; the full-build audit confirms
that the weak destructor is absent from the final ELF. The object emits no
constant, data, BSS, constructor/destructor table, exception table or padding.
Original assembly references are calls and definitions, with no constructor
entry to transfer.

`action_candidate.json`, `action_actual_relocations.json` and
`action_unlinked_relocations.json` preserve the acceptance evidence. This is
a fully integrated and accepted match. The split owns
only the retained function, leaving original data and neighboring functions
outside it; no original translation-unit boundary is claimed.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
