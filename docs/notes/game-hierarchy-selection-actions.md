# Hierarchy selection actions

`hierarchy_selection_default.cpp` recovers `fn_802043FC` at
`0x802043FC..0x80204580` (388 bytes). `hierarchy_selection_command.cpp` recovers
`fn_80204580` at `0x80204580..0x80204734` (436 bytes). These are separate retained
text fragments; the original translation-unit boundary remains unproven.

The first method is registered as `ResetCameraZone` and starts with index zero.
Only when console `argc == 2` and `numeric[1]` at `0x8A5` is nonzero does it
replace that default with integer-converted `values[1]` at `0x8B8`. Other
argument counts or failed numeric parsing retain index zero. It initializes
three typed handles and asks the group manager for the corresponding entries.
A valid target receives virtual call `0x38`; an invalid target returns false.
The second method, `EndCameraCapture`, requires `argc == 2` and `numeric[1]`,
then rejects an index greater than or equal to the game's signed count byte at
`0x214`. Its valid target receives virtual call `0x80` with command 70 and the
external float at `0x8037A928`. Argument counts include the command token; the
numeric byte means parse validity, including valid zero-valued boolean aliases,
as described in [console argument layout](console-argument-layout.md).

The default constructors reveal five, two and three inherited zeroing layers.
The private `hierarchy_selection_actions_internal.h` models these layers and
the observed four-byte handle size. Ordinary C++ scope cleanup reproduces every
native destructor call, including all early-return paths. No new validation or
changed selection bounds were introduced.

`scratch/game_hierarchy_selection_actions/verify.py` compiles both production
files with GC/1.3.2, `-O4,p -inline auto -Cpp_exceptions off`, and the established
Gekko flags. It resolves all 35 retained relocations and verifies all 824 code
bytes. Each object also emits six unreferenced weak wrapper destructors totaling
564 bytes with 12 relocations. Their extents, weak binding and lack of retained
references are checked; normal linker dead stripping excludes them from credit.
There is no owned data, BSS, exception metadata or trailing padding.

Both units pass the full original-DOL hash, direct byte comparison, native
objdiff and source-section extent guard. Acceptance manifests are
`game_hierarchy_selection_default.json` and
`game_hierarchy_selection_command.json` under `config/GSQE78/candidates/`.
