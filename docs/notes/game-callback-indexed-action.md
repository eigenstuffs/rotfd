# Indexed callback action selector

Isolated ordinary C++ recovery is exact for `fn_8025DB30` at
`8025DB30..8025DE20`: 752 text bytes and the complete 28-byte compiler local
jump table at `802ECF68..802ECF84`. All 29 actual relocations and every emitted
allocated byte pass the unchanged strict verifier. Production registration and
full original-DOL acceptance remain with the integrator.

The function uses the established callback-event protocol: the first seven
events register/remove callbacks, query two flag bits, return readiness, or
return the signed callback index. Later events initialize shared scratch state,
report the action category, derive the indexed action and finalize the callback.
The dynamic action queries owner flag `0x1E` or converts the owner's float at
`0x2C` to an integer argument for virtual slot `0x7C`, invokes virtual slot
`0x28` with argument 3, and clears callback flag bit 2. An explicit unsigned
16-bit mask `0xFFFB` reproduces the native AND-immediate instruction; the
initial `~4` spelling emitted an inexact rotate-mask instruction.

The new dedicated header records only the physical views established here:
an inherited eight-byte prefix before the owner vtable, its float field at
`0x2C`, callback flags at `0x28`, signed callback index at `0x2A`, and the
three-word member-pointer value ABI. The full original classes remain unknown.
The original C function identity stays unchanged. Existing accepted selector
sources and declarations are untouched.

The compiler naturally emits one GLOBAL 752-byte function and LOCAL `@54`, a
28-byte object in an eight-byte-aligned `.data` section. Original
`jumptable_802ECF68` can be scoped to this source under the emitted local name;
there is no alias, synthetic prefix, alignment adaptation, padding ownership,
weak helper, BSS, exception allocation, constructor or destructor emission.
Standard GC1.3.2 Gekko `-O4,p`, exceptions off and individual register saves
produce the exact source object.

Complete original exception-index, constructor and destructor table scans find
no ownership in this range. The active consumer census reads 10,208 ELF inputs
selected by `objdiff.json`, excluding stale generated assembly. The original
table has exactly its function's HA/LO pair, with zero addends. A bytewise scan
of every initialized original data section finds two external function-entry
pointers and the seven owned jump-table pointers; there is no external interior
function pointer or initialized pointer into the local table. Original direct
branch scans find no external branch into the function. No existing compiled
source/header consumer requires a change.

Original member-pointer pool `lbl_802ECE30`, message `lbl_802AEC74`, shared
small-data scratch fields, external callees and neighboring code/data retain
all original ownership and identities. This is a partial original translation
unit, with credit requested only for the exact function and its complete table.
Frozen integration and ownership evidence is under
`scratch/engine_callback_indexed_action_20261011jr/`.
