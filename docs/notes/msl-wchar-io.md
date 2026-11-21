# MSL stream orientation

`src/MSL/wchar_io.c` reconstructs the complete retained `fwide` unit at `0x80129C64..0x80129CEC` (136 bytes). It checks that the stream is open, assigns its orientation when still unset, and returns the existing orientation otherwise. Its field accesses use the recovered 80-byte FILE layout in `src/MSL/stdio_internal.h`.

The implementation follows the [pinned Wind Waker source](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wchar_io.c), preserved unchanged under `reference/tww-msl/` with its upstream license. The switch intentionally retains the reference behavior for invalid orientation bits; no additional default return is introduced.

`python3 scratch/msl_wchar_io/verify.py` produces an exact 136-byte `.text` section with GC/1.3, `-O4,p`, deferred inlining, and `-use_lmw_stmw off`. There are no relocations or owned data sections. The candidate manifest records compiler flags and source/object/header hashes. Global integration is separately verified by the parent build.
