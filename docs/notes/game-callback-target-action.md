# Target callback action selector

Isolated ordinary C++ recovery is exact for `fn_8025C858` at
`8025C858..8025CC04`: 940 text bytes and the complete 28-byte compiler local
jump table at `802ECE10..802ECE2C`. All 31 actual relocations and every emitted
allocated byte pass the unchanged strict verifier. Production registration and
full original-DOL acceptance remain with the integrator.

The function implements the established callback-event protocol: the first
seven events register/remove callbacks, query two flag bits, return readiness,
or return the signed callback index. Later events clear shared scratch state,
report the action category, derive an indexed action, and finalize the callback.
Action 14 queries owner flag `0x1E`. Action 15 converts the owner's float at
`0x2C` to an integer, compares it with the key resolved from virtual slot
`0x78(-1)`, tests flag `0x200000` on the owner's handle at `0x28`, and invokes
virtual slot `0x30` when both conditions allow it.

The two adjacent handle resolutions need distinct physical manager views. A
typed key entry for the first resolution and byte-addressed backing storage for
the flags resolution preserve the original second entries-pointer load. The
initial generic and concrete typed-entry variants commoned that load and
emitted only 936 bytes. The byte-backed flags and byte-backed key alternatives
both close the complete 940-byte extent and all actual relocation targets.

The dedicated header records only the established partial views: an inherited
eight-byte prefix before the owner vtable, its handle at `0x28` and float at
`0x2C`, a plain four-byte packed handle, callback flags at `0x28`, signed index
at `0x2A`, and the three-word member-pointer ABI. Full original classes remain
unknown. The original C function identity and all existing compiled consumers
stay unchanged.

The compiler naturally emits one GLOBAL 940-byte function and LOCAL `@121`, a
28-byte object in an eight-byte-aligned `.data` section. Original
`jumptable_802ECE10` can be scoped to this source under that emitted local name.
There is no alias, synthetic prefix, alignment adaptation, padding ownership,
weak helper, BSS, exception allocation, constructor or destructor emission.
Standard GC1.3.2 Gekko `-O4,p`, exceptions off and individual register saves
produce the exact source object.

Complete original exception-index, constructor and destructor table scans find
no ownership in this range. The active consumer census reads 10,216 ELF inputs
selected by `objdiff.json`, excluding stale generated assembly. The original
table has exactly its function's HA/LO pair, with zero addends. A bytewise scan
of every initialized original data section finds two external function-entry
pointers and the seven owned jump-table pointers; there is no external interior
function pointer or initialized pointer into the local table. Original direct
branch scans find no external branch into the function. No existing compiled
source/header consumer requires a change.

Original member-pointer pool `lbl_802ECCD8`, message `lbl_802AEC4C`, global
manager `lbl_801E9D24`, shared small-data scratch fields, external callees and
neighboring code/data retain their ownership and identities. This is a partial
original translation unit, with credit requested only for the exact function
and complete table. Frozen integration and ownership evidence is under
`scratch/engine_callback_target_action_20261011js/`.

The research directory also preserves an unsubmitted manifest-generation
transcription error and its correction. The final manifest and fresh verifier
explicitly require the original normalized DOL SHA1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`; no executable, expected hash,
compiler object or comparison logic was altered.
