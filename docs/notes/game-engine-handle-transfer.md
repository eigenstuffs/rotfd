# Retained handle transfer

`src/Game/engine_handle_transfer.cpp` reconstructs the complete ordinary C++
entry `fn_80230A34`, `.text:80230A34..80230B78` (324 bytes). It resolves the
owner handle at offset `0x0C`, copies a supplied handle through a temporary
and retained local, dispatches `fn_8023297C` with the previous unsigned flag
at `0x5E`, then sets that flag to one.

The first retained copy is a full-expression temporary passed directly to
an inline generation resolver. A scoped named local produced the same code
except seven stack-slot operands. The temporary places the first copy at
`sp+0x0C`, the intermediate copy at `sp+8`, and the final local at `sp+0x10`,
matching the original. Distinct ordinary derived copy types preserve the
intermediate copy and its destruction before the dispatch call. The owner
copy has two zero-initializing base stages; the other two copies have one.
No assembly, fixed registers, aliases, or object patching are used.

GC/1.3.2 with the standard Game flags and `-use_lmw_stmw on` emits the exact
324 retained bytes after applying all 12 actual relocations. Five normal
trailing weak destructors occupy 440 additional emitted bytes and carry 10
relocations. They are fully inventoried by symbol, extent, binding, raw
SHA-256, and relocation; no retained instruction references them. The
compiler emits no allocated data, BSS, exception, constructor, or destructor
sections. The source split owns only the retained text entry, not a recovered
complete original translation unit.

`scratch/engine_handle_transfer_20261010bi/verify.py` recompiles the production
source, validates all allocated emissions and actual relocations, and checks
complete raw original tables: `extabindex:80015F60..8001F2C0`, including its
descriptor and trailing zeros; `ctors:80299920..80299980`; and
`dtors:80299980..802999A0`. None references this entry. Existing external
handle identities and context/dispatch symbols remain unchanged.

The frozen handoff is `final_integration.json` in that scratch directory,
with integration snippets, full ownership audit, probe variants, and file
hashes alongside it. Central registration, original-DOL hash acceptance,
and progress credit are the integrator's remaining steps.
