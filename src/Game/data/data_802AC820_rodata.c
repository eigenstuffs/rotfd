/* Original .rodata 0x802AC820..0x802AC8D0: 0xB0 zero bytes that no code or
   data relocation references (DTK names them pad_06_802AC820_rodata). They
   are not alignment fill: the block starts 32-aligned and the next unit
   starts at 0x802AC8D0, so they are an unreferenced zero-initialised object
   of unknown type, reproduced byte-identically here. */
#pragma explicit_zero_data on
#pragma force_active on
__declspec(section ".rodata") const unsigned char lbl_802AC820[0xB0] = { 0 };
#pragma force_active reset
