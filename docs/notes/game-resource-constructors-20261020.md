# Light, Fog and resource constructors

Three source constructors add 416 matched text bytes, with 17 actual
relocations. They use existing global data providers and emit no owned data,
exception tables, unlinked helpers or padding.

| Source | Native text range | Bytes | Actual relocations |
| --- | --- | ---: | ---: |
| `src/Game/light_constructor_8024405C.cpp` | `8024405C..80244128` | 204 | 9 |
| `src/Game/fog_constructor_801F0920.cpp` | `801F0920..801F0980` | 96 | 4 |
| `src/Game/record_constructor_8024E18C.cpp` | `8024E18C..8024E200` | 116 | 4 |

All use GC/1.3.2 with the recorded native compiler settings. Naming the
unsigned-short flags value before its bitwise update recovers the native
epilogue scheduling. The observed type, table, flag and scalar/vector member
writes are ordinary C++; all unresolved fields retain offset-based names.

Light is emitted as a true C++ constructor. Its identity changes from
`fn_8024405C` to `__ct__14Light_8024405CFv` at the same address. The complete
active-input audit found exactly two call relocations: the Light factory and
the spatial-handle constructor. Both are migrated with unchanged resolved
code. Every allocated byte, symbol extent and relocation in all seven
affected production objects is preserved, except those two callee names.
Shared-header hashes are refreshed in the six affected canonical records.
The spatial constructor's pre-existing unlinked weak tails remain unchanged.
Fog and the resource constructor preserve their existing function identities.

These are complete function splits, not claims to complete original
translation units. Their tables, scalars and base constructor remain owned
by their existing source or original units. The manifests record each
provider and original exception/startup scans.

The standard full build passes the original DOL SHA-1, `ninja changes` is
empty, source extents pass for 5,769 units / 6,739 data/BSS sections, and all
66 tooling tests pass. Matched code is 1,922,268 / 2,607,776 bytes (73.7129%),
with 7,975 / 8,803 functions. Data remains 971,539 / 1,030,936 (94.2385%).

Canonical manifests are under `config/GSQE78/candidates/game_*_constructor_*.json`.
Private evidence is preserved in the corresponding `scratch/light_constructor_8024405C_20261020/`,
`scratch/fog_constructor_801F0920_20261020/`, and
`scratch/record_constructor_8024E18C_20261020/` directories.
