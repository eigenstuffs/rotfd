# Indexed owner timing dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_indexed_timing_dispatch.cpp` reconstructs `fn_8021E8FC`,
`0x8021E8FC..0x8021E9F8` (252 bytes), using standard GC 1.3.2 settings.

The function forwards the input descriptor, its owner pointer, its 64-bit flags,
and the selected index to virtual slot `0x64`. When input flag `0x8` is set,
it enables owner mask `0x2000000000000`, forwards the duration to slot `0x78`,
and sends the difference from the comparison descriptor's duration to slot
`0x74`. It returns one. The owner vtable is at offset eight; duration, flags,
and the owner pointer are descriptor offsets `0x4`, `0x28`, and `0x30`.

The 64-bit virtual argument at slot `0xDC` starts in registers r5/r6, leaving
r4 unused, as required by the native C++ ABI. No forced register assignments
or assembly are used.

`python3 scratch/game_owner_indexed_timing_dispatch/verify.py` recompiles the
frozen production source, checks the sole 252-byte allocated text section,
verifies the complete original function after real relocation processing
(zero relocations), and audits the complete original extabindex, constructor,
and destructor tables. No original table entries, data, BSS, padding, or weak
helper functions belong to this text split. Its containing original engine
translation unit remains incomplete. Central integration and final DOL hash
acceptance are parent-owned.
