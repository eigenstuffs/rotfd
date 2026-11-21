#include "Game/platform_index_lists_internal.h"
extern "C" PlatformIndexList fn_8026EBE8(PlatformArrays_802EA884*self,const PlatformIndexList&a,const PlatformIndexList&b){
 if(a.count==0)return b;
 if(b.count==0)return a;
 platformLink(self,a.last)->next=b.first;
 platformLink(self,b.first)->previous=a.last;
 PlatformIndexList result;result.first=a.first;result.last=b.last;result.count=a.count+b.count;
 return result;
}
