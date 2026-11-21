/* Viewport render preparation (fn_801E8274): runs the world's render callback,
 * caches the camera node/geometry and inverse view matrix, selects the visible
 * light entries, computes the camera footprint, dispatches render objects, and
 * draws the queued debug lines in view space.
 * The line transform stores into a local and returns it through a const
 * reference; that keeps each component a CSE temporary (the original FPR
 * allocation). fp_contract is enabled for this function only; the neighbouring
 * fn_801E7D1C was compiled without contraction.
 */
#pragma fp_contract on
typedef unsigned long u32;
struct Node_Z;
struct Entry {
    Node_Z* object;
    u32 unknown[2];
    signed char generation;
    char pad[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct MatrixBuffers;
struct Globals {
    char unknown0[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixBuffers* matrices;
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct OwnerHandle : Handle_801F7F10 {
    OwnerHandle() { value = 0; }
    Node_Z* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? m->entries[index].object : 0;
    }
};
struct Root_80207414 {
    u32 unknown0;
    Handle_801F7F10 identity;
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct ViewVec3 {
    float x,y,z;
    ViewVec3(){}
    ViewVec3(const ViewVec3&v):x(v.x),y(v.y),z(v.z){}
    ViewVec3&operator=(const ViewVec3&v){x=v.x;y=v.y;z=v.z;return *this;}
    ViewVec3(float a,float b,float c):x(a),y(b),z(c){}
};
struct ViewVec2 {float x,y;};
struct ViewMatrix {float m[4][4];
    ViewVec3 transform(const ViewVec3&v)const{
        ViewVec3 r;
        r.x=m[3][0]+(m[2][0]*v.z+(m[0][0]*v.x+m[1][0]*v.y));
        r.y=m[3][1]+(m[2][1]*v.z+(m[0][1]*v.x+m[1][1]*v.y));
        r.z=m[3][2]+(m[2][2]*v.z+(m[0][2]*v.x+m[1][2]*v.y));
        const ViewVec3&q=r;return q;
    }
};
extern "C" {void fn_801F1080(ViewMatrix*,const ViewMatrix*,ViewMatrix*);void fn_801F230C(const ViewMatrix*,ViewMatrix*);}
static inline ViewMatrix product(ViewMatrix&a,const ViewMatrix&b){ViewMatrix r;fn_801F1080(&a,&b,&r);return r;}
struct ViewHandleBase:OwnerHandle {ViewHandleBase(){value=0;}};
struct ViewHandle:ViewHandleBase {
    ViewHandle(){}
    ViewHandle(const OwnerHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~ViewHandle(){}
};
struct CallbackHandle:Handle_801F7F10 {
    CallbackHandle(const OwnerHandle&h){value=0;value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~CallbackHandle(){}
    Node_Z*get()const{
        int index=bits.index;Manager*m=lbl_801E9D24.manager;
        int generation=m->entries[index].getGeneration();
        return generation==bits.generation?m->entries[index].object:0;
    }
};
extern "C" {extern const ViewVec3 game_vec4_zero;extern const float lbl_8037A5BC;}
struct ViewSphere {ViewVec3 center;float radius;ViewSphere():center(game_vec4_zero),radius(lbl_8037A5BC){}};
struct ViewCamera {char unknown[0x48];ViewVec3 corners[8];};
struct ViewGeometry:Root_80207414 {char unknownC[0x68];ViewCamera camera;char unknown11C[12];float height128;
    ViewCamera* getCamera(){return &camera;}};
struct ViewNode {char unknown[0x1C];OwnerHandle geometry;char unknown20[0x100];u32 flags120;ViewMatrix*matrix124;ViewMatrix*inverse128;short field12C,index12E;};
struct MatrixBuffers {ViewMatrix* buffers[6];unsigned char current;};
static inline ViewMatrix& inverse(ViewNode*p){
    if(p->flags120&0x20){
        MatrixBuffers*b=lbl_801E9D24.matrices;
        p->inverse128=b->buffers[b->current]+p->index12E;
        fn_801F230C(p->matrix124,p->inverse128);
        p->flags120&=~0x20;
    }
    return *p->inverse128;
}
struct ViewLightGeometry:Root_80207414 {ViewSphere bounds;char unknown1C[0x64];signed char enabled;};
struct ViewEntry_801E8A88 {
    ViewSphere sphere;ViewNode*object;ViewLightGeometry*geometry;u32 unknown18,unknown1C;
    ViewEntry_801E8A88(){}
};
struct ViewEntryList {ViewEntry_801E8A88 entries[64];u32 count;ViewEntryList():count(0){}
    void append(const ViewEntry_801E8A88&e){if(count<64){entries[count]=e;++count;}}
};
struct ViewLine {ViewVec3 a,b;u32 color[4];};
struct ViewWorld {char unknown0[0x18];int count,capacity;OwnerHandle*data;char unknown24[0x10];char index34[0xDA00-0x34];int lineCount,lineCapacity;ViewLine*lines;};
struct ViewEngineBase {char unknown[0x278];};
struct ViewEngine:ViewEngineBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54(const ViewVec3&,const ViewVec3&,const u32*,int,int);
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0(const ViewHandle&);
};
struct ViewViewport {char unknown0[0x14];OwnerHandle camera;char unknown18[0x30];ViewEngine*engine;};
struct ViewContext {ViewViewport*viewport;u32 field4;ViewGeometry*geometry;ViewNode*node;char unknown10[0x50];ViewMatrix inverse60;};
struct ViewCallback:Root_80207414 {virtual void slot20(ViewViewport*);};
extern "C" {
CallbackHandle fn_801E8AB0(ViewWorld*);
void fn_80269F2C(ViewWorld*,ViewVec3*,void*);
signed char fn_8026C094(ViewCamera*,ViewMatrix*,void*,u32*,ViewSphere*);
float fn_800AA53C(float,float);float fn_800AA52C(float,float);
void fn_80266C78(void*,ViewVec2*,ViewVec2*);
void fn_801E7D1C(ViewWorld*,ViewContext*,ViewCamera*,ViewEntryList*);
extern const float lbl_8037A5B8,lbl_8037A5BC,lbl_8037A5C0;
extern const ViewVec3 game_vec4_zero;
}
extern "C" void fn_801E8274(ViewWorld*self,ViewContext*context){
    ViewViewport*viewport=context->viewport;
    ViewEngine*engine=viewport->engine;
    ViewCallback*callback=(ViewCallback*)fn_801E8AB0(self).get();
    if(callback)callback->slot20(viewport);
    context->node=(ViewNode*)viewport->camera.get();
    context->geometry=(ViewGeometry*)context->node->geometry.get();
    ViewCamera*camera=context->geometry->getCamera();
    context->inverse60=inverse(context->node);
    unsigned long mode;
    float height=context->geometry->height128;
    height-=((ViewNode*)viewport->camera.get())->matrix124->m[3][1];
    if(height>lbl_8037A5B8)fn_80269F2C(self,&camera->corners[0],&mode);
    else fn_80269F2C(self,&camera->corners[1],&mode);
    ViewEntryList entries;
    for(int i=0;i<self->count;++i){
        ViewEntry_801E8A88 entry;
        entry.object=(ViewNode*)self->data[i].get();
        entry.geometry=(ViewLightGeometry*)ViewHandle(entry.object->geometry).get();
        if(entry.geometry->enabled){
            ViewMatrix matrix=product(context->inverse60,*entry.object->matrix124);
            entry.geometry->bounds.radius+=lbl_8037A5C0;
            u32 flags;
            if(fn_8026C094(camera,&matrix,&entry.geometry->bounds,&flags,&entry.sphere))entries.append(entry);
            entry.geometry->bounds.radius-=lbl_8037A5C0;
        }
    }
    ViewVec2 lower,upper;
    lower.x=camera->corners[0].x;lower.y=camera->corners[0].z;
    upper.x=lower.x;upper.y=lower.y;
    int i;for(i=1;i<8;++i){
        lower.x=fn_800AA53C(lower.x,camera->corners[i].x);
        lower.y=fn_800AA53C(lower.y,camera->corners[i].z);
        upper.x=fn_800AA52C(upper.x,camera->corners[i].x);
        upper.y=fn_800AA52C(upper.y,camera->corners[i].z);
    }
    fn_80266C78(self->index34,&lower,&upper);
    fn_801E7D1C(self,context,camera,&entries);
    engine->slotA0(ViewHandle());
    const ViewMatrix&matrix=inverse((ViewNode*)viewport->camera.get());
    for(i=0;i<self->lineCount;++i){
        ViewLine&line=self->lines[i];
        engine->slot54(matrix.transform(line.a),matrix.transform(line.b),line.color,1,0);
    }
}
