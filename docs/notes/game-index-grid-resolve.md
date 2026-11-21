# Resolve serialized index-grid context tokens

`src/Game/index_grid_resolve.cpp` reconstructs `fn_802667F0`, the 240 bytes at
`802667F0..802668E0`. It creates a temporary typed handle and walks the
20-byte grid records. For each nonzero context field, it calls `fn_801B3F0C`
with that serialized token, resolves the returned handle and writes the object
pointer back into the record's context field.

The record layout reuses the frozen index-grid declaration. A private signed
array accessor and simple context getter preserve the original address
formation. An explicit record pointer before the final assignment reproduces
the original store evaluation order. The temporary uses the frozen typed
handle's ordinary C++ constructor and destructor chain.

GC/1.3.2 with standard optimized Game flags reproduces every retained byte
after five actual relocations are applied. The strict check is:

```
python3 scratch/game_index_grid_resolve/verify.py
```

The object also emits unused weak destructors `__dt__21ArrayClearTypedHandleFv`
(88 bytes) and `__dt__22ArrayClearNativeHandleFv` (84 bytes). Their exact raw
bytes, symbols and four external call relocations are accounted separately.
These 172 bytes earn no progress credit; integration must confirm both symbols
are absent from the final ELF. All 412 emitted text bytes are accounted for,
with no constants, data, BSS, constructor/destructor tables, exception tables
or padding. Original retained-function references are calls; no constructor
entry accompanies this partial text split. Neighboring functions and external
manager data retain their existing ownership. No original translation-unit
boundary is claimed.

`candidate.json`, `actual_relocations.json` and `unlinked_relocations.json`
preserve the isolated evidence. Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
