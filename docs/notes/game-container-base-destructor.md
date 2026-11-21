# Container base destructor

`src/Game/container_base_destructor.cpp` is a bounded reconstruction. The native strong destructor at `0x8002DF20..0x8002E014` restores its external descriptor, destroys the handle and array members, calls the native root destructor, and conditionally frees storage. The array element destructor is empty; its ordinary C++ destruction loop reproduces the retained original loop. The canonical native base constructor remains external.

All 244 retained instruction bytes, 52 exception/index bytes, and 13 retained relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and standard Gekko hardware-FP flags. Every allocated compiler byte is covered by verification, including complete symbols, exception records, and relocations. The complete central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_container_base_destructor/verify.py`; transcript: `scratch/game_container_base_destructor/verification.txt`. The verifier checks the original DOL SHA1 and exact source hash before recording the candidate. Shared external storage remains unclaimed.
