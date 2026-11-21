# Hierarchy lifecycle and owner setup

| Source | Original extent | Code bytes | Relocations |
| --- | --- | ---: | ---: |
| `src/Game/hierarchy_lifecycle.cpp` | `0x80203510..0x80203890` | 896 | 9 |
| `src/Game/hierarchy_owner_setup.cpp` | `0x80203890..0x802039A8` | 280 | 10 |

The lifecycle method preserves the canonical C++ identity
`slot1C__18Hierarchy_80200478Fv` as a strong, global, out-of-line method. It first
calls the corresponding root method at `0x80207354`. On success it invokes
virtual offset `0x1C` on valid handles in four parallel lists, two additional
lists, and finally the related object; on failure it immediately returns zero.

The root call must be declared to return a signed byte. A `bool` declaration
produces a low-byte mask where the original sign-extends the return value.
The private root and hierarchy declarations therefore use `signed char` for
this method. Return types do not alter its MW mangled symbol. This refines the
earlier inferred `bool` declarations in other partial class views. The root
implementation and hierarchy destructor declarations were subsequently aligned
to this signed-byte result; fresh compilation produces exactly the same object
hashes for both existing units. The existing hierarchy vtable at
`0x802EAF40` remains owned by the previously recovered destructor unit. This
method emits no vtable, RTTI, exception records, or other metadata.

The adjacent setup function updates the owner handle with balanced release and
retain operations, copies the supplied name to the object buffer, and assigns
a retained copy of the object's identity to the related object's owner field
at offset `0x28`. A const reference accessor preserves the identity address
across native handle construction. Direct field access shortens the method by
four bytes and changes that address lifetime. The source preserves the original
unbounded `strcpy` operation and handle update order.

The new private `hierarchy_lifecycle_internal.h` reuses the existing handle
resolver, records the observed root prefix and list fields, and exposes the
canonical virtual method. Its names and partial layout views describe recovered
ABI evidence, not original debug information.

`scratch/game_hierarchy_lifecycle/verify_lifecycle.py` and `verify_setup.py`
compile with GC/1.3.2, `-O4,p`, `-inline auto`, and `-use_lmw_stmw on`. They apply
all 19 retained relocations and verify all 1,176 retained code bytes against the
SHA-1-checked original DOL. No original data or padding is claimed. The setup
source emits one unused 84-byte weak wrapper destructor; its two relocations,
exact extent and binding, and absence of retained references are checked before
excluding it from source credit through normal linker dead stripping.

The stable candidates are `config/GSQE78/candidates/game_hierarchy_lifecycle.json`
and `game_hierarchy_owner_setup.json`. Full-DOL and native objdiff integration
pass for both functions and all 1,176 code bytes, with no owned data. The
source-section extent guard and direct comparison with the original DOL pass.
