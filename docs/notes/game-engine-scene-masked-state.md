# Masked scene event selection and forwarding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ units are strict isolated byte matches. Full original DOL
acceptance remains the parent integrator's responsibility.

| Entry | Text | Exception table + index | Actual relocations |
| --- | ---: | ---: | ---: |
| `fn_80041B7C` | 948 | 8 + 12 | 6 |
| `fn_80044380` | 52 | 8 + 12 | 2 |
| `fn_80044428` | 32 | 8 + 12 | 3 |

Total: 1,032 original code bytes, 60 original exception bytes and 11 actual
relocations. GC 1.3.2 uses the unchanged `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile. All emitted allocated bytes,
symbols, compiler categories and actual resolved relocations are accounted.
There are no weak helpers, extra data, padding, renames, migrations or gates.

41B7C queries the owner's original signed-byte event status for 0xBF and
resolves its Handle at +70. It switches on the full 64-bit word at the resolved
object's +438 masked by 0x07800000. Thirteen masked states and the default map
the status to the observed event enum, then call the original event operation
with arguments event, 0xF, zero, zero. The unsigned 64-bit switch exactly
reproduces the original equality/range comparison tree, including the high
word operations. The signed status remains in the original return register
through the pure Handle lookup.

The provisional enum names describe only numeric event IDs, not inferred game
semantics. Named enum constants preserve the original conditional selection
of the final 0x97/0x98 event pair. Integer literals caused a different arithmetic
selection at four instructions; that initial probe and bounded alternatives
remain preserved without credit. The private Entry view establishes object
+0 and signed generation +C within each 16-byte record, and the manager view
establishes entries +8. Unknown storage remains opaque.

44380 forwards to the owner's virtual slot +8C with two zero arguments. Its
private view preserves the observed vptr at +8 after an opaque base. 44428
forwards the same owner pointer to the existing external fn_80256370. Both
retain their original C entry identities and all accepted callers unchanged.
Each hook matched in its first ordinary source probe.

`ownership_audit.json` scans the complete original extabindex
80015F60..8001F2C0, ctor table 80299920..80299980 and dtor table
80299980..802999A0. Each accepted function owns exactly its original exception
record, with no startup or termination entry. All initialized-data references
and unchanged source/header consumers are inventoried. Original external
tables and remaining translation-unit data retain assembly ownership.
Dependencies are restricted to actual undefined ELF symbols.

The fresh namespace is `scratch/game_engine_scene_masked_state_continuation`.
`final_integration.json` records the exact owned ranges, symbols, source hashes,
flags and actual relocations. `allocated_inventory.json` records every emitted
allocation and defined symbol. `verify.py` recompiles the exact production
source and checks complete code/metadata without relocation masking. No central
metadata, shared header, accepted source or old frozen artifact was modified.
Split/config files are proposals only.
