/* Planar (XZ) unit direction from this owner's geometry position to the
   related actor's (service +0x13C -> handle -> child 0xB0 -> actor handle
   0x70, validated with fn_801F7EB8), with y cleared, written to *out.
   Same shape as owner_planar_direction_8009A6D4.cpp; the related-actor chain
   is the helper from actor_sphere_contact_gate_8007FC68.cpp (resolve keeps
   the manager pointer, reloading entries per resolve). The fast normalize
   uses a bare reciprocal-square-root estimate (frsqrte with no frsp), which
   no compiler built-in emits, so the math helper uses a minimal inline asm
   statement. */
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);
 char unknownC[0x70-0xC];Handle actor;char unknown74[0xB0-0x74];Handle*child;char unknownB4[0x124-0xB4];Geometry*geometry;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C" const float lbl_80378D10; /* 0.0f */
extern "C" Word fn_801F7EB8(const Handle*);
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*relatedActor(){const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(h))return resolve(*h);return 0;}
inline float rsqrt(register float x){register float r=lbl_80378D10;if(x!=lbl_80378D10){asm{frsqrte r,x}}return r;}
extern "C" void fn_8009A3CC(Node*self,Vec3*out){
 Node*other=relatedActor();
 float ox=resolve(other->query(0))->geometry->position.x;
 float oz=resolve(other->query(0))->geometry->position.z;
 float sx=resolve(self->query(0))->geometry->position.x;
 float sz=resolve(self->query(0))->geometry->position.z;
 float dx=ox-sx;float dz=oz-sz;
 float sq=dx*dx+dz*dz;
 if(lbl_80378D10!=sq){float inv=rsqrt(sq);dx*=inv;dz*=inv;}
 out->x=dx;out->y=lbl_80378D10;out->z=dz;
}
