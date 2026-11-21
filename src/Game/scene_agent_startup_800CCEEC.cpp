typedef unsigned long u32;
extern "C" {extern const char lbl_802C1DC4[];extern u32 lbl_80377888;void fn_8002B58C();}
struct Agent_8002B5F4 {u32 unknown00[2];const void*vtable;char unknown0C[0x84-0xC];Agent_8002B5F4();~Agent_8002B5F4();};
struct SceneStartupAgent:Agent_8002B5F4 {char tail84[0xC];SceneStartupAgent(){vtable=lbl_802C1DC4;}~SceneStartupAgent(){vtable=lbl_802C1DC4;}};
extern "C" void fn_800CCEEC(){lbl_80377888=0;fn_8002B58C();SceneStartupAgent agent;}
