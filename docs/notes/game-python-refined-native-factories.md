# Python factories using refined native constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary native placement-new bindings at `800DB388`, `800DBD3C`,
`800DC56C`, `800DCCF4` and `800DE414` each match 296 text bytes, eight exception
bytes and twelve exception-index bytes, with twenty actual relocations.
Each includes the frozen full native class header and allocates `sizeof` its
class before the original pointer-name encoding.

The source constructors for CallbackControl, LodAgent, LodDynamicAgent and
SkinAgent already had verified free-C entries. Their native refinements preserve
the exact existing owned extents and receive zero new credit. Breakable adds
120 previously unowned constructor bytes. The five Python wrappers add 1,480
previously unowned code bytes only after central acceptance.

The frozen manifests include complete original exception/startup/shutdown table
ownership audits and all allocated source bytes. No wrapper emits additional
weak helpers, data, BSS or padding. Evidence is preserved under
`scratch/game_python_refined_native_factories/`.
