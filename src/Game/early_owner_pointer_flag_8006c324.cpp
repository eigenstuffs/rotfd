#include "Game/early_owner_pointer_flag_views.h"
extern "C" signed char fn_8006C324(PointerQuery*self,unsigned char){
PointerOwner*selected=fn_80024960(lbl_803776B8->getResource()->registration);
PointerOwner*owner=0;if(selected)owner=resolvePointer(selected->owner);
if(!owner)owner=resolvePointer(fn_8005E9A0()->owner);
PointerOwner*actor=resolvePointer(*self->getHandle());actor->selection=owner;
if(owner && owner->id==PointerName(lbl_8029C79C).value)actor->selected=1;else actor->selected=0;
if(owner)actor->available=1;return 1;
}
