# Allocator state startup

The original GLOBAL entry `fn_80290B50` at `80290B50..80290B88` initializes
the allocator state at the original GLOBAL label `lbl_8028F698`: six words
become zero, then fields `18` and `1C` become `0x400` and `0x200`.

`src/Game/engine_allocator_state_startup.cpp` matches all 56 original code
bytes and the sole four-byte constructor pointer at `80299968..8029996C`.
The explicit compiler-native `.ctors` pointer uses the existing runtime's
`__init_cpp_exceptions.cpp` declaration pattern. The recovered C entry retains
its original name, address, size and GLOBAL binding; the pointer is the LOCAL
object `allocator_state_startup_reference`. No native startup-function rename
or constructor class identity is proposed.

GC 1.3.2 with `-O4,p`, exceptions off and individual GPR saves reproduces the
whole allocation. GC 1.2.5 initially produces the same 56-byte extent with five
scheduling differences; that diagnostic and a failed unused compiler-option
probe are preserved. The production object emits only 56 `.text` bytes and
four `.ctors` bytes. All three actual relocations match: the storage HA/LO pair
and the constructor pointer. There are no helper, weak, exception, destructor,
literal, BSS or padding allocations.

The complete original exception, constructor and destructor table census finds
only the owned constructor slot. Current source definitions, native symbols,
canonical text and constructor-section ownership were checked. The active
object audit covers 10,294 ELF inputs, with 647 object reference records for
the startup and borrowed allocator label. The original initialized-data scan
finds the sole constructor pointer and no external interior pointer or direct
branch to the routine. Existing callers and declarations remain unchanged.

The 32-byte allocator storage remains the original assembly allocation in
`original/platform_allocator_storage.s`, without source credit or payload,
binding or name changes. Its complete payload and sole active original
definition are frozen separately. The dedicated header is a partial scalar
view for this source; it does not replace the other existing allocator views.

The frozen handoff is
`scratch/engine_allocator_state_startup_20261011kc/final_integration.json`.
`allocation_inventory.json`, `borrowed_storage_provenance.json`, complete
original-table and active-consumer audits, fresh-production `verify.py`, and
`frozen_sha256.json` record every owned byte, symbol and actual relocation.
Root owns registration, full DOL acceptance and progress reporting.
