# Python scalar argument bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty-five ordinary C++ Python argument wrappers match all 5,148 original
text bytes, 700 exception metadata/index bytes and 350 actual relocations in
isolated production objects. Full executable acceptance is pending.

Each wrapper parses one existing Python-object argument and one scalar,
converts the native self pointer with the original type entry and error flag,
calls the original scalar method, and constructs a Python integer. The scalar
parameter types reproduce unsigned byte, signed/unsigned halfword, and float
loads. Native signed-byte return declarations preserve sign extension.
Both parsing and conversion failures return null exactly as before.

All integer forms matched the first private probe. The six float forms
initially swapped the parsed-object and scalar stack slots; declaring the
float before the parsed object corrects this without changing executable
logic. The initial evidence is preserved in
`scratch/game_python_scalar_inputs/initial-probe-results.json`.

The final manifest freezes the production sources and both shared headers.
All allocated sections, symbol extents, actual relocations, original exception
index rows and both startup tables are checked. There are no additional
allocated bytes, discarded helpers, local strings, BSS or padding. Existing
entry names and original external format/type-table data are preserved.
