# MSL/buffer_io.c

The full retained buffering unit contains `setvbuf`, `__flush_buffer`, `__load_buffer`, and `__prep_buffer`, occupying `0x80123E78–0x80124184` (780 bytes). It owns no allocated data or alignment padding. `fputs`, beginning at the upper boundary, belongs to character I/O support.

`src/MSL/buffer_io.c` follows the pinned [Strikers source](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/buffer_io.c), with the platform no-op newline helpers corroborated by the [Wind Waker source](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/buffer_io.c). Unmodified reference files and upstream notices are retained in their reference directories; these are community reconstructions, not official SDK source releases.

The target's read-buffer path advances the file position by the bytes read and performs no additional newline-position scan. `setvbuf` contains no critical-region calls. Calls that allocate or free replacement buffers resolve to `__msl_malloc` and `__msl_free`. The shared 80-byte `FILE` layout is recorded in the source-local `stdio_internal.h` and [ansi_files notes](msl-ansi-files.md).

GC/1.3 requires `-inline auto,deferred` for this unit. Automatic inlining reproduces the copies of `__prep_buffer` inside load/flush while retaining the external body; deferred emission reproduces the original reverse function order. All helpers remain ordinary C; no linker patch or invented retained helper is used.

Run `python3 scratch/msl_buffer_io/verify.py`. All 780 instruction bytes match after applying three relocations, without masking branch fields. The verifier also asserts that the object contains no unexpected allocated sections. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The full flags, function mappings, and source/header/object hashes are in `config/GSQE78/candidates/msl-buffer-io.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).
