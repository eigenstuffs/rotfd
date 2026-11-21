# LoadingScreen base setup

`src/Game/loading_screen_base_setup.cpp` reconstructs `fn_800C58F8` at `0x800C58F8..0x800C59E8`. It clears the LoadingScreen class descriptor, delegates base setup, and constructs and destroys a temporary LoadingScreen object. This complete routine is also inlined in the adjacent derived setup at `0x800C59E8`; its separate existence explains that method's distinct temporary stack allocation.

All 240 instruction bytes, 60 exception/index bytes, and 20 retained relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and the standard Gekko hardware-FP flags. Four emitted weak destructor duplicates also match their canonical originals, including all exception records, and receive no additional credit. Original vtables and descriptor storage remain external.

`python3 scratch/game_loading_screen_base_setup/verify.py` checks the original DOL SHA1, every allocated section byte and relocation, full symbol sizes, exception actions, and source hash. The transcript is `scratch/game_loading_screen_base_setup/verification.txt`. The central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.
