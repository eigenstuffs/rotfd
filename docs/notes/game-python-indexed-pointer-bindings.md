# Python indexed pointer bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary wrappers at `800CF1A0`, `800CF2E8`, `800CF430` and `800CFBC0`
parse an owner and an index, convert the owner pointer, read the Python integer,
and encode the address of the selected four-byte array element. The array
pointers are at owner offsets `B0`, `A4`, `98` and `D8`; returned Python type
entries are at `B8`, `A4`, `BC` and `C0`.

All 1,312 code bytes and 80 exception/index bytes match, including eighty actual
relocations. Each unit owns its complete original exception-index entry and no
additional allocation. The new encoding header retains the ordinary pointer
hexadecimal loop, Python None behavior and string-copy calls. A named pointer
local and moving the integer copy before the inner null check reproduce the
observed register allocation and instruction scheduling. No register assembly,
object edits, relocation masking or manual instruction replacement is used.

Private bounded variants and frozen source/header/manifest/object evidence are
under `scratch/game_python_indexed_pointer_bindings/`. The same unchanged
header serves the separately documented member-pointer bindings.
