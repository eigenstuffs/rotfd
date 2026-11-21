# Console named-group binding at 8003E258

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated ordinary C++ source: src/Game/console_group_binding_8003E258.cpp. Original C entry fn_8003E258 is preserved. Central full-DOL acceptance is pending; no progress credit until integration.

The callback accepts one console argument, resolves a named group, reports missing names/groups, obtains the scene target named by the original diagnostic pool, assigns the corresponding group handle, and refreshes its scene owner. All original strings and globals remain external.

Genuine native Handle lifetimes reproduce the complete 492-byte primary, 144-byte exception table and 12-byte index. The original six-byte SDA name declaration restores the single native SDA load; an unsized declaration incorrectly generated two instructions and shifted saved-register assignment. Compiler GC1.3.2, processor gekko, O4,s, exceptions on and use_lmw_stmw on.

All648 retained allocated bytes and41 actual relocations pass the unchanged standard defined-weak/EH verifier. Five accepted GLOBAL strong Handle destructor owners (8001FF78/80020834/80020478/80020C04/8003E120) were independently recompiled and strictly verified. Six compiler backup functions (652 bytes) plus12 EH/index allocations (280 bytes) are uncredited and discarded by real isolated MWLD. The unique InitZero_E258 backup remains absent from the final link. Native checks apply every primary and metadata relocation, retain the five GLOBAL strong owners, and reject a wrong fixture name and wrong branch addend.

The full stable active original inventory scans5641 objects,119086 actual relocations and777360 initialized words. Its sole primary definition, console callback pointer and all original references remain unchanged. Full extabindex/ctor/dtor audits find only the owned exception record and no startup entries. No engine data, BSS, padding, alias, dependency identifier or caller migration is introduced. The original44-byte allocator storage referenced only by discarded backup cleanup remains external and untouched.

Frozen evidence: scratch/game_engine_batch282/manifest-list.json and frozen_hashes.json; source, original tables, actual allocation inventory, strict recompile, strong owners, native discard/relocation proof, and complete current original ownership snapshots are included.
