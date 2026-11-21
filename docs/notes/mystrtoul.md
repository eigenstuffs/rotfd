# Integer parsing (`Python/mystrtoul.c`)

Both linked routines from CPython 2.1 are reconstructed exactly in
`src/Python/mystrtoul.c`. The complete `.text` range is
`8019F914..8019FBA0`: `PyOS_strtol` occupies `0xB0` bytes and
`PyOS_strtoul` occupies `0x1DC` bytes. All 652 bytes match after applying
11 ELF relocations. This unit owns no data sections. Whole-program integration
is a separate main-build check.

The official reference is `reference/cpython-2.1/Python/mystrtoul.c`;
its license is retained at `reference/cpython-2.1/LICENSE`. Source behavior
is unchanged. Matching requires the MSL character helpers: bitmap masks
`6` for whitespace, `0x10` for digits, and `0x80` for uppercase characters.
The `tolower` helper preserves EOF and indexes `__lower_map` with an
unsigned-character cast. `Py_CHARMASK` retains the reference's `c & 0xff`.
These distinct expressions affect register allocation in this compiler.

`__lower_map` is the 256-byte table at `802D0360`; the shared ctype table and
`errno` addresses are already recorded by the integer-object reconstruction.
The complete flags and mappings are in
`config/GSQE78/candidates/mystrtoul.json`.

```sh
python3 scratch/mystrtoul/verify.py
```

The check recompiles with GC/2.0, applies every relocation, validates the
original DOL hash, and compares the entire text section without masking
instruction or address differences. Section-size changes fail. The manifest
records source and object hashes from the verified candidate.
