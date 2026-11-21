# Scoped handle lookup

`src/Game/scoped_handle_lookup.cpp` reconstructs `fn_802631B0`,
`0x802631B0..0x80263308` (344 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The function creates a two-zero local handle. If the supplied object's scope
handle at `0x18` is valid, it resolves that scope and looks up the key through
`fn_801E7654`, retaining the returned handle into the local and cleaning up
the lookup temporary. If the local remains invalid, `fn_8023A8C0` performs a
fallback lookup through context resource manager `0x120`. It returns a
one-zero retained copy of the local, then cleans up the local. Genuine C++
structure return, layered initialization, and destructors reproduce the
native hidden output pointer and both temporary stack slots.

Run `python3 scratch/game_scoped_handle_lookup/verify.py` to reproduce the
frozen proof: 344 retained bytes, 17 actual relocations, and all 604 allocated
text bytes. Three unused weak destructor backups total 260 bytes; their six
relocations are inventoried, no retained reference targets them, and they must
be absent from the final ELF. Complete original extabindex, constructor, and
destructor tables show no retained ownership. No data, BSS, or padding is
owned. This partial split leaves the containing original translation unit
outside its scope.
