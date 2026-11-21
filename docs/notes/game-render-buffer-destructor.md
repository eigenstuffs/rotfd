# Render-buffer destructor at 0x8028245C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The 180-byte routine is reconstructed as an ordinary C++ destructor with an inline buffer member destructor and an inline resource-base destructor. The inferred class and field names describe the observed layout; they are not recovered original names.

The derived destructor installs the original dispatch table at offset 8. Its buffer member at offset 0x40 releases a non-null allocation through the original buffer manager and clears its pointer, length, and capacity. The base destructor installs the original base table and calls the already reconstructed resource destructor at 0x801CF8D4 with a zero deletion flag. Native C++ destruction supplies the observed null guards and signed deletion flag; class-specific delete uses the original heap manager. The existing base function identity remains unchanged.

GC/1.3.2 with the standard O4,p/EH-off flags emits exactly 180 allocated text bytes and eleven actual relocations. There are no extra allocated sections, weak helpers, or exception/startup references in the full original tables. The native destructor identity replaces the provisional function label only after checking for compiled consumers. External dispatch tables and heap state remain original data.

The strict isolated evidence is in `scratch/game_render_buffer_lifecycle/final_integration.json`. Full build acceptance is recorded separately by the integration checkpoint.
