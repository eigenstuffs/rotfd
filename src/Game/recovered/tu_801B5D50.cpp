/* Merged TU: .text 0x801B5D50-0x801BA54C, .sdata2 0x8037A250-0x8037A270 (collision queries).
   GC/1.3.2 -O4,p -fp_contract on -use_lmw_stmw on, exceptions/RTTI off.
   .sdata2 is entirely compiler-pooled float literals in first-use order:
   0 (fn_801B5D50), -1, 1, -1e10, 1e10, 1e-6 (fn_801B602C), -1e-4 (fn_801B6430), -1e-6 (fn_801B7C18). */
namespace p_5D50 {
/* Projected quad rejection reconstruction; see docs/notes/game-projected-quad-test.md. */
struct ProjectedQuadVector {
    float x, y, z;
};

struct ProjectedQuadVertex {
    float x, y, z, w;
};

struct ProjectedQuadQuery {
    ProjectedQuadVector position;
    float distance;
    ProjectedQuadVector direction;
    float unknown1C;
};

struct ProjectedQuadResult {
    ProjectedQuadVector position;
    float distance;
    ProjectedQuadVector normal;
    char unknown1C[20];
};


extern "C" signed char fn_80279558(ProjectedQuadQuery*, const ProjectedQuadVertex*,
                                    const ProjectedQuadVertex*, const ProjectedQuadVertex*,
                                    const ProjectedQuadVertex*, const ProjectedQuadVertex*,
                                    ProjectedQuadResult*);
extern "C" signed char fn_801B5D50(ProjectedQuadQuery* self,
                                    const ProjectedQuadVertex* a,
                                    const ProjectedQuadVertex* b,
                                    const ProjectedQuadVertex* c,
                                    const ProjectedQuadVertex* d,
                                    const ProjectedQuadVertex* normal,
                                    ProjectedQuadResult* out) {
    if (self->direction.y) {
        if (self->position.x > a->x &&
            self->position.x > b->x &&
            self->position.x > c->x &&
            self->position.x > d->x) {
            return 0;
        }
        if (self->position.x < a->x &&
            self->position.x < b->x &&
            self->position.x < c->x &&
            self->position.x < d->x) {
            return 0;
        }
        if (self->position.z > a->z &&
            self->position.z > b->z &&
            self->position.z > c->z &&
            self->position.z > d->z) {
            return 0;
        }
        if (self->position.z < a->z &&
            self->position.z < b->z &&
            self->position.z < c->z &&
            self->position.z < d->z) {
            return 0;
        }
    } else if (self->direction.x) {
        if (self->position.y > a->y &&
            self->position.y > b->y &&
            self->position.y > c->y &&
            self->position.y > d->y) {
            return 0;
        }
        if (self->position.y < a->y &&
            self->position.y < b->y &&
            self->position.y < c->y &&
            self->position.y < d->y) {
            return 0;
        }
        if (self->position.z > a->z &&
            self->position.z > b->z &&
            self->position.z > c->z &&
            self->position.z > d->z) {
            return 0;
        }
        if (self->position.z < a->z &&
            self->position.z < b->z &&
            self->position.z < c->z &&
            self->position.z < d->z) {
            return 0;
        }
    } else {
        if (self->position.x > a->x &&
            self->position.x > b->x &&
            self->position.x > c->x &&
            self->position.x > d->x) {
            return 0;
        }
        if (self->position.x < a->x &&
            self->position.x < b->x &&
            self->position.x < c->x &&
            self->position.x < d->x) {
            return 0;
        }
        if (self->position.y > a->y &&
            self->position.y > b->y &&
            self->position.y > c->y &&
            self->position.y > d->y) {
            return 0;
        }
        if (self->position.y < a->y &&
            self->position.y < b->y &&
            self->position.y < c->y &&
            self->position.y < d->y) {
            return 0;
        }
    }
    return fn_80279558(self, a, b, c, d, normal, out);
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_602C {
// Partial text split: fn_801B602C, fn_801B6338, fn_801B6430 of the segment/shape
// collision query unit; the following functions up to fn_801B70DC remain original
// (full 20-function draft: scratch/claude_match/auto_03_801B602C_text/final.cpp).
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants 0.0f..(-0.000001f).  CodeWarrior caches literal
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








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
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
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*(0.0f)-v.z*(1.0f),v.z*(0.0f)-v.x*(0.0f),v.x*(1.0f)-v.y*(0.0f),(1.0f));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

#define M1 (-1.0f)
#define P1 1.0f
extern "C" signed char fn_801B602C(const SegmentBoxQuery*self,const SegmentBoxMatrix*matrix) {
 SegmentBoxVector start=matrix->transform(self->position);
 SegmentBoxVector end=matrix->transform(self->position+self->direction*self->distance);
 SegmentBoxVector delta;delta.x=end.x-start.x;delta.y=end.y-start.y;delta.z=end.z-start.z;
if(start.x<(M1) && end.x<(M1))return 0;
if(start.x>(P1) && end.x>(P1))return 0;
if(start.y<(M1) && end.y<(M1))return 0;
if(start.y>(P1) && end.y>(P1))return 0;
if(start.z<(M1) && end.z<(M1))return 0;
if(start.z>(P1) && end.z>(P1))return 0;
float lower=((-1.0e10f)),upper=(1.0e10f);
{float inverse=(P1)/delta.x;float first=inverse*((M1)-start.x);float second=inverse*((P1)-start.x);if(first>second){float temp=first;first=second;second=temp;}if(first>((-1.0e10f)))lower=first;if(second<(1.0e10f))upper=second;if(lower>upper)return 0;if(upper<(0.000001f))return 0;}
{float inverse=(P1)/delta.z;float first=inverse*((M1)-start.z);float second=inverse*((P1)-start.z);if(first>second){float temp=first;first=second;second=temp;}if(first>lower)lower=first;if(second<upper)upper=second;if(lower>upper)return 0;if(upper<(0.000001f))return 0;}
{float inverse=(P1)/delta.y;float first=inverse*((M1)-start.y);float second=inverse*((P1)-start.y);if(first>second){float temp=first;first=second;second=temp;}if(first>lower)lower=first;if(second<upper)upper=second;if(lower>upper)return 0;if(upper<(0.000001f))return 0;}
return 1;
}

struct SphereBoxSphere {SegmentBoxVector position;float radius;};
struct SphereBoxTransform : SegmentBoxMatrix {float extents[3];};
extern "C" signed char fn_801B6338(const SphereBoxSphere*self,const SphereBoxTransform*matrix){
 SegmentBoxVector center=matrix->transform(self->position);
 float radius=matrix->extents[0]*self->radius;
 if(center.x-radius>(P1) || center.x+radius<(M1))return 0;
 radius=matrix->extents[1]*self->radius;
 if(center.y-radius>(P1) || center.y+radius<(M1))return 0;
 radius=matrix->extents[2]*self->radius;
 if(center.z-radius>(P1) || center.z+radius<(M1))return 0;
 return 1;
}

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
#define Z0 0.0f
extern "C" signed char fn_801B6430(const SegmentBoxQuery*self,const SegmentBoxVector*a,const SegmentBoxVector*b,SegmentHit*out){
 out->normal=(*b-*a).cross(SegmentBoxVector(0.0f,1.0f,0.0f));
 SegmentBoxVector pos=self->position;
 SegmentBoxVector dir=self->direction;
 float d=-out->normal.dot(*a);
 float side=d+out->normal.dot(pos);
 out->distance=-(side/out->normal.dot(dir));
 if(out->distance<(0.000001f)||out->distance>self->distance)return 0;
 out->position=dir*out->distance+pos;
 if((*b-*a).cross(out->position-*a).dot(out->normal)<((-0.0001f)))return 0;
 if((out->position-*a).cross(SegmentBoxVector(0.0f,1.0f,0.0f)).dot(out->normal)<((-0.0001f)))return 0;
 if(SegmentBoxVector((Z0),(P1),(Z0)).cross(out->position-*b).dot(out->normal)<((-0.0001f)))return 0;
 float scale=reciprocalSqrt(out->normal.dot(out->normal));
 out->normal.x*=scale;out->normal.y*=scale;out->normal.z*=scale;
 if(side<(0.000001f))out->normal=-out->normal;
 return 1;
}


struct StripVector3 {float x,y,z;void operator=(const StripVector3&v){x=v.x;y=v.y;z=v.z;} };
struct StripVertex:StripVector3 {float w;StripVertex(){} void set(const StripVector3&v,float W){w=W;StripVector3::operator=(v);} };
struct StripQuery {float x,y,z,distance,dx,dy,dz,unknown;StripQuery(const StripQuery&q):x(q.x),y(q.y),z(q.z),distance(q.distance),dx(q.dx),dy(q.dy),dz(q.dz),unknown(q.unknown){} };
struct StripResult {StripVector3 position;float distance;StripVector3 normal;char unknown[20];};
extern "C" {signed char fn_8027AD94(StripQuery*,const StripVertex*,const StripVertex*,const StripVertex*,StripResult*);}
struct LineShape { SegmentBoxVector origin; float unknown0C; SegmentBoxVector direction; };




namespace Circle9318 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Capsule{Vec3 origin;float length;Vec3 direction;float radius;};
}


struct CapsuleShape { SegmentBoxVector start; float length; SegmentBoxVector direction; float unknown1C; float radius; };
namespace Circle98A4 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Segment{Vec3 origin;float length;Vec3 direction;};
}

