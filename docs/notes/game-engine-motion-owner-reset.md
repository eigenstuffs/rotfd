# Motion owner reset and default arrays

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_motion_owner_reset.cpp` reconstructs original C entry `fn_80220754`, the full `.text` range `80220754..80220D78` (1,572 bytes), as ordinary C++. The dedicated public declaration is `include/Game/engine_motion_owner_reset.h`. The existing native base declarations in `src/Game/objects_owner_internal.h` are included unchanged.

The function directly invokes the genuine `ObjectsOwner_80213D44::slot18()` base method, assigns the external zero vector to movement and velocity fields, writes 64-bit flags `C000` and the external scalar default, then resets Handles at offsets `20`, `68` and `28` using two-, two- and three-layer native full-expression temporaries. It selects state one through `fn_80213920`, then resizes the five arrays at `38`, `44`, `50`, `5C` and `6C` to one element each. Their element sizes are 12, 16, 12, 4 and 40 bytes. Placement construction, destruction and exact-size allocation use the same ordinary array structure recovered for the independently frozen base resize routine.

Fresh production GC/1.3.2 compilation with Game defaults, `-use_lmw_stmw on`, and `-i src/Game` matches all 1,572 retained bytes and 81 actual retained relocations. The complete allocated object contains the strong entry and three ordinary unused destructor backups totaling 264 bytes and six actual relocations. All backup extents, bindings and raw bytes are inventoried; no retained defined-local relocation references them, and there is no allocated data/EH/startup reference. Their unique source type names avoid unrelated weak-name collisions. `default_discard_audit.json` documents ordinary default discard. No special native override or identity migration is needed.

`scratch/engine_motion_owner_reset_20261011ep/final_integration.json` freezes source and both header hashes, compiler flags, every allocated symbol and every real relocation target. Run `python3 scratch/engine_motion_owner_reset_20261011ep/verify.py` to recompile and repeat strict byte, allocation, target and frozen-hash verification. The full original `extabindex` range `80015F60..8001F2C0`, `ctors` range `80299920..80299980`, and `dtors` range `80299980..802999A0` have no reference into this function. Data, BSS, exception/startup and padding ownership are zero. All existing C/native identities, external vector/scalar/allocator data, compiled consumers, shared declarations and nearby routines remain with their original owners.

The isolated exact handoff awaits central NonMatching registration, full native linking and original DOL/regression acceptance before credit. The source uses no forced registers, assembly, aliases, thunks or object transformations.
