# Callback actions and shared scalar constants, 2026-10-12

The two callback functions below are integrated as Matching. Both use ordinary
C++ and retain their original GLOBAL C entry identities. Root integration
verified the standard DOL hash, native objdiff, original section coverage, and
absence of match regressions.

| Source | Original text | Bytes | Finding |
| --- | --- | ---: | --- |
| `callback_handle_ready_actions_8025D4D0.cpp` | `8025D4D0..8025D588` | 184 | Resolve the callback handle, check readiness, resolve again after each action, and invoke the three existing action providers. |
| `callback_key_filter_clear_8025EBF0.cpp` | `8025EBF0..8025ECB4` | 196 | Clear the low three flag bits and state in linked nodes when the filter is empty or no node key matches a filter key. |

GC/1.3.2 settings are `-proc gekko -fp hardware -enum int -str reuse -common off
-O4,p -inline auto -sdata 8 -sdata2 8 -pool off -Cpp_exceptions off`.
The action function has five actual relocations: context HA/LO and three REL24
calls. The filter function has none. Each has one compiler category relocation;
neither emits data, helpers, EH records, or startup entries. Natural inline
getters preserve the original signed generation/count operations and register
lifetimes. All actual relocations are applied against real native addresses;
probe scores with masked operands are not acceptance evidence.

Eight integrated constant sources own 164 original initialized bytes:
`platform_trig_pool_constants.c` (24), `audio_start_constants.c` (16),
`audio_source_rate_constants.c` (8), `platform_disc_display_constants.c` (8),
`menu3d_pulse_constants.c` (16), `callback_record_default_constants.c` (40),
`resource_constructor_constants_80095E90.c` (28), and
`loading_particle_constants.c` (24). These definitions preserve GLOBAL typed
float/double/string objects already declared by matching consumers. Four bytes
are natural internal string alignment; all emitted bytes are accounted for.
The real five-byte string at `80378C64` remains wholly original with align1;
its first four bytes must not be split off as purported alignment.

Five additional sources are frozen isolated exact candidates awaiting root's
native integration at the time of this note:

| Source | Original .sdata2 | Bytes |
| --- | --- | ---: |
| `early_record_activation_constants.c` | `803781E8..80378224` | 60 |
| `early_record_default_override_constants.c` | `80378228..80378238` | 16 |
| `resource_constructor_constants_800978D8.c` | `80378CB8..80378CD0` | 24 |
| `resource_constructor_constants_80098470.c` | `80378CE8..80378D00` | 24 |
| `menu2d_color_constants.c` | `8037AD68..8037AD78` | 16 |

These 140 bytes contain 35 native GLOBAL floats. GC/1.2.5n uses the same flags
above. Each object emits only .sdata2 with alignment8, no padding, code,
relocations, undefined providers, or compiler helpers. Native main.elf proves
each original binding/address/extent. All 61 direct native accesses are `lfs`;
the complete original initialized-data pointer census finds no pointer into
these groups. All existing source declarations remain unchanged. Preserve the
real original GLOBAL float `lbl_80378224` as a separate four-byte original
owner with align1 or4 between the first two candidates; it is not padding.
Preserve the original preceding and following fragments for every new split.

Reproducible hashes, exact compiler commands, allocation ownership, physical
consumer census, and native binding evidence are in
`scratch/sdk_continuation_20261012_b/`: `freeze_ready_actions.py`,
`freeze_key_filter.py`, `freeze_shared_constants.py`,
`freeze_scalar_constants.py`, `freeze_early_float_owners.py`, and their
individual `*-contract.json` manifests. The baseline and native reports remain
unchanged by these private verifiers.

The fresh `80263DDC` constructor remains private research. A natural C++ view
reproduces its exact 864-byte extent and every instruction/actual relocation
from offset E8 onward (632 bytes). The remaining prefix differs because the
original hoists the pooled string base at `802AEF48` before member construction;
the external GLOBAL string-base probe initializes it later. This earns no
source progress. Inline parameter/constructor probes and the complete direct
pool-consumer census are preserved beside `owner_ctor_members.cpp`.

A separate second scalar handoff is frozen in
`motion_float_owners-contracts.json` / `freeze_motion_float_owners.py`: fourteen
sources, 312 bytes, and 78 original GLOBAL floats used by existing scene,
transform, camera, launch, acceleration, event, record, facing, basis, and
spatial source consumers. Every section boundary is eight-aligned, with no
padding claim. The full direct census finds 303 `lfs` instructions and no
initialized-data pointer into any range. Per-object native binding/address/
size, complete allocated bytes, and source consumer hashes are recorded in
each manifest. Root's native integration is still required for this tranche.

The isolated Node constructor proposal in
`src/Game/node_resource_constructor_802417BC.cpp` reproduces all 1,332 bytes at
802417BC..80241CF0 with GC 1.3.2 and the flags above. All 69 retained actual
relocations resolve to the original addresses. It emits only text: the retained
constructor and 352 trailing unused weak Handle destructors, whose eight
relocations, positive symbols and raw hashes are recorded. All five compiler
category relocations are inventoried separately. No retained relocation targets
the discarded helpers. There is no data, BSS, literal, vtable, EH or startup
allocation.

The nonpolymorphic partial Node view contains a genuine Resource_802E9E20
member at offset zero. Its inline base construction retains the original two
base-pointer aliases, while the borrowed Node table is assigned through the
existing prefix storage view before the first Handle member initializes. This
preserves the existing GLOBAL table provider. A named inline copied-assignment
helper gives the original stack+8 copy lifetime; explicit vector/quaternion
assignment operators preserve sequential loads and stores. The declared
0x138-byte extent agrees with the existing Node_Z.h factory allocation and
destructor view.

