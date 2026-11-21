#include "Game/early_owner_flag_branch_views.h"
extern "C" signed char fn_8006734C(FlagObject*self,FlagObject*other){
if(flagSet(other->flags,1)){
if(!(resolveFlag(other->controller)->actorFlags&0x8000000000ULL))return 1;return 0;
}
if(other->flags&0x2000000ULL){if(!flagSet(fn_8005E90C()->actorFlags,0x8000000000ULL))return 1;return 0;}
return 0;
}
