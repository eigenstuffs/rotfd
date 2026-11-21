#include "Game/platform_pool_internal.h"
extern "C" void fn_80281EA0(){}
PlatformPool_80281EA4::~PlatformPool_80281EA4(){
 for(int i=first();i!=-1;i=next(i)){
  data[i].object->slot=-1;
  release(i);
 }
}

PlatformPool_80281EA4::PlatformPool_80281EA4(){}
