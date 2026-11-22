#ifndef GAME_CALLBACK_HANDLE_TRANSFERS_INTERNAL_H
#define GAME_CALLBACK_HANDLE_TRANSFERS_INTERNAL_H

#include "Game/callback_related_dispatch_internal.h"
struct CallbackTransferOwner {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    CallbackRelatedHandle handle58;
    char unknown5C[8];
    CallbackRelatedHandle handle64;
    char unknown68[8];
    CallbackRelatedHandle handle70;
    char unknown74[0xC];
    CallbackRelatedHandle handle80;
};
extern "C" {
    signed char slot1C__13MovingAgent_ZFv(void*);
    void fn_8025BB68(void*);
    void fn_801FFFCC(void*,const CallbackRelatedHandle*);
    void fn_8020009C(void*,const CallbackRelatedHandle*);
    void fn_80200104(void*,const CallbackRelatedHandle*);
    void fn_8020016C(void*,const CallbackRelatedHandle*);
    void fn_802001D4(void*,const CallbackRelatedHandle*,int);
    void fn_80257E04(void*,const CallbackRelatedHandle*);
    void fn_80257D20(CallbackTransferOwner*,const CallbackRelatedHandle&);
}

#endif