The genuine constructor symbol is `__ct__13Node_802417BCFv`, replacing the
provisional GLOBAL `fn_802417BC` at the same address and extent, with self and
returned self in r3. Its original calls are 800CE7B4 and 8020AE40. A full
initialized-data pointer scan, extabindex scan and startup/destructor scan find
no other entry references. Proposed factory and scene_callbacks_more.h identity
edits are saved only under scratch/node_ctor_consumers. All six registered
affected complete objects reproduce current allocated bytes, positive symbols
and relocations after this one same-address name change. The seventh header
consumer, scene_message_allocator.cpp, is unregistered; its isolated before/after
object also remains unchanged. Native `__dl__FPv` is weak despite the provisional
configuration comment; it is referenced only by unused helper output, and that
actual binding is recorded rather than changed.

Reproduce with
`python3 scratch/sdk_continuation_20261012_b/probe_node_ctor_consumers.py` then
`python3 scratch/sdk_continuation_20261012_b/freeze_node_ctor.py`. The final
contract is `node_resource_constructor_802417BC-contract.json`. Root integration
and final native DOL/regression checks remain pending for this proposal.

`src/Game/node_python_factory_800CE754.cpp` is an additional isolated exact
proposal: 296 text bytes at 800CE754..800CE87C, eight EH bytes at 80013858 and
twelve index bytes at 8001D460. GC 1.3.2 uses O4,s, exceptions on, RTTI off and
use_lmw_stmw on; the complete flags are in its frozen contract. All 20 actual
relocations and one compiler category relocation are checked, with no weak,
padding, table or literal output. Passing the local numeric pointer address by
reference through both nested inline encoding helpers removes the prior extra
register copy while retaining the native type and buffer lifetimes. This
consumes only a dead local address variable after allocation and construction.

The existing GLOBAL Python callback identity remains `fn_800CE754`; its two
original initialized-data pointers are the owned EH index at 8001D460 and the
borrowed SWIG method record at 802C1FCC. The latter retains its original owner.
The factory invokes the genuine Node constructor identity above. All GLOBAL
strings, typed SWIG hexadecimal digits and type registry, allocator context and
Python None object retain their current providers. Shared headers are unchanged.
Reproduce with `freeze_node_factory.py`; the final contract is
`node_python_factory_800CE754-contract.json`. Final native acceptance remains
with the root integrator.

Fourteen further typed scalar owners are frozen isolated exact in
`phase_float_owners-contracts.json`: 400 bytes, 100 existing GLOBAL floats and
482 native `lfs` references. Their addresses and source identities are:

| Source stem | Original .sdata2 | Bytes |
| --- | --- | ---: |
| `random_record_setup_scalar_constants` | `803786F8..8037871C` | 36 |
| `early_agent_profile_scalar_constants` | `803788A8..803788D4` | 44 |
| `record_completion_scalar_constants` | `80378938..8037894C` | 20 |
| `camera_orientation_scalar_constants` | `80378998..803789BC` | 36 |
| `actor_event_control_scalar_constants` | `80378AD0..80378AE4` | 20 |
| `resource_constructor_80096954_scalar_constants` | `80378C78..80378C8C` | 20 |
| `actor_vector_interpolation_scalar_constants` | `80378D58..80378D6C` | 20 |
| `owner_elapsed_scalar_constants` | `80378DA8..80378DCC` | 36 |
| `menu_record_layout_scalar_constants` | `803792F0..8037931C` | 44 |
| `scene_color_default_scalar_constants` | `80379518..8037953C` | 36 |
| `qsnail_initialize_scalar_constants` | `80379608..8037961C` | 20 |
| `viewport_layout_scalar_constants` | `8037AC18..8037AC2C` | 20 |
| `animation_cursor_scalar_constants` | `8037B1D0..8037B1EC` | 28 |
| `buffer_record_scalar_constants` | `8037B208..8037B21C` | 20 |

Each `.c` source uses GC/1.2.5n and the scalar flags above. Each emits precisely
its stated .sdata2 bytes, alignment8, and only the original GLOBAL four-byte
objects. There are no relocations, undefined dependencies, code, other allocated
sections or padding. All native bindings, addresses and extents agree; all
existing consumer declarations and physical accesses establish float reads.
The full original initialized-data census finds no pointer into these groups.

Every new extent ends four modulo eight. Keep the entire following original
fragment at align1, including the eight-byte objects at 8037871C, 803788D4,
8037894C and 8037961C and the two-byte object at 8037B21C. None is source padding.
`phase_float_original_ownership_partition.json` partitions all 4,016 bytes of
the nine affected original sections into these 400 source bytes and 3,616
original bytes with no gap or overlap. It records all fragment hashes and the
complete neighboring positive symbols.

Two declaration qualifications are proposed only in scratch candidates:
`engine_queue_followup.h`'s lbl_8037B1D0 and `engine_record_dispatch_80235D54.c`'s
lbl_8037B208/lbl_8037B20C should be const to agree with their observed read-only
storage. `phase_const_consumer_contracts.json` proves all four affected complete
objects retain every allocated byte, symbol and actual relocation after these
qualifications, including agreement with current native build objects. No shared
source/header has been edited by this agent. Reproduce with
`freeze_phase_float_owners.py`, `augment_phase_float_contracts.py` and
`probe_phase_const_consumers.py`. Final link and regression acceptance remain
with the root integrator.

Two further code proposals are frozen with canonical native provider audits.
`record_array_constructor_8007146C.cpp` emits the genuine
`__ct__15Object_80071358Fv`: 156 text bytes at 8007146C..80071508, 28 compiler
EH bytes at 8000C73C..8000C758 and twelve index bytes at 800191F4..80019200.
GC/1.3.2 uses O4,s, exceptions on, RTTI off and use_lmw_stmw on, with the complete
scalar flags recorded in `record_array_constructor_8007146C-contract.json`.
Every byte and all eleven actual relocations match; there is one compiler
category relocation and no other allocated section, weak output or padding.

