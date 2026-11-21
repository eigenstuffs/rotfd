# Owner related-resource readiness

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source in `src/Game/engine_owner_related_ready.cpp` matches fn80240FC4 at `80240FC4..80241344`, all 896 retained text bytes. Production compilation uses GC 1.3.2 and the default Game flags; no additional compiler option is required. All 25 actual relocations resolve to their original targets. The compiler emits only this strong text function: no weak backups, initialized data, BSS, padding, vtable, exception table or startup allocation.

The function first calls `Root_80207414::slot1C()` through a genuine qualified C++ base call and returns zero if that readiness check fails. It then checks the related handles at offsets 1C, 20, 10, 18, 24, 28, 130 and 2C, in that order. Each valid handle is resolved through its signed 24-bit index and signed 8-bit generation, then receives virtual slot1C. The related method return values are ignored; once the base check succeeds the function returns one. The observed inline resolver compares the entry generation without a separate bounds check.

The dedicated header provides partial layout views, with unknown fields retained as padding. The genuine Root view places its vptr at offset08 and readiness slot at vtable offset1C; no construction or destruction is instantiated in this unit. Primary, secondary, first-child and next-sibling names follow neighboring recovered owner views; the four remaining handle names retain their offsets because their broader roles remain uncertain. The global context and all related targets remain external.

The first ordinary probe matched all bytes. Production types and resolver use a dedicated RelatedReady prefix, and the renamed, formatted source with size assertions was recompiled and strictly verified. The frozen manifest is `scratch/engine_owner_related_ready_20261011dw/final_integration.json`. Its verifier recompiles production source, checks every allocated byte and symbol extent, compares every resolved real relocation, audits the complete original extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, and checks frozen file hashes. Those complete original tables contain no references requiring ownership in this split.

This is a partial text split with its existing entry identity unchanged. All adjacent code and original external data/functions retain their owners. No consumer, shared declaration, symbol, dependency identity or central configuration migration is required. Full executable acceptance remains with the root integrator.
