# Record scene state updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen isolated handoff is `scratch/game_engine_record_state_updates_continuation/final_integration.json`. Central full native link acceptance remains required.

Thirteen ordinary C++ functions reproduce 2,116 original text bytes and 260 exception/index bytes, with 115 actual relocations. There is no extra allocated output, weak backup, static data transfer, source alias, native symbol rename, or compiled consumer migration. Each function retains its original C entry and complete 8-byte extab plus 12-byte index. Compiler is GC 1.3.2 with the established container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags.

| Original entry | Text bytes | Actual relocations | Observed behavior |
| --- | ---: | ---: | --- |
| `fn_800EC1B4` | 88 | 5 | flag4 notification then clear |
| `fn_800EC468` | 280 | 15 | one-shot operation, countdown14/status1C switch, service query |
| `fn_800EC7D4` | 88 | 5 | flag6 cleanup and notification |
| `fn_800ECB44` | 212 | 11 | service/flag4/flag5 dispatch, conditional machine reset |
| `fn_800ED044` | 176 | 9 | service/flag4/flag5 dispatch to messages6/15/14 |
| `fn_800ED520` | 124 | 7 | flag4/flag5 dispatch to messages0/5 |
| `fn_800ED9C8` | 176 | 10 | service/flag8/flag7 dispatch and record refresh |
| `fn_800EDED0` | 276 | 17 | countdown10/status14 switch and service cleanup |
| `fn_800EE420` | 72 | 4 | countdown10 then message0 |
| `fn_800EE88C` | 184 | 10 | service/flag4/flag5 dispatch to messages6/0/17 |
| `fn_800EED7C` | 188 | 8 | one-shot flag14 operation then countdown10 and message18 |
| `fn_800EF268` | 144 | 8 | service message6 then independent flag6 cleanup |
| `fn_800EF71C` | 108 | 6 | flag7 machine reset or flag8 cleanup |

The private owner view establishes pointer fields 8/C, a float or signed-byte field 10, a float/signed-byte/integer field 14 used by different derived owner routines, and integer status field 1C. These unions describe observed same-offset storage across separate original derived routines; they do not claim a shared complete class identity or complete allocation extent. The record view follows the accepted 3B5C array stride and observed B300 flag bytes. The service view has its vptr at 30 and signed-byte result method at virtual offset 64. All outside functions and existing data remain original-owned.

EC468 and EED7C carry a float elapsed value across real calls, so the compiler itself emits the original FPR31/paired-single save/restore sequence. The source is ordinary C++ with float subtraction and comparisons; no native-ABI or paired-single assembly is credited.

The first ECB44 probe incorrectly declared `fn_801EBE14` with a record argument and differed in two register operands. The already accepted source `src/Game/engine_leaf_801EBE14.c` establishes `void fn_801EBE14(void)` and performs the VI/GX/cache/pad reset sequence followed by OSResetSystem. Correcting only this private declaration/call to its genuine no-argument identity closes ECB44 exactly and preserves EF71C exactly. The original instructions around ECB44 may leave a record-derived address in r3 before the no-argument reset; that value is not an argument. `initial_probes` preserves the earlier incorrect declaration and full relocated diagnostic output. There is no accepted-source edit.

`ownership_audit.json` scans the full original exception index (`80015F60..8001F2C0`, stride 12), constructor pointers (`80299920..80299980`, stride 4), destructor pointers (`80299980..802999A0`, stride 4), and initialized data words. Each original function extent is independently checked against the complete disassembly. Every function has exactly its listed EH/index and no constructor/destructor table entry. Original assembly-owned callable table references, table object names/ranges/offsets, and compiled source consumers with hashes are inventoried; those tables and callers remain unchanged. This is a partial split of original units, not a claim to reconstruct their remaining data or neighboring functions.

`verify.py` recompiles every expanded production source, checks source and recursive quoted-header hashes, exact all-section symbol extents and ownership, every retained original byte, and all actual relocation targets. All 13 passed; there are no relocation masks or near-match credit. Shared symbols/splits/configure/headers, input hashes, original executable/disc, progress, and full builds remain untouched by this isolated work. All prior production sources and frozen artifacts remain unchanged; earlier checkpoint notes may have separately received central acceptance annotations.
