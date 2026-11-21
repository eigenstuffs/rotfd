# Scene resource setup follow-up pair

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This independently frozen pair follows the twelve routines documented in
`game-engine-scene-scalar-setup.md`, without changing their sources or proofs.
Only new production sources under `src/Game/engine_scene_scalar_setup_more_`
are proposed. Promotion and the original full-DOL hash remain integrator checks.

| Function | Original text range | EH + index |
| --- | --- | ---: |
| `fn_80035390` | `80035390..8003543C` (172 bytes) | 24 + 12 bytes |
| `fn_80039584` | `80039584..80039810` (652 bytes) | 24 + 12 bytes |

Both functions match on their first ordinary C++ probes and fresh production
recompiles, with GC 1.3.2 and the established `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile. The objects emit only their original
`.text`, `extab` and `extabindex`: 824 code bytes, 72 metadata bytes and 27 actual
relocations. No weak helpers, literal pools, data, BSS, padding or adapters are
introduced. `allocated_inventory.json` records every allocated section and raw
hash, all defined symbols and all actual relocations.

`80035390` performs the same original reset, registry lookup, retained-handle
binding and virtual slot `+0x94`/`+0x5C`/`+0x60` calls as the scalar family,
without the resource-field writes. Its genuine nontrivial native Handle return
and external destructor reproduce the original hidden-return ABI, temporary
stack slot and exception cleanup.

`80039584` performs the six independently resolved scalar operations through
the same observed manager and resource layouts as that family. It additionally
writes zero to owner byte `+0x88`, then clears `0x20000` in its established
64-bit flags field at `+0x38`. Its private view exposes only those observed owner
fields and the resource handle at `+0x70`; all other bytes are opaque. The source
preserves original string, constant, function and destructor identities.

The full original exception-index table `80015F60..8001F2C0` was scanned with
stride 12. Each routine owns exactly its listed 24-byte exception table and
12-byte index. Full ctor `80299920..80299980` and dtor `80299980..802999A0` scans
found no startup or termination pointers. Original assembly function extents
were independently checked. Original callback/type-table references remain
unchanged in their assembly owners; no existing source/header consumers of
these two entry names were found. Dependencies are restricted to actual
undefined ELF symbols, excluding local exception metadata.

`scratch/game_engine_scene_scalar_setup_more_continuation/final_integration.json`
contains complete ranges, actual relocations, source/header hashes and flags.
`final_splits.txt` and `final_config.txt` are integration proposals only.
`ownership_audit.json` records all original references, and `verify.py` recompiles
and strictly checks the entire emitted allocation. `handoff.json` pins the
production sources, this note and the complete isolated evidence. No shared
metadata, headers, original accepted source or frozen verifier core was changed.
