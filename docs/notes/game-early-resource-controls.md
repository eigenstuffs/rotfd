# Early resource controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The two partial source units reconstruct `fn_8006219C` and `fn_800622CC`, 304 bytes each, using GC/1.3.2 with `-O4,s -Cpp_exceptions on`. Each retains an 80-byte exception record and its 12-byte index. Isolated strict checks prove 608 text bytes and 184 retained exception/index bytes, with actual relocations applied to the original DOL addresses. Full native-link acceptance remains with the central integrator.

Each routine first checks a distinct bit in the owner's 64-bit flags at offset 0x38 (bits 17 and 18). When clear, it copies and retains the handle at 0x1F4, tests the native validity function, and destroys that temporary before the next condition. If valid, a second copied temporary resolves the resource and invokes `fn_802139D8` or `fn_80213A18`, then releases the temporary. A separate local signed-char validity result reproduces the native full-expression lifetime; combining the flag and temporary test in one `&&` expression introduces extra conditional-cleanup state.

The source expresses the two clearing layers and copy-retain layer as genuine C++ Handle classes. The retained exception records refer to the compiler's defined weak `Handle_80021BCC` and `Handle_80021B54` destructors. The bounded adopted audit recompiles and verifies the accepted strong owners at 0x80021BCC and 0x80021B54, resolves all four retained EH references per unit to those original strong definitions, and compares all retained initialized bytes. The actual compiler-local EH/index names and extents are inventoried.

Every emitted allocated byte is accounted for. Per unit, three trailing weak destructors total 348 text bytes and have 156 bytes of backup exception/index records. These receive no matching credit and must be discarded by the final native link. Their original identities are Handle_80021B54, Handle_80021BCC, and Handle_80021C40. All 16 retained and 21 unlinked actual relocations, plus four nonallocated compiler-category references per unit, are frozen in the evidence. There are no literal, BSS, constructor-array, destructor-array, or padding allocations.

Original table audits cover extabindex 0x80015F60..0x8001F2C0, constructors 0x80299920..0x80299980, and destructors 0x80299980..0x802999A0. Each original function has exactly the retained exception/index entry and no startup/shutdown pointer. This is partial ownership, not a claim to recover the surrounding original translation unit.

Frozen manifests: `scratch/game_early_resource_controls/manifest-list.json`. Batch handoff: `scratch/game_engine_batch85/HANDOFF.md`. The earlier position-copy probes at 0x80061064 and 0x80061610 remain private and uncredited in `scratch/game_early_owner_position`.
