# Resolved-index callback selector and original vtable

Isolated ordinary C++ recovery matches `fn_8025A5F8` at
`8025A5F8..8025A930` (824 bytes) and the complete 152-byte data allocation at
`802ECA18..802ECAB0`. All 61 actual relocations, allocated bytes and symbol
extents pass the unchanged strict verifier and fresh production compilation.
Registration and full original-DOL/native-link acceptance remain with root.

The selector implements the established seven-event callback registration/query
protocol, then initializes shared scratch state, derives an indexed action and
finalizes the callback. Action 14 requires owner flag `0x42` and a nonzero
availability query on its packed handle at `0x70`. Action 15 resolves that
handle and invokes the resolved object's virtual slot `0xF4` with the owner's
float at `0x2C` converted to an integer.

The availability result is an ordinary named signed-char local inside the flag
branch. This preserves the original pointer-to-boolean conversion and signed
extension. A direct combined condition and inline validity helpers folded that
conversion into a branch and emitted 812 bytes; the named local matches all
824 original bytes. The dedicated header records only the physical owner,
callback, packed handle and member-pointer views. The resolved object's vtable
follows an eight-byte inherited prefix. Complete original classes remain unknown.

The original GLOBAL `lbl_802ECA18` is a real 124-byte vtable: two zero header
words followed by 29 function pointers. A writable typed physical storage record
owns that complete allocation and retains every original C/native symbol and
all 29 actual kind-1, zero-addend relocations. Its pointer type describes storage;
complete method signatures and a recovered native class identity are not claimed.
No code invokes the table through this partial storage type. Existing consumer
byte views and all original identities remain unchanged.

The compiler naturally emits LOCAL `@70`, a 28-byte switch table immediately
after the vtable at `802ECA94`. The complete section begins at the original
eight-byte-aligned address and ends at the next borrowed member-pointer pool.
There is no synthetic prefix, gap, padding ownership, alignment adaptation,
alias or compiler payload rewrite. There are no emitted weak helpers, exception
sections, ctor/dtor-table entries, BSS, small-data allocations or extra sections.
Standard GC1.3.2 Gekko `-O4,p`, exceptions off and individual saves reproduce
the exact object.

Current original-identity/canonical checks find no accepted source overlap in
either owned section. Full original exception-index, constructor and destructor
table scans find no ownership. The consumer census scans 10,234 active ELF inputs
selected by `objdiff.json`, excluding stale generated assembly, and includes
numerical addends into the owned ranges. All existing vtable declarations and
the three actual source consumers/six original-source objects retain their HA/LO
references. All 29 vtable function targets have active defined providers. The
private switch table has only this function's own HA/LO pair, with zero addends.

A bytewise scan of every initialized original data section finds 100 pointers
into the function: seven owned switch entries and 93 function-entry pointers.
There is no external interior function pointer or initialized pointer into the
local switch table or global vtable. Full original direct-branch scans find no
external branch into the function. Its inherited use by many external vtables
retains the original function identity and requires no consumer changes.

Borrowed member-pointer pool `lbl_802EC9D0`, message `lbl_802AEBE4`, availability
query `fn_801F7EB8`, manager and scratch globals, native destructor/method owners,
other vtables and neighboring allocations retain their original ownership and
identities. This is a partial original translation unit. Frozen production,
allocation, vtable and consumer evidence is under
`scratch/engine_callback_resolved_index_20261011jv/`; failed and intermediate
private probes remain uncredited.
