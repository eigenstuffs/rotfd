# Callback registration controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ functions match isolated production compiler objects:
`fn_80048BAC` is 168 bytes and `fn_8004B1EC` is 236 bytes. All 404 code
bytes, sixteen exception-header bytes, twenty-four exception-index bytes,
and eleven actual relocations match. Each object emits only those retained
sections; no weak functions, data tables, globals, or additional allocations
are present. Full native target acceptance remains the integrator's check.

Both query original controls `8A` then `8B`, invoking observed virtual slots
through the table at object offset eight. `80048BAC` calls slots `7C` and
`84`, then `fn_800487C4` only for the first successful control. `8004B1EC`
calls slots `84` and `7C`; for control `8A` it also copies the three floats
at object offset `7C` and four floats at `94` into original settings fields
`2D0` and `2DC`. Settings are reached through context offset `124`, then
pointer offset `15058`. Scalar field assignments reproduce the observed
copy, while a bounded loop probe emits a different loop and remains private.
Private declarations establish these observed offsets and dispatch slots,
without proposing a complete shared object layout.

Original C entry names, global context, accepted helper identity, external
constant data, and all original table references remain unchanged. The
ownership audit scans the complete original exception-index table
`80015F60..8001F2C0`, constructor pointers `80299920..80299980`, and
destructor pointers `80299980..802999A0`. Each function owns its one original
exception record and no constructor/destructor pointer. Original initialized
data references and current compiled consumers are inventoried. No symbol
rename, alias, identifier migration, pool partition, force-active directive,
or shared-header change is requested. Neighboring original code and data
remain outside these partial units.

`scratch/game_engine_callback_registration_controls_continuation/handoff.json`
freezes the source/header hashes, raw compiler objects, every allocated
section and ELF symbol, actual relocations, original ownership audit,
split/config proposals, and strict verifier. `verify.py` recompiles both
production sources and checks all allocations and actual relocation targets.
The larger registration startup family is separate private research under
`scratch/game_engine_callback_registration_continuation`; it receives no
matching credit from this handoff. Earlier frozen handoffs and central
metadata remain unchanged.
