# Owner cache slot and record conversion at 801D864C

`src/Game/owner_cache_record_convert_801D864C.cpp` reconstructs the complete
352-byte GLOBAL entry `fn_801D864C` at `801D864C..801D87AC`. It first stores
the supplied unsigned-short cache index at owner offset `0x20`. When owner
flag bit 3 is set, it resolves the packed signed8/signed24 owner handle via
the existing registry at global offset `0x118`, moves cache row index+1
to the sentinel chain through the cache at global offset `0x130`, and
converts each resource record into the corresponding owner record.

The cache has 12-byte rows with packed handle at 0, record index at 4,
and halfword links at 8/0xA. Its record blocks also have 12-byte stride.
The source retains ordinary inline `at`, `unlink`, `prepend`, `get` and
`convert` methods, including the native reloads around possibly aliasing
link stores. Resource records have 0x90-byte stride, owner records 0x68.
The source views deliberately leave their unobserved contents opaque.

The existing `fn_801D84F4` call receives resource in r3, resource record
in r4, owner record in r5 and cache block in r6. Its accepted implementation
uses the first three arguments; the existing accepted
`engine_dispatch_801D890C.c` caller already declares and passes the same
observed fourth argument. No external callee or existing caller changes
are needed. A const local resource pointer in the outer entry preserves
the native three-way register allocation: resource r28, resource offset
r29, owner offset r30, with loop index r31. The previous mutable-pointer
source differed at ten register words.

GC 1.3.2 uses standard Gekko `-O4,p`, automatic inline, exceptions and RTTI
off, and `-use_lmw_stmw on`; no extra optimization or scheduling flags.
Both the frozen scratch source and a fresh compile of production source
pass full relocated byte comparison. The object emits only aligned-four
`.text` 352, one GLOBAL function, and five allocated RELAs: two HA/LO
pairs for existing GLOBAL `lbl_801E9D24` and one REL24 for `fn_801D84F4`.
There are no helpers, weak tails, literals, initialized data, BSS, EH
records or padding.

Frozen source/object/proof:
`scratch/game_frontier_20261012_b/owner_cache_record_convert_801D864C.cpp`,
`.o`, `.json`, `.owned.json`; independent fresh production object ends
`_fresh.o`. `audit_owner_cache_record_convert.py` rescans all 3,109,410
original aligned and unaligned four-byte positions, the complete original
exception/startup tables, direct branches and absolute materializations,
and all actual RELAs in 6313 active link inputs. The census found two
aligned initialized data pointers, at `802EA658` and `802ED4A8`, to the entry, no interior external
references, and no associated EH/ctors/dtors. The two active GLOBAL
R_PPC_ADDR32 entry references use addend 0. The 6313 inputs and 133735 actual
RELAs were verified unchanged during the audit.

This is a partial original translation-unit text split. Preserve following
original `fn_801D87AC` at `801D87AC..801D890C`, and every original global,
registry/cache allocation, block and record allocation. Register 352 bytes
NonMatching, validate normal allocation/relocation proof, then promote
only after full original DOL hash, regressions, interface and extent audits.
Central integration and final progress remain with the parent integrator.

Integrated as Matching source after an independent production compile and
standard/mapped native acceptance. Code rises by352bytes; the original DOL
hash, baseline, full original coverage, complete allocation/consumer proofs,
source extents and all66tests pass. No source credit is assigned to any
neighboring original allocation.
