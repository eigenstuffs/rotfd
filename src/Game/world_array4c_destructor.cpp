#include "world_lifetime_internal.h"
WorldArray4C_801E506C::~WorldArray4C_801E506C(){
 if(data){
  for(int i=0;i<count;++i)data[i].~CurveRecord4C_802EA7D8();
  if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(CurveRecord4C_802EA7D8));data=0;}
  data=0;
 }
}
