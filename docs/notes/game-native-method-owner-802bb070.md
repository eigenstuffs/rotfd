# Native owner method table at 0x802BB070

`src/Game/native_method_owner_802BB070.cpp` owns one 416-byte method table at `0x802BB070..0x802BB210`. Its first word is the runtime type pointer, followed by method targets and a secondary interface segment whose receiver adjustment is `-0x318`. The source is an ABI view of this data object; exact class signatures and the neighboring data remain outside its scope.

GC/1.3.2 emitted the original 416-byte section in a private compile. Native objdiff reports 100% data and 101 matching `R_PPC_ADDR32` relocations. The standard DOL hash passes, `ninja changes` shows no regression, the generated progress/source extents pass, and all 66 tests pass.
