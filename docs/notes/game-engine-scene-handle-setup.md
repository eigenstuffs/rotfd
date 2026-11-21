# Scene and record Handle setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ten ordinary scene service functions are frozen under `engine_scene_handle_setup_`:
800EB7C0, 800EB95C, 800EBCC0, 800EBFA8, 800EC0B8, 800EC20C, 800EC334,
800EC6D8, 800EC82C, and 800EF788. The isolated production objects match 2,120
original code bytes, 560 original extab/index bytes, and 196 retained actual
relocations. GC 1.3.2 uses the established space optimization, automatic inlining,
exceptions enabled, and lmw/stmw flags. Every existing entry name is preserved.
Central original DOL acceptance and native backup discard remain mandatory.

The observed context has a Handle manager at118, Scene pointer at124 and record
service pointer at164. Scene records at1505C supply an owner pointer and
service15060 supplies the second service. Owner wordC is the Record pointer;
the Record's four-byte Handle is at4. Record service field1C points to a first
word used to save global803778C0 before replacing it through fn800B6C84. The
other global803777C4 is passed unchanged as an observed service argument. No
complete object identities or omitted field interpretations are claimed.

Six teardown variants call the scene service, copy and retain the owner's
Handle, pass that temporary through fn800B6F70, destroy it, then restore the
saved service value. EBCC0 additionally refreshes owner wordC first. Four setup
variants install owner wordC, save the previous service word, apply a retained
Handle through fn800B6DA8, then construct a name from an original string and
call fn800C3934 followed by fn800C2540. Their original scalar defaults and two
extra fn8007D7F4 calls in EC334 are retained.

The Handle declaration uses existing native Handle801F7F10 construction and
cleanup. Its inline typed Handle80020478 destructor calls the native base,
with the original allocator-backed throw() operator delete. This emits a real
112-byte weak backup plus its 40-byte extab/12-byte index. Retained exception
metadata refers to the existing original strong Handle80020478 destructor at
80020478. The canonical owner source, recursive header hashes, complete original
relocations, production object hash and an independently recompiled identical
object are frozen in each manifest. The guarded adopted weak-override audit
compares all retained bytes after actual strong resolution and inventories
every allocated byte, including backup metadata. Aggregate backup output is
1,120 code bytes, 520 metadata bytes and 70 actual relocations; none receives
matching credit. Final native ELF/map acceptance must retain the strong owner
at its original address and discard all ten backup text/EH/index groups.

The four name setups required the original three distinct stack lifetimes:
Handle at8, name construction atC and copied Name at10. A genuine inline
applyHandle helper containing a full-expression by-value Handle temporary,
followed by a const Name reference bound to a construction temporary and a
local Name copy, emits those exact operands. Direct named locals and direct
by-value calls had swapped stack locations and remain private probe history;
they receive no credit. The helper emits no function of its own. EB7C0's float
at10 and EC334's byte at10 use private alternative views of that observed slot.

Each true function extent and its one original exception-table record are
independently audited against full extabindex80015F60..8001F2C0. Full constructor
80299920..80299980 and destructor80299980..802999A0 tables have no references.
All original extab/index ownership transfers with its retained function. There
are no additional data allocations. dependency_symbols includes only actual
undefined ELF relocation targets, including backup dependencies. Frozen source
and verifier hashes are listed in handoff.json. No shared metadata, accepted
source, or original extraction was changed.
