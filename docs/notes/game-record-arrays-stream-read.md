# Vector and fixed-record stream reader

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801D4F98` matches `801D4F98..801D52EC` (852 text bytes) as ordinary C++ serialized array reading. It delegates the base read, reads/resizes/copies a12-byte vector array at74, then a248-byte record array at80, then20 tail bytes at8C. Each new fixed record constructs eight28-byte elements through the existing `fn_801D52EC` callback; empty vector/record destruction preserves the native growth and shrink counting loops.

GC1.3.2 Gekko O4,p with exceptions off emits only the primary852-byte text section. Strict production and fresh recompilation verify all allocated bytes, extents and45 actual relocations with zero differences. No helpers, owned data, literals, BSS, padding or EH allocations are emitted. The runtime allocator and construction APIs keep their original external identities.

Full original exception/startup tables and777360 initialized words were audited: no EH/startup records belong to this function. The sole initialized function pointer at802EA564 remains in the unchanged external88-byte original vtable `lbl_802EA558`; the original C entry/address is preserved. The active original-object audit scans5565 objects/119086 actual relocations and accounts for both references to the entry.

Frozen handoff: `scratch/game_engine_batch220/HANDOFF.md`. Root owns central integration and final original-DOL acceptance.
