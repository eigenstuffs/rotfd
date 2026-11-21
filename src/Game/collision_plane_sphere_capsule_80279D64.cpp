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
   lbl_8037B740..lbl_8037B754 owned by Game/render_transform_constants.c.
   Each function keeps its own private struct views in a namespace (the
   functions are extern "C", so the namespaces do not change symbol names);
   fn_8027B140 is declared once with the nsB140 types and callers cast.
   The K* spellings are distinct read forms of one extern label
   (pooled-literal emulation, scratch/claude_match/GUIDE.md). */
namespace nsB140 { struct Sphere; struct Vertex; struct Hit; }
extern "C" signed char fn_8027B140(const nsB140::Sphere* sphere, const nsB140::Vertex* a, const nsB140::Vertex* b, nsB140::Hit* out);

namespace ns9D64 {
/* fn_80279D64: swept sphere (capsule) vs triangle with a precomputed plane.
   Part of auto_03_80279558_text (GC/1.3.2, -O4,p, fp_contract on, no exceptions).
   The plane-side test passes the plane normal as three scalars (dot3): this
   fixes the plane x/y FPR colouring (CSE temps are created in the order of
   the inline arguments).  K* are distinct read forms of one pooled label. */
typedef unsigned long Word;
extern "C" { extern const float lbl_8037B744, lbl_8037B74C, lbl_8037B750, lbl_8037B754; }
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
 Point4(float a,float b,float c):Point3(a,b,c),w(lbl_8037B74C){}
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
 if(self->direction.dot(*plane)>=K0(lbl_8037B750))return 0;
 const Point3& delta=self->position-*a;
 float side=delta.dot3(plane->x,plane->y,plane->z);
 if(side<=K1(lbl_8037B750))return 0;
 if(side<=self->radius){
  Point3 av=*a-self->position;
  Point3 bv=*b-self->position;
  if(crossW(av,bv,K0(lbl_8037B74C)).dot(*plane)<K0(lbl_8037B754))return 0;
  Point3 cv=*c-self->position;
  if(crossW(bv,cv,K1(lbl_8037B74C)).dot(*plane)<K1(lbl_8037B754))return 0;
  if(crossW(cv,av,K2(lbl_8037B74C)).dot(*plane)<K2(lbl_8037B754))return 0;
  out->point=self->position;
  out->distance=lbl_8037B744;
  out->normal=*plane;
  return 1;
 }
 out->distance=(self->radius-side)/plane->dot(self->direction);
 if(out->distance<K0(lbl_8037B750)||out->distance>self->distance)return 0;
 out->point=self->direction*out->distance+self->position;
 Point3 av=*a-out->point;
 Point3 bv=*b-out->point;
 if(crossW(av,bv,K0(lbl_8037B74C)).dot(*plane)<K0(lbl_8037B754))return 0;
 Point3 cv=*c-out->point;
 if(crossW(bv,cv,K1(lbl_8037B74C)).dot(*plane)<K1(lbl_8037B754))return 0;
 if(crossW(cv,av,K2(lbl_8037B74C)).dot(*plane)<K2(lbl_8037B754))return 0;
 out->normal=*plane;
 return 1;
}

} /* namespace ns9D64 */
#undef K0
#undef K1
#undef K2

namespace nsA180 {
typedef unsigned long Word;
extern "C" { extern const float lbl_8037B74C, lbl_8037B750; }
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
 Point4(float a,float b,float c):Point3(a,b,c),w(lbl_8037B74C){}
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
 if(planeSide(*plane,*self,*a)<=lbl_8037B750)return 0;
 const Point3& delta=*self-*a;
 float depth=plane->dot(delta);
 if(depth>self->radius)return 0;
 out->point=*self-(*plane*planeSide(*plane,*self,*a));
 out->normal=*plane;
 Point3 av=*a-out->point;
 Point3 bv=*b-out->point;
 if(crossW(av,bv,K0(lbl_8037B74C)).dot(*plane)<lbl_8037B750)return edgeTest(self,a,b,out);
 Point3 cv=*c-out->point;
 if(crossW(bv,cv,K1(lbl_8037B74C)).dot(*plane)<lbl_8037B750)return edgeTest(self,b,c,out);
 if(crossW(cv,av,K2(lbl_8037B74C)).dot(*plane)<lbl_8037B750)return edgeTest(self,c,a,out);
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
