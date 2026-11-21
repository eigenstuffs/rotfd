#ifndef GAME_ENGINE_OWNER_SPHERE_COLLECT_H
#define GAME_ENGINE_OWNER_SPHERE_COLLECT_H

typedef unsigned long SphereCollectWord;typedef unsigned long long SphereCollectFlags;
struct SphereCollectHandle{signed int generation:8,index:24;};
struct SphereCollectVec3{float x,y,z;SphereCollectVec3(){}SphereCollectVec3(float a,float b,float c):x(a),y(b),z(c){}SphereCollectVec3(const SphereCollectVec3&v):x(v.x),y(v.y),z(v.z){}void operator=(const SphereCollectVec3&v){x=v.x;y=v.y;z=v.z;}SphereCollectVec3 operator+(const SphereCollectVec3&v)const{return SphereCollectVec3(x+v.x,y+v.y,z+v.z);}SphereCollectVec3 operator-(const SphereCollectVec3&v)const{return SphereCollectVec3(x-v.x,y-v.y,z-v.z);}float lengthSquared()const{return x*x+y*y+z*z;}};
struct SphereCollectSphere{SphereCollectVec3 center;float radius;SphereCollectSphere(const SphereCollectVec3&v,float r):center(v),radius(r){}SphereCollectSphere(const SphereCollectSphere&s):center(s.center),radius(s.radius){}};
struct SphereCollectBounds{SphereCollectVec3 min,max;};struct SphereCollectMatrix{float a[16];};
struct SphereCollectResource{char unknown00[0x2C];unsigned short*status;};
struct SphereCollectMaterial{char unknown00[0x64];SphereCollectWord flags;char unknown68[4];SphereCollectWord type;};
struct SphereCollectEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct SphereCollectManager{char unknown00[8];SphereCollectEntry*entries;};struct SphereCollectMatrixPool{SphereCollectMatrix*pages[6];unsigned char active;};
extern "C"{extern struct{char unknown00[0x118];SphereCollectManager*manager;char unknown11C[0x18];SphereCollectMatrixPool*pool;}lbl_801E9D24;extern const SphereCollectVec3 game_vec4_zero;extern const float lbl_8037B410;void fn_801F230C(const SphereCollectMatrix*,SphereCollectMatrix*);SphereCollectSphere fn_80099A00(const SphereCollectMatrix*,const SphereCollectSphere*);void fn_801F0C68(SphereCollectSphere*,const SphereCollectVec3*,int);void fn_801DC784(void*,int,void*);}
struct SphereCollectObject{char unknown00[0x20];SphereCollectHandle resource;char unknown24[0xFC];SphereCollectWord flags;SphereCollectMatrix*matrix,*inverse;short unknown12C,index;SphereCollectMatrix*getMatrix(){if(flags&0x20){inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+index;fn_801F230C(matrix,inverse);flags&=~0x20;}return inverse;}};
struct SphereCollectOwner{char unknown00[0x74];int count,capacity;SphereCollectVec3*points;char unknown80[0x14];char*indicesBytes;char unknown98[8];SphereCollectBounds*bounds;char unknownA4[0x14];SphereCollectHandle*materials;};
struct SphereCollectResult{SphereCollectVec3 point;char unknown0C[0x10];int index;char unknown20[8];SphereCollectWord flags28,flags2C;char unknown30[4];SphereCollectOwner*owner;SphereCollectResource*resource;signed char enabled;char unknown3D[3];SphereCollectWord type;char unknown44[4];};
inline char*resolveSphereCollect(const SphereCollectHandle&h){int index=h.index;SphereCollectManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}

typedef char SphereCollectHandleSize[sizeof(SphereCollectHandle)==4?1:-1];
typedef char SphereCollectVec3Size[sizeof(SphereCollectVec3)==12?1:-1];
typedef char SphereCollectSphereSize[sizeof(SphereCollectSphere)==16?1:-1];
typedef char SphereCollectBoundsSize[sizeof(SphereCollectBounds)==24?1:-1];
typedef char SphereCollectResultSize[sizeof(SphereCollectResult)==72?1:-1];
extern "C" int fn_8024890C(SphereCollectOwner*,SphereCollectObject*,const SphereCollectSphere*,const void*,SphereCollectResult*,int,SphereCollectFlags);
#endif
