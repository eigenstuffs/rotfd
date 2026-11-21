# Audio record array cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80287BEC` (`0x80287BEC`, 188 bytes) releases four record arrays and
clears their owner fields. Ordinary typed `delete[]` expressions reproduce
the original nested null guards and compiler array-cookie adjustment. The
record types have declared constructors and trivial destructors; their
inline array deallocation operators call the existing heap service.

`src/Game/audio_array_cleanup.cpp` records only the observed partial owner
layout and array element sizes. It is a text-only split, not a complete
original translation unit. Original shared heap state and the adjacent
allocation routine remain outside this source unit.

All 188 original text bytes, all 12 actual external relocations, and all
emitted allocated sections and symbols match under GC 1.3.2. No weak code,
local data, exception entries, or startup-table references are emitted or
owned. Full original metadata scans and the frozen integration manifest
are in `scratch/game_audio_runtime_controls/array_final_integration.json`.
The central production build and original DOL hash check remain pending.
