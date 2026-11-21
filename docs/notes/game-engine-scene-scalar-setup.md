# Repeated scene resource scalar setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twelve ordinary C-entry scene setup routines reproduce their complete original
608-byte bodies and 24-byte exception tables plus 12-byte exception indices.
They remain separate partial translation units at their physical addresses.
The parent integrator is responsible for promotion and full original-DOL acceptance.

| Function | Text bytes | EH + index bytes |
| --- | ---: | ---: |
| `fn_80035C34` | 608 | 36 |
| `fn_80036070` | 608 | 36 |
| `fn_800364AC` | 608 | 36 |
| `fn_800368E8` | 608 | 36 |
| `fn_80036E98` | 608 | 36 |
| `fn_80038274` | 608 | 36 |
| `fn_80039120` | 608 | 36 |
| `fn_80039F00` | 608 | 36 |
| `fn_8003A33C` | 608 | 36 |
| `fn_8003A778` | 608 | 36 |
| `fn_8003ABB4` | 608 | 36 |
| `fn_8003AFF0` | 608 | 36 |

The frozen source prefix is `src/Game/engine_scene_scalar_setup_`. Complete
address ranges, compiler flags, original symbols and all actual relocations are
in `scratch/game_engine_scene_scalar_setup_continuation/final_integration.json`.
GC 1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` with the
established base flags. Each source matches on the first ordinary C++ probe.
Fresh production-source recompiles also match all retained allocations and symbols.

## Behavior and private views

Each entry calls the original `fn_8025BBA8`, obtains a nontrivial native
`Handle_801F7F10` return value from `fn_801B52EC`, and passes the temporary by
const reference to `fn_8025A3C8`. Its genuine external destructor is called on
normal and exceptional cleanup. Declaring the real constructor/destructor
preserves hidden-return-pointer ABI and exactly the original temporary lifetime;
there is no inline backup destructor or synthetic helper.

The owner has a virtual-table pointer at `+8` and the resource handle at `+0x70`.
It calls the observed virtual slots `+0x94` with two zero arguments, `+0x5C`
and `+0x60` with `0x85`. The resource is resolved independently for each original
operation through the unchanged context manager at `lbl_801E9D24+0x118`.
Entries have stride 16, object pointer at zero and signed generation byte at
`+0xC`; the handle has signed 8-bit generation and 24-bit index fields.

The resource view defines only the observed fields: floats at `+0x348`,
`+0x34C`, `+0x370`, `+0x3DC`, `+0x3E0`, `+0x3E4`, and integer `+0x3EC`.
Its other bytes are opaque. A genuine inline setter writes the same value to
`+0x370` followed by `+0x34C`, preserving the single resolution in that operation.
The remaining writes each resolve independently, including the original null
fallback followed by unchecked field access. Variants preserve their own original
external resource names, scalar constants and final integer value; no literal
pool or string data is emitted or moved.

## Complete ownership audit

`ownership_audit.json` verifies true original assembly function extents and scans
all exception indices `80015F60..8001F2C0` (stride 12), constructors
`80299920..80299980`, and destructors `80299980..802999A0` (stride 4).
Every entry owns exactly its listed exception/index pair and no startup or
termination pointer. The emitted exception-table header, PC action, stack-local
cleanup and actual destructor relocation all match original bytes.

Each function has two initialized-data references in the original executable:
one in its owned exception index and one in its external original callback/type
table. Those original tables remain in assembly, with current visibility and
entry identities unchanged. No existing source/header consumers of these entry
names were found. Dependencies include only actual undefined ELF symbols;
local exception records are never published as external dependencies.

`allocated_inventory.json` inventories every emitted allocated section, its raw
SHA256, alignment, all defined symbols and actual relocations. Only original
`.text`, `extab` and `extabindex` are emitted: 7,296 text bytes, 432 metadata bytes
and 192 actual relocations total. There are no extra code/data/BSS allocations,
weak helpers, masks or data-ownership adapters.

## Handoff

`final_splits.txt`, `final_config.txt` and `final_integration.json` are proposals
for the sole integrator; shared metadata, headers, configure files and prior
frozen research remain untouched. `verify.py` recompiles the frozen production
sources and checks every allocated byte, symbol extent and actual relocation.
`handoff.json` pins this note, all production sources and complete scratch evidence.
