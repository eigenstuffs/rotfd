# Callback dispatch runtime bases at 0x802B2AD4 and 0x802B2EAC

`src/Game/engine_callback_dispatch_family_8003D944.cpp` emits an original
28-byte compiler switch table in `.data`. The twelve-byte runtime-base list
at `0x802B2AD4` follows that table at its original four-byte offset within
an eight-byte aligned section. The list has one pointer to the BaseObject_Z
runtime type, zero adjustment and a zero terminator.

The extended source compiles to the original 616 text bytes, exception data,
40 data bytes and all relocations. Native objdiff reports 100% for each owned
section. The standard DOL hash, `ninja changes`, generated progress check
and all 66 tests pass. This adds 12 verified data bytes; the original
switch-table allocation and complete data denominator remain intact.

The analogous dispatch variant in
`src/Game/engine_callback_dispatch_variant_80043648.cpp` now owns the
one-base record at `0x802B2EAC`, directly after its 28-byte compiler switch
table. Its pointer selects the second BaseObject_Z runtime type
`lbl_80374208`. Native objdiff reports 100% for the original 668 text bytes,
exception/index records and 40 data bytes, with all eight data relocations.
The DOL hash, `ninja changes`, progress check and all 66 tests pass. This
adds another 12 verified data bytes without changing the denominator.
