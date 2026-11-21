typedef unsigned long u32;
extern "C" {extern const char lbl_802B780C[];extern const float lbl_803788A8;extern u32 lbl_80377740,lbl_80377730;void fn_8002B58C();void __ct__14Agent_800703F0Fv(void*);void fn_80070474(void*,int);}
struct Agent_8002B5F4 {u32 unknown00[2];const void*vtable;char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x50];Agent_8002B5F4();~Agent_8002B5F4();};
struct First_80070378:Agent_8002B5F4 {unsigned char flag90;char unknown91[3];float value94,value98;First_80070378(){vtable=lbl_802B780C;flag90=0;value94=lbl_803788A8;value98=lbl_803788A8;}~First_80070378(){vtable=lbl_802B780C;}};
struct Second_80070378 {union {char unknown00[0xB8];double alignment;};Second_80070378(){__ct__14Agent_800703F0Fv(this);}~Second_80070378(){fn_80070474(this,-1);}};
inline void initializeFirst(){First_80070378 first;}
extern "C" void fn_80070378(){lbl_80377740=0;lbl_80377730=0;fn_8002B58C();initializeFirst();Second_80070378 second;}
