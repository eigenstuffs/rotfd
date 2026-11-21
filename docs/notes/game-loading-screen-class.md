# LoadingScreen class metadata

`src/Game/loading_screen_class.cpp` is a bounded source recovery. The four contiguous methods at `0x800C6098..0x800C6150` get and set the class descriptor, enumerate descriptors for this class and its base, and search them in order with `-1` as the absent result. They use the shared class descriptor at `0x80377820` and base descriptor at `0x80378018`. Both storage locations remain external. No weak helpers or literal data are emitted.

Isolated verification matches every allocated compiler byte: 184 retained instruction bytes, 40 exception/index bytes, and 14 retained relocations. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`, with the standard Gekko hardware-FP flags. Original DOL SHA1 is checked before each comparison. There is no raw instruction encoding, assembly, or binary patching. The central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_loading_screen_class/verify.py`. The script checks section coverage, complete symbol sizes, all relocations, exception actions, and the exact source hash; transcript: `scratch/game_loading_screen_class/verification.txt`. The manifest is `config/GSQE78/candidates/game_loading_screen_class.json`.
