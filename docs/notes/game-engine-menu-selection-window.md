# Menu selection window

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Isolated exact handoff, awaiting central acceptance.** Ordinary C++ `fn_8021D51C`, `8021D51C..8021D7AC`, matches all 656 original text bytes and six resolved relocations with standard GC1.3.2 Game flags. Source is `src/Game/engine_menu_selection_window.cpp`, with a dedicated partial view in `include/Game/engine_menu_selection_window.h`. The compiler emits exactly this one function and no allocated data, weak backups, BSS, exception, startup or padding bytes.

The routine initializes the requested visible count from the menu's item count when zero, scans forward from the requested signed selection, and accepts an item according to its halfword flags at +0x8C. Flag 0x100 selects the special predicate `!(flags & 2)`; ordinary items require bit 0 and neither bit 1 nor bit 2. If no eligible item remains, the original requested index is retained. The result is copied to the previous-selection halfword.

Mode 2 adjusts the start and visible halfwords until the visible count stabilizes. It clips the trial end through the existing `fn_8021DA0C`, subtracts items bearing flag 2, clamps the window around the selected index and count, and preserves a neighboring item at either boundary when more than two items are visible. Mode 1 calls the existing logger with its original external message. Every mode finishes through virtual slot 0x4C with arguments 1 and 0.

The ordinary source structure matters: declaring the cached count before the signed-byte found flag preserves their original physical registers; an explicit empty mode-0 case reproduces the original switch tree. A post-increment item lookup places both induction updates before the flag test. The signed-short selected local and typed inline unsigned-short getter preserve the original narrowing instructions. These are source-level types and control flow, with no register directives or assembly.

`ownership_full.py` scans the full original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980` and destructors `80299980..802999A0`, including the descriptor, padding and trailing zeros. None refer to this retained range. Original context storage, strings, virtual tables and adjacent routines remain external and unclaimed.

The frozen handoff is `scratch/engine_menu_selection_window_20261011da/final_integration.json`. Its `verify.py` recompiles production source, compares every allocated byte with real relocation targets, checks the complete symbol inventory and all frozen source/header/evidence hashes, and repeats the complete original table audit. The entry identity is unchanged and no consumer migration is required. Central registration begins NonMatching; the root integrator must still pass the original DOL hash and regression checks before crediting the unit. All bounded source probes remain preserved.
