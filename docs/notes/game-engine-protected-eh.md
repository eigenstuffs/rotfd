# Protected-name destructor source

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: original C entry `dtor_80024E50` retains its protected name and recovers all 124 text bytes plus 52 compiler-emitted exception bytes, with nine actual relocations. Existing accepted callers and declarations remain unchanged. No alias, thunk, native-symbol rename or caller modification is needed. Parent staging, full DOL hash and regression acceptance remain required.

A normal C++ source definition with C linkage accepts the observed object prefix and integer flag, checks the object, updates its table at offset 0x08, invokes existing `fn_80020FE8(self, 0)`, conditionally releases storage for positive signed-short flags, and returns the object pointer. The release is an ordinary inline function declared `throw()`; CodeWarrior emits exactly the original no-throw exception landing pad and associated extab/index. The first isolated and production probes both match all original bytes. The ABI's returned object pointer is preserved even though existing callers do not use it.

GC/1.3.2 uses the established container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`, hardware Gekko. Strict verification checks every allocated byte, exact symbol extents, actual relocations, source SHA256, empty recursive quoted-header inventory and referenced-undefined-ELF dependency scope. The original-table audit covers full extabindex 0x80015F60..0x8001F2C0, ctors 0x80299920..0x80299980 and dtors 0x80299980..0x802999A0. There is exactly one 40-byte extab and 12-byte extabindex record, with no constructor/destructor-table entries, helpers, weak code, padding, BSS or other data. Original surrounding code/data retain ownership. Frozen manifest, proposed splits/configuration, verifier and ownership audit are under `scratch/game_engine_protected_eh_continuation/`.
