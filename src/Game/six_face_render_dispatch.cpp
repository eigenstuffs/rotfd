#include "Game/six_face_render_dispatch.h"

typedef unsigned int u32;
typedef unsigned char u8;
struct Handle {signed generation:8;signed index:24;};
struct Matrix {float value[16];};
struct Resource {
    char unknown00[0x1C];
    Handle parent1C;
    char unknown20[0x54];
    Matrix matrix74;
    char unknownB4[0x6C];
    u32 flags120;
    Matrix*local124;
    Matrix*world128;
    char unknown12C[2];
    short index12E;
    Matrix*getWorld();
    Matrix*getParentMatrix();
    Matrix*getLocal(){return local124;}
};
struct Entry {Resource*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct Manager {int count,capacity;Entry*entries;};
struct MatrixPool {Matrix*banks[6];u8 active18;};
struct WorldHandle {signed generation:8;signed index:24;};
struct WorldResource:Resource {};
struct WorldEntry {WorldResource*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct WorldManager {int count,capacity;WorldEntry*entries;};
struct ParentResource {char unknown00[0x74];Matrix matrix74;};
struct ParentEntry {ParentResource*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct ParentManager {int count,capacity;ParentEntry*entries;};
struct Globals {char unknown00[0x118];union{Manager*manager;ParentManager*parentManager;WorldManager*worldManager;};char unknown11C[0x18];MatrixPool*pool;};
struct ContextPrefix {char unknown00[0x278];};
struct Context:ContextPrefix {
    virtual void v00();virtual void v01();virtual void v02();virtual void v03();
    virtual void v04();virtual void v05();virtual void v06();virtual void v07();
    virtual void v08();virtual void v09();virtual void v10();virtual void v11();
    virtual void v12();virtual void v13();virtual void v14();virtual void v15();
    virtual void v16();virtual void v17();virtual void v18();virtual void v19();
    virtual void v20();virtual void v21();virtual void v22();virtual void v23();
    virtual void v24();virtual void v25();virtual void v26();virtual void v27();
    virtual void v28();virtual void v29();virtual void v30();virtual void v31();
    virtual void v32();virtual void v33();virtual void v34();virtual void v35();
    virtual void v36();virtual void v37();virtual void apply(const Handle*);
    char unknown27C[0x54];
    unsigned short flags2D0,flags2D2;
};
struct Buffer {void*data;u32 capacity,size;};
struct SixFaceRenderOwner {char unknown00[0x10];Handle handles10[6];float positions28[24];u32 unknown88;float uv8C[8];Buffer buffersAC[6];};
struct SixFaceRenderRecord {char unknown00[0x14];Handle handle14;char unknown18[0x30];Context*context48;};
extern "C" {
extern Globals lbl_801E9D24;
extern const float lbl_8037B6C8;
void fn_801F230C(const Matrix*,Matrix*);
void fn_80272F14(Context*,const Matrix*);
void GXInvalidateVtxCache();
void GXSetArray(int,const void*,u8);
signed char fn_80267748(SixFaceRenderOwner*,const Matrix*,const Matrix*,const Matrix*,u8);
void __ct__15Handle_801F7F10Fv(void*);
void __dt__15Handle_801F7F10Fv(void*,int);
void fn_801F86C8(Manager*,const Handle*,int);
void fn_8027353C(Context*);
void GXCallDisplayList(const void*,u32);
}
static inline Resource*resolve(const Handle&h)
{
    Entry*e=&lbl_801E9D24.manager->entries[h.index];
    if(e->generation==h.generation)return e->object;
    return 0;
}
static inline WorldResource*resolveWorld(const WorldHandle&h)
{
    WorldEntry*e=&((WorldManager*)lbl_801E9D24.manager)->entries[h.index];
    if(e->generation==h.generation)return e->object;
    return 0;
}
static inline ParentResource*resolveParent(const Handle&h)
{
    ParentEntry*e=&((ParentManager*)lbl_801E9D24.manager)->entries[h.index];
    if(e->generation==h.generation)return e->object;
    return 0;
}
inline Matrix*Resource::getWorld()
{
    Resource*r=this;
    if(r->flags120&0x20){
        MatrixPool*p=lbl_801E9D24.pool;
        r->world128=p->banks[p->active18]+r->index12E;
        fn_801F230C(r->local124,r->world128);
        r->flags120&=~0x20;
    }
    return r->world128;
}
inline Matrix*Resource::getParentMatrix()
{
    return &resolveParent(parent1C)->matrix74;
}
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct FaceZero_8027121C:Handle_801F7F10 {
    FaceZero_8027121C(){word=0;}
    ~FaceZero_8027121C(){}
};
struct FaceCopy_8027121C:FaceZero_8027121C {
    FaceCopy_8027121C(const Handle&source){
        word=*(const u32*)&source;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
    ~FaceCopy_8027121C(){}
};
extern "C" void fn_8027121C(SixFaceRenderOwner*self,SixFaceRenderRecord*record)
{
    Matrix*local;
    Matrix*transform;
    Matrix*parent;
    Context*context=record->context48;
    Matrix matrix=*resolveWorld(*(const WorldHandle*)&record->handle14)->getWorld();
    matrix.value[12]=lbl_8037B6C8;
    matrix.value[13]=lbl_8037B6C8;
    matrix.value[14]=lbl_8037B6C8;
    fn_80272F14(context,&matrix);
    GXInvalidateVtxCache();
    GXSetArray(9,self->positions28,12);
    GXSetArray(13,self->uv8C,8);
    parent=resolve(record->handle14)->getParentMatrix();
    transform=resolveWorld(*(const WorldHandle*)&record->handle14)->getWorld();
    local=resolve(record->handle14)->getLocal();
    for(int i=0;i<6;++i){
        if(fn_80267748(self,parent,local,transform,(u8)i)){
            context->flags2D0=0;
            context->flags2D2=0xFFFF;
            context->flags2D0|=0x100;
            {
                FaceCopy_8027121C copy(self->handles10[i]);
                context->apply((const Handle*)&copy);
            }
            fn_8027353C(context);
            Buffer*b=&self->buffersAC[i];
            if(b->data&&b->capacity)GXCallDisplayList(b->data,b->size);
        }
    }
}

typedef char SixFaceRenderHandleSize[sizeof(Handle)==4?1:-1];
typedef char SixFaceRenderMatrixSize[sizeof(Matrix)==64?1:-1];
typedef char SixFaceRenderEntrySize[sizeof(Entry)==16?1:-1];
typedef char SixFaceRenderContextFlags[((unsigned int)&((Context*)0)->flags2D0==0x2D0)?1:-1];
typedef char SixFaceRenderOwnerBuffers[((unsigned int)&((SixFaceRenderOwner*)0)->buffersAC==0xAC)?1:-1];
typedef char SixFaceRenderRecordContext[((unsigned int)&((SixFaceRenderRecord*)0)->context48==0x48)?1:-1];
