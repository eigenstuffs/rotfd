/* Original masked sphere/geometry dispatch.
 * See docs/notes/game-engine-sphere-mask-dispatch.md. */
#include "Game/engine_sphere_mask_dispatch.h"
static inline bool overlaps(const MaskSphere& a,const MaskSphere& b) { float radius=a.radius+b.radius; const MaskSpherePoint& delta=a.center-b.center; return delta.lengthSquared()<radius*radius; }
#define MASK(x) (MaskSphereFlags(x)<<32)
extern "C" int fn_80244710(MaskSphereOwner* self,MaskSphereObject* object,const MaskSphereInfo* info,const MaskSphere* sphere,MaskSphereCollector* collector,MaskSphereFlags flags)
{
    if(!(flags&MASK(0xF000))) return 0;
    if(info->flags&1) return 0;
    MaskSphere transformed=fn_80099A00(object->getInverse(),sphere);
    if(!overlaps(self->bounds,transformed)) return 0;
    void* saved=collector->record;
    if(flags&MASK(0x8000)) {
        if((flags&MASK(0x200))&&self->a2)
            fn_801E059C(&transformed,self->a2,collector,MASK(0x8200));
        else if((flags&MASK(0x400))&&self->a3)
            fn_801DFE90(&transformed,self->a3,collector,MASK(0x8400));
        else if(flags&MASK(0x800)) {
            if(self->a0) fn_801E0BA4(&transformed,self->a0,collector,MASK(0x8800));
            if(self->a1) fn_801E0BA4(&transformed,self->a1,collector,MASK(0x8800));
        }
    } else if(flags&MASK(0x2000)) {
        if((flags&MASK(0x200))&&self->d1)
            fn_801E059C(&transformed,self->d1,collector,MASK(0x2000));
        else if((flags&MASK(0x400))&&self->d2)
            fn_801DFE90(&transformed,self->d2,collector,MASK(0x2000));
        else if((flags&MASK(0x800))&&self->d0)
            fn_801E0BA4(&transformed,self->d0,collector,MASK(0x2800));
    } else {
        if(flags&MASK(0x1000)) {
            if((flags&MASK(0x200))&&self->c1)
                fn_801E059C(&transformed,self->c1,collector,MASK(0x1200));
            else if((flags&MASK(0x400))&&self->c2)
                fn_801DFE90(&transformed,self->c2,collector,MASK(0x1400));
            else if((flags&MASK(0x800))&&self->c0)
                fn_801E0BA4(&transformed,self->c0,collector,MASK(0x1800));
        }
        if(flags&MASK(0x4000)) {
            if((flags&MASK(0x200))&&self->b1)
                fn_801E059C(&transformed,self->b1,collector,MASK(0x4200));
            else if((flags&MASK(0x400))&&self->b2)
                fn_801DFE90(&transformed,self->b2,collector,MASK(0x4400));
            else if((flags&MASK(0x800))&&self->b0)
                fn_801E0BA4(&transformed,self->b0,collector,MASK(0x4800));
        }
    }
    return fn_801DC718(collector,saved,object);
}
