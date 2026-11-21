# Handle owner update forwarding

`src/Game/handle_owner_update.cpp` reconstructs the 128-byte `fn_8026A690` at
`8026A690..8026A710`. It forwards the incoming time step to the verified handle
list update `fn_80268364`, invokes `fn_8028DD18` on the same instance, resolves
the owner handle at offset `30` and invokes `fn_8023DE28` on that object.
The source reuses the frozen typed-array view and handle resolution layout.

GC/1.3.2 with standard optimized Game flags reproduces all 128 bytes after
five actual external relocations are applied. Run:

```
python3 scratch/game_handle_owner_update/verify.py
```

The strict verifier checks the entire emitted object, symbol size and binding,
all relocation sites and targets, and the original DOL hash. The only allocated
section is the exact 128-byte text function. There is no owned constant, data,
BSS, constructor/destructor table, exception table, weak function or padding.
Original references are calls; no original constructor entry accompanies this
partial text split. Neighboring functions and the manager global retain their
existing ownership. No original translation-unit boundary is claimed.

`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
