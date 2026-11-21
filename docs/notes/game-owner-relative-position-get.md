# Owner relative position getter

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_relative_position_get.cpp` reconstructs `fn_8022E488`,
`0x8022E488..0x8022E63C` (436 bytes), with standard GC 1.3.2 flags and source
`fp_contract on` for the native fused multiply-add operations.

The function obtains the indexed primary handle from virtual slot `0x9C`,
resolves the owner-related handle at `0x1A8`, and obtains that related owner's
primary handle at index zero. Both objects' matrix pointers are at `0x124`.
It transforms the selected object's translation by the related primary's
4x4 matrix and returns the resulting three-float point through its native
hidden output pointer. The matrices use columns at `0x00`, `0x10`, and `0x20`,
with translation at `0x30`. Named source and result components followed by
ordinary scalar point construction reproduce native floating-point scheduling
and the complete return ABI. No explicit output-pointer workaround is used.

`python3 scratch/game_owner_relative_position_get/verify.py` recompiles frozen
production source, validates both actual relocations, and compares all
436 bytes to the hash-verified original DOL. The sole allocated section is
exactly 436 bytes of text, without weak helpers, data, BSS, or owned padding.
Complete original extabindex, constructor, and destructor table scans show no
retained ownership. The original engine translation unit remains incomplete.
Central integration and final DOL hash acceptance are parent-owned.
