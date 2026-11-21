# TeleportVolume method and jump-table records

The matching runtime-base-list source at `0x802C1288` now also owns the
adjacent `0x802C1308..0x802C1418` interval, adding 272 original data bytes.
It contains the named TeleportVolume method table, a three-word callback
record, a six-record callback array, and a seven-entry jump table targeting
interior labels of `fn_800C96E0`. The source preserves four new original
symbols and all relocation addends. Referenced methods and type descriptors
retain their existing owners; this is a partial original translation unit.

Isolated GC/1.3.2 source reproduces the full enlarged 400-byte `.data`
section and its 60 real relocations. Native objdiff reports 100% `.data` with
60 matching relocations. The standard build retains the expected full-DOL
SHA1; `ninja changes`, the progress check, and all 66 tests pass. Private
probes and reports are retained in
`scratch/native_teleport_jump_table_802C1308/`.
