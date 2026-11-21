# Native empty methods and the original curve table

Two separately bounded ordinary C++ source units reconstruct eight code bytes:
`CurveRecordBase_802E9E08::reset()` at `801B3A24` and the default
`Vector3_801D5330` constructor at `801D5330`. Existing native symbols remain
unchanged. The reset hook changes no observed state; the constructor leaves
its three float components untouched. Neither routine owns exception or
startup metadata, and neither is an adjustor thunk or native assembly helper.

Both sources use unchanged established class headers. The curve record's
prefix is eight bytes and its virtual table pointer is at offset eight;
accepted 60-/76-byte derived records already establish this relationship.
The vector has three floats and size twelve, also established by accepted
native array construction with stride twelve and by resource members.
No aliases, instruction forcing, new layouts or manual hidden return ABI
are used.

The out-of-line virtual reset is a key function. It naturally emits the
**GLOBAL**, complete twelve-byte `__vt__24CurveRecordBase_802E9E08` table:
two zero words and a real pointer relocation to the reset method. This is
ordinary owned source data, rather than an unused weak backup. The table
matches `802E9E08..802E9E14` completely with natural alignment eight.
Only this complete original table should move out of the original
`auto_07_802E9D98_data` range. The preceding `lbl_802E9DE8`, following
`lbl_802E9E14`, and all other original data remain external. No padding,
extra table, RTTI or helper is emitted. The vector object emits only four
text bytes.

Fresh preflight scans 46,693 source/header files and all canonical function
owners, including native scoped definitions. Neither function had an
implementation or accepted owner. The original complete exception-index,
constructor and destructor tables contain no entries for either function.
The current consumer census checks 10,379 distinct original/active ELF
inputs, 203,836 actual allocated relocations and all 501,416 bytewise
initialized-data pointer positions. It finds exactly one current GLOBAL
curve-table definition, in the original assembly input, and no accepted
source table owner. Existing references and all five original inherited
reset pointers are inventoried with input hashes; all three identities
have current consumers.

Two strict complete production compiles match every allocated byte,
binding, symbol extent and actual relocation. The total is eight text
bytes, twelve data bytes and one allocated pointer relocation; the two
compiler category relocations are nonallocated metadata. Nine negative
object mutations reject changes to instructions, table contents, pointer
target/addend, bindings, types, extents, alignment and extra allocation.
An actual isolated MWLD link selects both native functions and the source
GLOBAL table, resolving the table pointer to the selected reset body.

Evidence is frozen in `scratch/sdk_native_empty_methods_20261011`.
The unchanged strict core handles both objects directly; no new adapter,
weak gate, symbol migration or ownership exception is required. Final dual
full-game original placement, original DOL hash and no-regression acceptance
remain root-owned integration steps. No source credit is asserted before
those checks.
