# Early related Handle append

Frozen batch146 reconstructs fn800BCCBC (572 bytes). It avoids duplicate resolved children, assigns the child's parent and grows/copies into the retained Handle array by8. Ordinary entry-pointer resolution, equality order and an object-level parent setter reproduce native allocation. The copied Handle's original80020834 base cleanup remains external.

GC1.3.2 Gekko -O4,s -Cpp_exceptions on strictly matches572text+40EH/index bytes and18actual retained relocations across all allocated sections. Full original extabindex80015F60..8001F2C0, ctors80299920..80299980, dtors80299980..802999A0 ownership and initialized data-word inventory pass. No weak code, aliases, migrations, non-EH data, BSS or padding.

Complete frozen proof: scratch/game_engine_batch146/HANDOFF.md. Central full-DOL acceptance remains with root. Adjacent BCF58 is a separate bounded private probe and receives no credit.
