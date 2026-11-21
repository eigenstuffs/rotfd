#ifndef GAME_HANDLE_RESOURCE_INTERNAL_H
#define GAME_HANDLE_RESOURCE_INTERNAL_H
#include "world_lifetime_internal.h"
struct ResourceHandle : OwnerHandle {
    ResourceHandle(){value=0;}
    ResourceHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~ResourceHandle(){}
};
struct HandleResource_802EA820 : Resource_802E9E20 {
    WorldCurveArray<ResourceHandle> handles;
    virtual ~HandleResource_802EA820();
    virtual void slot10();
    virtual void slot0C(u32);
    virtual signed char slot1C();
};
#endif
