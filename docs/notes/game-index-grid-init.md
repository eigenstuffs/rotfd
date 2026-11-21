# Index-grid initialization

`src/Game/index_grid_init.cpp` reconstructs the 152-byte `fn_80266758` at
`80266758..802667F0`. It zeros two array descriptors, initializes the bitset at
`1C`, copies the existing integer zero vector into fields `6C..74`, copies the
existing float zero vector into `78..80`, sets the flag at `84` to one and
returns the receiver. Explicit integer/float component assignment preserves
the original load/store ordering.

The source reuses the frozen bitset declaration and its existing constructor
ABI entry. `game_int3_zero` and `game_vec3_zero` at `80340B48/80340B54` remain
external original objects; no duplicate zero data is emitted or claimed.

GC/1.3.2 with standard optimized Game flags reproduces all 152 bytes after
five actual external relocations are applied. Run:

```
python3 scratch/game_index_grid_init/verify.py
```

The complete object emits exactly one global text function, with no weak
functions, constants, data, BSS, constructor/destructor tables, exception
tables or padding. Original references to this initialization entry are calls;
no global constructor table entry or owned data accompanies this partial text
split. Adjacent functions and the external zero vectors retain their existing
ownership. No original translation-unit boundary is claimed.

`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
