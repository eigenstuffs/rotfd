# Platform control followups

Eight independent ordinary C++ units match **600 code bytes and 17 actual relocations**. Production integration and full original-DOL acceptance are pending. The entries retain their original global C identities.

| Source | Original extent | Bytes / relocations | Behavior |
| --- | --- | ---: | --- |
| platform_callback_post_empty.cpp | 802603A0..802603E8 | 72 / 2 | Post a keyed callback with a genuine local empty Handle, then destroy that Handle. |
| platform_record_reset.cpp | 802676F4..80267734 | 64 / 1 | Clear record counters and fields, set field 20 to -1, and load the original shared float into fields 10/14. |
| platform_hierarchy_reset.cpp | 8026A63C..8026A690 | 84 / 5 | Reset both owner structures, visit the global child group, then clear two owner fields. |
| platform_six_buffer_stream.cpp | 80271980..802719CC | 76 / 2 | Read the six-handle base, then read 32 bytes into the derived buffer fields. |
| platform_motor_update.cpp | 80275F24..80275F7C | 88 / 2 | Select motor state from amplitude/activity and the owner's enable flag. |
| platform_motor_enable.cpp | 80275F7C..80275FC8 | 76 / 1 | Stop a disabled motor before storing the signed-byte enable flag. |
| platform_manager_control.cpp | 80276A08..80276A44 | 60 / 2 | Dispatch virtual slot 10 through the global manager and return one. |
| platform_buffer_close.cpp | 8028C494..8028C4E4 | 80 / 2 | Finish the open buffer, close its DVD file, and clear its state. |

The first probes and the fresh production compiles match completely with GC1.3.2 `-O4,p`, exceptions off. The native six-handle resource header is reused unchanged; `-i src/Game` permits its existing include chain. The empty Handle uses its recovered signed bitfields and normal C++ lifetime. Its destructor binds to the accepted original native destructor. It emits no constructor helper or weak backup. The remaining local types describe only fields and virtual slots used by these functions; existing consumers retain their current pointer views and declarations.

All eight compiler objects emit only their complete `.text` functions, with no data, BSS, EH, constructor/destructor entries, backups or owned padding. The shared float `lbl_8037B62C` and the global manager storage remain external and uncredited. Complete original exception-index, constructor/destructor and initialized-pointer audits preserve original table ownership. Current symbols and canonical ranges confirm these entries had no prior source ownership. Stale generated assembly contains an identical second copy of the reset function; the original report's current unit selects the preserved assembly evidence.

Two additional candidates remain private and uncredited. The 72-byte name lookup at 80262AB4 still has six physical register/scheduling differences after ordinary staged and Name-copy forms. Its earlier GM probes remain unchanged. The 80-byte controller flag query at 80275ED4 has one reversed pair of operands in a commutative addition; byte-addressed access recovers the unsigned comparison, but bounded index/helper/type variants do not close the final word. Neither appears in the integration manifest.

The immutable handoff is `scratch/engine_platform_followup_controls_20261011ir/final_integration.json`, with eight complete records, all allocation/symbol/actual-relocation inventories, original table/pointer audits, consumer declarations and a fresh strict verifier. Root owns central registration and the final original-DOL/regression acceptance.
