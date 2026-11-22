typedef unsigned int u32;
extern "C" {
extern const float lbl_8037A250; /* 0.0f */
extern const float lbl_8037A254; /* -1.0f */
extern const float lbl_8037A258; /* 1.0f */
extern const float lbl_8037A25C; /* -1.0e10f */
extern const float lbl_8037A260; /* 1.0e10f */
extern const float lbl_8037A264; /* 1.0e-6f */
extern const float lbl_8037A268; /* -0.0001f */
extern const float lbl_8037A26C; /* -1.0e-6f */
}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */
enum KFormEnum { KFormEnumMax = 0x7fffffff };
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))
#define K6(l) (*(const float*)(unsigned long)(const void*)&(l))
#define K7(l) (*(const float*)(long)(const void*)&(l))
#define K8(l) (*(const float*)(unsigned int)(const void*)&(l))
#define K9(l) (*(const float*)(int)(const void*)&(l))
#define K10(l) (*(const float*)(unsigned long)(const char*)&(l))
#define K11(l) (*(const float*)(unsigned long)(char*)&(l))
#define K12(l) (*(const float*)(unsigned long)(void*)&(l))
#define K13(l) (*(const float*)(unsigned long)(int*)&(l))
#define K14(l) (*(const float*)(KFormEnum)&(l))
#define K15(l) (*(const float*)(KFormEnum)(const void*)&(l))
#define K16(l) (*(const float*)(unsigned long)(const volatile void*)&(l))
#define K17(l) (*(const float*)(unsigned long)(volatile void*)&(l))

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(register float sq)
{
    register float r = K0(lbl_8037A250);
    if (sq != r) { asm { frsqrte f4, sq
          fres r, f4 } }
    return r;
}

inline float sqrtOrZeroK(float sq,float zero){float r=zero;if(sq!=r)r=fastSqrt(sq);return r;}

inline float reciprocalSqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

struct SegmentBoxVector { float x,y,z; SegmentBoxVector(){} SegmentBoxVector(float X,float Y,float Z):x(X),y(Y),z(Z){} SegmentBoxVector operator+(const SegmentBoxVector&r)const{return SegmentBoxVector(x+r.x,y+r.y,z+r.z);} SegmentBoxVector operator-(const SegmentBoxVector&r)const{return SegmentBoxVector(x-r.x,y-r.y,z-r.z);} SegmentBoxVector operator*(float r)const{return SegmentBoxVector(x*r,y*r,z*r);}
 SegmentBoxVector&operator=(const SegmentBoxVector&v){x=v.x;y=v.y;z=v.z;return *this;}
 float dot(const SegmentBoxVector&v)const{return x*v.x+y*v.y+z*v.z;}
 SegmentBoxVector cross(const SegmentBoxVector&v)const{return SegmentBoxVector(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}
 SegmentBoxVector crossQ(const SegmentBoxVector&v)const{float cy=z*v.x-x*v.z;float cz=x*v.y-y*v.x;float cx=y*v.z-z*v.y;return SegmentBoxVector(cx,cy,cz);}
 SegmentBoxVector crossR(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVector(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x);}
 SegmentBoxVector crossS(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=y*v.z-z*v.y;r.y=z*v.x-x*v.z;r.z=x*v.y-y*v.x;return r;}
 SegmentBoxVector crossP(const SegmentBoxVector&v)const{float cy=z*v.x-x*v.z;float cx=y*v.z-z*v.y;float cz=x*v.y-y*v.x;return SegmentBoxVector(cx,cy,cz);}
 SegmentBoxVector crossPs(float vx, float vy, float vz)const{return SegmentBoxVector(y*vz-z*vy,z*vx-x*vz,x*vy-y*vx);}
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=1.0f;}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,1.0f);}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,K0(lbl_8037A258));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,0.0f);}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*0.0f-v.z*1.0f,v.z*0.0f-v.x*0.0f,v.x*1.0f-v.y*0.0f,1.0f);}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);


