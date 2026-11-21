typedef unsigned long u32;
extern "C" {extern const char lbl_802B780C[];extern const float lbl_803788A8;extern u32 lbl_80377738,lbl_80377730;void fn_8002B58C();void fn_8006FCB8(void*);void fn_8006FD14(void*,int);}
struct Agent_8002B5F4 {u32 unknown00[2];const void*vtable;char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x50];Agent_8002B5F4();~Agent_8002B5F4();};
struct First_8006FC40:Agent_8002B5F4 {unsigned char flag90;char unknown91[3];float value94,value98;First_8006FC40(){vtable=lbl_802B780C;flag90=0;value94=lbl_803788A8;value98=lbl_803788A8;}~First_8006FC40(){vtable=lbl_802B780C;}};
struct Second_8006FC40 {union {char unknown00[0xA0];double alignment;};Second_8006FC40(){fn_8006FCB8(this);}~Second_8006FC40(){fn_8006FD14(this,-1);}};
inline void initializeFirst(){First_8006FC40 first;}
extern "C" void fn_8006FC40(){lbl_80377738=0;lbl_80377730=0;fn_8002B58C();initializeFirst();Second_8006FC40 second;}
