# Skin callback action selector and original vtable

Isolated ordinary C++ recovery matches `fn_8025ACF0` at
`8025ACF0..8025B158` (1,128 bytes) and the complete 188-byte data allocation at
`802ECAF8..802ECBB4`. The unchanged strict verifier checks all 89 retained
actual relocations, every retained allocated byte, all symbol extents, and the
complete original exception-index, constructor and destructor tables. Production
registration and full original-DOL/native-link acceptance remain with root.

The selector shares the established seven-event callback registration/query
protocol. Later events initialize shared state and report the action category.
Action 11 checks flag `0x40` and the absence of flag `0x3F`; action 12 binds a
returned handle to the target resolved from the owner's handle at `0x64`.
Action 14 queries flag `0x3F`. Action 15 activates flag `0x40`, copies a returned
handle with the native reference increment, binds it to the owner's target,
applies the resolved target's float at `0x30`, and destroys the copied handle.

An explicitly initialized integer readiness local preserves the original
branch result move. A distinct nontrivial returned-handle view records the
hidden-return ABI and destructor call with argument zero. The copied handle
uses the native base constructor, its zeroing layer, word copy and reference
increment. The full original owner/class definitions remain unknown; the new
header records only the established physical views and ordinary value lifetimes.

The original GLOBAL `lbl_802ECAF8` is a real 124-byte vtable: two zero header
words followed by 29 function pointers. It is reconstructed as a writable typed
vtable storage record with explicit function-pointer initializers, retaining
every original C/native symbol and all 29 actual kind-1, zero-addend relocations.
The storage's function-pointer type describes its physical representation;
complete virtual-method signatures and the native class identity are not claimed.
Existing consumers keep their original read-only byte views of the same GLOBAL
symbol. They are not edited, and no code invokes the table through this partial
storage type. There is no native identity migration or alias.

The compiler naturally places the two switch tables immediately after that
vtable: LOCAL `@146`, 36 bytes at `802ECB74`, then LOCAL `@145`, 28 bytes at
`802ECB98`. The complete allocation begins at the original eight-byte-aligned
address. This is genuine original data ownership, with no synthetic prefix,
gap, padding ownership, section alignment change or compiler payload rewrite.
The four original bytes after `802ECBB4` remain external and uncredited.

The compiler also emits three unique, unreferenced weak destructor copies:
`__dt__20SkinActionCopyHandleFv` (88 bytes),
`__dt__20SkinActionZeroHandleFv` (84 bytes), and
`__dt__24SkinActionReturnedHandleFv` (84 bytes). Their 256 trailing text bytes,
six actual relocations and four total nonallocated compiler metadata records
are fully inventoried. No retained code/data relocation points to these copies.
Their names have no existing active symbol/reference collision. They request
zero credit and require the existing complete native unused-copy discard audit
at integration. There are no emitted EH, ctor, dtor-table, BSS or small-data
allocations.

The current ownership preflight finds no accepted source overlap in either
owned section. The consumer census scans 10,230 ELF inputs selected by
`objdiff.json`, excluding stale generated assembly, and records numerical
relocation addends into the owned ranges as well as named references. The
vtable's three existing source consumers and six corresponding active original/
source objects retain all their HA/LO references. All 29 original vtable targets
have active defined providers. Each private switch table has only its own
function's HA/LO pair, with zero addends.

A bytewise scan of every initialized original data section finds 17 pointers
into the function: its own vtable entry and the 16 owned switch entries. There
is no external interior function pointer or initialized pointer into either
local table or the global vtable. Full original direct-branch scans find no
external branch into this function. No existing compiled consumer requires a
source/header change.

Borrowed member-pointer pool `lbl_802ECAB0`, message `lbl_802AEBF0`, manager and
scratch globals, float literal `lbl_8037B520`, native Handle implementation,
external functions, neighboring data and accepted constructor/destructor sources
retain their original identities and ownership. This is a partial original
translation unit. Frozen production, allocation, vtable and consumer evidence
is under `scratch/engine_callback_skin_action_20261011jt/`.
