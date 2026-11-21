#ifndef GAME_EARLY_ACTOR_RETAINED_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_RETAINED_CONTROL_VIEWS_H
typedef unsigned long RetainedControlWord;
struct RetainedControlManager;
struct RetainedControlPrefix{char unknown00[0x1C];};
struct RetainedControlOutput:RetainedControlPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void clear(int,int,int);
};
struct RetainedControlScene{char unknown00[0x15058];void*screen;};
struct RetainedControlContext{char unknown00[0x114];char*lists;RetainedControlManager*manager;char unknown11C[8];RetainedControlScene*scene;char unknown128[0x2C];RetainedControlOutput*output;};
extern "C"{extern RetainedControlContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(RetainedControlManager*,const void*,int);RetainedControlWord fn_801F948C(void*,const char*);void fn_801E2074(void*,const struct Handle_8002F6B0&,int);void fn_801E1F3C(void*,const struct Handle_8002F6B0&);void fn_80213A18(void*);void fn_802139D8(void*);void fn_800B3344(void*);void fn_80255678(void*);extern const float lbl_80379354;extern const char lbl_802A0178[],lbl_802A04EC[];}
struct RetainedControlResource{char unknown00[0x38];unsigned long long flags;};
struct Handle_801F7F10{union{RetainedControlWord word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}RetainedControlResource*resolve()const;};
struct RETAINED_CONTROL_ZERO:Handle_801F7F10{RETAINED_CONTROL_ZERO(){word=0;}~RETAINED_CONTROL_ZERO(){}};
struct Handle_80021BCC:RETAINED_CONTROL_ZERO{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}};
struct Handle_8002F6B0:Handle_80021BCC{Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F6B0(){}};
struct RetainedControlEntry{RetainedControlResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RetainedControlManager{char unknown00[8];RetainedControlEntry*entries;};
inline RetainedControlResource*Handle_801F7F10::resolve()const{int index=bits.index;RetainedControlManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==bits.tag?m->entries[index].object:0;}
struct RetainedControlName{RetainedControlWord word;RetainedControlName(const char*s){word=fn_801F948C(this,s);}};
struct RetainedControlItem{char unknown00[0x80];RetainedControlName name;char unknown84[8];unsigned short flags;char unknown8E[0x36];};
struct RetainedControlRecord{char unknown00[4];Handle_801F7F10 handle;char unknown08[0x24];short start;char unknown2E[6];unsigned char selection;char unknown35[0x11];unsigned short count;char unknown48[0x28];RetainedControlItem*items;char unknown74[0x130];float scalar;signed char active;};
struct RetainedControlAction{char unknown00[4];Handle_801F7F10 handle;char unknown08[0x10];signed char active;char unknown19[0x13];int index;};
extern "C" Handle_801F7F10 fn_80058778(void*,const RetainedControlName&,int);
#endif
