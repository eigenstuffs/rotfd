# DamageVolume initialization callbacks

`src/Game/damage_volume_callbacks.cpp` is a bounded reconstruction. The two contiguous methods at `0x800C939C..0x800C9404` delegate to native base operations. Initialization additionally invokes the observed virtual method at vtable offset `0x8C`, with both arguments zero. The real virtual class declaration places its descriptor at object offset eight and emits no invented vtable.

All 104 retained instruction bytes, 40 exception/index bytes, and 6 retained relocations match the original. GC/1.3.2 uses `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` and standard Gekko hardware-FP flags. Every allocated compiler byte is covered by verification, including complete symbols, exception records, and relocations. The complete central build passes the original DOL SHA-1, direct byte comparison, and complete native objdiff code/data matching.

Reproduce with `python3 scratch/game_damage_volume_callbacks/verify.py`; transcript: `scratch/game_damage_volume_callbacks/verification.txt`. The verifier checks the original DOL SHA1 and exact source hash before recording the candidate. Shared external storage remains unclaimed.

The next configuration method at `0x800C9404` is preserved in `scratch/game_damage_volume_callbacks/near-match.cpp`. It is 164 bytes with five floating-point register-encoding differences when loading the shared minimum of `1.0f` at `0x80379640`. A native `1.0f` literal generates exact instructions but requires ownership of that shared literal; the candidate does not claim it. Bounded local, double-promotion, and inline-clamp probes did not remove the external-value allocation difference.

This previously verified partial source is now preserved as history and is not registered in the current build. [The combined lifetime unit](game-damage-volume-lifetime.md) owns these same callbacks together with construction, destruction, configuration, and their shared 1.0f literal. The full build verifies that replacement; no callback bytes receive duplicate credit.

This source slice is superseded by `src/Game/damage_volume_lifetime.cpp`, which owns these methods together with both consumers of the shared `1.0f` literal. The slice is retained as source history and receives no separate progress credit.
