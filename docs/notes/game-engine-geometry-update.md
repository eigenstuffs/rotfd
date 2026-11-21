# Uncredited geometry update probes

No source or matching credit is claimed by this investigation. Research remains
in `scratch/game_engine_geometry_update_continuation/`.

`fn_801DDB3C` (192 bytes) copies a start point, stores end minus start as the
direction, computes its approximate magnitude, and normalizes only when that
magnitude exceeds a versioned threshold. `fn_801DC5E8` and `fn_801DC784` (304
bytes each) transform record positions with a 4x4 matrix at owner `+0x124`,
transform directions with the owner's 3x3 basis at `+0x30`, scale radius by the
matrix's approximate first-column magnitude, and associate the owner pointer.
Their records have strides `0x28` and `0x48`, with owner pointers at `+0x1C`
and `+0x30` respectively.

The originals use `frsqrte f4,...` followed immediately by `fres`, with no
intermediate rounding. CodeWarrior's standard built-ins declare
`double __frsqrte(double)` and `float __fres(float)`. Ordinary C++ composition
therefore inserts `frsp` between the operations. Redeclaring the built-in with
a different parameter type is rejected by the compiler. The original fixed
scratch register is also absent from the normal intrinsic allocation, changing
later floating-point allocation. A hand-written inline square-root helper is
a possible original provenance, but has not been established. No assembly
helper was introduced to force these probes to match.

The initial ordinary C++ bodies and failed intrinsic-shape probes are retained
for future research. The entry-point extents, all original exception-index
entries, and constructor pointers were inspected; no exception or constructor
ownership was found for these functions. Original assembly ownership remains
untouched, and the production integration list is empty.
