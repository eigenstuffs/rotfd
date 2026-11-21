# World reference callbacks

`src/Game/world_reference_callbacks.cpp` owns `801E8B10..801E8E2C`:
248 bytes of registry notification and 548 bytes of reference traversal.
Both routines match exactly; this partial split owns no data or tables.

The first callback creates two retained copies of the Root identity and
passes them to slots `3C` and `40` of the registry at globals offset `124`.
Each temporary is destroyed using the native handle lifetime path.

The second marks the dynamic handle arrays at `C`, `24` and `18`, the
handle at `30`, and three index structures at `34`, `4078` and `80BC`.
It then visits two eight-handle fixed-capacity arrays at `C110` and `C140`,
with the dynamic array at `C134` between them, and the handles at `C164`
and `C168`. A valid final handle is passed to the manager at globals
`14C`; a retained Root identity is passed to the manager at `11C`.

The fixed-capacity arrays use signed counts and unsigned element indexing.
Recovering that container boundary reproduces the original induction
variables and loop increments. The partial world view ends at `C16C`;
compile-time size checks cover it, the fixed array, and the registry view.
Names describe observed behavior rather than recovered original types.

Strict production verification compares all 796 retained bytes after 34
actual relocations. The object emits two unreferenced weak destructors,
172 bytes in total, which are absent from the final ELF and excluded from
credit. The adjacent 3,064-byte loader at `801E8E2C` remains original.

Evidence: `scratch/game_world_reference_callbacks/verify.py`,
`scratch/world_reference_callbacks_link_proof.json`, and
`scratch/world_reference_callbacks_checkpoint.json`. All 665 source units
remain exact, the DOL is byte-identical, and all 23 tests and progress,
extent and assembly audits pass. The original baseline is unchanged;
existing fallback/native-padding accounting warnings remain documented
without source regressions.
