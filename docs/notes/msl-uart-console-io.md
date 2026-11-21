# MSL UART console output

`src/MSL/uart_console_io.c` reproduces the retained `__write_console` function at `0x80129BA0..0x80129C64` (196 bytes). It initializes UART once at 57600 baud, forwards output to UART, and then invokes the MetroTRK console callback. A UART write failure clears the requested count and returns an error. The initializer remains ordinary inline C and contributes no separate function body.

The source is adapted from the [pinned Wind Waker reconstruction](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/uart_console_io.c). The unmodified reference and upstream license are in `reference/tww-msl/`. Typed callback declarations use the independently recovered local FILE ABI. The reference's trivial `__close_console` stub is absent from this retained unit; the game uses a separate MetroTRK close callback elsewhere.

The function-local `initialized` variable owns four zero-initialized bytes at `0x80377D18`, with four following alignment bytes through `0x80377D20`. It remains in `.sbss`.

`python3 scratch/msl_uart_console_io/verify.py` compiles with GC/1.3, `-O4,p`, deferred inlining, and `-use_lmw_stmw off`. All 196 instruction bytes match after applying all five relocations to recovered addresses. The verifier also checks `.sbss` ownership and alignment within the original DOL's zero-initialized range. The candidate manifest records exact flags, hashes, callbacks, and the compiler-local variable name. Global integration is separately verified by the parent build.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `MSL/uart_console_io.c` | `.sbss` | `0x80377D18..0x80377D1C` (4 bytes) | `0x80377D1C..0x80377D20` (4 bytes) |

Current native objdiff credits `MSL/uart_console_io.c`: 4 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
