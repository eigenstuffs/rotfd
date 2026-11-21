# Typed Handle zero constructor

Status: isolated production source exact; central integration pending.

`src/Game/engine_typed_zero_constructor.cpp` reconstructs the genuine `Handle_8001FF78::Handle_8001FF78()` entry, original `fn_8023F704`, `.text` range `8023F704..8023F73C` (56 bytes). It calls the existing native `Handle_801F7F10` constructor and clears the derived reference word. The recovered one-layer inheritance agrees with the already accepted `Handle_8001FF78` destructor. The production compiler is GC 1.3.2, ordinary Game `-O4,p` flags, exceptions off, with `-use_lmw_stmw on`.

The complete object owns exactly 56 bytes of text and one real REL24 relocation to the original native base constructor. It emits no weak functions, data, BSS, EH, startup entries, vtable, or padding. Complete original extabindex/ctors/dtors tables contain no references to this extent. Adjacent array/tree routines remain outside this source unit.

The proposed central identity migration is `fn_8023F704` → `__ct__15Handle_8001FF78Fv`, retaining address, extent and global function attributes. Current `src/` and `include/` contain no old-spelling consumer. Original split assembly has exactly two distinct branch references, at `8023F134` and `8023F2EC`, both in unowned recursive collection `fn_8023EFAC`; duplicate stale split files are separately inventoried rather than counted as additional callers. A full aligned original DOL pointer scan finds no pointer/data references to the old entry. No accepted source/header/canonical file was changed, and no alias or thunk is proposed.

Strict source/header hashes, all allocated bytes, the nonzero symbol inventory, actual relocation, complete original tables and the separate native identity/reference proposal are frozen under `scratch/engine_typed_zero_constructor_20261011fj/`. Run `python3 scratch/engine_typed_zero_constructor_20261011fj/verify.py` to repeat the isolated production proof. Root must register this source NonMatching, perform the guarded native identity/split integration, and accept the full original DOL hash before counting progress.

The larger recursive collection investigation remains private and uncredited in `scratch/engine_owner_tree_collect_20261011fi/`: its proposed original-binding diagnostic is 1,200 bytes with two load-order differences and unadopted weak/native identity assumptions. This independent constructor handoff does not promote that research.
