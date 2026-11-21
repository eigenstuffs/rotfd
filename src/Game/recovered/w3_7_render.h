// shared renderer/model views for w3_7 pending units (types from renderer_model_light_draw_8027C4D8.cpp)
#ifndef W3_7_RENDER_H
#define W3_7_RENDER_H
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
inline float fastSqrt(register float x,register float zero){register float r=zero;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 float lengthSquared()const{return x*x+y*y+z*z;}float length(float zero)const{return fastSqrt(lengthSquared(),zero);}};
inline Vec3 operator-(const Vec3&a,const Vec3&b){return Vec3(a.x-b.x,a.y-b.y,a.z-b.z);}
struct Row{float x,y,z;Row(float a,float b,float c):x(a),y(b),z(c){}
 float dot(const Row&v)const{return x*v.x+y*v.y+z*v.z;}
 float length(float zero)const{return fastSqrt(dot(*this),zero);}};
struct Matrix{float m[4][4];Row column(int i)const{return Row(m[0][i],m[1][i],m[2][i]);}
 const Vec3&translation()const{return *(const Vec3*)m[3];}};
inline Vec3 transformPoint(const Matrix*m,const Vec3&p){
 return Vec3(m->m[0][0]*p.x+m->m[1][0]*p.y+m->m[2][0]*p.z+m->m[3][0],
  m->m[0][1]*p.x+m->m[1][1]*p.y+m->m[2][1]*p.z+m->m[3][1],
  m->m[0][2]*p.x+m->m[1][2]*p.y+m->m[2][2]*p.z+m->m[3][2]);}
struct Handle{signed int tag:8,index:24;};
struct MatrixPool{Matrix*banks[6];u8 active18;};
struct Parent{char unknown00[0x74];Vec3 color74;float unknown80;float range84;float radius88;};
struct Resource{
 char unknown00[0x1C];
 Handle parent1C;
 char unknown20[4];
 Handle handle24;
 char unknown28[0xF8];
 u32 flags120;
 Matrix*local124;
 Matrix*world128;
 char unknown12C[2];
 short index12E;
 Matrix*getWorld();
};
struct Texture{char unknown00[0x3F];u8 format3F;};
struct Material{char unknown00[0x18];float alpha18;char unknown1C[0x4C];u32 flags68;char unknown6C[8];Handle texture74;};
struct Mesh{char unknown00[0xB8];Handle materialB8;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];MatrixPool*pool;};
extern "C"{
extern Global lbl_801E9D24;
extern const float lbl_8037B790,lbl_8037B79C,lbl_8037B7A8;
extern const double lbl_8037B7A0;
}
inline void*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];return e->tag==h.tag?e->object:0;}
struct Mesh;struct Material;struct MeshEntry{Mesh*object;char unknown04[8];signed char tag;char unknown0D[3];};struct MeshManager{int count,capacity;MeshEntry*entries;};
struct MaterialEntry{Material*object;char unknown04[8];signed char tag;char unknown0D[3];};struct MaterialManager{int count,capacity;MaterialEntry*entries;};
inline Mesh*resolveMesh(const Handle&h){MeshEntry*e=&((MeshManager*)lbl_801E9D24.manager)->entries[h.index];return e->tag==h.tag?e->object:0;}
inline Material*resolveMaterial(const Handle&h){int index=h.index;MaterialManager*m=(MaterialManager*)lbl_801E9D24.manager;int tag=m->entries[index].tag;return tag==h.tag?m->entries[index].object:0;}
extern "C" void fn_801F230C(const Matrix*,Matrix*);
inline Matrix*Resource::getWorld(){
 if(flags120&0x20){MatrixPool*p=lbl_801E9D24.pool;world128=p->banks[p->active18]+index12E;fn_801F230C(local124,world128);flags120&=~0x20;}
 return world128;}
