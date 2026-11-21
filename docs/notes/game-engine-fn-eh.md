# Ordinary destructors previously provisionally named fn_*

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three bounded ordinary native C++ destructors now match in isolated production
objects, including every original exception byte and actual relocation. The
`fn_*` inventory reveals native destructor bodies omitted by older `auto_dtor_*`
searches. Source names remain provisional private layout descriptions.

| Original address/name | Compiler native name | Text | EH/index | Relocations |
| --- | --- | ---: | ---: | ---: |
| fn_8007D284 | __dt__15Object_8007D284Fv | 472 | 52 | 23 |
| fn_800A6090 | __dt__15Object_800A6090Fv | 420 | 52 | 24 |
| fn_800E82C4 | __dt__15Object_800E82C4Fv | 340 | 52 | 22 |

The frozen handoff is `scratch/game_engine_fn_eh_continuation/final_integration.json`
with split/config suggestions, full ownership audit, source hashes, and strict
verifier alongside. Sources use GC 1.3.2 with established container-base flags,
`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. All three matched on the
first structural probe. No additional weak helper or allocated section is
emitted. Root alone integrates central metadata and performs full-DOL acceptance.

`8007D284` extends the already verified owner prefix from `80075AF8`: vtable at
8, layered handles at 24/28/7C, and an inline virtual notification through slot
4C. It adds paired-depth handles at 134, 1EC, 1F0, 230, and 234, destroyed in
reverse member order. Opaque gaps preserve only established offsets.

`800A6090` first calls the original setup cleanup and conditionally another
cleanup when context manager114 and signed active18 are nonzero. Its ordinary
draw/root hierarchy preserves table updates at 8. A size/capacity/data array at
20 destroys D4-byte records with layered handles at their start; handles at
30,34,1980 are destroyed first. The D4 stride is established by both the loop
index multiplication and allocation-release capacity multiplication.

`800E82C4` clears context service124's observed owner1505C field when the service
exists. Its inline fixed-record group at C8 updates its own table, then destroys
three `Record_800E6A58` elements at D4 with the established 3B5C stride. The
native record declaration intentionally includes the four opaque tail bytes
beyond the original destructor's minimum observed 3B58 view. The previously
verified container prefix then releases its array48 and layered handle58.

All three original global names have no compiled source/header/assembly caller;
the proposed `original_symbol` mappings preserve original addresses and binding
while publishing genuine compiler-native destructor names. No alias or thunk is
introduced. External dependencies retain their established names. Undefined
dependency lists use only actually referenced ELF symbols with section index
zero; compiler-local EH literals cannot become external dependencies.

The complete original extabindex table and constructor/destructor tables were
audited. Each function owns one original 40-byte EH record and 12-byte index;
none has a constructor/destructor-table pointer. Every original assembly
instruction belongs to the reported extent. These are partial reconstructed
translation units; original data and neighboring code remain with their owners.
