# Mesh vertex incidence collection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801D8980`, original `.text` range `801D8980..801D8DC0`, is an 1,088-byte integer incidence-counting and vector-copy routine. Its isolated production source matches every retained byte and all 21 real retained relocation targets with GC 1.3.2, Gekko, `-O4,p`, exceptions off. Two fresh unchanged-core strict production recompiles pass; native whole-game acceptance is pending with the root integrator.

The owner has vertices at 0x74, 144-byte face records at 0xA4, and 8-byte edge records at 0xB0. Each face stores four unsigned-short edge indices at 0x58 and a flag word at 0x60; flag bit 0 selects three sides instead of four. The routine creates a temporary integer array sized to the vertices, zeros it, increments incidence counts for both endpoints of every referenced edge, and copies vertices with count two to the caller's output. A single function-scope loop index preserves the original induction-variable reuse. Ordinary array subscripts and the face's integer edge accessor reproduce the native combined offset calculation and two-iteration loop unrolling.

The compiler also emits one unused 208-byte weak array-destructor backup, `__dt__27MeshVertexIncidenceArray<i>Fv`, with four actual relocations. The complete allocation and relocation inventory records it as unlinked; no retained text or EH references it. Both final native ELF/map outputs must show the entire backup discarded, with no code or metadata credit. The primary owns no data, BSS, padding, EH, constructor, or destructor-table allocations.

Full original extabindex (`80015F60..8001F2C0`, including descriptor), constructors (`80299920..80299980`), and destructors (`80299980..802999A0`) have no references to the range. The active audit scans 5,578 object inputs, 119,086 actual relocations, and all 777,360 initialized words. The only three original entry consumers are unchanged original text callers at `800B3344`, `80216228`, and `8021894C`; there are no initialized data pointers, aliases, compiled source consumers, or identifier migrations. The unique unused backup is absent from all active inputs.

Frozen evidence is in `scratch/game_engine_batch235/manifest-list.json` and `frozen_hashes.json`; complete probes, manifests, strict verification, and ownership inventories are under `scratch/game_mesh_vertex_incidence_801d8980/`. All prior handoffs remain immutable.
