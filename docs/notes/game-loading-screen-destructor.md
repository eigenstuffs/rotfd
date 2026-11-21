# LoadingScreen destructor

`src/Game/loading_screen_destructor.cpp` is a bounded source recovery. The native C++ destructor at `0x800B9214..0x800B92F0` restores its external descriptor, destroys its resource handle at `0x50`, then inlines the base cleanup at `0x800B9368` before custom deletion. Typed member and base destruction generate the original null checks, delete-flag handling, and exception specification records. Explicitly described descriptor fields keep both original vtables external. No other code or data is emitted.

Isolated verification matches every allocated compiler byte: 220 retained instruction bytes, 52 exception/index bytes, and 13 retained relocations. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`, with the standard Gekko hardware-FP flags. Original DOL SHA1 is checked before each comparison. There is no raw instruction encoding, assembly, or binary patching. The central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_loading_screen_destructor/verify.py`. The script checks section coverage, complete symbol sizes, all relocations, exception actions, and the exact source hash; transcript: `scratch/game_loading_screen_destructor/verification.txt`. The manifest is `config/GSQE78/candidates/game_loading_screen_destructor.json`.

The retained destructor has strong global linkage. Earlier setup verification also proves the equivalent compiler-generated weak duplicate; this standalone unit now owns the original destructor and its exception/index ranges for progress credit. Address-suffixed class names and opaque fields express observed layout rather than claiming original identifiers.
