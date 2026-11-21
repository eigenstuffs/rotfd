# Interpreter and thread state (`Python/pystate.c`)

`src/Python/pystate.c` reconstructs all eight linked state-management
functions. The entire 1,576-byte text section and all 389 initialized data
bytes match the original DOL after applying 48 ELF relocations. Three data
alignment bytes and the two four-byte state pointers are also checked.
Whole-program integration remains a separate main-build check.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | `8019FBA0..801A01C8` | 1,576 |
| `.data` | `802E30E8..802E3270` | 389 + 3 alignment |
| `.sbss` | `80377F38..80377F40` | 8 |

The code and state structures follow the official
`reference/cpython-2.1/Python/pystate.c` and `Include/pystate.h`;
`reference/cpython-2.1/LICENSE` retains the reference license. The recovered
interpreter structure is 24 bytes, and the thread structure is 60 bytes.
Type-oriented allocations request one extra byte, as in the list unit.
`WITH_THREAD` is disabled, so no native-thread locks or
`PyThreadState_DeleteCurrent` body are present.

The eight linked functions cover interpreter creation, clearing, deletion,
and thread creation, clearing, retrieval, swapping, and dictionary access.
`zapthreads`, `tstate_delete_common`, and `PyThreadState_Delete` are
inline-only helpers; no separate thread-delete function occupies the original
linked range. Its behavior remains in interpreter deletion.

Diagnostic strings are named static character arrays in their original
linked order. This preserves their exact addresses even though the
thread-delete helpers have no standalone emission in the reconstruction.
`interp_head` is at `80377F38`; `_PyThreadState_Current` is at `80377F3C`.

```sh
python3 scratch/pystate/verify.py
```

The verifier recompiles with GC/2.0 and the flags recorded in
`config/GSQE78/candidates/pystate.json`, applies every relocation, and checks
the complete text/data sections, alignment, and BSS placement. It validates
the original DOL hash and rejects section-size changes without masking any
instruction or address differences. The manifest records the verified source
and object hashes and all symbol mappings.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/pystate.c` | `.data` | `0x802E30E8..0x802E326D` (389 bytes) | `0x802E326D..0x802E3270` (3 bytes) |

Current native objdiff credits `Python/pystate.c`: 397 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
