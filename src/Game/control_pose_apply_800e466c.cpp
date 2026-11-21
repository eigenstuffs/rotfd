#include "Game/control_pose_apply_800e466c.h"

extern "C"void fn_800E466C(PoseApplyControl*self){
 if(fn_8007D604((char*)self->actor+0x318,5)){
  if(fn_80255618(resolve(self->targets->first))){resolve(self->targets->first)->reset38();fn_802554F4(resolve(self->targets->first));}
  if(fn_80255618(resolve(self->targets->second))){resolve(self->targets->second)->reset38();fn_802554F4(resolve(self->targets->second));}
  PoseApplyVector position=resolveTransform(resolveModel(self->actor->matrixHandle(0))->transform)->position;
  position=(*resolve(self->actor->matrixHandle(0))->transform)*position;
  fn_80254BB4(resolve(self->targets->first),position);
  const PoseApplyBasis parent=resolve(self->actor->matrixHandle(0))->basis;
  const PoseApplyVector direction=parent*PoseApplyVector(self->second->transform->tx,self->second->transform->ty,self->second->transform->tz);
  PoseApplyQuaternion rotation;
  rotation.x=fn_8028506C(lbl_803797D4);
  float cosine=fn_80284FA8(lbl_803797D4);
  rotation.z=lbl_803797C8*cosine;rotation.y=lbl_803797CC*cosine;rotation.w=rotation.z;
  fn_801F1AAC(&rotation);
  PoseApplyNode*target=resolve(self->targets->second);
  fn_80254AF4(target,self->actor->position(0)+direction,rotation);
 }else{
  fn_80255678(resolve(self->targets->first));
  fn_80255678(resolve(self->targets->second));
 }
}
