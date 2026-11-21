// Billboard particle batch builder (fn_80283160).
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Matrix{float m[4][4];};
struct Handle{signed int tag:8,index:24;};
struct MatrixPool{Matrix*banks[6];u8 active18;};
struct Resource{
 char unknown00[0x1C];
 Handle parent1C;
 char unknown20[0x100];
 u32 flags120;
 Matrix*local124;
 Matrix*world128;
 char unknown12C[2];
 short index12E;
 Matrix*getWorld();
};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Pool;
struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];MatrixPool*pool;char unknown138[0x34];Pool*particles16C;char unknown170[0x10];Pool*links180;};
extern "C"{extern Global lbl_801E9D24;void fn_801F230C(const Matrix*,Matrix*);}
struct System;struct MaterialC;
struct SysEntry{System*object;char unknown04[8];signed char tag;char unknown0D[3];};struct SysManager{int count,capacity;SysEntry*entries;};
struct MatEntry{MaterialC*object;char unknown04[8];signed char tag;char unknown0D[3];};struct MatManager{int count,capacity;MatEntry*entries;};
inline System*resolveSystem(const Handle&h){SysEntry*e=&((SysManager*)lbl_801E9D24.manager)->entries[h.index];return e->tag==h.tag?e->object:0;}
inline MaterialC*resolveMaterial(const Handle&h){MatEntry*e=&((MatManager*)lbl_801E9D24.manager)->entries[h.index];return e->tag==h.tag?e->object:0;}
inline Matrix*Resource::getWorld(){
 if(flags120&0x20){MatrixPool*p=lbl_801E9D24.pool;world128=p->banks[p->active18]+index12E;fn_801F230C(local124,world128);flags120&=~0x20;}
 return world128;}
struct Manager2:Manager{Entry*at(int i){return &entries[i];}signed char tagOf(int i){return at(i)->tag;}void*get(const Handle&h){signed char t=tagOf(h.index);return t==h.tag?at(h.index)->object:0;}};
#define RES(h) ((Manager2*)lbl_801E9D24.manager)->get(h)
struct DisplayList{void*data;u32 capacity;u32 size;};
struct Context{char unknown00[0x2D0];u16 flags2D0;u16 flags2D2;char unknown2D4[0x710];DisplayList*lists9E4;int count9E8;};
struct Record0{char unknown00[0x48];Context*context48;};
struct Owner8{char unknown00[0x74];Vec3 eye74;};
struct Renderer{Record0*record0;char unknown04[4];Owner8*owner8;Resource*resC;Resource*res10;void*x14;void*fog18;u32 flags1C;char unknown20[0x88];float xA8;float xAC;};
struct Material;struct Bounds;
extern "C"{
void fn_80272968(Context*,Material*,int);
void fn_8027353C(Context*);
signed char fn_801E2370(Record0*,Bounds*,Vec3*,Matrix*,int*);
}
#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U8 (*(volatile u8*)0xCC008000)
struct Vec2{float x,y;};
struct Color8{u8 r,g,b,a;Color8(){}Color8(u8 r_,u8 g_,u8 b_,u8 a_):r(r_),g(g_),b(b_),a(a_){}};
struct ColorF{float r,g,b,a;};
struct Particle{char unknown00[0xC];float x0C;char unknown10[4];float x14;char unknown18[8];float angle20;char unknown24[0x40];ColorF color64;Vec3 pos74;float w80;float h84;short unknown88;short next8A;};
struct Link{short previous,next;};
struct ParticleRecord{Particle*base;int status;short w08,w0A,w0C,w0E,w10,w12;float value14;};
struct LinkRecord{Link*links;int status;short first08,last0A,count0C,free0E,freeLast10,freeCount12;float value14;
 void take(){
  if(freeCount12==0)return;
  short n=free0E;
  if(freeCount12==1){free0E=freeLast10=-1;}
  else free0E=links[n].next;
  if(count0C==0){links[n].previous=-1;links[n].next=-1;first08=last0A=n;}
  else{links[n].previous=last0A;links[n].next=-1;links[last0A].next=n;last0A=n;}
  count0C++;freeCount12--;
 }};
