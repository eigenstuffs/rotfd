# Native hook method records

The matching runtime base lists at `0x802B03D0..0x802B0510` and
`0x802B05C0..0x802B05E0` now own their adjacent records. The first adds
the 176-byte method table at `0x802B0510`; the second adds three 28-byte
method records and an interleaved 20-byte two-base list at
`0x802B05E0..0x802B0648`. Referenced methods and type descriptors retain
their existing owners. The two source files remain partial original
translation units.

Isolated GC/1.3.2 compiles reproduce the enlarged 496-byte and 136-byte
`.data` sections, all new symbol extents, and their 78 and 23 relocations.
Native objdiff reports 100% for both. The integrations add 280 verified
data bytes. The full DOL hash, `ninja changes`, generated progress check,
and all 66 tests pass; the original denominator remains complete.
