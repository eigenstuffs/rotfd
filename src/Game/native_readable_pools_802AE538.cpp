// Native resource paths, parser tokens, type names and diagnostic text.
// Complete external NUL-separated arrays retain their original storage ABI.

extern "C" const char lbl_802AE538[] =
    "InGameCameraNode"; // +0x0

// Camera diagnostics formerly held in an adjacent original-only span.
#pragma force_active on

extern "C" const char lbl_802AE54C[] = "InGameCamera";

extern "C" const char lbl_802AE560[] __attribute__((aligned(8))) = "* InGame overflows -> moved at up/left\n"; // +0x15C

#pragma force_active reset