The source derives Object_80071358 from the observed ContainerLayer_80044168
and ContainerBase_802563CC prefixes. Automatic layer and object vtable writes
retain the native base-pointer aliases and register lifetimes. The EH action is
DESTROYBASE through r30+0 and names the existing ContainerLayer destructor.
The owner extent is 0x390, with nine twenty-byte records at 0x74. The constructor
keeps the native array-constructor callback and count and initializes the
observed short, word and byte fields.

The final handoff requires three GLOBAL, same-address identities:
fn_8007146C becomes __ct__15Object_80071358Fv; lbl_802ECF88/120 becomes
__vt__23ContainerLayer_80044168; lbl_802B7A14/132 becomes
__vt__15Object_80071358. Both tables remain original owners. Their first
callable slots already name the corresponding genuine native destructors.
`record_ctor_consumer_contracts.json` proves all fifty registered consumer
objects preserve every allocated byte, symbol, category and actual relocation
except these identities; all concrete candidates are under
`record_ctor_consumers/changed/src/Game`. There are no shared-header edits.
Original direct calls are 80071250 and 800BB410. The owned EH index is the
sole original initialized-data pointer to this constructor; no startup record
references it. Reproduce with `probe_record_ctor_consumers.py` and
`freeze_record_ctor.py`. Earlier text-only compositional probes are superseded
by this complete genuine inheritance proposal.

`owner_child_handle_copy_80237BC8.cpp` emits the existing GLOBAL fn_80237BC8,
all 120 bytes at 80237BC8..80237C40, with GC/1.3.2 and the scalar flags above.
The C++ value-return ABI uses a hidden destination in r3, owner in r4 and signed
index in r5. The inline array getter establishes the native large-field-address
calculation before the four-layer Handle copy initializes its returned object.
Eight handles at 0xC110 and a signed count at 0xC130 agree with existing matched
reverse-hit, reverse-sphere and world-reference consumers. No caller changes
are needed. The sole direct call is 80237A0C; there are no data, EH, startup or
destructor records referencing the entry.

`owner_child_handle_copy_80237BC8-contract.json` records all four retained real
relocations and 264 trailing unused weak destructor bytes (92+88+84) with six
additional real relocations and raw hashes. All four compiler categories and
all positive symbols are inventoried. No retained reference targets discarded
helpers. There is no data, literal, BSS or padding allocation. The actual native
weak binding of __dl__FPv is preserved. `freeze_child_copy.py` verifies all
retained bytes against the original DOL and the current canonical native
providers. Final integration, DOL hash and regression checks remain with root.


### Seventeen further scalar groups (204 bytes)

The independent `scalar_triples_owners-contracts.json` receipt freezes 17 unique
C sources containing 51 existing GLOBAL `const float` objects, each with one
12-byte `.sdata2` allocation and no code, relocations, anonymous literals or
padding. GC/1.2.5n with `typed_globals_flags.json` reproduces every byte and
positive symbol. The complete native read census contains 141 `lfs`
instructions; existing declarations are already const and need no edits.
Canonical native ELF provider addresses, sizes and GLOBAL bindings were checked.

The sources start at 80378248, 80378288, 80378308, 80378AA8, 80378D10,
80378F78, 80379058, 803790A8, 803795B8, 803795D8, 803795F0, 80379628,
80379750, 8037A588, 8037AA40, 8037ABF8 and 8037B080. All end four modulo
eight; no following bytes belong to these compiler sections. The separate
`scalar_triples_original_ownership_partition.json` covers all 4,376 bytes of the
13 affected original sections without gaps or overlap: 204 source bytes and
4,172 original bytes. Retained original fragments use explicit alignment one,
including complete positive-sized neighboring objects. Native link and
objdiff regression acceptance remain the integrator's final checks.

The 208-byte query-loop frontier at 80210374 remains private: size optimization
and ordinary getter forms reach six genuine instruction differences involving
two register lifetimes and increment order. No source credit or split is
requested for it.

### Twenty-six float pairs (208 bytes)

`scalar_pairs_owners-contracts.json` freezes 26 further C owners with 52
existing GLOBAL `const float` definitions. Each GC/1.2.5n object emits exactly
eight initialized `.sdata2` bytes at alignment eight, with no text, BSS,
undefined symbols, relocations, anonymous literals or padding. All original
bytes and all positive symbol addresses, sizes and bindings pass the isolated
and canonical native ELF checks. The native census contains 215 `lfs` reads
and no initialized data pointer into any new owner.

The sources start at 803784D8, 80378510, 80378578, 80378650, 80379000,
80379048, 80379160, 80379170, 80379350, 803794D8, 803794E8, 80379590,
803797C8, 8037A210, 8037A2A0, 8037A2F8, 8037A4E0, 8037A928, 8037AB30,
8037B140, 8037B160, 8037B2D8, 8037B378, 8037B390, 8037B3A8 and 8037B508.
The adjacent 80379368 pair is excluded from this handoff because the integrator
is reconstructing the controller conversion-pool closure there.

`scalar_pairs_original_ownership_partition.json` preserves all 4,696 bytes of
the fourteen affected original sections: 208 source bytes and 4,488 original
bytes. Every retained original interval uses explicit alignment one, and no
whole positive-sized neighbor is cut. The sole declaration correction is
`extern const float lbl_80378514` in `early_single_record_event_8003F5F4.cpp`.
The candidate and `scalar_pairs_const_consumer_contracts.json` prove all 1,000
allocated consumer bytes, symbols, categories and 28 actual relocations remain
unchanged. Native link, full original DOL hash and objdiff regression checks
remain with the integrator.

