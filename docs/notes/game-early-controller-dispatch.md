# Early controller dispatch

Frozen isolated ordinary C++ pair, 2026-10-11; central integration pending. New `include/Game/early_controller_dispatch_views.h` has two verified consumers. Standard GC1.3.2 plus `-O4,s` and `-Cpp_exceptions on` for both.

| Source | Function | Text extent | Bytes | extab | extabindex |
| --- | --- | --- | ---: | --- | --- |
| early_controller_deactivate_8006311c.cpp | fn_8006311C | 8006311C..80063290 | 372 | 8000B5FC..8000B604 | 800186A8..800186B4 |
| early_controller_start_80064470.cpp | fn_80064470 | 80064470..800644FC | 140 | 8000B75C..8000B764 | 8001872C..80018738 |

Deactivate first updates the embedded script/controller region@90 and calls fn_8002B820. When signed registered@1ED equals one, it resolves resource@1F4 and invokes its genuine virtual slot0x34, resolves the same handle again for fn_802139D8, and clears low-word flag0x8000 in the64-bit flags@38. It gets another handle through native virtual slot0x130 and resolves that for fn_8009FD38; an exact signed-byte result of one triggers fn_80069218 on the embedded region with argument three.

Start obtains the handle through native virtual slot0x130, resolves it, and forwards the index to the accepted fn_8007D6A0 at resolved-object offset0x318. Native behavior assumes resolvable objects before these member accesses; no extra null checks were introduced.

Combined: **512 text +40 EH/index =552 allocated bytes**. Strict per-function verification recompiles production source and covers all original allocated bytes, ten text/four EH-index actual relocations, two nonallocated metadata refs, actual local EH identities/extents, and complete original extabindex/ctors/dtors ownership. No helpers/data/BSS/padding emitted or claimed. Original SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Manifest list `scratch/game_early_controller_dispatch/manifest-list.json`. Production sources/header/evidence/verifiers are frozen.

Adjacent fn800648C0 (388-byte current-owner action notification) remains private/uncredited. Direct, captured, inline helper, explicit conditional, and raw/void/byte-manager variants all emit384bytes with the same missing repeated entry-array load and register scheduling differences. Preserved private namespace and probe JSON document this bounded result; existing sources/metadata remain untouched.
