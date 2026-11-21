#ifndef GAME_ENGINE_SPATIAL_HANDLE_CTOR_H
#define GAME_ENGINE_SPATIAL_HANDLE_CTOR_H

struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z : RootStorage_80207414 {
 BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();
};
extern "C" {extern const char lbl_801EF5C8[];void fn_801EF610(const void*,void*);}
struct Resource_802E9E20:BaseObject_Z {Resource_802E9E20(){}virtual ~Resource_802E9E20();static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}};
struct SpatialPoint {float x,y,z;SpatialPoint(const SpatialPoint&other){x=other.x;y=other.y;z=other.z;}};
extern "C" {extern SpatialPoint game_vec4_zero;extern const float lbl_8037B3DC,lbl_8037B3E0,lbl_8037B3D0;void __ct__14Light_8024405CFv(void*);}
struct SpatialSphere {SpatialPoint point;float radius;SpatialSphere(float value):point(game_vec4_zero),radius(value){}};
struct SpatialBase_802EC118:Resource_802E9E20 {
 int flags;SpatialSphere bounds;
 SpatialBase_802EC118(float radius):bounds(radius){flags=0;}
 /* The native spatial stream reader overrides Root slot0C. Its argument
  * is represented here by the original 32-bit address-word ABI. */
 virtual void slot0C(unsigned long);
 virtual ~SpatialBase_802EC118();
 virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(void*); virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44(); virtual void slot48();

};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct SpatialZeroHandle:Handle_801F7F10 {SpatialZeroHandle(){value=0;}};
struct SpatialTwiceZeroHandle:SpatialZeroHandle {SpatialTwiceZeroHandle(){value=0;}};
struct SpatialThriceZeroHandle:SpatialTwiceZeroHandle {SpatialThriceZeroHandle(){value=0;}};
struct SpatialFields {int first,second,third;SpatialFields(){first=0;second=0;third=0;}};
struct SpatialTransform {char unknown00[0xB8];SpatialTransform(){__ct__14Light_8024405CFv(this);}};
struct SpatialHandles_802EA2E0:SpatialBase_802EC118 {
 SpatialFields fields;char unknown2C[0x4C-0x2C];SpatialTransform transform;
 SpatialTwiceZeroHandle first;SpatialThriceZeroHandle second,third;
 int tail00,tail04,tail08,tail0C,tail10,tail14;float x,y,z,w;
 SpatialHandles_802EA2E0();virtual ~SpatialHandles_802EA2E0();virtual void slot4C();
};

typedef char SpatialBaseSizeCheck[(sizeof(SpatialBase_802EC118)==0x20)?1:-1];
typedef char SpatialHandlesSizeCheck[(sizeof(SpatialHandles_802EA2E0)==0x138)?1:-1];

#endif
