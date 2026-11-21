#include "Game/owner_cleanup_virtual_view_80027A08.h"
extern "C" {extern char lbl_801EF5C8[],lbl_802B074C[];void fn_801EF610(void*,void*);void __dt__4CFSMFv(void*,int);void __dt__16Objects_802EB940Fv(void*,int);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct CleanupFields_80027A08 {u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknown31C[0x28];FactoryCallback**callbacks;};
inline void* cleanup_helper(CleanupFields_80027A08*self,int flag) {
 if(self){
 self->primaryTable=lbl_802B074C;self->secondaryTable=lbl_802B074C+0x170;
 for(int i=0;i<3;i++){FactoryCallback*p=self->callbacks[i];if(p)delete p;}
 operator delete(self->callbacks);
 __dt__4CFSMFv((char*)self+0x318,0);__dt__16Objects_802EB940Fv(self,0);
 if((short)flag>0)operator delete(self);
 }
 return self;
}
void*OwnerCleanupVirtualView_80027A08::cleanup(int flag){return cleanup_helper(reinterpret_cast<CleanupFields_80027A08*>(this),flag);}
