# Container intermediate destructor

`src/Game/container_layer_destructor.cpp` is a bounded reconstruction. The native strong destructor at `0x80044168..0x8004426C` restores its external descriptor and inlines the observed container-base cleanup before conditional custom deletion. Native C++ base and member destruction reproduce the original null tests and exception specification; no manually encoded instructions or metadata are used.

All 260 retained instruction bytes, 52 exception/index bytes, and 15 retained relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and standard Gekko hardware-FP flags. Every allocated compiler byte is covered by verification, including complete symbols, exception records, and relocations. The complete central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_container_layer_destructor/verify.py`; transcript: `scratch/game_container_layer_destructor/verification.txt`. The verifier checks the original DOL SHA1 and exact source hash before recording the candidate. Shared external storage remains unclaimed.
