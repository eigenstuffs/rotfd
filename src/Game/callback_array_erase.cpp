typedef unsigned long u32;
extern "C" void*memcpy(void*,const void*,u32);
struct Array {char unknown0[0x48];int length,capacity;int *data;};
extern "C" void fn_80255A90(Array*self) {
 int count=self->length;
 for(int i=0;i<count;++i) {int *data=self->data;int remaining=--self->length;memcpy(data,data+1,remaining*sizeof(int));}
}
extern "C" void fn_80255AFC(Array*self,int key) {
 for(int i=0;i<self->length;++i)if(key==self->data[i]) {
  int *position=self->data+i;memcpy(position,position+1,(--self->length-i)*sizeof(int));return;
 }
}
