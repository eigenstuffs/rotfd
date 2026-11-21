#ifndef GAME_VIEWPORT_RENDER_HELPERS_INTERNAL_H
#define GAME_VIEWPORT_RENDER_HELPERS_INTERNAL_H
#include "objects_owner_internal.h"
struct ViewVec3 {
    float x,y,z;
    ViewVec3(const ViewVec3&v):x(v.x),y(v.y),z(v.z){}
};
extern "C" {extern const ViewVec3 game_vec4_zero;extern const float lbl_8037A5BC;}
struct ViewSphere {ViewVec3 center;float radius;ViewSphere():center(game_vec4_zero),radius(lbl_8037A5BC){}};
struct ViewEntry_801E8A88 {
    ViewSphere sphere;void*object;void*geometry;u32 unknown18,unknown1C;
    ViewEntry_801E8A88();
};
struct CallbackHandle:Handle_801F7F10 {
    CallbackHandle(const OwnerHandle&h){value=0;value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~CallbackHandle(){}
};
struct ViewCallbackOwner {char unknown[0xC164];OwnerHandle callback;};
typedef char CheckViewEntrySize[sizeof(ViewEntry_801E8A88)==32?1:-1];
#endif
