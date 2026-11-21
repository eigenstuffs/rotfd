# Child-volume aggregation and optional spatial query

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Status: frozen isolated exact source; central original-DOL acceptance and progress credit remain with the integrator.

`src/Game/engine_volume_children_query.cpp` reconstructs the complete548-byte global C-entry `fn_802457B8` at `802457B8..802459DC`. The supplied object flags and the owner flags determine whether its cached sphere is initially available. The routine visits each generation-checked child handle, calls the virtual predicate at slot38, and obtains the accepted child sphere through slot3C. It copies the first sphere or merges later spheres using the native aggregate return from `fn_801F0A20`, then marks the result available. With no final query object it returns that signed-byte availability flag; otherwise it calls `fn_8026C094` with the aggregate sphere and the query-context fields when available.

The reconstruction uses ordinary virtual calls, a byte-backed handle accessor, signed24-bit index and generation fields, and a four-float assignment operator. The aggregate sphere return and right-to-left expression evaluation reproduce the original return temporary, subsequent virtual destination lookup and per-float copy. The partial virtual interface declares only enough slots for this caller; it does not claim the original complete class translation unit or any vtable ownership.

GC1.3.2 standard optimization settings plus `-use_lmw_stmw on` reproduce all548 text bytes and all4 real relocations. This object emits exactly one global text function and no unused weak functions, initialized data, BSS, padding, exception or startup-table allocations. The strict verifier checks every allocated section, exact symbol extent and resolved REL24/HA/LO operand against the original DOL; no relocation masking is used.

The full raw original extabindex `80015F60..8001F2C0`, ctor table `80299920..80299980` and dtor table `80299980..802999A0`, including descriptor and trailing zero bytes, have no references to this retained range. Existing source, headers, symbols, splits and configuration remain untouched. The original C-entry identity is retained, so no compiled consumer migration or alias is required.

The complete strict handoff is `scratch/engine_volume_children_query_20261010cl/final_integration.json`; its `verify.py` recompiles the production source and validates actual relocations, all allocations, complete original tables and frozen hashes. The first ordinary source probe was already exact. All probe evidence is preserved in the new namespace.
