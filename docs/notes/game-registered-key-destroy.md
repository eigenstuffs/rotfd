# Registered-key owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

**Accepted matching source.** The production object passes strict byte and
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/registered_key_destroy.cpp` reconstructs `fn_8026E834`, original `.text` range
`8026E834..8026E8D4` (160 bytes). This ordinary C++ reconstruction passes full executable acceptance.

The partial owner installs its original table at offset 8 and reads the registry pointer from the external global at offset 0x180. When that registry exists and the key at owner offset 0x34 is not -1, it copies the key to a local and passes the local address to the original removal routine. It then resets the key, calls base cleanup and optionally deletes the owner. The stack local reproduces the native argument location.

Run `python3 scratch/game_registered_key_destroy/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 160 emitted text bytes, the original global symbol
and 9 actual relocations. The verifier checks every allocated
byte and exact relocation site, kind, symbol and addend against the protected
original DOL. There are no other allocated sections, weak helpers, initialized
data, BSS or owned padding. Candidate, actual-relocation and original-metadata
JSON files preserve source/header/object hashes and the evidence.

The original extabindex, `.ctors` and `.dtors` audit finds no overlapping
exception entry or table reference into the retained range. Referenced tables,
allocators, base/member cleanup routines, global storage and neighboring
functions remain externally owned. This is a partial text-only split, not a
claim that the complete original translation unit has been recovered. The
integrator must still run the complete DOL hash, native objdiff, source-extent
and regression checks. No special flags, new symbol names or owned-data ranges
are needed.

The base lifetime now uses the genuine compiler destructor __dt__19CallbackRecordOwnerFv
at the original address. Only the external call spelling changed; fresh
isolated and production checks preserve every allocated byte, function
extent and actual relocation. Full original-hash and baseline checks pass.
Previous source, manifests and verifier evidence are preserved in
`scratch/continuation_20261010/record-owner-lifetimes-caller-history/`.
