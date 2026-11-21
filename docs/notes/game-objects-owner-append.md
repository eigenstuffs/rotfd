# Append to the Activable object list

`src/Game/objects_owner_append.cpp` reconstructs native virtual override
`slot18__21ObjectsOwner_80213D44Fv` (original `fn_80213B68`) at
`80213B68..80213D44`: **476 code bytes and 19 real relocations**, with zero
isolated byte differences. The source is integrated and exact in the full build.

Engine globals `+138` reference a list whose first two handle words are head
and tail. The object fields `+0C` and `+10` are previous and next handles. The
function borrows the object's identity at `+04`, converts it through two
retained handle views, and appends it to this list. It sets the new object's
previous link to the current tail. If that tail resolves to null, including an
empty handle or stale generation, it assigns the head; otherwise it updates the
resolved old tail's next link. It then assigns the new tail. All assignments preserve the
original release/copy/retain operations and temporary destruction order.

Resolution compares the signed generation byte in a 16-byte manager entry
against the handle's generation. The ordinary accessor promotes that byte to
an `int`, preserving the original evaluation and register lifetimes. The new
node's handle is resolved and dereferenced without an additional validity guard.
The tail has the separate null-resolution test described above before accessing
its next link. The reconstructed source preserves both original behaviors.

The body now uses the shared native interface and is the lower table's
slot `18` override. Changing the former free-function view to this member
preserved all 476 code bytes and 19 relocation targets. The previous view is
retained in `scratch/game_activable_interface/before_objects_owner_append.cpp`;
see the [interface note](game-activable-interface.md) for the integrated table
and hook evidence. The list type used here is a borrowed head/tail prefix;
its full constructor/update view separately establishes the filter byte at
`+8` and total list size `0xC`. This append body allocates no list or object.

No data or padding is claimed by the append unit. Two unreferenced weak handle destructors (168
bytes and four relocations) remain outside retained source credit.

Verify with `python3 scratch/game_objects_owner_append/verify.py`. The verifier
checks all emitted functions/sections and their binding/alignment, applies the
actual relocations and compares every retained byte with the original DOL.
Compiler-generated weak bodies are enumerated and excluded only through normal
dead stripping. No patched instructions or masked comparisons are accepted.
Current original-target assembly is
`build/GSQE78/asm/Game/objects_owner_append.s`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 476/476 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass; the documented baseline accounting corrections remain preserved.
