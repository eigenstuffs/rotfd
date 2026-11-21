# Registered-key owner initialization

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/registered_key_init.cpp` reconstructs `fn_8026E8D4`, original `.text`
range `8026E8D4..8026E940` (108 bytes). This ordinary C++ reconstruction passes full executable acceptance.

The partial owner calls its original base initializer, installs the original table at offset 8 and sets the key at offset 0x34 to -1. If the global registry pointer at offset 0x180 exists, it calls the original slot acquisition routine with argument 1 and stores the returned local key. The explicit output-pointer declaration records the observed native result ABI without claiming the complete registry value type.

Run `python3 scratch/game_registered_key_init/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 108 emitted text bytes, the original global symbol and
6 actual relocations. Every allocated byte and exact relocation
site, kind, symbol and addend is checked against the protected original DOL.
No weak helpers, other allocated sections, initialized data, BSS or padding
are emitted. Candidate, actual-relocation and original-metadata JSON preserve
source/header/object hashes, external dependencies and the evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Original tables,
global storage, runtime helpers, native initialization/reference operations and
neighboring functions remain externally owned. This partial text-only split
does not claim a complete original translation unit. Central integration must
still pass the complete DOL hash, native objdiff, source-extent and regression
checks. No special flags, new symbols or owned-data ranges are required.

The base lifetime now uses the genuine compiler constructor __ct__19CallbackRecordOwnerFv
at the original address. Only the external call spelling changed; fresh
isolated and production checks preserve every allocated byte, function
extent and actual relocation. Full original-hash and baseline checks pass.
Previous source, manifests and verifier evidence are preserved in
`scratch/continuation_20261010/record-owner-lifetimes-caller-history/`.
