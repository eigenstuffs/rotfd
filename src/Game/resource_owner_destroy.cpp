struct ResourceOwnerDestroyView {char unknown00[8];void* table;char unknown0C[0x64];void*data;};
extern "C" {
extern char lbl_802EC164[],lbl_801EF5C8[],__vt__17Resource_802E9E20[];
void __dt__12BaseObject_ZFv(void*,int);
void fn_801EF610(void*,void*);
}
extern "C" ResourceOwnerDestroyView* fn_80243E90(ResourceOwnerDestroyView*self,int deleting) {
 if(self){
  self->table=lbl_802EC164;
  if(self->data)fn_801EF610(lbl_801EF5C8,self->data);
  if(self){self->table=__vt__17Resource_802E9E20;__dt__12BaseObject_ZFv(self,0);}
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
