# Memory-card format worker

Isolated ordinary C++ source matches fn_80277CB4 at 80277CB4..80277EC8: **532 text bytes and 40 actual relocations**. Production integration and original-DOL acceptance are pending with root. Original C entry and all dependency identities remain unchanged.

The worker resumes the card thread, locks the owner mutex, performs a preliminary mount/probe, unmounts and frees its work area, then mounts for formatting when needed. Mount results 0, 3 and 21 permit a CARDFormat retry loop of up to 1000 busy attempts. The loop preserves reset-switch transition logging and request state. The owner is marked formatted after the loop; a successful format becomes result0, no-card result-3 becomes result1, and remaining format errors become result15. It unmounts, frees its work area, clears the format-in-progress byte, unlocks the mutex, suspends the thread, and returns the normalized result. The unavailable-card early return preserves the original cleanup sequence.

The first ordinary probe matched all prefix/loop code and generated a540-byte body because a two-case switch added dispatch branches. Expressing that final status mapping as the observed if/else chain produces all532 original bytes exactly, with the same real relocations. No assembly, compiler intrinsics, aliases or object rewriting is used.

Compiler: GC/1.3.2 standard Game flags, -O4,p/exceptions off, plus -use_lmw_stmw on. The complete object emits exactly one532-byte .text function, with no unused helpers, data, BSS, EH, startup data or padding. Every allocated byte and symbol and all40 actual relocation targets pass the unchanged strict verifier.

The complete original extabindex80015F60..8001F2C0 (including descriptor/padding), ctor80299920..80299980 and dtor80299980..802999A0 scans find no references to this body. Any original initialized-data function pointers are inventoried separately and retain their external ownership and unchanged global entry. Shared MemoryCardOwnerView, message pool, reset state, thread and allocator owners remain unchanged. Current source/header references are inventoried with no consumer migration required.

Production strict bytes/full allocations/real relocation targets and frozen hashes pass. The manifest, split/config proposals, complete allocation and table/pointer inventories, and verifier are frozen in scratch/engine_card_format_worker_20261011gq. Root owns central integration and final hash/regression acceptance. No existing source/header, metadata or original input was modified.