inline SegmentBoxVertex crossVs(float x, float y, float z, const SegmentBoxVector& v){const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,K3(lbl_8037A258));}
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>0.000001f){float inv=1.0f/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };

/* w20: (region 2) up components held in named float locals (named locals get the lowest
   FPR vregs, so they are coloured after the CSE temps of *b, as in the target);
   crossPs takes them as scalars with no inline locals.  MISMATCH 114 -> 12.
   auto_03_801B679C_text: segment (with thickness) vs. wall quad spanned by the
   edge a-b and the direction `up`.  Same translation unit as
   segment_shape_collision_queries_801B602C.cpp (GC/1.3.2, -O4,p, fp_contract on). */
#ifndef CR
#define CR crossP
#endif
#define EPS 0.000001f

struct WallSegment { SegmentBoxVector position; float distance; SegmentBoxVector direction; float radius; };

/* w21: region-1 edge tests read up directly (CSE temps, created y,x,z at the
   second occurrence) so they are coloured before the region-2 *b / position
   temps; region 2 keeps named ux/uz.  Parameter orders found by enumeration. */
inline SegmentBoxVector crossSu(const SegmentBoxVector& s, float vy, float vx, float vz){return SegmentBoxVector(s.y*vz-s.z*vy,s.z*vx-s.x*vz,s.x*vy-s.y*vx);}
inline SegmentBoxVertex crossUs(float z, float x, float y, const SegmentBoxVector& v){const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,K2(lbl_8037A258));}
/* w21b: the original reads 0.0f/1.0f/1e-6f from the shared TU pool (lbl_8037A250/258/264,
   owned by the collision-query TU 0x801B5D50..).  Plain extern reads are CSE'd by the
   frontend (low vregs) where the pooled literals are only CSE'd by the backend (high vregs),
   which changes colouring.  Giving every compare site a distinct but equivalent read form
   (K0, K2..K10 casts of the address through integer types) keeps the frontend from merging
   them; the backend still merges the identical lfs loads -> same allocation as the literals. */
extern "C" bool fn_801B679C(const WallSegment* self, SegmentBoxVertex* a, SegmentBoxVertex* b, const SegmentBoxVertex* up, SegmentHit* out)
{
    out->normal = (*b - *a).SegmentBoxVector::cross(*up);
    float len = out->normal.magnitude();
    if (len <= K0(lbl_8037A264)) return 0;
    float inv = K0(lbl_8037A258) / len;
    out->normal.x *= inv;
    out->normal.y *= inv;
    out->normal.z *= inv;
    float d = -out->normal.dot(*a);
    float side = d + self->position.dot(out->normal);
    if (side < K2(lbl_8037A264)) {
        out->normal = -out->normal;
        d = -d;
        SegmentBoxVertex tmp = *a;
        *a = *b;
        *b = tmp;
    }
    float denom = self->direction.dot(out->normal);
    if (denom > K3(lbl_8037A264)) return 0;
    float dist = d + out->normal.dot(self->position);
    if (dist <= self->radius) {
        if ((*b - *a).cross(self->position - *a).dot(out->normal) < K4(lbl_8037A264)) return 0;
        if (crossSu(self->position - *a, up->y, up->x, up->z).dot(out->normal) < K5(lbl_8037A264)) return 0;
        if (crossUs(up->z, up->x, up->y, self->position - *b).dot(out->normal) < K6(lbl_8037A264)) return 0;
        out->position = self->position;
        out->distance = K0(lbl_8037A250);
        return 1;
    }
    out->distance = -((dist - self->radius) / out->normal.dot(self->direction));
    if (out->distance < K7(lbl_8037A264) || out->distance > self->distance) return 0;
    out->position = self->direction * out->distance + self->position;
    if ((*b - *a).cross(out->position - *a).dot(out->normal) < K8(lbl_8037A264)) return 0;
    float ux = up->x, uz = up->z;
    if ((out->position - *a).crossPs(ux, up->y, uz).dot(out->normal) < K9(lbl_8037A264)) return 0;
    return !(crossVs(ux, up->y, uz, out->position - *b).dot(out->normal) < K10(lbl_8037A264));
}
