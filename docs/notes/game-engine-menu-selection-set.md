# Menu selected-index and visible-window update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Isolated exact handoff, awaiting central acceptance.** Ordinary C++ `fn_8021CDAC`, `8021CDAC..8021CFBC`, matches all 528 original text bytes and six actual relocations with standard GC1.3.2 Game flags. New source is `src/Game/engine_menu_selection_set.cpp`, with dedicated partial declarations in `include/Game/engine_menu_selection_set.h`.

The function rejects an out-of-range index or an item without flag1. It sets the selected index, then stabilizes the visible window in mode2: a one-item window follows the selection directly; larger windows repeatedly remove flag2 entries from the requested count, clamp the range and maintain an interior selection margin. Mode1 logs the existing diagnostic, while mode0 performs no window adjustment. A successful selection invokes virtual refresh at slot4C with arguments1,1 and returns1; a rejected index returns0.

This revisits the released private AW probe without changing any earlier evidence. The accepted DA selection-window routine established the required expression shapes: an ordinary unsigned-short getter at both the count test and final boundary expression preserves the redundant narrowing instruction; a named signed-short selected local preserves the explicit sign extension. Combined with an explicit empty mode0 case, integer previous-visible count and postincrement item-array access, these produce all original allocations and instructions. The first new probe is exact.

Only 528 text bytes are emitted. There are no weak backups, initialized data, BSS, exceptions, startup functions or padding. The complete original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980` and destructors `80299980..802999A0` are audited, including descriptors, padding and trailing zeros; none refers to the retained range. The existing diagnostic literal, logger state, clamp helper, virtual tables, adjacent functions and all other data retain their original owners. No identity or consumer migration is required.

The complete manifest is `scratch/engine_menu_selection_set_20261011df/final_integration.json`. `verify.py` recompiles production source, verifies every allocated section and symbol, compares all retained bytes with actual relocation targets, repeats the full original-table audit and verifies frozen source/header/evidence hashes. Root registration begins NonMatching; original DOL hash and regression acceptance remain required before crediting this unit.
