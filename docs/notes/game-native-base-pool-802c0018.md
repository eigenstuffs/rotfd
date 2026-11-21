# Native base pool at 0x802C0018

`src/Game/native_base_pool_802C0018.cpp` owns `0x802C0018..0x802C1150`: a 4,224-byte runtime-base pool and an adjacent 184-byte method table. The pool begins with ten type/zero-adjustment pairs and a zero terminator. Fifteen identical records follow, each with eleven type/zero-adjustment pairs and a 188-byte zero tail. The C++ source represents this repeated layout with bounded structs; it does not claim the complete original translation unit or the target methods.

A private GC/1.3.2 compile emitted the exact 4,408-byte section and both original symbol offsets. Native objdiff reports 100% data and 220 `R_PPC_ADDR32` relocations on each side. The standard DOL hash passes, `ninja changes` shows no regression, generated progress/source extents pass, and all 66 tests pass.
