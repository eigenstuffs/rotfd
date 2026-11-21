#include "Game/engine_manipulator_destroy.h"

extern "C" {
extern char __vt__28ViewportManipulator_802EB130[],__vt__24ManipulatorDraw_802BC9D0[],__vt__13Manipulator_Z[],lbl_8028F698[],lbl_801EF5C8[];
void fn_8028FD50(void*,void*,int);void fn_801EF610(void*,void*);void __dt__11Activable_ZFv(void*,int);
void __dt__15Handle_801F7F10Fv(Handle_801F7F10*,int);void __dt__15Handle_80020B90Fv(void*,int);
void __destroy_arr(void*,void(*)(void*,int),int,int);
}
static inline void unlinkOwner(ManipulatorDestroyObject*self,MembershipContext*context){
 if(self->isActive()){
  {const Handle_801F7F10&original=self->handle;MembershipHandle handle(original);fn_801E1F3C(context->groups+self->group*0x4C,handle);}
  fn_802139D8(self);
 }
}
static inline void destroyHandle(Handle_801F7F10*self){if(self)__dt__15Handle_801F7F10Fv(self,0);}
static inline void destroyWrapped(ManipulatorDestroyWrapped*self){if(self)destroyHandle(&self->handle);}
static inline void destroyArray(ManipulatorDestroyArray*self){
 if(self){if(self->data){
  int i=0;int offset=i;
  for(;i<self->count;offset+=4,++i)destroyWrapped((ManipulatorDestroyWrapped*)((char*)self->data+offset));
  if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*4);self->data=0;}
  self->data=0;
 }}
}
static inline void destroyRoot(ManipulatorDestroyObject*self){if(self){self->table=__vt__13Manipulator_Z;__dt__11Activable_ZFv(self,0);}}
static inline void destroyDraw(ManipulatorDestroyObject*self){if(self){self->table=__vt__24ManipulatorDraw_802BC9D0;destroyRoot(self);}}
extern "C" ManipulatorDestroyObject*fn_80211508(ManipulatorDestroyObject*self,short deleting){
 if(self){
  self->table=__vt__28ViewportManipulator_802EB130;
  MembershipContext*context=&lbl_801E9D24;
  if(context->groups&&self->isActive())unlinkOwner(self,context);
  destroyWrapped(&self->handle60);
  __destroy_arr(self->handles54,__dt__15Handle_80020B90Fv,4,3);
  destroyWrapped(&self->handle50);destroyWrapped(&self->handle48);destroyWrapped(&self->handle44);
  destroyArray(&self->records);destroyDraw(self);
  if(deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
