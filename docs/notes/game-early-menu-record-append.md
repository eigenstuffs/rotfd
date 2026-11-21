# Early menu record append

Frozen batch144 reconstructs fn_800B2F48 (624 bytes), which grows a196-byte record array by32, placement copies a record and appends its address to a pointer index array. Composite member layout and ordinary Name element copy constructors reproduce both the aggregate text copy and the eight-key pointer loop. The retained Handle is the final member; its original Handle8001FF78 cleanup stays external.

GC1.3.2 Gekko -O4,s -Cpp_exceptions on strictly matches624text+40EH/index bytes with25actual relocations across all allocated sections. Full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 audits plus initialized pointer-word inventory pass. No weak code, aliases, migrations, non-EH data, BSS or padding ownership.

Frozen proof: scratch/game_engine_batch144/HANDOFF.md. Central full-DOL acceptance and progress generation remain with root. Adjacent diagnostic switch B6C84 is a separate bounded private probe with no source or shared-pool credit.
