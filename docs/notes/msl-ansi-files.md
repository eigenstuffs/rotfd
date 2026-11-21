# MSL/ansi_files.c

The complete retained unit occupies `0x80121EEC–0x801221EC`: five routines and 768 instruction bytes. It traverses the open-file list to flush line-buffered writers, flush all files, and close all files; initializes a `FILE` object; and finds or allocates an unused file object. No critical-region calls occur in the original close-all path.

`src/MSL/ansi_files.c` follows the pinned [Strikers reconstruction](https://github.com/yannicksuter/smstrikers-decomp/blob/c62fc6a0ed90f4eacc8cca9b231f1d4aaf16ad0b/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/ansi_files.c), with the original absence of critical-region calls corroborated by the [Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ansi_files.c). Reference copies and license/provenance records are preserved under their respective `reference/` directories. These are community reconstructions, not official MSL SDK source releases.

The recovered 80-byte `FILE` layout lives in `src/MSL/stdio_internal.h`, local to the MSL stdio family. Its mode and state bitfields reproduce the original halfword/byte accesses. `__init_file` receives the four-byte file-mode aggregate using the original compiler ABI. This header requires the include path `-i src/MSL`; the candidate manifest records it. Calls to the MSL allocation APIs use `__msl_malloc` and `__msl_free` to distinguish them from game wrappers with the standard names.

| Storage | Address range | Contents |
| --- | --- | --- |
| `.data` | `0x802CFFB8–0x802D00F8` | Four `FILE` objects: stdin, stdout, stderr, empty |
| `.bss` | `0x8033D388–0x8033D488` | stderr buffer, 256 bytes |
| `.bss` | `0x8033D488–0x8033D588` | stdout buffer, 256 bytes |
| `.bss` | `0x8033D588–0x8033D688` | stdin buffer, 256 bytes |

The three buffers are emitted in reverse declaration order, and the file table links the three standard streams to the final empty file. This unit owns no alignment padding. It follows `alloc.c`; the function beginning at `0x801221EC` starts decimal conversion/arithmetic support and belongs to another unit.

Run `python3 scratch/msl_ansi_files/verify.py`. GC/1.3 with the full manifest flags produces all 768 instruction bytes and 320 initialized bytes exactly after applying 42 relocations; all 768 zero-initialized bytes lie in original DOL BSS. No relocation fields are masked. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The manifest is `config/GSQE78/candidates/msl-ansi-files.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals remain in [PROGRESS.md](../../PROGRESS.md).
