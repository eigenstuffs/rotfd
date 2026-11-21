struct OwnerRecordDestroyView {char unknown00[8];void* table;char unknown0C[0x124];unsigned long handle;};
extern "C" {
extern char lbl_802EC0C0[],lbl_801EF5C8[];
void __dt__15Handle_801F7F10Fv(void*,int);
void fn_80243E90(void*,int);
void fn_801EF610(void*,void*);
}
extern "C" OwnerRecordDestroyView* fn_80241CF0(OwnerRecordDestroyView*self,int deleting) {
 if(self){
  self->table=lbl_802EC0C0;
  if(&self->handle)if(&self->handle)__dt__15Handle_801F7F10Fv(&self->handle,0);
  fn_80243E90(self,0);
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
