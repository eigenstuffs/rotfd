# MSL/strtoul.c

The linked integer conversion unit is reconstructed in `src/MSL/strtoul.c`: `atoi` at `0x80129768` (192 bytes) and the previously unnamed `__strtoul` at `0x80129828` (888 bytes). The complete text range is `0x80129768–0x80129BA0`. Its only data is the 68-byte, 17-entry compiler-generated switch table at `0x802D0958–0x802D099C`.

`strtol` is an inline-only helper used by `atoi`. No standalone `strtol` or `strtoul` is linked here. The next routine at `0x80129BA0` belongs to console I/O. The input callback is `__StringRead` at `0x80127C8C`, belonging to the separate scanning implementation.

The source follows the [Melee MSL reconstruction](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/strtoul.c), checked against the [SMS reconstruction](https://github.com/doldecomp/sms/blob/c44637d42e09ec81973c4579e13ece8d0b0f5f58/src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/strtoul.c). Unchanged references and provenance records are retained under `reference/melee-msl/` and `reference/sms-msl/`.

The target contains an additional whitespace counter. Leading spaces are consumed without contributing to the maximum field width; successful character consumption includes them when setting `chars_scanned`. The retained code also preserves overflow behavior, base autodetection, MSL ctype masks, and the EOF branch in `toupper`. These behaviors were recovered from original instructions and verified without patching object bytes.

GC/1.3 with `-O4,p`, `-inline deferred`, and `-use_lmw_stmw on` produces the exact retained unit. The full flags and symbol mappings are recorded in `config/GSQE78/candidates/msl-strtoul.json`. Run:

```sh
python3 scratch/msl_strtoul/verify.py
```

The verifier compiles normal C, applies all 31 relocations (including every jump-table entry), and compares every allocated byte against the original DOL. All 1,080 instruction bytes and 68 data bytes match. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals are in [PROGRESS.md](../../PROGRESS.md).
