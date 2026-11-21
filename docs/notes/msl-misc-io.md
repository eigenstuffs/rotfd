# MSL/misc_io.c

The full retained unit consists of `__stdio_atexit` and `clearerr` at `0x80125AF0–0x80125B10` (32 bytes). The source follows the pinned [Strikers reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/misc_io.c). Unchanged references and upstream notices are preserved under `reference/strikers-msl/`; this is a community reconstruction, not an official SDK release.

`__stdio_atexit` installs `__close_all` into the external stdio exit callback, whose storage belongs to `abort_exit.c`. `clearerr` clears the EOF and error bytes in the shared recovered FILE layout. This unit owns no allocated data or padding.

`python3 scratch/msl_misc_io/verify.py` verifies all 32 instruction bytes after three relocations with GC/1.3 and the manifest flags, without masking. Mappings and hashes are in `config/GSQE78/candidates/msl-misc-io.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals remain in [PROGRESS.md](../../PROGRESS.md).
