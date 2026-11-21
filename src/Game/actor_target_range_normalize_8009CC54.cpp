/* fn_8009CC54: planar (XZ) distance from the actor's query(0) target
   geometry position to the actor's point (0x390); below range (0x3AC)
   starts control 0, otherwise the target-to-point direction (point - target)
   is normalized (bare frsqrte) and passed with delta to virtual slot 0x1A0.
   Same TU as fn_8009C400/fn_8009C834. The two zero-vector regions use
   different read forms of the shared 0.0f label (pooled-literal emulation);
   tx/tz/px/pz declaration order and the fieldwise x,y,z assignment of the
   normalized vector fix the FPR assignment. */
#pragma fp_contract off
typedef unsigned long Word;
extern "C" const float lbl_80378D98; /* 0.0f */
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 const Vec3&get()const{return *this;}
 float length()const{float sq=x*x+y*y+z*z;float r=y;if(sq!=r)r=fastSqrt(sq);return r;}};
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();virtual void slot128();virtual void slot12C();virtual void slot130();virtual void slot134();virtual void slot138();virtual void slot13C();virtual void slot140();virtual void slot144();virtual void slot148();virtual void slot14C();virtual void slot150();virtual void slot154();virtual void slot158();virtual void slot15C();virtual void slot160();virtual void slot164();virtual void slot168();virtual void slot16C();virtual void slot170();virtual void slot174();virtual void slot178();virtual void slot17C();virtual void slot180();virtual void slot184();virtual void slot188();virtual void slot18C();virtual void slot190();virtual void slot194();virtual void slot198();virtual void slot19C();
 virtual void move(float,const Vec3&);
 char unknownC[0xA4-0xC];Handle*child;char unknownA8[0x124-0xA8];Geometry*geometry;char unknown128[0x318-0x128];char control;char unknown319[0x390-0x319];Vec3 point;char unknown39C[0x3AC-0x39C];float range;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C" void fn_8007D6A0(void*,int);
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}

struct Owner{char unknown0[8];Node*actor;};
extern "C" void fn_8009CC54(Owner*self,float delta){
 const Vec3&tp=resolve(self->actor->query(0))->geometry->position;
 Node*actor=self->actor;
 float tx=tp.x;float tz=tp.z;float px=actor->point.x;float pz=actor->point.z;
 if(Vec3(tx-px,lbl_80378D98,tz-pz).get().length()<actor->range)fn_8007D6A0(&actor->control,0);
 else{
  Vec3 n;n.x=px-tx;n.y=*(const float*)&lbl_80378D98;n.z=pz-tz;
  float sq=n.x*n.x+n.y*n.y+n.z*n.z;
  if(*(const float*)&lbl_80378D98!=sq){float s=reciprocalSqrt(sq);n.x*=s;n.y*=s;n.z*=s;}
  self->actor->move(delta,n);
 }
}
