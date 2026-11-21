#ifndef GAME_ENGINE_MANIPULATOR_RESOURCE_CTOR_H
#define GAME_ENGINE_MANIPULATOR_RESOURCE_CTOR_H

struct ManipulatorPrefix {unsigned long unknown00[2];};
struct Manipulator_Z:ManipulatorPrefix {
 Manipulator_Z();virtual ~Manipulator_Z();
 virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float)=0;virtual void slot3C();
 char unknown0C[0x20-0x0C];
};
struct ManipulatorDraw_802BC9D0:Manipulator_Z {ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();virtual void slot40()=0;};
struct Handle_801F7F10 {
 union{unsigned long value;struct{signed int tag:8,index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();
};
struct ManipulatorZeroHandle:Handle_801F7F10 {ManipulatorZeroHandle(){value=0;}};
struct ManipulatorTwoZeroHandle:ManipulatorZeroHandle {ManipulatorTwoZeroHandle(){value=0;}};
struct Handle_80020B90:ManipulatorZeroHandle {Handle_80020B90();~Handle_80020B90();};
struct ManipulatorTarget {char unknown00[0x1C];Handle_801F7F10 handle;};
struct ManipulatorEntry {ManipulatorTarget*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ManipulatorManager {int count,capacity;ManipulatorEntry*entries;};
struct ManipulatorContext {char unknown00[0x118];ManipulatorManager*manager;};
extern "C" {
 extern ManipulatorContext lbl_801E9D24;
 extern const char lbl_802AE538[],lbl_802AE54C[],lbl_8037AC04[5],lbl_8037AC0C[7];
 extern const float lbl_8037ABF8,lbl_8037ABFC,lbl_8037AC00;
 void*fn_801F948C(void*,const char*);
 void fn_801F86C8(ManipulatorManager*,const Handle_801F7F10*,short);
 void fn_8023D648(ManipulatorTarget*);
}
struct ManipulatorName {void*value;ManipulatorName(const char*t){value=fn_801F948C(this,t);}};
extern "C" Handle_801F7F10 fn_801B550C(ManipulatorManager*,const ManipulatorName&,const ManipulatorName&);
struct ManipulatorCopy:ManipulatorZeroHandle {ManipulatorCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
static inline void assign(Handle_801F7F10&to,const Handle_801F7F10&from){fn_801F86C8(lbl_801E9D24.manager,&to,-1);to.value=from.value;fn_801F86C8(lbl_801E9D24.manager,&from,1);}
static inline ManipulatorTarget*resolve(const Handle_801F7F10&h){ManipulatorEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];return entry->tag==h.bits.tag?entry->object:0;}
static inline void setTarget(ManipulatorTarget*t,const Handle_801F7F10&h){assign(t->handle,h);fn_8023D648(t);}
struct ManipulatorArray {int count,capacity;void*data;ManipulatorArray(){count=0;capacity=0;data=0;}};
struct ViewportManipulator_802EB130:ManipulatorDraw_802BC9D0 {
 float field20,field24,field28,field2C,field30,field34;ManipulatorArray array;ManipulatorTwoZeroHandle handle44,handle48;int field4C;ManipulatorTwoZeroHandle handle50;Handle_80020B90 handles[3];ManipulatorTwoZeroHandle handle60;
 ViewportManipulator_802EB130();virtual ~ViewportManipulator_802EB130();virtual void slot38(float);virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
};

typedef char ViewportManipulatorSizeCheck[(sizeof(ViewportManipulator_802EB130)==0x64)?1:-1];

#endif
