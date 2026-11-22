typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}};struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void action(int);Handle handleC,related10;char unknown14[0x20-0x14];Handle action20;char unknown24[0x124-0x24];Geometry*geometry;Vec3 getPosition()const{return Vec3(geometry->position.x,geometry->position.y,geometry->position.z);}};
struct Resource:Node{};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];};struct Manager{int count,capacity;Entry*entries;};
struct ResourceEntry{Resource*object;char unknown4[8];signed char tag;char unknownD[3];};struct ResourceManager{int count,capacity;ResourceEntry*entries;};
struct Choice{char unknown0[0x29];signed char flag29,flag2A;char unknown2B[0x94-0x2B];};
struct Mode{char unknown0[0xF0];int choice;char unknownF4[0x138-0xF4];Choice*choices;};
struct Scene{char unknown0[0x15058];Mode*root;};
extern "C"struct Global{char unknown0[0x110];void*logger;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
struct Self{char unknown0[0x58];Handle handle;};
extern "C"{extern const char lbl_80299E6C[];void fn_801FA014(void*,const char*,...);void fn_8025A0A4(Self*,const Handle&);signed char fn_80056668(Mode*,Self*,const Vec3&);Node*fn_801F7EB8(const Handle*);}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline Resource*resolveResource(const Handle&h){ResourceEntry*e=&((ResourceManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"void fn_8002A164(Self*self,const Handle&value){
 fn_801FA014(lbl_801E9D24.logger,lbl_80299E6C);fn_8025A0A4(self,value);
 Mode*mode=lbl_801E9D24.scene->root;fn_80056668(mode,self,resolveResource(self->handle)->getPosition());
 if(!mode->choices[mode->choice].flag29||mode->choices[mode->choice].flag2A){
  resolve(resolveResource(self->handle)->action20)->action(-1);
  if(fn_801F7EB8(&resolveResource(self->handle)->related10))resolve(resolve(resolveResource(self->handle)->related10)->action20)->action(-1);
 }
 if(mode->choices[mode->choice].flag29&&!mode->choices[mode->choice].flag2A){
  if(fn_801F7EB8(&resolveResource(self->handle)->related10))resolve(resolve(resolveResource(self->handle)->related10)->action20)->action(-1);
 }
}
