# Scene logging and reset wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-three ordinary C++ units match in strict isolated production recompiles.
Full original DOL acceptance remains the parent integrator's responsibility.
Each listed entry also owns exactly eight bytes of original exception metadata
and its 12-byte original index.

| Entry | Text bytes | Actual relocations |
| --- | ---: | ---: |
| `fn_800356BC` | 32 | 3 |
| `fn_80035E94` | 32 | 3 |
| `fn_80035EB4` | 88 | 8 |
| `fn_800362D0` | 32 | 3 |
| `fn_800362F0` | 88 | 8 |
| `fn_8003670C` | 32 | 3 |
| `fn_8003672C` | 88 | 8 |
| `fn_80036B48` | 32 | 3 |
| `fn_80036B68` | 88 | 8 |
| `fn_80038F9C` | 32 | 3 |
| `fn_80039380` | 32 | 3 |
| `fn_800393A0` | 88 | 8 |
| `fn_80039810` | 80 | 3 |
| `fn_80039860` | 88 | 8 |
| `fn_8003A160` | 32 | 3 |
| `fn_8003A180` | 88 | 8 |
| `fn_8003A59C` | 32 | 3 |
| `fn_8003A5BC` | 88 | 8 |
| `fn_8003A9D8` | 32 | 3 |
| `fn_8003A9F8` | 88 | 8 |
| `fn_8003AE14` | 32 | 3 |
| `fn_8003AE34` | 88 | 8 |
| `fn_8003B250` | 32 | 3 |

Total: 1,344 original text bytes, 460 original exception bytes and 119 actual
relocations. All units use the established GC 1.3.2 `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile. Every emitted allocated byte,
symbol, compiler category and actual resolved relocation is accounted. There
are no weak functions, extra data, pools, padding, native renames or new gates.

Ten 88-byte wrappers emit their original logging string through the logger at
global +110, then forward the unchanged owner and integer value to the existing
fn_8003543C. Twelve 32-byte wrappers forward to existing reset or lifecycle
operations. In particular 800356BC preserves the genuine const reference
Handle argument of accepted fn_80259FB4; its private four-byte view introduces
no constructor, destructor or native symbol. Other single-pointer forwards
preserve the observed existing signatures. All original C entry identities,
logging strings, external callees and compiled callers remain unchanged.

80039810 invokes existing fn_800356DC, clears the signed flag at owner +88 and
calls virtual slot +94 with two zero arguments. The private owner has its vptr
at +8 after an opaque nonpolymorphic base, matching all observed field offsets.
No additional owner layout or game semantics are asserted. Every ordinary
source matched its first isolated probe. The initial two generic declaration
forms were corrected before freezing using the accepted callee ABI; final
production objects preserve all original bytes and actual targets.

`ownership_audit.json` scans the full original extabindex
80015F60..8001F2C0, ctor table 80299920..80299980 and dtor table
80299980..802999A0. Each entry owns exactly its original exception record;
none is a startup or termination entry. All original initialized-data references
and unchanged source/header consumers are inventoried. All external logging
strings, callback tables, globals and other original translation-unit data stay
assembly-owned. Dependencies are actual undefined ELF symbols only.

The fresh namespace is `scratch/game_engine_scene_log_wrappers_continuation`.
`final_integration.json` pins source hashes, compiler flags, exact owned ranges,
symbols and real relocations; `allocated_inventory.json` records all emitted
allocations and defined symbols. `verify.py` recompiles exact production sources
and checks all code/metadata without relocation masking. No central metadata,
shared header, accepted source, old handoff or verifier core was modified.
Split/config files remain integration proposals.
