#include "Game/owner_cleanup_virtual_view_8009A8AC.h"
extern "C" {
 extern char lbl_801EF5C8[],lbl_802BAE04[];
 void fn_801EF610(void*,void*);
 void __dt__15Object_8009AA98Fv(void*,int);
}
struct CleanupFields_8009A8AC {char unknown00[8];void*vtable;char unknown0C[780];void*secondary;};
static inline void dispose(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
inline void*cleanup_helper(CleanupFields_8009A8AC*self,int flag){
 
 if(self){self->vtable=lbl_802BAE04;self->secondary=lbl_802BAE04+368;__dt__15Object_8009AA98Fv(self,0);if((short)flag>0)dispose(self);}
 return self;
}
void*OwnerCleanupVirtualView_8009A8AC::cleanup(int flag){return cleanup_helper(reinterpret_cast<CleanupFields_8009A8AC*>(this),flag); }
#include "Game/motion_forwarding.h"

extern "C" void fn_8009A930(ForwardActor* self){fn_8009AB58(self);}

#include "Game/motion_forwarding.h"

extern "C" void fn_8009A950(ForwardActor* self){fn_8009BEE8(self);fn_8007DCDC(self->component);}

#include "Game/motion_forwarding.h"

extern "C" void fn_8009A984(ForwardActor* self,float delta){fn_8009ACBC(self,delta);}

#include "Game/motion_forwarding.h"

extern "C" void fn_8009A9A4(ForwardActor* self){fn_8009AEA4();}

void OwnerCleanupVirtualView_8009A8AC::hook(){}
