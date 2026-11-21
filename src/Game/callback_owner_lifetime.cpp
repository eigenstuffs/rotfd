// Recovered callback owner prefix and native lifetime entry points.
typedef unsigned int u32;
extern "C" {
extern char lbl_802ED078[],lbl_801E9D24[],lbl_801EF5C8[];
void fn_80286158(void*);
void fn_802861F0(void*);
void fn_80260744(void*,void*);
void __dt__15Handle_801F7F10Fv(void*,int);
void __dt__12BaseObject_ZFv(void*,int);
void fn_801EF610(void*,void*);
}
struct Link {char unknown0[8];Link *next;};
struct Owner {u32 unknown0,handle;void *table;u32 unknownC,field10,field14;Link *head;Link *previous;Link *next;u32 field24;char nativeHandle[4];char unknown2C[12];u32 field38,field3C,field40;};
struct Global {char unknown0[0x124];void *handles;};
extern "C" Owner *__dt__15Object_8025F0D8Fv(Owner *self,int flag) {
 if(self) {
  self->table=lbl_802ED078;
  Global *global=(Global*)lbl_801E9D24;
  if(global->handles) {
   if(self->previous)self->previous->next=self->next;
   else self->head=self->next;
   fn_80286158(self);
   fn_802861F0(self);
   fn_80260744(global->handles,&self->handle);
  }
  __dt__15Handle_801F7F10Fv(self->nativeHandle,-1);
  __dt__12BaseObject_ZFv(self,0);
  if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}

struct PackedHandle {signed int generation:8;signed int index:24;};
extern "C" {void __ct__12BaseObject_ZFv(void*);void __ct__15Handle_801F7F10Fv(void*);void fn_801F7914(void*,void*);}
extern "C" Owner *__ct__15Object_8025F0D8Fv(Owner *self) {
 __ct__12BaseObject_ZFv(self);
 self->table=lbl_802ED078;
 __ct__15Handle_801F7F10Fv(self->nativeHandle);
 self->field40=0;
 PackedHandle empty;
 empty.index=0;empty.generation=0;
 fn_801F7914(self->nativeHandle,&empty);
 __dt__15Handle_801F7F10Fv(&empty,-1);
 self->head=0;self->previous=0;self->next=0;
 self->field24=0;
 self->field10=0;self->field14=0;
 self->field3C=0;self->field38=0;
 return self;
}

typedef char CheckOwnerSize[sizeof(Owner)==0x44?1:-1];
typedef char CheckPackedHandleSize[sizeof(PackedHandle)==4?1:-1];
