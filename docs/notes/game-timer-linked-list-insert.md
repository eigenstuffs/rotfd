# Sorted timer linked-list insertion

`src/Game/timer_linked_list_insert.cpp` reconstructs `fn_802602B8`, the 232
bytes at `802602B8..802603A0`. It allocates a 20-byte timer node, assigns its
kind and target handle, stores the period and computes the firing time from
the list clock plus delay. It then inserts the node before the first existing
node with an equal or later time, preserving the original list ordering.

The node fields are handle `00`, kind `04`, next `08`, time `0C` and period
`10`; the list's clock is at `0C` and head at `1C`. The caller's target handle
is at offset `04`. The existing initial head is kept for insertion at the
front, reproducing the native load and pointer lifetime.

GC/1.3.2 with standard optimized Game flags reproduces the entire 232-byte
object after the two actual external call relocations are applied. Run:

```
python3 scratch/game_timer_linked_list/verify_insert.py
```

The object contains one global text function and no weak functions,
constants, data, BSS, constructor/destructor tables, exception tables or
padding. Original references are calls, with no constructor entry or owned
data accompanying this partial text split. Adjacent removal code retains
original ownership. No original translation-unit boundary is claimed.

`insert_candidate.json` and `insert_actual_relocations.json` preserve the
isolated evidence. Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
