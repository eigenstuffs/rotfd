# Unclassified function probes, 2026-10-20

The following bounded candidates were compared with native objdiff against the
normalized GSQE78 DOL. They remain **NonMatching** and earn no source credit.
The `ninja baseline` snapshot preceded all changes. Their partial text splits
leave neighboring original code and all unclaimed data under original ownership.

| Original text | Candidate | Current isolation result | Remaining difference |
| --- | --- | --- | --- |
| `800AC260..800AC2B4` | `src/Game/resource_record_find_800AC260.cpp` | 80 source bytes vs. 84 original; 94.76% fuzzy | The compiler folds the original `bne; b` pair into a single `beq`. The routine scans 0x58-byte records for the selected signed key. |
| `8009237C..800923B4` | `src/Game/actor_planar_motion_8009237C.cpp` | 56 bytes on both sides; 52.07% fuzzy | Floating point load order, register assignment, and addition scheduling differ. The original adds stored deltas at `+0x358/+0x360` into planar fields at `+0x144/+0x14C`, using `game_vec3_zero` components. |
| `8020BE78..8020BECC` | `src/Game/vector3_storage_construct_8020BE78.c` | 76 source bytes vs. 84 original; 80% fuzzy | The original preserves two pointer aliases in `r5/r6` during four zero stores before calling the verified `fn_8020BECC(self,16,1024)`. The current C optimizer removes those moves. |
| `801B11EC..801B12DC` | `src/Game/packed_vector_convert_801B11EC.c` | 240 text bytes on both sides; 98% fuzzy | Both functions use the right signed-short fields and scale `lbl_8037A20C`, but the compiler emits a private eight-byte integer-to-float bias pool instead of referencing shared `lbl_8037A1F8`; it also assigns the bias and scale to opposite FPRs. The pool has no accepted source ownership. |

Additional private `fn_8009237C` probes varied expression order, temporary
grouping, volatile access, three GC compiler versions, and optimization and
scheduling flags. The 56-byte candidate remained ten instruction words away;
the compiler canonicalized the expression variants to the same schedule.
Evidence is in `scratch/planar_motion_20261020/`.

For `fn_800AC260`, `-opt nocse` restores the 84-byte extent but reloads the
selected key and still folds the original `bne; b` pair into `beq`. That
candidate differs at seven instruction words. Other tried loop and peephole
flags remained nonmatching. Evidence is in
`scratch/resource_record_find_flags_20261020/`; no code is credited.

An additional three-function pointer-adjustment probe at
`80062D98..80062DB0` compiled as ordinary C++ calls, producing 36 bytes per
function instead of the original eight-byte tail branches. That failed probe
was removed from the active split rather than credited as C++ source. The
original thunks and the interface table that references them remain intact.

Isolation percentages are diagnostic only. Promotion requires exact code and
owned data, original relocations, an unchanged DOL hash, and `ninja changes`
without regressions. No source file in this note is integrated as Matching.

Additional isolated probes in this continuation did not qualify for promotion:
declaring `lbl_8037A1F8` locally beside the packed-vector conversion generated
both that global and a second private bias constant, while an explicit
signed-int-to-double union conversion added rounding instructions and changed
the floating-point schedule. A vector-storage initialization helper inlined
and still removed the original `r5/r6` alias moves. A C-front-end variant and
older compiler versions of the resource finder retained the missing branch;
an alternate do/while source made its control flow less similar. A quaternion
normalization probe at `801F1AAC..801F1B1C` reproduced its component order and
zero test, but `__frsqrte` conversion inserted extra rounding instructions.
The stream-copy probe at `801E9F40..801E9F8C` emitted the original `dcbt`
intrinsic, but its index loop differed. These are probe findings, not matched
source or accepted byte counts.

An event handler at `80069330..80069398` has a private source probe at
`scratch/game_actor_event_80069330/actor_event_80069330.cpp`. With GC/1.3.2,
`-O4,s`, and C++ exceptions enabled, its 104 text bytes and 20 bytes of
exception metadata align with the original except for an unsigned-short to
float bias relocation. Native objdiff reports 99.80769% text and an extra
private eight-byte `.sdata2` constant; the original function refers instead
to the shared `lbl_803787F0` double. An explicit union conversion references
that shared constant but adds a rounding instruction and changes the stack
and register schedule. Defining the shared constant beside the cast, even
with `-pool on`, emits two identical eight-byte constants. The split and
configuration entry were removed after the probe so its relocation-masked
score cannot inflate reported matched source. The original function and its
exception records remain under their original owners.

