#include "Game/callback_handle_chain_internal.h"

extern "C" void fn_8025E11C(ChainOwner*self) {ChainObject *target=resolve(resolve(self->owner)->related);fn_802432A8(target);fn_802431F8(target);}
extern "C" int *fn_8025E1D4(ChainOwner*self,int index) {ChainObject *target=resolve(resolve(self->owner)->related);struct Values {char unknown0[0x88];int data[10];};return &((Values*)target)->data[index];}
extern "C" float fn_8025E268(ChainOwner*self,int index) {ChainObject *target=resolve(resolve(self->owner)->related);return ((float*)((char*)target+0xB0))[index];}
