/* Scene effects and native typed Handle temporaries; see docs/notes/game-early-actor-scene-effects.md. */
#include "Game/early_actor_scene_effect_views.h"
extern "C" void fn_80089904(EffectOwner*self){
 if(fn_80206E28(lbl_801E9D24.service,0,-1))return;
 EffectTransform*transform=resolveEffect(*self->actor->getResource(0))->transform;
 EffectVector position(transform->position.x,transform->position.y,transform->position.z);
 position.y+=self->actor->height;
 if(self->second){self->second->control(0,0);fn_80254BB4(self->second,&position);fn_80255588(self->second);}
 if(self->first){
  if(lbl_801E9D24.system->enabled){
   self->first->control(0,0);fn_80255588(self->first);
   if(self->actor->hasFlags(0x0400000000000000ULL))fn_80254BB4(self->first,&position);
   else{
    float angle=fn_80285124(self->actor->forwardX,self->actor->forwardZ);angle*=lbl_80378AEC;
    float cosine=fn_8028506C(angle);float sine=fn_80284FA8(angle);
    EffectQuaternion rotation(cosine,lbl_80378AD0*sine,lbl_80378ADC*sine,lbl_80378AD0*sine);
    fn_80254AF4(self->first,&position,&rotation);
   }
  }else fn_80255678(self->first);
 }
}
