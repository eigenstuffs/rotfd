# Early record-array copy constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The genuine `Array_80025634(const Array_80025634&)` constructor matches372text bytes at80025724..80025898, plus original extab8000604C..80006068(28) andextabindex800163EC..800163F8(12). Strict production verification passes all retained bytes and17actual relocations usingGC1.3.2 with `-O4,s -Cpp_exceptions on`. Central full-DOL acceptance remains pending.

The constructor clears count,capacity and data, reserves the source count, then copies each24-byte record through the ordinary inline append operation. Records contain a key, inherited packed Handle and four floats. Their native copy construction retains the Handle and preserves individual float reads/stores. The retained exception action destroys the established Handle_8001FF78 base if its derived Handle construction fails.

Source is `src/Game/early_actor_array_copy_80025724.cpp`; dedicated declarations are in `include/Game/early_actor_array_copy_views.h`. The genuine ABI spelling is `__ct__14Array_80025634FRC14Array_80025634`, replacing the existing fn_80025724 identity at the same address. A full current5,494-unit original-object relocation scan records13callrelocations across12activeassemblycaller units, plus the constructor's own EH index. There are no existing source/header consumers of the old name. `scratch/game_early_actor_array_copy/original_consumer_inventory.json` and `identifier_migration.json` preserve the exact migration; central metadata and consumer regeneration remain with the integrator. No alias or address change is introduced.

Every allocated byte is accounted for. The object additionally emits three uncredited weak destructors totaling324text bytes, with124bytes of their own EH/index metadata: ArrayRecordBase96,ArrayRecordHandle116 andHandle_8001FF78112. The one retained EH reference to the defined weak Handle_8001FF78 is authorized by a freshly recompiled byte-exact proof of its existing original global strong owner. All backup code and metadata must be absent from the final native ELF. There is no owned non-EH data,BSS or padding.

Frozen manifest list: `scratch/game_engine_batch111/manifest-list.json`. Actual compiler-local EH names/extents and complete original extabindex80015F60..8001F2C0,ctors80299920..80299980 anddtors80299980..802999A0 ownership checks pass. Adjacent actor array-clear callers remain private432/5 and424/9scratch-register near matches, documented in `scratch/game_early_actor_array_copy/FINDINGS.md`; they receive no matching credit.
