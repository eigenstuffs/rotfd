# Unclassified function continuation, 2026-10-24/25

This continuation matched previously unclassified functions with parallel
worker agents (procedure: `scratch/claude_match/GUIDE.md`) and one integrator.
Every unit was verified with `tools/fdiff.py` (`EXACT`, `EXACT-WEAK`, or
`-DATA` only for compiler-generated items the unit then owns) and accepted only
after the full build reproduced the original DOL hash; `ninja changes` against
the session baseline reported no regressions at each checkpoint. The
integration helper is `scratch/claude_match/integrate.py`; the per-unit log is
`scratch/claude_match/SESSION_2026-10-24.md`.

Start of session: 2,028,640 / 2,607,776 code bytes (77.79%), 8,216 / 8,803
functions. See PROGRESS.md for the current generated totals.

## Integration mechanics

- `report_strip_weak=True` is added to every `EXACT-WEAK` unit so discarded
  inline-destructor copies do not lower the extab/extabindex data score.
- Int-to-float bias doubles and switch jump tables that a unit emits privately
  are given to it with `tools/absorb_data.py`. When the label sits inside an
  `original/` or `padding/` assembly fragment, the helper first carves the
  fragment around the range (new fragment named after its start address).
- Partial text splits (`tools/integrate_unit.py --functions`) are used when a
  unit has no extab and only a contiguous run of its functions is exact; each
  such source states in its header which neighbouring functions remain
  original code.
- One unit (`scene_transition_shutdown_800BE8AC.cpp`) uses the existing
  `extab_padding` option for four uninitialized padding bytes in its
  DESTROYLOCALCOND records.
- Int-to-float units own their literal pools (approved 2026-10-25): the
  matched constants unit holding the pool is shrunk or retired with
  `tools/split_data_unit.py`, the range is given to the code unit with
  `tools/absorb_data.py` (original fragments are carved first), and the DOL
  hash plus `ninja changes` decide acceptance. Example: fn_8024DEF8 made
  `curve_bezier_sampling_8024DA4C.cpp` the whole four-function unit with its
  pool 0x8037B460..0x8037B46C; `lbl_8037B468` was a 4-byte float whose
  symbols.txt extent had absorbed 4 bytes of alignment padding, so its size
  was corrected to 0x4.
- Alignment padding left behind when a pool moves (a tail after the new
  owner's emitted extent, or a gap before an 8-aligned neighbour) gets a
  `padding/source_extents/` unit with an explicit global `pad_source_extent_*`
  symbol of `align:1`, as in `source-section-padding.md`; without the symbol
  the linker misplaces 1-byte or odd-address padding, and without the unit the
  bytes leave the data denominator. Total data stays 1,030,932 bytes.
- `TRKMessageSend` is linked from the new `src/MetroTRK/msg_send.c`; the older
  unregistered research file `src/MetroTRK/msg.c` is kept for reference.

## Source techniques established

- **Pooled-literal emulation.** The original's float literals were not CSE'd
  with each other. Distinct read forms of one extern label — plain,
  `*(const float*)&lbl`, and the `(unsigned long)`, `(long)`, `(unsigned int)`
  and `(int)` address casts (more spellings are distinct within one basic
  block) — reproduce separate literal loads while keeping the shared label.
  Per-use assignment, sometimes found by enumerating combinations, closed
  dozens of float-register near-misses without moving data ownership.
- **Extern string pools.** When the original keeps a pool base in a saved
  register, a struct view of the whole pool, one `const Pool*const` local, and
  the offset-0 string reached as (member pointer to the next string) minus its
  offset reproduce `addi rX,rB,0x0` in its original slot; the pools stay owned
  by the `native_readable_pools_*` units.
- Compiler version (`GC/1.3`), `-opt nocse`, `-opt nopropagation` and
  `#pragma fp_contract on/off` matter per unit; neighbours' flags are the
  first guess.
- Loop and accessor shapes: unsigned accessor indices change strength
  reduction (SlotPool destructor); a resize grow loop counting with a separate
  copy of the index fixed the world handle loader; inline vector helpers that
  build `T r; r.x=..; const T& q=r; return q;` reproduce dead stack copies.
- CodeWarrior gives a C++ object's `.data` 8-byte alignment, so a private jump
  table starting 4 mod 8 can only be emitted together with the TU's earlier
  data (see `fn_800B7214`, `fn_800C96E0`).
- CodeWarrior evaluates constructor arguments right to left, so building a
  vector with `Vec3(x*s, y*s, z*s)` schedules its products differently from
  three assignments.
- An inline helper that assigns its pointer parameter to itself (`p = p;`)
  keeps the argument in its own saved register, as an inlined member
  constructor's `this` is kept (particles_constructor_80252B54,
  callback_record_acquire_80252E1C).
