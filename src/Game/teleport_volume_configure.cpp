// TeleportVolume parameter loading, generation-checked handles and destination orientation.
// The three floating constants remain shared original data until later handlers are recovered.
typedef unsigned long u32;
struct Resource;
struct Entry{Resource*object;u32 unknown[2];signed char generation;char padding[3];};
struct Registry{int size,capacity;Entry*entries;};
struct Transform;
struct World {char unknown[0x15058];Transform*active;};
struct Globals{char unknown[0x118];Registry*registry;char unknown11C[8];World*world;};
extern "C" Globals lbl_801E9D24;
struct Handle {
 union{u32 value;struct{signed long generation:8;signed long index:24;}bits;};
 void assign(const Handle&);
 Resource*resolve()const{Entry*entry=&lbl_801E9D24.registry->entries[bits.index];return entry->generation==bits.generation?entry->object:0;}
};
struct Vec3{float x,y,z;Vec3&operator=(const Vec3&other){float oz=other.z,oy=other.y,ox=other.x;x=ox;y=oy;z=oz;return *this;}};
struct Transform{char unknown[0x12C];Vec3 position;};
struct ObjectTransform{char unknown[0x30];Vec3 position;};
struct Resource{char unknown[0x124];ObjectTransform*transform;};
struct Quat{float w,x,y,z;};
struct Agent{
 char unknown[0x58];Handle reference58;char unknown5C[4];signed char field60;char pad61[3];u32 field64;char unknown68[8];
 Handle reference70,reference74,reference78,reference7C;signed char field80;char pad81[3];
 Vec3 position84,position90;Quat rotation9C;signed char fieldAC,fieldAD;char padAE[2];u32 fieldB0,fieldB4;Transform*fieldB8;
};
extern "C" {
void fn_801F86C8(Registry*,const Handle*,int);
float fn_8025E268(Agent*,int);
Handle*fn_8025E1D4(Agent*,int);
float fn_80285124(float,float);
float fn_8028506C(float);
float fn_80284FA8(float);
extern const float lbl_80379628,lbl_8037962C,lbl_80379630;
}
inline void Handle::assign(const Handle&other){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.registry,&other,1);}
extern "C" void fn_800C7A24(Agent*self){
 self->fieldAC=(signed char)fn_8025E268(self,1);
 self->fieldB0=(u32)fn_8025E268(self,2);
 self->field60=(signed char)fn_8025E268(self,3);
 self->field64=(unsigned char)fn_8025E268(self,4);
 self->fieldAD=(signed char)fn_8025E268(self,5);
 self->fieldB4=(u32)fn_8025E268(self,6);
 self->field80=(signed char)fn_8025E268(self,7);
 self->reference7C.assign(*fn_8025E1D4(self,3));
 self->fieldB8=lbl_801E9D24.world->active;
 if(self->field80)self->fieldB8->position=self->reference58.resolve()->transform->position;
 if(!self->fieldAC){
  self->reference78.assign(*fn_8025E1D4(self,0));
  self->reference74.assign(*fn_8025E1D4(self,1));
  self->position84=self->reference78.resolve()->transform->position;
  self->position90=self->reference74.resolve()->transform->position;
  float angle=fn_80285124(self->position90.x-self->position84.x,self->position90.z-self->position84.z);
  angle*=lbl_80379628;
  float cosine=fn_8028506C(angle);
  float sine=fn_80284FA8(angle);
  self->rotation9C.w=cosine;
  self->rotation9C.x=lbl_8037962C*sine;
  self->rotation9C.y=lbl_80379630*sine;
  self->rotation9C.z=lbl_8037962C*sine;
 }
}
