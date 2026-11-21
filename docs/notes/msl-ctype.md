# MSL/ctype.c

The complete retained ctype text consists of `tolower` and `isspace` at `0x801246B0–0x801246EC` (60 bytes). The source follows the pinned [Strikers source and header](https://github.com/yannicksuter/smstrikers-decomp/tree/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common), with unchanged references and upstream notices preserved under `reference/strikers-msl/`. These are community reconstructions, not official SDK releases.

All three 256-byte maps are retained in `.data`: `__ctype_map` at `0x802D0260`, `__lower_map` at `0x802D0360`, and `__upper_map` at `0x802D0460`. The complete 768-byte range ends at `0x802D0560` and owns no padding. Other inline header routines do not have retained function bodies in this unit. `tolower` preserves EOF and masks non-EOF indices to one byte; `isspace` reads the original classification bits.

`python3 scratch/msl_ctype/verify.py` verifies all 60 instruction bytes and 768 initialized data bytes after four relocations, with GC/1.3 and the manifest flags. No relocation fields are masked. Mappings and hashes are in `config/GSQE78/candidates/msl-ctype.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals remain in [PROGRESS.md](../../PROGRESS.md).
