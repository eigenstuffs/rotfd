#ifndef GAME_EARLY_CALLBACK_FACTORY_GROUP_VIEWS_H
#define GAME_EARLY_CALLBACK_FACTORY_GROUP_VIEWS_H
struct EarlyFactoryCallback{char unknown00[12];};
struct EarlyFactoryController3{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0x44];};
struct EarlyFactoryAgent3{char unknown00[0x168];EarlyFactoryController3 controller;EarlyFactoryCallback**callbacks;};
struct EarlyFactoryController2{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0x2C];};
struct EarlyFactoryAgent2{char unknown00[0x168];EarlyFactoryController2 controller;EarlyFactoryCallback**callbacks;};
struct EarlyFactoryController4{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0xCC];};
struct EarlyFactoryAgent4{char unknown00[0x318];EarlyFactoryController4 controller;EarlyFactoryCallback**callbacks;};
extern "C" {
extern unsigned char lbl_801EF5C8[];
void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void fn_8007D8EC(void*,EarlyFactoryCallback**);
extern const char lbl_8029CB88[],lbl_8029CB98[];
EarlyFactoryCallback*fn_80074468(EarlyFactoryCallback*,EarlyFactoryAgent3*);
EarlyFactoryCallback*fn_80074638(EarlyFactoryCallback*,EarlyFactoryAgent3*);
EarlyFactoryCallback*fn_800747D0(EarlyFactoryCallback*,EarlyFactoryAgent3*);
extern const char lbl_8029CC50[],lbl_8029CC60[];
EarlyFactoryCallback*fn_80075044(EarlyFactoryCallback*,EarlyFactoryAgent2*);
EarlyFactoryCallback*fn_80075124(EarlyFactoryCallback*,EarlyFactoryAgent2*);
extern const char lbl_8029D558[],lbl_8029D568[];
EarlyFactoryCallback*fn_800801F0(EarlyFactoryCallback*,EarlyFactoryAgent4*);
EarlyFactoryCallback*fn_80080850(EarlyFactoryCallback*,EarlyFactoryAgent4*);
EarlyFactoryCallback*fn_80080AD4(EarlyFactoryCallback*,EarlyFactoryAgent4*);
EarlyFactoryCallback*fn_80081124(EarlyFactoryCallback*,EarlyFactoryAgent4*);
}
#endif
