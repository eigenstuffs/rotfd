# Render object traversal and callback dispatch

`src/Game/render_object_dispatch.cpp` owns `fn_801E7D1C` at
`801E7D1C..801E81AC`, 1,168 matching code bytes. Address-based symbols are
retained; the source uses partial views for the observed object list, render
context, geometry, material and entry records.

The traversal reads the pointer array at 74 and its count at 4074, rejects
objects with flag 10000, and filters resolved materials by a view-dependent
mask. It resolves geometry, prepares the context's matrix product and other
object references, clears the word at BCC, and conditionally runs a bounds
query. It chooses a transformed explicit sphere or the query's output sphere,
collects up to 64 overlapping entries, and dispatches the geometry callback.
An eligible material then receives its conditional and final callbacks.

The matrix product preserves both the native temporary and assignment copy.
Vector subtraction uses a three-component constructor, avoiding a spurious
copy emitted for a named returned aggregate. The inner array accessor accepts
an unsigned index, which preserves the original offset-based iteration.
Explicitly scoped local declarations reproduce the original register
allocation; no source-authored assembly or instruction patching is used.
The 32-byte entry size and relevant view extents are compile-time checked.

`scratch/game_render_object_dispatch/verify.py --production` checks every
retained byte with all five actual relocations. The object contains only the
1,168-byte function: no weak helpers, data or alignment bytes receive credit.
All 662 source units remain exact; the complete DOL is byte-identical and all
23 tests and progress/extent/assembly audits pass. The initial baseline is
unchanged. Existing fallback/native-padding accounting warnings remain
without source regressions. Evidence:
`scratch/render_object_dispatch_checkpoint.json`.
The viewport-render preparation routine at 801E8274 and called bounds/matrix
helpers retain their existing ownership and are outside this split.
