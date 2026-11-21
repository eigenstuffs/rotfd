# Renderer index quicksort

Ordinary C++ reconstructs **920 code bytes and four actual recursive relocations** at 80271D74..8027210C. Production integration and original-DOL acceptance are pending.

The entry partitions an unsigned-short index array using float keys at offset 94 in A8-byte records, reached through the receiver's pointer at 3AC. It advances the left and right cursors within the supplied inclusive bounds, swaps indices when the cursors meet, and recursively processes the remaining ranges. The original computes the pivot array index as `(last - first) / 2`, without adding `first`, and reloads the indexed pivot during the scans. The reconstructed source preserves both behaviors.

Standard GC1.3.2 `-O4,p`, exceptions off, naturally inlines one recursive layer and emits the complete 920-byte entry. Direct float reads from the byte-backed entry storage preserve the original indexed loads and operand order. The first inline-key helper probe leaves calls to an extra helper inside the inlined recursive layer; its 944-byte allocation and actual relocations remain preserved as private research. The space-optimization alternative also differs and receives no credit.

The production object emits only the retained text function. All four actual branch relocations target its original entry address; there are no external dependencies, data, BSS, weak helpers, EH, startup allocations or owned padding. Full current symbol-address, canonical-range and prior-body censuses found no earlier owner. Complete original exception-index, constructor/destructor and initialized-pointer scans find no references requiring additional ownership. The receiver declaration is a partial field view and does not claim a complete original class or translation unit.

The frozen handoff is `scratch/engine_render_index_sort_20261011iv/final_integration.json`, with production source/header hashes, every emitted allocation and symbol, actual relocation records, original table proofs and fresh strict recompilation. Root owns central registration and full DOL/regression acceptance.
