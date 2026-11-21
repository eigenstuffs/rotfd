# Typed pool-cluster cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The partial source split reconstructs `800B6080..800B633C` (700 bytes) and
`800B5EC8..800B6080` (440 bytes) as ordinary C++ destructors. Both first probes
match their complete text and their compiler-emitted 40-byte exception table
and 12-byte exception index. All actual relocations are applied; no relocation
mask or assembly is used. Central executable acceptance is required.

`Record_800B6080` contains a nested pool of handle pools at offset zero, a
handle pool at `0C`, empty-element pools at `18`, `24`, and `34`, and an opaque
word at `30`. A four-byte handle wrapper supplies the observed null check before
the external base Handle destructor. Nested pool elements have the proved
12-byte size. Each pool releases live elements, frees its storage using its
capacity and element size, and clears the pointer twice in the original order.
The empty element destructors preserve the original counted loops.

`Object_800B5EC8` releases each record pointer in its `20` pool through the
record's native deleting destructor, then destroys that pointer pool, the
four-byte empty-element pool at `14`, and its base. The base sets the original
vtable and releases a pool of 56-byte empty records at offset `04`. Its word at
`10` remains opaque. Existing vtable data stays external. Non-throwing class
deletion generates the original exception-specification handler.

The complete original exception-index and constructor/destructor tables were
scanned. Each routine owns precisely its original exception-index entry; no
startup entry references either routine. Every allocated output section and
symbol extent is verified, with no extra output or owned padding. The two old
provisional spellings have no compiled callers, allowing guarded native-name
migration without aliases. Neighboring routines and external data remain
outside this split. Frozen proofs are in
`scratch/game_pool_cluster_destructors/final_integration.json`.
