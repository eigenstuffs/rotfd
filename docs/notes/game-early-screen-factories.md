# Early screen factories

Frozen isolated batch139 recovers ordinary native C++ factories `fn_800B9148` (204 bytes) and `fn_800B940C` (188 bytes). The former allocates and constructs LoadingScreen_800C0600, and the latter LoadingScreen_800B9214. Both preserve allocator parameters, genuine Object/ScreenBase inheritance, the three zeroing Handle layers for members48/50, and final active54 values.

Production sources are `src/Game/early_screen_factory_800b9148.cpp` and `early_screen_factory_800b940c.cpp`, with dedicated `include/Game/early_screen_factory_views.h`. GC1.3.2 uses normal Gekko `-O4,s -Cpp_exceptions on`. Existing native constructor/destructor/vtable identities remain unchanged. Declared external member/base destructors prevent unused backup definitions; there are no weak functions or extra code/data allocations.

Strict production recompilation verifies all **392 text +120 EH/index bytes**, using **38 actual retained relocations**. Each48-byte extab record preserves the two original native Object/ScreenBase cleanup actions. Full original extabindex80015F60..8001F2C0, ctors80299920..99980, dtors99980..999A0 audits pass. No non-EH initialized data, BSS, padding, alias or identity migration is owned. Existing original allocator strings, vtables, and called functions remain external and retained.

Frozen proof and integration manifest list: `scratch/game_engine_batch139/HANDOFF.md`. Isolated proofs establish complete emitted-object equality; root performs central full-DOL acceptance and progress generation. All prior sources and metadata remain untouched.
