# Engine member lifetime continuation

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Frozen isolated handoff: seven ordinary C++ units, seven original functions,
3,752 text bytes, zero owned data bytes and 131 real relocations. Sources are
`src/Game/engine_member_lifetime_*.cpp`; the exact handoff is
`scratch/game_engine_member_lifetime_continuation/final_integration.json`.
Each unit records its frozen source SHA-256, recursive quoted-header hash map
(empty: these sources include no headers), full compiler flags, section extent,
global symbol and address, and every dependency symbol/address/section.

| Original address | Bytes | Relocations | Recovered behavior |
| --- | ---: | ---: | --- |
| 801B252C | 432 | 19 | Resource with a pool of records containing inline curves, followed by two original array cleanup calls and resource base destruction |
| 801B27AC | 588 | 18 | Three 16-byte curve members and a 20-byte world-action curve, in reverse member order |
| 801BA7A0 | 480 | 10 | Four fixed-storage arrays and dynamic animation base chain |
| 801BB7CC | 396 | 10 | Three fixed-storage arrays and the same base chain |
| 801C426C | 720 | 28 | Three typed-handle pools, including three-handle records, four individual handles and manipulator base chain |
| 801CB130 | 536 | 20 | Two typed-handle pools, ten fixed handle objects, an opaque 128-byte record pool and resource base cleanup |
| 801CC4F0 | 600 | 26 | Scalar pool, separately owned allocation, three handles, inline child resource, handle pool and resource base chain |

## Ordinary lifetime reconstruction

The dynamic pool layout is the observed signed count, capacity, pointer triple.
Pool destruction walks the live elements, frees capacity times the observed
stride through the original allocator, and clears the pointer twice where the
original generic container does so. Empty inline element destructors reproduce
the original unrolled counted loops without assembly or inserted instructions.

801B27AC retains its original external name because accepted
`engine_loop_801B26DC.c` already calls it. The curve members inherit the original
four-byte `CurveBase_801B1088` and contain a 20-byte-element pool at member +4.
The last world-action curve uses its original native external destructor. The
80-byte complete record extent agrees with its accepted caller's element stride.
801B252C uses the same base with a 16-byte-element pool in each 28-byte record.

The fixed-storage containers use opaque byte storage with explicit live-element
destruction; they do not declare all capacity slots as live C++ array objects.
Declaring a nontrivial `T data[N]` emitted an additional `__destroy_arr` capacity
cleanup absent from the original. Nearby code establishes the first family's
strides/capacities as 104x16, 4x16, 44x8 and 24x8. The second family uses 148x16,
24x8 and 44x8, with an additional word at offset 968. Supporting original
instructions include 801BAAFC/801BAC64 (104 stride), 801BAFA8 (44 stride),
801BB094 (24 stride), 801BB9E8 (24 stride), 801BC524 (148 stride and sixteen-entry
capacity), and accepted `engine_leaf_801BBAF4.c` (44 stride and eight-entry capacity).
The inherited animation base preserves its observed vtable updates before the
original external `ObjectsOwner_80213D44` destructor.

Empty typed handle inheritance levels reproduce the observed nested destructor
null tests and the base native call with release zero. This is especially visible
in 801C426C's member at +4C (four levels), its 28-byte pool records (three handles
at +10/+14/+18), and its two four-byte-element pools of different handle types.
801CC4F0 retains the existing external name because accepted
`base_destructor_8026c10c.cpp` already calls it.

801CB130 preserves the original runtime array cleanup operation explicitly:
`__destroy_arr` receives the original external `Handle_80020B90` destructor,
four-byte stride and ten entries. No new helper function or destructor is emitted.
Its two dynamic handle pools have different inherited lifetime depths, as shown
by their original one- and two-test element destruction paths.

## Compiler and symbol integration

All units use GC/1.3.2 and the repository's ordinary `-O4,p` flags with C++
exceptions off. Only 801B252C and 801C426C require `-use_lmw_stmw on`.
All seven production sources were recompiled after private-type naming and
formatting; the strict verifier accepts exactly one global function per object,
exact `.text` extent and bytes with all real relocations applied. No weak or extra
helper functions and no unexpected allocated sections are emitted.

Three previously unreferenced original names are proposed as compiler-native
C++ definitions at the same addresses:

- `fn_801BA7A0` -> `__dt__18FixedAnim_801BA7A0Fv`
- `fn_801BB7CC` -> `__dt__18FixedAnim_801BB7CCFv`
- `fn_801C426C` -> `__dt__19HandleDraw_801C426CFv`

The manifest records each original name in `original_symbol` and publishes every
real dependency. The ownership audit found no accepted source caller for these
three original names. No aliases, thunks or shared metadata edits are part of the
handoff. The integrator must validate and publish these native names, update
existing assembly/data references to their unchanged addresses, and run the full
original DOL hash and match regression checks before accepting source credit.

## Original ownership audit

`ownership_audit.json` records the true original function extents and every
section of their current original split units. Those original units contain only
text; the other functions in their larger units remain outside these partial
splits. No target has an original `.extabindex` record or `.ctors` reference,
checked against all original 12-byte exception index records and the full startup
constructor table. Referenced vtables, constants, allocator globals, external
member/base destructors and remaining text retain their existing ownership.
`final_splits.txt` and `final_config.txt` provide exact proposed integration edits.
No full link or shared metadata mutation was performed by this agent.
