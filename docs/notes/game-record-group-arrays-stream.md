# Group record array stream reader

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801D0650..801D0CB8` is reconstructed as ordinary C++ in
`src/Game/record_group_arrays_stream_801D0650.cpp`. The first isolated
GC1.3.2 Gekko/O4,p/exceptions-off probe matches all1,640 original text bytes and
86 retained actual relocation targets. Complete native placement and discard
remain root's acceptance boundary.

After its existing base reader, the owner resizes and reads arrays of4-byte
words at0x8C,12-byte vectors at0x98 and8-byte pairs at0xA4. It then resizes a
two-layer native Handle array at0xB0, invokes the registry's name reader for
each entry, and reads its final two-byte field at0xBC. Typed placement
construction, reverse shrink destruction and ordinary capacity reservation
reproduce the native loops and register allocation.

There is one unique unused84-byte weak destructor,
`__dt__20GroupArrayStreamZeroFv`, and two backup relocations. The strict verifier
accounts for this trailing text allocation and proves no retained reference.
It receives no matching credit and must be absent from both complete native
ELFs/maps. The candidate owns no original EH, data, BSS, padding or startup.

The full original extabindex/constructor/destructor audit finds no references.
The active input and initialized-word audit preserves the sole original data
pointer802EA504 inside external`lbl_802EA4F8[96]`. Existing original assembly
callers and the C entry identity remain unchanged; no compiled consumer needs
migration. The audit scans every active input relocation and all777,360
initialized words.

Frozen evidence, two production recompiles, integration fragments and the
original ownership inventory are in
`scratch/game_record_group_arrays_stream_801d0650/` and batch229. No central or
shared source files were changed by the agent.
