#include "Game/ground_collision_callback_8028e4f8.h"

extern "C" void slot58__12ObjectMove_ZFv(GroundCollisionSelf*self,void*context,void*,float delta){
 GroundCollisionFlags flags=self->mode;
 if(flags&0xA000ULL){
  GroundCollisionVec4 point(game_vec4_zero,lbl_8037B940);
  if(self->getPoint(point,3,0)){
   GroundCollisionActor*actor=self->getHandle(0)->getActor();
   GroundCollisionOwner*owner=actor->owner.getOwner();
   GroundCollisionResult result;
   point.y+=lbl_8037B944;
   GroundCollisionVec3 oldPoint=point;
   float span=lbl_8037B944+self->height;
   float remaining;
   if(span<lbl_8037B948){span=lbl_8037B94C;remaining=lbl_8037B950;}
   else if(span>=lbl_8037B954){span=lbl_8037B958;remaining=lbl_8037B940;}
   else remaining=lbl_8037B954-span;
   while(remaining>lbl_8037B948 && !fn_80269230(context,GroundCollisionRay(point,GroundCollisionVec3(lbl_8037B95C,lbl_8037B960,lbl_8037B95C),span),&result,0x0000876000000002ULL,0x0000000400000008ULL)){
    remaining-=span;point.y-=span;span=lbl_8037B940;
   }
   if(remaining>lbl_8037B948){
    self->height=oldPoint.y-result.point.y;
    owner->contact(actor,oldPoint,&result,point.w);
    if(!(flags&0x2000ULL))actor->flags&=~0x80000;
    if((flags&0x8000ULL)&&(result.flags&0x100ULL))owner->flags|=0x10;
    else owner->flags&=~0x10;
    if(actor->type.getTypeObject()->type==5)fn_801CBDE4(owner,actor,result.object,delta);
   }else{actor->flags&=~0x80000;owner->flags&=~0x10;}
  }
 }
}