### Private transform transition at 801CBDE4

The 1,804-byte transition blends position, scale and quaternion direction over
the observed 0.2-second duration while retaining current/previous resources
through reference-counted handles. Ordinary reference getters recover the
native five saved GPRs and 0x160 frame. An unnamed first Handle temporary gives
the native stack offsets; a named final Point temporary gives the exact returned
vector copy. `transphase9.cpp` reaches the native primary extent with 64 actual
word differences and no new data or altered qualifiers. Handle copy/lookup
scheduling and floating-register lifetimes remain unresolved. A volatile read
was useful only as a private diagnostic for the native repeated duration load;
there is no independent volatile-semantics evidence, and it is not proposed as
source. All probes remain private with zero matching credit or split request.

### Selection key packer at 800596E4 (16 bytes)

`scene_selection_key_pack_800596E4.cpp` reconstructs the existing GLOBAL
function at 800596E4..800596F4. Its unused receiver is followed by two signed
short parameters. The result shifts the first value sixteen bits and ORs the
sign-extended second value, preserving its effect on the upper result bits.
This parameter type gives the native EXTSH-before-SLWI ordering; an int-parameter
form reversed those independent operations. The compiler is GC/1.3.2 with the
scalar flags and `-use_lmw_stmw on`.

`scene_selection_key_pack_800596E4-contract.json` verifies all sixteen text
bytes, the existing GLOBAL function extent and canonical native address, nine
direct native calls and no initialized data pointer. There is one compiler
category relocation, no allocated data, weak output, padding or actual
relocation. The single existing source declaration in
`owner_selection_update_8002A54C.cpp` should use short,short parameters.
`scene_key_consumer_contracts.json` and its concrete candidate prove all 356
allocated bytes, positive symbols, categories and nineteen actual relocations
are unchanged by that declaration correction. Final native link, hash and
regression checks remain with the integrator.

### Nearest box collision at 801DDBFC (1,156 bytes)

`box_collision_nearest_hit_801DDBFC.cpp` transforms the eight native cube
corners, queries each corner, twelve edges and six faces, and retains every
hit that improves the supplied result. The original 64-bit identity is stored
with each improved hit. Its ABI uses r3/r4/r5 for receiver/matrix/result and
r7/r8 for the identity, preserving the r6 alignment gap observed in both
native callers. The 16-byte vertex values have ordinary nontrivial copy
construction and pass by address; the three query providers remain original.
The output view preserves the native 48-byte query output and 64-byte result
with validity at 0x3C. Names describe partial views rather than recovered
original C++ identities.

Reusing one loop counter across transformation, corner, edge and face passes
resolved the point-cursor/counter lifetime differences. Declaring the saved
face-table pointer before the accumulated result resolved the remaining
register allocation differences. GC/1.3.2 with Gekko/O4,p, exception/RTTI off,
`-fp_contract on -use_lmw_stmw on` emits exactly 1,156 text bytes with twelve
actual relocations and one compiler category relocation. There are no data,
BSS, literal pools, weak helpers, EH/startup records or owned padding.

`freeze_box_collision.py` and `box_collision_nearest_hit_801DDBFC-contract.json`
record source/compiler/object hashes, every positive symbol and relocation,
canonical native GLOBAL bindings and extents, both original direct callers,
and no initialized pointer or exception/startup reference to the entry.
The accepted GLOBAL cube BSS, edge/face topology and vertex-w float keep their
existing owners. All emitted allocated bytes match the protected original
DOL after resolving actual relocations. Final native link, hash and regression
checks remain with the integrator.

### Thirty-two independent scalar constants (140 bytes)

`scalar_single_owners-contracts.json` freezes 29 existing GLOBAL float objects
and three existing GLOBAL double objects as ordinary typed constant definitions
in `src/Game/scalar_constant_*.c`. Each owner emits only its native four- or
eight-byte .sdata2 extent, alignment eight, with no trailing allocation, code,
relocations, new literal pool, helper, startup or exception record. GC/1.2.5n
uses the flags in `typed_globals_flags.json`; all object bytes and canonical
native symbol bindings, addresses and sizes pass. Existing compatible const
declarations and native LFS/LFD read censuses independently identify the types.
The root-reserved 8037B558..8037B878 interval and controller conversion pools
remain outside this batch.

`scalar_single_original_ownership_partition.json` preserves all 2,084 bytes
of the fourteen affected original sections: 140 source bytes and 1,944
original bytes. Every remaining fragment uses explicit alignment one and
retains whole native positive-sized neighbors and unnamed bytes. Four-byte
float owners have no manufactured padding.

`scalar_single_consumer_contracts.json` records unchanged hashes for 74
existing source/header files, 69 compatible const declarations, and complete
allocated-section/symbol/relocation receipts for 58 native consumer objects
covering 23,160 allocated bytes. No declaration or consumer was edited.
Reproduction order is `freeze_scalar_single_owners.py`, then
`augment_scalar_single_contracts.py`, then `audit_scalar_single_consumers.py`.
Final integration, original DOL hash and regression checks remain with root.

### Grid nearest-hit query at 801DEF20 (private)

The ordinary source in `grid_nearest/order_abdcnf.cpp` reproduces the native
1,400-byte primary extent and all floating operations for the vertex, edge
and triangle nearest-hit passes. It retains 54 actual instruction-word
differences in pointer/counter allocation and has no proposed split or
matching credit. Counter and cursor scopes, six meaningful local declaration
orders, typed cursor views and supported optimizer profiles are preserved in
the private probe directory. The remaining differences are not hidden by
relocation masking, qualifiers or data changes.

### Additional private scalar handoff: 57 float owners, 228 bytes