namespace Sphere38C {
struct Vec3 {
 float x,y,z;
 Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 float distanceSquared(const Vec3&v)const{float c=z-v.z;float b=y-v.y;float a=x-v.x;return a*a+b*b+c*c;}
 float dot(const Vec3&v)const{return x*v.x+y*v.y+z*v.z;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float squareParts()const{float a=x*x,b=y*y,c=z*z;return a+b+c;}
};
struct Sphere{Vec3 center;float radius;float distanceSquared(const Vec3&v)const{return v.distanceSquared(center);}};
struct Capsule{Vec3 start;float length;Vec3 direction;float radius;};

}
namespace Path54C {
typedef unsigned long Word;
struct Globals {char unknown00[0x10C];Word flags;void*console;};
extern "C"{
 extern Globals lbl_801E9D24;
 extern char lbl_802AC980[];
 extern __declspec(section ".sdata2") const char lbl_8037A270[],lbl_8037A274[];
 Word strlen(const char*);
 const char*strstr(const char*,const char*);
 char*strncpy(char*,const char*,Word);
 char*strcpy(char*,const char*);
 void fn_801FA014(void*,const char*,...);
}
}


#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_679C {
typedef unsigned int u32;
extern "C" {








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(register float sq)
{
    register float r = (0.0f);
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
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,0.0f);}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*0.0f-v.z*1.0f,v.z*0.0f-v.x*0.0f,v.x*1.0f-v.y*0.0f,1.0f);}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);


