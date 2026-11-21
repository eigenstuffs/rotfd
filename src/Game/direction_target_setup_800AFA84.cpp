/* Direction and target setup (counter at 0x1F8, record at 0x228); same shape as
 * fn_8007F990 without its flag updates. The unused owner resolve is dead code, but it
 * makes the compiler materialize lbl_801E9D24 into r31 at entry like the original.
 * The engine fast normalize uses a raw frsqrte estimate (no frsp), which no compiler
 * built-in emits, so the math helper uses a minimal inline asm statement. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Service{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Service*service;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_80379170;void fn_8007D6A0(void*,int);float fn_80284FA8(float);}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){word=0;}Handle_80021B54(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80021B54&operator=(const Handle_80021B54&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}};
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}float lengthSquared()const{return x*x+y*y+z*z;}void normalize(){if(lbl_80379170!=lengthSquared()){float inverse=reciprocalSqrt(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}}};
struct Record{char opaque;};
struct Prefix{Word unknown00;Handle_801F7F10 handle04;};
struct Node:Prefix{
virtual void v08();
virtual void v0C();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1C();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2C();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3C();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4C();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5C();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6C();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7C();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8C();
virtual void v90();
virtual void v94();
virtual void v98();
virtual const Handle_801F7F10*getChild(int);
virtual void vA0();
virtual void vA4();
virtual void vA8();
virtual void vAC();
virtual void vB0();
virtual void vB4();
virtual void vB8();
virtual void vBC();
virtual void vC0();
virtual void vC4();
virtual void vC8();
virtual void vCC();
virtual void vD0();
virtual void vD4();
virtual void vD8();
virtual void vDC();
virtual void vE0();
virtual void vE4();
virtual void vE8();
virtual void vEC();
virtual void vF0();
virtual void vF4();
virtual void vF8();
virtual void vFC();
virtual void v100();
virtual void v104();
virtual void v108();
virtual void v10C();
virtual void v110();
virtual void v114();
virtual void v118();
virtual void v11C();
virtual void apply(Record*);
char unknown0C[0x18];Handle_801F7F10 owner24;char unknown28[0x48];Handle_801F7F10 actor70;char unknown74[0x3C];Handle_801F7F10*childB0;char unknownB4[0x1F8-0xB4];char counter1F8[0x30];Record record228;char unknown229[0x5B];Vec3 direction284;char unknown290[0x24];Handle_80021B54 target2B4;char unknown2B8[4];float scale2BC;float angle2C0;float length2C4;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline const Handle_801F7F10&getActorHandle(){return resolve(*resolve(*lbl_801E9D24.service->handle)->childB0)->actor70;}
inline Node*getActor(){const Handle_801F7F10&h=getActorHandle();if(fn_801F7EB8(&h))return resolve(h);return 0;}
extern "C"void fn_800AFA84(Node*self,const Vec3*v){
 Node*owner=resolve(self->owner24); /* unused; see header */
 Vec3 d;d.x=v->x;d.z=v->z;
 d.y=self->length2C4*fn_80284FA8(self->angle2C0);
 d.normalize();
 self->direction284=d*self->scale2BC;
 self->target2B4=Handle_80021B54(getActor()->handle04);
 self->apply(&self->record228);
 fn_8007D6A0(self->counter1F8,2);
}
