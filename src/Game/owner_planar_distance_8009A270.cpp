/* Planar (XZ) distance from the owner geometry position (resolved twice from
   virtual query(0), slot 0x9C) to the point at 0x3C4, written to *out.
   Same layout as owner_planar_direction_8009A6D4.cpp (ox declared first fixes
   the FPR assignment). The planar difference is built by an inline helper
   that returns its result through get() (the dead stack copy at 0x8), and
   the file uses fp_contract off (no fmadds), like the neighbor
   actor_vector_interpolation_8009b7d0.cpp. The engine square root is the
   bare reciprocal of a reciprocal-square-root estimate (frsqrte into f4,
   then fres), written as the shared minimal inline asm math helper. */
#pragma fp_contract off
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);char unknownC[0x124-0xC];Geometry*geometry;char unknown128[0x3C4-0x128];Vec3 point;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
extern "C" const float lbl_80378D10; /* 0.0f */
inline Node*resolve(const Handle&h){const Entry*entries=lbl_801E9D24.manager->entries;int index=h.bits.index;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec2{float x,y;Vec2(){}Vec2(float ax,float ay):x(ax),y(ay){}
 const Vec2&get()const{return *this;}
 float length()const{float sq=x*x+y*y;float r=lbl_80378D10;if(sq!=r)r=fastSqrt(sq);return r;}};
inline Vec2 planarDifference(float ax,float ay,float bx,float by){Vec2 r(ax-bx,ay-by);return r.get();}
extern "C" void fn_8009A270(Node*self,float*out){
 float ox;float x=self->point.x;float z=self->point.z;
 ox=resolve(self->query(0))->geometry->position.x;
 float oz=resolve(self->query(0))->geometry->position.z;
 *out=planarDifference(x,z,ox,oz).length();
}