The private `scratch/sdk_continuation_20261012_b/scalar_more/` batch defines 57
existing GLOBAL `const float` objects using the compatible declarations already
present in reconstructed consumers. GC/1.2.5n and the unchanged
`typed_globals_flags.json` settings emit one exact four-byte `.sdata2` section
per owner, alignment eight, with no code, pool, relocation, helper or trailing
allocation. The constants retain their original names, native GLOBAL bindings
and four-byte extents. The unqualified `lbl_803790B8` declaration was excluded;
`lbl_80378560`, the controller conversion pools and the integrator's reserved
`8037B558..8037B878` interval remain outside this batch.

`scalar_more_owner_specs.json` and `scalar_more_owners-contracts.json` identify
private source candidates and intended production paths. The complete original
partition receipt accounts for 4,172 bytes across 29 affected sections: 228
source bytes and 3,944 original bytes. Every retained original fragment uses
explicit alignment one; whole neighboring objects and unnamed bytes remain
original. There are no source claims for linker padding.

`scalar_more_consumer_contracts.json` freezes 78 unchanged source/header files,
62 available consumer objects and 86 compatible const declarations.
`scalar_more_linked_consumer_contracts.json` independently scans all complete
source units in the current objdiff configuration, finding 54 linked consumer
objects, 36,375 allocated bytes and 87 actual relocations to these constants.
Each receipt includes positive symbols and complete allocated-section and RELA
table hashes. The native instruction and initialized-pointer census is retained
in each individual contract. Final standard linking and hash/regression checks
remain the integrator's acceptance step; private candidates earn no credit.

### Private animation application `801EDD8C`: native extent, four words remain

`animation_frame_apply/integer_curve_index.cpp` is an ordinary C++ candidate
for the 2,516-byte animation-frame application function. GC/1.3.2 with the
usual Gekko/O4,p, automatic inlining, disabled C++ exceptions/RTTI, hardware FP,
FP contraction and load/store-multiple settings emits the exact sole `.text`
extent, stack frame `0xE0`, all control flow and GPR instructions, and all 43
actual relocations. No data, exception table, helper or weak allocation is
emitted. Four FP words in the first upper weight clamp still differ, so this
candidate remains private and uncredited.

The reconstructed operation samples position, orientation, scale, weight,
motion and color channels. It handles distinct light/camera views, transforms
motion offsets through the resolved ancestor matrix, combines ancestor and
sampled rotations, then marks the target transform changed. Typed matrix
transformation with named X/Y/Z components matches both complete repeated
matrix/addition sequences. The quaternion output accessor must write directly
to its caller's object; returning a trivial quaternion by value introduced two
unnecessary copies and 32 extra stack bytes.

The motion sampler ABI needs **two** scalar FP arguments. Original
`fn_801ED050` entry saves F1 into f30 and F2 into f31; both remain in use in its
body. The observed application calls pass `weight * self->rate` in F1 and
`self->rate` separately in F2. The first provisional one-argument prototype was
incomplete and is superseded. `fn_801B0C3C` returns an integer curve index in
r3; this application ignores it and uses the output float and byte flag.
The preserved `integer_curve_index.json` resolves real relocations and records
the only remaining mismatch: native clamp loads weight into f1 and the upper
bound into f0, while the candidate exchanges those registers. Equivalent
scoped, reference, output-parameter and comparison forms did not close this
bounded frontier. All constant and vector providers remain external originals
or their already accepted source owners.

### Private established float ownership: 298 objects, 1,192 bytes

The `float_remaining/` private batch defines 298 four-byte GLOBAL constants
whose versioned metadata already identifies `data:float`. A deduplicated native
assembly census and independent original-DOL opcode scan agree on all 663
accesses: each is an `lfs` using SDA2. There are no initialized data pointers
or ambiguous address/integer accesses to these objects. Existing declarations,
where present, already use compatible `const float`; unqualified objects
`80378560` and `803790B8` remain original. The reserved `8037B558..8037B878`
interval and controller conversion pools are excluded.

GC/1.2.5n with `typed_globals_flags.json` emits a sole four-byte `.sdata2`
allocation, alignment eight, for every candidate. All original numeric bytes,
native GLOBAL identities and extents match, with no code, relocation, helper,
undefined dependency or trailing padding. The canonical native provider audit
was frozen only after the standard DOL SHA1 was restored. It checks all 298
providers and 543 adjacent positive symbol records against the canonical ELF.

`float_remaining_original_ownership_partition.json` accounts for every byte in
92 affected original sections: 6,560 bytes total, 1,192 new source bytes and
5,368 retained original bytes. Every remaining original fragment explicitly
uses alignment one, preserving whole positive symbols and unnamed bytes. No
neighbor or linker padding receives source credit.

The source/header receipt contains 11 unchanged files, one available consumer
object with 1,116 allocated bytes and ten compatible declarations. The complete
linked source-object census independently finds two consumers, 2,384 allocated
bytes and two actual scalar relocations, recording all allocated-section,
positive-symbol and RELA hashes. `float_remaining_native_provider_contracts.json`
contains the canonical provider snapshot and immutable original access roots.
The integrator still must run the standard full DOL, extent and regression
gates; these private candidates alone do not count as accepted progress.

## Stack-owner callback registration80071234

Private exact ordinary source and receipts are frozen in
`scratch/sdk_continuation_20261012_b/local_owner_registration/`. Genuine external
Object constructor declaration closes the old constructor-wrapper lifetime;
GC1.3.2 with established `-O4,s`, automatic inlining and exceptions emits all292
native instruction bytes,24 extab bytes and12 index bytes exactly. Current sole
registry caller and existing GLOBAL Object destructor owner remain unchanged.
Trailing weak276-byte destructor plus52 EH/index bytes are fully inventoried,
byte-exact backups with zero new credit; the existing GLOBAL provider supersedes
the sole retained EH reference at its unchanged native address. The full656-byte
emission resolves all40 actual RELAs,23 retained/17 discarded. No raw blobs,
qualifiers, literal storage, table claims or symbol migrations are used. Incoming
native/provider/caller snapshot and read-only verification pass; root integration
and full native acceptance remain required. Retained original partitions and
precise compiler flags are in the handoff.

