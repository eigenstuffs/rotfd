# Record scene operation variants

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen isolated handoff is `scratch/game_engine_record_scene_variants_continuation/final_integration.json`. Central original native linking and weak backup discard proof remain mandatory.

Five ordinary C++ functions reproduce 2,164 retained text bytes and 280 complete exception/index bytes, with 128 actual retained relocations. Original C entries remain unchanged; there are no native renames, aliases, consumer migrations, or owned static data additions. Compiler is GC 1.3.2 with the established container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags.

| Original entry | Text bytes | Actual retained relocations | Observed operation |
| --- | ---: | ---: | --- |
| `fn_800EDCAC` | 548 | 28 | countdown; notify6; name B584 operation6; store queried word14; clear occupancy |
| `fn_800EE210` | 528 | 26 | countdown; notify6; name B5B0 operation6 |
| `fn_800EEB6C` | 528 | 26 | countdown; clear flag14; notify6; name B5C8 operation6 |
| `fn_800EBDE0` | 316 | 23 | clear flag10; query record; conditional name B4A0 operation1 or flag10 |
| `fn_800EC580` | 244 | 25 | log B4E8; refresh record; stop; restore Handle/key; conditional record reset |

The private context/record/scene/Handle views use the same established offsets and native identities as the accepted notification/scene-operation handoffs. EDCAC, EE210, and EEB6C perform the genuine full-expression copied-Handle service operation, initialize the float countdown, notify the nested related object, then create an interned Name temporary and inline Name copy for a scene operation. EDCAC additionally stores the returned status word at owner14 and clears record occupancy. EEB6C uses signed-byte flag14 instead; these private union fields describe separate original derived owners, not a complete shared class identity.

EBDE0 uses signed-byte query results from E8E54 and E8DE8, matching the observed native `extsb` call sites; the already accepted producers and names remain unchanged. It sets owner flag10 when no named operation can be selected. EC580 treats status1C as a signed integer, matching the original `cmpwi`; the initial unsigned view produced one `cmplwi` difference and is preserved in `initial_probes`. This storage correction changes no layout or external signature.

The inline nested Handle lookup retains the verified signed 8/24-bit union and distinct byte-backed second manager lookup. Every retained instruction, full exception record, and actual relocation matches the original. Each object emits one weak native `__dt__15Handle_80020478Fv` backup: 112 text bytes, 40-byte extab, 12-byte index, seven actual backup relocations. Total uncredited backup output is 560 text bytes and 260 metadata bytes with 35 relocations. The guarded opt-in audit independently recompiles the already accepted strong original owner at 80020478, verifying canonical/source/recursive-header hashes, exact production digest, complete allocations, and all actual relocation targets. The retained EH pointer in each unit resolves to that real original strong owner. All backup bindings, raw digests, full EH/index groups, and retained resolutions are frozen. Final native ELF/map acceptance must prove every input backup and its metadata discarded while the original strong definition remains at its original address. Backup bytes receive no credit.

The full original extabindex (`80015F60..8001F2C0`, stride12), constructor table (`80299920..80299980`, stride4), destructor table (`80299980..802999A0`, stride4), initialized data words, and exact native function extents were audited. Every unit owns exactly one 44-byte extab and 12-byte index; no constructor/destructor pointer references it. Original assembly-owned callable table objects, ranges, entries, and all unchanged compiled source consumers with hashes appear in `ownership_audit.json`. Surrounding functions, data, names, logger text, scalar globals, and tables stay outside this partial split.

ABC8 and B2F8 remain private four-register-operand nears, sharing the unresolved operation-before-notification allocation pattern documented in `game-engine-record-scene-operations.md`. BA6C remains private with stack/register differences. Its array-backed literal-pool base reproduces the observed original base address and offsets, but fifteen ordinary Name helper/full-expression/copy and service-scope alternatives did not close all temporary stack slots. `initial_probes`, `report.json`, and `name_variants/results.json` preserve those actual relocated diagnostics. These three have no production sources, ownership transfer, or matching credit in this handoff.

`verify.py` recompiles all five expanded production sources, checks frozen source/recursive-header digests, complete retained and backup inventories, raw hashes, original bytes, actual relocations, strict EH/index target types and addends, and independent strong-owner proof. All passed. Central symbols, splits, configure, shared headers, expected hash, original inputs, progress, full builds, and all prior frozen production/research artifacts were untouched.