`fn_80089150` at `80089150..80089208` is a separate actor-completion reset
probe saved in `scratch/game_completion_reset_80089150/`. Its source identifies
the actor flag reset, virtual float setter, scene mode reset, system/input
flags, and conditional monitor callback using the existing completion views.
GC/1.3.2 `-O4,s` emits the original 184-byte extent and matching call
sequence, but saves both `r30` and `r31` where the original saves only `r31`;
it also hoists the second zero assignment across a call and schedules the
controller mode store differently. Typed-controller, const-global, and
volatile-store variants did not remove those differences. This probe is not
registered, split, linked, or counted as matched source.

Further `fn_800AC260` loop variants that explicitly use `continue` or retain a
local result pointer still compile to a different branch layout; their private
sources are in `scratch/game_resource_record_find_800AC260/`. A plain C
forwarder for the eight-byte adjustor thunk at `0x80028140` emitted a 36-byte
call frame instead of the native adjust-and-tail-branch pair. Its private
source is in `scratch/game_adjustor_thunk_80028140/`. Neither probe is linked
or credited.

The contiguous `80062D98..80062DB0` range contains three more eight-byte
receiver-adjusting tail branches with a `-0x60` offset. Ordinary C wrappers,
with both void and returned-call signatures, compiled to 108 bytes with call
frames rather than the original 24-byte thunk group. The bounded unsuccessful
probes are in `scratch/game_adjuster_thunks_20261020/`; no code is credited.

A planar-distance probe at `80066E08..80066E60` confirmed that the routine
loads two position pointers at owner offset `0x124`, subtracts their X and Z
coordinates, and returns the estimated square root of the squared planar
distance. A first ordinary C attempt used the wrong embedded-vector offset
and emitted 27 words against 22 native words. Its isolated source is at
`scratch/planar_distance_probe/probe.c`; no split or progress credit was added.

A constructor probe at `8024E18C..8024E200` recovered the base-constructor
call, derived table, six zeroed handles, kind/flag fields, and float value.
Moving the float load before the handle stores reproduced the original
116-byte extent and all ordinary body instructions. The linked address
relocations were not tested; the private compiler output still restores `r0`
before `r31`, opposite the original epilogue. The probe is retained at
`scratch/constructor_8024E18C_probe/probe.cpp` and earns no source credit.
An actual C++ constructor form in the same scratch directory reproduced the
116-byte body but retained the same epilogue mismatch.

The global resource-cache initializer at `80020C78..80020D00` has a private
probe in `scratch/global_resource_cache_init_80020C78/`. Its BSS storage is
already source-owned. Using one typed view of the registration record, record
array and two 200-entry caches reproduces the original 136-byte extent and
three call targets. The compiler still uses `mr r5,r31` where the original
uses `addi r5,r31,0`, and stores the array's second and third fields through
`r31` instead of the materialized `r3` array pointer. The `.ctors` word at
`0x80299924` remains original-owned. No code or constructor data was promoted.

A second private probe, `global.cpp` in the same directory, declares the record
array and both caches as genuine C++ global objects. GC/1.3.2 then generates
the original 136-byte initializer instruction sequence, including the `addi`
and `r3` stores, along with the adjacent 12-byte entry constructor, a
four-byte `.ctors` pointer, and the expected `0xC98` BSS layout. Integrating
these generated sections requires reconciling the already matched entry
constructor, exception-enabled record destructor and BSS owners. This remains
an isolated compiler result, with no linked source credit yet.

A full integration attempt moved the `0xC98` BSS region and generated entry
constructor into the global-object source. It retained the new initializer's
exact private code but changed the previously matched `fn_8001F38C`
interpreter initializer from `0x18C` to `0x19C` bytes. That function's original
translation unit uses co-located BSS definitions to select its register and
address schedule. The full DOL hash rejected the attempt. The source, build
logs and objdiff evidence are preserved under the same scratch directory; all
integration edits were restored and the original DOL hash passes again.

