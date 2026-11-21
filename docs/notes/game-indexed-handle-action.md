# Indexed handle action forwarding

`src/Game/indexed_handle_action.cpp` reconstructs `fn_8026B440`, the 288 bytes
at `8026B440..8026B560`. It resolves the target handle, reads that object's
index at `134`, copies the corresponding handle from the receiver's array,
resolves the copied handle and invokes the verified `fn_80268194` with the
target. It returns the action's signed-byte result after destroying the copy.

The source reuses the frozen native handle base. Its private typed handle
copy constructor first default-constructs the base, then copies the word and
adjusts the manager reference through `fn_801F86C8`. This constructor layering
preserves the native stack-handle pointer and exactly reproduces the original
code. The operations are ordinary C++ construction and destruction.

GC/1.3.2 with standard optimized Game flags reproduces all 288 retained bytes
after six actual relocations are applied. Run:

```
python3 scratch/game_indexed_handle_action/verify.py
```

The compiler also emits unused weak destructors `__dt__19IndexedActionHandleFv`
(88 bytes) and `__dt__22ArrayClearNativeHandleFv` (84 bytes). The complete object
check accounts for their raw-byte hashes, symbols and four call relocations
separately. These 172 bytes earn no progress credit; integration must confirm
both symbols are absent from the final ELF. All 460 emitted text bytes are
accounted for; there is no emitted constant, data, BSS, constructor/destructor
table, exception table or padding. Original retained-function references are
calls, with no constructor entry to transfer. The partial text split leaves
neighboring functions and manager data in their existing ownership. No
original translation-unit boundary is claimed.

`candidate.json`, `actual_relocations.json` and `unlinked_relocations.json`
preserve the isolated evidence. Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
