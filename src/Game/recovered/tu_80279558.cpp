/* Merged TU auto_03_80279558_text: .text 0x80279558-0x8027B2E4, .sdata2 0x8037B740-0x8037B758.
   GC/1.3.2 -O4,p -fp_contract on -use_lmw_stmw on, exceptions/RTTI off.
   .sdata2 is the compiler literal pool in first-use order: -1.0f, 0.0f, 0.999f, 1.0f
   (fn_80279558), 1.0e-6f, -1.0e-4f (fn_80279D64). */

namespace nsB140 { struct Sphere; struct Vertex; struct Hit; }
extern "C" signed char fn_8027B140(const nsB140::Sphere* sphere, const nsB140::Vertex* a, const nsB140::Vertex* b, nsB140::Hit* out);

namespace ns9558 {
/* fn_80279558: segment vs grid quad (two triangles a,b,c / b,d,c with one
   normal per triangle). First member of the collision primitive TU
   auto_03_80279558_text (GC/1.3.2, -O4,p, fp_contract on, no exceptions).
   Float literals -1.0f, 0.0f, 0.999f, 1.0f are written as literals: this unit
   owns .sdata2 0x8037B740..0x8037B74C (in that order).
   The odd per-site helpers (named scalar locals, sub-/dotK- variants, mixed
   *(const float*)& spellings, dead initialisers) only steer the frontend's
   temp numbering so the FPR colouring matches; the code is identical. */
extern "C" {
 /* -1.0f */
 /* 0.0f */
 /* 0.999f */
 /* 1.0f */
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 plusA(const Vec3& r) const { float X = x + r.x; float Y = y + r.y; float Z = z + r.z; return Vec3(X, Y, Z); }
    Vec3 plusM(const Vec3& r) const { Vec3 v; v.x = x + r.x; v.y = y + r.y; v.z = z + r.z; return v; }
    Vec3 plusMX(const Vec3& r) const { Vec3 v; v.x = x + r.x; v.z = z + r.z; v.y = y + r.y; return v; }
    Vec3 plusL(const Vec3& r) const { float Z; float Y; float X = x + r.x; Y = y + r.y; Z = z + r.z; return Vec3(X, Y, Z); }
    Vec3 plusX(const Vec3& r) const { float X = x + r.x; float Z = z + r.z; float Y = y + r.y; return Vec3(X, Y, Z); }
    float dotS(float X, float Y, float Z) const { return x * X + y * Y + z * Z; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float dotKy(const Vec3& v) const { return x * v.x + y * *(const float*)&v.y + z * v.z; }
    float dotKyz(const Vec3& v) const { return x * v.x + y * *(const float*)&v.y + z * *(const float*)&v.z; }
    float dotKx(const Vec3& v) const { return x * *(const float*)&v.x + y * v.y + z * v.z; }
};
struct Vertex : Vec3 {
    float w;
};
inline Vec3 crossA(float ax, float ay, float az, const Vec3& b) { return Vec3(ay * b.z - az * b.y, az * b.x - ax * b.z, ax * b.y - ay * b.x); }
inline Vec3 crossB(const Vec3& a, float bx, float by, float bz) { return Vec3(a.y * bz - a.z * by, a.z * bx - a.x * bz, a.x * by - a.y * bx); }
inline Vec3 crossSS(float ax, float ay, float az, float bx, float by, float bz) { return Vec3(ay * bz - az * by, az * bx - ax * bz, ax * by - ay * bx); }
inline Vec3 cross(const Vec3& a, const Vec3& b) { return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
inline Vec3 subL(const Vec3&p,const Vec3&q){float z;float y;float x=p.x-q.x;y=p.y-q.y;z=p.z-q.z; return Vec3(x,y,z);}
inline Vec3 subA(const Vec3&p,const Vec3&q){float x=p.x-q.x;float y=p.y-q.y;float z=p.z-q.z; return Vec3(x,y,z);}
inline Vec3 subM(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-q.x; r.y=p.y-q.y; r.z=p.z-q.z; return r;}
inline Vec3 subZ(const Vec3&p,const Vec3&q){float z=p.z-q.z;float y=p.y-q.y;float x=p.x-q.x; return Vec3(x,y,z);}
inline Vec3 subO2(const Vec3&p,const Vec3&q){return p-q;}
inline Vec3 subMZ(const Vec3&p,const Vec3&q){Vec3 r; r.z=p.z-q.z; r.y=p.y-q.y; r.x=p.x-q.x; return r;}
inline Vec3 subMX(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subX(const Vec3&p,const Vec3&q){float x=p.x-q.x;float z=p.z-q.z;float y=p.y-q.y; return Vec3(x,y,z);}
inline Vec3 addA(const Vec3&p,const Vec3&q){float x=p.x+q.x;float y=p.y+q.y;float z=p.z+q.z; return Vec3(x,y,z);}
inline Vec3 addL(const Vec3&p,const Vec3&q){float z;float y;float x=p.x+q.x;y=p.y+q.y;z=p.z+q.z; return Vec3(x,y,z);}
inline Vec3 addM(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x+q.x; r.y=p.y+q.y; r.z=p.z+q.z; return r;}
inline Vec3 addMX(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x+q.x; r.z=p.z+q.z; r.y=p.y+q.y; return r;}
inline Vec3 addX(const Vec3&p,const Vec3&q){float x=p.x+q.x;float z=p.z+q.z;float y=p.y+q.y; return Vec3(x,y,z);}
inline Vec3 mulM(const Vec3&p,float f){Vec3 r; r.x=p.x*f; r.y=p.y*f; r.z=p.z*f; return r;}
inline Vec3 mulA(const Vec3&p,float f){float x=p.x*f;float y=p.y*f;float z=p.z*f; return Vec3(x,y,z);}
inline Vec3 subL2(const Vec3&p,const Vec3&q){return subL(p,q);}
inline Vec3 mulL(const Vec3&p,float f){float z=p.z*f;float y=p.y*f;float x=p.x*f; return Vec3(x,y,z);}
inline Vec3 mulL2(const Vec3&p,float f){return mulL(p,f);}
inline Vec3 mulO(const Vec3&p,float f){return p*f;}
inline Vec3 subA2(const Vec3&p,const Vec3&q){return subA(p,q);}
inline Vec3 subA3(const Vec3&p,const Vec3&q){return subA2(p,q);}
inline Vec3 subM2(const Vec3&p,const Vec3&q){return subM(p,q);}
inline Vec3 subM3(const Vec3&p,const Vec3&q){return subM2(p,q);}
inline Vec3 subZ2(const Vec3&p,const Vec3&q){return subZ(p,q);}
inline Vec3 subZ3(const Vec3&p,const Vec3&q){return subZ2(p,q);}
inline Vec3 subMZ2(const Vec3&p,const Vec3&q){return subMZ(p,q);}
inline Vec3 subMZ3(const Vec3&p,const Vec3&q){return subMZ2(p,q);}
inline Vec3 subMX2(const Vec3&p,const Vec3&q){return subMX(p,q);}
inline Vec3 subMX3(const Vec3&p,const Vec3&q){return subMX2(p,q);}
inline Vec3 subX2(const Vec3&p,const Vec3&q){return subX(p,q);}
inline Vec3 subX3(const Vec3&p,const Vec3&q){return subX2(p,q);}
inline Vec3 subL3(const Vec3&p,const Vec3&q){return subL2(p,q);}
inline Vec3 subMKxy(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-*(const float*)&q.x; r.y=p.y-*(const float*)&q.y; r.z=p.z-q.z; return r;}
inline Vec3 subMKx(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-*(const float*)&q.x; r.y=p.y-q.y; r.z=p.z-q.z; return r;}
inline Vec3 subMKy(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-q.x; r.y=p.y-*(const float*)&q.y; r.z=p.z-q.z; return r;}
inline Vec3 subMXKx(const Vec3&p,const Vec3&q){Vec3 r; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subMZKx(const Vec3&p,const Vec3&q){Vec3 r; r.z=p.z-q.z; r.y=p.y-q.y; r.x=p.x-*(const float*)&q.x; return r;}
inline Vec3 subMXKxD(const Vec3&p,const Vec3&q){Vec3 r; r.z=0.0f; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subMXKxE(const Vec3&p,const Vec3&q){Vec3 r; r.x=0.0f; r.z=0.0f; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subMXKxF(const Vec3&p,const Vec3&q){Vec3 r; r.z=r.z; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subMXKxG(const Vec3&p,const Vec3&q){Vec3 r; r.y=0.0f; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subMXKxH(const Vec3&p,const Vec3&q){Vec3 r; r.x=0.0f; r.y=0.0f; r.x=p.x-*(const float*)&q.x; r.z=p.z-q.z; r.y=p.y-q.y; return r;}
inline Vec3 subLKx(const Vec3&p,const Vec3&q){float z;float y;float x=p.x-*(const float*)&q.x;y=p.y-q.y;z=p.z-q.z; return Vec3(x,y,z);}
inline Vec3 subLKx2(const Vec3&p,const Vec3&q){return subLKx(p,q);}
struct Query {
    Vec3 position;
    float distance;
    Vec3 direction;
    float unknown1C;
};
struct Hit {
    Vec3 position;
    float distance;
    Vec3 normal;
};

extern "C" signed char fn_80279558(const Query* self, const Vertex* a, const Vertex* b, const Vertex* c, const Vertex* d, const Vertex* normal, Hit* out)
{
    signed char result = 0;
    float bx, by, bz;
    Vec3 bp = subL3(*b,self->position);
    Vec3 seg = mulL(self->direction,self->distance);
    out->distance = -1.0f;
    if (normal[0].x == normal[1].x && normal[0].y == normal[1].y && normal[0].z == normal[1].z) {
        if (normal[0].w) {
            const Vertex& n = normal[0];
            if (self->direction.dot(n) > 0.0f) return 0;
            float num = n.dot(bp);
            float denom = n.dot(seg);
            if (denom == 0.0f) return 0;
            float t = 0.999f * (num / denom);
            if (t < 0.0f || t > 1.0f) return 0;
            out->distance = t * self->distance;
            out->position = self->direction * out->distance + self->position;
            Vec3 bv = *b - out->position;
            Vec3 cv = subMXKxH(*c, out->position);
            if (cross(bv, cv).dot(n) > 0.0f) {
                Vec3 av = subL2(*a, out->position);
                if (cross(av, bv).dotKyz(n) < 0.0f) return 0;
                if (cross(cv, av).dot(n) < 0.0f) return 0;
            } else {
                Vec3 dv = subM(*d, out->position);
                if (cross(bv, dv).dot(n) < 0.0f) return 0;
                if (cross(dv, cv).dot(n) < 0.0f) return 0;
            }
            out->normal = n;
            return 1;
        }
    } else {
        {
            const Vertex& n = normal[0];
            if (!n.w) goto second;
            if (self->direction.dot(n) > 0.0f) goto second;
            float num = n.dot(bp);
            float denom = n.dot(seg);
            if (denom == 0.0f) goto second;
            float t = 0.999f * (num / denom);
            if (t < 0.0f || t > 1.0f) goto second;
            out->distance = t * self->distance;
            out->position = mulL(self->direction, out->distance) + self->position;
            Vec3 av = subZ(*a, out->position);
            bx = b->x - *(const float*)&out->position.x; bz = b->z - out->position.z; by = b->y - out->position.y;
            Vec3 cv = subA3(*c, out->position);
            if (crossB(av, bx, by, bz).dot(n) < 0.0f) {
                out->distance = -1.0f;
                goto second;
            }
            if (crossA(bx, by, bz, cv).dotKyz(n) < 0.0f) {
                out->distance = -1.0f;
                goto second;
            }
            if (cross(cv, av).dot(n) < 0.0f) {
                out->distance = -1.0f;
                goto second;
            }
            out->normal = n;
            result = 1;
        }
    second:
        {
            const Vertex& n = normal[1];
            float b3x, b3y, b3z, c3x, c3y, c3z;
            if (!n.w) goto done;
            if (self->direction.dot(n) > 0.0f) goto done;
            float num = n.dot(bp);
            float denom = n.dot(seg);
            if (denom == 0.0f) goto done;
            float t = 0.999f * (num / denom);
            if (t < 0.0f || t > 1.0f) goto done;
            float dist = t * self->distance;
            if (out->distance != -1.0f && dist >= out->distance) goto done;
            Vec3 p = (self->direction * dist).plusM(self->position);
            c3x = c->x - p.x; c3z = c->z - p.z; c3y = c->y - p.y;
            b3x = b->x - p.x; b3y = b->y - p.y; b3z = b->z - p.z;
            if (crossSS(c3x, c3y, c3z, b3x, b3y, b3z).dot(n) < 0.0f) goto done;
            Vec3 dv = subL2(*d, p);
            if (crossA(b3x, b3y, b3z, dv).dot(n) < 0.0f) goto done;
            if (crossB(dv, c3x, c3y, c3z).dot(n) < 0.0f) goto done;
            out->position = p;
            out->distance = dist;
            out->normal = n;
            result = 1;
        }
    }
done:
    return result;
}

} /* namespace ns9558 */

// Partial text split: fn_80279D64 (capsule vs triangle with a given plane)
// and fn_8027A180 (sphere vs triangle with a given plane). fn_80279558 before
// them and fn_8027A410..fn_8027B140 after them (95.8-99.3%) remain original
// code; full draft: scratch/claude_match/auto_03_80279558_text/retry2/final.cpp.
/* auto_03_80279558_text (0x80279558..0x8027B2E4): collision primitive
   queries of one engine translation unit -- segment vs grid quad
   (fn_80279558), capsule vs triangle with a precomputed plane (fn_80279D64),
   sphere vs triangle with a precomputed plane (fn_8027A180), capsule vs
   triangle (fn_8027A410), sphere vs triangle (fn_8027AA38), segment vs
   triangle (fn_8027AD94) and sphere vs segment edge (fn_8027B140).
   This file holds: fn_80279D64, fn_8027A180.
   GC/1.3.2, -O4,p, fp_contract on, C++ without exceptions (no extab); the
   unit owns no data.  The float literals are the pooled labels
   -1.0f..-1.0e-4f owned by Game/render_transform_constants.c.
   Each function keeps its own private struct views in a namespace (the
   functions are extern "C", so the namespaces do not change symbol names);
   fn_8027B140 is declared once with the nsB140 types and callers cast.
   The K* spellings are distinct read forms of one extern label
   (pooled-literal emulation, scratch/claude_match/GUIDE.md). */

namespace ns9D64 {
/* fn_80279D64: swept sphere (capsule) vs triangle with a precomputed plane.
   Part of auto_03_80279558_text (GC/1.3.2, -O4,p, fp_contract on, no exceptions).
   The plane-side test passes the plane normal as three scalars (dot3): this
   fixes the plane x/y FPR colouring (CSE temps are created in the order of
   the inline arguments).  K* are distinct read forms of one pooled label. */
typedef unsigned long Word;
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
struct Point3 {
 float x,y,z;
 Point3() {}
 Point3(float a,float b,float c):x(a),y(b),z(c){}
 Point3 operator-(const Point3&v)const{return Point3(x-v.x,y-v.y,z-v.z);}
 Point3 operator*(float k)const{return Point3(x*k,y*k,z*k);}
 float dot(const Point3&v)const{return x*v.x+y*v.y+z*v.z;}
 float dot3(float X,float Y,float Z)const{return x*X+y*Y+z*Z;}
 Point3 operator+(const Point3&v)const{return Point3(x+v.x,y+v.y,z+v.z);}
 Point3&operator=(const Point3&v){x=v.x;y=v.y;z=v.z;return *this;}
};
struct Point4:Point3 {
 float w;
 Point4(float a,float b,float c):Point3(a,b,c),w(1.0f){}
 Point4(float a,float b,float c,float d):Point3(a,b,c),w(d){}
};
static inline Point4 crossW(const Point3&a,const Point3&b,float w){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x,w);
}
static inline Point4 cross(const Point3&a,const Point3&b){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
struct Result {Point3 point;float distance;Point3 normal;Word unknown1C;float unknown20,unknown24;Word unknown28,unknown2C;};
struct Capsule {Point3 position;float distance;Point3 direction;float radius;};
extern "C" signed char fn_80279D64(const Capsule*self,const Point4*a,const Point4*b,const Point4*c,const Point4*plane,Result*out){
 if(self->direction.dot(*plane)>=1.0e-6f)return 0;
 const Point3& delta=self->position-*a;
 float side=delta.dot3(plane->x,plane->y,plane->z);
 if(side<=1.0e-6f)return 0;
 if(side<=self->radius){
  Point3 av=*a-self->position;
  Point3 bv=*b-self->position;
  if(crossW(av,bv,1.0f).dot(*plane)<-1.0e-4f)return 0;
  Point3 cv=*c-self->position;
  if(crossW(bv,cv,1.0f).dot(*plane)<-1.0e-4f)return 0;
  if(crossW(cv,av,1.0f).dot(*plane)<-1.0e-4f)return 0;
  out->point=self->position;
  out->distance=0.0f;
  out->normal=*plane;
  return 1;
 }
 out->distance=(self->radius-side)/plane->dot(self->direction);
 if(out->distance<1.0e-6f||out->distance>self->distance)return 0;
 out->point=self->direction*out->distance+self->position;
 Point3 av=*a-out->point;
 Point3 bv=*b-out->point;
 if(crossW(av,bv,1.0f).dot(*plane)<-1.0e-4f)return 0;
 Point3 cv=*c-out->point;
 if(crossW(bv,cv,1.0f).dot(*plane)<-1.0e-4f)return 0;
 if(crossW(cv,av,1.0f).dot(*plane)<-1.0e-4f)return 0;
 out->normal=*plane;
 return 1;
}

} /* namespace ns9D64 */
#undef K0
#undef K1
#undef K2

namespace nsA180 {
typedef unsigned long Word;
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))
struct Point3 {
 float x,y,z;
 Point3() {}
 Point3(float a,float b,float c):x(a),y(b),z(c){}
 Point3 operator-(const Point3&v)const{return Point3(x-v.x,y-v.y,z-v.z);}
 Point3 operator*(float k)const{return Point3(x*k,y*k,z*k);}
 float dot(const Point3&v)const{return x*v.x+y*v.y+z*v.z;}
};
struct Point4:Point3 {
 float w;
 Point4(float a,float b,float c):Point3(a,b,c),w(1.0f){}
 Point4(float a,float b,float c,float d):Point3(a,b,c),w(d){}
};
static inline Point4 crossW(const Point3&a,const Point3&b,float w){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x,w);
}
static inline Point4 cross(const Point3&a,const Point3&b){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
struct Sphere:Point3 {float radius;};
static inline float planeSide(const Point3&n,const Point3&p,const Point3&o){float d=n.dot(o);return n.dot(p)-d;}
struct Result {Point3 point;float distance;Point3 normal;Word unknown1C;float unknown20,unknown24;Word unknown28,unknown2C;};
static inline signed char edgeTest(Sphere*s,const Point4*a,const Point4*b,Result*o){return ::fn_8027B140((const nsB140::Sphere*)s,(const nsB140::Vertex*)a,(const nsB140::Vertex*)b,(nsB140::Hit*)o);}
extern "C" signed char fn_8027A180(Sphere*self,const Point4*a,const Point4*b,const Point4*c,const Point4*plane,Result*out){
 if(planeSide(*plane,*self,*a)<=1.0e-6f)return 0;
 const Point3& delta=*self-*a;
 float depth=plane->dot(delta);
 if(depth>self->radius)return 0;
 out->point=*self-(*plane*planeSide(*plane,*self,*a));
 out->normal=*plane;
 Point3 av=*a-out->point;
 Point3 bv=*b-out->point;
 if(crossW(av,bv,1.0f).dot(*plane)<1.0e-6f)return edgeTest(self,a,b,out);
 Point3 cv=*c-out->point;
 if(crossW(bv,cv,1.0f).dot(*plane)<1.0e-6f)return edgeTest(self,b,c,out);
 if(crossW(cv,av,1.0f).dot(*plane)<1.0e-6f)return edgeTest(self,c,a,out);
 out->distance=depth;
 return 1;
}

} /* namespace nsA180 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5

/* auto_03_80279558_text (0x80279558..0x8027B2E4): collision primitive
   queries of one engine translation unit -- segment vs grid quad
   (fn_80279558), capsule vs triangle with a precomputed plane (fn_80279D64),
   sphere vs triangle with a precomputed plane (fn_8027A180), capsule vs
   triangle (fn_8027A410), sphere vs triangle (fn_8027AA38), segment vs
   triangle (fn_8027AD94) and sphere vs segment edge (fn_8027B140).
   This file holds: fn_8027A410, fn_8027AA38.
   GC/1.3.2, -O4,p, fp_contract on, C++ without exceptions (no extab); the
   unit owns no data.  The float literals are the pooled labels
   -1.0f..-1.0e-4f owned by Game/render_transform_constants.c.
   Each function keeps its own private struct views in a namespace (the
   functions are extern "C", so the namespaces do not change symbol names);
   fn_8027B140 is declared once with the nsB140 types and callers cast.
   The K* spellings are distinct read forms of one extern label
   (pooled-literal emulation, scratch/claude_match/GUIDE.md). */

namespace nsA410 {
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))
#ifndef E0
#define E0 K0
#define E1 K1
#define E2 K2
#define E3 K0
#define E4 K1
#define E5 K2
#endif
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float dotv(Vec3 v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    float length() const { float sq = lengthSq(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
};
struct Vertex : Vec3 {
    float w;
    Vertex() {}
    Vertex(float X, float Y, float Z, float W) : Vec3(X, Y, Z), w(W) {}
    Vertex(const Vec3& p) { x = p.x; y = p.y; z = p.z; w = 1.0f; }
    Vertex(const Vertex& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    Vertex& operator=(const Vertex& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    Vertex operator-(const Vertex& r) const { return Vertex(x - r.x, y - r.y, z - r.z, w - r.w); }
    Vertex cross(const Vec3& v) const { const Vec3* q = &v; return Vertex(y * q->z - z * q->y, z * q->x - x * q->z, x * q->y - y * q->x, 1.0f); }
};
struct Capsule {
    Vec3 position;
    float distance;
    Vec3 direction;
    float radius;
};
struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    unsigned long unknown1C;
    float unknown20, unknown24;
    unsigned long long unknown28;
};

extern "C" signed char fn_8027A410(const Capsule* self, const Vertex& a, const Vertex& b, const Vertex& c, Hit* out)
{
    out->normal.x = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
    out->normal.y = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
    out->normal.z = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    float length = out->normal.length();
    if (length <= 1.0e-6f) return 0;
    float inverse = 1.0f / length;
    out->normal.x *= inverse;
    out->normal.y *= inverse;
    out->normal.z *= inverse;
    if (self->direction.dot(out->normal) >= 0.0f) return 0;
    float side = (self->position - a).dot(out->normal);
    if (side <= 0.0f) return 0;
    if (side <= self->radius) {
        if ((a - Vertex(self->position)).cross(b - Vertex(self->position)).dot(out->normal) < -1.0e-4f) return 0;
        if ((b - Vertex(self->position)).cross(c - Vertex(self->position)).dot(out->normal) < -1.0e-4f) return 0;
        if ((c - Vertex(self->position)).cross(a - Vertex(self->position)).dot(out->normal) < -1.0e-4f) return 0;
        out->point = self->position;
        out->distance = 0.0f;
        return 1;
    }
    out->distance = (self->radius - side) / out->normal.dot(self->direction);
    if (out->distance < 0.0f || out->distance > self->distance) return 0;
    out->point = self->direction * out->distance + self->position;
    if ((a - Vertex(out->point)).cross(b - Vertex(out->point)).dotv(out->normal) < -1.0e-4f) return 0;
    if ((b - Vertex(out->point)).cross(c - Vertex(out->point)).dotv(out->normal) < -1.0e-4f) return 0;
    if ((c - Vertex(out->point)).cross(a - Vertex(out->point)).dotv(out->normal) < -1.0e-4f) return 0;
    return 1;
}

} /* namespace nsA410 */
#undef E0
#undef E1
#undef E2
#undef E3
#undef E4
#undef E5
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5

namespace nsAA38 {
typedef unsigned long Word;
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Normal;
struct Point3 {
 float x,y,z;
 Point3() {}
 Point3(float a,float b,float c):x(a),y(b),z(c){}
 Point3 operator-(const Point3&v)const{return Point3(x-v.x,y-v.y,z-v.z);}
 Point3 operator*(float k)const{return Point3(x*k,y*k,z*k);}
 float dot(const Point3&v)const{return x*v.x+y*v.y+z*v.z;}
 inline float dotN(Normal n)const;
 Point3&operator=(const Point3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Point3 cross(const Point3&v)const{return Point3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}
 float lengthSq()const{float xx=x*x;float yy=y*y;float zz=z*z;return xx+yy+zz;}
 float length()const{float sq=lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Normal{float x,y,z;Normal(const Point3&v):x(v.x),y(v.y),z(v.z){}Normal(const Normal&v):x(v.x),y(v.y),z(v.z){}};
inline float Point3::dotN(Normal n)const{return x*n.x+y*n.y+z*n.z;}
struct Point4:Point3 {
 float w;
 Point4(float a,float b,float c):Point3(a,b,c),w(1.0f){}
 Point4(float a,float b,float c,float d):Point3(a,b,c),w(d){}
};
static inline Point4 crossW(const Point3&a,const Point3&b,float w){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x,w);
}
static inline Point4 cross(const Point3&a,const Point3&b){
 return Point4(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
struct Sphere:Point3 {float radius;};
struct Result {Point3 point;float distance;Point3 normal;Word unknown1C;float unknown20,unknown24;Word unknown28,unknown2C;};
static inline signed char edgeTest(Sphere*s,const Point4*a,const Point4*b,Result*o){return ::fn_8027B140((const nsB140::Sphere*)s,(const nsB140::Vertex*)a,(const nsB140::Vertex*)b,(nsB140::Hit*)o);}
extern "C" signed char fn_8027AA38(Sphere*self,const Point4&a,const Point4&b,const Point4&c,Result*out){
 Point3 e1=b-a;
 Point3 e2=c-a;
 e2=e2;
 out->normal=e1.cross(e2);
 float length=out->normal.length();
 if(length<=0.0f)return 0;
 float inverse=1.0f/length;
 out->normal.x*=inverse;out->normal.y*=inverse;out->normal.z*=inverse;
 float da=out->normal.dot(a); float distance=out->normal.dot(*self)-da;
 if(distance<=0.0f)return 0;
 const Point3& delta=*self-a;
 float depth=out->normal.dot(delta);
 if(depth>self->radius)return 0;
 out->point=*self-(out->normal*distance);
 Point3 av=a-out->point;
 Point3 bv=b-out->point;
 if(crossW(av,bv,1.0f).dotN(out->normal)<0.0f)return edgeTest(self,&a,&b,out);
 Point3 cv=c-out->point;
 if(crossW(bv,cv,1.0f).dotN(out->normal)<0.0f)return edgeTest(self,&b,&c,out);
 if(crossW(cv,av,1.0f).dotN(out->normal)<0.0f)return edgeTest(self,&c,&a,out);
 out->distance=depth;
 return 1;
}

} /* namespace nsAA38 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5

// Partial text split: fn_8027AD94 (segment vs triangle) and fn_8027B140
// (sphere vs segment edge). fn_8027A410 (99.3%) and fn_8027AA38 (95.8%)
// before them remain original code; full draft:
// scratch/claude_match/auto_03_80279558_text/retry2/final_8027A410.cpp.
/* auto_03_80279558_text (0x80279558..0x8027B2E4): collision primitive
   queries of one engine translation unit -- segment vs grid quad
   (fn_80279558), capsule vs triangle with a precomputed plane (fn_80279D64),
   sphere vs triangle with a precomputed plane (fn_8027A180), capsule vs
   triangle (fn_8027A410), sphere vs triangle (fn_8027AA38), segment vs
   triangle (fn_8027AD94) and sphere vs segment edge (fn_8027B140).
   This file holds: fn_8027AD94, fn_8027B140.
   GC/1.3.2, -O4,p, fp_contract on, C++ without exceptions (no extab); the
   unit owns no data.  The float literals are the pooled labels
   -1.0f..-1.0e-4f owned by Game/render_transform_constants.c.
   Each function keeps its own private struct views in a namespace (the
   functions are extern "C", so the namespaces do not change symbol names);
   fn_8027B140 is declared once with the nsB140 types and callers cast.
   The K* spellings are distinct read forms of one extern label
   (pooled-literal emulation, scratch/claude_match/GUIDE.md). */

namespace nsAD94 {

#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq) { float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
inline float clampf2(float v, float lo, float hi) { if (v < lo) v = lo; else if (v > hi) v = hi; return v; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator/(float s) const { float inv = 1.0f / s; return Vec3(x * inv, y * inv, z * inv); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    /* normal passed as scalars, last component first: sets the order of the
       normal CSE temps (FPR colouring) */
    float dot3r(float Z, float Y, float X) const { return x * X + y * Y + z * Z; }
    float lengthSq() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    float magnitude() const { float sq = x * x + y * y + z * z; float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
    float length() const { float sq = lengthSq(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
};

struct Vertex : Vec3 {
    float w;
    Vertex() {}
    Vertex(float X, float Y, float Z, float W) : Vec3(X, Y, Z), w(W) {}
};
inline Vertex cross(const Vec3& a, const Vec3& b) { return Vertex(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 1.0f); }
struct Query {
    Vec3 position;
    float distance;
    Vec3 direction;
    float unknown1C;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    unsigned long unknown1C;
    float unknown20, unknown24;
    unsigned long long unknown28;
};

extern "C" signed char fn_8027AD94(const Query* self, const Vertex* a, const Vertex* b, const Vertex* c, Hit* out)
{
    out->normal.x = a->y * (b->z - c->z) + b->y * (c->z - a->z) + c->y * (a->z - b->z);
    out->normal.y = a->z * (b->x - c->x) + b->z * (c->x - a->x) + c->z * (a->x - b->x);
    out->normal.z = a->x * (b->y - c->y) + b->x * (c->y - a->y) + c->x * (a->y - b->y);
    float length = out->normal.length();
    if (length <= 1.0e-6f) return 0;
    float inverse = 1.0f / length;
    out->normal.x *= inverse;
    out->normal.y *= inverse;
    out->normal.z *= inverse;
    float plane = -out->normal.dot(*a);
    float side = plane + out->normal.dot(self->position);
    if (side <= 0.0f) return 0;
    out->distance = -(side / out->normal.dot(self->direction));
    if (out->distance < 0.0f || out->distance > self->distance) return 0;
    out->point = self->direction * out->distance + self->position;
    Vec3 av = *a - out->point;
    Vec3 bv = *b - out->point;
    if (cross(av, bv).dot(out->normal) < -1.0e-4f) return 0;
    Vec3 cv = *c - out->point;
    if (cross(bv, cv).dot3r(out->normal.z, out->normal.y, out->normal.x) < -1.0e-4f) return 0;
    if (cross(cv, av).dot(out->normal) < -1.0e-4f) return 0;
    return 1;
}

} /* namespace nsAD94 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5

namespace nsB140 {

#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq) { float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
/* clamp to [0, hi]; the zero bound is read through two distinct label forms */
inline float clampLH(float v, float hi) { if (v < 0.0f) v = 0.0f; else if (v > hi) v = hi; return v; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator/(float s) const { float inv = 1.0f / s; return Vec3(x * inv, y * inv, z * inv); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    Vec3& operator/=(float s) { float inv = 1.0f / s; x *= inv; y *= inv; z *= inv; return *this; }
    float magnitude() const { float sq = x * x + y * y + z * z; float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
    float length() const { float sq = lengthSq(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
};

struct Vertex : Vec3 {
    float w;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    unsigned long unknown1C;
    float unknown20, unknown24;
    unsigned long long unknown28;
};

extern "C" signed char fn_8027B140(const Sphere* sphere, const Vertex* a, const Vertex* b, Hit* out)
{
    Vec3 d = *b - *a;
    float len = d.magnitude();
    Vec3 v = sphere->center - *a;
    d /= len;
    float t = v.dot(d);
    t = clampLH(t, len);
    Vec3 p = *a + d * t;
    float dist = sqrtOrZero((p - sphere->center).lengthSq());
    float inv = 1.0f / dist;
    Vec3 n = (sphere->center - p) * inv;
    if (dist < sphere->radius) {
        Hit hit;
        hit.distance = dist;
        hit.point = p;
        hit.normal = n;
        *out = hit;
        return 1;
    }
    return 0;
}

} /* namespace nsB140 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5
