// Native menu keywords, resource names, input contexts and diagnostic messages.
// The named NUL-separated pools retain their original external char-array ABI.

extern "C" const char lbl_802A0400[] =
    "WORLD_BB\0\0\0\0" // +0x0
    "WORLD_JF\0\0\0\0" // +0xC
    "WORLD_CA\0\0\0\0" // +0x18
    "WORLD_DN\0\0\0\0" // +0x24
    "WORLD_GL\0\0\0\0" // +0x30
    "WORLD_DG\0\0\0\0" // +0x3C
    "WORLD_TD\0\0\0\0" // +0x48
    "WORLD_TEST\0"; // +0x54

extern "C" const char lbl_802A0460[] =
    "Unknown task\0\0\0\0" // +0x0
    "TASK_ICON_1\0" // +0x10
    "TASK_ICON_2\0" // +0x1C
    "TASK_ICON_3\0" // +0x28
    "TASK_ICON_4\0" // +0x34
    "TASK_ICON_5\0" // +0x40
    "TASK_ICON_6\0" // +0x4C
    "GUI_TASK_ACTION\0" // +0x58
    "GUI_TASK_NOCHECK\0\0\0\0" // +0x68
    "GUI_TASK_CHECK\0"; // +0x7C

extern "C" const char lbl_802A04EC[] =
    "PAUSE_VIBRATION"; // +0x0

extern "C" const char lbl_802A04FC[] =
    "OptionsMenuMove"; // +0x0

extern "C" const char lbl_802A050C[] =
    "BaseObject_Z"; // +0x0


// Adjacent complete native strings preserve their original external identities.
#pragma force_active on
extern "C" const char lbl_802A051C[] = "Activable_Z";
extern "C" const char lbl_802A0528[] = "Manipulator_Z";
extern "C" const char lbl_802A0538[] = "ManipulatorDraw_Z";
#pragma force_active reset
