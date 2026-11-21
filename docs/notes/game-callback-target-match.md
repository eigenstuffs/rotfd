# Target-match callback selector and original vtable

Isolated ordinary C++ recovery matches `fn_8025C520` at
`8025C520..8025C858` (824 bytes) and the complete 168-byte data allocation at
`802ECD68..802ECE10`. All 64 actual relocations, allocated bytes and symbol
extents pass the unchanged strict verifier and a fresh production compilation.
Registration and full original-DOL/native-link acceptance remain with root.

The function implements the established seven-event callback registration/query
protocol, then initializes shared scratch state, derives an indexed action and
finalizes the callback. Action 14 queries owner flag `0x1F`. Action 15 converts
the owner's float at `0x2C` to an integer, compares it with the key resolved
from virtual slot `0x78(-1)`, and invokes virtual slot `0x34` when they match.
The dedicated header describes only the established physical owner, callback,
packed handle and member-pointer views. Full original class definitions remain
unknown. Its ordinary source matches on the first probe with standard GC1.3.2
Gekko `-O4,p`, exceptions off and individual register saves.

The original GLOBAL `lbl_802ECD68` is a real 140-byte vtable: two zero header
words and 33 function pointers. A writable typed physical storage record owns
that complete allocation, retaining every original C/native symbol and all
33 actual kind-1, zero-addend relocations. Its pointer type describes storage;
complete method signatures and a recovered native class identity are not
claimed. No code invokes this table through the partial storage type. Existing
consumer byte views and every original symbol identity stay unchanged.

The compiler naturally emits LOCAL `@105`, a 28-byte switch table immediately
after the vtable at `802ECDF4`. The complete data section begins at the original
eight-byte-aligned address and ends exactly where the independently accepted
target-action selector's table starts. There is no synthetic prefix, gap,
padding ownership, alignment adaptation, alias or compiler payload rewrite.
There are no emitted weak helpers, exception sections, ctors, dtors, BSS,
small-data allocations or other extra sections.

Current original-identity/canonical checks find no accepted source overlap in
either owned section. Full original exception-index, constructor and destructor
table scans find no ownership. The consumer census scans 10,234 active ELF inputs
selected by `objdiff.json`, excluding stale generated assembly, and includes
numerical addends into the owned ranges. The three existing vtable consumer
sources, their shared header and six original/source objects retain all HA/LO
references. All 33 vtable function targets have active defined providers. The
private switch table has only this function's own HA/LO pair, with zero addends.

A bytewise scan of all initialized original data sections finds nine pointers
into the function: seven owned switch entries and two function-entry pointers.
There is no external interior function pointer or initialized pointer into the
local switch table or global vtable. Full original direct-branch scans find no
external branch into this function. No existing compiled source or header
requires a change.

Borrowed member-pointer pool `lbl_802ECCD8`, message `lbl_802AEC4C`, manager and
scratch globals, accepted neighboring target-action source and table, native
destructor/method owners and all other code/data retain their original ownership
and identities. This is a partial original translation unit. Frozen production,
allocation, vtable and consumer proofs are under
`scratch/engine_callback_target_match_20261011ju/`. An initial consumer scan
stopped while central configure was writing `objdiff.json`; the preserved
failure was followed by the complete successful census after configuration
stabilized, without any source or input changes.
