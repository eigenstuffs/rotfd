struct OwnedPushHandle{unsigned long value;};
struct OwnedPushArray{int count,capacity;OwnedPushHandle*handles;};
extern "C"{extern char lbl_8028F698[];extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);void __ct__15Handle_801F7F10Fv(void*);void fn_801F86C8(void*,const void*,int);}
extern "C" int fn_8023F45C(OwnedPushArray*self,const OwnedPushHandle*handle){
 if(self->count+1>self->capacity){int capacity=self->capacity+32;if(capacity){if(self->handles)self->handles=(OwnedPushHandle*)fn_8028FAF4(lbl_8028F698,self->handles,self->capacity*4,capacity*4);else self->handles=(OwnedPushHandle*)fn_8028FF24(lbl_8028F698,capacity*4);}else if(self->handles){fn_8028FD50(lbl_8028F698,self->handles,self->capacity*4);self->handles=0;}self->capacity+=32;}
 OwnedPushHandle*entry=&self->handles[self->count++];if(entry){__ct__15Handle_801F7F10Fv(entry);entry->value=0;entry->value=handle->value;fn_801F86C8(lbl_801E9D24.manager,handle,1);}return self->count-1;
}
