# MSL/signal.c

The complete retained signal unit contains `raise` at `0x80127D1C` (176 bytes) and `signal` at `0x80127DCC` (60 bytes), ending at `0x80127E08`. The only data is a six-entry function-pointer table occupying 24 zero-initialized bytes at `0x8033D688–0x8033D6A0`.

This C implementation was reconstructed directly from original instructions and data. Both functions accept signal numbers 1–6. Invalid registration returns `SIG_ERR` and writes the original error value 26; invalid delivery returns -1. Delivery resets handlers other than `SIG_IGN` before invoking them. The default `SIGABRT` case returns to the caller; the original abort path performs process shutdown afterward. `SIGABRT=1` is corroborated by that abort path at `0x8012107C` and the matched Python signal module.

The preceding `__StringRead` routine belongs to scanf.c. The following routine begins at `0x80127E08` and is outside this unit.

Run `python3 scratch/msl_signal/verify.py` to compile with GC/1.3 and apply all six relocations. The verifier checks every one of the 236 instruction bytes and the complete zero-initialized table range. Result: zero differences. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

All mappings and flags are recorded in `config/GSQE78/candidates/msl-signal.json`. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals are in [PROGRESS.md](../../PROGRESS.md).
