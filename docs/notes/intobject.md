# Integer objects (`Objects/intobject.c`)

The complete CPython 2.1 integer translation unit is reconstructed in
`src/Objects/intobject.c`: 33 functions and 11,084 code bytes. All initialized
sections match the original DOL byte for byte after applying all 604 ELF
relocations. The BSS allocation sizes and their placement inside the original
DOL zero-initialized range are also checked. Whole-program integration remains
a separate check owned by the main build.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | `80147184..80149CD0` | 11,084 |
| `.data` | `802D3478..802D37D0` | 856 |
| `.sdata` | `803761A8..803761D8` | 48 |
| `.sdata2` | `80379F78..80379F80` | 8 |
| `.bss` | `8033DAE0..8033DC74` | 404 |
| `.sbss` | `80377DF8..80377E00` | 8 |

The source follows the official reference at
`reference/cpython-2.1/Objects/intobject.c`, whose license is retained at
`reference/cpython-2.1/LICENSE`. The recovered ABI declarations are local to
the unit. The compiler is GC/2.0, with optimization
`level=4,nopeephole,speed`, `-inline auto,deferred` and `-pool off`; the full
flag list and symbol mappings are in
`config/GSQE78/candidates/intobject.json`.

The original contains the complete public integer API, including string and
Unicode parsing, conversion, allocation, and cleanup. Its number table and
all arithmetic operations match CPython 2.1, including the half-word checked
multiplication algorithm. `err_ovf`, `fill_free_list`, and `i_divmod` are
inline-only helpers, matching their absence as standalone original functions.
The reconstructed standard-library macros use an unsigned-character index
into the MSL ctype table, an 80-byte `FILE`, and `stderr = &__files[2]`.
The 8-byte `.sdata2` constant supports signed-integer to double conversion.

`small_ints` has 101 pointers and owns exactly `0x194` bytes. The earlier
generated label covered `0x198` bytes; its final four bytes,
`8033DC74..8033DC78`, are padding outside this source array. `block_list` and
`free_list` each occupy four bytes at `80377DF8` and `80377DFC`.

Re-run the isolated check with:

```sh
python3 scratch/intobject/verify.py
```

The verifier recompiles the source, checks the original DOL SHA-1, applies
absolute, high/low, branch, and SDA relocations at the recovered addresses,
then compares every initialized section byte. It rejects section size changes
and does not mask branch or address differences. The candidate manifest records
the exact source and object hashes from this verification. Source matching
credit is appropriate only after registration and a successful full DOL build.
