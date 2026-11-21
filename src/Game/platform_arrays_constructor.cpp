#include "Game/platform_index_lists_internal.h"
extern "C" {extern const float lbl_8037A618,lbl_8037A640;}
template<class T> inline void storageLinks(WorldCurveArray<T>*self,int count){
 if(count){
  if(self->data)self->data=(T*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*sizeof(T),count*sizeof(T));
  else self->data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));
 }else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(T));self->data=0;}
 self->capacity=count;
}
inline void resizeLinks(WorldCurveArray<PlatformLink>*self,int count){
 if(count>self->count){
  storageLinks(self,count);
  for(int i=self->count;i<count;++i)new(self->data+i)PlatformLink;
  self->count=count;
 }else if(count<self->count){
  for(int i=self->count-1;i>=count;--i)self->data[i].~PlatformLink();
  storageLinks(self,count);self->count=count;
 }
}
PlatformArrays_802EA884::PlatformArrays_802EA884(int value):vtable(__vt__23PlatformArrays_802EA884){
 unknown04=value;
 value10=lbl_8037A618;value14=lbl_8037A640;
 resizeLinks(&indices,2);
 freeIndices=fn_801ECA54(this,0,2);
 flag1A=1;unknown18=0;
}
