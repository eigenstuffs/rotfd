# Scene effect motion selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The two ordinary C++ sources reconstruct `fn_800C5034` and `fn_800C540C`,
340 code bytes each, with each complete eight-byte exception record and
twelve-byte exception index. Both log their borrowed operation name, invoke
the original base operation, resolve the owner Handle, set three actor motion
values, and apply mode 2. They hash the borrowed selection name and store
the resolved result of `80058778` before setting owner state `7C` to 2.

The return is a genuine four-byte nontrivial typed Handle using the native
hidden return pointer. Direct consumption through an inline `get()` preserves
the original lifetime and base destructor call with flag 0. The minimal
derived views do not claim the original template arguments or reconstruct
the callee's constructor hierarchy. Each source uses a distinct private
derived type so its unused destructor has independent native link evidence.

Each compiler object also emits an unused 76-byte destructor with twenty
exception/index bytes and four relocations. These allocations are inventoried
without credit under the existing strict weak-EH schema with no strong
overrides. Full production native discard acceptance is required. All 21
retained relocations per source and all retained allocated bytes match the
original. The complete original exception/startup tables, initialized pointer
references and source consumers are recorded in
`scratch/game_scene_effect_motion_selection/`.

Original context definitions, string pools, floating constants, base operation
and Handle routines retain their existing owners and identities. These are
partial original translation units; no data-pool ownership is transferred.

Full native production acceptance passed, including independent discard of
both private destructor and exception/index allocations.