Viewport-owner801E1920 now reaches its full392-byte extent via an ordinary inline
member constructor taking the shared string pointer by const reference. Seven
initial address-materialization words still differ; all subsequent array/member
construction, callbacks and fields match. Its proposed compiler vtable address
lookup is diagnostic only, with no identity/ownership/source credit. All private
variants remain under `viewport_owner_refine/`; production is unchanged.

## Handle erase pair8022B9F8/8022BCFC

Frozen ordinary sources under `handle_erase_refine/` each match312 bytes with
four actual RELAs and no other allocated output. Native equality resolves signed
24-bit index/signed8-bit generation handles to resources; the first matching
owned element is released and the tail compacted. Const typed index value plus
an ordinary generation-matching Entry accessor closes the prior ten register
lifetime differences. The two incoming native calls and complete unchanged936
allocated bytes of related_actions.cpp are audited against the fresh accepted
incoming graph; no initialized pointer references either function. Native GLOBAL
identities, external context and helpers are unchanged. The624-byte code handoff
owns no data/padding and changes no headers, tables, symbols or central files.
`erase_pair-contracts.json`, incoming audit and read-only verifier preserve the
strict compiler/allocation/SY/actual-RELA proof; native root integration remains
required. Earlier near-match research remains untouched.

## Name erase824 and original-EH registration152

`name_erase_refine/` freezes exact ordinary name388/path436 entries using the
const typed index and signedchar bounded-generation key resolver. Ordinary
if/return key values preserve native temporary lifetimes; a ternary key extends
them and introduces spills. Both sole text allocations resolve all32actualRELAs
without masks. Existing context, strings, Handle providers and GLOBAL identities
remain externally owned. Fresh nativee0350422 input/source/pointer census freezes
all3816allocatedbytes of the two unchanged consumer objects. The only source ABI
correction changes the five-result-discarding scene caller's declaration return
fromvoid toint; its entire object remains byte-identical (exact receipt).

`large_local_registration/` freezes a genuine first-member B310-byte automatic
owner registration,152exacttextbytes/sevenactualRELAs with exceptions disabled.
The original unsupported-action17EH record28bytes at80014FA4 and its12-byte index
at8001EAE0 explicitly remain original-owned LOCAL hidden records with zero source
credit. The source emits no EH and neither normalizes nor interprets their raw
word. Existing strong ctor/dtor and complete5356-byte registry caller remain
unchanged. Root is testing the permitted partial text-only split with the original
40metadata bytes retained in a separate original-only unit. Combined strict
production/native checker `name_erase_refine/verify_code_batch.py` requires exact
source objects, full unchanged consumers, native map ownership/providers and
original-only metadata retention. The976-byte batch is handed to root; final
DOL/hash/regression/partition acceptance remains required before credit.

DTK rejected the152partial because extabindex and function splits must have the
same unit identity; its normal link selects whole source or original objects.
Root removed that pending unit registration to keep all reported progress linked
and accepted. The function and all40metadata bytes therefore remain original-owned
and uncredited. Bounded EH-on GC1.3/1.3.2r/2.0 trials each reproduce the same sole
action-word mismatch;1.2.5n rejects local data greater than32KiB. No supported
existing mixed-object configuration or action17normalization was found.

Fresh neighboring resource-load80262F3C/628 reaches the exact retained size with
six requested-local-index/generation GPR coloring differences; every later loop,
call and instruction matches. Separate172weak backup bytes receive no credit.
Resource-save80262AFC/700 reaches native size through an ordinary inline member
cleanup scope, preserving33temporary-stack/GPR differences and172weak backup
bytes. Paired-dispatch8024CEDC/240 repeats the prior18second-argument differences.
All three private folders preserve precise raw symbol/actual-RELA/near-match
inventories, with zero source credit and no central ownership change.

### Scene-disable callback 8008B0EC

Fresh ordinary reconstruction matches192 code bytes plus native EH8/index12 with GC1.3.2 O4s/EH-on. A const typed HandleIndex and signed-char Entry getter close the first resolver's seven scheduling differences; both repeated resolutions remain explicit around resource.enabled byte88h store. Existing GLOBAL C void entry and original vtable target802B8A80 are preserved. No pools/helpers/weak output. All five actual relocations and every212 allocated bytes resolve exactly, including the defined LOCAL exception object. Fresh incoming native audit against91585e47… has one unchanged original .data84-byte consumer and no src/include declaration consumers. Private contract/checker/HANDOFF live in `scratch/sdk_continuation_20261012_b/early_scene_disable/`; final native integration remains root-owned.

### Genuine scene/vector constructor800E21D8

Fresh ordinary member initializers close all176 native code bytes and EH8/index12. The historical class candidate performed both automatic Vector construction and an explicit Vector temporary assignment; the genuine class now constructs it once after initializing scalar members. A first-value initializer sets the existing derived vtable before native defaults, using the established800E1A28 construction pattern. The real Object_800E2288 declaration is shared with the accepted paired destructor; the latter's entire204-byte object and all SY/RELAs remain byte-identical. Constructor emits176+20 retained bytes and an unreferenced weak prefix destructor100+20, fully inventoried and requiring native UNUSED discard with zero credit. Fresh incoming audit at35bc89d4… has one original320-byte factory consumer, unchanged modulo the sole undefined ctor identity rename. Existing tables/zero vector/scalars/providers retain their original ownership and native bindings. Contracts, shared header/corrected destructor source, complete weak inventory and strict read-only verifier are frozen under `scratch/sdk_continuation_20261012_b/scene_vector_ctor/`; central integration remains root-owned.

