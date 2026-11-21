# Collectable class metadata

`src/Game/collectable_class.cpp` recovers four contiguous methods at `0x800C5790..0x800C58F8`: the class descriptor getter/setter, descriptor enumeration, and descriptor lookup. Six class levels are visited in their observed order. Lookup stops at the first result other than `-1`; all shared descriptor storage stays external. The preceding accepted Collectable registration routines establish the class family.

All 360 instruction bytes, 40 exception/index bytes, and 30 relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and the standard Gekko hardware-FP flags. No other code or data is emitted. The central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_collectable_class/verify.py`; its transcript is `scratch/game_collectable_class/verification.txt`. Verification covers the original DOL hash, every allocated byte and relocation, full section and symbol extents, and the exact source hash.
