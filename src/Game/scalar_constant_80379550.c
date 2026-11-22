// Shared float constant; native GLOBAL identity, type and extent are preserved.

/* Adjacent native token names and scalar constants; all symbol extents are retained. */
__declspec(section ".sdata2") const char lbl_80379560[] __attribute__((aligned(4))) = "MSG_YES";
__declspec(section ".sdata2") const char lbl_80379568[] __attribute__((aligned(4))) = "MSG_OK";

// Shared float constant; native GLOBAL identity, type and extent are preserved.
const float lbl_80379570 __attribute__((aligned(8))) = 2.0f;

/* Former original data .sdata2 0x80379574..0x80379578, appended to the unit it follows (its section starts 8-aligned only together with this one). */
#pragma explicit_zero_data on
#pragma force_active on
__declspec(section ".sdata2") const float lbl_80379574 = 50.0f;

#pragma force_active reset
