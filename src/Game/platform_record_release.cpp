#include "Game/platform_index_lists_internal.h"
#include "Game/platform_record_selection_internal.h"
extern "C" void fn_8026EB34(PlatformArrays_802EA884*self,PlatformRecord18*record,int status){
 if(record->status==0){
  self->freeIndices=fn_8026EBE8(self,self->freeIndices,*(PlatformIndexList*)&record->unknown08);
  self->freeIndices=fn_8026EBE8(self,self->freeIndices,*(PlatformIndexList*)&record->unknown0E);
 }
 record->status=status;record->unknown00=0;
}
