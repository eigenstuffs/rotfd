#include "Game/platform_pool_internal.h"
inline void* operator new(unsigned long,void*memory){return memory;}
extern "C" void* fn_8028FAF4(void*,void*,u32,u32);
extern "C" void* fn_8028FF24(void*,u32);
template<class T,class A> inline void storage(A*self,int count){
 if(count){
  if(self->data)self->data=(T*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*sizeof(T),count*sizeof(T));
  else self->data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));
 }else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(T));self->data=0;}
}
inline void resizeWords(WordArray*self,int count){
 if(count>self->count){
  storage<u32>(self,count);self->capacity=count;
  for(int i=self->count;i<count;++i)new(self->data+i)u32;
  self->count=count;
 }else if(count<self->count){
  for(int i=self->count-1;i>=count;--i)self->data[i].~u32();
  storage<u32>(self,count);self->capacity=count;self->count=count;
 }
}
inline void resizeBits(BitSet_80207EE8*self,int n){self->bits=n;if(n&&(n>>5)+1>self->count)resizeWords(self,(self->bits>>5)+1);}
inline void setBit(BitSet_80207EE8*self,int i){self->data[i>>5]|=1UL<<(i&31);}
extern "C" int fn_80281BD8(PlatformPool_80281EA4*self){
 int index=self->limit==0?-1:fn_80207B94(&self->occupied,0,0);
 ++self->used;
 if(index==-1){
  if(self->count+1>self->capacity){storage<PlatformPoolRecord>(self,self->capacity+8);self->capacity+=8;}
  new(self->data+self->count++)PlatformPoolRecord;
  resizeBits(&self->occupied,self->limit+1);
  setBit(&self->occupied,self->limit);
  return self->limit++;
 }
 setBit(&self->occupied,index);
 return index;
}
