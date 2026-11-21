# Early actor scene controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six isolated ordinary C++ functions reproduce 868 original text bytes and
120 bytes of owned exception metadata with GC 1.3.2, `-O4,s`, exceptions on.
Central original-DOL linking remains required before matching credit.

| Function | Text bytes | extab | extabindex | Real retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80089B1C | 88 | 8000E288..8000E290 | 8001A358..8001A364 | 4 |
| fn_8008BED8 | 180 | 8000E4A4..8000E4AC | 8001A4E4..8001A4F0 | 12 |
| fn_8008C2DC | 120 | 8000E558..8000E560 | 8001A508..8001A514 | 4 |
| fn_8008C3C0 | 180 | 8000E568..8000E570 | 8001A520..8001A52C | 12 |
| fn_8008C754 | 120 | 8000E5F4..8000E5FC | 8001A538..8001A544 | 4 |
| fn_8008C838 | 180 | 8000E604..8000E60C | 8001A550..8001A55C | 12 |

The first function stops and clears the two effect pointers at owner offsets
40 and 44. BED8, C3C0, and C838 obtain the scene's target and either dispatch
controller event 7D with the controller itself, or store the target at actor
42C, dispatch their respective 20/98/2A event, then dispatch A8 with the target.
A present monitor with its first record enabled receives the actor's record
pointer at 320. C2DC and C754 notify the monitor's second record and clear bit
80000000 of the actor's 64-bit flags at 30. The source retains the actual
64-bit mask operation, including the original high-word store.

`include/Game/early_actor_scene_control_views.h` has exactly the six production
consumers listed by this handoff. Its unused inline Handle definitions do not
emit weak functions or data in any of these objects. All objects contain only
one global text function and its actual compiler-local extab/index objects.
There is no owned literal, initialized data, BSS, constructor/destructor-table
entry, padding, alias, identifier migration, or discarded allocated section.
The external float at 80378AE0 and context/monitor globals remain borrowed.

Each verifier recompiles the production source, pins source/header hashes,
accounts for every allocated symbol and section, applies every actual PowerPC
relocation including SDA base selection, and compares the complete relocated
bytes to the supported original DOL. The ownership audit scans extabindex
80015F60..8001F2C0, ctors 80299920..80299980, and dtors 80299980..802999A0.
Each source owns exactly its single original exception entry and no startup
entry. No shared metadata or global build was changed by this handoff.

A separate preserved ordinary probe for fn_80088FF4 has the correct 236-byte
extent and all real text relocations, but eight instructions still exchange
saved self/context registers. A local service result fixes the three additional
flag-assignment scheduling differences. Bool/char field types, pointer/reference
views, condition forms, local context/monitor variables, extra unused argument,
and a genuine member-function form do not close the remaining allocation.
The -O4,p form grows to 244 bytes. This near match receives no credit and is
not part of the production handoff; all probes are preserved unchanged under
`scratch/game_early_actor_scene_controls`.
