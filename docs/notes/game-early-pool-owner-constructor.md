# Pool-owner construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_pool_owner_constructor_800b5b6c.cpp` reconstructs the native492-byte constructor at800B5B6C as `Object_800B5EC8::Object_800B5EC8()`. The class identity agrees with the accepted derived destructor. It initializes the established base pool, two member arrays, scalar/vector defaults, appends the original singleton word, and resolves a named resource into the owner pointer.

The existing destructor sources establish explicit external table fields at offset0. This constructor retains that view: its inline base constructor installs `lbl_802B8460`, and the first derived field initializer installs `lbl_802BD920` before the two arrays construct. Both original table symbols and all16-byte table allocations remain external and unchanged. No compiler vtable is emitted, and no table or accepted destructor identity migration is required.

The isolated GC1.3.2 O4,s/exceptions production object exactly matches492 code bytes,52EH bytes at80011938 and12 index bytes at8001C0BC. All28 actual allocated relocations match. The exception actions destroy the two original array members and original `Object_8007F3DC` base. No helper code, literals, BSS or padding is emitted. Declaring the returned Base Handle's actual constructor restores the original hidden return-address ABI; omitting it produced a476-byte near probe. The remaining source uses ordinary placement construction and retain-aware Handle lifetime behavior.

Full original exception-index/startup tables and initialized-data word ownership scans pass. The sole initialized pointer to this function is its owned exception index. An active-original ELF census covers5525 objects and119086 actual relocations: one old492-byte strong definition, no native constructor definition, and two old-name references (assembly startup8007EE70 plus the owned index). No compiled source body calls the old name. One unused old declaration remains in `early_context_startup_views.h`; private copies changing only that declaration pass complete allocated-byte/symbol-extent/relocation equivalence for all three accepted header consumers. Existing sources, header and canonical manifest remain unchanged for root integration.

Root must concretely replace the original C identity `fn_800B5B6C` with `__ct__15Object_800B5EC8Fv`, regenerate the assembly caller, and optionally migrate the unused startup declaration with its three canonical header inventories. There is no alias or private linker workaround. Matching credit waits for native original placement, original DOL hash and regression acceptance. Frozen handoff: `scratch/game_engine_batch156/HANDOFF.md`; repeat proof: `python3 scratch/game_early_pool_owner_constructor/verify.py`.
