# Native constructor identities for four accepted setup bodies

This is a zero-credit proposal for continuation sources already accepted as
ordinary C entries. It retains the same original addresses, all 360 code bytes,
80 exception/index bytes, four callable extents, local metadata symbols,
allocation types/flags and alignments. The proposed native constructors emit
no additional functions or data. All 22 actual retained relocations match the
old objects as a multiset after renaming only the function symbol in its own
exception-index pointer. No source aliases or extra entry points are introduced.

| Accepted C entry | Proposed native constructor | Code | Full factory extent |
| --- | --- | ---: | ---: |
| fn_8002AD98 | Object_8002AD98::Object_8002AD98 | 116 | 0x98 |
| fn_8006565C | Object_8006565C::Object_8006565C | 80 | 0x200 |
| fn_8006590C | Object_8006590C::Object_8006590C | 84 | 0x200 |
| fn_80065C60 | Object_80065C60::Object_80065C60 | 80 | 0x200 |

The dedicated declaration-only native base views retain observed fields and
opaque storage rather than expanding unrelated implementations. CallbackSingle
is exactly 0x78, as established by its accepted header/factory; the collectable
constructor adds words at 78/7C, a vector at 80 and words at 8C/90. Its allocation
is 0x98 in accepted factory 800BB37C (CollectableAgents.h:28).

Agent_80062E18 is declared with its existing native constructor/destructor and
observed vtable08, flags38 and secondary-vtable94. Its opaque tail extends to
the full 0x200 factory allocation (800BA314; ActorScriptAgent.h:101). Each of the
three derived classes adds no storage, updates both tables and sets its observed
flag. The MediumAgent, SimpleAgent and ComplexAgent factories independently
allocate 0x200 at 800BA264, 800BA2BC and 800BA20C. Size assertions cover every
complete base/derived view. Declared destructors are unused; the proposal adds
no dependency on an undefined native destructor.

`scratch/game_engine_native_factory_refinement_continuation/verify.py`
independently recompiles preserved old source and new proposal source, checks
all allocated sections and symbol extents with actual ELF relocations, and
runs the integrator's strict zero-credit invariant checker. The old recompiled
object hashes equal the frozen current production object hashes. The current
canonical aggregates, old source/objects, proposed source/header/objects, exact
relocations, full-table ownership audit and 24 compiled consumer migrations
are preserved in this scratch package. Local extab/index identities remain
@5/@6 in every proposed object. The complete exception-index, constructor and
destructor tables were audited; only the original owned index self-pointers
refer to the four addresses. No ownership range changes are proposed.

The accepted production sources, shared headers, canonical manifests, symbols,
splits and compiler configuration remain unchanged. The integrator must stage
all four replacements and their consumers atomically, extend its ordered
continuation-source history, and require strict final objects plus original
DOL/hash/regression checks. New matching code/data credit is exactly zero.

A separate reused-header alternative for 8002AD98 preserves its 116+20 retained
bytes but emits an unused weak CallbackSingle destructor220 and 20 extra
metadata bytes. Its local metadata names also change. That private alternative
is evidence only and is excluded from this clean same-unit proposal. The first
freeze-script attempt expected a per-unit `integration` field that these
accepted aggregate entries do not contain; the preserved attempt changed only
new scratch snapshots. The completed freeze instead independently verifies
current canonical source hashes, current production objects and exact
recompilation, without assuming that bookkeeping field exists.
