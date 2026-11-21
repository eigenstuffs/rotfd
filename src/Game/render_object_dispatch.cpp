#include "objects_owner_internal.h"
struct RenderVec3 {
    float x,y,z;
    RenderVec3(){};
    RenderVec3(float a,float b,float c):x(a),y(b),z(c){}
    RenderVec3 operator-(const RenderVec3&v)const {return RenderVec3(x-v.x,y-v.y,z-v.z);}
    float square()const{return z*z+(x*x+y*y);}
};
struct RenderSphere {RenderVec3 center;float radius;};
struct RenderMatrix {u32 word[16];};
extern "C" void fn_801F1080(RenderMatrix*,const RenderMatrix*,RenderMatrix*);
static inline RenderMatrix product(RenderMatrix&a,const RenderMatrix&b){RenderMatrix r;fn_801F1080(&a,&b,&r);return r;}
struct RenderObjectView;
struct RenderContextView;
struct RenderMaterialView;
struct RenderGeometryView:BaseObject_Z {
    unsigned char bounds[0x60];
    unsigned short field6C,flags6E;
    RenderSphere* sphere70;
    virtual void slot20(RenderContextView*,RenderMaterialView*);
};
struct RenderMaterialView:BaseObject_Z {
    u32 flags0C;
    virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();
    virtual void slot34(RenderContextView*);
    virtual signed char slot38(RenderObjectView*,void*,RenderContextView*);
};
struct RenderObjectView {
    unsigned char unknown0[0x1C];
    OwnerHandle geometry,material,handle24,handle28;
    unsigned char unknown2C[0xF4];
    u32 flags120;
    RenderMatrix* matrix124;
};
struct RenderContextView {
    u32 field0,viewIndex,field8,fieldC;
    const u32& view()const{return viewIndex;}
    RenderObjectView* object;
    void* object14;void*object18;
    u32 field1C;
    RenderMatrix matrix20,matrix60;
    RenderSphere sphereA0;
    unsigned char unknownB0[0x10];
    void* entriesC0[64];
    u32 entryCount;
    unsigned char unknown1C4[0xA08];
    u32 fieldBCC;
    void append(void*const&p){if(entryCount<64){entriesC0[entryCount]=p;++entryCount;}}
};
struct RenderEntry {RenderSphere sphere;void*object;unsigned char unknown[12];};
struct RenderEntryList {RenderEntry entries[64];int count;
    RenderEntry&at(const unsigned int&i){return entries[i];}};
struct RenderObjectList {unsigned char unknown[0x74];RenderObjectView*objects[4096];int count;};
extern "C" {
void fn_80099A00(RenderSphere*,RenderMatrix*,RenderSphere*);
signed char fn_8026C094(void*,RenderMatrix*,void*,u32*,RenderSphere*);
}
static inline void selectEntries(RenderContextView*context,const RenderSphere&s,RenderEntryList*list){
    context->entryCount=0;
    int count=list->count;
    for(int i=0;i<count;++i){
        float radius=s.radius+list->at(i).sphere.radius;
        if((s.center-list->at(i).sphere.center).square()<radius*radius){
            context->append(list->at(i).object);
            if(context->entryCount==64)break;
        }
    }
}
extern "C" void fn_801E7D1C(RenderObjectList*self,RenderContextView*context,void*camera,RenderEntryList*entries){
    int mask=(0x20<<context->view())|1;
    RenderMaterialView*material;
    RenderGeometryView*geometry;
    int i;
    int count=self->count;
    RenderObjectView**objects=self->objects;
    for(i=0;i<count;++i){
        RenderObjectView*object=*objects++;
        if(object->flags120&0x10000)continue;
        material=(RenderMaterialView*)object->material.get();
        if(material &&(mask&material->flags0C))continue;
        geometry=(RenderGeometryView*)object->geometry.get();
        context->object=object;
        context->matrix20=product(context->matrix60,*object->matrix124);
        context->object14=object->handle24.get();
        context->object18=object->handle28.get();
        context->fieldBCC=0;
        if(!(geometry->flags6E&0x40) &&fn_8026C094(camera,&context->matrix20,geometry->bounds,&context->field1C,&context->sphereA0)){
            if(geometry->sphere70){
                RenderSphere sphere;
                fn_80099A00(&sphere,&context->matrix20,geometry->sphere70);
                selectEntries(context,sphere,entries);
            }else selectEntries(context,context->sphereA0,entries);
            geometry->slot20(context,material);
        }
        if(material &&!(material->flags0C&0x80)){
            if(material->slot38(object,camera,context))material->slot34(context);
        }
    }
}
// Views describe only the bytes observed by this traversal.
typedef char CheckRenderEntrySize[sizeof(RenderEntry)==0x20?1:-1];
typedef char CheckRenderObjectSize[sizeof(RenderObjectView)==0x128?1:-1];
typedef char CheckRenderContextSize[sizeof(RenderContextView)==0xBD0?1:-1];
typedef char CheckRenderObjectListSize[sizeof(RenderObjectList)==0x4078?1:-1];
