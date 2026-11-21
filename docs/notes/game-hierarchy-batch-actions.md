# Hierarchy batch assignment and reset

Two complete adjacent-family methods are recovered in separate source fragments:

| Source | Original extent | Code bytes | Retained relocations |
| --- | --- | ---: | ---: |
| `src/Game/hierarchy_batch_assign.cpp` | `0x802020AC..0x802022FC` | 592 | 10 |
| `src/Game/hierarchy_batch_clear.cpp` | `0x80202464..0x8020279C` | 824 | 7 |

The assignment method applies the already recovered entry-assignment algorithm
to each active entry at `offset + index`, dispatches virtual slot 11 across the
primary and valid secondary members, and invokes the related object's helper
at `0x80213A18`. The entry assignment retains the same game-entry reference
accessor, target reference-count updates, and temporary owned-handle lifetime
as the independently verified method at `0x80201F94`. It is ordinary inlined
C++ here, with no call substituted for the original inlined instructions.

The reset method sets valid secondary and primary members to `-1` through
their virtual methods at offsets `0x9C` and `0x7C`, resets the third list,
sets the hierarchy offset and related object's state to `-1`, then performs
the primary/secondary list reset and related-object helper at `0x802139D8`.
The final list operation is the same algorithm as the recovered method at
`0x802022FC`. Expressing it as an ordinary inline helper preserves the original
loop-variable lifetime and register allocation; duplicating its loop directly
in the outer method leaves 11 register bytes different.

The new private `hierarchy_batch_internal.h` records the common three lists,
related handle, third list, counts, and offset. It includes the existing
generation-checked resolver and virtual object layout without modifying them.
The reset source extends the virtual declarations privately for its two used
methods; no vtable data are emitted. Original class and method names remain
unknown, so descriptive private names do not claim recovered debug symbols.

The strict isolated verifiers are
`scratch/game_hierarchy_batch_actions/verify_batch_assign.py` and
`verify_batch_clear.py`. GC/1.3.2 with `-O4,p`, `-inline auto`, and
`-use_lmw_stmw on` reproduces all 1,416 retained code bytes and all 17 retained
relocations against the SHA-1-checked original DOL. Neither fragment owns data,
BSS, exception records, external literals, or alignment padding.

The assignment source emits two unused weak wrapper destructors totaling 172
bytes. The verifier checks both exact extents and bindings, all four helper
relocations, and the absence of retained references into those bodies. Normal
linker dead stripping removes them; they receive no source credit. The reset
source emits only its recovered 824-byte function.

The handoffs are `config/GSQE78/candidates/game_hierarchy_batch_assign.json`
and `game_hierarchy_batch_clear.json`. Full-DOL and native objdiff integration
pass for both units: 1,416/1,416 code bytes, two functions, and no owned data.
The complete executable is byte-identical to the protected original, and the
source-section extent guard passes. Existing source and shared headers were
unchanged throughout this work.
