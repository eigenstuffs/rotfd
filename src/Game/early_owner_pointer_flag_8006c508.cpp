#include "Game/early_owner_pointer_flag_views.h"
extern "C" signed char fn_8006C508(PointerQuery*self,unsigned char){
if(fn_8009FD38(resolvePointer(*self->getHandle()))==1)fn_8006B470(self,resolvePointer(self->getResource()->owner),0);
static_cast<PointerComposite*>(self)->mainSlot68();return 1;
}
