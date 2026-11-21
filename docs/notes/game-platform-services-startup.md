# Platform service startup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary source for fn_801EA734 occupies 801EA734..801EAA7C (840 bytes), with no owned data, BSS, startup tables, EH metadata, padding or helper allocations. GC1.3.2, Gekko, O4,p, exceptions off and use_lmw_stmw on reproduce every allocated byte and all72 actual relocations. Production and independent fresh strict verification pass; full-game integration remains pending.

The routine allocates and initializes ten platform services, stores each in the existing global context, calls the corresponding startup virtuals and logs completion. Existing constructor/vtable identities are unchanged. A single shared diagnostic-pool pointer passed through the inline allocator helper preserves the native one-register pool lifetime; separate constant substring expressions retained two addresses and added32 bytes. An ordinary virtual CacheDispatch view reproduces the native r12 table load.

All original strings, service tables and allocator context remain borrowed. In particular lbl_801EF5C8 is the original44-byte zero storage in .text, represented by the accepted raw-link/report-copy metadata route. Its payload/global identity and ownership remain unchanged; this source only references it.

Complete active original ownership census:5640 objects,119086 actual relocations and777360 initialized words. Exactly one original GLOBAL840 definition and one direct original caller, with no table pointers, aliases, overlaps or compiled source consumers. Full extabindex/ctors/dtors scans find no metadata owned by this primary. Real isolated MWLD retains only the primary allocation and verifies all72 linked relocation operands; wrong primary extent is rejected.

Frozen evidence and integration files are in scratch/game_engine_batch278/ and scratch/game_platform_services_startup_801ea734/.
