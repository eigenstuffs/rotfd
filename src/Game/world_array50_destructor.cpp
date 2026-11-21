#include "world_lifetime_internal.h"
WorldArray50_801E4F9C::~WorldArray50_801E4F9C(){
 if(data){
  for(int i=0;i<count;++i)data[i].~CurveRecord50_802F15C0();
  if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(CurveRecord50_802F15C0));data=0;}
  data=0;
 }
}
