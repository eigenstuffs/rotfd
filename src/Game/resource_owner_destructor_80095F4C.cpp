#include "Game/owner_cleanup_virtual_view_80095F4C.h"
extern "C" {extern char lbl_801EF5C8[],lbl_802B995C[];void fn_801EF610(void*,void*);void __dt__15Object_80098A70Fv(void*,int);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct CleanupFields_80095F4C {u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknown31C[0x28];Resource_80095F4C**resources;};
inline void* cleanup_helper(CleanupFields_80095F4C*self,int flag) {
 if(self){
 self->primaryTable=lbl_802B995C;self->secondaryTable=lbl_802B995C+0x170;
 for(int i=0;i<9;i++)delete self->resources[i];
 operator delete(self->resources);
 __dt__15Object_80098A70Fv(self,0);
 if((short)flag>0)operator delete(self);
 }
 return self;
}
void*OwnerCleanupVirtualView_80095F4C::cleanup(int flag){return cleanup_helper(reinterpret_cast<CleanupFields_80095F4C*>(this),flag);}
