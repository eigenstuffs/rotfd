# Scene record event and aggregate owner adoption

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This handoff reconstructs `fn_800E1B94` in `src/Game/scene_record_event_800E1B94.cpp`. Its 284 original code bytes, 24-byte exception record, and 12-byte exception index match with all actual relocations applied. Acceptance remains conditional on root's separately verified native constructor migration and complete original DOL build. The private diagnostic linker proof is not a full-target match.

The source uses an ordinary scoped `Record_800218F8` object. It sets the record's float at +8, resolves the target's signed-generation handle, clears the observed actor flag mask, applies the record and scalar operation, and sends event `(0x7B, 0x15, 0, 0)` through the owner's event object. Private views establish only the observed offsets: owner's events +0xC and target +0xA4, target handle +0x80, actor flags +0x30, and 16-byte manager entries. `Record_800218F8` has the established size 0x94: an opaque prefix through +0x8C and two four-byte nested Handle members. Unknown storage is retained explicitly.

The owned ranges are:

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | `800E1B94..800E1CB0` | 284 |
| `extab` | `80014734..8001474C` | 24 |
| `extabindex` | `8001E6E4..8001E6F0` | 12 |

GC 1.3.2 with the established Gekko space flags, exceptions enabled, and `lmw/stmw` enabled emits exactly these retained allocations. It also emits a weak `__dt__15Record_800218F8Fv` backup of 176 code bytes, 40 exception bytes, and a 12-byte index. Those 228 backup bytes receive no credit. The object has 13 retained actual relocations and eight backup relocations; every emitted allocation, local symbol, binding, extent, raw hash, exception pair, and category relocation is inventoried.

The retained exception record points to the weak destructor symbol. Its accepted original strong owner is `src/Game/nested_lifetime_destructor_800218F8.cpp`, selected uniquely from the four-entry legacy aggregate `config/GSQE78/candidates/game-nested-lifetime-destructors.json`. That owner recompiles to the identical production object, is a GLOBAL/FUNC at original `800218F8` with size 176, and matches all original code, exception bytes, and eight actual relocations. No accepted source, header, or canonical is changed.

The private source-bound outer gate is `scratch/game_scene_event_aggregate_owner_adoption_continuation/aggregate_owner_gate.py`. It pins this exact source, manifest, compiler evidence and original strong owner. It accepts only the exact legacy aggregate/source/native-symbol tuple and retains all unchanged object/EH/native verifier checks. The parent may add only inert `integration` and `_canonical` bookkeeping. The gate's persistent evidence excludes this documentation file, allowing an acceptance note refresh after root verifies its initial handoff hash.

A genuine native constructor `__ct__15Record_800218F8Fv` at `800219A8`, size 428, is a root-owned dependency. The existing original identity is `fn_800219A8`. Before migration, the isolated verifier adds that single native spelling to a copied original-address lookup; it does not edit source linkage, ELF symbols, the original executable, or shared metadata. Root must prove the real constructor body, ownership and compiled consumer migration independently. The full native gate requires an actual GLOBAL/FUNC constructor of size 428 at the original address and requires the old C identity to be absent; an absolute diagnostic linker symbol fails.

The MWLD diagnostic links the actual event object and accepted production strong destructor. The unchanged native checker proves all three backup allocations are discarded, the exact strong input is selected, and every retained metadata pointer resolves correctly. A wrong fixture basename is rejected. This private link intentionally uses a diagnostic original-address constructor symbol and is rejected by the full-target constructor identity guard. It does not establish original placement or replace root's original DOL hash check.

The complete original exception index and constructor/destructor startup tables were audited. The only exception index owned by this event is the 12-byte record above; it owns no startup pointer. Original initialized data contains two references into its extent: the owned exception index and the unchanged `lbl_802C8630` table entry at `802C863C`. That 28-byte table remains externally owned. Its existing constructor/destructor consumers and the external small-data constants at `80379784` and `80379790` retain their owners. The original C event identity is preserved.

Replay scripts accept a new output path, so repeat verification does not overwrite frozen evidence:

- `verify.py <new-directory>` recompiles the production source and runs the bounded outer gate, including a fresh independent strong owner compile.
- `native.py <new-directory>` repeats the diagnostic actual linker/discard proof.
- `test_guards.py <new-report.json>` repeats the source, ownership, raw ELF, relocation, constructor identity and native-input rejection checks.
- `audit_tables.py <new-report.json>` repeats the original initialized-pointer audit.

Root integration must pin both the gate and adoption JSON, route this exact source to the outer verifier, use the exact aggregate selector for independent strong-owner checks, route the native-only copied proposal to the unchanged native checker, and run the real constructor/full-target identity check. Original DOL SHA, baseline regressions, source extents, progress and tests remain mandatory. The root fixture folder and all earlier gates and handoffs remain unchanged.
