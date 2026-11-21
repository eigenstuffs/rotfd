# Collectable-agent method records

Three existing matching base-list sources now also own the adjacent records
at `0x802B1220..0x802B12A0`, `0x802B139C..0x802B1420`, and
`0x802B14E0..0x802B15B0`. The first two are 128-byte and 132-byte
method tables. The third contains a 136-byte method table and a 72-byte
array of six callback records. Referenced methods and type descriptors
retain their existing owners; each source remains a partial original
translation unit.

Isolated GC/1.3.2 compiles reproduce the enlarged 320-byte, 384-byte,
and 400-byte `.data` sections and all their symbol extents. Native objdiff
reports 100% with 52, 60, and 53 matching relocations respectively. The
integrations add 468 verified data bytes. The full DOL hash, `ninja changes`,
generated progress check, and all 66 tests pass. The complete original
denominator remains in the reports.
