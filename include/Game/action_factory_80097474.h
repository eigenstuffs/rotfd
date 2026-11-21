#ifndef GAME_ACTION_FACTORY_80097474_H
#define GAME_ACTION_FACTORY_80097474_H
struct FactoryComponent{virtual void slot0();virtual void slot1();virtual void slot2(int);char unknown04[0x28];};
struct FactoryTarget{char unknown00[0x14];void*action;};
struct FactoryOwner{char unknown00[0x318];FactoryComponent component;FactoryTarget*target;};
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_8029DFF8[],lbl_8029E008[];void fn_80098B18(FactoryOwner*,void*);void*fn_801EFA1C(void*,int,const char*,const char*,int,int);void*fn_80097144(void*,FactoryOwner*,void*);}
#endif
