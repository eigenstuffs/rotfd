# ContainerInVolume class metadata

`src/Game/container_in_volume_class.cpp` owns four contiguous methods at `0x800CADB8..0x800CAE9C`: the descriptor getter/setter, enumeration, and lookup. It visits the ContainerInVolume descriptor at `0x80377878` followed by the two observed base descriptors. Enumeration retains that order; lookup returns the first result other than `-1`. All descriptor storage remains external.

All 228 instruction bytes, 40 exception/index bytes, and 18 relocations match. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and standard Gekko hardware-FP flags. No other code or data is emitted.

Reproduce with `python3 scratch/game_container_in_volume_class/verify.py`; transcript: `scratch/game_container_in_volume_class/verification.txt`. It checks the untouched original DOL hash, exact source hash, every allocated byte and relocation, and full symbol/section sizes.

The source is integrated. `config/GSQE78/candidates/game_container_in_volume_class.json` records successful full-DOL and native objdiff verification, and its recorded source hash matches the current file. `build/GSQE78/report.json` reports 100% matching for `main/Game/container_in_volume_class`: all four functions and 228 code bytes, plus 16 `extab` and 24 `extabindex` bytes. The rebuilt and untouched original DOL both have SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