### Genuine worker-color startup80269A30

`color_arrays_startup/` freezes a natural compiler startup closure:52textbytes,
its4-byte `.ctors` record, and the complete1616-byte typed BSS owner. Two genuine
four-float objects produce the observed stores; two792-byte OSThread objects
retain their definitions. GC1.3.2 O4p/EH-off with supported `-opt nocse` reproduces
all allocated bytes and actual relocations, preserving all four GLOBAL BSS names
and extents. The generated startup function is genuinely LOCAL. Full incoming
census,11 unchanged source consumers and four frozen historical storage receipts
are pinned. `verify_startup.py` includes a narrow storage supersession API that
requires fresh actual-native map/source ownership and unchanged complete provider
extents; the retired unlinked old object alone cannot qualify progress. Root owns
integration and native acceptance.

### Bounded game-main and grid frontiers

Private `game_main_pool/` confirms the bounded context at801E9D24 ends exactly
801E9F40:540/0x21C bytes. Root's exploratory longer root-path view is not an owner.
Supported nopropagation leaves seven main864-byte GLOBAL-BSS materialization
words; exact compiler-LOCAL record/thread output cannot justify changing the
native GLOBAL providers. A natural complete context startup still needs the real
context in original `.text`; no legitimate compiler placement path was found.
No source, metadata, binding or ownership migration was made.

`grid_cell_trace/` reconstructs the1040-byte grid traversal and validates genuine
`__fres` output. Ordinary explicit axis blocks promote steps to registers;
compiler unrolling retains undesired reciprocal spills. None of the bounded
aggregate/accessor/supported-option variants is exact. Existing GLOBAL zero/one
constants remain external and no qualifier or raw storage claim was introduced.

### Polynomial pair801DE498/801DEA88

The game-frontier cubic reconstruction and natural128-byte LOCAL pool close the
complete quartic1520/cubic1176 pair when the three mathematical fractional
coefficients use literal arithmetic. Replacing `lbl_8037A500/8.0` and `/16.0` in
those expressions with `1.0/8.0` and `1.0/16.0` permits genuine constant folding;
actual coefficient-array unit values still load the existing GLOBAL one. Private
`polynomial_first_block/fractional_literals.cpp` resolves every actual relocation
and matches all2696text+128pool bytes under GC1.3.2 O4p/EH-off/lmw-on/fp-contract-on.
The game-frontier agent owns the complete incoming pool-consumer audit and final
handoff; no central files were changed here.

### Named setup temporaries

`springboard_setup/` reproduces432 bytes with12 remaining words after bounded
Name lifetime refinement. Combining its already accepted GLOBAL64-byte pool is
byte-exact but leaves the native ADDI-zero versus compiler MR materialization.
`actor_named_target/` preserves504-byte16-word near-match; typed index/generation
and manager-parameter boundaries do not close the scheduling or Key/Handle stack
slot differences. Both remain uncredited research with original providers fixed.

### Message parser empty buffer and state RTTI continuation

The empty message work buffer at `802A19F8..802A21F8` has an existing complete
`Buffer { char text[2048]; }` declaration in the accepted scene parser. Ordinary
aggregate initialization emits one GLOBAL object and exactly 2048 bytes of
`.rodata`, with natural alignment8 and no text, helpers, relocations or padding.
The complete parser source/object remains unchanged. The incoming snapshot at
main ELF `b1f7c42d59c10ac0f0ef3fc811d65f0b04054350e667d4237b982269f48ea274`
checked all7575active inputs/133832raw RELAs, the sole HA/LO consumer at parser
object offsets50/58, all original initialized-data byte positions, and native
prefix/following ownership. The private handoff and strict production/map
checker are under `scratch/sdk_continuation_20261012_b/message_text_buffer/`.
The old full2440-byte readable owner/partition and its immutable receipts are
preserved; a narrow helper verifies the retired2048 fragment against actual
current source ownership, rather than allowing a stale original object to
qualify it.

A fresh natural grouping under `rtti_state_records/` compiles the established
0.99 float at `80374A18` followed by sixty native `NativeRuntimeTypeInfo` records
at `80374A1C..80374BFC`. It emits exactly484 bytes of `.sdata`, alignment8, and
119 actual relocations, all raw bytes exact after real relocation resolution.
The prefix float makes the otherwise4mod8 first descriptor position natural.
Fifty-nine descriptors already have shared declarations; final `CStateIdle`
at `80374BF4` is a genuine8-byte record followed by four original zero bytes.
Its existing provisional annotation is12 bytes, so integration needs an
explicit narrowly audited extent correction and original-only tail ownership.
The final borrowed base list at `802B9280` contains two `(type, offset)` entries
and one null terminator (20 bytes); it remains original. Root subsequently
accepted the full484-byte group with the original DOL hash and all native,
historical, source-extent and test gates. The incoming census resolved178 actual
references from87 unchanged consumer objects; the four-byte tail remains original.

### Further typed RTTI and token storage

`rtti_other_records/` naturally owns300 bytes at803754B8..803755E4 (the signed
GameCube error code initialized to-1 plus37 native type records) and44 bytes at
80375BA0..80375BCC (three already-declared memory-card name pointers plus four
type records). The complete objects emit82 real ADDR32 relocations and45 GLOBAL
allocations. Incoming census311 references/32 whole consumers proves that final
provisional12-byte annotations at755DC and75BC4 are real8-byte descriptors;
their four-byte tails stay original and uncredited. No shared headers change.

