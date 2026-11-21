# Owner identity handle find

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_identity_handle_find.cpp` reconstructs `fn_8024BDA0`, original `.text` range `8024BDA0..8024BEA8` (264 bytes), as ordinary C++.

Scans owner handles at offset 0x28, validates each through the existing checked resolver, compares the resolved type identity at offset zero, and returns a retaining copy of the first matching handle. The fallback constructs the native empty handle with both inline null initialization layers. The recovered inline handle hierarchy preserves the native base-constructor ABI, local address assignment and reference retention. The signed 24-bit index and signed 8-bit generation lookup retains native behavior. External globals and helpers keep their original ownership.

Run `python3 scratch/game_owner_identity_handle_find/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce all 264 retained bytes after applying the actual ELF relocations. Every function extent, allocated byte and real relocation site, kind, symbol, addend and target is checked. Unreferenced weak bodies are fully accounted and fingerprinted; nonallocated compiler metadata relocations are also checked. The protected original DOL hash and original extabindex, `.ctors` and `.dtors` ownership audits pass for this range. No owned data, BSS or padding are emitted.

The compiler emits 1 unused weak destructor backup(s), totaling 84 bytes: `__dt__24IdentityFindNativeHandleFv` (84 bytes). These receive no credit and must be absent from the final ELF. The retained function has no relocation to them. Central integration must verify their absence, the original full DOL hash, native objdiff, source extents and regressions.

This partial text-only split leaves neighboring functions and original data external. No new symbols, shared headers or special flags are needed. Source and evidence are frozen after handoff.
