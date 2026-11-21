# MSL/file_pos.c

The complete retained file-position unit contains `fseek`, `_fseek`, and `ftell` at `0x80125290–0x8012555C` (716 bytes). It owns no allocated data or padding. The next function, `wcstombs`, belongs to multibyte conversion support.

`src/MSL/file_pos.c` follows the pinned [Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/FILE_POS.c). The corresponding [Strikers source](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/file_pos.c) was retained for comparison. Unchanged source/header references and upstream notices remain in their reference directories. These are community reconstructions, not official SDK source releases.

The target omits the extra text-mode newline position adjustment found in the Strikers source. Ordinary inline `_ftell` C is reused by the public `ftell` and the relative-seek path; it emits no separate body. Seeking preserves the original buffered read-position optimization, flushes writes when required, updates state through the file-position callback, and reports failure with errno `0x28`. No critical-region calls appear in the retained wrappers.

Run `python3 scratch/msl_file_pos/verify.py`. GC/1.3 with the manifest flags produces all 716 instruction bytes exactly after applying seven relocations, without masking. The object has no unexpected allocated data sections. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Function mappings and source/header/object hashes are in `config/GSQE78/candidates/msl-file-pos.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress remains in [PROGRESS.md](../../PROGRESS.md).
