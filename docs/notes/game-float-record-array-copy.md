# Float record array copy assignment

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801C33F4` reconstructs `801C33F4..801C3780` (908 text bytes) as ordinary C++ array copy assignment. It clears existing elements while retaining capacity, reserves the source count, and appends32-byte records, growing capacity by64 when needed. Eight named float members produce the native sequence of individual floating-point loads/stores in the implicit copy constructor. An array of eight floats instead generated integer copies; no explicit instruction or register control is used.

GC1.3.2 Gekko O4,p with exceptions off produces only the primary908-byte text section and39 actual relocations. Strict production compilation and independent fresh compilation match every allocated byte and symbol extent. Empty default/destructor lifetimes reproduce native counter loops. No helpers, literals, data, BSS, EH, padding or startup ownership is introduced.

Full original exception/startup tables,777360 initialized words and5567 active objects/119086 actual relocations were audited. There are no original initialized pointers into this function. One original object reference preserves the C identifier/address; no source consumer or identity migration is required. Runtime allocator dependencies stay external.

Frozen handoff: `scratch/game_engine_batch221/HANDOFF.md`. Root owns central integration and final original-DOL acceptance.
