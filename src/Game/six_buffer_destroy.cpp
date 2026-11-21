extern "C" {
extern char lbl_802ED518[],lbl_8028F698[],lbl_801EF5C8[];
extern char __vt__26SixHandleResource_802EA840[],__vt__17Resource_802E9E20[];
void fn_8028F8F0(void*,void*,unsigned long);
void fn_801EF610(void*,void*);
void fn_801EB634(void*,int);
void __dt__15Handle_800A8204Fv(void*,int);
void* __dt__12BaseObject_ZFv(void*,int);
void __destroy_arr(void*,void(*)(void*,int),unsigned long,unsigned long);
}
struct SixBuffer {void*data;unsigned long capacity,count;void clear(){if(data)fn_8028F8F0(lbl_8028F698,data,capacity);data=0;capacity=0;count=0;}};
struct SixBufferView {char unknown00[8];void*table;int unknown0C;unsigned long handles[6];char unknown28[0x84];SixBuffer buffers[6];};
extern "C" SixBufferView* fn_80271A00(SixBufferView*self,int deleting) {
 if(self) {
  self->table=lbl_802ED518;
  for(int i=0;i<6;++i)self->buffers[i].clear();
  __destroy_arr(self->buffers,fn_801EB634,12,6);
  if(self) {
   self->table=__vt__26SixHandleResource_802EA840;
   __destroy_arr(self->handles,__dt__15Handle_800A8204Fv,4,6);
   if(self){self->table=__vt__17Resource_802E9E20;__dt__12BaseObject_ZFv(self,0);}
  }
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
