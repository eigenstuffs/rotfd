# Record and Handle stream reader at 801D2538

The isolated ordinary C++ reconstruction covers `fn_801D2538` through
`801D3088`: 2,896 original text bytes, 130 retained actual relocations, and no
owned data, exception tables, or startup slots. Full-game acceptance remains
the integrator's responsibility.

The reader initializes two arrays of two-layer Handle values, reads and binds
resource Handle fields, reads three arrays of 24-byte records, initializes a
three-layer Handle array, and reads nested word arrays. Native
`Handle_801F7F10` construction and destruction remain external. The temporary
returned Handle, copied Handle, assignment, and cleanup sequence are ordinary
C++ lifetimes; the observed stack slots and cleanup arguments match.

`Read2538Array::operator[](int)` returning a reference closes 48 saved-register
operand differences. Its signed `long` resize parameter closes the remaining
38 operands. On this compiler both `int` and `long` are four-byte signed types;
the source asserts that ABI. Serialized counts and indices remain `int`.
An independently saved variant with consistent long container counts and
resize locals emits the same complete object. The original member range is
serialized using its two unsigned addresses plus the final member's 12 bytes.

The original C entry name stays unchanged. The complete original-plus-active
scan covers 10,490 ELF inputs, 204,111 allocated relocations, and 501,416
initialized DOL byte positions. Its three entry relocations and one initialized
entry pointer all name the exact function start with zero addends; no interior
entry references were found. The existing context and allocator GLOBAL labels
and five-byte SDA string `lbl_8037A470` remain borrowed. In particular, the
context and allocator are original `.text` labels, not newly owned BSS.

The compiler additionally emits three unique, unreferenced weak destructors:
88, 88, and 84 bytes, with six actual relocations. The unchanged strict plain
weak-function schema inventories all 260 bytes. A real private MWLD link
retains the primary, verifies all 130 resolved relocations, and proves all
three backups unused and absent. The original full exception-index allocation
(including its terminal descriptor), all constructor slots, and all destructor
slots were scanned without finding ownership for this function.

Evidence is frozen separately in `scratch/game_record_stream_read_322/`.
