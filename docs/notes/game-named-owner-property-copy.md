# Named owner property copy

`src/Game/named_owner_property_copy.cpp` reconstructs the original C entry
`fn_80238F64`, 1,268 bytes at `80238F64..80239458`, with ordinary C++ and genuine
native Handle construction/destruction. The isolated production compiler proof
matches every retained byte and all 15 actual resolved relocations. Central
full-DOL acceptance is pending; this handoff requests NonMatching first.

The routine creates a named resource through the existing lookup, retains and
assigns its returned Handle, then invokes the original base-copy helper. It
copies two reference-counted Handle members at +0x74/+0x78, pairs at +0x54 and
+0x5C, scalar +0x50, position +0xC, scale +0x1C, scalars +0x18/+0x28 and words
+0x64/+0x68/+0x6C. The destination is freshly resolved before each property copy,
and virtual slot+0x24 commits the completed resource. The source/header expose
partial object views and preserve all existing native C entry identities.

One zero-initializing derived Handle layer around the lookup return reproduces
the original return temporary, copied temporary, assignment and native base
destructions. The two-member copy loop retains its source Handle pointer before
resolving the destination and traverses both partial object views by four bytes;
this preserves the original source address across the decrement/store/increment
sequence. Separate counter initialization and current-pointer-before-offset
increments reproduce the original loop scheduling. Float point/pair assignment
performs the original separate component copies.

All 1,440 emitted allocated bytes are accounted: 1,268 retained text plus two
unreferenced weak destructor backups totaling 172 bytes (88 and 84). Their raw
bytes, symbols and four real relocations are inventoried, and no retained
instruction references either weak helper. Both backups must be discarded from
the final native link; the existing strong native Handle constructor/destructor
remain the retained targets. No special override adapter is needed.

There are no initialized-data, BSS, vtable, padding, exception, constructor-table
or destructor-table allocations in this partial text split. The full original
exception/startup tables contain no owned entry. The original external string
`lbl_802AEA90`, global context and related functions retain their owners and
receive no new credit. No consumer, shared header, central symbol, split or
configuration edit was made by this agent.

`python3 scratch/engine_named_owner_copy_20261011fe/verify.py` checks complete
retained bytes, all 19 emitted actual relocations, complete allocation/symbol
inventories, unused weak accounting, original DOL SHA1, full original tables and
frozen source/research hashes. `final_integration.json`, `final_splits.txt`,
`final_config.txt` and `scope_edits.txt` freeze the integration proposal.
