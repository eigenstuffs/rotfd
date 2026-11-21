# MSL/direct_io.c

The complete retained direct I/O unit contains `__fwrite`, `fwrite`, `__fread`, and `fread`, occupying `0x801246EC–0x80124D88` (1,692 bytes). It owns no allocated data or padding. The next routine parses file mode strings and belongs to `file_io.c`.

`src/MSL/direct_io.c` follows the pinned [Strikers reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/direct_io.c). Reference source/header copies and upstream notices remain under `reference/strikers-msl/`. These are community reconstructions, not an official MSL SDK source release.

Both public wrappers call the corresponding internal implementation and retain a 32-byte body. The original wrappers contain no critical-region operations. Wide orientation checks and pushed-back wide-character support are retained. The internal implementations preserve buffered and direct paths, error/EOF state updates, line-buffer flushing, temporary buffer replacement, and the distinct original item-count calculations: reads count complete items, while the write result uses the original rounded-up byte count.

Run `python3 scratch/msl_direct_io/verify.py`. GC/1.3 with the manifest flags reproduces all 1,692 instruction bytes exactly after twenty relocations, with no masked fields or unexpected allocated sections. This unit uses `-use_lmw_stmw on`, `-inline deferred`, and the source-local FILE header via `-i src/MSL`. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Mappings and source/header/object hashes are recorded in `config/GSQE78/candidates/msl-direct-io.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).
