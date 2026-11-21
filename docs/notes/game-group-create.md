# Hierarchy group creation

`src/Game/group_create.cpp` reconstructs `fn_801FF4F8` at `0x801FF4F8..0x801FF834`: one 828-byte retained function. Strict isolated verification passes after applying all 27 retained relocations. Full-DOL and native objdiff acceptance pass as recorded below. The original complete translation-unit and class names remain unknown.

The method takes the group collection, a borrowed world handle, a name, element count, shared-width mode, and camera-type hash. It searches for a hierarchy whose valid owner handle resolves to the same object as the supplied world. If one is already present, it returns without creating anything. This search compares resolved object pointers, rather than packed handle words.

For an absent world, it creates a `Game` object with the original `AddGame` name, retains the returned native handle, and appends a reference-counted copy to the collection. The array grows capacity by eight using the existing allocator helpers, then placement-constructs the new element and increments its count. It copies the world's name hash to the new group through `fn_802072D4`, sets the owner/name with `fn_80203890`, passes the count/mode/camera type to `fn_80202A18`, and finishes with `fn_801FDD60`. The scoped creation handle is released on return. There are no added validity or allocation guards beyond those emitted by the original source behavior.

## Compiler and lifetime evidence

GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` reproduces the function. The returned value from `fn_801B550C` uses the real native hidden-return-pointer ABI and is destroyed with flag -1. The retained wrapper and array element use actual C++ copy constructors, each calling the native base constructor and incrementing the referenced source handle. These copies have no inherited zero layer, matching the original stores.

Two source distinctions reproduce the original allocation: explicit `if`/return structure in both typed resolvers, and a placement-new storage pointer written as `void* slot = data + count++; new(slot) T(h);`. A typed `T*` local left a three-instruction register difference. The void storage pointer is ordinary placement-construction source; no register bindings, instruction patches, or address aliases are used.

## Retained-section proof

Run `python3 scratch/game_group_create/verify.py`. It verifies the protected original DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`, applies real ELF relocations, and compares every retained byte without masks. `verification.json` records zero differences and source/object hashes.

The compiler emits only `.text`, totaling 912 allocated bytes. The first 828 bytes are the retained function; one unreferenced weak `GroupHandle` destructor occupies object offset `0x33C..0x390` (84 bytes) and owns two additional relocations. No retained relocation targets that body. The verifier checks its weak binding and exact extent, plus contiguous coverage of every emitted text byte. Ordinary linker dead stripping excludes this body from matching-source credit.

No data, BSS, exception table, or trailing padding is owned. `AddGame` at `0x8037A8C8` (eight bytes) and `Game` at `0x8037A8D0` (five bytes) remain external original strings. Their following original padding is not claimed.

The manifest is `config/GSQE78/candidates/game-group-create.json`. Earlier near-matching hierarchy setup source remains separate and is not credited by this exact caller.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 828/828 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
