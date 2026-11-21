# Owner unique handle and companion arrays

**Isolated ordinary source match; production integration pending.**

`src/Game/engine_owner_unique_lists.cpp` recovers the complete existing C entry
`fn_8022BE34` at `8022BE34..8022C598`, 1,892 text bytes. GC 1.3.2 with the standard
Game options plus `-use_lmw_stmw on` matches every retained instruction and all
166 actual relocation targets. The dedicated header contains only the opaque
owner and handle declarations and the existing entry prototype.

The routine searches the packed-handle array at owner offset 0x60 by resolved
object identity. An existing match leaves all arrays unchanged. Otherwise it
grows the handle storage in groups of 32, placement-constructs a two-layer handle
copy, and retains the source reference. It then reserves index-plus-one entries
in three four-byte companion arrays at 0x78, 0x84 and 0x90 using the original
debug allocator, strings and line arguments. Ordinary inline storage, allocation,
resize and reserve methods preserve the original nested comparisons and the
idempotent capacity stores, including the duplicate store in the resize growth
path. A separately named resolved current owner establishes the original
left-before-right lookup sequence.

The unchanged compiler object allocates only 1,976 bytes of text: the retained
1,892-byte entry and one 84-byte weak `UniqueListsZeroHandle` destructor. The
weak copy has two actual relocations, no retained reference and no retained
exception/data/startup pointer. It uses the existing default unused weak discard
path; no strong override or adapter is proposed. The strong function and the weak
backup are fully inventoried with their raw bytes and symbols. No initialized
data, BSS, exception table, constructor/destructor pointer, vtable or owned
padding is emitted or claimed.

The full original extabindex, ctor and dtor table allocations were scanned,
including their descriptors and padding, and contain no reference to the
retained entry. The original context, managers, allocators, debug strings,
neighboring functions and original translation-unit data retain their owners.
All existing function and external symbol identities remain unchanged; no
consumer migration is required.

`scratch/engine_owner_unique_lists_20261011fb/final_integration.json` is the
complete frozen production proposal. `verify.py` recompiles the source and checks
all retained bytes, all 168 actual relocations, complete allocated-section and
nonzero-symbol inventories, the unchanged raw object, the full original tables
and the frozen source/header/research hashes. The original source prototypes of
the debug allocation calls are partial caller views; their observed six-argument
sequences are preserved without changing accepted callers or
allocator definitions. Root integration and full original DOL acceptance remain
required before claiming project progress.
