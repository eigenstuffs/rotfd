# Nullable Handle control forwarder

Isolated matching source; full executable acceptance remains with the root integrator.

src/Game/engine_nullable_handle_forward.cpp recovers fn80255CBC at80255CBC..80255D88:204 retained text bytes and11 actual relocations under default GC1.3.2 Game flags. The original C identity and all external identities remain unchanged.

When a source record is present, the routine takes its mutable Handle at04, builds a copied full-expression temporary through the native Handle constructor and one zero layer, acquires its reference through the manager at global118, and forwards the copy with destination index54 and the supplied integer event/control argument to fn8023B35C through manager158. It destroys the temporary afterward. With a null source, it forwards destination Handle58 directly. The mutable named source reference before the temporary preserves both the source address and original manager-load/copy-load order. The routine does not directly change the source record.

The header is a partial storage view. Existing unrelated caller headers approximate the third argument as int and currently pass zero; those declarations and accepted source files remain unchanged. The new body retains the recovered nullable source-pointer declaration and integer second argument. No caller migration is proposed.

The complete compiler allocation is376 text bytes:204 retained plus88/84-byte unused weak copied/zero Handle destructors, with four extra actual relocations. All symbols, complete raw allocations and real relocations are inventoried. No retained reference points at either discarded helper. There is no allocated data, BSS, literals, vtables, EH, startup or padding ownership. Full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans include descriptors/padding/terminators and find no ownership references. All external data/functions and adjacent55D88 remain with their existing owners.

Frozen manifest: scratch/engine_nullable_handle_forward_20261011fz/final_integration.json. Its verifier freshly compiles production source, compares every retained byte with actual relocation targets, audits every unused helper byte and symbol, repeats complete original table scans and checks frozen hashes. Root should stage NonMatching, then promote only through original DOL hash and normal acceptance checks.
