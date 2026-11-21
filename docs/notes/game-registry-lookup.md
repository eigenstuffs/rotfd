# Game registry lookup and cleanup

Eleven ordinary C++ routines are reconstructed and verified as six partial source units. Original class names and the complete original translation-unit extent are not claimed.

| Source | Text range | Functions | Code bytes | Relocations |
|---|---|---:|---:|---:|
| `src/Game/registry_shutdown.cpp` | `801F50B0..801F50E8` | 1 | 56 | 2 |
| `src/Game/registry_destructor.cpp` | `801F5944..801F5C04` | 1 | 704 | 20 |
| `src/Game/registry_lookup.cpp` | `801F5C04..801F5CA4` | 1 | 160 | 5 |
| `src/Game/registry_cleanup.cpp` | `801F5E14..801F6038` | 2 | 548 | 15 |
| `src/Game/registry_slots.cpp` | `801F6038..801F6624` | 2 | 1,516 | 58 |
| `src/Game/registry_bindings.cpp` | `801F6624..801F694C` | 4 | 808 | 31 |

All six isolated objects contain only the claimed `.text` section. Every byte matches the unchanged original DOL after applying all relocations. Compiler: GC/1.3.2, `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on -bool off`. Manifests are `config/GSQE78/candidates/game_registry_lookup.json` `game_registry_cleanup.json`, `game_registry_destructor.json`, `game_registry_shutdown.json`, `game_registry_slots.json`, and `game_registry_bindings.json`. All six units pass the central full-DOL SHA-1 and complete native objdiff verification.

`801F50B0` invokes registry cleanup and the observed shutdown hook, then returns true.

`801F5944` runs the observed virtual cleanup method, unregisters the object, destroys its nested handle pool and four arrays, then calls its base destructor. The typed array destructor emits the original empty primitive-destruction loops and duplicate null checks naturally. The original signed 16-bit deleting-destructor flag is retained.

`801F5C04` constructs an integer hash key, searches the selected table, and initializes a four-byte handle from the found value. A failed lookup clears both its 24-bit payload and its leading type byte. Ordinary C++ bitfields reproduce the original read/insert/store sequence.

`801F5E14` iterates occupied registry tables and calls the observed virtual method at vtable offset `0x1C` for each resolved object. The transient handle is initialized, resolved and destroyed before the object call. Declaring the resolved object pointer before a nested handle scope preserves its lifetime through destruction and emits the original `r3 -> r0 -> r27` copies. Moving this entire sequence into an inline helper or relying on an automatic temporary destructor changes register allocation or instruction scheduling. The source retains explicit calls to the recovered handle constructor and destructor in that scope. Its object uses a real C++ virtual declaration with an eight-byte observed prefix; no function-pointer dispatch substitute is used.

`801F5F28` searches paired values in occupied slots. The output index is a signed `long`, while pool sizes and accessor indices are `int`. This type boundary preserves the original loop reload. Inline equality and array-reference accessors preserve the original comparison register allocation. If requested, the routine creates three synchronized entries when no pair is found and still returns false; that original return behavior is retained.

`801F6038` and `801F6330` find a free slot or grow the pool by 32 elements. The flag array stores its bit count as a signed `long`; its resize argument and array sizes are `int`. Checking the argument before resizing from the stored field preserves the original repeated field load and nested size checks. The empty construction/destruction loops of the flag words are emitted by the same array template, not written as synthetic delay loops. Hash-table slots are placement-constructed on reuse; value slots use ordinary assignment on reuse and placement copy construction only when appended. Both original behaviors are retained.

`801F6624..801F694C` contains four further binding operations: release objects for a selected pair, resolve serialized handles for that pair, deserialize integer-key entries from a cursor, and clear each occupied hash table. The same four-byte handle lifetime and typed virtual interface reproduce all four routines without further compiler adjustments. All external calls and original return behavior are preserved.

## Remaining neighboring work

The neighboring pool destructors at `801F551C` and `801F56A8` are recovered semantically in `scratch/game_file_io/destructors_2.cpp` but remain fallback. The current objects are 400 versus 396 bytes and 660 versus 668 bytes respectively; unresolved differences involve inlined destructor null checks, bit-word reloads and register allocation.

The removal routine at `801F5CA4..801F5E14` remains original fallback. Its behavior is understood, but the current source still differs in bit-test normalization, repeated word loads and saved-index allocation. Durable probes are `scratch/game_file_io/lookup*.cpp` and `probe_lookup*.py`; `lookup13_1.cpp` currently has the correct 368-byte size but 85 differing bytes. This candidate is not represented as matching source.

The registry constructor at `801F50E8` remains fallback. `scratch/game_file_io/registry_ctor.cpp` recovers its complete initialization sequence at 1,068 bytes versus the original 1,076. Two base/derived `this` copies and the associated base initialization register remain unresolved. GC/1.3, GC/1.3.2r and GC/2.0 do not change the result; `-O4,s` shortens it to 1,044 bytes. The preceding 56-byte cleanup wrapper at `801F50B0` is independently verified and promoted as `registry_shutdown.cpp`.

Verification can be repeated with `python3 scratch/game_file_io/verify.py registry_lookup` `registry_cleanup`, `registry_destructor`, `registry_shutdown`, `registry_slots`, and `registry_bindings` after compiling their current source. Those commands regenerate only candidate manifests; they do not edit central configuration or the original executable. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
