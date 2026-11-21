# Early component forwarding calls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ routines own136 text bytes and80 original exception/index bytes: `fn_80096030`(32),`fn_80096050`(40),`fn_800964F4`(32),`fn_80097504`(32). Frozen handoff: `scratch/game_early_component_calls/final_integration.json`.

Three routines forward the same receiver to their original external state operation. `fn_80096050` passes the embedded +0x318 component and event6 to the existing event dispatcher. The dedicated header represents only observed receiver storage; original class and larger component ownership remain unresolved.

GC1.3.2 with size optimization and C++ exceptions enabled reproduces every allocated byte and all twelve actual relocations. Each function owns its actual compiler-local eight-byte exception record and twelve-byte index record. Full original callable-index/startup scans, including descriptors and trailing slots, prove that every original reference into these ranges is owned. No data literals, BSS, weak helpers or padding are emitted. Neighboring compiler-generated this-adjustment thunks remain original assembly and receive no credit.

Status: frozen isolated match, pending full integration checkpoint.
