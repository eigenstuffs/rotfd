# Actor transform curve application

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two independent ordinary source units reconstruct716 text bytes: fn801AED04..801AEE70364 bytes initializes sampled actor transforms and marks the actor dirty; fn801AEE70..801AEFD0352 bytes updates cached signed-short indices while sampling animated tracks. Position/scale vector fields are B8/D8 and quaternion rotation C8. The owner exposes four16-byte curves beginning C, with count@4 in each partial curve view.

Both first probes match using one shared function-scope Vector output and one Quaternion output. Native temporary storage is Vector18 and Quaternion8. The first routine samples any populated transform with index1 and calls the action track with index0, then existing fn8023D648. The second samples transform curves with count>1 and updates caller indices, while any populated action curve forwards all three float inputs and two pointer arguments.

GC1.3.2 Gekko/O4,p production objects and fresh unchanged-core strict recompiles match all716 allocated bytes and9 actual relocations (5/4). No compiler helpers, data, literal pools, BSS, padding, EH or startup sections are allocated. Current native-name/all1,673-canonical overlap/43,737-source body preflight passes. Stable5,583-object/119,086-actual-relocation/777,360-word audit verifies all config/object hashes unchanged throughout, finds four original entry references/direct callers, and no aliases/initialized data pointers. Full original table ownership audits find no owned entries. Original C spellings and all existing callers remain unchanged.

Evidence scratch/game_actor_transform_curve_apply_801aed04; frozen handoff scratch/game_engine_batch248. Central/native acceptance pending.
