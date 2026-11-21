# Late scene and Python property controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Seventeen ordinary C++ routines recover scene callback forwarding, event delivery, timed completion, child and selected-Handle virtual calls, flag updates, a Python string result and linked property getter/setter lookup. The code preserves the native signed-byte conditions, float timer delta, 64-bit flags, actual Handle reference argument and Python callback signatures.

All seventeen first probes and independent production recompiles match complete owned allocations: 1,108 text bytes, 340 exception/index bytes and 65 actual relocations. Each function owns its original 8-byte exception record and 12-byte index. Full scans of all original exception, constructor/destructor and terminal records preserve ownership. Python string/error objects and scene constants remain external; no extra data, BSS, weak helpers, padding or identity migration is claimed. The shared Python pointer-binding header remains unchanged and is hash-bound alongside the dedicated header.

Evidence is preserved in `scratch/game_scene_late_leaf_controls`. Central full-DOL acceptance is pending.
