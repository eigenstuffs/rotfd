#ifndef GAME_OWNER_CALLBACK_FACTORY_VIEWS_H
#define GAME_OWNER_CALLBACK_FACTORY_VIEWS_H
struct OwnerFactoryCallback{char unknown00[12];};
struct OwnerFactoryController{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0xDC];};
struct OwnerFactoryAgent{char unknown00[0x318];OwnerFactoryController controller;OwnerFactoryCallback**callbacks;};
extern "C" {
extern unsigned char lbl_801EF5C8[];
extern const char lbl_8029E9C0[],lbl_8029E9D0[],lbl_8029EAD8[],lbl_8029EAE8[];
void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
OwnerFactoryCallback*fn_800A4334(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A4490(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A4630(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A4560(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A3978(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A3AD4(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A3C74(OwnerFactoryCallback*,OwnerFactoryAgent*);
OwnerFactoryCallback*fn_800A3BA4(OwnerFactoryCallback*,OwnerFactoryAgent*);
void fn_8007D8EC(OwnerFactoryController*,OwnerFactoryCallback**);
}
#endif
