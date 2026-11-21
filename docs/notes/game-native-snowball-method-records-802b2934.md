# Snowball method tables and callback records at 0x802B2934

`src/Game/native_rtti_base_lists_802B28F0.cpp` now includes the original
`0x802B2934..0x802B2AB8` data that follows its already matching 68-byte
Snowball runtime-base list. The recovered interval contains the 156-byte
Snowball method table, a related 160-byte projectile table and six repeated
three-word callback member records (72 bytes). Their pointer targets remain
with their existing code and runtime-type owners. The callback dispatcher at
`0x8003D944` continues to reference the original `lbl_802B2A70` address.

The source's `.data` section is 456 bytes with all four original symbol
offsets. Native objdiff reports 100% for every symbol, byte and all 84
relocations; 76 relocations belong to the newly sourced tables. The standard
DOL hash, `ninja changes`, generated progress check and all 66 tests pass.
This adds 388 verified data bytes while retaining the complete original data
denominator. The adjacent `0x802B2AD4` runtime record is now also sourced in
the callback-dispatch unit described below.
