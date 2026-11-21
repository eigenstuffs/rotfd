#ifndef GAME_OWNER_CALLBACK_FACTORY_GROUP_VIEWS_H
#define GAME_OWNER_CALLBACK_FACTORY_GROUP_VIEWS_H
struct FactoryGroupCallback{char unknown00[12];};
struct FactoryGroupController22{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0xDC];};
struct FactoryGroupAgent22{char unknown00[0x318];FactoryGroupController22 controller;FactoryGroupCallback**callbacks;};
struct FactoryGroupController6{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0x2C];};
struct FactoryGroupAgent6{char unknown00[0x168];FactoryGroupController6 controller;FactoryGroupCallback**callbacks;};
struct FactoryGroupController3{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0xD0];};
struct FactoryGroupAgent3{char unknown00[0x1F8];FactoryGroupController3 controller;FactoryGroupCallback**callbacks;};
extern "C" {
extern unsigned char lbl_801EF5C8[];
void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void fn_8007D8EC(void*,FactoryGroupCallback**);
extern const char lbl_8029E890[],lbl_8029E8A0[];
FactoryGroupCallback*fn_8009FE50(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A0C88(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_8009FF74(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A063C(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A0D00(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A083C(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A09F0(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A0EDC(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1068(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1F70(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A2038(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A13C8(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A14D0(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1600(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1720(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A17B8(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A125C(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1AE8(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1B60(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1CCC(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_800A1EA8(FactoryGroupCallback*,FactoryGroupAgent22*);
FactoryGroupCallback*fn_8009FFEC(FactoryGroupCallback*,FactoryGroupAgent22*);
extern const char lbl_8029EED0[],lbl_8029EEE0[];
FactoryGroupCallback*fn_800AAC0C(FactoryGroupCallback*,FactoryGroupAgent6*);
FactoryGroupCallback*fn_800AB190(FactoryGroupCallback*,FactoryGroupAgent6*);
FactoryGroupCallback*fn_800AB9E4(FactoryGroupCallback*,FactoryGroupAgent6*);
FactoryGroupCallback*fn_800AB470(FactoryGroupCallback*,FactoryGroupAgent6*);
FactoryGroupCallback*fn_800AB804(FactoryGroupCallback*,FactoryGroupAgent6*);
FactoryGroupCallback*fn_800ABC04(FactoryGroupCallback*,FactoryGroupAgent6*);
extern const char lbl_802A01D0[],lbl_802A01E0[];
FactoryGroupCallback*fn_800AE3B4(FactoryGroupCallback*,FactoryGroupAgent3*);
FactoryGroupCallback*fn_800AE6F8(FactoryGroupCallback*,FactoryGroupAgent3*);
FactoryGroupCallback*fn_800AEEF4(FactoryGroupCallback*,FactoryGroupAgent3*);
}
#endif
