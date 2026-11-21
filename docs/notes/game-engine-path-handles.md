# Engine keyed handle selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/game_engine_path_handles_continuation/final_integration.json`.
One ordinary C++ source reproduces **212 original text bytes**, no data, and **two actual branch relocations**. Production recompilation passes the strict verifier. No weak helpers or other allocated bytes are emitted. Source SHA256 and recursive quoted-header inventory (empty) are frozen in the manifest. Central integration and full DOL acceptance remain the integrator's responsibility.

`fn_801B3D80` walks a packed handle array, resolves each handle through `fn_801F7EB8`, and compares the resolved object's first key word with the input/output handle word captured on entry. A matching handle copies its signed 24-bit index and generation byte to the output, then calls `fn_801F86C8(manager, output, 1)`. If none matches, it clears only the index. The captured key uses an ordinary private C++ copy constructor; this reproduces the original register allocation without assembly or artificial side effects. The array fields are count, capacity and data at offsets 0, 4 and 8. Packed generation and index occupy the original high byte and low 24 bits.

The production object uses GC/1.3.2 standard flags plus `-use_lmw_stmw on`. Exact split is `.text 0x801B3D80..0x801B3E54`. The original assembly fragment also contains `fn_801B3BE4`; its 412 bytes remain outside this partial text split. The original fragment owns no non-text data. Complete original extabindex and constructor-table scans find no record or constructor pointer for the retained function. All original external names are preserved. See `ownership_audit.json`, `final_splits.txt`, and `final_config.txt` for the checked proposals.

Uncredited research is preserved in the same scratch directory: `fn_801B3BE4` normalizes a path, constructs its resource key and scans selected handles with inline validity and key lookup. Its closest probe has the correct 412-byte extent and differs in the destination registers of only the generation-byte load and sign extension at offsets 0xC8 and 0xD4. Every such probe remains unaccepted; no production source or credited bytes exist for it. Simple local/type/helper and bounded optimization variants were exhausted before moving on.
