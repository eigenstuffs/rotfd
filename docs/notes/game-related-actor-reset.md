# Related actor reset at 800389C8

`src/Game/related_actor_reset_800389C8.cpp` reconstructs the original C entry
`fn_800389C8` (956 bytes), its 144-byte exception record, and 12-byte index.
It copies the owner's related Handle, retains two nested Handle values,
updates related flags, dispatches a reset through virtual slot 40, conditionally
applies a three-float operation, clears the resolved state's byte at 415, and
forwards owner notification arguments 1 and 0.

Private layouts establish owner Handles at 58 and 70, node self Handle at 4,
virtual table at 8, child Handles at C and 20, flags at 120, and the state byte
at 415. Manager entries have stride 16, node pointer at 0 and signed generation
at C. Named `const Handle&` member references preserve the observed source
pointer lifetimes. The validity helper returns an unsigned word; using `int`
instead changes the two native unsigned comparison instructions.

GC 1.3.2, Gekko, `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`
produces exact code and exception structure. Three compiler-emitted weak
destructor backups total 344 text bytes plus 156 exception bytes, all uncredited.
Accepted native Handle 8001FF78/80020B90/80027528 strong owners are independently
recompiled and checked against actual production bytes and relocations. Actual
MWLD/map verification discards all nine backup allocations and selects those
original strong definitions. There are 29 retained and 21 discarded relocations.

The full original initialized-word scan finds the expected index and a callback
pointer at 802B2550 inside the original 156-byte `lbl_802B2518` table. That table,
its original pointer identity, all other original data, and the existing C entry
name remain unchanged. No startup constructor/destructor entry refers to the
function. Evidence is frozen under `scratch/game_related_actor_reset_batch_20261011`;
this is a partial original translation unit. Isolated strict verification passes;
the root integrator must still require the original full DOL hash, no regressions,
all production extents, and original-placement native backup-discard audit before
source credit.
