# Surface, mode and pose production acceptance

The `surface-mode-pose` checkpoint accepts three independently reviewed C++
functions: `fn_8007AF08` (surface adjustment, 1,216 bytes), `fn_8007626C` (mode
preparation, 1,472 bytes), and `fn_800E466C` (pose application, 1,632 bytes).
Their 4,320 code bytes and 308 exception metadata bytes match the original.

The full build preserves original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, with no baseline regressions and all
43 repository tests passing. All 174 native weak override cases and every
preceding acceptance gate pass. Both actual native ELFs retain every byte of
these functions and their owned metadata, select the six original accepted
strong destructors, discard all 36 backup allocations, and preserve all 15
borrowed GLOBAL float constants without additional data credit.

Generated progress is 1,829,524 / 2,607,776 matching code bytes
(70.156485833%), and 7,732 / 8,803
functions. The complete proof and generated progress snapshots are pinned by
`scratch/continuation_20261010/surface-mode-pose-root-route-seal-v1.json`
(SHA-256 `bdd41572cb61e0e619ab8e97fddc96d801310edbc55fb1763e047e41f1c7b998`,
1,351 pins). Frozen producer notes remain untouched; this note records their
completed full-game acceptance. Original functions and data outside each declared
split remain with their existing owners. `PROGRESS.md` is the current generated
report.
