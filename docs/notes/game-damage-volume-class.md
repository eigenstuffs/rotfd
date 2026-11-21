# DamageVolume class metadata

`src/Game/damage_volume_class.cpp` is a bounded reconstruction. Four methods at `0x800C9DB8..0x800C9EC8` expose the descriptor at `0x80377870`, enumerate four descriptor levels, and search them in order until the result differs from `-1`. The preceding accepted DamageVolume factory and registration establish the class identity. Shared descriptors remain external.

All 272 retained instruction bytes, 40 exception/index bytes, and 22 retained relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and standard Gekko hardware-FP flags. Every allocated compiler byte is covered by verification, including complete symbols, exception records, and relocations. The complete central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_damage_volume_class/verify.py`; transcript: `scratch/game_damage_volume_class/verification.txt`. The verifier checks the original DOL SHA1 and exact source hash before recording the candidate. Shared external storage remains unclaimed.
