typedef unsigned long Word;
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Return_80085C14:Handle_801F7F10{Return_80085C14();~Return_80085C14(){}};
struct Vec3{float x,y,z;};struct Node{};
struct SceneNode{char unknown0[0x1F0];Handle_801F7F10 related;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];};struct Manager{int count,capacity;Entry*entries;};
struct SceneEntry{SceneNode*object;char unknown4[8];signed char tag;char unknownD[3];};struct SceneManager{int count,capacity;SceneEntry*entries;};
struct Mode{char unknown0[0x12C];Vec3 position;};struct Scene{char unknown0[0x15058];Mode*root;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
struct Name{Word value;Name(const char*);};
struct Actor{char unknown0[0x64];Handle_801F7F10 handle;};
struct Prefix{char unknown0[8];};
struct Parent:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle_801F7F10&query(int);char unknownC[0x320-0xC];int property;};
struct Self{char unknown0[8];Parent*parent;Actor*actor;char unknown10[0x30];Vec3 position;Node*first,*second,*third;};
struct Service{char unknown0[0x130];void*enabled;};
extern "C"{extern Service*lbl_803776B8;extern const char lbl_8029D6B4[],lbl_80378B18[4];Word fn_801F948C(Name*,const char*);Return_80085C14 fn_80058778(Mode*,const Name&,signed char);Return_80085C14 fn_8024BDA0(Node*,const Name&);void fn_8025795C(Actor*,int,int);void fn_80255D88(Actor*,int,int,int,int);void fn_8006803C(Service*,int);}
inline Name::Name(const char*s){value=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline SceneNode*resolveScene(const Handle_801F7F10&h){SceneEntry*e=&((SceneManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"void fn_80085C14(Self*self){self->position=lbl_801E9D24.scene->root->position;self->first=resolve(fn_80058778(lbl_801E9D24.scene->root,Name(lbl_8029D6B4),0));Node*target=resolve(resolveScene(self->actor->handle)->related);self->second=resolve(fn_8024BDA0(target,Name(lbl_80378B18)));self->third=resolve(self->parent->query(0));fn_8025795C(self->actor,0x20,0);fn_80255D88(self->actor,0x83,15,0,0);if(lbl_803776B8&&lbl_803776B8->enabled)fn_8006803C(lbl_803776B8,self->parent->property);}
