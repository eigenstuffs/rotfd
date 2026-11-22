#include "Game/actor_matrix_offset_801bcd74.h"

extern "C" ActorOffsetVec3 slot110__12ObjectMove_ZFv(ActorOffsetOwner*self,const ActorOffsetVec3&from,ActorOffsetVec3*delta,ActorOffsetVec3*point,int index){
 ActorOffsetVec3 first,second,third;
 ActorOffsetResource*resource=self->getVectors(&first,&second,&third,index);
 if(!resource)return game_vec3_zero;
 ActorOffsetMatrix*matrix=resource->matrix;
 ActorOffsetVec3 offset=matrix->point(second);
 unsigned long long flags=self->getFlags(index);
 if(flags&0x0000000200000000ULL)offset-=from;
 else offset-=first;
 ActorOffsetVec3 target=matrix->point(third);
 if(flags&0x0000080200000000ULL){
  *point=target;self->clearFlags(0x40,index);
  *delta=target-(from+offset);
 }
 return offset;
}
