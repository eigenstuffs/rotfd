# Mapped handle matrix copy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/mapped_handle_matrix_copy.cpp` reconstructs `fn_8024BFB4`, original `.text` range `8024BFB4..8024C138` (388 bytes), as ordinary C++.

The function maps the incoming index through the external context map at 0x144 (index array at 0x94), selects the owner's handle at offset 0x28, makes a retaining local handle copy, and resolves its signed index/generation through the external manager. It returns false when that handle resolves to null; otherwise it copies the complete 64-byte matrix pointed to at resolved object offset 0x124 and returns true. Both paths run the original base handle destructor. The native hierarchy has an inline null-handle constructor between the external base constructor and retaining copy constructor. Recovering this layer preserves the original local handle address and argument schedule; a flat wrapper lost eight bytes.

Run `python3 scratch/game_mapped_handle_matrix_copy/verify.py`. Standard optimized GC/1.3.2 Game flags reproduce all 388 retained bytes after applying real relocations. The verifier checks every function extent, every emitted allocated byte, and all real relocation sites/kinds/symbols/addends/targets, including unused weak bodies and nonallocated compiler metadata. It audits the protected original DOL SHA-1 and original extabindex, `.ctors` and `.dtors` ownership; none overlap or reference the retained range. All external data and helpers retain their original ownership. No owned data, BSS or padding are emitted.

The compiler additionally emits two unreferenced weak destructor backups (88 and 84 bytes). These 172 bytes are fully accounted and fingerprinted in `emission_reference.json`, receive no source credit, and must be absent from the final ELF. The retained function has no relocation into either tail. `actual_relocations.json` separates retained, discarded weak and nonallocated metadata relocations. Central integration must verify helper absence along with the full DOL hash, native objdiff, source-extent and regression checks.

This is a partial text-only split. Neighboring functions, original tables and data remain external. No new symbols, shared headers or special flags are needed. Source and verification evidence are frozen after handoff.
