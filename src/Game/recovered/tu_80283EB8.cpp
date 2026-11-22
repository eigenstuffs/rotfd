struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
namespace p_sphere {
// Partial text split: fn_80283EB8 only. fn_8028437C after it (97.8%:
// callee-saved FPR order and induction registers) remains original code;
// its draft: scratch/claude_match/auto_03_80283EB8_text/wip_fn_8028437C_both.cpp.
// Sphere-marker quad builder (fn_80283EB8): for each enabled item, place a
// world matrix from the item's direction and radius and record a four-vertex
// GX display list. Only fn_80283EB8 of this original unit is reconstructed;
// fn_8028437C (the following function) is still outside this source.
//
// The 0.0/1.0/0.01 constants are referenced through their existing labels.
// They are declared without const so that each display-list write reloads
// them after the preceding volatile FIFO store, which reproduces the original
// literal-pool loads; the fastSqrt default reads through a const view.
typedef unsigned long Word;
typedef unsigned char Byte;
typedef unsigned short Half;
#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U32 (*(volatile Word*)0xCC008000)

inline float fastSqrt(register float x)
{
    register float r = 0.0f;
    if (x != r) {
        asm { frsqrte f4, x
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Quat {
    float x, y, z, w;
    Quat() {}
    Quat& operator=(const Quat& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix {
    float a[16];
    Vec3 transform(const Vec3& p) const {
        Vec3 r;
        r.x = a[12] + (a[8] * p.z + (a[0] * p.x + a[4] * p.y));
        r.y = a[13] + (a[9] * p.z + (a[1] * p.x + a[5] * p.y));
        r.z = a[14] + (a[10] * p.z + (a[2] * p.x + a[6] * p.y));
        return r;
    }
};
struct Handle { signed generation:8; signed index:24; };
struct Resource {
    char unknown00[0x120];
    Word flags120;
    Matrix* local124;
    Matrix* world128;
    char unknown12C[2];
    short index12E;
    Matrix* getWorld();
};
struct MatrixPool { Matrix* banks[6]; Byte active18; };
struct HandleHolder { char unknown00[0x280]; Handle handle; };
struct Manager;
struct Globals {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[0x14];
    HandleHolder* holder;
};
struct Buffer { void* data; Word capacity, size; };
struct ContextPrefix { char unknown00[0x278]; };
struct Context : ContextPrefix {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void apply(const Handle*);
    char unknown27C[0x54];
    Half flags2D0, flags2D2;
};
struct Model { char unknown00[0x48]; Context* context; };
struct RenderRecord {
    Model* model;
    char unknown04[8];
    Resource* resource;
    Resource* source;
};
struct SphereItem { Vec3 position; Vec3 direction; float radius; };
struct SphereOwner {
    char unknown00[0x2C];
    Half* flags;
    int count;
    char unknown34[4];
    SphereItem* items;
    Buffer buffer;
    int getCount() const { return count; }
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F230C(const Matrix*, Matrix*);
Quat fn_801F27BC(const Vec3*, const Vec3*);
void* memset(void*, int, unsigned long);
void fn_801F1D90(const Quat*, Matrix*);
void fn_801F2788(Matrix*, const Matrix*);
void fn_80272F14(Context*, const Matrix*);
void fn_801F86C8(Manager*, const void*, int);
void fn_8027353C(Context*);
void DCInvalidateRange(void*, Word);
void DCStoreRange(void*, Word);
void GXBeginDisplayList(void*, Word);
void GXResetWriteGatherPipe();
void GXBegin(int, int, unsigned short);
Word GXEndDisplayList();
void fn_8027210C(Context*, RenderRecord*, Buffer*, float);
}
inline Matrix* Resource::getWorld()
{
    Resource* r = this;
    if (r->flags120 & 0x20) {
        MatrixPool* p = lbl_801E9D24.pool;
        r->world128 = p->banks[p->active18] + r->index12E;
        fn_801F230C(r->local124, r->world128);
        r->flags120 &= ~0x20;
    }
    return r->world128;
}
struct SphereZero : Handle_801F7F10 {
    SphereZero() { word = 0; }
    ~SphereZero() {}
};
struct SphereCopy : SphereZero {
    SphereCopy(const Handle& source) {
        word = *(const Word*)&source;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    ~SphereCopy() {}
};

extern "C" void fn_80283EB8(SphereOwner* self, RenderRecord* record)
{
    int count;
    int i;
    Context* context;
    Matrix world;
    Matrix m;
    Quat q;
    Vec3 up(0.0f, 1.0f, 0.0f);
    if (!(record->source->flags120 & 0x80000)) return;
    context = record->model->context;
    count = self->getCount();
    for (i = 0; i < count; ++i) {
        Half f = self->flags[i];
        if (f & 8) continue;
        if (!(f & 0x20)) continue;
        m = *record->source->local124;
        world = *record->resource->getWorld();
        Vec3 p = m.transform(self->items[i].position);
        Vec3 col(m.a[0], m.a[4], m.a[8]);
        float sq = col.dot(col);
        float scale = fastSqrt(sq);
        float r = scale * self->items[i].radius;
        q = fn_801F27BC(&up, &self->items[i].direction);
        memset(&m, 0, sizeof(Matrix));
        m.a[0] = 1.0f;
        m.a[5] = 1.0f;
        m.a[10] = 1.0f;
        m.a[15] = 1.0f;
        fn_801F1D90(&q, &m);
        m.a[12] = p.x;
        m.a[13] = p.y;
        m.a[14] = p.z;
        fn_801F2788(&world, &m);
        fn_80272F14(context, &world);
        context->flags2D0 = 0;
        context->flags2D2 = 0xFFFF;
        {
            SphereCopy copy(lbl_801E9D24.holder->handle);
            context->apply((const Handle*)&copy);
        }
        context->flags2D0 |= 0x2000;
        fn_8027353C(context);
        DCInvalidateRange(self->buffer.data, self->buffer.capacity);
        GXBeginDisplayList(self->buffer.data, self->buffer.capacity);
        GXResetWriteGatherPipe();
        GXBegin(0x80, 1, 4);
        float n = -r;
        WGPIPE_F32 = n;
        WGPIPE_F32 = 0.01f;
        WGPIPE_F32 = n;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = 0.0f;
        WGPIPE_F32 = 0.0f;
        WGPIPE_F32 = r;
        WGPIPE_F32 = 0.01f;
        WGPIPE_F32 = n;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = 1.0f;
        WGPIPE_F32 = 0.0f;
        WGPIPE_F32 = r;
        WGPIPE_F32 = 0.01f;
        WGPIPE_F32 = r;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = 1.0f;
        WGPIPE_F32 = 1.0f;
        WGPIPE_F32 = n;
        WGPIPE_F32 = 0.01f;
        WGPIPE_F32 = r;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = 0.0f;
        WGPIPE_F32 = 1.0f;
        self->buffer.size = GXEndDisplayList();
        DCStoreRange(self->buffer.data, self->buffer.capacity);
        fn_8027210C(context, record, &self->buffer, 0.0f);
    }
}

}
#undef WGPIPE_F32
#undef WGPIPE_U32
namespace p_sprites {
// Textured sprite-quad batch (fn_8028437C): per enabled item, builds a facing
// basis from the item position, emits a 4-vertex display list with a clamped
// fog-plane colour and material-transformed texture coordinates.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U32 (*(volatile u32*)0xCC008000)
inline float fastSqrt(register float x,register float zero){register float r=zero;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
inline float rsqrt(register float x){register float r;asm{frsqrte r,x}return r;}
struct Vec2{float x,y;};
inline float sq(float f){return f*f;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 scaled(float f)const{return Vec3(x*f,y*f,z*f);}
 Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
 float lengthSq()const{return x*x+y*y+z*z;}
 Vec3&normalize(){float inv=rsqrt(sq(z)+(sq(x)+sq(y)));x*=inv;y*=inv;z*=inv;return *this;}};
struct Row{float x,y,z;Row(float a,float b,float c):x(a),y(b),z(c){}
 float dot(const Row&v)const{return x*v.x+y*v.y+z*v.z;}
 float length(float zero)const{return fastSqrt(dot(*this),zero);}};
struct Matrix{float m[4][4];const Vec3&row(int i)const{return *(const Vec3*)m[i];}Row column(int i)const{return Row(m[0][i],m[1][i],m[2][i]);}};
inline Vec3 mul0(const Vec3&v,float f){Vec3 r;r.x=v.x*f;r.y=v.y*f;r.z=v.z*f;return r;}
inline Vec3 cr0(const Vec3&a,const Vec3&b){Vec3 r;r.x=a.y*b.z-a.z*b.y;r.y=a.z*b.x-a.x*b.z;r.z=a.x*b.y-a.y*b.x;return r;}
inline void crI(Vec3&r,const Vec3&a,const Vec3&b){r.x=a.y*b.z-a.z*b.y;r.y=a.z*b.x-a.x*b.z;r.z=a.x*b.y-a.y*b.x;}
struct Handle{signed int tag:8,index:24;};
struct MatrixPool{Matrix*banks[6];u8 active18;};
struct Resource{char unknown00[0x120];u32 flags120;Matrix*local124;Matrix*world128;char unknown12C[2];short index12E;Matrix*getWorld();};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];MatrixPool*pool;};
struct DisplayList{void*data;u32 capacity;u32 size;};
struct Context{char unknown00[0x2D0];u16 flags2D0;u16 flags2D2;char unknown2D4[0x710];DisplayList*lists9E4;int count9E8;};
struct Record0{char unknown00[0x48];Context*context48;};
struct Fog{char unknown00[0x74];Vec3 color74;};
struct Ambient{char unknown00[0x84];Vec3 a84;char unknown90[0xC];Vec3 b9C;};
struct Renderer{Record0*record0;char unknown04[8];Resource*resC;Resource*res10;Ambient*x14;Fog*fog18;u32 flags1C;Matrix m20;char unknown60[0x48];float xA8;float xAC;};
struct Texture{char unknown00[0x3F];u8 format3F;};
struct Material{char unknown00[0x18];float alpha18;char unknown1C[0x10];float m2C,m30;char unknown34[4];float m38,m3C;char unknown40[4];float m44,m48;char unknown4C[0x1C];u32 flags68;char unknown6C[8];Handle texture74;};
struct Plane{float a,b,c,d;float dist(const Vec3&v)const{return d+(c*v.z+(a*v.x+b*v.y));}};
struct Sprites{char unknown00[0x74];int count74;char unknown78[4];Vec3*pos7C;char unknown80[0x14];int*mat94;char unknown98[8];Vec3*quadA0;char unknownA4[8];Vec2*uvAC;char unknownB0[0xC];u16 modeBC;char unknownBE[2];DisplayList listC0;};
struct Flags{char unknown00[0x2C];u16*flags2C;};
struct Scene{char unknown00[8];Handle*materials08;};
struct Color8{u8 r,g,b,a;};
extern "C"{
extern Global lbl_801E9D24;
extern char lbl_8028F698[];
void fn_801F230C(const Matrix*,Matrix*);
float fn_800A8E8C(float,float,float);
void fn_801F86C8(Manager*,const void*,int);
u32 fn_801F7EB8(const Handle*);
void fn_80282234(Renderer*,Plane*);
void fn_80272708(Context*,const Vec3*);
void fn_80272F14(Context*,const Matrix*);
void fn_80272968(Context*,Material*,int);
void fn_8027353C(Context*);
void*fn_8028FACC(void*,u32);
void fn_8027210C(Context*,Renderer*,DisplayList*,float);
void GXSetChanAmbColor(int,Color8);
void GXDrawDone();
void DCInvalidateRange(void*,u32);
void DCStoreRange(void*,u32);
void GXBeginDisplayList(void*,u32);
void GXResetWriteGatherPipe();
void GXBegin(int,int,u16);
u32 GXEndDisplayList();
void GXCallDisplayList(const void*,u32);
}
inline Matrix*Resource::getWorld(){
 if(flags120&0x20){MatrixPool*p=lbl_801E9D24.pool;world128=p->banks[p->active18]+index12E;fn_801F230C(local124,world128);flags120&=~0x20;}
 return world128;}
inline void*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];return e->tag==h.tag?e->object:0;}
inline float getScale(const Matrix*m){Row c=m->column(0);return c.length(0.0f);}
struct RefZero:Handle_801F7F10{RefZero(){word=0;}~RefZero(){}};
struct Ref:RefZero{Ref(){word=0;}~Ref(){}
 void set(const Handle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=*(const u32*)&h;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 void*get()const{return resolve(*(const Handle*)this);}};
inline signed char isTranslucent(Material*m){
 if(fn_801F7EB8(&m->texture74)&&((Texture*)resolve(m->texture74))->format3F==2)return 1;
 if(m->alpha18<1.0f)return 1;
 if(m->flags68&8)return 1;
 return 0;}
#define needsSort(m) ((m)->alpha18<1.0f||isTranslucent(m))
inline Vec3&posAt(Sprites*s,int i){return s->pos7C[i];}
inline Vec2&uvAt(Sprites*s,unsigned i){return s->uvAC[i];}
inline void xfUV(Vec2&r,const Material*m,const Vec2&v){float a=m->m44+(m->m2C*v.x+m->m38*v.y);a=a;float b=m->m48+(m->m30*v.x+m->m3C*v.y);r.x=a;r.y=b;}
inline void vertex3(float v,float u,u32 c,float z,float y,float x){x=x;WGPIPE_F32=x;WGPIPE_F32=y;WGPIPE_F32=z;WGPIPE_U32=c;WGPIPE_F32=u;WGPIPE_F32=v;}
extern "C" void fn_8028437C(Sprites*self,Renderer*r,Flags*flagsSrc,Scene*scene){
    struct MatBox{Material*m;};Resource*res;u32 col;Matrix*world;MatBox mb;Context*ctx;int i;Ambient*amb;Handle*mh;DisplayList*dl;
    float scale=getScale(r->res10->local124);
    res=r->resC;
    ctx=r->record0->context48;
    amb=r->x14;
    world=res->getWorld();
    Ref ref;
    Vec3 sum=(amb->b9C+amb->a84).scaled(255.0f);
    Color8 c8;
    c8.r=(int)fn_800A8E8C(sum.x,0.0f,255.0f);
    c8.g=(int)fn_800A8E8C(sum.y,0.0f,255.0f);
    c8.b=(int)fn_800A8E8C(sum.z,0.0f,255.0f);
    GXSetChanAmbColor(1,c8);
    int count;u16 flags=0x40;
    Plane plane;
    fn_80282234(r,&plane);
    if(r->fog18){
        fn_80272708(ctx,&r->fog18->color74);
        flags|=0x8000;
    }
    float depth=r->xA8+r->xAC;
    GXDrawDone();
    count=self->count74;
    for(i=0;i<count;i++){
        if(flagsSrc->flags2C[i]&8)continue;
        Vec3 p;p.x=r->m20.m[3][0]+(r->m20.m[2][0]*posAt(self,i).z+(r->m20.m[0][0]*posAt(self,i).x+r->m20.m[1][0]*posAt(self,i).y));p.y=r->m20.m[3][1]+(r->m20.m[2][1]*posAt(self,i).z+(r->m20.m[0][1]*posAt(self,i).x+r->m20.m[1][1]*posAt(self,i).y));p.z=r->m20.m[3][2]+(r->m20.m[2][2]*posAt(self,i).z+(r->m20.m[0][2]*posAt(self,i).x+r->m20.m[1][2]*posAt(self,i).y));
                col=(u32)fn_800A8E8C(plane.dist(*(const Vec3*)(const float*)&posAt(self,i)),0.0f,255.0f);
        mh=&scene->materials08[self->mat94[i]];
        ref.set(*mh);
        Entry*e=&lbl_801E9D24.manager->entries[((Handle*)&ref)->index];mb.m=(Material*)(e->tag==((Handle*)&ref)->tag?e->object:0);
#define mat mb.m

        if(mat->flags68&1)continue;
        Vec2 tc[4];
        xfUV(tc[1],mat,uvAt(self,i*4));
        xfUV(tc[0],mat,uvAt(self,i*4+1));
        xfUV(tc[3],mat,uvAt(self,i*4+3));
        xfUV(tc[2],mat,uvAt(self,i*4+2));
        Vec3 rx,ry,rz;
        Vec3 up;up.x=0.0f;up.y=0.0f;up.z=0.0f;
        if(self->modeBC==0){
            ry=world->row(1);
            ry.y*=scale;ry.z*=scale;ry.x*=scale;
            rx.x=0.0f;rx.y=0.0f;rx.z=0.0f;
            Vec3 c=cr0(p,ry).normalize();
            crI(rz,c,ry);
            float inv=rsqrt(rz.lengthSq());
            rz.x*=inv;rz.y*=inv;rz.z*=inv;
            rx=mul0(c,scale);
            rz.x*=-scale;rz.y*=-scale;rz.z*=-scale;
        }else{
            rz=mul0(p,rsqrt(p.lengthSq()));
            rz.x*=scale;rz.y*=scale;rz.z*=scale;
            up=world->row(1);rx.x=up.y*rz.z-up.z*rz.y;rx.y=up.z*rz.x-up.x*rz.z;rx.z=up.x*rz.y-up.y*rz.x;
            float inv=rsqrt(rx.lengthSq());
            rx.x*=inv;rx.y*=inv;rx.z*=inv;
            ry=cr0(rz,rx);
            rx.x*=scale;rx.y*=scale;rx.z*=scale;
        }
        Matrix mm;
        mm.m[0][0]=rx.x;mm.m[0][1]=rx.y;mm.m[0][2]=rx.z;mm.m[0][3]=0.0f;
        mm.m[1][0]=ry.x;mm.m[1][1]=ry.y;mm.m[1][2]=ry.z;mm.m[1][3]=0.0f;
        mm.m[2][0]=rz.x;mm.m[2][1]=rz.y;mm.m[2][2]=rz.z;mm.m[2][3]=0.0f;
        mm.m[3][0]=p.x;mm.m[3][1]=p.y;mm.m[3][2]=p.z;mm.m[3][3]=1.0f;
        Vec3 q[4];
        const Vec3&qa=self->quadA0[(unsigned)(i*2L)];
        const Vec3&qb=self->quadA0[(unsigned)(i*2L+1)];
        q[0].x=qa.x;q[0].y=qa.y;q[0].z=qa.z;
        q[1].x=-qa.x;q[1].y=qa.y;q[1].z=qa.z;
        q[3].x=qb.x;q[3].y=qb.y;q[3].z=qb.z;
        q[2].x=-qb.x;q[2].y=qb.y;q[2].z=qb.z;
        ctx->flags2D0=0;
        ctx->flags2D2=0xFFFF;
        fn_80272F14(ctx,&mm);
        fn_80272968(ctx,mat,5);
        ctx->flags2D0|=flags;
        fn_8027353C(ctx);
        if(needsSort(mat)){
            dl=&ctx->lists9E4[ctx->count9E8++];
            dl->capacity=0xA0;
            dl->data=fn_8028FACC(lbl_8028F698,dl->capacity);
        }else dl=&self->listC0;
        DCInvalidateRange(dl->data,dl->capacity);
        GXBeginDisplayList(dl->data,dl->capacity);
        GXResetWriteGatherPipe();
        GXBegin(0x98,1,4);
        for(int k=0;k<4;k++)vertex3(tc[k].y,tc[k].x,col,q[k].z,q[k].y,q[k].x);
        dl->size=GXEndDisplayList();
        DCStoreRange(dl->data,dl->capacity);
        if(needsSort(mat))fn_8027210C(ctx,r,dl,depth);
        else if(dl->data&&dl->capacity)GXCallDisplayList(dl->data,dl->size);
    }
}

}
