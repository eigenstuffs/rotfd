# Scene record activation and removal

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800C2540` and `fn_800C2700` reconstruct the mirrored scene-record activation/removal operations (448 code bytes each). Both retain a record Handle during list registration or removal. Their current-scene comparison uses a returned typed Handle and a null Handle with the native cleanup ABI. An explicit local in the ordinary equality helper preserves the original order of generation-checked lookups.

Each GC 1.3.2 `-proc 750 -O4,s` production unit matches 448 text bytes, 60 extab bytes, and 12 extabindex bytes with all actual relocation targets checked. No data pools, BSS, padding, or external identities move. Original function-pointer tables remain external and continue to name the same C entries.

The existing strong native destructors `Handle_80021BCC`, `Handle_8002F6B0`, and `Handle_8003E120` authorize the retained EH references under the unchanged standard weak-override verifier. Each unit separately inventories the compiler's backups, including its unique private zero/null Handle helpers. Full original exception/descriptor/startup/initialized-word and compiled-caller scans are in `scratch/game_scene_record_activation_800c2540/ownership_audit.json`. Fresh production compilation and strict original-byte verification are complete; full native placement, helper discard, original DOL hash, regression checks, and tests remain with the integrator.
