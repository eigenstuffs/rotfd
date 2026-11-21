struct CallbackValueListOwner {char unknown0[0x48];int count,capacity;int*data;};
extern "C" {
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);
 void*fn_8028FF24(void*,unsigned long);
 void fn_8028FD50(void*,void*,unsigned long);
}
extern "C" void fn_80255B78(CallbackValueListOwner*self,int value){
 for(int i=0;i<self->count;++i){if(self->data[i]==value)return;}
 if(self->count+1>self->capacity){
  int capacity=self->capacity+4;
  if(capacity!=0){
   if(self->data)self->data=(int*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*4,capacity*4);
   else self->data=(int*)fn_8028FF24(lbl_8028F698,capacity*4);
  }else if(self->data){
   fn_8028FD50(lbl_8028F698,self->data,self->capacity*4);
   self->data=0;
  }
  self->capacity+=4;
 }
 int*slot=&self->data[self->count++];
 if(slot)*slot=value;
}
