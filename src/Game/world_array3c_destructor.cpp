#include "world_lifetime_internal.h"
WorldArray3C_801E513C::~WorldArray3C_801E513C(){
 if(data){
  for(int i=0;i<count;++i)data[i].~CurveRecord3C_802EA7E4();
  if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(CurveRecord3C_802EA7E4));data=0;}
  data=0;
 }
}