A later private `ResourceArray`/`ResourceCacheEntry` global-object probe in
`scratch/game_python_resource_cache_startup_20261020/` reproduced all 136
startup text bytes, the four-byte constructor entry, eight exception bytes,
twelve index bytes, and the 3,224-byte BSS layout, with fourteen actual
relocations and no allocated-byte differences. The adjacent constructor and
destructor can be resolved to their existing original addresses, but moving
BSS ownership again changes `fn_8001F38C` code generation. Its standard link
failed the DOL hash; all integration edits were rolled back. This exact
isolated object is research evidence and earns no linked-source credit.

The renderer diagnostic interval `802AF064..802AF100` was probed as seven
ordinary C++ string definitions. GC/1.3.2 emitted the first 150 bytes
exactly, but the original has six trailing alignment bytes. Splitting those
bytes into a separate raw object shifted later data by eight bytes in the
native link; the DOL hash rejected the attempt. The entire interval retains
its original auto split and progress denominator. The isolated source and
object are in `scratch/game_render_diagnostics_802AF064_20261020/` and earn
no credit.

`TRK_flush_cache` at `8011C2CC..8011C304` was tested as ordinary C in
`scratch/trk_flush_cache_8011C2CC_20261020/`. GC/1.3.2 recognizes the data
cache and synchronization intrinsics but emits a call relocation for
`__icbi`, so it cannot reproduce the original inline instruction sequence.
The SDK routine remains original assembly and earns no C source credit.

Further code probes in this continuation are also uncredited. Correcting the
embedded-vector offset in `fn_80066E08` to `0x30` preserved its original
exception records, but an ordinary C++ aggregate copy emitted 104 text bytes
against the original 88. Explicit and user-defined copies collapsed to 68
bytes without those records; volatile copies emitted 100 bytes with a
different load/store order. The compiler also inserts a rounding instruction
between the reciprocal-square-root and reciprocal operations. The probes are in
`scratch/planar_distance_code_20261020/`.

The input-device constructor `fn_8027696C` was probed with its two array
members, table at offset `0x1C`, console callback registration, and final
fields at `0xE0/0xE4`. A manual C++ source emitted 148 text bytes and a
placement-constructor variant 152, against 156 original bytes. Register
scheduling and the first table assignment remain different. The probes are
in `scratch/game_input_device_ctor_8027696C_20261020/`; no split or source
credit was added.

The later resource constructor `fn_801F0920` has a 96-byte private C/C++ probe
in `scratch/resource_constructor_801F0920_20261020/`. Its four actual
relocations and body match; only the final `r31` and `r0` stack-load order is
reversed. Native constructor, inline member initialization, C frontend,
compiler-version and processor variants did not close that difference.
Disabling scheduling restores the epilogue but changes twelve body words.
This remains uncredited.

The related 116-byte `fn_8024E18C` probe was rechecked with actual relocations
in `scratch/resource_finder_inline_20261020/constructor_continue/`. Declaring
the native table with its non-small-data extent preserves all four relocation
targets and leaves only the same two epilogue loads different. GC3 restores
the original epilogue but changes thirteen body words. This supersedes the
earlier unverified-relocation observation above, without adding source credit.

For `fn_800AC260`, an inline lookup helper restores the original 84-byte
extent and `bne; b` branch pair. Six instruction words still exchange the
key and offset registers. Reference getters, predicate helpers and a native
iterator form do not close the difference. The candidate and strict evidence
are in `scratch/resource_finder_inline_20261020/`.

The latest shared curve-literal closure was recovered and recompiled at
`scratch/packed_vector_bias_research_20261020/closure_v3_recompiled.cpp`.
It owns exactly 8,500 text bytes and 48 literal bytes, with twenty native
function extents and seventeen exact functions. Three functions retain 127
word differences: `801AF1A8` (31), `801AFFE4` (76), and `801B0C3C` (20).
The complete consumer audit finds no required external constant alias.
Further scalar coefficient ordering/reference tests in
`scratch/curve_derivative_scalar_20261020/` do not improve it. No part of this
combined probe is promoted until its complete ownership closure matches.
