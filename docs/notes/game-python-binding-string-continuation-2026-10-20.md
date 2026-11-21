# Python binding string continuation

Two existing matching string sources now include their adjacent original
intervals. `src/Game/python_remaining_formats_802A5980.cpp` extends through
`802A5C38`, adding the `PythonInterpreter_Z_StoreObject` and
`PythonInterpreter_Z_GetStoredObject` names. Its GC/1.3.2 `.rodata` section is
exactly 696 bytes. The two bytes formerly owned by an external padding unit
are emitted as ordinary alignment before the new strings.

`src/Game/python_format_strings_802A51E8.cpp` now spans
`802A51E8..802A543B`. It includes four original MovingAgent, CollectableAgent
and Throwable names and the nine previously accepted Throwable formats. The
compiler emits all 595 original bytes, including one and three internal
alignment bytes. The retired Throwable source is preserved in
`scratch/python_moving_throwable_strings_20261020/` for provenance. The two
unreferenced names at `lbl_802A52A4` and `lbl_802A52DC` require native
`force_active` retention.

Together the changes add 179 matched data bytes from C++ source. The measured
data denominator remains 1,030,936 bytes. No code or whole original
translation unit is claimed. Production objects have the exact allocated
bytes and no relocations; the rebuilt DOL passes its original SHA-1 check,
`ninja changes` reports no regressions, the source extent audit passes, and
all 66 repository tests pass. The earlier
[argument-format](game-python-format-strings.md) and
[additional-format](game-additional-python-format-strings.md) notes preserve
their original isolated handoff boundaries; this note records the later
native integration.
