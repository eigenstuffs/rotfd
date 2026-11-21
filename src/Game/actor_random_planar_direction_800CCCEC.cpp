/* fn_800CCCEC: picks a random point within radius lbl_803796C4 (5.0) at a
   random angle (lbl_803796C8 = 2*pi, fn_801F1200 = random unit float) around
   the position of the entity resolved through the actor's handle slot 0x9C,
   and stores the normalized planar (XZ) direction from that position to the
   point in the actor's direction field (0x390). The bare frsqrte normalize
   is the engine reciprocalSqrt helper. lbl_803796B0 (0.0f) was a pooled
   literal: the original folded y*y of the planar vector to that constant, so
   the length sum reads the y component once as the addend. */
struct Handle{signed int generation:8;signed int index:24;};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Geometry{char unknown00[0x30];Vec3 position;};
struct Entity{char unknown00[0x124];Geometry*geometry;};
struct Entry{Entity*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;}
inline Entity*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;Entry*e=&m->entries[index];int generation=e->getGeneration();if(generation==h.generation)return e->object;return 0;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
extern "C"{float fn_801F1200(void);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" const float lbl_803796B0; /* 0.0f */
extern "C" const float lbl_803796C4; /* 5.0f */
extern "C" const float lbl_803796C8; /* 6.2831855f */
struct Storage{char unknown00[8];};
struct Owner:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 char unknown0C[0x390-0xC];Vec3 direction;
};
extern "C" void fn_800CCCEC(Owner*self){
 float radius=lbl_803796C4*fn_801F1200();
 float angle=lbl_803796C8*fn_801F1200();
 Vec3 t;
 t.x=radius*fn_8028506C(angle);
 t.z=radius*fn_80284FA8(angle);
 t.z+=resolve(*self->getHandle(0))->geometry->position.z;
 t.x+=resolve(*self->getHandle(0))->geometry->position.x;
 const Vec3&p=resolve(*self->getHandle(0))->geometry->position;
 Vec3 d(t.x-p.x,lbl_803796B0,t.z-p.z);
 float inv=reciprocalSqrt(d.x*d.x+d.y+d.z*d.z);
 d.x*=inv;d.y*=inv;d.z*=inv;
 self->direction=d;
}
