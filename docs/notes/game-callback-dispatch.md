# Callback dispatch at 8025F240

`src/Game/callback_dispatch.cpp` reconstructs the complete 316-byte function
at `8025F240..8025F37C`. The private node view adds the observed native C++
member-function pointer at offset four and the 16-bit counter at `2A`.
The enclosing type and field names remain provisional.

The dispatcher marks a node visited, requests activation with callback event
9, sets the active flag and resets the counter when activation succeeds, then
sends event 10. Event 11 selects completion (clear the active flag and send
12) or continued processing (query 14, then send 15 or 13). Calls preserve the
native member-pointer ABI through ordinary C++ expressions; the compiler emits
all seven `__ptmf_scall` calls and their following no-op instructions.

The GC/1.3.2 strict verifier checks all 316 bytes, one complete global function,
seven actual call relocations and one nonallocated compiler metadata reference:

```
python3 scratch/game_callback_dispatch/verify.py
```

No extra function, constructor, owned table, constant, BSS or exception record
is emitted or claimed. Original exception-index and constructor tables were
independently scanned for all functions in this integration batch.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
