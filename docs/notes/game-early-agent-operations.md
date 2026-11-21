# Early agent binding and threshold initialization

Batch98 frozen ordinary C++ reconstruction, pending central integration: 540 text bytes plus 56 original exception metadata bytes.

| Function | Text | extab | extabindex | Retained relocations |
|---|---:|---|---|---:|
| fn8006F35C |208|8000C4EC..8000C504|80019044..80019050|11|
| fn8006F44C |332|8000C50C..8000C514|8001905C..80019068|12|

Both matched their first ordinary probe. F35C binds the original named registry result through a genuine returned Handle temporary, clears resource flag3, invokes the original base helper and two virtual operations with85, then sets flags44 and48. Its original24-byte EH record retains the external raw Handle destructor reference. No weak helper is emitted.

F44C logs the original external message, forwards the input to the existing base initializer, sets high/low thresholds at94/98 from three native resolutions of controller70/radius370 and the original external floats, then sets the controller actor flag9. The dedicated observed agent view includes only virtual declarations and fields needed to reproduce these operations; no table identity or native spelling migration is needed.

The strict verifier independently recompiles both frozen sources with GC1.3.2 `-O4,s -Cpp_exceptions on`, verifies all allocated bytes after actual ELF relocation application, checks actual local EH symbol names/extents, and scans original extabindex80015F60..8001F2C0, ctors80299920..80299980, dtors80299980..802999A0. Only each exact function's retained EH/index records refer to its extent. No constructor/destructor slot points inside either function. Every object emits exactly its text and original EH/index; no owned literals, BSS, padding, weak functions, or discarded allocations. One nonallocated compiler category relocation per function is accounted.

Manifests: `scratch/game_early_agent_operations/manifest-list.json`. Frozen handoff: `scratch/game_engine_batch98/HANDOFF.md`. Dedicated header: `include/Game/early_agent_operation_views.h`, consumed by these two new sources only. All shared metadata/global build remain root-owned.
