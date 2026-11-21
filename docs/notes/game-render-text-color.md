# Render text color and integer position

The isolated source is uncredited. Full production linking cannot export its compiler-local conversion pool to the four remaining original assembly consumers. Its temporary configure/split entries were removed so native progress cannot count an unlinked exact object. The shared original constant remains in assembly.

`src/Game/render_text_color.cpp` reconstructs `fn_8027DBA8`, 200 bytes at `8027DBA8..8027DC70`, as ordinary C++ compiled with GC 1.3.2 and the standard Game flags.

The routine converts normalized RGB components into the font's three byte fields, truncates both floating screen coordinates to integers, converts them back to floats, and calls `fn_8027B790(font,x,y,text)`. The callee's pointer argument follows the two float arguments in the source signature; this preserves the native position pointer until its loads are complete. Byte local types and their evaluation order reproduce the native floating conversion schedule.

The strict isolated verifier, `scratch/game_render_text_color/verify.py`, checks all 200 relocated text bytes and all eight emitted `.sdata2` bytes. Three actual retained relocations comprise the external color scale, the source-local signed-integer conversion literal, and the text call. The object emits no helper functions, padding, BSS, constructors, destructors, or exception entries. The original SHA1 and the complete extabindex/ctors/dtors tables are checked.

The compiler's eight-byte `4330000080000000` conversion literal owns the native pool at `8037B7B8..8037B7C0`. This pool is shared by original text: its complete direct SDA2 consumer list is `8027D94C`, `8027DAF4`, `8027DBE8`, `8027E740`, and `8027EFC0`; only `8027DBE8` belongs to the retained function. No aligned absolute DOL pointers enter the pool. The other four consumers remain outside this partial text split and must keep resolving to the same native pool. `original_literal_audit.json` preserves their exact instructions.

The matching source is frozen for central integration. This isolated result does not by itself establish full-DOL acceptance; that is performed by the parent integrator.
