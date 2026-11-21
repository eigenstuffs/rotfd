# Audio-owner destructor at 0x80287A48

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This 152-byte routine is reconstructed as an ordinary C++ destructor. It installs the original audio dispatch table at offset 0x7C, frees a non-null channel allocation at 0x410, clears the channel pointer, destroys the stream at offset 0x420 through its existing function view with flag -1, and invokes the existing owner-base cleanup with flag zero. Native signed destructor deletion flags and class-specific heap delete reproduce the final guarded release.

The partial layout and descriptive class name are inferred; the existing stream and base implementation identities remain unchanged. The source explicitly invokes their existing function views rather than claiming recovery of the original inheritance declarations. External dispatch tables and heap state remain original.

Standard GC/1.3.2 O4,p/EH-off output matches all 152 allocated text bytes and ten actual relocations. No extra allocated sections, weak helpers, or references from the complete original exception/startup tables are present. The provisional function identity changes to the native destructor name only after checking compiled consumers. Strict isolated evidence is `scratch/game_audio_owner_destructor/final_integration.json`; full build acceptance is recorded by the integration checkpoint.
