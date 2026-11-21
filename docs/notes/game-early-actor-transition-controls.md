# Early actor transition controls

Six isolated ordinary C++ routines recover 1,304 text bytes and 120 bytes of exception metadata/index. Production sources are `src/Game/early_actor_transition_control_<address>.cpp`, with a dedicated `early_actor_transition_control_views.h` header. Central registration and complete DOL acceptance remain with the integrator.

| Address | Text bytes | Behavior | Required flags beyond common Game configuration |
| --- | ---: | --- | --- |
| 800A1554 | 172 | Resolve actor behavior, start its selected controller state when the signed byte flag equals one, then update the base owner | `-O4,s -Cpp_exceptions on -proc 750` |
| 800A1678 | 168 | Resolve behavior and select its state-zero operation or the base update | `-O4,s -Cpp_exceptions on -proc 750` |
| 800A3628 | 168 | Perform actor reset and start controller state zero when the resolved resource lacks flag bit 39 | `-O4,s -Cpp_exceptions on` |
| 800AAA1C | 192 | Save velocity, clear it to the original external zero vector, activate state five when a signed-short scene count is positive, then update the controller | `-O4,s -Cpp_exceptions on` |
| 800BEC04 | 188 | Temporarily begin an inactive window, apply the scene service, submit its output, and end it when the saved signed byte is nonzero | `-O4,s -Cpp_exceptions on` |
| 80094110 | 416 | Select controller transitions from active state predicates and update actor flags/activity | `-O4,s -Cpp_exceptions on` |

The signed byte behavior field produces the original signed equality comparison without an unnecessary sign-extension. For the window, its ordinary inline getter preserves the native temporary capture and saved-register copy. Both 750-target routines save FPR31 using the original double save format; the Gekko target introduces paired-single save/restore operations absent from the original. This compiler setting also reproduces each eight-byte exception entry.

All six production objects pass strict complete allocated-section comparison, all actual relocations, precise ELF local exception names and extents, and full original extabindex (`80015F60..8001F2C0`), constructor (`80299920..80299980`), and destructor (`80299980..802999A0`) ownership scans. The objects contain only their function, eight-byte exception entry and twelve-byte index; 54 actual retained relocations and six nonallocated compiler metadata relocations are accounted for. No weak helpers, owned literal/data/BSS, padding, native identity migrations, or aliases are introduced. The original context, zero vector and callees retain their existing global identities.

Evidence and frozen hashes are listed in `scratch/game_engine_batch135/`. Private source/type probes remain preserved under `scratch/game_early_actor_transition_controls/`.
