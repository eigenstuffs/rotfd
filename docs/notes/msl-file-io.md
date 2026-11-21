# MSL/file_io.c

The complete retained file I/O unit consists of `__get_file_modes`, `freopen`, `fopen`, `fflush`, and `fclose`, occupying `0x80124D88–0x80125290` (1,288 bytes). It owns no allocated data or padding. The following `fseek` starts the separate file-position unit.

`src/MSL/file_io.c` follows the pinned [Strikers reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/file_io.c), with flush/close behavior also corroborated by the [Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/file_io.c). Unchanged reference copies, revisions, and upstream notices are retained in their reference directories. These are community reconstructions, not official SDK source releases.

The target retains `freopen` as a separate routine; `fopen` acquires an unused `FILE` and passes it to that routine. The reopened stream closes its old handle, frees an owned buffer, clears errors, parses the mode string, and requests a 4,096-byte initial buffer before opening the new handle. That size differs from the 1,024-byte request in the Strikers open path. Append mode seeks to the end. `fflush` and `fclose` preserve the original state transitions, callback calls, and error results. No critical-region calls occur in this retained unit.

The mode parser requires signed character promotion. GC/1.3 with `-char signed`, `-use_lmw_stmw off`, `-inline deferred`, and the remaining manifest flags reproduces the original code and scalar register saves. The shared FILE layout remains in the source-local `stdio_internal.h`.

Run `python3 scratch/msl_file_io/verify.py`. All 1,288 instruction bytes match after sixteen relocations, without masking; the object has no unexpected allocated data sections. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Exact function mappings and source/header/object hashes are recorded in `config/GSQE78/candidates/msl-file-io.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).
