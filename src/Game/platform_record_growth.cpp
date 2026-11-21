#include "Game/platform_index_lists_internal.h"
#include "Game/platform_record_access_internal.h"
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
extern "C" signed char fn_80283AA0(PlatformArrays_802EA884*self,PlatformRecord18*record,short amount){
 if(!record)return 0;
 if(record->status!=2)return 0;
 if(amount==0)return 0;
 if(self->freeIndices.count<amount)fn_80283D5C(self,amount);
 if(self->freeIndices.count<amount){
  int old=self->indices.count;
  int extra=amount+16;
  int count=old+extra;
  if(count>32000)return 0;
  resizeLinks(&self->indices,old+extra);
  PlatformIndexList list=fn_801ECA54(self,old,extra);
  self->freeIndices=fn_8026EBE8(self,self->freeIndices,list);
 }
 record->status=0;record->count0C=0;
 record->unknown08=-1;record->unknown0A=-1;
 record->count12=amount;
 record->unknown0E=self->freeIndices.first;
 self->freeIndices.count-=amount;
 while(amount--){
  record->unknown10=self->freeIndices.first;
  self->freeIndices.first=platformLink(self,self->freeIndices.first)->next;
 }
 platformLink(self,record->unknown10)->next=-1;
 if(self->freeIndices.count==0)self->freeIndices.first=self->freeIndices.last=-1;
 return 1;
}
