# Object word update and list notification

`src/Game/objects_owner_mode.cpp` reconstructs `fn_80213920` at
`80213920..802139D8`: **184 code bytes and 11 actual relocations**, with zero
isolated byte differences. The source is integrated and exact in the full build.

The function compares its incoming 32-bit value with the object's word at
`+14`. Equal values leave the object unchanged. Otherwise it stores the new
value, borrows the object's identity at `+04`, converts it through two retained
handle views and notifies `fn_80212FC4` on the engine list at globals `+138`.
The temporary handles are destroyed in their original order. The word's domain
meaning remains uncertain; `mode` is a descriptive argument name rather than
an established enumeration. Its constructor default is 9.

The same borrowed identity accessor and conversion model also reproduces the
adjacent object destructor and list append routine. No data or padding is
owned. Two unreferenced weak handle destructors (168 bytes, four relocations)
are excluded by normal dead stripping.

Run `python3 scratch/game_objects_owner_mode/verify.py` for a fresh compiler and
relocation-aware check. All retained bytes, function identities/bindings,
allocated sections, weak-body references and section alignment are checked
against the protected original DOL.
Current original-target assembly is
`build/GSQE78/asm/Game/objects_owner_mode.s`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 184/184 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass; the documented baseline accounting corrections remain preserved.
