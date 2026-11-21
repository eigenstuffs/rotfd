# Three native neighbor method-record groups

Three preceding runtime-base-list sources now also own their adjacent original
data groups:

| Source base | Added range | Added bytes | Contents |
| --- | --- | ---: | --- |
| `0x802B54B0` | `0x802B5690..0x802B57B0` | 288 | Two method tables |
| `0x802B74E8` | `0x802B753C..0x802B7700` | 452 | Two method tables and one ten-base list |
| `0x802BCE70` | `0x802BCE90..0x802BCFB8` | 296 | Seven method tables and five two-base lists |

The source arrays retain the observed table slots, including null entries;
the runtime lists retain their type pointers and zero adjustments. They are
bounded ABI views. Referenced functions and runtime type descriptors retain
their existing owners, and the rest of each original translation unit remains
outside these partial source splits.

Isolated GC/1.3.2 compiles match every byte of the three enlarged `.data`
sections and preserve all old symbol extents while adding 17 original symbols.
The native objdiff reports show 100% `.data` matches with 106, 110, and 55
matching relocations respectively. Private source and object evidence is in
`scratch/native_neighbor_more_20261020/`.

The standard build retains the expected DOL SHA1. `ninja changes`, the
generated progress check, and all 66 tests pass. The integration adds 1,036
verified data bytes while keeping the original unknown-unit denominator.
