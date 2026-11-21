# MSL/char_io.c

The complete retained character I/O unit is reconstructed in `src/MSL/char_io.c`: `fputs`, `fputc`, `__putc`, `fgets`, and `__getc`, at `0x80124184–0x801246B0` (1,324 bytes). It owns no allocated data or alignment padding. The next two functions are `tolower` and `isspace`, a separate ctype unit.

The primary reference is the pinned [Strikers character I/O reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/char_io.c). Unchanged source/header copies and upstream notices are retained in `reference/strikers-msl/`. This is a community reconstruction, not an official MSL SDK source release.

The target retains `__getc` as a separate slow-path helper, while the reference inlines that logic inside `fgets`. The reconstruction expresses its original error checks, pushed-back character handling, buffer reload, and EOF handling as ordinary C. Indexing `file->ungetc_buffer[io_state - __rereading]` reproduces the original addressing order. `fputc` implements the same orientation check and direct buffered write used inside `fputs`; both fall back to `__putc` when the buffer is exhausted. No critical-region calls appear in the original paths.

GC/1.3 with `-char signed` reproduces the original signed promotion of source string characters in `fputs`; input and pushed-back character results remain unsigned bytes. `-use_lmw_stmw off` preserves the original scalar register saves. The full flag list includes `-inline deferred` and `-i src/MSL`, using the shared [recovered FILE layout](msl-ansi-files.md).

Run `python3 scratch/msl_char_io/verify.py`. All 1,324 instruction bytes match after applying twelve relocations, without masking. The verifier asserts that the object has no unexpected allocated data sections. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Function mappings and source/header/object hashes are in `config/GSQE78/candidates/msl-char-io.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).
