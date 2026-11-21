# Controller-glyph token parser

Current combined recovery: the glyph function (1,076 bytes) and configuration
function (2,376 bytes) match, with 359 `.rodata` bytes and 234 `.sdata2` bytes
also exact. The 1,456-byte item parser still reverses two adjacent conversion
instructions (eight differing bytes). The complete shared-pool consumer scan
is in `scratch/game_menu_config_parser/ownership_summary.json`; all consumers
belong to these three functions. The combined group remains uncredited pending
that instruction match and full-link verification. The standalone ownership
limitations and smaller extents below describe the earlier isolated probe.


Status: **isolated exact, do not integrate**. The shared long-string pool still has original consumers outside this function. No new source or data progress is claimed.

`fn_80214544` spans `0x80214544..0x80214978` (1076 bytes). It reads tokens into a 128-byte local buffer, skips opening braces, and builds the output string until a closing brace. Recognized controller tokens become the original one-byte glyphs through `sprintf(..., "%c", glyph)`; ordinary tokens are copied unchanged. Each appended token after the first receives a separating space. The original loop and buffer behavior are preserved without additional checks.

| Token | Original glyph byte |
| --- | --- |
| `ITEM_UPDOWN` | `80` |
| `ITEM_LEFTRIGHT` | `81` |
| `ITEM_DIRPAD` | `82` |
| `ITEM_CROSS` | `7B` |
| `ITEM_CIRCLE` | `7C` |
| `ITEM_SQUARE` | `7D` |
| `ITEM_TRIANGLE` | `7E` |
| `ITEM_L1` | `83` |
| `ITEM_R1` | `84` |

The source uses ordinary literals for the long controller names. Metrowerks pools their addresses into one preserved register, matching the original instruction schedule. The earlier external-name probes hoisted separate addresses and remain available as historical evidence. Four ordered named constants hold the format string, separator, opening brace, and closing brace. `global_braces.cpp` changes only the two brace definitions from file-local to `extern const char[]` with initializers; the compiler then emits genuine strong global objects for their known external consumers. This variation preserves all code and data bytes.

The exact compiler invocation uses GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse,readonly -pool on -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`.

| Emitted section | Original extent | Bytes | Natural alignment |
| --- | --- | ---: | ---: |
| `.text` | `80214544..80214978` | 1076 | 4 |
| `.rodata` | `802AE588..802AE5E2` | 90 | 8 |
| `.sdata2` | `8037AC78..8037AC98` | 32 | 8 |

The two data sections contain 113 semantic string bytes and nine internal compiler alignment bytes: 88 + 2 in `.rodata`, and 25 + 7 in `.sdata2`. Every object has its actual semantic size in the candidate; the nine intervening zeros are recorded separately as compiler-emitted internal alignment. The two zeros at `802AE5E2..802AE5E4` are **outside** the emitted `.rodata` section and remain original uncredited padding. No section extent was rounded up to absorb them.

The strict verifier applies all 78 real ELF relocations: 53 REL24 calls, 23 SDA21 addresses, one HA, and one LO. It compares all allocated bytes directly with the untouched original DOL, checks the single strong 1076-byte function, verifies every string object's size/binding, and accounts for all internal alignment. Neither object emits weak bodies, exception tables, or discarded allocated sections. The two variants have identical relocated section hashes.

Integration remains blocked by real shared ownership. The pooled base is the compiler-local, zero-sized `...rodata.0` anchor at `802AE588`. The original adjacent functions `fn_80214978` and `fn_80214F28` also load this base with addend-zero HA/LO relocations, then use plain instructions to select later strings at offsets `5C..B0` and `C0..15C`. They do not semantically consume the first seven names, but their original relocations still depend on the same pooled base. A local compiler anchor cannot satisfy those external dependencies. No fabricated global alias, negative-addend retargeting, or compiler-object rewriting is proposed.

The braces at `8037AC80` and `8037AC84` are also shared with `fn_80214978`; the genuine global definitions solve that smaller issue. `%c`, the separator, `ITEM_L1`, and `ITEM_R1` have only this function as an original consumer. The next planned step is coherent recovery of the remaining pooled-string consumers, then complete shared-pool byte, relocation, and ownership proof. The current coarse 360-byte pool includes later menu strings and must not be credited wholesale to this function.

Evidence:

- `scratch/game_input_glyph_parser/ordered_constants.cpp`: frozen exact root probe.
- `scratch/game_input_glyph_parser/global_braces.cpp`: exact ordinary global-brace variation.
- `scratch/game_input_glyph_parser/verify.py`, `strict_summary.json`, `candidate_ordered_constants.json`, and `candidate_global_braces.json`: isolated proof, explicitly marked `do_not_integrate`.
- Per-variant `*_relocations.json`: every actual retained relocation.
- `scratch/game_input_glyph_ownership/REPORT.md`, `summary.json`, and `findings.json`: all 4078 configured original target ELFs, no missing objects or unresolved section bases, independent raw SDA2/base-address checks, semantic string extents, and all three pooled-register consumer maps.

The original DOL, accepted sources, and central build/configuration files remain unchanged by this probe.
