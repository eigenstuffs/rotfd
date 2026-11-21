#ifndef GAME_PLATFORM_DRAW_DISPATCH_INTERNAL_H
#define GAME_PLATFORM_DRAW_DISPATCH_INTERNAL_H
#include "Game/platform_draw_internal.h"
struct PlatformDrawDispatchOwner : PlatformDrawOwner {
    virtual void slot5C();
    virtual void dispatch(void*,void*,void*);
};
extern "C" void fn_80284D80(PlatformDrawDispatchOwner*,void*,void*);
typedef char CheckPlatformDrawDispatchOwner[sizeof(PlatformDrawDispatchOwner)==0xC0?1:-1];
#endif
