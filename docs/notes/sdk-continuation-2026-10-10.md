# SDK continuation: lighting colors and TEV order

This bounded continuation investigated the remaining ordinary-C fragments in
[GXLight](GXLight.md) and [GXTev](GXTev.md). It does not establish any new
matching source, split, symbol, data ownership, or progress credit. Production
sources, shared headers, compiler configuration, and original input are
unchanged.

The best preserved candidates still emit the correct function extents:

| Candidate | Original range | Unresolved words |
| --- | --- | --- |
| `src/dolphin/gx/GXLight_colors.c` | `0x801148AC..0x80114A94` | Eight instructions: each RGB merge copies into the final register after its insertion instead of before it |
| `scratch/GXTev/GXTev_order.c` | `0x801162E8..0x801164C0` | Two instructions: the invalid-coordinate path computes the cached field address before loading the value |

The TEV candidate's full 36-byte table at `0x802CFC28..0x802CFC4C` remains
exact. It is still original fallback with its function. The following four
bytes are alignment padding and are excluded from this candidate.

New isolated probes are retained in `scratch/sdk_continuation/`:

- `flags.py` checks independently disabling propagation, lifetimes, CSE,
  dead-store removal, dead-code removal and function optimization, and checks
  optimization levels 2 and 3. None improves the preserved candidate.
- `forms.py` checks ordinary packed-color unions, bitfields, C mask/arithmetic
  expressions, scoped volatile cached-state accesses, compound assignments,
  De Morgan mask clearing, and equivalent bit-mask expressions. None improves
  the preserved candidate.
- `versions.py` checks previously unexamined compiler revisions 1.1p1,
  1.3.2r, 2.0, 2.0p1, 2.5, 2.6 and 2.7. All are worse than GC/1.2.5n.
- `processors.py` checks 750, 740, 7400, generic, 604e, 603e, 602 and 601
  scheduler targets. None improves the preserved candidate.

Each probe compiles an independent object, disassembles it, resolves the
actual symbolic address relocations, and compares the resulting instruction
words to the supported DOL. No relocation masking is used. The `.result`
files retain per-instruction diagnostics; differing function extents are
failures, even when a diagnostic equality count is high. No accepted manifest
is written by these experiments. Full link and hash verification remain
required if a future source variant closes either discrepancy.
