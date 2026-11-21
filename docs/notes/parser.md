# Parser and tokenizer

These CPython 2.1 units pass isolated relocation-aware comparison and the
complete GSQE78 DOL hash check. Source attribution is retained in each file.

| Unit | Text range | Functions | Code bytes |
| --- | --- | ---: | ---: |
| Parser/tokenizer.c | 0x801707CC..0x80171E7C | 6 | 5,808 |
| Parser/grammar1.c | 0x80171E7C..0x80171ED4 | 1 | 88 |
| Parser/myreadline.c | 0x80171ED4..0x80172194 | 2 | 704 |
| Parser/node.c | 0x80172194..0x8017269C | 4 | 1,288 |
| Parser/parser.c | 0x8017269C..0x80172B44 | 3 | 1,192 |
| Parser/parsetok.c | 0x80172B44..0x80172F28 | 3 | 996 |

`include/parser_abi.h` records the recovered node, grammar, tokenizer, and parser
stack layouts. The MSL FILE EOF byte is at offset 9, its stride is 80 bytes,
and BUFSIZ is 4096. Typed PyMem allocations reserve the observed extra byte;
raw PyMem reallocations call realloc directly. Readline retains EINTR handling.

Parser/assert.h uses active printf-and-abort assertions even without Py_DEBUG.
Those checks remain in parser and grammar lookup; disabling them changes the
executable. The source's token-name debug table and unused grammar label printer
have no linked representation here and are omitted. Inline-only helpers retain
their C algorithms without introducing unused standalone bodies.

Each candidate manifest records owned sections, symbols, and its relocation
count. Original inter-unit alignment bytes are retained. Inspect generated
PROGRESS.md for the current integrated status rather than inferring completion
from the number of source files.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Parser/grammar1.c` | `.data` | `0x802DB1E8..0x802DB1FA` (18 bytes) | `0x802DB1FA..0x802DB200` (6 bytes) |
| `Parser/parser.c` | `.data` | `0x802DB218..0x802DB24B` (51 bytes) | `0x802DB24B..0x802DB250` (5 bytes) |
| `Parser/parsetok.c` | `.data` | `0x802DB250..0x802DB289` (57 bytes) | `0x802DB289..0x802DB290` (7 bytes) |

Current native objdiff credits `Parser/grammar1.c`: 18 data bytes; `Parser/parser.c`: 51 data bytes; `Parser/parsetok.c`: 61 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
