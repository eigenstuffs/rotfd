#ifndef GAME_ENGINE_DRAW_RECORD_CTOR_H
#define GAME_ENGINE_DRAW_RECORD_CTOR_H

struct DrawRecordPrefix {unsigned long unknown00[2];};
struct Manipulator_Z:DrawRecordPrefix {
 Manipulator_Z();virtual ~Manipulator_Z();
 virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float)=0;virtual void slot3C();
 char unknown0C[0x20-0x0C];
};
struct ManipulatorDraw_802BC9D0:Manipulator_Z {ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();virtual void slot40()=0;};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct DrawRecordZeroHandle:Handle_801F7F10 {DrawRecordZeroHandle(){value=0;}};
struct DrawRecordTwoZeroHandle:DrawRecordZeroHandle {DrawRecordTwoZeroHandle(){value=0;}};
struct DrawRecordArray {int count,capacity;void*data;DrawRecordArray(){count=0;capacity=0;data=0;}};
struct DrawRecord_802EB0E0:ManipulatorDraw_802BC9D0 {
 DrawRecordArray array;int type;DrawRecordTwoZeroHandle handle;
 DrawRecord_802EB0E0();virtual ~DrawRecord_802EB0E0();virtual void slot38(float);virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
};

typedef char DrawRecord_802EB0E0SizeCheck[(sizeof(DrawRecord_802EB0E0)==0x34)?1:-1];

#endif