inline float getScale(const Matrix*m){Row c=m->column(0);return c.length(lbl_8037B790);}
struct Handle_801F7F10{u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct LightZero:Handle_801F7F10{LightZero(){word=0;}~LightZero(){}};
struct LightZero2:LightZero{LightZero2(){word=0;}~LightZero2(){}};
extern "C" void fn_801F86C8(Manager*,const void*,int);
struct LightCopy:LightZero2{LightCopy(const Handle&h){word=*(const u32*)&h;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~LightCopy(){}};
inline void*resolve(const Handle_801F7F10&h){return resolve(*(const Handle*)&h);}
struct Bounds;struct LightRec{Vec3 pos;float radius;Vec3 color;float rangeSq;float unknown20;inline bool reaches(const Bounds*b)const;};
struct Bounds{Vec3 center;float radius;char unknown10[0x58];};
inline bool LightRec::reaches(const Bounds*b)const{float r=radius*lbl_8037B7A0;float limit=r+b->radius;return (pos-b->center).lengthSquared()<limit*limit;}
struct BoundsArray{int count,capacity;Bounds*data;};
struct State{u16 slot;u16 lod;u16 getLod()const{return lod;}};
struct StateArray{int count,capacity;State*data;};
struct Cone{char unknown00[0x24];};
struct PartRecord{char unknown00[0x64];Cone cone64;Handle mesh88;char unknown8C[4];const Cone*cone()const{const PartRecord*self=this;return &self->cone64;}};
struct DisplayList{void*data;u32 capacity;u32 size;};
struct VertexBuffer{void*positions;void*normals;void*colors;void*texcoords;};
struct DrawRecord{u16 flags;u16 next;DisplayList*list;VertexBuffer*buffer;Material*material;float mtx[3][4];Matrix matrix;void*x80;void*x84;Vec3 fog;float depth94;char unknown98[0x10];};
struct Context{char unknown00[0x2D0];u16 flags2D0;u16 flags2D2;char unknown2D4[0xD8];DrawRecord*records3AC;int count3B0;DisplayList lists3B4[3];};
struct Record0{char unknown00[0x48];Context*context48;};
struct Owner8{char unknown00[0x74];Vec3 eye74;char unknown80[0x38];float rangeB8;};
struct Fog{char unknown00[0x74];Vec3 color74;signed char enabled80;};
struct CacheNode{char unknown00[8];u16 prev;u16 next;};
struct CacheBase{char unknown00[8];CacheNode*nodes;int stride;VertexBuffer*buffers;};
struct Cache:CacheBase{virtual u16 allocate(Handle*,u16);
 void touch(int n){n=n;nodes[nodes[n].prev].next=nodes[n].next;nodes[nodes[n].next].prev=nodes[n].prev;nodes[n].next=nodes[0].next;nodes[n].prev=0;nodes[nodes[0].next].prev=n;nodes[0].next=n;}
 VertexBuffer*buffer(int slot){return &buffers[slot*stride];}
 VertexBuffer*acquire(int slot){touch(slot+1);return buffer(slot);}};
struct Renderer{
 Record0*record0;
 char unknown04[4];
 Owner8*owner8;
 Resource*resC;
 Resource*res10;
 void*x14;
 Fog*fog18;
 u32 flags1C;
 Matrix m20;
 Matrix m60;
 Vec3 offsetA0;
 float distanceAC;
 char unknownB0[0x10];
 Resource*lights[64];
 int lightCount;
 LightRec lightRecs[64];
 int lightCountAC4;
 int activeAC8;
 char unknownACC[0xBCC-0xACC];
 int lodBCC;
 char unknownBD0[8];
 int valueBD8;
 int valueBDC;
 Cache*cacheBE0;
 Handle handleBE4;
};
struct Prefix{char unknown00[4];Handle handle04;};
struct Model:Prefix{
 virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();
 virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();
 virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();
 virtual void v50();virtual void v54();virtual void v58();virtual void v5C();
 char unknown0C[0x62];
 u16 flags6E;
 char unknown70[0xC];
 int value7C;
 char unknown80[0x24];
 int partCountA4;
 char unknownA8[4];
 PartRecord*partsAC;
 char unknownB0[0x14];
 int valueC4;
 char arrayC8[0x34];
 char arrayFC[0x14];
 int*indices110;
 int maxLod114;
};
struct Source{char unknown00[4];Handle handle04;char unknown08[0x1C];char array24[0xC];char array30[0xC];};
struct Global2{char unknown00[0x178];Cache*cache178;Cache*cache17C;};
extern "C"{
extern const float lbl_8037B794,lbl_8037B798;
void fn_801F7914(void*,const void*);
float fn_800A8E8C(float,float,float);
int fn_801CBC44(int,int,int);
void fn_801D890C(Model*,void*,int);
void fn_8027C720(Model*,Renderer*,Source*,BoundsArray*,StateArray*);
void fn_80272F14(Context*,const Matrix*);
void fn_8027FC80(Context*,void*,Matrix*,void*);
void fn_80272708(Context*,const Vec3*);
signed char fn_801E2370(Record0*,Bounds*,Vec3*,Matrix*,int*);
signed char fn_801F0980(const Cone*,const Vec3*);
u32 fn_801F7EB8(const Handle*);
void fn_8027F994(Context*,int,LightRec*,Matrix*,Resource*);
void fn_80270564(Model*,Renderer*,PartRecord*,VertexBuffer*,Material*);
void fn_802820B4(Renderer*,VertexBuffer*);
void fn_800F22F4(void*,u32);
void fn_800F2320(void*,u32);
void fn_80272968(Context*,Material*,int);
void fn_8027353C(Context*);
void GXSetZMode(int,int,int);
void GXSetZCompLoc(int);
void PPCSync();
void GXInvalidateVtxCache();
void GXSetArray(int,const void*,u8);
void GXCallDisplayList(const void*,u32);
void GXDrawDone();
}

#endif
