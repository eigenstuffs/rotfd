# Scene registry and record controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ controls match in isolated production recompiles. Full original
DOL acceptance remains the parent integrator's check.

| Entry | Text bytes | Exception table + index |
| --- | ---: | ---: |
| `fn_8003F9A4` | 176 | 8 + 12 |
| `fn_8003FBC8` | 276 | 8 + 12 |

Total: 452 original text bytes, 40 original exception bytes, 23 actual
relocations. GC 1.3.2 uses the established `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` profile. All emitted allocations, symbols,
raw bytes and actual resolved relocation targets are accounted. There are no
weak helpers, new data pools, padding, native renames, migrations or adapters.

F9A4 requires one argument, captures the registry count, looks up the original
six-byte type-name constant and reports using the existing original string.
It scans 16-byte registry entries, tests the signed type at +8, and sets bit 2
in the matching object's byte at +C. The observed registry fields are count +0
and entries +8. The source initially declared the type-name as an unsized
non-const array, producing an extra address instruction; declaring the original
six-byte const object restores exact SDA21 addressing. That initial source is
preserved and receives no credit. All constant/string ownership stays external.

FBC8 captures the scene targets at +15058/+1505C. It reads a record at the second
target's +D4 using the original 0x3B5C size, then applies its first two words to
the captured first target. On fallback it optionally reads two floats and calls
the render service's original virtual slots +30/+38, then queries and applies
selection 0x1E. The private renderer view preserves the established +7C derived
vptr after a nonpolymorphic opaque base. The record view contains only its first
two established words and an opaque tail to the observed read extent; it does
not assert additional field identities. The first ordinary source probe was
exact, including repeated stream-mode queries and signed-byte read status.

`ownership_audit.json` checks complete original extabindex 80015F60..8001F2C0,
ctors 80299920..80299980 and dtors 80299980..802999A0. Exactly one original
exception record belongs to each function and neither function has startup or
termination references. Original initialized-data references and unchanged
source/header caller identities are inventoried. All external callback tables,
constants and other original translation-unit data remain assembly-owned.
Dependencies are restricted to actual undefined ELF symbols.

The fresh namespace is `scratch/game_engine_scene_registry_controls_continuation`.
`final_integration.json` pins source hashes, flags, complete sections and symbols,
and actual relocations; split/config fragments are proposals only.
`allocated_inventory.json` records every emitted allocation and defined symbol.
`verify.py` performs strict fresh recompiles. No shared header, central metadata,
old matching source or frozen verifier core was modified.
