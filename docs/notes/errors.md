# Error handling (`Python/errors.c`)

The complete linked error-handling unit is reconstructed in
`src/Python/errors.c`: 21 functions and 10,152 code bytes. All code and
initialized data match the original DOL after applying 244 ELF relocations.
The alignment bytes are verified separately. Whole-program integration is
a separate main-build check.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | `8018EE70..80191618` | 10,152 |
| `.data` | `802DCFA0..802DD0C8` | 292 + 4 alignment |
| `.sdata` | `803766F0..80376748` | 83 + 5 alignment |

The source follows the official `reference/cpython-2.1/Python/errors.c`,
whose license is retained at `reference/cpython-2.1/LICENSE`. It covers
exception storage, normalization, matching, creation, formatting, errno
conversion, unraisable-error reporting, explicit warnings, syntax locations,
and source-line retrieval. The linked warning function at `8018F560` is
`PyErr_WarnExplicit`. Simple `PyErr_Warn` and legacy `PyErr_BadInternalCall`
have no linked bodies here and are omitted; `_PyErr_BadInternalCall` is present.

The recovered compiler configuration is GC/2.0 with
`-opt level=4,nopeephole,speed`, `-inline auto,deferred`, and `-pool off`.
The complete variadic `PyErr_Format` matches, including two argument-list
initializations and its 12-byte PowerPC argument-list structure. The
Metrowerks `__builtin_va_info`, `__va_arg`, and `_var_arg_typeof` interface
is independently documented in
[Melee's MSL stdarg header](https://github.com/doldecomp/melee/blob/master/src/MSL/stdarg.h).
The MSL ctype masks and unsigned-character indexing match the other recovered
Python units. `EINTR` is 4; platform-specific Windows paths are excluded.

This unit owns no BSS. Its diagnostic and format strings retain their
compiler-generated order. The candidate manifest,
`config/GSQE78/candidates/errors.json`, records the five newly identified
dependencies, complete function mappings, and verified source/object hashes.

```sh
python3 scratch/errors/verify.py
```

The verifier recompiles the source, validates the original DOL hash, rejects
unexpected allocated sections or size changes, applies every relocation, and
compares the entire text/data sections and alignment bytes. It does not mask
instruction or address differences. Matching credit requires the registered
full DOL build to pass.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/errors.c` | `.data` | `0x802DCFA0..0x802DD0C4` (292 bytes) | `0x802DD0C4..0x802DD0C8` (4 bytes) |
| `Python/errors.c` | `.sdata` | `0x803766F0..0x80376743` (83 bytes) | `0x80376743..0x80376748` (5 bytes) |

Current native objdiff credits `Python/errors.c`: 375 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
