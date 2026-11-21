# Sparse Handle and record array owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801B58D0`, original `.text` range `801B58D0..801B5C20`, is an 848-byte C-entry owner destructor. The isolated production source matches every allocated byte and all 24 real relocation targets with GC 1.3.2, Gekko, `-O4,p`, exceptions off. Two fresh strict production recompiles pass. Native whole-game acceptance is pending with the root integrator.

The owner contains empty 16-byte record arrays at 0 and 0x28, an empty 4-byte record array at 0xC, a native Handle array at 0xB8, and sparse 129-byte records at 0xCC. Sparse occupancy is the native BitSet at 0xD8; its limit and occupied count are at 0xE8 and 0xEC. Destruction clears occupied bits and decrements the count, destroys the BitSet, releases the raw sparse storage, then destroys the other arrays. A const word-reference bitset accessor preserves the original reload before clearing each bit. The raw sparse-storage base has no element-destruction loop; the other record arrays retain their observed empty element lifetime loops.

Only primary text is allocated. There is no compiler helper, owned data, BSS, padding, or startup entry. Full original extabindex (`80015F60..8001F2C0`, including descriptor), constructors (`80299920..80299980`), and destructors (`80299980..802999A0`) have no references to this range. The active inventory scans 5,577 object inputs, 119,086 actual relocations, and all 777,360 initialized words. The sole data pointer is `802E9E84 -> 801B58D0`, within unchanged external `lbl_802E9E70[48]`. Both original vtable identities and the existing native Handle/BitSet destructor identities stay external and unchanged. There are no compiled C/C++ consumers or identifier migrations.

Frozen evidence: `scratch/game_engine_batch234/manifest-list.json` and `frozen_hashes.json`; production and complete strict/ownership inventories are under `scratch/game_sparse_handle_arrays_destroy_801b58d0/`. Older probes and handoffs are preserved unchanged.
