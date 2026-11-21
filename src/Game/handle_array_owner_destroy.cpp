#include "Game/handle_array_clear_internal.h"
extern "C" {
extern char lbl_802ED110[], __vt__17Resource_802E9E20[], lbl_801EF5C8[];
void* __dt__12BaseObject_ZFv(void*, int);
void fn_801EF610(void*,void*);
}
struct CleanupNative : Handle_801F7F10 {};
struct CleanupHandle : CleanupNative {};
struct CleanupArray {
 int count, capacity; CleanupHandle* data;
 void clear() {
  if(data) {
   for(int i=0;i<count;++i) data[i].~CleanupHandle();
   if(data) {fn_8028FD50(lbl_8028F698,data,capacity*sizeof(CleanupHandle));data=0;}
   data=0;
  }
 }
};
struct CleanupView {char unknown00[8];void*table;CleanupArray handles;};
extern "C" CleanupView* fn_802646EC(CleanupView*self,int deleting) {
 if(self) {
  self->table=lbl_802ED110;
  if(&self->handles)self->handles.clear();
  if(self) {self->table=__vt__17Resource_802E9E20;__dt__12BaseObject_ZFv(self,0);}
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
