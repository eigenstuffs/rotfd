# Python mixed object and scalar bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty original wrappers are reconstructed in ordinary C++ and match all 4,416 text bytes, 400 exception metadata bytes and 297 actual relocations in isolated and source-path compilation. Their original C entry names remain intact. No additional allocations or helper functions are emitted.

Each wrapper parses its original format string, converts two Python objects to the observed native type table entries, then invokes the original native method or virtual slot with the observed scalar widths and argument order. Optional integer-object arguments preserve their original defaults; optional floats refer to the original read-only defaults. Category wrappers dereference the converted category word before calling their native methods.

The optional signed-byte wrapper at 800D0514 requires a signed-byte value converted through long at its call site, retaining both observed sign-extension instructions. The category reset/add wrapper at 800D904C uses an ordinary inline helper to preserve the receiver and category across reset; this reproduces the original register lifetimes. Initial near probes and successful variants are preserved under scratch/game_python_mixed_objects.

All allocated text, extab and extabindex extents are inventoried with their real relocations. Complete original exception/startup tables are audited, including each original index entry. Sources and both shared Python ABI headers are frozen by SHA256. Production full executable acceptance remains pending integration.
