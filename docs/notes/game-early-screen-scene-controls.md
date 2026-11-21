# Early screen scene controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen batch140 reconstructs `fn_800B7C60` (504 bytes) and `fn_800B7E58` (416 bytes) as ordinary C++. The update clears optional screen objects and copied related objects; setup resolves two named screen types, retains a display-image Handle in member1506C, and installs two callbacks. Dedicated source/header preserve native four-byte Handle inheritance and complete temporary lifetimes.

All **920 text +140 EH/index bytes**, **48 actual retained relocations**, strictly match original allocated sections using GC1.3.2 Gekko `-O4,s -Cpp_exceptions on`. Every emitted weak backup is separately accounted: update120code52metadata7relocs; setup228code104metadata14relocs, uncredited. Native Handle8003E120/21C40/21BCC EH cleanup references must bind to independently audited original strong definitions. The existing bounded `production-defined-weak-eh-override-v1` gate verifies these identities; final full-map discard/strong resolution remains a root checkpoint check.

Original extabindex80015F60..8001F2C0, ctors80299920..99980, dtors99980..999A0 and all initialized pointer words are audited. Existing original callable table lbl802BEF98 (802BEF98..BEFF0) entries802BEFA8→B7C60 and802BEFA4→B7E58 remain externally owned unchanged. No non-EH data/BSS/padding, identity migration or aliases.

Strict production manifests/verifiers and complete frozen proof: `scratch/game_engine_batch140/HANDOFF.md`. Root owns central registration, full-DOL acceptance and progress. The 920 instruction bytes require ordinary type/lifetime corrections: nested validity conditions avoid cross-expression EH flags, and the validity query returns an unsigned word.
