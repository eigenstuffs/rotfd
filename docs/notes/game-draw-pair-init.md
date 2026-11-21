# Native DrawPair initialization

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/draw_pair_init_801C4074.cpp` reconstructs the504-byte constructor at `801C4074..801C426C` as `__ct__17DrawPair_801C2F70Fv`. Strict production/fresh recompilation matches every primary byte and all29 actual relocations. Central native identity migration and full-game acceptance are pending.

The accepted neighboring DrawPair destructor establishes the layout. Genuine base/member construction initializes three layered handles, two arrays and a flag, then resets two handles and looks up the third by two borrowed names. Initializing the derived table before the first member preserves native construction order.

Four unique unused helper destructors total356 bytes/8 relocations; an actual isolated native link proves complete discard. No data, literal pool, EH, index, BSS or startup ownership transfers. Private caller snapshots prove changing the old C declaration/call in `factories_80209554.cpp` preserves all704 allocated bytes and64 relocation targets. No live consumer or shared file was changed. Complete frozen proof and root-only migration requirements are under `scratch/game_draw_pair_init_801c4074` and `scratch/game_engine_batch268`.
