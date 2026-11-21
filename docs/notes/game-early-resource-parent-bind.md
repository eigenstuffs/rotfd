# Resource parent binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source at `src/Game/early_resource_parent_bind_80026258.cpp` matches the620-byte original function at80026258. It resolves the owner record, tests its resource flag, selects the appropriate parent binding through the current system, and initializes the selected target position with the original external scalar constants.

The resource flag accessor returns signed char, preserving the original extraction and sign extension. An ordinary named system lookup in the first branch establishes the native evaluation order before resolving the parent argument; direct nested arguments evaluate in the other order under this compiler. Both choices express normal typed C++ operations, without register constraints or assembly.

GC1.3.2 gekko/O4,s/exceptions-on matches all620 text bytes, eight EH bytes at80006130 and12 index bytes at80016494, including14 real allocated relocations and actual compiler-local EH identities. The object emits no helper, literal, BSS or padding allocation. Its dependencies are selected from actual undefined ELF symbol indices. The original EH has Elf Vector set, so this unit uses gekko.

Complete original exception and startup table scans pass. The initialized-data word scan finds only the owned index and the unchanged callback at802B05EC inside the original28-byte `lbl_802B05E0` table. The callback table, global context and two scalar constants retain their original external ownership and identities. No existing source/header caller requires migration.

Frozen handoff: `scratch/game_engine_batch171/HANDOFF.md`. Repeat: `python3 scratch/game_early_resource_parent_bind/verify.py`. Central native DOL/hash/regression acceptance remains pending; this isolated match grants no credit before integration.
