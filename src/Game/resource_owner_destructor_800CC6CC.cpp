#include "Game/owner_cleanup_virtual_view_800CC6CC.h"
extern "C" {extern char lbl_801EF5C8[],lbl_802C1A90[];void fn_801EF610(void*,void*);void __dt__15Object_800A8F90Fv(void*,int);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct CleanupFields_800CC6CC {u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknown31C[0x28];Resource_800CC6CC**resources;};
inline void* cleanup_helper(CleanupFields_800CC6CC*self,int flag) {
 if(self){
 self->primaryTable=lbl_802C1A90;self->secondaryTable=lbl_802C1A90+0x170;
 for(int i=0;i<4;i++)delete self->resources[i];
 operator delete(self->resources);
 __dt__15Object_800A8F90Fv(self,0);
 if((short)flag>0)operator delete(self);
 }
 return self;
}
void*OwnerCleanupVirtualView_800CC6CC::cleanup(int flag){return cleanup_helper(reinterpret_cast<CleanupFields_800CC6CC*>(this),flag);}
