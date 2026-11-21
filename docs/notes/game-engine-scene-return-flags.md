# Nested Handle return flag operations

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ controls are strict isolated byte matches, including all
original exception metadata and actual relocations. Full original DOL
acceptance remains the parent integrator's responsibility.

| Entry | Text | Exception table + index | Retained relocations |
| --- | ---: | ---: | ---: |
| `fn_80041F30` | 408 | 8 + 12 | 12 |
| `fn_800420C8` | 408 | 8 + 12 | 12 |

Total: 816 original code bytes, 40 original exception bytes and 24 actual
retained relocations. The GC 1.3.2 profile remains `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on`. All original external entry names remain
unchanged; there are no native identity migrations, new pools or padding.

Both routines resolve the owner's Handle at +64 and then the resolved node's
Handle at +1F0. They perform two original named lookups and set bit 25 in each
returned object's word at +120. 41F30 uses external keys 80378544 and 8037854C;
420C8 uses 80378550 and 8037854C. Those original constant objects remain
external with their confirmed sizes 5/4/7. The key constructor preserves the
original function's return word assignment.

The private first resolver views only the manager's entries field as a raw
byte pointer, then computes the observed signed index times 16 and converts
that entry to the established record view. The second resolver uses the typed
Entry pointer field. This distinct ordinary view preserves the original
second load of the entries pointer while retaining the manager pointer. The
initial single typed view eliminated that load and produced a 404-byte near
match; it is preserved and receives no credit. The Entry view establishes the
object at +0 and signed generation byte at +C, with opaque words at +4/+8.
All unobserved node and manager fields remain opaque.

The name lookup returns a genuine nontrivial four-byte Handle value. A private
returned Handle type derives from the original Base Handle and has an empty
inline destructor. Its hidden return pointer and end-of-full-expression base
destruction with flag zero match the observed ABI. No original native identity
is claimed for the private derived return type. Each unit emits one unique
unused weak destructor of 76 bytes plus 8 bytes of exception metadata and a
12-byte index, with four actual backup relocations. Across both units these
152 code bytes and 40 metadata bytes are uncredited.

The unchanged strict weak inventory core verifies every retained byte and
resolved relocation, every weak backup's binding/type/offset/size/raw hash,
all compiler category records and all exception groups. The manifest has an
empty strong-owner authorization set: no retained code or metadata reference
points to either backup. Actual native MWLD links prove all three backup
allocations per object are discarded and the retained original bytes/targets
survive. Wrong fixture basenames reject in both proofs. The parent must repeat
this audit in the full original-placement link. No verifier core or new gate
is needed.

`ownership_audit.json` checks the complete original extabindex
80015F60..8001F2C0, ctor table 80299920..80299980 and dtor table
80299980..802999A0. Each function owns exactly its original exception record,
and neither has startup/termination references. All original initialized-data
references and unchanged source/header consumers are inventoried. Other
original translation-unit data, constants and functions remain assembly-owned.
Dependency symbols are actual undefined ELF symbols only.

The fresh namespace is `scratch/game_engine_scene_return_flags_continuation`.
`final_integration.json` records exact sections, symbols, source hashes, raw
object hashes and actual relocations. `complete_allocated_inventory.json`
accounts for every emitted allocation. `verify.py` performs strict fresh
production recompiles; `native.py` preserves real linker/discard proofs.
No central metadata, shared header, accepted source or old frozen artifact was
modified. Split/config files are proposals only.
