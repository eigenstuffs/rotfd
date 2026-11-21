# Python module objects

`src/Objects/moduleobject.c` reconstructs the module object implementation in
GSQE78. Its implementation derives from the included CPython 1.5.2 reference;
the original copyright and permission notice remain in the source.

The full translation unit occupies `.text` 0x80155C0C–0x80156580 (2,420 bytes),
`.data` 0x802D4280–0x802D4403 (387 emitted bytes), and
`.sdata` 0x80376270–0x80376284 (20 bytes).

| Function | Address | Bytes |
| --- | --- | ---: |
| `module_traverse` | 0x80155C0C | 64 |
| `module_setattr` | 0x80155C4C | 332 |
| `module_getattr` | 0x80155D98 | 300 |
| `module_repr` | 0x80155EC4 | 352 |
| `module_dealloc` | 0x80156024 | 456 |
| `_PyModule_Clear` | 0x801561EC | 384 |
| `PyModule_GetName` | 0x8015636C | 132 |
| `PyModule_GetDict` | 0x801563F0 | 76 |
| `PyModule_New` | 0x8015643C | 324 |

An isolated CodeWarrior GC/2.0 compile reproduced every instruction byte after
resolving relocations to the verified DOL addresses. The type object, string
pool, and small data also reproduce all 407 emitted bytes. The complete project's
linked DOL SHA-1 check is the authoritative acceptance check.

The final byte at `0x802D4403` belongs to original linker padding and now has a
separate NonMatching owner. The [section-extent audit](source-section-padding.md)
preserves the initial baseline's older 408-byte attribution and checks this
one-byte accounting correction explicitly. The corrected full build still
matches the original executable, and all nine source functions remain exact.

Integration passed on 2026-09-07: all 9 functions and all owned data report
100% in objdiff. The complete rebuilt DOL is byte-identical to the original
(`5da8295a79bf297ab62c620e6ac66210be1c6ef5`).

## Compiler settings

The ordinary platform flags are `-proc gekko -fp hardware -enum int -str reuse
-common off`. Matching additionally requires:

- `-opt level=4,nopeephole,speed`: preserves separate decrement/compare
  instructions and emits individual register saves instead of helper calls.
- `-inline auto,deferred`: inlines `PyModule_GetName` and `_PyModule_Clear`
  and emits functions in reverse source order.
- `-pool off`: loads each data address directly rather than reserving a shared
  register for the translation unit's data.
- `-Cpp_exceptions off`: omits unused exception tables.

The filename lookup helper is `static inline`; it appears only inside
`module_repr`. Keep the upstream function definition order. Moving functions
also changes string placement because deferred compilation emits their
literals in reverse order.

## Differences from the CPython 1.5.2 reference

The target formats missing-attribute errors using the module name, falling back
to `?` when the name lookup fails. Its allocation macro invokes `malloc` with
`PyModule_Type.tp_basicsize`, then `PyObject_Init`. Reference count decrements
call `tp_dealloc` directly. `PyModule_GetDict` reports the original filename
`moduleobject.c` and source line 41 on internal errors.

`PyModule_Type` is 0x6C bytes, has flags 0x6B at offset 0x54, and includes a
traversal callback at offset 0x5C. That callback visits the module dictionary
when present and returns zero otherwise. This ninth function was originally
left just outside the module split; its type-table reference and exact source
match establish its membership in the translation unit. Other extension slots
are preserved as zero without assigning unverified semantics.
