struct TransformOwnerDestroyView {char unknown00[8];void* table;};
extern "C" {
extern char lbl_802EC1B8[],lbl_801EF5C8[];
void fn_80243E90(void*,int);
void fn_801EF610(void*,void*);
}
extern "C" TransformOwnerDestroyView* fn_80244128(TransformOwnerDestroyView*self,int deleting) {
 if(self){
  self->table=lbl_802EC1B8;
  fn_80243E90(self,0);
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
