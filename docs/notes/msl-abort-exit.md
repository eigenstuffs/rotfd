# MSL/abort_exit.c

`exit` and `abort` are fully reconstructed in `src/MSL/abort_exit.c`. Their text occupies `0x80120FB0–0x80121104`: `exit` is 204 bytes and `abort` is 136 bytes. The source preserves destructor traversal, the stdio and console callbacks, reverse-order internal exit callbacks, and the terminal `_ExitProcess` call. `abort` raises signal 1 and sets the abort flag before common cleanup.

The retained data consists of the 64-pointer `__atexit_funcs` array at `0x8033D250–0x8033D350` and four globals at `0x80377CF8–0x80377D08`: `__aborting`, `__atexit_curr_func`, `__stdio_exit`, and `__console_exit`. All 272 bytes are zero-initialized. The public atexit table and its registration API are absent from this linked unit.

The source follows the exit logic in the pinned [Melee](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/abort_exit.c) and [SMS](https://github.com/doldecomp/sms/blob/c44637d42e09ec81973c4579e13ece8d0b0f5f58/src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/abort_exit.c) reconstructions, with the original abort path and retained storage recovered from GSQE78. Reference copies and available license records are retained alongside the other MSL references. Common cleanup is expressed as ordinary inline C and emits no extra function body.

No retained `__begin_critical_region`, `__end_critical_region`, or `__kill_critical_regions` body has been identified in this MSL text inventory. Neither original termination path calls such a helper. The pinned Melee critical-region source supplies an empty kill helper; its source and declaration are retained as comparative evidence. No critical-region body is fabricated or credited as matched source.

The preceding 12-byte function at `0x80120FA4` returns the `bad_exception` name and belongs to C++ runtime support. The following function at `0x80121104` begins allocation/free logic, beyond this unit's boundary. Assembly-only PowerPC helpers remain outside this candidate.

Run `python3 scratch/msl_abort_exit/verify.py` to compile with GC/1.3 and apply all 24 relocations. Every one of the 340 instruction bytes matches, and all owned zero-initialized storage lies within the original DOL BSS. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

All source, data, and compiler mappings are in `config/GSQE78/candidates/msl-abort-exit.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project progress is tracked in [PROGRESS.md](../../PROGRESS.md).
