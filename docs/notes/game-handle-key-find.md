# Typed handle lookup by object key

`src/Game/handle_key_find.cpp` reconstructs `fn_8026A494`, the 424 bytes at
`8026A494..8026A63C`. It searches the typed-handle arrays at offsets `0C` and
`24` in order, resolving each handle and comparing the resolved object's first
pointer-sized field with the supplied key. On success it returns a copied
handle and adjusts its manager reference through `fn_801F86C8`. Otherwise it
returns a default typed handle. C++ value return supplies the original hidden
result pointer ABI.

The private handle layers implement the observed native constructor, zero
store, word copy and reference adjustment. A default handle adds the second
zero store. Both loops share their signed index variable, reproducing the
original second-loop initialization instruction. The underlying generation
and index layout comes from the established frozen handle headers.

GC/1.3.2 with standard optimized Game flags matches all 424 retained bytes with
seven actual relocations. The complete allocation check is:

```
python3 scratch/game_handle_key_find/verify.py
```

The object additionally emits the unused 84-byte weak destructor
`__dt__19KeyFindNativeHandleFv`. The verifier accounts for its exact raw bytes,
symbol metadata and two external call relocations separately. These bytes earn
no progress credit; integration must confirm the weak symbol is absent from
the final ELF. No constant, data, BSS, constructor/destructor table, exception
table or padding is emitted. Original function references are calls, with no
constructor entry to transfer. This partial split leaves neighboring functions
and the manager object in their existing ownership and does not claim an
original translation-unit boundary.

`candidate.json`, `actual_relocations.json` and `unlinked_relocations.json`
preserve the isolated evidence. Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
