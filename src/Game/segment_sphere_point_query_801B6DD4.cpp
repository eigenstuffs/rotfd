// Partial text split: fn_801B6DD4 only. fn_801B679C before it (97.9%: FPR
// colouring in the in-range block) remains original code; full draft:
// scratch/claude_match/auto_03_801B679C_text/final.cpp.
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants lbl_8037A250..lbl_8037A26C.  CodeWarrior caches literal
   loads per extended basic block, which plain extern reads do not reproduce,
   so each read site uses one of the K* spellings below: the compiler keeps
   them as separate common-subexpression candidates (integer and pointer
   casts of the address) while still emitting the plain sda21 load.

   Status (fdiff, GC/1.3.2): EXACT fn_801B602C, fn_801B6338, fn_801B6430,
   fn_801B70DC, fn_801B9108.  All other functions reproduce the original
   extent and (except where noted in the report) instruction sequence but
   differ in floating-point register allocation only.

   Notes: Vec3/Vertex need user-declared copy/assignment members; an
   implicit (compiler-generated) operator= makes CodeWarrior defer the
   using function to the end of the object.  Temporaries bound to `this`
   are kept in stack slots, so which side of each member call a temporary
   is on is significant (several near-duplicate helpers exist for that
   reason: cross/operator^ differ only in whether the argument's address is
   taken).  The index pointers of fn_801B9108 must be plain short*. */
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

inline float sqrtOrZero(float sq)
{
    float r = K0(lbl_8037A250);
    if (sq != r) r = fastSqrt(sq);
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
 SegmentBoxVector crossP(const SegmentBoxVector&v)const{float cy=z*v.x-x*v.z;float cx=y*v.z-z*v.y;float cz=x*v.y-y*v.x;return SegmentBoxVector(cx,cy,cz);}
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*lbl_8037A250-z*lbl_8037A258,z*lbl_8037A250-x*lbl_8037A250,x*lbl_8037A258-y*lbl_8037A250);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=K0(lbl_8037A250);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=K0(lbl_8037A258);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,K0(lbl_8037A258));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,K0(lbl_8037A258));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,K0(lbl_8037A250));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*K1(lbl_8037A250)-v.z*K0(lbl_8037A258),v.z*K1(lbl_8037A250)-v.x*K1(lbl_8037A250),v.x*K0(lbl_8037A258)-v.y*K1(lbl_8037A250),K0(lbl_8037A258));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>K0(lbl_8037A264)){float inv=K1(lbl_8037A258)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
extern "C" signed char fn_801B6DD4(const SegmentBoxQuery*self,const SegmentBoxVertex*sphere,SegmentHit*out){
 SegmentBoxVector cd;
 if((self->position-*sphere).dot(self->direction)>K4(lbl_8037A264))return 0;
 SegmentBoxVector dir=self->direction;
 float t=(*sphere-SegmentBoxVertex(self->position)).dot(dir);
 cd=(dir*t+self->position)-*sphere;
 float closestSq=cd.dot(cd);
 float radiusSq=self->unknown1C*self->unknown1C;
 if(closestSq>radiusSq)return 0;
 if((self->position-*sphere).lengthSq()<radiusSq){
  out->distance=K0(lbl_8037A250);
  out->position=self->position;
  out->normal=(out->position-*sphere).normalize();
  return 1;
 }
 float r=sqrtOrZeroK(radiusSq-closestSq,K0(lbl_8037A250));
 out->distance=t-r;
 if(out->distance>K5(lbl_8037A264)&&out->distance<self->distance){
  out->position=self->position+self->direction*out->distance;
  out->normal=(out->position-*sphere).normalize();
  return 1;
 }
 return 0;
}
