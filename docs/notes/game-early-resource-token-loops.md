# Early resource token loops

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Batch141 recovers ordinary resource parsers `fn_800A4F2C` (340 bytes) and `fn_800B026C` (508 bytes), each with complete native Handle8001FF04/8001FF78 lifetimes. A4F2C reads named blocks and selects state6 on success; B026C resets and fills the existing400-element132-byte external record table, preserving comment/delimiter handling and bounded text copying.

GC1.3.2 Gekko `-O4,s -Cpp_exceptions on` reproduces all **848 text +160 EH/index bytes**, **53 real retained relocations**. Each compiler object includes228weak text104metadata14backup relocations, inventoried uncredited. Existing bounded `production-defined-weak-eh-override-v1` proof independently recompiles native1FF04/1FF78 strong owners; central native map must prove original strong cleanup and all backup discard.

Full original extabindex80015F60..8001F2C0, ctors80299920..99980, dtors99980..999A0 and initialized pointer-word audits pass. Original lbl802BC988 table remains externally owned with entry802BC9CC→A4F2C unchanged. Existing strings and record BSS remain external; no non-EH data/BSS/padding/alias/migration ownership. Dedicated header has two source consumers.

Frozen complete proof and manifests: `scratch/game_engine_batch141/HANDOFF.md`. Root owns central integration/full-DOL acceptance and generated progress. Initial table annotation history remains preserved alongside the corrected resume proof; reconstructed source did not change.
