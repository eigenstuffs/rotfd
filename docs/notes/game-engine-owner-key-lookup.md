# Owner key lookup with three handle outputs

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Isolated exact handoff, awaiting central acceptance.** Ordinary C++ `fn_801FE6BC`, `801FE6BC..801FE99C`, matches all 736 original text bytes and 23 actual retained relocations with GC1.3.2 Game flags plus `-use_lmw_stmw on`. New source is `src/Game/engine_owner_key_lookup.cpp`, with dedicated partial declarations in `include/Game/engine_owner_key_lookup.h`.

The function first clears three output handles through native Handle construction, assignment and destruction. Five, three and two ordinary derived zero-initializing constructor layers preserve the observed stores; those depths were already established independently by the existing hierarchy-selection caller headers. The routine traverses an outer owner handle array and each resolved object's inner handle array. It checks the inner object's virtual key at table offset A0 and the enclosing object's related handle. On the first match, three decrement/copy/increment assignments return its first-array handle, second-array handle and related handle; the function returns 1. It returns 0 when no match is found.

Byte-backed outer and inner handle storage preserves the native indexed word/byte loads and four-byte induction offsets. The first and second output arrays use ordinary typed handle storage. A direct generation-check resolver preserves both original indexed search paths. The compiler retains the shared manager field address across the calls without source register directives. The first ordinary source probe matched every retained instruction.

The compiler emits 460 trailing unused weak destructor bytes in five fully inventoried functions, with ten actual relocations. None has a retained reference, and all remain unlinked under the normal discard policy. No initialized data, BSS, exception, startup or padding allocation is claimed. The complete original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980` and destructors `80299980..802999A0` are audited, including descriptors, padding and trailing zeros; none refers to this retained range. Original external state, native Handle lifecycle, manager operations, virtual tables and adjacent routines retain their owners.

The entry identity remains `fn_801FE6BC`. Its observed return is int0/1; two earlier private caller headers declare void and all four compiled callers ignore the return. `consumer_inventory.json` inventories the exact untouched two headers and four caller files for root's declaration-only correction, with preserved originals and unchanged allocated-byte recompilation if performed. No existing consumer is edited by this handoff.

The complete manifest is `scratch/engine_owner_key_lookup_20261011de/final_integration.json`. `verify.py` recompiles production source, verifies every allocated section and symbol, compares all retained bytes with actual relocation targets, inventories unused weak code, repeats the full original-table audit and verifies frozen source/header/evidence hashes. Root registration begins NonMatching; original DOL hash, regression checks and the normal unused weak discard audit remain required before credit.

Root integration preserves the existing four caller sources and both private
caller headers byte for byte. Those earlier partial views declare this entry
with a void result; all four callers ignore the returned register. The new
bounded definition retains the recovered integer 0/1 result. The declaration
inventory and proposed correction remain in the frozen handoff for later
shared-header reconstruction. No caller source or progress credit changes in
this integration.
