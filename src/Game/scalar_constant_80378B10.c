// Existing shared float constant; native identity and extent are preserved.
const float lbl_80378B10 = 2.0f;

/* Adjacent native token names and scalar constants; all symbol extents are retained. */
const float lbl_80378B14 __attribute__((aligned(4))) = 0.4f;
__declspec(section ".sdata2") const char lbl_80378B18[] __attribute__((aligned(4))) = "Wand07";

// Shared float constant; native GLOBAL identity, type and extent are preserved.
const float lbl_80378B20 __attribute__((aligned(8))) = 30.0f;

/* Former original data .sdata2 0x80378B24..0x80378B28, appended to the unit it follows (its section starts 8-aligned only together with this one). */
#pragma explicit_zero_data on
#pragma force_active on
__declspec(section ".sdata2") const float lbl_80378B24 = 128.0f;

#pragma force_active reset
