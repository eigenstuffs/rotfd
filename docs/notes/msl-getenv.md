# GameCube getenv stub

The retained `getenv` function at `0x80129CEC..0x80129CF4` unconditionally returns a null pointer. The reconstructed C source emits the exact eight original bytes under GC/1.3 with the ordinary MSL flags. It contains no data or code/data relocations.

This is a reconstruction from the complete original function, not an adaptation of an external implementation. Only this function's retained scope is claimed; the original encompassing translation-unit extent has not been established. An environmentless GameCube runtime returning null is the observed behavior, not a proposed replacement implementation.

Run `python3 scratch/msl_getenv/verify.py` for the isolated compiler and DOL comparison. The candidate manifest is `config/GSQE78/candidates/msl-getenv.json`. Central full-DOL integration passes the original SHA-1 and native objdiff checks.
