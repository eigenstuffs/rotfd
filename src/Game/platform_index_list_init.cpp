#include "Game/platform_index_lists_internal.h"
extern "C" PlatformIndexList fn_801ECA54(PlatformArrays_802EA884*self,short first,short count){
 PlatformIndexList result;result.first=first;result.count=count;result.last=first+count-1;
 for(int i=result.first;i<=result.last;++i){
  platformLink(self,i)->previous=i-1;
  platformLink(self,i)->next=i+1;
 }
 platformLink(self,result.first)->previous=-1;
 platformLink(self,result.last)->next=-1;
 return result;
}
