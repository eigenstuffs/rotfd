# Interpreter frames

All nine emitted frame functions match at 0x8014597C..0x801467C8 (3,660
bytes). Source follows CPython v2.1 `Objects/frameobject.c`, with its original
frame, code, thread-state, and block-stack layouts.

| Section | Start | End, exclusive |
| --- | --- | --- |
| .text | 0x8014597C | 0x801467C8 |
| .data | 0x802D2F80 | 0x802D317C |
| .sdata | 0x80376170 | 0x803761A0 |
| .sbss | 0x80377DF0 | 0x80377DF8 |

`map_to_dict` and `dict_to_map` are static inline helpers with no standalone
linked bodies. The allocator and free list preserve the upstream behavior,
including trash-chain disposal. Error-location evidence identifies
`frameobject.c:130`; `#line` preserves that value. The local builtins cache
and free-list pointer own the complete eight-byte small BSS range.

GC/2.0 with speed optimization, deferred inlining, pooling off, and C++
exceptions off matches every byte after 135 relocations. Full DOL SHA-1
verification passes and objdiff reports all nine functions matched.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/frameobject.c` | `.data` | `0x802D2F80..0x802D317A` (506 bytes) | `0x802D317A..0x802D317C` (2 bytes) |
| `Objects/frameobject.c` | `.sdata` | `0x80376170..0x8037619D` (45 bytes) | `0x8037619D..0x803761A0` (3 bytes) |

Current native objdiff credits `Objects/frameobject.c`: 559 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
