# MSL error-string unit

`src/MSL/strerror.c` reconstructs the internal message switch and public `strerror` at `0x80127E08–0x80128288` (1,152 bytes). The original object filename and internal helper spelling are not preserved; `strerror.c` and `strerror_impl` are descriptive reconstruction names. The helper takes an error number and destination buffer, returns that buffer, and is distinct from the later three-argument `strerror_r` API.

The implementation is recovered directly from original branch destinations, the 100-entry jump table, message strings, and the fallback `sprintf` call. Its 42 specific mappings cover errors 0–40 with gaps, plus 77, 88, and 99. Other values use the original unknown-error format. The [NXP MSL C Reference](https://www.nxp.jp/docs/en/reference-manual/MSLCRM.pdf), printed pages 88–89 and 489–490, corroborates the MSL error-message family and public API; it is not treated as the original implementation source. No matching full reference implementation was found in the pinned community MSL trees.

The original pooled message data has a leading NUL. The first source literal explicitly contains this byte and is accessed at offset one, matching the original first-case `addi`. This is a deliberate representation of the recovered data layout, not a claim that the historical source used the same spelling. It adds no helper, unused object, or substitute instructions. The output buffer remains uninitialized static storage in BSS.

| Section | Address range | Ownership |
| --- | --- | --- |
| `.rodata` | `0x802ABC00–0x802ABF6D` | Leading NUL and pooled messages, 877 bytes |
| `.rodata` padding | `0x802ABF6D–0x802ABF70` | Three zero bytes |
| `.data` | `0x802D07C8–0x802D0958` | Compiler switch table, 400 bytes |
| `.bss` | `0x8033D6A0–0x8033D6E0` | Function-local output buffer, 64 bytes |

The initial auto rodata symbol includes the three padding bytes and must shrink from `0x370` to `0x36D`. The code follows the signal unit and ends immediately before the separately matched string functions.

Run `python3 scratch/msl_strerror/verify.py`. GC/1.3 with `-str reuse,pool,readonly` and the remaining manifest flags reproduces all code, messages, and switch entries exactly after 234 relocations. Three padding bytes and BSS placement are also verified; no fields are masked. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

All mappings and hashes are in `config/GSQE78/candidates/msl-strerror.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/strerror.c` | `.rodata` | `0x802ABC00..0x802ABF6D` (877 bytes) | `0x802ABF6D..0x802ABF70` (3 bytes) |

Current native objdiff credits `MSL/strerror.c`: 1,341 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
