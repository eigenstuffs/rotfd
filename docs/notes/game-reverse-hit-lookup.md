# Reverse hit lookup

`src/Game/reverse_hit_lookup.cpp` reconstructs `fn_80269DE0`,
`0x80269DE0..0x80269F2C` (332 bytes), with standard GC 1.3.2 settings.
Every original byte and actual relocation matches in the isolated production
compilation; central integration is pending.

The partial owner view has eight handles at `0xC110` and a signed count at
`0xC130`. It visits occupied indices in reverse order. A nonnegative selector
restricts the visit to that index; a negative selector visits all indices.
Each candidate is copied into a retained four-zero temporary and resolved
through context manager `0x118` before `fn_80242C70` tests it. A successful test
assigns that handle to output offset `4` and returns one. Every temporary is
cleaned up, and exhaustion returns zero. The external call spelling remains
unchanged so its centrally owned reconstruction can be integrated independently.

An unsigned element accessor prevents an extra pointer induction variable;
its array reference preserves the original high-address calculation. The
signed reverse loop and selector comparison remain signed. Layered helper
initialization describes the observed native construction sequence rather
than asserting original class identities. No assembly or aliases are used.

Run `python3 scratch/game_reverse_hit_lookup/verify.py` to reproduce the frozen
proof: 332 retained bytes, nine actual relocations, and all 792 allocated text
bytes. Five unused weak destructor backups total 460 bytes; their ten
relocations are inventoried, no retained reference targets them, and they must
be absent from the final ELF. Complete original extabindex, constructor, and
destructor tables show no retained ownership. No data, BSS, or padding is
owned. This partial split leaves the containing original translation unit
outside its scope.
