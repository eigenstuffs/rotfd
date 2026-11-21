# Render index reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/render_index_reset.cpp` reconstructs `fn_802701C0`,
`0x802701C0..0x8027024C` (140 bytes), using ordinary C++ and standard
GC 1.3.2 settings. Its isolated production object matches every original
byte. Central integration and full executable acceptance are pending.

If the receiver's halfword flags at `0x6E` contain bit 4, the function calls
the supplied object's virtual method at table offset `0x54`, forwarding the
second argument. It then clears the first halfword of each four-byte record
to `0xFFFF`, using the signed count at `0x30` and record pointer at `0x38`.
The receiver's active byte at `0x118` is cleared unconditionally. An inline
object method for the record loop reproduces the native counter/offset
register allocation; no assembly or aliases are used.

Run `python3 scratch/game_render_index_reset/verify.py` for the frozen proof.
The object emits exactly 140 allocated text bytes, with no relocations,
unused helpers, data, BSS or padding. The verifier checks the original DOL
SHA1 and complete extabindex, constructor and destructor tables; none refers
into this range. No shared headers or metadata are changed. This is a partial
text split of its original translation unit.
