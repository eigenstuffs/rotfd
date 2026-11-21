# Owner parent apply

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_parent_apply.cpp` reconstructs `fn_80240E50`, original `.text` range `80240E50..80240F28` (216 bytes), as ordinary C++.

Makes a retaining local copy of the supplied handle, resolves the owner parent handle at offset 0x0C and forwards the copy plus caller argument to the existing parent operation. The recovered inline handle hierarchy preserves the native base-constructor ABI, local address assignment and reference retention. The signed 24-bit index and signed 8-bit generation lookup retains native behavior. External globals and helpers keep their original ownership.

Run `python3 scratch/game_owner_parent_apply/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce all 216 retained bytes after applying the actual ELF relocations. Every function extent, allocated byte and real relocation site, kind, symbol, addend and target is checked. Unreferenced weak bodies are fully accounted and fingerprinted; nonallocated compiler metadata relocations are also checked. The protected original DOL hash and original extabindex, `.ctors` and `.dtors` ownership audits pass for this range. No owned data, BSS or padding are emitted.

The compiler emits 2 unused weak destructor backup(s), totaling 172 bytes: `__dt__17ParentApplyHandleFv` (88 bytes), `__dt__23ParentApplyNativeHandleFv` (84 bytes). These receive no credit and must be absent from the final ELF. The retained function has no relocation to them. Central integration must verify their absence, the original full DOL hash, native objdiff, source extents and regressions.

This partial text-only split leaves neighboring functions and original data external. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