- Files that instantiate templates or use compiler-generated copy members
  have those functions deferred and emitted in reverse definition order; such
  sources are written in reverse address order (curve_bezier_sampling_8024DA4C,
  segment_query_cache_80269230).
- A 3-iteration pointer loop that the compiler unrolls lets loop-invariant
  code motion hoist a pooled constant first, reproducing the original's FPR
  split (render_material_bind_80272968).

## Not integrated (decision or further work needed)

These are exact or nearly exact but would require changing existing matched
sources, `symbols.txt`, or adding game assembly sources; they were left for an
explicit decision:

- `__ct__14Agent_80052520Fv`: code and extab identical; needs `fn_800528F0`
  renamed to `__ct__15Handle_80024844Fv` with its source rewritten as that
  constructor (declined once in this session).
- `fn_80098EDC`, `fn_800A5080`: bias doubles defined inside matched scalar or
  token data sources.
- `fn_80071A64`, `fn_800C96E0`, `fn_800B7214`: jump tables defined inside
  matched data sources or requiring a merge with a neighbouring unit's data.
- `main` (99.51%): exact only when it owns its BSS objects (now in
  `engine_reset_typed_storage.cpp`) with `lbl_8033E758` split into three
  symbols.
- `lbl_801E9D24` (engine context, 0x21C bytes in `.text`): exact as a
  `__declspec(section ".text")` object but needs a `symbols.txt` type change;
  the following `fn_801E9F40` appears to be hand-written assembly.
- `fn_801F0EFC`/`fn_801F1080`: paired-single matrix routines, hand-written
  assembly; an `asm` transcription is exact but no game source uses assembly.
  `fn_8027FF4C`/`fn_802800A8` (paired-single vertex loops that read a ninth
  argument from the caller's frame) look hand-written as well and remain
  original code after the gx_point_light_setup_8027F994 split.
- `fn_8024DEF8`: exact only when its unit owns `.sdata2` 0x8037B460..0x8037B46C
  (1e-6, 3.0, 6.0; referenced by nothing else), which means retiring
  `Game/scalar_constant_8037B460.c` and `original/float_remaining_fragment_8037B464.s`;
  the other three functions of its unit are integrated as a partial split.
- Int-to-float units: 70 of the 78 remaining have their bias double inside a
  matched constants unit (`Game/scalar_constant_*.c` and similar); integrating
  them means shrinking or splitting that unit. The per-unit owners are in
  `scratch/claude_match/bias_owners_2026-10-25.txt`.
- Renames: `fn_8023EFAC` needs three handle-constructor/placement-new renames
  (replacement owner sources in its scratch `identity/` folder) and still has
  one swapped load pair; `fn_8023BB18` and `fn_80263DDC` are real constructors
  that would need constructor symbol names.
- Nine adjustor thunks (e.g. `fn_80081368`) need their class's vtable source to
  emit them, which means renaming symbols in matched sources.

Numerous near-misses (typically 95–99.9%, register colouring only) are listed
with their best sources in the session log.
