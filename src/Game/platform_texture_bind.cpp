#include "Game/platform_pool_internal.h"
extern "C" {int fn_80281BD8(PlatformPool_80281EA4*);extern float lbl_8037B7E0;}
inline void* paletteData(PlatformPoolObject*object){return object->palette10;}
inline int paletteEntries(PlatformPoolObject*object){if(object->format3C==1)return 16;else if(object->format3C==2)return 256;else return 0;}
extern "C" void fn_80281830(PlatformPool_80281EA4*self,PlatformPoolObject*object,GXTexWrapMode wrapS,GXTexWrapMode wrapT,GXTexMapID unit){
 PlatformPoolRecord*entry;
 if(object->slot==-1){
  object->slot=fn_80281BD8(self);
  entry=&self->data[object->slot];
  u32 width=object->width30,height=object->height34;
  switch(object->format3C){
   case 1:
    GXInitTexObjCI(&entry->texture,object->image0C,width,height,GX_TF_C4,wrapS,wrapT,0,unit);
    if(object->paletteFormat3E==2)GXInitTlutObj(&entry->palette,paletteData(object),GX_TL_RGB565,paletteEntries(object));
    else GXInitTlutObj(&entry->palette,paletteData(object),GX_TL_RGB5A3,paletteEntries(object));
    entry->palette51=1;entry->extra52=0;break;
   case 2:
    GXInitTexObjCI(&entry->texture,object->image0C,width,height,GX_TF_C8,wrapS,wrapT,0,unit);
    if(object->paletteFormat3E==2)GXInitTlutObj(&entry->palette,paletteData(object),GX_TL_RGB565,paletteEntries(object));
    else GXInitTlutObj(&entry->palette,paletteData(object),GX_TL_RGB5A3,paletteEntries(object));
    entry->extra52=0;entry->palette51=1;break;
   case 8:
    GXInitTexObj(&entry->texture,object->image0C,width,height,GX_TF_RGB565,wrapS,wrapT,0);
    entry->palette51=0;entry->extra52=0;break;
   case 7:case 10:
    GXInitTexObj(&entry->texture,object->image0C,width,height,GX_TF_RGB5A3,wrapS,wrapT,0);
    entry->palette51=0;entry->extra52=0;break;
   case 12:case 13:
    GXInitTexObj(&entry->texture,object->image0C,width,height,GX_TF_RGBA8,wrapS,wrapT,0);
    entry->palette51=0;entry->extra52=0;break;
   case 14:
    GXInitTexObj(&entry->texture,object->image0C,width,height,GX_TF_CMPR,wrapS,wrapT,0);
    entry->palette51=0;entry->extra52=0;break;
  }
  if((signed char)(object->flags41&4))GXInitTexObjLOD(&entry->texture,GX_LINEAR,GX_LINEAR,lbl_8037B7E0,lbl_8037B7E0,lbl_8037B7E0,0,0,GX_ANISO_1);
  else GXInitTexObjLOD(&entry->texture,GX_NEAR,GX_NEAR,lbl_8037B7E0,lbl_8037B7E0,lbl_8037B7E0,0,0,GX_ANISO_1);
 }else entry=&self->data[object->slot];
 entry->object=object;entry->flag50=1;
 if(entry->palette51)GXLoadTlut(&entry->palette,unit);
 GXInitTexObjWrapMode(&entry->texture,wrapS,wrapT);
 GXLoadTexObj(&entry->texture,unit);
 if(entry->extra52)GXLoadTexObj(&entry->extra,GX_TEXMAP1);
}
