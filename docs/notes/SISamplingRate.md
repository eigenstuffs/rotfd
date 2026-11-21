# Dolphin controller sampling-rate tables

`SISetSamplingRate` and `SIRefreshSamplingRate` match all 264 original text bytes at `80299818..80299920`, which is the end of the executable's main text section. The projectPiki/pikmin2 SDK reconstruction supplies the exact sampling tables and algorithm: clamp the interval, select the video-standard table, double the horizontal setting for the observed VI mode, then apply the polling coordinates with interrupt state preserved.

GC/1.2.5n with `-O4,p -inline auto`, normal peephole optimization, reproduces every instruction and relocation. There is no inline assembly. The register binding at `CC00206C` is the reference's ordinary halfword memory access. Existing ABI headers are read only.

Initialized data at `802F33B0..802F3443` is exactly 147 bytes, aligned to eight: two 48-byte tables of twelve `{u16, u8}` records and a 51-byte diagnostic string. Each table record's fourth byte is its natural structure alignment. These bytes match the original DOL, and the candidate enumerates both tables and the literal separately.

The final 29 zero bytes at `802F3443..802F3460` are terminal alignment of the original initialized data section and remain outside source-owned data. Small BSS owns only the four-byte `SamplingRate` word at `803781B0..803781B4`, aligned to eight. `803781B4` is the end of the original overall BSS extent; there is no additional four-byte tail to claim or emit.

`SISamplingRate.json` records the complete source extent and padding evidence. The `scratch/si` compile/verification probes check both functions and all 147 initialized bytes. The integrated source passes full-game byte equality, native objdiff code/data checks and the original-source regression audit; the report credits exactly 151 data/BSS bytes. Reference provenance and hash are saved under `reference/pikmin2-sdk/PROVENANCE.md`.
