#include "Game/platform_aram_lifetime_internal.h"
PlatformAramPool::~PlatformAramPool(){for(int i=0;i<limit;++i)release(i);}
