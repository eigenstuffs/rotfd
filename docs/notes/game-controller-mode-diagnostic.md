# Controller mode diagnostic

`src/Game/controller_mode_diagnostic_800B6C84.cpp` reconstructs the native
`800B6C84..800B6DA8` routine with ordinary C++. The isolated source matches all
292 code bytes, its compiler-generated 36-byte LOCAL switch table at
`802BD8B0..802BD8D4`, eight exception-table bytes at `80011A2C`, and twelve
exception-index bytes at `8001C128`, after all 27 actual relocations. The native full-game build now links this unit from Matching source.

The function writes a mode to the indexed controller slot, formats one of nine
descriptions into a 64-byte local buffer, and logs that description. A local
`const char*` borrowing the existing format pool before the mode store preserves
the native retained pool base in r31. Direct external array/aggregate expressions
had repeatedly materialized the pool in every switch arm and emitted 356 bytes.
No format strings or shared pool bytes move into this partial source split.

Use GC1.3.2 with `-proc 750 -fp hardware -enum int -str reuse -common off -O4,s
-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on`. The only normal
allocated sections are `.text`292, `.data`36 with natural alignment8, `extab`8,
and `extabindex`12. There are no additional helpers, literals, BSS, constructors,
destructors, weak bodies or padding. Keep the original GLOBAL function identity,
extent and ABI, and retain the switch table's LOCAL binding.

Frozen evidence and the read-only audit script are under
`scratch/game_frontier_20261012_b/controller_mode_diagnostic_800B6C84.*` and
`audit_controller_mode_diagnostic.py`. The audit checked 3,109,410 original
byte-offset pointer positions, including unaligned positions in every initialized
segment, all direct branches and plausible absolute code materializations, the
complete exception index and startup tables, and 133,509 actual relocations in
6,204 active inputs. It recorded eleven initialized pointers into owned ranges:
nine switch targets and the two exception-index pointers. External code targets
only the preserved function entry. Central inputs and every active object stayed
unchanged during the census.

The preceding `Object_800B4F28` vtable, the following LOCAL switch table at
`802BD8D4`, its `800B7214` getter, intervening handle routines beginning at
`800B6DA8`, and the complete shared GLOBAL `lbl_802A0550` format pool remain
outside this partial split. This result does not resolve the getter's separate
alignment/ownership investigation. The earlier private direct-pool candidates
remain preserved as research.

Production acceptance passes the unchanged original DOL hash, immutable baseline
regression check, complete original section coverage, native allocation and
relocation proofs, source extents and all 66 tests. Logs are
`scratch/continuation_20261012_b/build-controller-mode-promote.log` and
`changes-controller-mode-promote.log`. The original prefix and full neighboring
data tail are explicit align-1 original splits; no neighbor padding is credited.
