# Typed handle array clear and forward

`src/Game/handle_array_clear.cpp` reconstructs `fn_80269FE0`, the 328 bytes
at `80269FE0..8026A128`. It resizes the typed-handle array at offset `0C` to
zero, resolves the owner handle at offset `30`, and forwards the array to
`fn_8023EFAC`. A negative old count retains the original placement-construction
loop and capacity repair branch. A positive count destroys elements in reverse
order, retaining allocation capacity.

The dedicated header uses the previously verified handle generation/index
layout. Two derived handle layers reproduce the two initialization stores and
nested destructor null checks. Separating the reverse destruction loop into an
inline array helper recovers the original register allocation. These are
ordinary C++ construction and destruction operations.

GC/1.3.2 with standard optimized Game flags matches every retained byte after
all eight actual relocations are applied. The strict check is:

```
python3 scratch/game_handle_array_clear/verify.py
```

The object also emits the unused 84-byte weak destructor
`__dt__22ArrayClearNativeHandleFv`. Its bytes, symbol metadata and two external
call relocations are checked separately; these bytes earn no progress credit.
Integration must confirm this weak symbol is absent from the final ELF. The
complete emitted allocation inventory contains only these 412 text bytes, with
no constants, data, BSS, constructor/destructor tables, exception tables or
padding. The original assembly references to the retained function are direct
calls; no constructor entry or owned data accompanies this partial text split.
Original neighboring functions and allocator/manager objects retain their
existing ownership. No original translation-unit boundary is claimed.

`candidate.json`, `actual_relocations.json`, and `unlinked_relocations.json`
preserve the isolated evidence. Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
