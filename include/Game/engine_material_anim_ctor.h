#ifndef GAME_ENGINE_MATERIAL_ANIM_CTOR_H
#define GAME_ENGINE_MATERIAL_ANIM_CTOR_H

struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z:RootStorage_80207414 {BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();};
struct Resource_802E9E20:BaseObject_Z {Resource_802E9E20(){}virtual ~Resource_802E9E20();};
struct CurveBase_801B1088 {unsigned short flags,unknown02;CurveBase_801B1088();~CurveBase_801B1088();};
template<int Type> struct MaterialCurve:CurveBase_801B1088 {int count,capacity;void*data;MaterialCurve(){count=0;capacity=0;data=0;if(Type==2)flags=2;}~MaterialCurve();};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct MaterialZeroHandle:Handle_801F7F10 {MaterialZeroHandle(){value=0;}};
struct MaterialTwoZeroHandle:MaterialZeroHandle {MaterialTwoZeroHandle(){value=0;}};
extern "C" const float lbl_8037B300;
struct MaterialAnim_802EC000:Resource_802E9E20 {
 unsigned char flags;char unknown0D[3];MaterialCurve<0> curve10;MaterialCurve<2> curve20,curve30,curve40,curve50,curve60,curve70;MaterialCurve<0> curve80,curve90,curveA0;
 float first,second;MaterialTwoZeroHandle handle;
 MaterialAnim_802EC000();virtual ~MaterialAnim_802EC000();
};

typedef char MaterialAnimSizeCheck[(sizeof(MaterialAnim_802EC000)==0xBC)?1:-1];

#endif
