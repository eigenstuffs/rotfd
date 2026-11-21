# Lower Objects constructor

`src/Game/objects_owner_constructor.cpp` reconstructs the native constructor at
`80213D44..80213E58`: **276 code bytes and 15 real relocations**, with zero
isolated byte differences. The source is integrated and exact in the full build.

The address-qualified C++ class `ObjectsOwner_80213D44` corresponds to the
runtime `Activable` class. The registration hierarchy is `BaseObject` →
`Activable` → `Manipulator`, and accepted concrete Manipulator factories call
the next constructor at `80213EBC`. These registrations support the semantic
names, without proving the original C++ spelling or translation-unit boundary.

The native Root base occupies 12 bytes. One-layer handle members at `+0C` and
`+10` are constructed, assigned empty temporary handles, and retained through
the existing manager. Subsequent list code identifies these as previous and
next links. The constructor clears the signed activation byte at `+18` and
sets the word at `+14` to 9. The complete observed lower prefix is `0x1C` bytes.

The constructor now includes the shared native interface in
`objects_owner_internal.h`. Its table reference resolves to the genuine
44-byte table emitted by the integrated destructor unit at
`802EB1D0..802EB1FC`; this constructor still owns no data. The four original
zero bytes through `802EB200` remain explicit fallback with no source credit.
The compiler emits an unreferenced 84-byte weak handle destructor with two
relocations; ordinary dead stripping excludes it.

Earlier work left the coarse 48-byte original table wholly external while its
last word was unresolved. The subsequent native-interface proof emitted only
44 bytes without a synthetic virtual slot, preserving all 276 constructor
bytes. The previous source view and comparison inputs remain under
`scratch/game_activable_interface/before_objects_owner_constructor.cpp` and
`accepted_input_hashes.json`; the [interface note](game-activable-interface.md)
records the coordinated change.

Verify with `python3 scratch/game_objects_owner_constructor/verify.py`. The
verifier enumerates all functions and allocated sections, checks strong/weak
bindings, resolves all retained relocations, checks section alignment and
compares every retained byte against the protected original DOL. The candidate
and fresh verification JSON record hashes and accounting. No assembly, patched
object code, or relocation masking is used.
Current original-target assembly is
`build/GSQE78/asm/Game/objects_owner_constructor.s`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 276/276 code bytes and one exact function,
with zero owned data. The source-section extent guard and generated progress
checks pass; the documented baseline accounting corrections remain preserved.
