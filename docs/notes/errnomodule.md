# Python errno module

`src/Modules/errnomodule.c` reconstructs the complete linked CPython 2.1 errno module. Its sole emitted function, `initerrno`, matches all 6,760 original text bytes after relocation. The implementation and module documentation derive from the official source retained at `reference/cpython-2.1/Modules/errnomodule.c`, under `reference/cpython-2.1/LICENSE`.

| Section | Original range | Verified content |
| --- | --- | --- |
| `.text` | `0x801A7628..0x801A9090` | 6,760 bytes, `initerrno` |
| `.data` | `0x802E8938..0x802E8B78` | 574 bytes plus 2 zero padding bytes |
| `.sdata` | `0x80377310..0x80377438` | 290 bytes plus 6 zero padding bytes |

The module registers 39 target errno names and builds the reverse `errorcode` dictionary. Every target constant was recovered from the original string-construction and integer-construction call pairs. The source defines this recovered set explicitly rather than using the host operating system's errno header. In particular, `EILSEQ` is 88 and `ENOLCK` is 77. `EDEADLK` and `EDEADLOCK` both equal 35; their original registration order and reverse-dictionary behavior are preserved. The full ordered mapping appears under `errno_constants` in the candidate manifest.

`_inscode` is inline-only, matching its 39 expanded uses and the absence of a standalone original helper. The empty method-table sentinel and complete module documentation are retained. The source allocates no BSS or floating-constant sections and uses no assembly or raw instruction arrays.

Run the independent verification from the repository root:

```sh
python3 scratch/errnomodule/verify.py
```

The check compiles with the manifest's recovered GC/2.0 flags, applies all 209 relocations, and compares every allocated section against the SHA-verified original DOL. It also verifies exact section lengths and alignment padding. No instruction or relocation differences are masked. Source/object hashes and exact function/data mappings are recorded in `config/GSQE78/candidates/errnomodule.json`.

The isolated candidate is ready. The normal project build and full-DOL SHA check remain the integration gate; use the generated `PROGRESS.md` for current project totals.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Modules/errnomodule.c` | `.data` | `0x802E8938..0x802E8B76` (574 bytes) | `0x802E8B76..0x802E8B78` (2 bytes) |
| `Modules/errnomodule.c` | `.sdata` | `0x80377310..0x80377432` (290 bytes) | `0x80377432..0x80377438` (6 bytes) |

Current native objdiff credits `Modules/errnomodule.c`: 864 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
