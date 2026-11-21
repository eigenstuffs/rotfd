# Late record setup and handle assignment

This handoff contains **13 partial source fragments, 13 complete original
functions, and 1,608 text bytes** in `8020CF70..8024E62C`. All selected functions
are ordinary C. The existing versioned function names and external original
table targets are retained. These fragments are accepted matching source after strict production
verification and the full native DOL hash and regression checks.

The accepted canonical manifest is
`config/GSQE78/candidates/game-record-setup-late.json`. The frozen handoff is
`scratch/game_record_setup_late_continuation/final_integration.json`.
`final_splits.txt`, `final_config.txt`, and `ownership_audit.json` accompany it.
The config handoff deliberately starts every object as `NonMatching`.

| Original function | Complete text extent | Bytes |
| --- | --- | ---: |
| `fn_8020CF70` | `0x8020CF70..0x8020CFDC` | 108 |
| `fn_8021121C` | `0x8021121C..0x802112FC` | 224 |
| `fn_8021EBA4` | `0x8021EBA4..0x8021EC10` | 108 |
| `fn_80231D20` | `0x80231D20..0x80231D8C` | 108 |
| `fn_80243D84` | `0x80243D84..0x80243DE4` | 96 |
| `fn_80243F28` | `0x80243F28..0x80243FA8` | 128 |
| `fn_802441F0` | `0x802441F0..0x8024424C` | 92 |
| `fn_80247458` | `0x80247458..0x802474F8` | 160 |
| `fn_80248864` | `0x80248864..0x8024890C` | 168 |
| `fn_80249B50` | `0x80249B50..0x80249BA8` | 88 |
| `fn_80249CDC` | `0x80249CDC..0x80249D58` | 124 |
| `fn_8024D47C` | `0x8024D47C..0x8024D4E8` | 108 |
| `__ct__19SplineZone_8024E5CCFv` | `0x8024E5CC..0x8024E62C` | 96 |

## Recovered behavior

Four functions assign reference-counted handles. Each releases the old handle
through `fn_801F86C8`, copies the supplied four-byte value, and acquires the new
handle. `fn_8021121C` performs four ordered assignments; the other three perform
one. The manager field is reread after each external call, while the original
global base address remains cached.

The other nine functions call their original base initializer, install observed
external table pointers, initialize scalar fields, and return the object.
`fn_80243F28` retains both successive table writes, copies three components from
the original mutable `game_vec4_zero`, and initializes its scalar tail. The
SplineZone entry retains its existing mangled name as an ordinary C entry point.
These fragments do not reconstruct complete class definitions or virtual tables.

Private observed layouts matter for handle assignments: declaring the object
fields allows the compiler to retain the object pointer and use native field
displacements. Raw character-pointer expressions instead cached a derived
subobject pointer. Likewise, the vector globals must retain their mutable
declarations; declaring them `const` permits alias-sensitive read hoisting and
changes the native instruction order.

## Verification and integration

`python3 scratch/game_record_setup_late_continuation/verify.py` recompiles all 13
production sources with GC/1.3.2 and checks every emitted allocated section,
function binding, offset, extent, and all **59 real relocations**. It resolves
SDA21, ADDR16_LO, ADDR16_HA, and REL24 targets to their versioned addresses and
compares all resulting bytes with the normalized original DOL. No relocation
bits are masked. `finalize.py` separately checks each complete original
`.fn` / `.endfn` extent and freezes the original ownership audit.

The standard GC/1.3.2 flags are recorded in each manifest entry.
`fn_8021121C` additionally needs `-use_lmw_stmw on -opt space`; the other twelve
functions need no extra flags. All newly emitted functions have global binding.
Set the corresponding twelve provisional `fn_...` symbol scopes to `global`;
the named SplineZone constructor is already global. No symbol renaming or shared
header change is needed. Carve only the thirteen listed `.text` intervals out of
their existing fallback owners. Then perform the normal NonMatching validation,
promotion, full DOL hash check, and regression check.

## Original data ownership and excluded probes

The sources emit and claim **zero data bytes**, no exception records, and no
`.ctors` entries. All current original fallback owners listed in
`ownership_audit.json` contain text only; any original tables, exception data,
startup references, and neighboring functions retain their existing owners.
The original external vtable/function-table contents and mutable vector globals
are referenced rather than redefined. Every source fragment is therefore only
a partial reconstruction of its original translation unit.

Private probes for `fn_8024405C` and `fn_8024E18C` retain five and two native
instruction differences respectively, chiefly scheduling and the final saved
register/load order. Menu constructors and raw-pointer handle probes are also
preserved in scratch. None is included in the canonical handoff or counted as
matching source.

## Accepted integration

Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
