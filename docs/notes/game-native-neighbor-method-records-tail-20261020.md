# Twenty-one adjacent native method-record groups

Twenty-one existing matching `native_rtti_base_lists_*.cpp` sources now own
their immediately following original data groups. The groups begin at
`0x802B4CC4`, `0x802B4ECC`, `0x802B7A14`, `0x802B7E38`, `0x802B7EF8`,
`0x802B83EC`, `0x802B9264`, `0x802BC988`, `0x802BD800`, `0x802BDB24`,
`0x802BDBEC`, `0x802BDCB4`, `0x802BDD7C`, `0x802BF91C`, `0x802BFA00`,
`0x802BFB7C`, `0x802BFCFC`, `0x802C171C`, `0x802C1DC4`, `0x802C8530`,
and `0x802C9144`. They add 2,996 data bytes in total. The source retains
observed method slots, null entries, and zero-adjustment runtime-base lists
as bounded ABI views.

Isolated GC/1.3.2 compiles reproduce every enlarged `.data` section byte and
all new original symbol extents, while preserving the old symbol sets. All 21
native objdiff reports show 100% `.data` matches and 1,085 matching
relocations across the enlarged units. Private probes and reports are retained
in `scratch/native_neighbor_tail_20261020/`.

The standard build retains the expected full-DOL SHA1. `ninja changes`, the
generated progress check, and all 66 tests pass. Referenced methods and type
descriptors retain their existing owners; these source ranges remain partial
original translation units. The original unknown-unit denominator remains in
the report.
