# Nine adjacent native method-record groups

Nine existing matching runtime-base-list sources now own their immediately
following data groups. These bounded source arrays retain the original method
slots, null entries, and zero-adjustment runtime-base entries. The groups
include the named `LoadingScreen_800C0600` vtable at `0x802BEF20`.

| Added range | Bytes | Preceding source base |
| --- | ---: | --- |
| `0x802AFFCC..0x802B0158` | 396 | `0x802AFF80` |
| `0x802B66F4..0x802B67F8` | 260 | `0x802B6640` |
| `0x802BEF20..0x802BEFF0` | 208 | `0x802BEEE0` |
| `0x802C85D0..0x802C8698` | 200 | `0x802C85B0` |
| `0x802C1870..0x802C1938` | 200 | `0x802C1850` |
| `0x802B7430..0x802B74E8` | 184 | `0x802B7250` |
| `0x802B5C28..0x802B5CE0` | 184 | `0x802B5A48` |
| `0x802B53F8..0x802B54B0` | 184 | `0x802B5218` |
| `0x802B5160..0x802B5218` | 184 | `0x802B4F80` |

Isolated GC/1.3.2 compiles reproduce every enlarged section byte, preserve
all old symbol extents, and add 28 original symbols. The nine native objdiff
reports show 100% `.data` matches, with 96, 82, 55, 39, 39, 100, 99, 99,
and 99 matching relocations in table order. The private probes and reports are
retained in `scratch/native_neighbor_batch_20261020/`.

The standard build retains the expected full-DOL SHA1. `ninja changes`, the
generated progress check, and all 66 tests pass. These partial source units
add 2,000 verified data bytes. Referenced methods, runtime type descriptors,
and the rest of their original translation units remain with existing owners.
The original unknown-unit denominator remains in the reports.
