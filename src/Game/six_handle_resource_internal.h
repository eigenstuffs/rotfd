#ifndef GAME_SIX_HANDLE_RESOURCE_INTERNAL_H
#define GAME_SIX_HANDLE_RESOURCE_INTERNAL_H
#include "world_lifetime_internal.h"
// Same native typed-handle declaration as typed_handle_800A8204.cpp.
template<int Depth> struct TypedHandleLayer:TypedHandleLayer<Depth-1> {
    ~TypedHandleLayer(){}
};
template<> struct TypedHandleLayer<1>:Handle_801F7F10 {
    TypedHandleLayer(){value=0;}
    ~TypedHandleLayer(){}
};
struct Handle_800A8204:TypedHandleLayer<1> {
    Handle_800A8204();
    ~Handle_800A8204();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
struct Vector3_801D5330 {float x,y,z;Vector3_801D5330();};
struct SixHandleResource_802EA840 : Resource_802E9E20 {
    u32 field0C;
    Handle_800A8204 handles[6];
    Vector3_801D5330 data28[8];
    SixHandleResource_802EA840();
    virtual ~SixHandleResource_802EA840();
    virtual void slot20();
    virtual void slot10();
    virtual void slot0C(u32);
    virtual signed char slot1C();
};
typedef char CheckSixHandleResourceSize[sizeof(SixHandleResource_802EA840)==0x88?1:-1];
#endif
