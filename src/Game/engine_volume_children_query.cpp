#include "Game/engine_volume_children_query.h"

extern "C" {extern VolumeContext lbl_801E9D24;VolumeSphere fn_801F0A20(const VolumeSphere*,const VolumeSphere*);signed char fn_8026C094(void*,void*,const VolumeSphere*,void*,void*);}
static inline VolumeQuery*resolve(const VolumeHandle&h){VolumeEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C" signed char fn_802457B8(VolumeQuery*self,VolumeObject*object,void*query,VolumeQueryContext*context){
 signed char available=1;
 if(!(object->flags&0x80000)||(self->flags&1))available=0;
 for(int i=0;i<self->count;++i){
  if(resolve(self->at(i))->test(object,0,0)){
   VolumeSphere*child=resolve(self->at(i))->sphere();
   if(available)*self->sphere()=fn_801F0A20(self->sphere(),child);
   else *self->sphere()=*child;
   available=1;
  }
 }
 if(!query)return available;
 if(available)return fn_8026C094(query,context->field20,self->sphere(),&context->field1C,context->fieldA0);
 return 0;
}
