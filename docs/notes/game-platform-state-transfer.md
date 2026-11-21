# Platform state transfer at 0x8028BFC8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This 144-byte function forwards the object and stream cursor to the context service at offset 0x118, transfers two words at object offset 4 through 0x801E9F40, then delegates the blocks at offsets 0x0C, 0x1C, 0x2C and the handle at 0x3C. Each helper receives the original cursor by reference. The partial layout and descriptive names are inferred from the observed call arguments; helper direction and the complete original object type remain unspecified.

Ordinary C++ with GC/1.3.2 standard O4,p/EH-off flags matches all 144 text bytes and eight actual relocations. No extra allocated sections, weak helpers, or references from the original exception/startup tables are emitted or owned. External context and helper identities remain unchanged. The strict isolated manifest is `scratch/game_platform_state_transfer/final_integration.json`; full acceptance is recorded by the integration checkpoint.
