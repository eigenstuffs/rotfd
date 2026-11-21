# Reverse sphere lookup

`src/Game/reverse_sphere_lookup.cpp` reconstructs `fn_80269C94`,
`0x80269C94..0x80269DE0` (332 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The partial owner view has eight handles at `0xC110` and a signed count at
`0xC130`. Starting from the final occupied index, the function makes a retained
four-zero handle copy, resolves it through context manager `0x118`, copies the
resolved sphere at `0xC` into the output, and returns another retained copy.
The body returns on its first iteration. An empty owner returns a five-zero
handle. Genuine C++ structure return and layered initialization reproduce the
hidden output pointer and original construction/cleanup sequence. An array
reference accessor preserves the original common high-address calculation;
direct element access adds an instruction. The helper type names describe
these observed sequences rather than asserting original class identities.

Run `python3 scratch/game_reverse_sphere_lookup/verify.py` to reproduce the
frozen proof: 332 retained bytes, eight actual relocations, and all 792 allocated
text bytes. Five unused weak destructor backups total 460 bytes; their ten
relocations are inventoried, no retained reference targets them, and they must
be absent from the final ELF. Complete original extabindex, constructor, and
destructor tables show no retained ownership. No data, BSS, or padding is
owned. This partial split leaves the containing original translation unit
outside its scope.
