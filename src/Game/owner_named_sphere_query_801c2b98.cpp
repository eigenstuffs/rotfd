#include "Game/owner_named_sphere_query_801c2b98.h"

extern "C" signed char fn_801C2B98(OwnerSphereOwner*self,OwnerSphereSphere*out,unsigned short mode,int index)
{
 OwnerSphereHandle*h=self->getHandle(index);
 OwnerSphereInfo info;info.bounds.point=game_vec4_zero;info.bounds.radius=lbl_8037A3B0;info.index=-1;
 if(mode==0){OwnerSphereResource*r=fn_8022E63C(self)->getResource();if(!fn_8024C138(r,OwnerSphereName(lbl_8037A3B4),h,&info))return 0;}
 else if(mode==2){OwnerSphereResource*r=fn_8022E63C(self)->getResource();if(!fn_8024C138(r,OwnerSphereName(lbl_802ACA78),h,&info))return 0;}
 else if(mode==3){OwnerSphereResource*r=fn_8022E63C(self)->getResource();if(!fn_8024C138(r,OwnerSphereName(lbl_8037A3B8),h,&info))return 0;}
 else return 0;
 const OwnerSphereHandle&parent=self->parent;
 OwnerSphereHandle*base=parent.getOwner()->getHandle(0);
 OwnerSphereObject*first=base->getObject();
 const OwnerSphereMatrix*left=first->matrix;
 OwnerSphereOtherObject*second=h->getOther();
 *out=fn_80099A00(product(left,second->matrix),&info.bounds);
 return 1;
}
