# Transform record append at 801C3B2C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ source src/Game/transform_record_append_801C3B2C.cpp exactly reconstructs the452-byte function at801C3B2C..801C3CF0. Production and fresh strict verification pass all allocated bytes and12actual relocations. Only the GLOBAL .text primary is emitted; full original-placement/DOL acceptance remains pending with root.

This captures a related transform position and matrix-derived quaternion with the current time, grows an original32-byte-record array by64 entries, and placement-copies the complete snapshot. The allocator's allocate/resize/free branches, count update and null placement behavior are preserved. No new constructor identity or shared declarations are introduced.

The earlier13 released private probes in game_engine_record_stream_more_continuation declared fn801F1E78 as returning a Quaternion by value, retaining extra spills/lifetimes. They remain unchanged and hash-inventoried. Existing accepted consumers establish its output-pointer ABI. Writing directly into record.rotation closes the extent and all but six words; Transform::getPosition() returning Vec3 by value closes the native three-float load/store order. The fresh exact source uses ordinary C++ getters, scalar field copies and placement construction, without assembly, register forcing or qualifiers introduced for matching.

Original full extabindex80015F60..8001F2C0 (including terminal descriptor), ctors80299920..80299980 and dtors80299980..802999A0 ownership audits find no entries. No EH, weak backups, owned data/BSS, padding, aliases or identifier migrations occur. All original dependencies and callback-containing data remain external.

The stable full active-original audit scans5641objects,119086 actual relocations and777360 initialized words: sole GLOBAL452, one callback relocation and initialized pointer, no direct calls, overlapping text owners or source consumers. Actual isolated MWLD retains the primary with all12real relocations applied exactly and no extra source allocations; wrong primary extent is rejected. Frozen handoff: scratch/game_engine_batch284/.
