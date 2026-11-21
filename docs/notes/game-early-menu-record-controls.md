# Early menu record controls

Frozen batch142 reconstructs `fn_800B31B8` (208 bytes) and `fn_800A5774` (488 bytes). The first applies menu selection setup and scales four vector/color triples; the second grows an array by8 and placement copies a212-byte record with a retained Handle member.

Genuine composite record copy and `set(x*scale,y*scale,z*scale)` reproduce the native allocation/scheduling. External destructor declarations retain original Handle8001FF78 exception cleanup and avoid unused backup definitions. Dedicated source/header preserve existing C entry identities and caller ABI. No weak code, aliases, migrations, non-EH data/BSS/padding.

GC1.3.2 standard Gekko `-O4,s -Cpp_exceptions on` strictly matches **696text+60EH/index bytes**, **21 actual retained relocations** across all allocated sections. Full original extabindex80015F60..8001F2C0, ctors80299920..99980, dtors99980..999A0 audit and separate original initialized pointer-word inventory complete. Existing external literals, record allocator and source callers remain unchanged.

Frozen complete proof/manifests: `scratch/game_engine_batch142/HANDOFF.md`. Root owns full-DOL acceptance and progress generation. Optional selectorB3C8C was inspected only and owns no reconstructed source in this batch.
