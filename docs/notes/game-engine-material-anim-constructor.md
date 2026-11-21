# Material animation construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_material_anim_ctor.cpp` reconstructs all464 bytes of the original
constructor at `8023A40C..8023A5DC`. The existing factory identifies
`MaterialAnim_Z.h` and allocation sizeBC. The recovered native entry is
`__ct__21MaterialAnim_802EC000Fv`; its external32-byte table keeps its original
address and owner under `__vt__21MaterialAnim_802EC000`.

Genuine Root/Resource construction preserves the original base alias. Ten
16-byte curve members at10..A0 call the accepted native CurveBase constructor
and clear their three storage words. Six middle curves also set their type to
two. A two-zero native handle atB8 precedes the final two float and flag writes.
The first ordinary source probe reproduced every retained instruction; private
curve destructor declarations leave their definitions and original data owners
outside this constructor fragment.

`scratch/engine_material_anim_ctor_20261010cd/verify.py` verifies all464 retained
bytes, function binding/extent and17 actual relocations with standard GC/1.3.2
flags. Two unused weak handle destructor backups account for172 additional
bytes and four relocations, with no retained reference. There are no other
allocated sections or owned data/BSS/padding/EH/startup bytes. Full original raw
extabindex, ctors and dtors audits include descriptors and zero tails and have
no references to the extent.

Only initial-snapshot `src/Game/factories_8020AC68.cpp` calls the old function
identity; no existing source/header references the old table identity. Root
owns untouched initial snapshots, full original consumer copies, the narrowly
permitted identifier replacement and recompilation proof that every allocated
byte and resolved target remains unchanged. This agent edits no consumer or
central metadata. The frozen manifest retains every original_symbol guard;
no alias/thunk is proposed. Central NonMatching registration and full original
DOL hash/regression/native allocation acceptance remain the final gate.
