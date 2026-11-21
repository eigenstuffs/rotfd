# Native animation-frame initialization

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/anim_frame_init_801EF438.cpp` reconstructs the400-byte constructor at `801EF438..801EF5C8` as `__ct__18AnimFrame_801EF438Fv`. Production and fresh strict recompilation match every primary byte and all16 actual relocations; central integration is pending.

Genuine native base/member construction initializes a layered handle, eight ordinary curve members and the existing virtual world-action curve. The constructor clears a short and loads three floats from an existing global constant. Every original table, constant and dependency identity remains borrowed.

Four unique unused weak destructors total344 bytes/8 relocations; actual isolated MWLD proves complete discard. The existing original small-data object supplies the constant for native relocation validation. Full original tables and active ownership scans are clean. Private identifier-only caller recompilation preserves all792 factory bytes and72 actual targets. No live consumer/shared file changed. Frozen handoff and complete migration/native acceptance requirements are under `scratch/game_anim_frame_init_801ef438` and `scratch/game_engine_batch269`.
