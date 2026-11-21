# Console argument layout

The pointer at `lbl_801E9D24 + 0x110` is the console. Its command parser and accepted console controls establish these argument fields; the former `Engine`/`state`/`active` and random-settings labels described the same storage provisionally.

| Console offset | Field | Meaning |
| --- | --- | --- |
| `0x860` | `int argc` | Token count including the command at index zero |
| `0x864` | `char* argv[16]` | Command and argument strings |
| `0x8A4` | `signed char numeric[16]` | Whether each token has a parsed numeric value |
| `0x8B4` | `float values[16]` | Parsed values at the corresponding token indices |

For user argument N, `argv[N]` is at `0x864 + 4*N`, its numeric flag at `0x8A4 + N`, and its value at `0x8B4 + 4*N`. Thus argument one uses `0x868`/`0x8A5`/`0x8B8`; argument two uses `0x86C`/`0x8A6`/`0x8BC`; argument three uses `0x870`/`0x8A7`/`0x8C0`; argument four uses `0x874`/`0x8A8`/`0x8C4`. The private views use `ConsoleArguments`, `console`, `argc`, `argN`, `argNIsNumeric` and `argNValue` where those fields are needed.

The parser in [logger_parser.cpp](../../src/Game/logger_parser.cpp) sets a numeric flag for successful number parsing and for boolean aliases. `TRUE`/`On` produce a valid value of one; `FALSE`/`Off` produce a valid value of zero. The flag records parse validity, not argument truth. When neither a number nor a boolean alias is accepted, the parser clears the flag without assigning a new numeric value. [console_controls.cpp](../../src/Game/console_controls.cpp) independently demonstrates the distinction by testing the flag before comparing the value with zero.

Original guards remain unchanged. In particular, `PlayerGotoCoord` rejects its coordinate arguments only when all three numeric flags are false; `SetPersoCamera` checks the argument count without checking the numeric flag; `ResetCameraZone` retains index zero unless both its optional argument checks pass; and the seed command retains its original `argc >= 1` condition. The original hierarchy registration in [hierarchy_command_registration.cpp](../../src/Game/hierarchy_command_registration.cpp) establishes the displayed command names and help strings.

[scratch/console_argument_names/verification.json](../../scratch/console_argument_names/verification.json) records the refinement across 16 accepted sources and six private headers. All 16 complete before/after compiled objects have identical SHA-256 hashes; the stored object pairs were also directly compared. The full build subsequently passed the protected original-DOL hash, direct whole-file comparison, native objdiff and source-section extent checks. This naming correction changes no compiled bytes, source credit or data ownership. Earlier isolated results, near-match status and padding-accounting history in individual unit notes remain preserved.
