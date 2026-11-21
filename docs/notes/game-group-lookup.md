# Group lookup by resolved object identity

`src/Game/group_lookup.cpp` reconstructs the 192-byte lookup at `0x801FF18C..0x801FF24C`. The strict verifier `scratch/game_selection_callbacks/verify_lookup.py` checks the entire allocated text section, section alignment and both applied ELF relocations. GC/1.3.2 with `-O4,p -inline deferred -use_lmw_stmw on` produces an exact match. No data is owned; whole-DOL byte equality, native objdiff checks and the original-source regression audit pass.

The function returns the first matching index in the count/capacity/data list at `+0x14`, or `-1`. Both handles resolve through the same 16-byte manager entry layout, using a signed 24-bit index and signed eight-bit generation comparison. Equality compares resolved pointers, so two generation mismatches resolve to equal null pointers; the reconstruction preserves that behavior. A local manager pointer within the inline equality helper reproduces the original manager/table/register reuse. The original class and method names remain unestablished.

The adjacent selection callbacks at `0x801FEE10` and `0x801FEF6C` are preserved in `scratch/game_selection_callbacks/near-match.cpp` but remain uncredited. Their 348- and 544-byte emitted sizes match; respectively 55 and 24 register/scheduling bytes still differ. Their list traversal, integer allocation arithmetic, repeated handle initialization stores and callback roles are recorded by the source and original disassembly. No original instruction or data byte was altered.

The protected DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The registered source passes complete DOL SHA-1 and byte equality, native objdiff source checks, and the preserved original-source regression audit.
