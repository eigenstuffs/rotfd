# MetroTRK target mutable state

`src/MetroTRK/targimpl_mutable_state.c` now owns the initialized `.data`
interval `0x802CFE20..0x802CFE50` (48 bytes). Its three source globals match
the original object, including symbol sizes and addresses:

| Global | Range | Initialization |
| --- | --- | --- |
| `gTRKRestoreFlags` | `802CFE20..802CFE29` | Nine zero bytes; TBR and DEC are the two observed fields, with seven reserved bytes inside the original symbol. |
| `gTRKExceptionStatus` | `802CFE2C..802CFE3C` | Zeroed stop information and `inTRK = 1`. |
| `gTRKStepStatus` | `802CFE3C..802CFE50` | Zeroed stepping state. |

The three bytes between the first two globals are compiler-emitted internal
alignment. The nine-byte restore flag extent is confirmed both by the target
symbol table and the preserved Pikmin 2 MetroTRK source family. The shared ABI
now declares its seven reserved bytes, with compile-time size checks for all
three records. Existing target-access, control and reset units recompile and
retain their matches.

GC/1.3.2 emits an exact 48-byte `.data` section with no relocations. The
source object matches objdiff, the linked DOL retains the expected SHA-1,
`ninja changes` reports no regressions, the source extent audit passes, and
all 66 tests pass. Overall matched data rises from 1,003,561 to 1,003,609
of 1,030,936 bytes; matched code and its denominator remain unchanged.
