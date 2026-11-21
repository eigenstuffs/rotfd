# Owner list destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source in `src/Game/engine_owner_lists_destructor.cpp` matches fn8022D2B0 at `8022D2B0..8022D618`, all 872 retained text bytes. GC 1.3.2 with the default Game compiler flags produces one strong function and no other allocated section or helper. All 24 actual relocations resolve to their original targets. Production executable acceptance remains with the root integrator.

The retained entry installs the existing ObjectsBreak table, destroys the five arrays at offsets 1DC, 1D0, 1C4, 1B8 and 1AC, and destroys the handle at 1A8. Four-byte empty element views reproduce four arrays; the array at 1D0 has sixteen-byte empty elements. Their ordinary inline destructors preserve the original count loops, including the compiler's eight-iteration unrolling, both pointer checks and the repeated null store. Four derived handle layers reproduce the four original member null checks before the existing native handle destructor. The routine then installs the existing ObjectsBounce table, calls the existing ObjectsMove destructor with flag zero, conditionally frees the outer object for a positive signed-short flag and returns the original object pointer.

The dedicated header is a partial storage view. It retains the existing C entry identity and references the already named native tables and ObjectsMove/Handle destructors at their unchanged addresses. No vtable, function or consumer rename is proposed. The inline layer names express observed destruction depth; they do not establish the original derived handle class identities.

The frozen manifest is `scratch/engine_owner_lists_destructor_20261011ee/final_integration.json`. Its verifier recompiles the production source, compares every allocated byte, exact symbol extent and actual relocation, and checks frozen research hashes. The original table audit reads the complete extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, including descriptors, padding and terminators; none refers to this retained range. The source emits no initialized data, BSS, padding, exception table, startup allocation or weak backup.

This is a partial text split. All original tables, referenced globals, allocator functions, adjacent code and original translation-unit data retain their current owners. Central registration should begin as NonMatching and be promoted only after the full original DOL hash and standard acceptance checks pass.
