# Movie block interpolation

`src/Game/movie_block_interpolation.cpp` reconstructs the contiguous four-function
range `80292AC8..80293158`, totaling 1,680 bytes:

| Function | Size | Operation |
| --- | ---: | --- |
| `fn_80292AC8` | 156 | Copy a four-by-four byte block. |
| `fn_80292B64` | 412 | Average each source byte with its right neighbor, rounding up. |
| `fn_80292D00` | 428 | Average each source byte with the corresponding byte in the next row, rounding up. |
| `fn_80292EAC` | 684 | Average the four samples of each two-by-two source neighborhood, adding two before the shift. |

Each function takes independent input and output row strides. These functions
supply the integer and half-pixel cases used by the neighboring movie motion
compensation routine. The source keeps the interpolation rows explicitly
expanded as four ordinary column loops. A nested four-by-four loop reproduces
the copy function, but the larger interpolation bodies exceed the compiler's
outer-loop full-unrolling threshold. Naming the current source row separately
from the next row preserves the native pointer allocation and schedule.

The compiler is GC/1.2.5 with ordinary movie flags: `-O4,p -inline auto`, Gekko
hardware FP, exceptions and RTTI off, `-use_lmw_stmw on`, and `-fp_contract on`.
The source has no inline assembly, patched instructions, relocation masks or
compiler-generated helper function dependencies.

Run `python3 scratch/movie_worker_continuation/verify_block_interpolation.py`
for the strict isolated check. It verifies the normalized DOL SHA-1, all four
symbol names, binding, types, offsets and sizes, and every emitted allocated
byte. The only allocated section is `.text`, 1,680 bytes aligned to four, with
no allocated relocations, data, BSS, exceptions or padding. Four relocations in
nonallocated compiler metadata point to the four functions.

Integration owns only `.text 80292AC8..80293158`, alignment four. Set all four
function scopes explicitly global. Register the unit NonMatching first with
the GC/1.2.5 movie flags, validate it, then promote it. The adjacent motion
compensation routine and original data remain outside this partial text split.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
