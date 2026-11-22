typedef unsigned long Word;
typedef unsigned long long Flags;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct PositionReturn_8002B0A8:Handle_801F7F10{~PositionReturn_8002B0A8(){}};
struct Prefix{char unknown00[8];};
struct VirtualNode:Prefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void start();virtual void s11();virtual void activate();virtual void s13();virtual void select(int);};
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3 operator+(const Vec3&b)const{return Vec3(x+b.x,y+b.y,z+b.z);}};
struct Model{char unknown00[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}};
struct Node:VirtualNode{char unknown0C[0x14];Handle_801F7F10 related;char unknown24[0x100];Model*model;};
struct Owner:VirtualNode{char unknown0C[0x2C];Flags flags;char unknown40[0x18];Handle_801F7F10 target;char unknown5C[0x1C];Node*resource;int duration;Vec3 offset;signed char hasFlag(Flags f)const{signed char b=0;if(flags&f)b=1;return b;}};
struct Primary{};struct Scene{char unknown00[0x15058];Primary*primary;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
struct Name{Word word;Name(const char*);};
extern "C"{extern const char lbl_80299F6C[];Word fn_801F948C(Name*,const char*);PositionReturn_8002B0A8 fn_8005863C(Primary*);PositionReturn_8002B0A8 fn_80058778(Primary*,const Name&,signed char);void fn_80254BB4(Node*,const Vec3&);void fn_802554F4(Node*);void fn_80255D88(Owner*,int,int,int,int);}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"void fn_8002B0A8(Owner*self){
 if(self->hasFlag(0x200000000ULL))self->resource=resolve(fn_8005863C(lbl_801E9D24.scene->primary));
 else if(self->flags&0x400000000ULL)self->resource=resolve(fn_80058778(lbl_801E9D24.scene->primary,Name(lbl_80299F6C),0));
 else if(self->flags&0x2000000000000ULL)self->resource=resolve(fn_8005863C(lbl_801E9D24.scene->primary));
 if(self->resource){fn_80254BB4(self->resource,resolve(self->target)->model->getPosition()+self->offset);self->resource->activate();fn_802554F4(self->resource);}
 if(self->duration>0)fn_80255D88(self,self->duration,15,0,0);
 resolve(resolve(self->target)->related)->select(-1);self->flags|=0x40000ULL;self->start();
}

typedef char ResourceActivationHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char ResourceActivationReturnSize[(sizeof(PositionReturn_8002B0A8)==4)?1:-1];
typedef char ResourceActivationVectorSize[(sizeof(Vec3)==12)?1:-1];
typedef char ResourceActivationEntrySize[(sizeof(Entry)==16)?1:-1];
