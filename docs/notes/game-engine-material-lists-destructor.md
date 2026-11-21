# Material animation list destructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source in `src/Game/engine_material_lists_destructor.cpp` matches fn80239D30 at `80239D30..8023A40C`, all 1,756 retained text bytes. GC 1.3.2 with the default Game flags emits one strong function and no other allocated section or helper. All 50 actual relocations resolve to their original targets. Production executable acceptance remains with the root integrator.

The retained entry installs the existing MaterialAnim table, destroys its two-layer handle at B8 and then destroys ten curve members in reverse order, A0 through10. Each curve derives from the existing four-byte CurveBase and owns an array at offset04. Curves A0,90,80,70 and40 have eight-byte empty elements; curves60 and50 have sixteen-byte empty elements; curves30 and20 have twelve-byte empty elements. Their ordinary inline element destructors reproduce the original count loops and compiler unrolling. The first curve has eight-byte key records whose native handle member at offset04 requires real destruction. Array cleanup calls the existing allocator with capacity times the element size, then destroys each CurveBase. Finally the entry installs the existing Resource table, calls the existing Root destructor with flag zero, conditionally frees the object for a positive signed-short flag, and returns its original pointer.

The dedicated header is a partial destruction view; the array element sizes and handle lifetimes are recovered, while their broader names remain uncertain. The accepted material constructor and its header are untouched. The entry and existing native dependency identities retain their names and addresses. No consumer, vtable or declaration migration is proposed.

The frozen manifest is `scratch/engine_material_lists_destructor_20261011ef/final_integration.json`. Its verifier recompiles production source, checks every allocated byte, exact symbol extent and actual relocation, and verifies frozen hashes. A complete audit of original extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, including descriptors, padding and terminators, finds no references into this retained range. There is no owned data, BSS, padding, exception table, startup allocation or weak backup.

This is a partial text split. All referenced native functions, vtables, global allocator objects, original translation-unit data and adjacent routines retain their existing owners. Central registration should begin NonMatching and be promoted after the full original DOL hash and standard acceptance checks pass.
