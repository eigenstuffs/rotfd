#include "Game/platform_record_access_internal.h"
extern "C" PlatformRecord18* fn_80283954(PlatformArrays_802EA884*self,const PlatformRecordIndex&key){
 int i=key.index;
 if(i==-1)return 0;
 if(i>=self->records.count)return 0;
 PlatformRecord18*entry=&self->records.data[i];
 if(entry->status!=0)return 0;
 entry->value14=self->value10;
 entry->unknown00=(unsigned long)self->indices.data;
 return entry;
}
extern "C" PlatformRecord18* fn_802839B4(PlatformArrays_802EA884*self,const PlatformRecordIndex&key,signed char*changed){
 int i=key.index;
 if(i==-1)return 0;
 if(i>=self->records.count)return 0;
 PlatformRecord18*entry=&self->records.data[i];
 if(changed)*changed=0;
 if(entry->status==1)return 0;
 if(entry->status==2){
  if(!fn_80283AA0(self,entry,short(entry->count0C+entry->count12)))return 0;
  if(changed)*changed=1;
 }
 entry->value14=self->value10;
 entry->unknown00=(unsigned long)self->indices.data;
 return entry;
}
