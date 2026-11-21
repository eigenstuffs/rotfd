typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Return_800E2320:Handle_801F7F10{~Return_800E2320(){}};
struct Vec{float x,y,z;Vec(){}Vec(float xx,float yy,float zz):x(xx),y(yy),z(zz){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}Vec operator-(const Vec&v)const{return Vec(x-v.x,y-v.y,z-v.z);}float dot(const Vec&v)const{return x*v.x+y*v.y+z*v.z;}};
struct Transform{char unknown00[0x30];Vec position;Vec getPosition()const{return Vec(position.x,position.y,position.z);}};
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const Handle_801F7F10*slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const Vec&,int);
char unknown0C[0x118];Transform*transform;char unknown128[0x1C];Vec velocity;
inline void setVelocity(Vec v){velocity=v;}
};
struct Target{char unknown00[0x118];Vec position;};
struct SystemGroup{char unknown00[0x98];Handle_801F7F10*related;char unknown9C[0x14];Handle_801F7F10*next;};
struct Group{char unknown00[0x70];Handle_801F7F10 actor;};
struct System{char unknown00[0x1C];Handle_801F7F10*handle;};
struct Index{int value;Index(int v):value(v){}operator int()const{return value;}};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}void*getObject()const{return object;}};struct Entries{Entry*p;Entry&operator[](const Index& i)const{return p[i];}};
struct Manager{int count,capacity;Entries entries;};
struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];System*system;};
extern "C"Context lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){Manager*manager=lbl_801E9D24.manager;Index index(h.bits.index);signed char tag=h.bits.tag;if(manager->entries[index].matchesTag(tag))return manager->entries[index].getObject();return 0;}
inline Actor*resolveActor(const Handle_801F7F10&h){return(Actor*)resolve(h);}
inline SystemGroup*resolveSystemGroup(const Handle_801F7F10&h){return(SystemGroup*)resolve(h);}
inline Group*resolveGroup(const Handle_801F7F10&h){return(Group*)resolve(h);}
extern "C"{Word fn_801F7EB8(const Handle_801F7F10*);Return_800E2320 fn_8004A6C8(void*);float fn_801F1200();void fn_80255D88(void*,int,unsigned int,void*,void*);extern const float lbl_80379780,lbl_80379784,lbl_80379788;}
inline Actor*validResolve(const Handle_801F7F10&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Owner{void*vtable;unsigned char enabled;char unknown05[3];Word first;void*second;Actor*actor;float scale,phase,rate;Vec vector;};
extern "C"void fn_800E2320(Owner*self){
self->phase=lbl_80379788;
Handle_801F7F10&handle=resolveGroup(*resolveSystemGroup(*lbl_801E9D24.system->handle)->next)->actor;
Transform*transform=resolveActor(*validResolve(handle)->slot37(0))->transform;
Vec position=transform->getPosition();
self->actor->slot45(position,0);
Target*object=(Target*)resolve(fn_8004A6C8(resolve(*resolveSystemGroup(*lbl_801E9D24.system->handle)->related)));
Vec target=object->position;
Handle_801F7F10&handle2=resolveGroup(*resolveSystemGroup(*lbl_801E9D24.system->handle)->next)->actor;
Transform*transform2=resolveActor(*validResolve(handle2)->slot37(0))->transform;
Vec delta=transform2->getPosition()-target;
float scale=reciprocalSqrt(delta.dot(delta));
delta.x*=scale;delta.y*=scale;delta.z*=scale;
delta.y=lbl_80379780+fn_801F1200();
float rate=self->rate;
delta.x*=rate;delta.y*=rate;delta.z*=rate;
self->vector=delta;
self->actor->setVelocity(self->vector);
fn_80255D88(self->second,0x7A,0xF,0,0);
self->scale=lbl_80379784;
}
