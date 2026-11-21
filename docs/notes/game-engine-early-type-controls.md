# Early type and virtual controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ units match 484 original text bytes and 92 original exception/index bytes in fresh strict production-source recompiles. Full original DOL acceptance belongs to the parent integrator. Every emitted allocated byte, defined symbol, compiler category and actual resolved relocation is accounted; there are no weak backups, extra data, padding, native renames or new gates.

fn_8002A0CC (148 bytes) clears flag bit0, sets flag bit35, binds the existing type named at lbl_80299E58 through the genuine nontrivial BaseHandle return of fn_801B52EC, then calls the existing final setup. fn_8002AE88 (176 bytes) clears bits0 and7, sets bit36, binds the original lbl_80299F58 type and calls the same setup. Ordinary full-expression Handle return lifetimes emit original direct destructor(-1) calls, 24-byte exception records and 12-byte indices. No Handle aliases or alternate ABI wrappers are used.

fn_8002B780 (160 bytes) clears flag bit3, calls fn_802597A4, invokes observed virtual slots5C and60 with0x85, slotAC with0,0, and stores1 to integer state84. Its original8-byte exception record and12-byte index also match. The private polymorphic owner view has an opaque8-byte prefix, vptr+8, 64-bit flags+38 and state+84, with opaque unobserved storage. No complete class layout beyond these observed accesses is asserted.

All three matched on their first isolated probes with GC1.3.2 -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on. Existing C entry names and all accepted source/header callers remain unchanged. The ownership audit scans full original extabindex80015F60..8001F2C0, constructors80299920..80299980 and destructors80299980..802999A0; none of these entries is a startup or termination initializer. Original initialized-data references and compiled callers are inventoried. All type strings, globals, callable tables and original data stay outside these partial text/EH units.

final_integration.json records exact original owned ranges, source hashes and actual undefined-symbol dependencies. allocated_inventory.json contains all emitted allocations, raw section hashes, defined symbols, compiler categories and relocation records. verify.py recompiles exact production sources and verifies code plus metadata without masking. Handoff source and recursive quoted-header hashes are frozen (the new sources have no quoted headers). Central metadata, shared declarations, accepted functions, old freezes and verifier cores were not modified; split/config files are proposals only.
