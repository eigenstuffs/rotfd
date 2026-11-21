# Scene argument controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three adjacent ordinary C++ routines are exact in isolated production recompiles.
Promotion and the original full-DOL link remain parent integrator checks.

| Entry | Text bytes | Original exception table + index |
| --- | ---: | ---: |
| `fn_8003DCBC` | 92 | 8 + 12 |
| `fn_8003DD20` | 156 | 8 + 12 |
| `fn_8003DDBC` | 156 | 8 + 12 |

Total: 404 text bytes, 60 exception metadata bytes, 14 actual relocations.
GC 1.3.2 uses the established `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` profile. All allocated code and exception bytes, defined
symbols, and actual relocated targets match. There are no extra allocations,
weak helpers, data or literal pools, padding, renames, or verifier adapters.

DCBC releases the old Handle at owner +60, copies the incoming word, and
retains the incoming Handle through the original manager at global +118.
The external reference-count helper and all C entry identities remain intact.

DD20 and DDBC read the argument count +860 from the service at global +110.
They return zero below two arguments. Otherwise they reset the parser at
global +15C (mode zero or one respectively), invoke its virtual slots +14
with arguments +868 and +18 without arguments, then set enabled +1 to one,
mode +4 to zero, and return one. The private C++ Parser inherits its eight-byte
non-polymorphic Prefix at offset zero; this compiler places the derived vptr
at +8. The field accesses and both virtual table loads prove those offsets. Remaining
storage and virtual-slot semantics stay opaque. Inline reset/finish methods
capture the parser pointer across each paired write. The original direct
repeated-global expressions emit extra reloads and 164-byte bodies; those
uncredited probes are preserved under `-direct` names. The ordinary inline
methods reproduce both original 156-byte bodies and all branch operands.

Every original assembly function extent was checked. Complete exception-index
80015F60..8001F2C0, ctor 80299920..80299980, and dtor 80299980..802999A0 scans
show exactly one owned exception record per function and no startup or
termination references. Original external tables remain assembly-owned;
complete initialized-data references and source/header consumer hashes are
preserved in `ownership_audit.json`. Dependencies are only actual undefined
ELF symbols. Neighboring accepted functions and all shared metadata are
unchanged. This is a partial original translation-unit recovery.

The fresh namespace is `scratch/game_engine_scene_argument_controls_continuation`.
`final_integration.json` records source hashes, exact sections, symbols, real
relocations, and compiler flags; split/config files are proposals only.
`allocated_inventory.json` records every raw allocation and defined symbol.
`verify.py` performs strict fresh production recompiles. `handoff.json` pins
all sources, this note, and isolated evidence. No central metadata, shared
header, prior matching source, or frozen verifier core was changed.
