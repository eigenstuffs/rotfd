# Native state tables at 0x802B95B8

`src/Game/native_state_tables_802B95B8.cpp` owns the original
`0x802B95B8..0x802B9710` data interval. It reconstructs eight seven-word
state method tables and six five-word two-base runtime lists, preserving all
14 original symbols and their order. Referenced methods and neighboring data
retain their existing owners.

A private GC/1.3.2 compile placed every symbol at its original offset. Native
objdiff reports 100% for all 344 data bytes and all 60 original
`R_PPC_ADDR32` relocations. The full DOL retains its expected SHA-1; `ninja
changes`, generated progress, and all 66 tests pass.
