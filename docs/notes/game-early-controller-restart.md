# Early controller restart routines

Frozen isolated matching handoff, batch 88. Central integration remains pending.

| Function | Text | Exception table | Exception index |
| --- | --- | --- | --- |
| fn_80060538 | 80060538..80060820 (744) | 8000B0F4..8000B0FC (8) | 800183E4..800183F0 (12) |
| fn_80060CB0 | 80060CB0..80060DEC (316) | 8000B16C..8000B174 (8) | 80018450..8001845C (12) |

The ordinary C++ sources reset their owner, query state 0x82, and start controller operation 3 when operations 3 and 4 are inactive. The larger routine additionally handles state 0x85: it clears the resolved controller byte at 0x3EC and starts operation 8 when operations 8, 3, and 4 are inactive. Every operation resolves the owner handle at 0x70 through the signed 24-bit index and signed generation byte in the original context manager. The shared header describes only observed storage and external function interfaces; it introduces no native class identity.

Both first probes matched exactly under GC/1.3.2 with `-O4,s -Cpp_exceptions on`. Production sources and header are frozen. Each separate source emits one contiguous .text extent, 8 bytes of extab, and 12 bytes of extabindex. The strict verifiers map actual ELF relocations, compare every retained allocated byte with the original DOL, and check actual local exception symbol names/extents. The larger routine has 16 retained relocations, the smaller 9; each has one nonallocated compiler category relocation. There are no weak functions, compiler-owned literals, BSS, padding, aliases, or constructor/destructor table entries.

The full original extabindex range 80015F60..8001F2C0 and the complete .ctors 80299920..80299980 and .dtors 80299980..802999A0 ranges were audited. All function exception ownership is retained. The original DOL SHA-1 remains 5da8295a79bf297ab62c620e6ac66210be1c6ef5.

Manifest list: `scratch/game_early_controller_restart/manifest-list.json`. Each manifest has its own strict `verify.py`. The 1,060 text bytes and 40 exception bytes are isolated evidence; final credit requires the root integrator's original-hash build and regression checks.
