# Early context startup and dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three isolated ordinary C++ functions match592 bytes of text plus60 original EH/index bytes usingGC1.3.2 with `-O4,s -Cpp_exceptions on`.

| Function | Text | extab | extabindex | Actual retained relocations |
|---|---:|---|---|---:|
| fn_8007EF60 |200|8000D6F8..8000D700|80019A1C..80019A28|19|
| fn_8007F33C |160|8000D708..8000D710|80019A34..80019A40|11|
| fn_8007F8A8 |232|8000D7D0..8000D7D8|80019A88..80019A94|5|

EF60 resets the original singleton, allocates and initializes its replacement, then validates the logger mode and binds the logger device. Its original allocation tag, source filename and error string remain in the existing external pool at8029D05C,8029D2C0 and8029D2CC. `borrowed_data.json` records each original NUL-terminated string and its displacement from the existing registry base8029CD70. There is no new string allocation or data label. F33C logs shutdown, deletes the context's scene and input objects through their virtual destructors, and clears both pointers. F8A8 resolves the handle returned by virtual slot37 and either forwards to the original update routine or calls virtual slot45 according to flag0x10000. The floating argument is a double; that preserves the original single stfd save rather than adding a paired-single save.

Production sources are `src/Game/early_context_startup_8007ef60.cpp`, `early_context_startup_8007f33c.cpp`, and `early_context_startup_8007f8a8.cpp`; their dedicated declarations are in `include/Game/early_context_startup_views.h`. Every referenced function and external allocation remains under its existing identity. No weak functions, data/BSS allocations, padding, aliases or native identity migrations are introduced. Each source emits only one function and its actual compiler-local EH/index objects.

Frozen manifests: `scratch/game_engine_batch105/manifest-list.json`. Production verifiers account for all allocated bytes and real relocations, compare every relocated byte to the original normalized DOL, and scan complete original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0. They retain each original EH owner and find no constructor/destructor slot. Central full-DOL acceptance remains pending. This is a partial text reconstruction; neighboring functions, strings and the broader original translation unit remain external. Private fn8007EE70 initializer near-matches are preserved and excluded.
