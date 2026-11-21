#ifndef GAME_ENGINE_OWNER_SPATIAL_APPLY_H
#define GAME_ENGINE_OWNER_SPATIAL_APPLY_H

typedef unsigned long SpatialApplyWord;
struct SpatialApplyHandle{signed int generation:8,index:24;};
struct SpatialApplyVec3{float x,y,z;SpatialApplyVec3(){}SpatialApplyVec3(float a,float b,float c):x(a),y(b),z(c){}SpatialApplyVec3(const SpatialApplyVec3&v):x(v.x),y(v.y),z(v.z){}void operator=(const SpatialApplyVec3&v){x=v.x;y=v.y;z=v.z;}SpatialApplyVec3 operator+(const SpatialApplyVec3&v)const{return SpatialApplyVec3(x+v.x,y+v.y,z+v.z);}};
struct SpatialApplySphere{SpatialApplyVec3 center;float radius;};
struct SpatialApplyBounds{SpatialApplyVec3 min,max;};
struct SpatialApplyMatrix{float a[16];SpatialApplyVec3 transform(const SpatialApplyVec3&v)const{float X=a[0]*v.x+a[4]*v.y+a[8]*v.z+a[12];float Y=a[1]*v.x+a[5]*v.y+a[9]*v.z+a[13];float Z=a[2]*v.x+a[6]*v.y+a[10]*v.z+a[14];return SpatialApplyVec3(X,Y,Z);}};
struct SpatialApplyRecord{SpatialApplyVec3 position;float unknown0C;SpatialApplyVec3 direction;};
struct SpatialApplyOutput{SpatialApplyVec3 position,direction;float scalar;};
struct SpatialApplyResource{char unknown00[0x7C];SpatialApplyVec3*position;char unknown80[0x20];SpatialApplyBounds*bounds;};
struct SpatialApplyEntry{SpatialApplyResource*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct SpatialApplyManager{char unknown00[8];SpatialApplyEntry*entries;};
struct SpatialApplyMatrixPool{SpatialApplyMatrix*pages[6];unsigned char active;};
extern "C"{extern struct{char unknown00[0x118];SpatialApplyManager*manager;char unknown11C[0x18];SpatialApplyMatrixPool*pool;}lbl_801E9D24;void fn_801F230C(const SpatialApplyMatrix*,SpatialApplyMatrix*);float fn_800A8E8C(float,float,float);void fn_801F0C68(SpatialApplySphere*,const SpatialApplyVec3*,int);extern const float lbl_8037B418,lbl_8037B41C,lbl_8037B420,lbl_8037B424;}
struct SpatialApplyObject{char unknown00[0x1C];SpatialApplyHandle resource;char unknown20[0x100];SpatialApplyWord flags;SpatialApplyMatrix*matrix,*inverse;short unknown12C,index;SpatialApplyMatrix*getMatrix(){if(flags&0x20){inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+index;fn_801F230C(matrix,inverse);flags&=~0x20;}return inverse;}};
struct SpatialApplyStorage{char unknown00[8];};struct SpatialApplyOwner:SpatialApplyStorage{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual SpatialApplySphere*getSphere();
char unknown0C[0x20];unsigned short*status;char unknown30[8];SpatialApplyOutput*output;
};

typedef char SpatialApplyVec3Size[sizeof(SpatialApplyVec3)==12?1:-1];
typedef char SpatialApplyRecordSize[sizeof(SpatialApplyRecord)==28?1:-1];
typedef char SpatialApplyOutputSize[sizeof(SpatialApplyOutput)==28?1:-1];
typedef char SpatialApplyMatrixSize[sizeof(SpatialApplyMatrix)==64?1:-1];
extern "C" void fn_80248D20(SpatialApplyOwner*,SpatialApplyObject*,const SpatialApplyVec3*,const SpatialApplyRecord*);
#endif
