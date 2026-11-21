/* Scene effects and native typed Handle temporaries; see docs/notes/game-early-actor-scene-effects.md. */
#include "Game/early_actor_scene_effect_views.h"
extern "C" void fn_80089B74(EffectOwner*self){
 const char*strings=lbl_8029D680;
 EffectTransform*transform=resolveEffect(*self->actor->getResource(0))->transform;
 EffectVector position(transform->position.x,transform->position.y,transform->position.z);
 position.y+=self->actor->height;
 if(self->actor->velocityY>self->maximum)return;
 signed char below=self->actor->velocityY<self->minimum;
 SceneEffect*effect;
 if(below){effect=resolveEffect(fn_80058778(lbl_801E9D24.scene->mode,EffectName(strings+0x104),0));fn_80255D88(self->controller,0x9E,15,0,0);}
 else{effect=resolveEffect(fn_80058778(lbl_801E9D24.scene->mode,EffectName(strings+0x118),0));fn_80255D88(self->controller,0x9D,15,0,0);}
 if(effect){effect->activate();fn_802554F4(effect);fn_80254BB4(effect,&position);}
 if(below){
  effect=resolveEffect(fn_80058778(lbl_801E9D24.scene->mode,EffectName(strings+0x130),0));
  if(effect){effect->activate();fn_802554F4(effect);fn_80254BB4(effect,&position);fn_80255D88(self->controller,0x9D,15,0,0);}
  effect=resolveEffect(fn_80058778(lbl_801E9D24.scene->mode,EffectName(strings+0x148),0));
  if(effect){effect->activate();fn_802554F4(effect);fn_80254BB4(effect,&position);fn_80255D88(self->controller,0x9D,15,0,0);}
 }
}
