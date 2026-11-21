# Resource motion-event dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801BE188` owns text `801BE188..801BE46C` (740 bytes). The ordinary C++ source forwards three virtual event-mask queries and their actions, resolves a returned related Handle, snapshots position, copies a selected Handle, then either applies flags and clears two target bindings or restores position.

Production is `src/Game/resource_motion_event_dispatch_801BE188.cpp`, GC 1.3.2 with `-proc gekko -O4,p -Cpp_exceptions off -use_lmw_stmw on` plus common manifest flags. Production and independent fresh compilation match the complete retained bytes and 14 actual relocations. No data/BSS/EH/startup/padding or native identifier migration is owned.

The existing C entry `fn_801BE46C` is declared as returning a genuine derived Handle value: its already accepted body constructs the native `Handle_801F7F10`, writes two zero layers, copies a word and retains it. The private returned type's inline destructor naturally invokes the native base cleanup with parameter0, matching the original; a direct base-return declaration instead emitted-1. The original six argument register positions, signed-byte virtual results, selected Handle const reference, copied one-zero-layer Handle and two three-zero-layer empty temporaries all follow ordinary lifetime rules.

Four unique unused private destructor backups total352 bytes (92,88,88,84) and eight actual relocations. The strict manifest accounts for all of them and no retained relocation references any backup. Real isolated MWLD discards all4, with a negative fixture check. They receive no code credit and must remain absent in both central native ELF variants.

A stable complete original census scanned5,638 objects,119,086 actual relocations and777,360 initialized words. Exactly one original GLOBAL740-byte definition remains; one original direct call and eight borrowed vtable entries reference it. The eight table allocations preserve their original ownership and identities. There are no aliases, overlapping text owners, existing compiled source consumers or migrations. Full original extabindex including terminal range80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 contain no primary ownership.

Frozen evidence is under `scratch/game_resource_motion_event_dispatch_801be188/`, listed by `scratch/game_engine_batch275/manifest-list.json`. Final original-DOL hash, baseline, native placement/discard and progress acceptance remain central requirements.
