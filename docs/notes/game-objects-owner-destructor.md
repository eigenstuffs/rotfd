# Lower Objects destructor

`src/Game/objects_owner_destructor.cpp` reconstructs the native destructor at
`80213A58..80213B68`: **272 code bytes, 44 table bytes and 28 real relocations** (19 in code,
nine in the native table), with zero isolated byte differences. The source is
integrated and exact in the full build.

`ObjectsOwner_80213D44` is the address-qualified native identity for the runtime
Activable class. The shared interface now declares the destructor virtual,
and the compiler installs and emits its real virtual table naturally. Native
C++ member destruction, base destruction and class-specific `operator delete`
preserve every previously accepted instruction and cleanup operation.

When the engine list at globals `+138` exists, the object borrows its identity
through a reference accessor, constructs two successively retained handle
views, destroys the first temporary, and asks `fn_80212AA0` to unlink the second.
The remaining temporary then releases its reference. Finally, the two member
links at `+10` and `+0C` are destroyed, the Root base is destroyed, and positive
native deletion flags invoke the existing allocator.

A borrowed identity accessor is necessary to reproduce the original address
lifetime across the handle constructor call. A returned handle adds a helper
call, while direct field access lets the compiler eliminate that pointer
lifetime. These source variants remain in the private scratch directory.

The unit owns the genuine 44-byte table at `802EB1D0..802EB1FC`, naturally
aligned to eight, with two zero header words and nine function pointers.
Ordinary `-RTTI off` matches the observed table header. Four original zero
bytes at `802EB1FC..802EB200` remain fallback and receive no credit. No extra
null slot or raw function-pointer array is introduced. Two unreferenced
compiler-generated weak handle destructors (168 bytes, four relocations) are
discarded normally.

The first exact implementation used an explicit virtual-pointer ABI view and
owned only text. That source remains preserved as
`scratch/game_activable_interface/before_objects_owner_destructor.cpp`.
Replacing its explicit table assignment with the real virtual destructor
preserved all 272 code bytes; the [interface note](game-activable-interface.md)
describes the later coordinated proof and table ownership.

Verify with `python3 scratch/game_objects_owner_destructor/verify.py`. Every
retained instruction and relocation is checked against the original DOL;
function bindings, weak-body references, all allocated sections and alignment
are checked explicitly.
Current original-target assembly is
`build/GSQE78/asm/Game/objects_owner_destructor.s`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 272/272 code bytes and one exact function,
with all 44 owned table bytes exact. The source-section extent guard and generated progress
checks pass; the documented baseline accounting corrections remain preserved.
The native table extent is now verified independently of the original coarse
48-byte symbol; its four-byte trailing fallback remains uncredited.
