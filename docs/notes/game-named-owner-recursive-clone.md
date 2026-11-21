# Named owner recursive clone

`src/Game/named_owner_recursive_clone.cpp` reconstructs the original C entry
`fn_8023E994`, 1,140 bytes at `8023E994..8023EE08`, with ordinary C++ and genuine
native Handle lifetimes. The isolated production compiler proof matches every
retained byte and all 31 actual resolved relocations. Central full-DOL acceptance
is pending; this handoff requests NonMatching first.

The routine creates a resource using a local name object and the source name,
retains and assigns the lookup result, then resolves the assigned destination.
It copies reference-counted members +0x24/+0x28, two float vectors and four float
scalars, applies the source group, copies flags and the nine-word basis, and
copies the sixteen-word local matrix into the active buffer for the destination
index. It sets matrix-dirty bit0x20 and invokes the original update helper, then
copies the parent Handle. A two-zero-layer native Handle receives an optional
linked resource lookup and is assigned to destination +0x20. If the signed
children flag is true, each source child is recursively cloned and added to the
destination using a retained by-value Handle; iteration follows the child's
next Handle at +0x18.

A genuine local Name object places it at stack+0x1C, while the two-zero linked
and child Handles occupy +0x18/+0x14. The initial return and retained copy use
+0x10/+0xC; the per-child retained argument uses +8. Explicit if/return resolver
control flow reproduces the native saved child pointer and matrix-copy register
allocation. Basis/matrix aggregate copies preserve the original raw word pairs,
and point assignment preserves the separate float component copies. The source
uses partial object views and keeps every existing C/native dependency identity.

All 1,400 emitted allocated bytes are accounted: 1,140 retained text and three
unreferenced weak destructor backups totaling 260 bytes (88, 88 and 84). Their
raw bytes, symbols and six real relocations are inventoried. No retained
instruction refers to any backup; all three must be discarded from the final
native link. The existing native Handle constructor/destructor remain the
strong retained targets. No special override adapter is needed.

There are no initialized-data, BSS, vtable, padding, exception, constructor-table
or destructor-table allocations in this partial text split. The full original
exception/startup tables contain no owned entry. The external five-byte string
`lbl_8037B338`, global context, matrix pool and adjacent functions retain their
owners and receive no credit. No consumer, shared header, central symbol, split
or configuration edit was made by this agent.

`python3 scratch/engine_named_owner_clone_20261011fg/verify.py` checks complete
retained bytes, all 37 emitted actual relocations, complete allocation/symbol
inventories, unused weak accounting, original DOL SHA1, full original tables and
frozen source/research hashes. `final_integration.json`, `final_splits.txt`,
`final_config.txt` and `scope_edits.txt` freeze the integration proposal.
