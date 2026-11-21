# Actor base constructor80026BB8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated genuine C++ construction matches196text80026BB8..80026C7C +48extab80006198..800061C8 +12extabindex800164D0..800164DC, all17 actual relocations. The emitted real GLOBAL identity is __ct__15Object_80026BB8Fv; original C name fn_80026BB8 requires root's concrete identifier-only migration before acceptance. No aliases, inline assembly, forced registers, object edits, weak backups, data, BSS or padding are used. Production acceptance is pending.

The constructor initializes the existing Objects_802EB940 base and Object_8007D594 secondary base, installs the unchanged borrowed primary/secondary tables from lbl_802B074C, copies game_vec3_zero into point348, clears bytes354/355, allocates three words at344 and zeros them. Native base subobjects naturally produce the exact two DESTROYBASE exception actions and PC timings. The first ordinary compile matches all text/EH/index bytes under GC1.3.2 gekko/O4,s/exceptions-on/use_lmw_stmw. The existing destructor and every dependency retain their original identities.

The full original extabindex80015F60..8001F2C0/descriptor and ctors80299920..80299980/dtors80299980..802999A0 pass. Exactly one owned exception-index entry points into this body; no startup or other initialized data word does. The original borrowed vtable and string/constants remain outside this split.

The complete active original identity census scans5540 objects/119086 actual relocations. It finds one original GLOBAL fn_80026BB8(196), no proposed native definition, and exactly two original-name references: the owned exception-index entry and fn_8007E688's call at offset564 within the3344-byte factory text. The sole live source consumer is src/Game/factories_8007E160.cpp, with one declaration and one call; its canonical is config/GSQE78/candidates/game_factories_8007E160.json. All consumers and shared metadata remain untouched.

Private before/after factory snapshots replace exactly those two identifier occurrences. Both compile with the existing canonical's GC1.3.2/O4,p flags; strict comparison proves the complete3344text+304EH+456index allocations and380 actual relocation targets unchanged. Exactly one relocation spelling changes to the native constructor and still targets80026BB8. All function/object extents remain equal. Snapshot verification remains reproducible after root migrates the live caller.

Frozen batch184 is scratch/game_engine_batch184/HANDOFF.md. Repeat verify.py and caller_equivalence.py in scratch/game_early_actor_base_constructor. Root must migrate the one factory/canonical, retire the old global identity and prove real GLOBAL native placement plus all original allocated bytes, full DOL hash and no regressions before credit. No new proof adapter or force_active entry is needed.
