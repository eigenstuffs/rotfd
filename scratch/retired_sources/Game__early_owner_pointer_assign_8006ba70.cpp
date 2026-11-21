#include "Game/early_owner_pointer_flag_views.h"
extern "C" signed char fn_8006BA70(PointerQuery*self,PointerOwner*owner){
PointerOwner*actor=resolvePointer(*self->getHandle());actor->selection=owner;
if(owner && owner->id==PointerName(lbl_8029C79C).value)actor->selected=1;else actor->selected=0;
if(owner)actor->available=1;return 1;
}
