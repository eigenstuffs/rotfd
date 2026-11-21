# Engine nested short-array and base cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `fn_801CA6B8`, 668 retained text bytes, zero data bytes, 21 actual relocations, range 0x801CA6B8..0x801CA954. Its existing C ABI name is preserved, including the accepted callers in `engine_pool_lifetime_801CA4C8.cpp` and `engine_loop_801CF5AC.c`. GC/1.3.2 uses the ordinary hardware Gekko optimization flags plus `-use_lmw_stmw on`, with exceptions off.

The routine installs the observed outer table at +8, destroys the nested count/capacity/pointer array at +0xCC within the +0xAC subobject, calls the existing native `Pool_801CA954` destructor on +0xA0, installs the base table, and cleans up the arrays at +0x80 (248-byte records) and +0x74 (12-byte records). Each nested row is a 12-byte array header owning two-byte elements. Ordinary empty element destructors reproduce the original unrolled counter loops. The base cleanup calls `fn_80243E90(self,0)` after storage cleanup. A positive signed-short release flag invokes `fn_801EF610` on the global allocator.

Private storage views give the two inherited arrays explicit observed cleanup without asserting an unverified native class name or generating a duplicate base-destructor null check. The nested short array uses the pool directly; adding an extra empty derived row class generates an extra null check absent from the original. The accepted C++ source matches every retained byte and real relocation with the direct pool and storage-view shapes. No assembly or relocation masking is used.

`final_integration.json` under `scratch/game_engine_nested_cleanup_continuation` freezes source SHA256, an empty recursive quoted-header inventory, all symbol extents, allocated sections and actual relocations. Proposed central split/config edits and `ownership_audit.json` are siblings. Strict production recompile through `verify.py` passes. No helper or weak functions, data, BSS or padding are emitted. Full original extabindex, constructor and destructor table audits find no owned records. The current original 668-byte text unit is fully covered; neighboring native pool and base routines retain their existing ownership. This does not establish an entire original translation unit. Parent final DOL and regression acceptance remain required.
