#include "Game/platform_aram_internal.h"
#include "Game/platform_aram_lifetime_internal.h"
inline void* operator new(unsigned long,void*memory){return memory;}
extern "C" signed char lbl_80377FB4;
extern "C" PlatformAramOwner* fn_802859F0(PlatformAramOwner* self) {
    if(lbl_80377FB4)new (&lbl_8035DE34)PlatformAramPool;
    self->unknown08=0;
    return self;
}
