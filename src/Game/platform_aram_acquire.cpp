#include "Game/platform_aram_internal.h"
inline void* operator new(unsigned long,void*memory){return memory;}
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*,void*,unsigned long,unsigned long);
void* fn_8028FF24(void*,unsigned long);
void fn_8028FD50(void*,void*,unsigned long);
int fn_80207B94(void*,int,int);
}
typedef unsigned long AramWord;
struct AramWords {int count,capacity;AramWord* data;};
struct AramBits : AramWords {int bits;};
template<class T,class A> inline void storage(A*self,int count){
 if(count){
  if(self->data)self->data=(T*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*sizeof(T),count*sizeof(T));
  else self->data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));
 }else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(T));self->data=0;}
}
inline void resizeWords(AramWords*self,int count){
 if(count>self->count){
  storage<AramWord>(self,count);self->capacity=count;
  for(int i=self->count;i<count;++i)new(self->data+i)AramWord;
  self->count=count;
 }else if(count<self->count){
  for(int i=self->count-1;i>=count;--i)self->data[i].~AramWord();
  storage<AramWord>(self,count);self->capacity=count;self->count=count;
 }
}
inline void resizeBits(AramBits*self,int n){self->bits=n;if(n&&(n>>5)+1>self->count)resizeWords(self,(self->bits>>5)+1);}
inline void setBit(AramBits*self,int i){self->data[i>>5]|=1UL<<(i&31);}
extern "C" int fn_80285458(PlatformAramBytePool*self,unsigned char value){
 int index=self->limit==0?-1:fn_80207B94(reinterpret_cast<AramBits*>(&self->occupied.count),0,0);
 ++self->used;
 if(index==-1){
  if(self->count+1>self->capacity){storage<unsigned char>(self,self->capacity+256);self->capacity+=256;}
  new(self->data+self->count++)unsigned char(value);
  resizeBits(reinterpret_cast<AramBits*>(&self->occupied.count),self->limit+1);
  setBit(reinterpret_cast<AramBits*>(&self->occupied.count),self->limit);
  return self->limit++;
 }
 self->data[index]=value;
 setBit(reinterpret_cast<AramBits*>(&self->occupied.count),index);
 return index;
}
