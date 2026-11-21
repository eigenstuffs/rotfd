# Python/exceptions.c

The complete linked CPython exception hierarchy has been reconstructed from the official CPython 2.1 `Python/exceptions.c`, with the original Secret Labs AB copyright retained. Licensing is preserved in `reference/cpython-2.1/LICENSE`.

The source implements Exception, SystemExit, EnvironmentError, and SyntaxError methods, creates the hierarchy and preallocated MemoryError instance, and releases the classes during shutdown. The full hierarchy table, method tables, documentation strings, and 36 exception globals match the original. The Windows-specific exception is excluded by the target configuration.

| Section | Original range | Source bytes | Alignment padding |
| --- | --- | ---: | ---: |
| `.text` | `0x80191618–0x80193318` | 7,424 | 0 |
| `.data` | `0x802DD0C8–0x802DE6F8` | 5,675 | 5 |
| `.sdata` | `0x80376748–0x803767C0` | 113 | 7 |
| `.sbss` | `0x80377E80–0x80377F10` | 144 | 0 |

The next text routine, `PyNode_Future` at `0x80193318`, belongs to a separate translation unit. All twelve emitted functions belong to this candidate; no discarded bodies or assembly substitutes contribute to its proof.

`populate_methods`, `make_class`, `get_self`, and `my_basename` are inline-only helpers. The recovered target uses slash as the path separator. Typed `PyMem_NEW` allocates one extra element, while `SyntaxError__str__` calls the actual `PyMem_Malloc` API; replacing that API with raw `malloc` gives a branch relocation mismatch. The source uses the recovered object layouts and reference-count macros.

Reproduce isolated verification from the repository root:

```sh
python3 scratch/exceptions/verify.py
```

The verifier compiles with GC/2.0 and the flags in `config/GSQE78/candidates/exceptions.json`, applies all 463 relocations at the original addresses, and compares every allocated instruction and initialized data byte. It also checks all 12 alignment bytes and the complete zero-initialized range against the DOL BSS bounds. Result: zero differences. The input DOL SHA-1 is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The candidate manifest contains all function and named data mappings, including previously unnamed exception globals. Full-DOL integration passes the original SHA-1 and native objdiff checks; project-wide completion is reported in [PROGRESS.md](../../PROGRESS.md).

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/exceptions.c` | `.data` | `0x802DD0C8..0x802DE6F3` (5,675 bytes) | `0x802DE6F3..0x802DE6F8` (5 bytes) |
| `Python/exceptions.c` | `.sdata` | `0x80376748..0x803767B9` (113 bytes) | `0x803767B9..0x803767C0` (7 bytes) |

Current native objdiff credits `Python/exceptions.c`: 5,932 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