inline SegmentBoxVertex crossVs(float x, float y, float z, const SegmentBoxVector& v){const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
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
inline SegmentBoxVertex crossUs(float z, float x, float y, const SegmentBoxVector& v){const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
/* w21b: the original reads 0.0f/1.0f/1e-6f from the shared TU pool (0.0f/258/264,
   owned by the collision-query TU 0x801B5D50..).  Plain extern reads are CSE'd by the
   frontend (low vregs) where the pooled literals are only CSE'd by the backend (high vregs),
   which changes colouring.  Giving every compare site a distinct but equivalent read form
   (K0, K2..K10 casts of the address through integer types) keeps the frontend from merging
   them; the backend still merges the identical lfs loads -> same allocation as the literals. */
extern "C" bool fn_801B679C(const WallSegment* self, SegmentBoxVertex* a, SegmentBoxVertex* b, const SegmentBoxVertex* up, SegmentHit* out)
{
    out->normal = (*b - *a).SegmentBoxVector::cross(*up);
    float len = out->normal.magnitude();
    if (len <= (0.000001f)) return 0;
    float inv = (1.0f) / len;
    out->normal.x *= inv;
    out->normal.y *= inv;
    out->normal.z *= inv;
    float d = -out->normal.dot(*a);
    float side = d + self->position.dot(out->normal);
    if (side < (0.000001f)) {
        out->normal = -out->normal;
        d = -d;
        SegmentBoxVertex tmp = *a;
        *a = *b;
        *b = tmp;
    }
    float denom = self->direction.dot(out->normal);
    if (denom > (0.000001f)) return 0;
    float dist = d + out->normal.dot(self->position);
    if (dist <= self->radius) {
        if ((*b - *a).cross(self->position - *a).dot(out->normal) < (0.000001f)) return 0;
        if (crossSu(self->position - *a, up->y, up->x, up->z).dot(out->normal) < (0.000001f)) return 0;
        if (crossUs(up->z, up->x, up->y, self->position - *b).dot(out->normal) < (0.000001f)) return 0;
        out->position = self->position;
        out->distance = (0.0f);
        return 1;
    }
    out->distance = -((dist - self->radius) / out->normal.dot(self->direction));
    if (out->distance < (0.000001f) || out->distance > self->distance) return 0;
    out->position = self->direction * out->distance + self->position;
    if ((*b - *a).cross(out->position - *a).dot(out->normal) < (0.000001f)) return 0;
    float ux = up->x, uz = up->z;
    if ((out->position - *a).crossPs(ux, up->y, uz).dot(out->normal) < (0.000001f)) return 0;
    return !(crossVs(ux, up->y, uz, out->position - *b).dot(out->normal) < (0.000001f));
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_6DD4 {
// Partial text split: fn_801B6DD4 only. fn_801B679C before it (97.9%: FPR
// colouring in the in-range block) remains original code; full draft:
// scratch/claude_match/auto_03_801B679C_text/final.cpp.
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants 0.0f..(-0.000001f).  CodeWarrior caches literal
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








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
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
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*(0.0f)-v.z*(1.0f),v.z*(0.0f)-v.x*(0.0f),v.x*(1.0f)-v.y*(0.0f),(1.0f));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
extern "C" signed char fn_801B6DD4(const SegmentBoxQuery*self,const SegmentBoxVertex*sphere,SegmentHit*out){
 SegmentBoxVector cd;
 if((self->position-*sphere).dot(self->direction)>(0.000001f))return 0;
 SegmentBoxVector dir=self->direction;
 float t=(*sphere-SegmentBoxVertex(self->position)).dot(dir);
 cd=(dir*t+self->position)-*sphere;
 float closestSq=cd.dot(cd);
 float radiusSq=self->unknown1C*self->unknown1C;
 if(closestSq>radiusSq)return 0;
 if((self->position-*sphere).lengthSq()<radiusSq){
  out->distance=(0.0f);
  out->position=self->position;
  out->normal=(out->position-*sphere).normalize();
  return 1;
 }
 float r=sqrtOrZeroK(radiusSq-closestSq,(0.0f));
 out->distance=t-r;
 if(out->distance>(0.000001f)&&out->distance<self->distance){
  out->position=self->position+self->direction*out->distance;
  out->normal=(out->position-*sphere).normalize();
  return 1;
 }
 return 0;
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_70DC {
// Partial text split: fn_801B70DC of the segment/shape collision query unit;
// its neighbours remain original (see scratch/claude_match/auto_03_801B602C_text).
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants 0.0f..(-0.000001f).  CodeWarrior caches literal
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








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
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
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*(0.0f)-v.z*(1.0f),v.z*(0.0f)-v.x*(0.0f),v.x*(1.0f)-v.y*(0.0f),(1.0f));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

#define M1 (-1.0f)
#define P1 1.0f

struct SphereBoxSphere {SegmentBoxVector position;float radius;};
struct SphereBoxTransform : SegmentBoxMatrix {float extents[3];};

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
#define Z0 0.0f


extern "C" signed char fn_801B70DC(const SegmentBoxQuery*self,const SegmentBoxVector*a,const SegmentBoxVector*b,const SegmentBoxVector*c,const SegmentBoxVector*d,SegmentHit*out){
 out->normal.x=a->y*(b->z-c->z)+b->y*(c->z-a->z)+c->y*(a->z-b->z);
 out->normal.y=a->z*(b->x-c->x)+b->z*(c->x-a->x)+c->z*(a->x-b->x);
 out->normal.z=a->x*(b->y-c->y)+b->x*(c->y-a->y)+c->x*(a->y-b->y);
 float length=out->normal.length();
 if(length<=(0.000001f))return 0;
 float inverse=(1.0f)/length;
 out->normal.x*=inverse;out->normal.y*=inverse;out->normal.z*=inverse;
 SegmentBoxVector pos=self->position;
 SegmentBoxVector dir=self->direction;
 float plane=-out->normal.dot(*a);
 float side=plane+out->normal.dot(pos);
 if(side<=(0.000001f))return 0;
 out->distance=-(side/out->normal.dot(dir));
 if(out->distance<(0.000001f)||out->distance>self->distance)return 0;
 out->position=dir*out->distance+pos;
 if((*a-out->position).cross(*b-out->position).dot(out->normal)<((-0.0001f)))return 0;
 if((*b-out->position).cross(*c-out->position).dot(out->normal)<((-0.0001f)))return 0;
 if((*c-out->position).cross(*d-out->position).dot(out->normal)<((-0.0001f)))return 0;
 if((*d-out->position).cross(*a-out->position).dot(out->normal)<((-0.0001f)))return 0;
 return 1;
}
struct StripVector3 {float x,y,z;void operator=(const StripVector3&v){x=v.x;y=v.y;z=v.z;} };
struct StripVertex:StripVector3 {float w;StripVertex(){} void set(const StripVector3&v,float W){w=W;StripVector3::operator=(v);} };
struct StripQuery {float x,y,z,distance,dx,dy,dz,unknown;StripQuery(const StripQuery&q):x(q.x),y(q.y),z(q.z),distance(q.distance),dx(q.dx),dy(q.dy),dz(q.dz),unknown(q.unknown){} };
struct StripResult {StripVector3 position;float distance;StripVector3 normal;char unknown[20];};
extern "C" {signed char fn_8027AD94(StripQuery*,const StripVertex*,const StripVertex*,const StripVertex*,StripResult*);}
struct LineShape { SegmentBoxVector origin; float unknown0C; SegmentBoxVector direction; };




namespace Circle9318 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Capsule{Vec3 origin;float length;Vec3 direction;float radius;};
}


struct CapsuleShape { SegmentBoxVector start; float length; SegmentBoxVector direction; float unknown1C; float radius; };
namespace Circle98A4 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Segment{Vec3 origin;float length;Vec3 direction;};
}

namespace Sphere38C {
struct Vec3 {
 float x,y,z;
 Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 float distanceSquared(const Vec3&v)const{float c=z-v.z;float b=y-v.y;float a=x-v.x;return a*a+b*b+c*c;}
 float dot(const Vec3&v)const{return x*v.x+y*v.y+z*v.z;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float squareParts()const{float a=x*x,b=y*y,c=z*z;return a+b+c;}
};
struct Sphere{Vec3 center;float radius;float distanceSquared(const Vec3&v)const{return v.distanceSquared(center);}};
struct Capsule{Vec3 start;float length;Vec3 direction;float radius;};

}
namespace Path54C {
typedef unsigned long Word;
struct Globals {char unknown00[0x10C];Word flags;void*console;};
extern "C"{
 extern Globals lbl_801E9D24;
 extern char lbl_802AC980[];
 extern __declspec(section ".sdata2") const char lbl_8037A270[],lbl_8037A274[];
 Word strlen(const char*);
 const char*strstr(const char*,const char*);
 char*strncpy(char*,const char*,Word);
 char*strcpy(char*,const char*);
 void fn_801FA014(void*,const char*,...);
}
}


#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_74D8 {
// Partial text split: fn_801B74D8 and fn_801B7C18. fn_801B80B0, fn_801B85B0
// and fn_801B8B20 after them (92.8-97.0%) remain original code; full draft:
// scratch/claude_match/auto_03_801B74D8_text/final.cpp.
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants 0.0f..(-0.000001f).  CodeWarrior caches literal
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








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
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
 float dotR(const SegmentBoxVector&v)const{return v.x*x+v.y*y+v.z*z;}
 SegmentBoxVector cross(const SegmentBoxVector&v)const{return SegmentBoxVector(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}
 SegmentBoxVector crossP(const SegmentBoxVector&v)const{float cy=z*v.x-x*v.z;float cx=y*v.z-z*v.y;float cz=x*v.y-y*v.x;return SegmentBoxVector(cx,cy,cz);}
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*(0.0f)-v.z*(1.0f),v.z*(0.0f)-v.x*(0.0f),v.x*(1.0f)-v.y*(0.0f),(1.0f));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
extern "C" signed char fn_801B74D8(const SegmentBoxQuery*self,const SegmentBoxVertex*a,const SegmentBoxVertex*b,const SegmentBoxVertex*c,const SegmentBoxVertex*d,SegmentHit*out){
 out->normal.x=a->y*(b->z-c->z)+b->y*(c->z-a->z)+c->y*(a->z-b->z);
 out->normal.y=a->z*(b->x-c->x)+b->z*(c->x-a->x)+c->z*(a->x-b->x);
 out->normal.z=a->x*(b->y-c->y)+b->x*(c->y-a->y)+c->x*(a->y-b->y);
 float length=out->normal.length();
 if(length<=(0.000001f))return 0;
 float inverse=(1.0f)/length;
 out->normal.x*=inverse;out->normal.y*=inverse;out->normal.z*=inverse;
 if(self->direction.dot(out->normal)>=(0.000001f))return 0;
 float plane=-out->normal.dot(*a);
 float distance=plane+out->normal.dot(self->position);
 if(distance<=(0.000001f))return 0;
 if(distance<=self->unknown1C){
  if((*a-SegmentBoxVertex(self->position)).cross(*b-SegmentBoxVertex(self->position)).dot(out->normal)<((-0.0001f)))return 0;
  if((*b-SegmentBoxVertex(self->position)).cross(*c-SegmentBoxVertex(self->position)).dot(out->normal)<((-0.0001f)))return 0;
  if((*c-SegmentBoxVertex(self->position)).cross(*d-SegmentBoxVertex(self->position)).dot(out->normal)<((-0.0001f)))return 0;
  if((*d-SegmentBoxVertex(self->position)).cross(*a-SegmentBoxVertex(self->position)).dot(out->normal)<((-0.0001f)))return 0;
  out->position=self->position;
  out->distance=(0.0f);
  return 1;
 }
 out->distance=-((distance-self->unknown1C)/out->normal.dot(self->direction));
 if(out->distance<(0.000001f)||out->distance>self->distance)return 0;
 out->position=self->direction*out->distance+self->position;
 if((*a-SegmentBoxVertex(out->position)).cross(*b-SegmentBoxVertex(out->position)).dot(out->normal)<((-0.0001f)))return 0;
 SegmentBoxVector n=out->normal;
 if((*b-SegmentBoxVertex(out->position)).cross(*c-SegmentBoxVertex(out->position)).dot(n)<((-0.0001f)))return 0;
 if((*c-SegmentBoxVertex(out->position)).cross(*d-SegmentBoxVertex(out->position)).dot(n)<((-0.0001f)))return 0;
 if((*d-SegmentBoxVertex(out->position)).cross(*a-SegmentBoxVertex(out->position)).dot(n)<((-0.0001f)))return 0;
 return 1;
}
extern "C" signed char fn_801B7C18(const SegmentBoxSphere*self,const SegmentBoxVertex*a,const SegmentBoxVertex*b,const SegmentBoxVertex*c,const SegmentBoxVertex*d,SegmentHit*out){
 out->normal.x=a->y*(b->z-c->z)+b->y*(c->z-a->z)+c->y*(a->z-b->z);
 out->normal.y=a->z*(b->x-c->x)+b->z*(c->x-a->x)+c->z*(a->x-b->x);
 out->normal.z=a->x*(b->y-c->y)+b->x*(c->y-a->y)+c->x*(a->y-b->y);
 float length=out->normal.length();
 if(length<=(0.000001f))return 0;
 float inverse=(1.0f)/length;
 out->normal.x*=inverse;out->normal.y*=inverse;out->normal.z*=inverse;
 float plane=-out->normal.dot(*a);
 float side=plane+out->normal.dot(self->center);
 if(side<=(0.0f))return 0;
 float distance=(self->center-*a).dotR(out->normal);
 if(distance>self->radius)return 0;
 SegmentBoxVector point=out->normal*-(side/out->normal.dot(out->normal))+self->center;
 point=point;
 SegmentBoxVertex pv(point.x,point.y,point.z,(1.0f));
 if(((*a-pv)^((const SegmentBoxVector&)*b-point)).dot(out->normal)<((-0.000001f)))return fn_8027B140(self,a,b,out);
 if(((*b-pv)^((const SegmentBoxVector&)*c-point)).dot(out->normal)<((-0.000001f)))return fn_8027B140(self,b,c,out);
 if(((*c-pv)^((const SegmentBoxVector&)*d-point)).dot(out->normal)<((-0.000001f)))return fn_8027B140(self,c,d,out);
 if(((*d-pv)^((const SegmentBoxVector&)*a-point)).dot(out->normal)<((-0.000001f)))return fn_8027B140(self,d,a,out);
 out->position=point;
 out->distance=distance;
 return 1;
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_80B0 {
/* auto_03_801B80B0_text: segment/sphere queries against lines and walls
   (tail of the segment_sphere_quad_queries_801B74D8 translation unit).
   GC/1.3.2, -O4,p, -fp_contract on.
   w27: fn_801B80B0 and fn_801B85B0 EXACT, reading 0.0f/258/264/26C
   through per-site extern spellings (KKn casts: equal spellings are
   CSE'd by the frontend, so each site has its own).  fn_801B8B20 is
   EXACT-MOD-POOL with 4 literal loads left (0.0f/1.0f of the first up
   vector, the 1.0f w of the xL vertex, the 0.0f of the crossUpVL up
   vector); its other constants are extern reads.  Matching levers:
   member-wise n (no copy alias), "a = d*t0; a.x = pos.x - a.x" forms,
   r2 declared before q, distSq1 with dz/dy/dx declared in reverse,
   direct-asm sqrt (sqrtA) for 85B0 so the fres result is r itself,
   and "d(p.x,p.y,p.z); d.x = q.x - d.x" so p is loaded before q. */
extern "C" {




}
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
    if (sq != r) r = fastSqrt(sq);
    return r;
}
inline float sqrtOrZero2(float sq)
{
    float r = (0.0f);
    if (sq != r) r = fastSqrt(sq);
    return r;
}
inline float reciprocalSqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

struct SegmentBoxVector { float x,y,z; SegmentBoxVector(){} SegmentBoxVector(float X,float Y,float Z):x(X),y(Y),z(Z){}
 SegmentBoxVector operator+(const SegmentBoxVector&r)const{return SegmentBoxVector(x+r.x,y+r.y,z+r.z);}
 SegmentBoxVector operator-(const SegmentBoxVector&r)const{return SegmentBoxVector(x-r.x,y-r.y,z-r.z);}
 SegmentBoxVector operator*(float r)const{return SegmentBoxVector(x*r,y*r,z*r);}
 SegmentBoxVector&operator=(const SegmentBoxVector&v){x=v.x;y=v.y;z=v.z;return *this;}
 float dot(const SegmentBoxVector&v)const{return x*v.x+y*v.y+z*v.z;}
 float dotR(const SegmentBoxVector&v)const{return v.x*x+v.y*y+v.z*z;}
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthE2()const{return x*x+y*y+z*z;}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float lengthE80()const{float sq=x*x+y*y+z*z;float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float lengthE()const{float sq=x*x+y*y+z*z;float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
struct LineShape { SegmentBoxVector origin; float unknown0C; SegmentBoxVector direction; };
struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
extern "C" {
signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*);
}

inline float lenW(const SegmentBoxVector&v){return v.lengthE();}
inline float distSq1(const SegmentBoxVector&a,const SegmentBoxVector&v){float dz=a.z-v.z;float dy=a.y-v.y;float dx=a.x-v.x;return dx*dx+dy*dy+dz*dz;}
inline float lenW80(const SegmentBoxVector&v){return v.lengthE80();}
inline SegmentBoxVertex toDirection80(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
extern "C" signed char fn_801B80B0(const SegmentBoxQuery*self,const LineShape*line,SegmentHit*out){
 SegmentBoxVector end=self->position+self->direction*self->distance;
 float t0=(self->position-line->origin).dot(line->direction);
 SegmentBoxVector a=line->direction*t0;a.x=self->position.x-a.x;a.y=self->position.y-a.y;a.z=self->position.z-a.z;
 float t1=toDirection80(end-line->origin).dot(line->direction);
 SegmentBoxVector b=end-line->direction*t1;
 SegmentBoxVector n;n.x=b.x-a.x;n.y=b.y-a.y;n.z=b.z-a.z;
 float length=lenW80(n);
 if(length>(0.000001f)){float inv=(1.0f)/length;n.x*=inv;n.y*=inv;n.z*=inv;}
 if((a-line->origin).dot(n)>(0.000001f))return 0;
 float s=(line->origin-a).dot(n);
 float rr=self->unknown1C*self->unknown1C;
 float d2=distSq1(n*s+a,line->origin);
 if(d2>rr)return 0;
 if((a-line->origin).lengthSq()<rr){
  if((self->position-line->origin).dot(line->direction)<(0.000001f))return 0;
  out->distance=(0.0f);
  out->position=self->position;
  out->normal=(a-line->origin).normalize();
  return 1;
 }
 float r2=(0.0f);float q=rr-d2;if(q!=r2)r2=fastSqrt(q);float h=s-r2;
 out->distance=h*self->distance/length;
 if(out->distance>(0.000001f)&&out->distance<self->distance){
  out->position=self->position+self->direction*out->distance;
  if((out->position-line->origin).dot(line->direction)<(0.000001f))return 0;
  out->normal=(a+n*h-line->origin).normalize();
  return 1;
 }
 return 0;
}

inline float sqrtA_s(register float sq){register float r=(0.0f);if(sq!=r){asm{ frsqrte f4, sq
 fres r, f4 }}return r;}
inline float lenA_s(const SegmentBoxVector&v){return sqrtA_s(v.x*v.x+v.y*v.y+v.z*v.z);}
inline float sqrtA_n(register float sq){register float r=(0.0f);if(sq!=r){asm{ frsqrte f4, sq
 fres r, f4 }}return r;}
inline float lenA_n(const SegmentBoxVector&v){return sqrtA_n(v.x*v.x+v.y*v.y+v.z*v.z);}
inline float lenAW_n(const SegmentBoxVector&v){return lenA_n(v);}
inline SegmentBoxVertex toDirection85(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
extern "C" signed char fn_801B85B0(const SegmentBoxQuery*self,const SegmentBoxVertex&p,const SegmentBoxVertex&q,SegmentHit*out){
 SegmentBoxVector d(p.x,p.y,p.z);d.x=q.x-d.x;d.y=q.y-d.y;d.z=q.z-d.z;
 float span=lenA_s(d);
 if(span>(0.000001f)){float inv=(1.0f)/span;d.x*=inv;d.y*=inv;d.z*=inv;}
 SegmentBoxVector end=self->position+self->direction*self->distance;
 float t0=(self->position-p).dot(d);
 float t1=toDirection85(end-p).dot(d);
 SegmentBoxVector a=d*t0;a.x=self->position.x-a.x;a.y=self->position.y-a.y;a.z=self->position.z-a.z;
 SegmentBoxVector b=d*t1;b.x=end.x-b.x;b.y=end.y-b.y;b.z=end.z-b.z;
 SegmentBoxVector n;n.x=b.x-a.x;n.y=b.y-a.y;n.z=b.z-a.z;
 float length=lenAW_n(n);
 if(length>(0.000001f)){float inv=(1.0f)/length;n.x*=inv;n.y*=inv;n.z*=inv;}
 if((a-p).dot(n)>(0.000001f))return 0;
 float s=(p-a).dot(n);
 float rr=self->unknown1C*self->unknown1C;
 float d2=distSq1(n*s+a,p);
 if(d2>rr)return 0;
 if((a-p).lengthSq()<rr){
  float t=(self->position-p).dot(d);
  if(t<(0.000001f)||t>span)return 0;
  out->distance=(0.0f);
  out->position=self->position;
  out->normal=(a-p).normalize();
  return 1;
 }
 float r2=(0.0f);float qq=rr-d2;if(qq!=r2)r2=fastSqrt(qq);float h=s-r2;
 out->distance=h*self->distance/length;
 if(out->distance>(0.000001f)&&out->distance<self->distance){
  out->position=self->position+self->direction*out->distance;
  float t=(out->position-SegmentBoxVector(p)).dot(d);
  if(t<(0.000001f)||t>span)return 0;
  out->normal=(a+n*h-SegmentBoxVector(p)).normalize();
  return 1;
 }
 return 0;
}

inline float lenL(const SegmentBoxVector&v){float sq=v.lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline SegmentBoxVector crossV(const SegmentBoxVector&a,const SegmentBoxVector&v){return SegmentBoxVector(a.y*v.z-a.z*v.y,a.z*v.x-a.x*v.z,a.x*v.y-a.y*v.x);}
inline SegmentBoxVertex crossVV(const SegmentBoxVector&a,const SegmentBoxVector&v){return SegmentBoxVertex(a.y*v.z-a.z*v.y,a.z*v.x-a.x*v.z,a.x*v.y-a.y*v.x,1.0f);}
struct VtxL : SegmentBoxVertex { VtxL(float X,float Y,float Z,float W):SegmentBoxVertex(X,Y,Z,W){}
 SegmentBoxVertex crossL(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,1.0f);} };

struct CV : SegmentBoxVector { SegmentBoxVector crossM(const SegmentBoxVector&v)const{return SegmentBoxVector(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);} };
inline float lenL_a(const SegmentBoxVector&v){float sq=v.lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline float lenL_b(const SegmentBoxVector&v){float sq=v.lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline float lenL_c(const SegmentBoxVector&v){float sq=v.lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline SegmentBoxVertex crossVV_a(const SegmentBoxVector&a,const SegmentBoxVector&v){return SegmentBoxVertex(a.y*v.z-a.z*v.y,a.z*v.x-a.x*v.z,a.x*v.y-a.y*v.x,1.0f);}
inline SegmentBoxVertex crossUpVL_a(const SegmentBoxVector&v){return crossVV_a(v,SegmentBoxVector(0.0f,1.0f,0.0f));}
inline void buildSegmentL_a(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->direction=end-start;segment->position=start;segment->distance=lenL_b(segment->direction);if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
inline void buildSegmentL_b(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->direction=end-start;segment->position=start;segment->distance=lenL_c(segment->direction);if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
struct VtxL_a : SegmentBoxVertex { VtxL_a(float X,float Y,float Z,float W):SegmentBoxVertex(X,Y,Z,W){}
 SegmentBoxVertex crossL(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,1.0f);} };
inline SegmentBoxVertex xL_a(const SegmentBoxVertex&a,const SegmentBoxVector&v){return SegmentBoxVertex(a.y*v.z-a.z*v.y,a.z*v.x-a.x*v.z,a.x*v.y-a.y*v.x,1.0f);}
extern "C" signed char fn_801B8B20(const SegmentBoxSphere*self,SegmentBoxVertex*a,SegmentBoxVertex*b,SegmentHit*out){
 out->normal=crossV(*b-*a,SegmentBoxVector(0.0f,1.0f,0.0f));
 float length=lenL_a(out->normal);
 if(length<=(0.000001f))return 0;
 float inverse=(1.0f)/length;
 out->normal.x*=inverse;out->normal.y*=inverse;out->normal.z*=inverse;
 float plane=-out->normal.dot(*a);
 if(plane+out->normal.dot(self->center)<=(0.0f)){
  out->normal=-out->normal;
  plane=-plane;
  SegmentBoxVertex t=*a;*a=*b;*b=t;
 }
 float distance=(self->center-*a).dotR(out->normal);
 if(distance>self->radius)return 0;
 out->position=out->normal*-(plane+out->normal.dot(self->center)/out->normal.dot(out->normal))+self->center;
 SegmentBoxVector n=out->normal;
 SegmentBoxVector d=out->position-*a;
 if(xL_a(*b-*a,d).dot(n)<((-0.000001f)))return fn_8027B140(self,a,b,out);
 SegmentBoxVector n2=out->normal;
 if(crossUpVL_a(d).dot(n2)<((-0.000001f))){
  SegmentBoxQuery segment;
  buildSegmentL_a(&segment,*a,*a+SegmentBoxVector(0.0f,1.0f,0.0f));
  return fn_801B9620(self,&segment,out);
 }
 if(VtxL_a(0.0f,1.0f,0.0f,1.0f).crossL(out->position-*b).dot(n)<((-0.000001f))){
  SegmentBoxQuery segment;
  buildSegmentL_b(&segment,*b,*b+SegmentBoxVector(0.0f,1.0f,0.0f));
  return fn_801B9620(self,&segment,out);
 }
 out->distance=distance;
 return 1;
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_9108 {
// Partial text split: fn_801B9108 (triangle-strip query) of the segment/shape
// collision query unit; its neighbours remain original (see
// scratch/claude_match/auto_03_801B602C_text).
/* auto_03_801B602C_text: segment/sphere collision queries against boxes,
   walls, quads, triangles and capsules (GC/1.3.2, -O4,p, fp_contract on,
   C++ without exceptions; same flags as projected_quad_test_801B5D50).

   The original translation unit used float literals; these are the shared
   pooled constants 0.0f..(-0.000001f).  CodeWarrior caches literal
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








}
/* Read forms of one extern constant that the compiler keeps as separate
   expressions; this emulates the original's unpooled literal loads. */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (0.0f);
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
 SegmentBoxVector crossUp()const{return SegmentBoxVector(y*0.0f-z*1.0f,z*0.0f-x*0.0f,x*1.0f-y*0.0f);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float magnitude()const{return sqrtOrZero(lengthSq());}
 float length()const{float sq=lengthSq();float r=(0.0f);if(sq!=r)r=fastSqrt(sq);return r;}
 float distanceSqZYX(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector addZYX(const SegmentBoxVector&r)const{float zz=z+r.z;float yy=y+r.y;float xx=x+r.x;return SegmentBoxVector(xx,yy,zz);}
 float distanceSqZYX2(const SegmentBoxVector&v)const{float dz=z-v.z;float dy=y-v.y;float dx=x-v.x;float r=dx*dx+dy*dy+dz*dz;return r;}
 float distanceSq(const SegmentBoxVector&v)const{float dx=x-v.x;float dy=y-v.y;float dz=z-v.z;return dx*dx+dy*dy+dz*dz;}
 SegmentBoxVector&normalize(){float s=reciprocalSqrt(lengthSq());x*=s;y*=s;z*=s;return *this;}
 SegmentBoxVector operator-()const{return SegmentBoxVector(-x,-y,-z);} };
struct SegmentBoxVertex : SegmentBoxVector { float w; SegmentBoxVertex(){} SegmentBoxVertex(float X,float Y,float Z,float W):SegmentBoxVector(X,Y,Z),w(W){}
 SegmentBoxVertex(const SegmentBoxVector&p){x=p.x;y=p.y;z=p.z;w=(1.0f);}
 SegmentBoxVertex(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 SegmentBoxVertex&operator=(const SegmentBoxVertex&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 SegmentBoxVertex operator-(const SegmentBoxVertex&r)const{return SegmentBoxVertex(x-r.x,y-r.y,z-r.z,w-r.w);}
 SegmentBoxVertex operator^(const SegmentBoxVector&v)const{return SegmentBoxVertex(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,(1.0f));}
 SegmentBoxVertex cross(const SegmentBoxVector&v)const{const SegmentBoxVector*q=&v;return SegmentBoxVertex(y*q->z-z*q->y,z*q->x-x*q->z,x*q->y-y*q->x,(1.0f));}
 };
inline SegmentBoxVertex toDirection(const SegmentBoxVector&v){return SegmentBoxVertex(v.x,v.y,v.z,(0.0f));}
inline SegmentBoxVertex crossUpV(const SegmentBoxVector&v){return SegmentBoxVertex(v.y*(0.0f)-v.z*(1.0f),v.z*(0.0f)-v.x*(0.0f),v.x*(1.0f)-v.y*(0.0f),(1.0f));}
struct SegmentBoxSphere { SegmentBoxVector center; float radius; };
struct SegmentHit;
extern "C" signed char fn_8027B140(const SegmentBoxSphere*,const SegmentBoxVertex*,const SegmentBoxVertex*,SegmentHit*);
struct SegmentBoxQuery { SegmentBoxVector position;float distance;SegmentBoxVector direction;float unknown1C; };
inline void buildSegment(SegmentBoxQuery*segment,const SegmentBoxVector&start,const SegmentBoxVector&end){segment->position=start;segment->direction=end-start;segment->distance=segment->direction.length();if(segment->distance>(0.000001f)){float inv=(1.0f)/segment->distance;segment->direction.x*=inv;segment->direction.y*=inv;segment->direction.z*=inv;}}
extern "C" { signed char fn_801B9620(const SegmentBoxSphere*,const SegmentBoxQuery*,SegmentHit*); }
struct SegmentBoxMatrix { float m[4][4]; SegmentBoxVector transform(const SegmentBoxVector&v)const{SegmentBoxVector r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;} };

#define M1 (-1.0f)
#define P1 1.0f

struct SphereBoxSphere {SegmentBoxVector position;float radius;};
struct SphereBoxTransform : SegmentBoxMatrix {float extents[3];};

struct SegmentHit { SegmentBoxVector position; float distance; SegmentBoxVector normal; };
#define Z0 0.0f


struct StripVector3 {float x,y,z;void operator=(const StripVector3&v){x=v.x;y=v.y;z=v.z;} };
struct StripVertex:StripVector3 {float w;StripVertex(){} void set(const StripVector3&v,float W){w=W;StripVector3::operator=(v);} };
struct StripQuery {float x,y,z,distance,dx,dy,dz,unknown;StripQuery(const StripQuery&q):x(q.x),y(q.y),z(q.z),distance(q.distance),dx(q.dx),dy(q.dy),dz(q.dz),unknown(q.unknown){} };
struct StripResult {StripVector3 position;float distance;StripVector3 normal;char unknown[20];};
extern "C" {signed char fn_8027AD94(StripQuery*,const StripVertex*,const StripVertex*,const StripVertex*,StripResult*);}
struct LineShape { SegmentBoxVector origin; float unknown0C; SegmentBoxVector direction; };



extern "C" signed char fn_801B9108(const StripQuery*self,const StripVector3*positions,short*indices,int count,signed char flip,StripResult*out){
 StripQuery query(*self);signed char found=0;short*second=indices+1;short*third=indices+2;
 for(int i=0;i<count;++i,++indices,++second,++third){
  StripVertex a,b,c;StripResult result;
  a.set(positions[indices[0]],(1.0f));
  if((i&1)^flip){b.set(positions[*third],(1.0f));c.set(positions[*second],(1.0f));}
  else{b.set(positions[*second],(1.0f));c.set(positions[*third],(1.0f));}
  if(fn_8027AD94(&query,&a,&b,&c,&result)){
   if(!found || result.distance<out->distance){
   query.distance=result.distance;found=1;
   out->normal.x=result.normal.x;out->normal.y=result.normal.y;out->normal.z=result.normal.z;
   out->position.x=result.position.x;out->position.y=result.position.y;out->position.z=result.position.z;out->distance=result.distance;
  }}
 }
 return found;
}

namespace Circle9318 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Capsule{Vec3 origin;float length;Vec3 direction;float radius;};
}


struct CapsuleShape { SegmentBoxVector start; float length; SegmentBoxVector direction; float unknown1C; float radius; };
namespace Circle98A4 {
struct Vec3 {float x,y,z;};
struct Vec2XZ {
    float z, x;
    Vec2XZ(float vx,float vz):z(vz),x(vx){}
    float dot(const Vec2XZ& b)const {return z*b.z+x*b.x;}
    float length2()const{return z*z+x*x;}
    Vec2XZ operator+(const Vec3& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator*(float s)const{return Vec2XZ(x*s,z*s);}
    Vec2XZ operator+(const Vec2XZ& b)const{return Vec2XZ(x+b.x,z+b.z);}
    Vec2XZ operator-(const Vec2XZ& b)const{return Vec2XZ(x-b.x,z-b.z);}
};
struct Sphere{Vec3 center;float radius;};
struct Segment{Vec3 origin;float length;Vec3 direction;};
}

namespace Sphere38C {
struct Vec3 {
 float x,y,z;
 Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 float distanceSquared(const Vec3&v)const{float c=z-v.z;float b=y-v.y;float a=x-v.x;return a*a+b*b+c*c;}
 float dot(const Vec3&v)const{return x*v.x+y*v.y+z*v.z;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float squareParts()const{float a=x*x,b=y*y,c=z*z;return a+b+c;}
};
struct Sphere{Vec3 center;float radius;float distanceSquared(const Vec3&v)const{return v.distanceSquared(center);}};
struct Capsule{Vec3 start;float length;Vec3 direction;float radius;};

}
namespace Path54C {
typedef unsigned long Word;
struct Globals {char unknown00[0x10C];Word flags;void*console;};
extern "C"{
 extern Globals lbl_801E9D24;
 extern char lbl_802AC980[];
 extern __declspec(section ".sdata2") const char lbl_8037A270[],lbl_8037A274[];
 Word strlen(const char*);
 const char*strstr(const char*,const char*);
 char*strncpy(char*,const char*,Word);
 char*strcpy(char*,const char*);
 void fn_801FA014(void*,const char*,...);
}
}


#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
namespace p_9318 {
/* auto_03_801B9318_text: 2D/3D sphere/capsule/cylinder overlap tests.
   GC/1.3.2, -O4,p, -fp_contract on.
   EXACT: fn_801B9318, fn_801B9458, fn_801B9620, fn_801B98A4, fn_801B99DC,
   fn_801BA38C and fn_801B9D1C (all seven).
   fn_801B9620: the frsqrte/fres helper writes straight into the result
   variable (`fres r, f4` inside sqrtOrZero).  A separate fastSqrt() helper
   returns through a temporary that is coalesced into the result; coalesced
   copies stay in the interference graph and raise the degree of every value
   live across them, which changed the simplify order of the CSE'd
   differences.
   Register colouring follows the creation order of locals: a component kept
   in a small local array (float d[3]) is coloured after named scalars, which
   is what fixed fn_801B9458.  An element's colouring rank is set by its
   FIRST assignment, while the order of the arithmetic sets the rank of the
   operands it reads; pre-assigning d[k] = component (then d[k] -= o.k)
   decouples the two, which fixed fn_801BA38C.
   Each function keeps its own operator spellings (namespaces) because the
   spelling of the inline operators drives register colouring. */
extern "C" { }
/* Read forms of one pooled constant that the compiler keeps apart (the
   original reloads its literals per block; same idiom as
   segment_sphere_quad_queries_801B74D8.cpp). */
namespace w3_2_9318 {
struct Vec3 { float x, y, z; };
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(float a, float b, float) { y = b; x = a; }
    Vec2(const Vec3& v) { y = v.x; x = v.z; }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 sub1(const Vec2& o) const { return Vec2(x - o.x, y - o.y, 0.0f); }
    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    Vec2 mul1(float s) const { return Vec2(x * s, y * s, 0.0f); }
    Vec2 add1(const Vec2& o) const { return Vec2(x + o.x, y + o.y, 0.0f); }
    float dot(const Vec2& o) const { return x * o.x + y * o.y; }
    float distSq(const Vec2& o) const { float b = y - o.y; float a = x - o.x; return a * a + b * b; }
    float lenSq() const { float a = x * x; float b = y * y; return a + b; }
};
inline Vec2 to2(const Vec3& v) { return Vec2(v.z, v.x); }
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B9318(const Sphere* s, const Capsule* c) {
    Vec2 cd = to2(c->d); Vec2 sc = to2(s->c); Vec2 cp = to2(c->p);
    float t = sc.sub1(cp).dot(cd);
    float rr = (s->r + c->r) * (s->r + c->r);
    if ((cd.mul1(t) + cp).distSq(sc) > rr) return 0;
    if (t < 0.0f) return (to2(c->p) - to2(s->c)).lenSq() < rr;
    if (t > c->len) return (to2(c->p) + to2(c->d) * c->len - to2(s->c)).lenSq() < rr;
    return 1;
}
}
namespace w3_2_9458 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[2] = z - o.z; float b = y - o.y; float a = x - o.x; float r = a * a + b * b + d[2] * d[2]; return r; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B9458(const Sphere* s, const Capsule* c) {
    float t = (s->c - c->p).dot(c->d);
    float sum = s->r + c->r;
    float rr = sum * sum;
    if ((c->d * t + c->p).distSq(s->c) > rr) return 0;
    if (t < 0.0f) return (c->p - s->c).lenSq() < rr;
    if (t > c->len) return (c->p + c->d * c->len - s->c).lenSq() < rr;
    return 1;
}
}
namespace w7_9620 {
/* Returning the difference from an inline call (rather than a named local)
   makes the inliner's return temporaries number the distSq components after
   the dot-product temporary t, which colours t/add/distSq as in the target. */
inline float dif(float a, float b) { return a - b; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 sub1(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub2(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub4(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub5(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 add1(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 add4(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 mul1(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 mul4(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot1(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float dot4(const Vec3& o) const { float d = x * o.x + y * o.y + z * o.z; return d; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq2() const { float rx = x * x; float ry = y * y; float rz = z * z; return rx + ry + rz; }
    float lenSq5() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
inline float sqrtOrZero(register float sq) { register float r = 0.0f; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Sphere { Vec3 c; float r; };
struct Segment { Vec3 p; float len; Vec3 d; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B9620(const Sphere* s, const Segment* c, Hit* out) {
    float r = s->r;
    float t = s->c.sub1(c->p).dot1(c->d);
    float rr = r * r;
    if (c->d.mul1(t).add1(c->p).distSq(s->c) > rr) return 0;
    if (t < 0.0f) {
        if (c->p.sub2(s->c).lenSq2() < rr) {
            out->pos = c->p;
            out->dist = sqrtOrZero(c->p.sub5(s->c).lenSq5());
            return 1;
        }
        return 0;
    }
    out->pos = c->d.mul4(c->d.dot4(s->c.sub4(c->p))).add4(c->p);
    out->dist = sqrtOrZero(out->pos.sub5(s->c).lenSq5());
    return 1;
}
}
namespace w3_2_98A4 {
struct Vec3 { float x, y, z; };
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(float a, float b, float) { y = b; x = a; }
    Vec2(const Vec3& v) { y = v.x; x = v.z; }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 sub1(const Vec2& o) const { return Vec2(x - o.x, y - o.y, 0.0f); }
    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    float dot(const Vec2& o) const { return x * o.x + y * o.y; }
    float distSq(const Vec2& o) const { float b = y - o.y; float a = x - o.x; return a * a + b * b; }
    float lenSq() const { float a = x * x; float b = y * y; return a + b; }
};
inline Vec2 to2(const Vec3& v) { return Vec2(v.z, v.x); }
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B98A4(const Sphere* s, const Capsule* c) {
    Vec2 sc = to2(s->c); Vec2 cp = to2(c->p); Vec2 cd = to2(c->d);
    float t = sc.sub1(cp).dot(cd);
    float rr = s->r * s->r;
    if ((cd * t + cp).distSq(sc) > rr) return 0;
    if (t < 0.0f) return (to2(c->p) - to2(s->c)).lenSq() < rr;
    if (t > c->len) return (to2(c->p) + to2(c->d) * c->len - sc).lenSq() < rr;
    return 1;
}
}
namespace w17_99DC {
/* Constants are re-read at every use (volatile read idiom); the frsqrte/fres
   pair writes straight into the result variable; q is declared before e in
   the far-cap branch; the cap normal is scaled in place (n *= r) and the hit
   normal is w /= dist. */
#define ZERO (0.0f)
#define ONE (1.0f)
#define EPS (0.000001f)
inline float sqrtOrZero(register float sq) { register float r = ZERO; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    Vec3 operator/(float s) const { Vec3 r; float inv = ONE / s; r.x = x * inv; r.y = y * inv; r.z = z * inv; return r; }
    void operator/=(float s) { float inv = ONE / s; x *= inv; y *= inv; z *= inv; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float length() const { return sqrtOrZero(lenSq()); }
};
struct Sphere { Vec3 c; float r; };
struct Cyl { Vec3 p; float len; Vec3 d; float pad; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B99DC(const Sphere* s, const Cyl* c, Hit* out) {
    float t = c->d.dot(s->c - c->p);
    if (t < EPS) {
        Vec3 q = s->c - c->d * t;
        Vec3 v = q - c->p;
        float l = v.length();
        if (!(l < EPS)) {
            Vec3 n = v / l;
            if (l > c->r) { n *= c->r; q = c->p + n; }
        }
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r) {
            out->pos = q;
            w /= dist; out->n = w;
            out->dist = dist;
            return 1;
        }
    } else if (t > c->len) {
        Vec3 q = s->c + c->d * (c->len - t);
        Vec3 e = c->p + c->d * c->len;
        Vec3 v = q - e;
        float l = v.length();
        if (!(l < EPS)) {
            Vec3 n = v / l;
            if (l > c->r) { n *= c->r; q = e + n; }
        }
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r) {
            out->pos = q;
            w /= dist; out->n = w;
            out->dist = dist;
            return 1;
        }
    } else {
        Vec3 q = c->p + c->d * t;
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r + c->r) {
            Vec3 n = w / dist;
            out->pos = q + n * c->r;
            out->n = n;
            out->dist = dist - c->r;
            return 1;
        }
    }
    return 0;
}
#undef ZERO
#undef ONE
#undef EPS
}
namespace w6_9D1C {
/* fn_801B9D1C (segment sweep against a capped cylinder).  What the match needed (GC/1.3.2 debugger dumps):
   - statement order f, e, planeA, tA, tB, pa, pb, planeB: the frontend numbers its CSE temporaries at the SECOND
     occurrence of a load, so c->p / c->d get theirs interleaved per component (y, x, z) in the planeA dot, before
     s->p (pa) and s->d; computing f before e gives the pre-RA schedule of the first block.
   - dir is first cleared in x, z, y member order (dead stores, no code) and then assigned pb - pa: field
     temporaries are numbered by FIRST assignment, so dir.y gets the lowest virtual register of the three, is
     scanned first and stays (31 neighbours) in the high-degree set with the loads, while the subtraction still
     evaluates pb's products in x, y, z order.
   - L comes from length() through one more inline level (len()): the sqrt result is then numbered below f / pa.
   - 0.000001 is read through a different expression at every use so that the frontend makes no CSE temporary
     (the backend merges the identical loads).  The plain literal 0.000001f at all eight uses gives the same
     code as EXACT-MOD-POOL (3 pool refs to 0.000001f) and is presumably the original spelling.
   - uh = u - h is a named local. */
#define EPS0 (0.000001f)
#define EPS1 (0.000001f)
#define EPS2 (0.000001f)
#define EPS3 (0.000001f)
#define EPS4 (0.000001f)
#define EPS5 (0.000001f)
#define EPS6 (0.000001f)
#define EPS7 (0.000001f)
inline float rsqrt(register float x) { register float r; asm { frsqrte r, x } return r; }
inline float sqrtOrZero(register float sq) { register float r = 0.0f; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    void clear() { x = 0.0f; z = 0.0f; y = 0.0f; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
    float length() const { return sqrtOrZero(x * x + y * y + z * z); }
    float len() const { return length(); }
    Vec3& normalize() { float s = rsqrt(lenSq()); x *= s; y *= s; z *= s; return *this; }
};
struct Seg { Vec3 p; float len; Vec3 d; float pad; };
struct Cyl { Vec3 p; float len; Vec3 d; float pad; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B9D1C(const Seg* s, const Cyl* c, Hit* out) {
    Vec3 f = c->p + c->d * c->len;
    Vec3 e = s->p + s->d * s->len;
    float planeA = -c->d.dot(c->p);
    float tA = (s->p - c->p).dot(c->d);
    float tB = (e - c->p).dot(c->d);
    Vec3 pa = s->p - c->d * tA;
    Vec3 pb = e - c->d * tB;
    float planeB = -c->d.dot(f);
    Vec3 dir;
    dir.clear();
    dir = pb - pa;
    float L = dir.len();
    if (L > EPS0) {
        float inv = 1.0f / L;
        dir.x *= inv; dir.y *= inv; dir.z *= inv;
    }
    float rr = c->r * c->r;
    float u = (c->p - pa).dot(dir);
    float d2 = (dir * u + pa).distSq(c->p);
    if (d2 > rr) return 0;
    if (s->d.dot(c->d) > EPS1) {
        float dA = planeA + c->d.dot(s->p);
        if (dA < EPS2) {
            out->dist = -(dA / c->d.dot(s->d));
            if (out->dist > EPS3 && out->dist < s->len) {
                out->pos = s->d * out->dist + s->p;
                if ((out->pos - c->p).lenSq() < rr) { out->n = -c->d; return 1; }
            }
        }
    } else {
        float dB = planeB + c->d.dot(s->p);
        if (dB > EPS4) {
            out->dist = -(dB / c->d.dot(s->d));
            if (out->dist > EPS5 && out->dist < s->len) {
                out->pos = s->d * out->dist + s->p;
                if ((out->pos - f).lenSq() < rr) { out->n = c->d; return 1; }
            }
        }
    }
    float h = sqrtOrZero(rr - d2);
    float uh = u - h;
    out->dist = uh * s->len / L;
    if (out->dist > EPS6 && out->dist < s->len) {
        out->pos = s->p + s->d * out->dist;
        float v = (out->pos - c->p).dot(c->d);
        if (v < EPS7 || v > c->len) return 0;
        out->n = (pa + dir * uh - c->p).normalize();
        return 1;
    }
    return 0;
}
#undef EPS0
#undef EPS1
#undef EPS2
#undef EPS3
#undef EPS4
#undef EPS5
#undef EPS6
#undef EPS7
}
namespace w3_2_A38C {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801BA38C(const Capsule* r, const Sphere* s) {
    float rr = s->r * s->r;
    float t = (s->c - r->p).dot(r->d);
    if ((r->d * t + r->p).distSq(s->c) > rr) return 0;
    if (t < 0.000001f) return (r->p - s->c).lenSq() < rr;
    if (t > r->len) return (r->p + r->d * r->len - s->c).lenSq() < rr;
    return 1;
}
}

#undef EPS
#undef CR
#undef ZERO
#undef ONE
#undef M1
#undef P1
#undef Z0

}
