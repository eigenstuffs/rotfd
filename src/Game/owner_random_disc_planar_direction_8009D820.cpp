/* fn_8009D820: picks a random point on a disc of radius 0x3A8 (fn_801F1200 =
   random unit float, lbl_80378DCC = full-turn angle scale, fn_8028506C/
   fn_80284FA8 = cos/sin) around the agent's center (0x390), and stores the
   normalized planar (XZ) direction from the position of the entity resolved
   through virtual getHandle(0) (slot 0x9C) to that point in the direction
   field (0x39C). lbl_80378DA8 (0.0f) is the pooled planar Y; as in
   actor_random_planar_direction_800CCCEC.cpp the y*y term of the length sum
   folds to that constant, so the sum reads d.y once as the addend. The random
   factor is assigned before scaling by the radius (r = rand; r *= radius),
   which fixes the operand order of the first product. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return*this;}
 Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
};
struct Geometry{char unknown00[0x30];Vec3 position;};
struct Entity{char unknown00[0x124];Geometry*geometry;};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Prefix{char unknown00[8];};
struct Agent:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int); /* vtable +0x9C */
 char unknown0C[0x390-0xC];
 Vec3 center;    /* 0x390 */
 Vec3 direction; /* 0x39C */
 float radius;   /* 0x3A8 */
};
extern "C"{float fn_801F1200(void);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" const float lbl_80378DCC; /* angle scale */
extern "C" const float lbl_80378DA8; /* 0.0f */
extern "C" void fn_8009D820(Agent*self){
 float radius=self->radius;
 float r=fn_801F1200();
 r*=radius;
 float angle=lbl_80378DCC*fn_801F1200();
 Vec3 offset;
 offset.x=r*fn_8028506C(angle);
 offset.z=r*fn_80284FA8(angle);
 offset.y=lbl_80378DA8;
 Vec3 point=self->center+offset;
 const Vec3&p=resolve(*self->getHandle(0))->geometry->position;
 Vec3 d(point.x-p.x,lbl_80378DA8,point.z-p.z);
 float inv=reciprocalSqrt(d.x*d.x+d.y+d.z*d.z);
 d.x*=inv;d.y*=inv;d.z*=inv;
 self->direction=d;
}
