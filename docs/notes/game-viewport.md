# Viewport rendering and lifetime

Three adjacent C++ routines at `0x801F0290..0x801F0518` reproduce 648 game code
bytes. The draw routine checks its enabled flag and context, gets the rectangle
and projection scales, calls the engine's rectangle method, installs a
perspective matrix, sets the graphics viewport and scissor, and draws its base
content. Its constructor and deleting destructor restore the same virtual
table at offset eight. Original class and method names remain unknown.

The matrix helper computes `zfar / (zfar - znear)` with caller values
`0.0001f` and `32.0f`. Keeping this as an ordinary inlined helper reproduces
the original compiler's constant folding and floating-point allocation.
Writing the final coefficients directly folds extra arithmetic and changes
the code. The generated 32-byte constant pool at `0x8037A698..0x8037A6B8`
includes all five floats, alignment, and the integer-conversion double.

`include/game_engine.h` shares the observed engine layout with the controller
unit: its virtual pointer is at `0x278`, notification slot at `0xAC`, and
rectangle slot at `0xB0`. Unknown slot declarations preserve the ABI and are
not reconstructed function bodies. This unit's original virtual table and
base constructor/destructor remain external.

GC/1.3.2 with the normal scalar-save game flags matches every instruction,
constant and all 24 relocations. `scratch/viewport/verify.py` checks isolated
objects. Acceptance additionally requires the complete DOL hash and native
objdiff checks recorded in the candidate manifest.
