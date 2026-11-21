# MSL/scanf.c

`__StringRead` is the only retained scan callback in this translation unit, at `0x80127C8C–0x80127D1C` (144 bytes). It reads a byte, reports end of input, permits one-character pushback through its input state, and exposes that state to the scanner. No allocated data or relocations belong to this unit.

The boundary evidence is explicit in the surrounding code: the previous routine at `0x80127C6C` is the random-number generator using multiplier 1103515245 and increment 12345; the following routine at `0x80127D1C` implements `raise` through six signal handlers. Neither is a scan callback. No adjacent `__FileRead` implementation is retained.

The source is adapted from the [SMS MSL reconstruction](https://github.com/doldecomp/sms/blob/c44637d42e09ec81973c4579e13ece8d0b0f5f58/src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/scanf.c), retained unchanged in `reference/sms-msl/scanf.c` with its repository license. The equivalent helper in the pinned Melee `string.c` was also checked. The original uses signed-byte conversion for the null test and returns the original unsigned byte value. The recovered C expresses the input value and test conversion explicitly to reproduce that behavior.

Reproduce the complete isolated byte comparison:

```sh
python3 scratch/msl_scanf/verify.py
```

GC/1.3 with the MSL flags in `config/GSQE78/candidates/msl-scanf.json` generates all 144 instruction bytes exactly. The verifier asserts that text is the only allocated section and compares every byte without masking. Original DOL SHA-1: `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Full-DOL integration passes the original SHA-1 and native objdiff checks; overall source progress is reported in [PROGRESS.md](../../PROGRESS.md).
