# Event counter updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/event_counter_update.cpp` reconstructs three adjacent functions, `fn_80055DC0`, `fn_80055EE4`, and `fn_80056014`, covering `80055DC0..80056144` (292, 304, and 304 bytes). They resolve a generation-tagged handle at object offset `60`, construct and copy a name token, and notify the target through `fn_800A6234`. Each then updates a selected item counter, reduces the group's counters, raises its recorded peak when needed, and updates the object total. The latter two update the selected item and group peak only for positive input amounts; their object totals always receive the input amount. The three external notification strings are `PATTY_COUNT`, `JELLY_COUNT`, and `SAND_DOLLAR_COUNT`, supporting the counter names used in the source.

The selected group and item indexes are at `F0/F4`, with a group array at `138`. Groups are `94` bytes, holding count at `00`, three peak fields at `04/08/0C`, and an item pointer at `2C`. Items are `20` bytes, with the three counters at `08/0C/10`; the object's totals are `13C/140/144`. The two nested ordinary name-token temporaries preserve the native constructor and copy stack slots.

GC/1.3.2 requires the file options `-O4,s` and `-Cpp_exceptions on`. The size optimization preserves the native compact reduction loops and register save layout. The default speed optimization unrolls the reductions. These options are already supported per Object in this repository; no global flag change is required.

The complete compiler allocation is 900 bytes of `.text`, 24 bytes of `extab` at `80009EEC..80009F04`, and 36 bytes of `extabindex` at `80017FAC..80017FD0`. All allocated bytes match the original, including all three original exception descriptors and entries. There are 18 actual text relocations, six actual exception-index relocations, and three nonallocated compiler metadata relocations. No additional functions, weak helpers, literals, BSS, or padding are emitted. The referenced strings remain external original `.rodata`.

`python3 scratch/game_event_counter_update/verify.py` recompiles the production source, checks the frozen symbol and relocation inventories, resolves every retained relocation, and compares all allocated sections to the original DOL. It audits the complete original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`), proving that the three exception entries are reconstructed and no constructor or destructor ownership is omitted. The DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Central whole-DOL acceptance is pending.
