# Engine raster span fragments

Three ordinary C units reconstruct three complete functions, 940 bytes of
`.text`, and no data. The new shared declarations are isolated in
`include/Game/engine_raster_span.h`.

| Source suffix | Owned text | Bytes | Extra flags |
| --- | --- | ---: | --- |
| `engine_raster_span_80238310.c` | `80238310..802383D8` | 200 | `-opt nocse` |
| `engine_raster_span_802383D8.c` | `802383D8..802385C0` | 488 | `-use_lmw_stmw on` |
| `engine_raster_span_802385C0.c` | `802385C0..802386BC` | 252 | `-opt nocse` |

The compiler is standard Game GC/1.3.2 with the per-object additions above.
All three function symbols need global scope. No existing source/header is edited.
These partial text splits do not establish an original translation unit.

## Observed behavior

The raster prefix contains a 16-bit index buffer at offset 0xC, width at 0x30,
and height at 0x34. `fn_80238310` converts a point to integer coordinates and
returns one index through its output pointer, returning 1 on success and 0 for
an out-of-range coordinate. `fn_802385C0` converts and checks coordinates the same
way, caches the index buffer, obtains the encoded color from the original
`fn_80238900`, and stores it. Negative input values subtract the original
`lbl_8037B2D8` bias (approximately 0.999999) before truncation; other values
truncate directly. Both use the original zero constant at `lbl_8037B2DC`.
The separate original loads of zero require disabling common-subexpression
elimination. This recovers all original loads and register choices without
volatile fields, assembly, or instruction substitution.

`fn_802383D8` truncates two endpoints directly, checks both against the observed
width/height, encodes the color once, and fills the half-open rectangle with
nested loops. The ordinary compiler unrolls the inner loop eight times exactly
as in the original. Declaring the cached buffer before the row/column variables
recovers the native register allocation. The compiler's lmw/stmw option produces
the observed five-register prologue and epilogue.

All coordinate checks preserve the original inclusive upper-bound acceptance:
a coordinate is rejected when greater than width/height, rather than when equal.
The source does not change these observed conditions.

## Verification and ownership

`scratch/engine_raster_span_20261010f/final_integration.json` records the complete
section extents, function bindings, compiler options, and all 10 real relocations.
The strict verifier recompiles the production source, checks all allocated
sections and emitted function extents, applies each REL24/SDA21 relocation to
its versioned target, and compares every owned byte directly to the protected
DOL without masking. The helpers inline completely and emit no additional code
or data. Both `verify.py` and `audit.py` pass on the final formatted sources.

The original complete function extents are checked against generated assembly.
All 3,141 original `.extabindex` records and the full 24-entry `.ctors`/8-entry
`.dtors` sections have no references into these functions. The source owns no
startup, exception, data, or BSS bytes. Original constants, the color encoder,
and all neighboring functions/data retain their existing ownership. The
ownership report preserves the original fallback ranges. Central NonMatching
registration, full DOL hash verification, native report comparison and promotion
remain the integrator's acceptance steps.

The nearby line-drawing function `fn_80238180` has a 400-byte ordinary probe
with five differing instruction words and remains uncredited. Reordering the
two raster branches' independent setup statements preserves the original
extent, branch schedule, and color-encoder relocation. The five remaining
differences are register choices at offsets `0xC4`, `0xD0`, `0xE8`, `0xF0`,
and `0xF8` in the first branch. The best private source is
`scratch/engine_raster_span_20261010f/line_setupB_08.c`. The earlier decoder
probe was superseded by the exact 176-byte source now integrated at
`fn_802380D0`; see [bitmap color decode](game-bitmap-color-decode-802380d0.md).

Further private probes reused dead coordinate locals for the first branch's
step and permuted 120 groups of local declarations. None resolved the five
remaining register choices; the declaration variants that kept the original
instruction schedule retained the same five differences. These probes remain
uncredited in `scratch/engine_raster_span_20261010f/`.
