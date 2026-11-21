# Generated Python grammar

`src/Python/graminit.c` uses CPython 2.1's generated grammar as its source
reference, with the recovered parser ABI in `include/parser_abi.h`.
The retained tables describe 64 DFAs and 142 grammar labels. They contain no
executable functions and earn only data coverage.

The source owns `.data` at `0x802DF270..0x802E1E90` and `.sdata` at
`0x80376830..0x80376EA0`. The former contains 11,296 bytes; the latter has
1,642 emitted bytes followed by six alignment bytes retained in its split.
All 504 relocations were resolved and checked against the original table
contents before the full-DOL hash and objdiff integration checks passed.

Small arc arrays follow CodeWarrior's small-data allocation rules; larger
arrays, states, DFAs and label tables remain in normal data. The split includes
alignment bytes to preserve the next unit's placement. These bytes do not
represent extra grammar entries.

The registered source uses GC/2.0 and the standard recovered CPython flags.
The source retains upstream provenance and the license in
`reference/cpython-2.1/LICENSE`. The isolated verifier is
`scratch/graminit/verify.py`; canonical progress comes from the full build.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/graminit.c` | `.sdata` | `0x80376830..0x80376E9A` (1,642 bytes) | `0x80376E9A..0x80376EA0` (6 bytes) |

Current native objdiff credits `Python/graminit.c`: 12,938 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