`actor_token_buffer/` groups the established GLOBAL char64 buffer at802F4108,
accepted float[3] at802F4148 and GLOBAL char68 buffer at802F4154. Both token
dispatchers clear byte0, format values through sprintf and return the buffer.
Ordinary C emits exactly144 NOBITS bytes with three GLOBAL objects and no code,
helpers or relocations. It adds132 bytes while preserving the existing12-byte
vector. The strict historical adapter retires the old active vector unit and
requires the real new mapped/objdiff/source provider; the unchanged old source,
object and sdk-state-leaf contract remain historical witnesses. Incoming census
114 references/15 complete consumers and all preceding/following original
fragments are preserved. Root promoted344+144 with the original DOL hash;
the next main ELF is86e3047a8bc6b75707a486892771d17c1222ec41b273ef4aa49523ec1ee536fc.

GLOBAL data allocations in native MWLD symbol tables appear after the ELF
sh_info LOCAL/GLOBAL boundary. The last preceding FILE can be unrelated
(__mem.c for the2048-byte buffer), so it cannot establish GLOBAL ownership.
The preserved original checkers have strict successors that use the exact
compiler FILE, valid native symbol partitions, whole-object/SY/RELA identity,
sole actual active provider, actual native map rows and objdiff source owner.
The complete mapped ELF must equal actual main ELF; original DOL hashes stay
mandatory. No FILE name, binding or retention metadata was fabricated.

### Further semantic platform state

`platform_small_storage/` isolates72 ordinary NOBITS bytes in five units:
char32 DVD-read buffer80373100; disc status/three guard bytes/u32 at80378170;
two decoder ints80378180; two frame flags/timestamps at80377FF0; and float
motion time80377768. All types, including FF0's existing volatile qualifier,
come from pinned accepted declarations. The compiler emits13 GLOBAL objects
and seven natural internal alignment bytes, without text or RELAs. The
incoming snapshot on86e3047a… checks7578 inputs/133834 RELAs,66 incoming
references and10 whole unchanged consumers. Only lbl80378178 needs provisional
size8→4 refinement; its four-byte tail and every original prefix/suffix remain
original. The strict five-row handoff is complete; final root integration is
pending. No ambiguous callback word pairs or untyped padding were claimed.

### State operation records, private handoffs (2026-10-15)

The complete original GLOBAL state record fragment `802B87C0..802B89F0`
now has ordinary typed source for560 initialized bytes:12 heterogeneous native
C-entry operation records and11 already declared RTTI base lists. The isolated
GC1.3.2 object emits exactly one naturally8-aligned `.data` allocation,23
unchanged positive GLOBAL symbols and95 actual ADDR32 relocations. The complete
new relocation graph agrees with the old560-byte provider at every physical
place, target, binding and addend. All23 required accepted declaration corrections
preserve their complete compiler objects, including EH and all raw symbols and
relocations. Compiler-only C++ call probes establish the12 genuine destructor
entry ABIs without introducing replacement code or metadata. Three original timed
forwarders preserve f1 without arithmetic; float versus double original source
formals remain indistinguishable, and the documented double declaration follows
existing accepted forwarding source. This is an ABI inference, not additional
code credit.

The incoming graph was frozen at ELF614284bbc89363b3a5e5f3478dd54446057cd967a1d4db9b8cf77067339d6ca4:
7585 inputs,133834 actual relocations,59 incoming references to object starts,
24 complete consumers and55 complete providers. The private handoff and strict
old484 dependency adapters are in
`scratch/sdk_continuation_20261012_b/state_native_tables/HANDOFF.md`.
Root integration and full acceptance determine production status; this note does
not claim the private560-byte object as linked progress.

A further private costume group `802B89F0..802B8B30` compiles exactly320 bytes
with12 GLOBAL objects and55 actual relocations, combining232 original bytes
with88 bytes already owned by three typed base-list units. Its entire six-owner
union preserves all positive identities and physical relocations. All11 affected
accepted consumer corrections also produce byte-identical complete objects.
All callback prototypes in this group come from existing accepted source; four
additional genuine C++ destructor call probes establish the compiler entry ABI.
The probe is under
`scratch/sdk_continuation_20261012_b/costume_native_tables/`; no current graph
snapshot or production ownership is claimed yet.

### State record acceptance and next complete pairs (2026-10-15)

The560-byte state closure above is now fully accepted at native ELF
`d6354002826dddacb7bf056d050340b1508dd31f17e2cf9783859186c34ee317`:
standard and mapped original DOL hashes, all prior native proofs, interval
coverage, source extents and66 tests passed. Its bounded checker successor
accounts for MWLD's sorted exception-index map rows and validates only complete
owned canonical rows, while preserving all immutable original receipts.

The320-byte costume closure now has a frozen exhaustive incoming audit against
that graph, plus a root-ready production ownership verifier,11 negative/positive
adapter tests, and explicit old33652/484/560 proof routes. It preserves six whole
old owners and11 complete consumer objects, with232 additional data bytes;
production status remains determined by root's acceptance. The full handoff is
`scratch/sdk_continuation_20261012_b/costume_native_tables/HANDOFF.md`.

A fresh private scout selects21 further state pairs whose callback definitions
are all already accepted source. Eight contiguous groups emit exactly1008 bytes,
42 GLOBAL positive symbols and168 actual relocations, preserving588 original
bytes plus420 already accepted typed BaseList bytes. Forty-two declaration
corrections preserve every complete compiler object. Twenty genuine destructor
call probes establish40 explicit/delete compiler calls, with no code credit.
The whole42-owner original union is frozen under
`scratch/sdk_continuation_20261012_b/state_operation_scout/`. Original callback
states between these groups remain untouched; no graph snapshot or production
credit is claimed for this1008-byte private probe.
