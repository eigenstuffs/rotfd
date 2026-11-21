# Effect-array activation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source `src/Game/early_effect_array_activate_800E5254.cpp` matches the648-byte function at800E5254. It queries the initial effect and optionally prepares a separate shared effect, then queries/prepares/finishes each selected array element and deactivates the remaining slots through index2. The same integer loop index intentionally continues into the deactivation loop.

Checked Handle resolution uses the observed signed tag and24-bit signed index with16-byte manager entries. The effect has an8-byte nonvirtual prefix and genuine virtual prepare method at table offset38. Query and mutation calls remain separate, preserving the native reloads and validity checks around each external operation. This direct ordinary source matched on its first compile.

GC1.3.2 processor750/O4,s/exceptions-on matches all648 text bytes, eight EH bytes at80014A3C and12 index bytes at8001E924, including nine actual allocated relocations and real compiler-local metadata identities. The original EH has no Elf Vector, requiring processor750. No helper, literal, BSS or padding is emitted. Dependency names come exclusively from actual undefined ELF symbols.

Full original exception/startup table and complete initialized-data word scans pass. The owned index is the sole initialized reference into the function; no existing source/header caller requires migration. All external function/global identities remain unchanged.

Frozen handoff: `scratch/game_engine_batch173/HANDOFF.md`. Repeat `python3 scratch/game_early_effect_array_activate/verify.py`. Central native DOL/hash/regression acceptance remains pending.
