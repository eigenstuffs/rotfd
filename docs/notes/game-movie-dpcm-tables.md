# Movie DPCM delta and index tables

`src/Game/movie_dpcm_tables.c` reconstructs all 3,560 bytes of
`lbl_802F23A0` at `802F23A0..802F3188`. Its source contains 89 editable
quantization steps and constant-expression macros for the delta and next-index
tables. No extracted instruction or binary byte arrays are counted as code.

Each step `s` supplies eight magnitudes. For nibble `n` in zero through seven,
the magnitude is `(s>>3)` plus `(s>>2)` when bit zero is set, `(s>>1)` when bit
one is set and `s` when bit two is set. The original decoder adds or subtracts
the magnitude according to the nibble's sign bit and clamps the sample to the
signed sixteen-bit range.

The next quantization index uses adjustments `-1, -1, -1, -1, 2, 4, 6, 8`,
clamped to zero through 88. The table layout is 89 rows of eight four-byte
signed deltas, followed at offset `B20` by 89 rows of eight unsigned index
bytes. Size and offset checks preserve the original packed extent. The object
remains mutable in `.data`, as in the original executable.

GC/1.2.5 emits exactly 3,560 bytes aligned to eight. The verifier checks every
byte against the DOL and independently checks every row's delta/index formulas.
There are no code, padding bytes or relocations. The neighboring 1,044-byte
audio decoder remains a private source probe. It now emits the complete
1,044-byte body, with eight differing instructions from its larger stack frame
and saved-register offsets. It earns no matching code credit.

The linked ELF proof, byte-identical DOL, all prior source/header hashes and
matches, immutable baseline, protected input checks, source audits and all
23 tests pass. The four preceding alignment bytes at `802F239C..802F23A0` retain explicit
original ownership in `original/platform_movie_dpcm_padding.s` and receive no
source credit. Splitting this data adds one provisional native unit without
changing code, function or data byte denominators. See
`scratch/movie_dpcm_tables_checkpoint.json`.
