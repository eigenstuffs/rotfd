# Registry retain-and-return operation at 801F84D4

Status: integrated exact C++ reconstruction. The source `src/Game/handle_retain.cpp` owns the strong global function `fn_801F84D4` at `801F84D4..801F86C8`: 500 code bytes. It emits no initialized data, BSS, metadata, weak helper functions or padding.

The routine decodes the packed signed 8-bit generation and signed 24-bit index, validates the index against the registry count and compares the generation, then increments the record's signed 16-bit reference count. If the increment becomes zero and the manager's automatic-release byte is nonzero, it validates the handle again and releases the record. Every path returns the original packed handle word, including failed validation. The original does not separately reject a negative index; that behavior is preserved.

The release path uses the manager virtual method at vtable offset `10` to detach the object's identity at object offset four. It clears the record flags, sets its short link to minus one, deletes the object through its virtual destructor if present, replaces the name hash with the shared empty-name hash, resets references, advances the generation while skipping zero, clears the object pointer, and appends the index to the free-index array. The manager layout preserves its vptr at `24`, 16-byte registry records, free-index pointer at `14`, free count at `1C` and automatic-release byte at `20`.

The private reconstruction builds on the independently verified adjacent `handle_reference.cpp` source and its original-instruction evidence. The generic byte-indexed field accessor preserves the observed table reloads. The skip-zero generation access uses `field<Entry>(index, 0).generation`, allowing the compiler to reuse the same unsigned 16-byte record stride. A direct `entries[index].generation` variant emitted an additional scale instruction and was 504 bytes; it is retained as private research in `scratch/game_handle_retain/retain_504.cpp`. Capturing `int slot = freeCount++` before writing `freeIndices[slot]` preserves the original free-count store before the pointer reload.

The empty-name literal beginning at `lbl_8037A820` is declared as an external one-byte character array, reflecting the observed leading NUL and its original SDA reference. Its storage remains entirely external and receives no source credit. The only two ELF relocations are that SDA reference and the branch to `fn_801F948C`. Both are applied at their genuine original addresses before comparison.

Verification uses GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`. Run `python3 scratch/game_handle_retain/verify.py`. The production-source probe passes: all 500 text bytes, both relocations, exact function size and strong binding, and every allocated section agree with the original DOL whose SHA-1 is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. The verifier rejects unexpected allocated sections or helper tails. The handoff candidate is `config/GSQE78/candidates/game_handle_retain.json`.

No existing source or shared header was changed. Central integration also includes the adjacent reference-count updater.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 500/500 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
