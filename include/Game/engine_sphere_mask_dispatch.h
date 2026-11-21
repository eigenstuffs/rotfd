#ifndef GAME_ENGINE_SPHERE_MASK_DISPATCH_H
#define GAME_ENGINE_SPHERE_MASK_DISPATCH_H

typedef unsigned long MaskSphereWord;
typedef unsigned long long MaskSphereFlags;
struct MaskSpherePoint {
    float x, y, z;
    MaskSpherePoint() {}
    MaskSpherePoint(float a,float b,float c):x(a),y(b),z(c){}
    MaskSpherePoint(const MaskSpherePoint& p):x(p.x),y(p.y),z(p.z){}
    MaskSpherePoint operator-(const MaskSpherePoint& p) const {
        return MaskSpherePoint(x-p.x,y-p.y,z-p.z);
    }
    float lengthSquared() const { return x*x+y*y+z*z; }
};
struct MaskSphere {
    MaskSpherePoint center;
    float radius;
    MaskSphere(const MaskSphere& s):center(s.center),radius(s.radius){}
};
struct MaskSphereMatrix { float data[16]; };
struct MaskSphereMatrixPool { MaskSphereMatrix* pages[6]; unsigned char active; };
struct MaskSphereGlobal { char unknown00[0x134]; MaskSphereMatrixPool* pool; };
extern "C" {
extern MaskSphereGlobal lbl_801E9D24;
void fn_801F230C(const MaskSphereMatrix*,MaskSphereMatrix*);
MaskSphere fn_80099A00(const MaskSphereMatrix*,const MaskSphere*);
}
// Partial views: only offsets used by the original dispatcher are modeled.
struct MaskSphereObject {
    char unknown00[0x120];
    MaskSphereWord flags;
    MaskSphereMatrix* matrix;
    MaskSphereMatrix* inverse;
    short unknown12C,index;
    MaskSphereMatrix* getInverse() {
        if(flags&0x20) {
            inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+index;
            fn_801F230C(matrix,inverse);
            flags&=~0x20;
        }
        return inverse;
    }
};
struct MaskSphereOwner {
    char unknown00[0xC];
    MaskSphere bounds;
    char unknown1C[0x58];
    void *a0,*a1,*a2,*a3;
    void *b0,*b1,*b2;
    void *c0,*c1,*c2;
    void *d0,*d1,*d2;
};
struct MaskSphereInfo { char unknown00[0xC]; MaskSphereWord flags; };
struct MaskSphereCollector { char unknown00[0x2800]; void* record; };
extern "C" {
void fn_801E059C(const MaskSphere*,void*,MaskSphereCollector*,MaskSphereFlags);
void fn_801DFE90(const MaskSphere*,void*,MaskSphereCollector*,MaskSphereFlags);
void fn_801E0BA4(const MaskSphere*,void*,MaskSphereCollector*,MaskSphereFlags);
int fn_801DC718(MaskSphereCollector*,void*,MaskSphereObject*);
int fn_80244710(MaskSphereOwner*,MaskSphereObject*,const MaskSphereInfo*,const MaskSphere*,MaskSphereCollector*,MaskSphereFlags);
}
typedef char MaskSphereSize[sizeof(MaskSphere)==16?1:-1];
typedef char MaskSpherePointSize[sizeof(MaskSpherePoint)==12?1:-1];
#endif
