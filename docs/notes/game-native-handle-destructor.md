# Native handle destructor at 801F7F10

Status: integrated exact C++ reconstruction. `src/Game/native_handle_destructor.cpp` recovers the strong global C++ destructor `__dt__15Handle_801F7F10Fv` at `801F7F10..801F8114`, totaling 516 code bytes. All seven real relocations match. There is no source-owned data, BSS, metadata, padding or extra generated helper code.

The native packed handle uses a signed 8-bit generation and signed 24-bit index. Its destructor decrements the corresponding registry record's signed 16-bit reference count. A valid record whose count becomes zero is automatically released when the manager's signed-byte automatic-release setting is nonzero. That release detaches the object's identity, clears record flags and linkage, invokes virtual deletion when appropriate, resets its name and references, advances the generation while skipping zero, clears the object pointer and pushes its index onto the free-index array. The ordinary C++ destructor also generates the original null-this check and destruction-flag test. A positive destruction flag calls the class-specific deallocator, which forwards the handle storage to the existing allocator at `lbl_801EF5C8` through `fn_801EF610`.

The release implementation and private registry layout were independently recovered in the adjacent retain/reference-count operations. Byte-indexed field access preserves the record reloads, `field<Entry>(index, 0).generation` preserves the reused 16-byte stride in the skip-zero step, and an explicit free-list slot local preserves the free-count store before the array-pointer reload. Those portions were already exact before the final destructor investigation.

The remaining six-byte discrepancy was solely the initial index/generation register allocation. Introducing the ordinary const accessor `int getIndex() const { return index; }` on the handle, and using `handle.getIndex()` inside the inlined `Manager::adjust`, fixes the original r6/r7 allocation without changing any other instruction. The release path retains its direct index access. No extra generation accessor is needed. The earlier six-byte form and seven-byte declaration-order form are preserved under `scratch/game_native_handle_destructor` for research. No register binding, inline assembly, byte masking, compiler-flag sweep, or artificial padding was introduced.

The seven relocations refer to the existing engine globals, native allocator, allocator free routine, shared empty-name prefix at `lbl_8037A820`, and name-hash routine. All referenced storage remains external and uncredited. The one-byte declaration for the empty-name prefix accurately models the original leading NUL and SDA access without taking ownership of its surrounding original literal pool.

Run `python3 scratch/game_native_handle_destructor/verify.py`. It recompiles the production source with GC/1.3.2 and `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`. It checks the original DOL SHA-1, exact strong function identity and size, every allocated section, and all real ELF relocations; unexpected allocated sections or helper tails are rejected. The final production probe passes with zero differences across all 516 bytes and seven relocations. The manifest is `config/GSQE78/candidates/game_native_handle_destructor.json`.

The reconstruction uses private source views. Existing shared headers are unchanged; central integration is verified below.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 516/516 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
