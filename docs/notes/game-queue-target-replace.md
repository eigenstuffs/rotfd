# Queue target replacement

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The complete ordinary C++ entry `fn_80230F7C` matches all 240 bytes at `80230F7C..8023106C`, including actual relocation addresses. It releases the old target, copies and retains the new handle, constructs a retained copy of the previous handle, resolves the new target through its signed generation/index, and dispatches virtual slot 30 with that copy. The local copy is destroyed on return. An explicit reference to the previous member preserves the native alias and register lifetime across construction.

Source: `src/Game/queue_target_replace.cpp`. The unit uses the standard GC/1.3.2 Game flags and has no owned data, BSS, padding, or startup/exception records. Private cleanup backups are inventoried separately with exact extents, weak bindings, raw hashes and actual relocations; no retained code refers to them, and final acceptance requires their absence. The private observed layouts do not claim complete original class identities. All original tables and neighboring functions remain externally owned.

Frozen isolated evidence: `scratch/game_queue_target_replace/final_integration.json` and `verify.py`. The strict verifier compares every retained byte after actual relocation application and accounts for all emitted allocated sections and symbols. Central integration audits the complete original exception/startup tables; full DOL, baseline, progress and repository test acceptance remains pending.
