# Dolphin GX TEV state

Two C fragments match all 1,432 owned code bytes and 80 initialized data bytes with GC/1.2.5n and `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/gx -Cpp_exceptions off`.

| Source | Original text range | Functions | Code bytes | Initialized data |
| --- | --- | --- | --- | --- |
| `GXTev_state.c` | `0x80115D80..0x801162E8` | 13 | 1,384 | 80 bytes at `0x802CFBD8..0x802CFC28` |
| `GXTev_stages.c` | `0x801164C0..0x801164F0` | 1 | 48 | None |

The state fragment recovers the TEV color and alpha inputs, arithmetic modes, constant colors, channel swapping, alpha comparison, and depth-texture registers. The stage fragment changes the stage count and marks the cached general mode dirty. The [Melee reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/gx/GXTev.c) supplies the SDK register-field algorithms. The [Pikmin 2 reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/gx/GXTev.c) supplies the later table-driven operation selection and corroborates its four five-entry tables. Exact local reference hashes are recorded in each reference directory's `PROVENANCE.md`.

The initialized objects are four local 20-byte tables, in original order: `TEVCOpTableST0`, `TEVCOpTableST1`, `TEVAOpTableST0`, and `TEVAOpTableST1`. Their section alignment is 8. Text alignment is 4. Neither fragment owns BSS or linker padding, and neither requires a shared header change. The manifests enumerate every function, table, and external symbolic relocation.

`scratch/GXTev/compile_fragments.py`, `verify_state.py`, and `verify_stages.py` retain the isolated compilation and relocation checks. Both integrated fragments pass complete DOL byte equality, native objdiff code/data checks and the preserved original-source regression audit. The verifiers create candidate manifests and should not overwrite an accepted manifest during later rechecks.

`GXSetTevOrder`, `0x801162E8..0x801164C0` (472 bytes), remains original fallback. The coherent complete reconstruction is retained in unconfigured `GXTev.c`. It matches 1,896 of 1,904 original text bytes, including the full function lengths and every relocation; two instructions exchange the load of `tevTcEnab` and the calculation of its address in the invalid-coordinate branch. Ordinary expression, local-variable, inline-helper, and compiler scheduling variants have not resolved that order. Its local `c2r` table is 36 bytes at `0x802CFC28..0x802CFC4C`; the following four bytes are original alignment padding. This table and the pending function receive no recovered-source credit. No instruction assembly or dummy behavior was introduced to close the discrepancy.

A subsequent bounded pass examined only the unresolved mask update. A const local value, const read pointer, const structure view, small const-parameter getter, equivalent clear-bit expression, and private same-width integer field types left the original two-instruction ordering difference unchanged or worsened the match. No broad compiler-option sweep was repeated, and no accepted TEV source or shared header was modified.

The exact best standalone reconstruction is saved as `scratch/GXTev/GXTev_order.c`, with `compile_order.py` and strict `verify_order.py`. It emits the original 472-byte function and complete 36-byte `c2r` table. At `0x8011633C`, the target loads `tevTcEnab` into r8; at `0x80116340`, it computes the field address into r10. The candidate emits those two instructions in the opposite order. All other relocated instruction words match. The verifier returns a failure status for this 464/472 diagnostic result and never creates an accepted manifest. `final_order_results.txt` preserves the bounded source variants. This pass is stopped pending new source/compiler evidence.
