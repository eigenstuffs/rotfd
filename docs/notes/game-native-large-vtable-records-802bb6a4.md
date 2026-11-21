# Five larger native table groups

Five existing matching runtime-base-list sources now own their immediately
following original data groups:

| Added range | Bytes | Preceding source base |
| --- | ---: | --- |
| `0x802BB6A4..0x802BB850` | 428 | `0x802BB598` |
| `0x802B170C..0x802B1808` | 252 | `0x802B15D8` |
| `0x802C9024..0x802C9108` | 228 | `0x802C8F98` |
| `0x802B1C74..0x802B1D50` | 220 | `0x802B1C38` |
| `0x802B1884..0x802B1960` | 220 | `0x802B1830` |

The `0x802BB6A4` table includes the observed `-0x318` secondary-base
adjustment as a literal pointer-sized word. These are bounded ABI views of
method slots and runtime-base entries; they do not assert full class
declarations. Referenced methods and type descriptors retain their existing
owners, and the rest of each original translation unit remains outside these
partial splits.

Isolated GC/1.3.2 compiles reproduce every enlarged `.data` byte, preserve
all old symbol extents, and add the original new-symbol extents. All five
native objdiff reports show 100% `.data` matches with 351 matching relocations
across the enlarged units. Private probes and reports are retained in
`scratch/native_large_vtable_802BB6A4/`.

The integration adds 1,348 verified data bytes. The standard build retains
the expected full-DOL SHA1; `ninja changes`, the generated progress check,
and all 66 tests pass. The unknown-unit denominator is preserved.
