# Named handle lookup and key transfer

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/named_handle_key_transfer.cpp` reconstructs `fn_80248610`, 364 bytes at `80248610..8024877C`, as ordinary C++ using genuine native `Handle_801F7F10` construction and destruction.

The routine looks up a resource with the existing type-name literal and the owner's name hash, assigns a retained handle to its output argument, resolves a further retained temporary, and copies the owner's key at offsetC into the resolved object. The native lifetime schedule comes from one zero-initializing derived layer for the lookup copy and three zero-initializing layers for the resolver temporary. The lookup's raw returned handle uses the native standalone destructor, while the derived temporaries use the native base destruction path.

`python3 scratch/game_named_handle_key_transfer/verify.py` passes all364 retained original bytes and15 actual retained relocations. The object allocates only812 bytes of text:364 retained bytes plus five unreferenced weak inline destructor backups totaling448. Every emitted function, raw hash and relocation is inventoried; retained code never refers to these helpers. They must be absent from the final ELF. There is no owned data, BSS, padding, exception entry, constructor entry or destructor entry. The verifier checks the original DOL SHA1 and the complete original extabindex/ctors/dtors table ranges.

This is a partial text split; related object/resource functions and the external type-name literal remain outside it. The source and isolated evidence are frozen for central integration, whose full-DOL and regression acceptance remains separate.
