# Scene service setup and callback guard

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two new ordinary C++ units match in strict isolated production recompiles.
The parent integrator remains responsible for the complete original DOL link.

| Entry | Text | Exception table + index | Actual relocations |
| --- | ---: | ---: | ---: |
| `fn_800400BC` | 320 | 24 + 12 | 13 |
| `fn_80044494` | 144 | 8 + 12 | 4 |

Total: 464 original text bytes, 56 original exception bytes and 17 actual
relocations. GC 1.3.2 uses the established `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile. Every emitted allocated section,
symbol, raw byte and actual resolved relocation is accounted. Neither unit
emits weak functions, new data, padding or startup entries. Original entry
identities and external callers remain unchanged.

400BC clears flag bits 0/2/3 at the observed 64-bit field +38, sets bits 25/8,
runs the original owner base setup, and assigns a Handle returned by the global
manager's original name lookup. The real nontrivial Handle return preserves
its hidden result pointer and original Base Handle destructor lifetime. It then
calls service +154 virtual slot +34 with zero and the first scene target's
signed byte +2EC, followed by owner slots +5C/+60 with 0x85. The signed byte
passes through an explicit short conversion to the integer argument. This
ordinary promotion reproduces the original separate byte-load and sign-extend
registers; direct promotion left two instruction operands different. All such
near probes are preserved and receive no credit. The private owner view has a
vptr at +8 after an opaque nonpolymorphic base, and the service has a vptr at
+1C. Fields outside those directly observed offsets remain opaque.

44494 returns when flag bit 18 is set or the signed active byte +68 is nonzero.
Otherwise it sets that byte to one, calls owner virtual slot +28 with zero and
forwards event 0x8F with the original external float. The compound OR guard
reproduces the original branch structure. The earlier nested-guard source was
four bytes shorter and remains uncredited research.

Private 80042260 research is preserved in this scratch namespace, but is not
part of the manifest or any source credit. Its true native extent is 224 bytes,
with 44 bytes of exception actions and a 12-byte index. The ordinary copy
hierarchy and named member reference reproduce its three zeroing stores, real
Handle copy/retain, stack lifetime and saved registers. The best inline apply
form still differs in nine volatile register operands in the entry/scene
lookup. Its weak backups and metadata are diagnostic only; no weak override
claim or verifier authorization is proposed for that near match.

`ownership_audit.json` scans the complete original extabindex
80015F60..8001F2C0, constructor table 80299920..80299980, and destructor table
80299980..802999A0. Each accepted function owns exactly its original exception
record; neither has a constructor or destructor table reference. All original
initialized-data references and unchanged compiled source/header consumers are
inventoried. Other original translation-unit data, tables, constants and
functions retain assembly ownership. Dependencies are restricted to actual
undefined ELF symbols, excluding local exception labels.

The fresh namespace is `scratch/game_engine_scene_service_setup_continuation`.
`final_integration.json` pins source hashes, flags, complete owned sections,
symbols and actual relocations. `allocated_inventory.json` records every
allocation and defined symbol. `verify.py` recompiles the exact production
sources and checks all retained code and metadata without relocation masking.
No central metadata, shared header, accepted source, old handoff or verifier
core was modified. Split/config files are integration proposals only.
