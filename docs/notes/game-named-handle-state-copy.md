# Named handle state and record-array copy

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/named_handle_state_copy.cpp` reconstructs `fn_8024906C`,484 bytes at `8024906C..80249250`, using ordinary C++ and genuine native handle construction/destruction.

It looks up a named resource, retains the resulting output handle, resolves an owned temporary and the assigned handle, copies four float values and the owner's key, then invokes the two original record-array transfer helpers on members30 and24. The lookup copy uses one zero-initializing derived handle layer; the resolver temporary uses three. Their compiler-generated lifetime schedule reproduces the original calls and temporary stack slots.

`python3 scratch/game_named_handle_state_copy/verify.py` passes all484 retained original bytes and17 actual retained relocations. All932 emitted allocated bytes are accounted:484 retained text and five unreferenced weak destructor backups totaling448 bytes. Each helper's raw bytes and all10 unlinked relocations are inventoried, and no retained instruction refers to them. All five helpers must be absent from the final ELF.

No initialized data, BSS, padding or original exception/constructor/destructor entries belong to this partial text split. The strict proof checks the original DOL SHA1 and the complete original ownership tables. External literals and related resource functions remain outside it. The source and isolated evidence are frozen; central full-DOL/regression acceptance is separate.
