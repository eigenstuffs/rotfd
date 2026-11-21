typedef unsigned long u32;
extern "C" {extern const char lbl_802B5F74[];extern const float lbl_803788A8;extern u32 lbl_803776FC,lbl_803776F8;void fn_8002B58C();void fn_80061470(void*);void fn_800614C0(void*,int);}
struct Agent_8002B5F4 {u32 unknown00[2];const void*vtable;char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x50];Agent_8002B5F4();~Agent_8002B5F4();};
struct First_80061404:Agent_8002B5F4 {int value90;First_80061404(){vtable=lbl_802B5F74;value90=-1;}~First_80061404(){vtable=lbl_802B5F74;}};
struct Second_80061404 {union {char unknown00[0x98];double alignment;};Second_80061404(){fn_80061470(this);}~Second_80061404(){fn_800614C0(this,-1);}};
inline void initializeFirst(){First_80061404 first;}
extern "C" void fn_80061404(){lbl_803776FC=0;lbl_803776F8=0;fn_8002B58C();initializeFirst();Second_80061404 second;}
