# Early mode Handle selector at 8004B984

This is an isolated ordinary C++ reconstruction pending root integration. It owns the original 1,176-byte C entry `fn_8004B984`, 24-byte exception record at 800095BC, 12-byte exception index at 80017B2C, and 88 original data bytes at 802B3C98..802B3CF0. No matching credit is claimed until the original DOL hash and complete native placement audit pass.

The selector dispatches callback operations through five member-pointer records, converts four float query results into observed mode/state fields, counts valid returned Handles, updates two virtual selections, and clears callback flag bit 2. Private layouts establish the observed prefix, virtual slots, scalar fields through byte 0x72, and callback flags/index at 0x28/0x2A. They are partial views rather than recovered complete class definitions. The original C entry and all external callable identities remain unchanged.

`-proc 750 -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` reproduces every retained instruction and every owned metadata/data byte after actual ELF relocations. The explicit ordinary `flags &= 0xFFFB` produces the native `andi.`; a prior equivalent bit clear compiled to a different instruction and remains preserved privately. Production is an unchanged copy of `exact.cpp`.

The source emits a 116-byte weak Handle80020B90 destructor and a private 76-byte zero-base destructor, plus 72 bytes of their exception records/indices. These 192 code bytes and 72 metadata bytes are uncredited. The exact accepted GLOBAL116 Handle80020B90 owner is independently recompiled, verified against original bytes/actual relocations, and selected in an actual MWLD link. All six backup allocations are discarded. A wrong fixture basename is rejected. The isolated native link proves selection/discard only; its relocated addresses are intentionally rejected by the full original-placement gate.

The private inline zero base was named `ModeHandleZero_4B984` to avoid colliding with the unrelated accepted strong Handle8001FF78 destructor. The preserved mask/exact probe pair proves that this changes only its weak symbol name (and nonallocated source-file name): every allocated byte and all 54 actual relocation encodings remain identical, and retained code/EH never reference that private backup. No accepted source or native identity was changed.

## Genuine data partition

Original GLOBAL `lbl_802B3C74` contains eight complete 12-byte member-pointer records. Its first three records at 3C74, 3C80, and 3C8C remain in original assembly under the same base name/address, with size 36. Their words are `(0,0x94,8)`, `(0,0x98,8)`, and `(0,0x9C,8)`.

The final five complete records at 3C98..3CD4 are each `(0,0x9C,8)` and become GLOBAL60 `lbl_802B3C98`. They are a genuine subarray tail, not padding. The original seven-entry local switch at 3CD4..3CF0 follows at offset 60, with exact ADDR32 function-relative addends 0x48, 0x74, 0x9C, 0xC4, 0x11C, 0x174, and 0x17C. The resulting original data allocation begins on an 8-byte boundary, satisfying the compiler's emitted alignment without changing bytes or adding storage.

Borrowed GLOBAL72 `lbl_802B3708` and accepted neighboring GLOBAL60 `lbl_802B3CF0` remain unchanged. The private borrowed pool view retains the original 3708+0x590 addressing; it does not acquire the intervening data. Root must partition the original base, transfer only the complete tail and switch, and add `lbl_802B3C98` exactly once to both config `force_active` and generated native FORCEACTIVE. The tail is otherwise unreferenced by symbol name and can be removed by the linker.

The independent ownership audit scans 5,563 original inputs and 5,563 current active inputs, resolving 119,086 and 131,400 actual relocations respectively. The switch has only the original function's two addressing relocations; no matching canonical owns the tail/table, and no initialized pointer among 777,360 original DOL words enters the entire original record pool or switch. Broader borrowed-base source/header and object consumers are inventoried and preserved. The full original extabindex, constructor and destructor tables have no additional owned records/startup pointers.

## Bounded adoption

`record_switch_gate.py` and `table_adapter.py` authorize only this exact frozen source, manifest, section inventory, raw data shape, seven actual ADDR32 records, and one exact accepted strong owner. They clone the unchanged reviewed inspector/opt-in code objects with only the exact record-tail switch check substituted. Old ELF/EH/native cores, old gates, adoptions and routes remain unchanged. The outer interface delegates all other sources to the parent's current loader.

The native gate requires the primary, strong owner, GLOBAL60 tail and LOCAL28 switch at exact original addresses, all six backup allocations discarded, exact map ownership, FORCEACTIVE retention, original bytes across all four owned sections, and preserved identities/bytes for the first three records, borrowed base, and next accepted record pool. Root must run it on both full original-layout ELF/map pairs.

Twelve guard tests pass with 11 positive cases and 2,478 rejected mutations covering every manifest/strong-proof/canonical leaf, actual ELF allocation/relocation mutations, all seven switch relocations and raw table words, original symbol sizes/bindings/addresses, duplicate aliases, FORCEACTIVE omission/duplication, wrong native fixture and wrong original placement. Persistent compiler authorizations pin source, recursive accepted strong-owner headers, manifests, exact objects, compiler, strict cores and ownership evidence. Documentation hashes are recorded at adoption but excluded from the persistent compiler gate so this note can be refreshed after acceptance.