struct RecIndex{int index;RecIndex():index(-1){}RecIndex(int i):index(i){}};
struct Pool{inline ParticleRecord*get(RecIndex i);inline LinkRecord*find(const RecIndex&i,signed char*c);};
struct Group{char unknown00[0x10];short first10;short count12;};
struct Emitter{char unknown00[0x20];int index20;int count24;int capacity28;Group*groups2C;char unknown30[4];int index34;};
struct System{char unknown00[0xB4];u32 flagsB4;char unknownB8[0xD0];Handle material188;};
struct MaterialC{char unknown00[0xC];ColorF color0C;};
extern "C"{
extern const float lbl_8037B810,lbl_8037B814,lbl_8037B818;
extern Vec2 lbl_8035D360[4];
extern Vec2 lbl_8035D380[4];
extern char lbl_8028F698[];
ParticleRecord*fn_80283954(Pool*,const RecIndex&);
LinkRecord*fn_802839B4(Pool*,const RecIndex&,signed char*);
void fn_80284DB0(Emitter*,Renderer*);
float fn_80284FA8(float);
float fn_8028506C(float);
void*fn_8028FACC(void*,u32);
void GXSetCurrentMtx(u32);
void GXSetChanAmbColor(int,Color8);
void DCInvalidateRange(void*,u32);
void DCStoreRange(void*,u32);
void GXBeginDisplayList(void*,u32);
void GXResetWriteGatherPipe();
void GXBegin(int,int,u16);
u32 GXEndDisplayList();
void fn_8027210C(Context*,Renderer*,DisplayList*,float);
}
inline ParticleRecord*Pool::get(RecIndex i){return fn_80283954(this,i);}
inline LinkRecord*Pool::find(const RecIndex&i,signed char*c){return fn_802839B4(this,i,c);}
inline void color4(u32 r,u32 g,u32 b,u32 a){WGPIPE_U8=r;WGPIPE_U8=g;WGPIPE_U8=b;WGPIPE_U8=a;}
struct V3{float x,y,z;V3(){}V3(float a,float b,float c):x(a),y(b),z(c){}
 V3 operator+(const V3&o)const{return V3(x+o.x,y+o.y,z+o.z);}
};
inline V3 operator*(const V3&v,float f){return V3(v.x*f,v.y*f,v.z*f);}
inline float reciprocalSqrt(register float x){register float r;asm{frsqrte r,x}return r;}
inline bool feq(float a,float b){return a==b;}
#define ZERO 0.0f
#define ONE 1.0f
#define C255 255.0f
extern "C" void fn_80283160(Emitter*self,Renderer*r){
    Matrix m;int tmp;Color8 amb;System*sys;Resource*res;Particle*base;Vec3*eye;Context*ctx;int cr;int cg;int cb;int ca;Group*g;int count;int n;int i;short idx;signed char check;MaterialC*mat;DisplayList*dl;signed char changed;
    int id=self->index20;
    Pool*pool=lbl_801E9D24.particles16C;
    ParticleRecord*rec=pool->get(id);
    if(!rec)return;
    base=rec->base;
    int id2=self->index34;
    Pool*pool2=lbl_801E9D24.links180;
    LinkRecord*lr=pool2->find(id2,&changed);
    if(!lr)return;
    if(changed)lr->take();
    fn_80284DB0(self,r);
    eye=&r->owner8->eye74;
    ctx=r->record0->context48;
    sys=(System*)RES(r->res10->parent1C);
    mat=(MaterialC*)RES(sys->material188);
    ctx->flags2D0=0;
    ctx->flags2D2=0xFFFF;
    fn_80272968(ctx,(Material*)mat,4);
    ctx->flags2D0|=0x80;
    fn_8027353C(ctx);
    GXSetCurrentMtx(0x3C);
    amb.r=(u8)(C255*mat->color0C.r);amb.g=(u8)(C255*mat->color0C.g);amb.b=(u8)(C255*mat->color0C.b);amb.a=(u8)(C255*mat->color0C.a);
    GXSetChanAmbColor(4,amb);
    res=r->resC;
    m=*res->getWorld();
    u32 flags=sys->flagsB4;
    u32 b2=(flags>>1)&1;
    u32 b4=(flags>>2)&1;
#define f2 ((signed char)b2)
#define f4 ((signed char)b4)
    check=(flags&0x20)&&f2;
    V3 right,up;
    if(f2){
        right=V3(m.m[0][0],m.m[0][1],-m.m[0][2]);
        up=V3(m.m[2][0],m.m[2][1],-m.m[2][2]);
    }else if(f4){
        right=V3(ONE,ZERO,ZERO);
        up=V3(m.m[1][0],m.m[1][1],-m.m[1][2]);
    }else{
        right=V3(ONE,ZERO,ZERO);
        up=V3(ZERO,ONE,ZERO);
    }
    Group*first=self->groups2C;
    count=self->count24;
    g=first;
    if(count*first->count12==0)return;
    dl=&ctx->lists9E4[ctx->count9E8++];
    dl->capacity=(first->count12*(count*0x63)+0x3F)&~0x1F;
    dl->data=fn_8028FACC(lbl_8028F698,dl->capacity);
    DCInvalidateRange(dl->data,dl->capacity);
    GXBeginDisplayList(dl->data,dl->capacity);
    GXResetWriteGatherPipe();
    for(i=0;i<count;i++,g++){
        if(g->first10<0)break;
        tmp=0;
        if(r->flags1C&3){
            if(!fn_801E2370(r->record0,(Bounds*)g,eye,&m,&tmp))continue;
        }
        idx=g->first10;
        n=g->count12;
        while(n--!=0){
            Particle*p=&base[idx];
            idx=p->next8A;
            float s=fn_80284FA8(p->angle20);
            float c=fn_8028506C(p->angle20);
            Vec3 q=p->pos74;
            float x,y,z;
            z=-m.m[0][2]*q.x-m.m[1][2]*q.y-m.m[2][2]*q.z-m.m[3][2];
            if(!(z<ZERO))continue;
            x=m.m[3][0]+(m.m[2][0]*q.z+(m.m[0][0]*q.x+m.m[1][0]*q.y));
            y=m.m[3][1]+(m.m[2][1]*q.z+(m.m[0][1]*q.x+m.m[1][1]*q.y));
            cr=(int)(C255*p->color64.r);
            cg=(int)(C255*p->color64.g);
            cb=(int)(C255*p->color64.b);
            ca=(int)(C255*p->color64.a);
            V3 rr=right,uu=up;
 if(check&&feq(p->x0C,ZERO)&&feq(p->x14,ZERO)){float inv=reciprocalSqrt(p->x0C*p->x0C+p->x14*p->x14);}
            float w=p->w80;
            float h=p->h84;
            GXBegin(0x80,1,4);
            for(int k=0;k<4;k++){
                float dx=w*lbl_8035D360[k].x;
                float dy=h*lbl_8035D360[k].y;
                float a=dx*c+dy*s;
                float b=dy*c-dx*s;
                V3 cen(x,y,z);
                V3 v=cen+rr*a+uu*b;
                WGPIPE_F32=v.x;
                WGPIPE_F32=v.y;
                WGPIPE_F32=v.z;
                color4(cr&0xFF,cg&0xFF,cb&0xFF,ca&0xFF);
                WGPIPE_F32=lbl_8035D380[k].x;
                WGPIPE_F32=lbl_8035D380[k].y;
            }
        }
    }
    dl->size=GXEndDisplayList();
    DCStoreRange(dl->data,dl->capacity);
    fn_8027210C(ctx,r,dl,r->xA8+r->xAC);
}
