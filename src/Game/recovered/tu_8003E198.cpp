/* Merged translation unit for .text 0x8003E198-0x8003F0E4 (fn_8003E198 .. fn_8003F040).
   .sdata2 0x803784E8-0x80378510: pooled literals and the two small named strings, in
   definition/first-use order. */
typedef unsigned long Word;
typedef unsigned long u32;
/* Reference-handle layers: address-named classes whose weak destructors are owned by
   earlier units; one global definition each. */
struct Handle_801F7F10{union{Word word;Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct GManager;
namespace unit_8003E258{struct Console;struct Scene;struct Groups;}
namespace unit_8003E444{struct Arguments;struct Manager;struct Scene;struct Service;struct Input;}
namespace part_8003E630{struct Manager;struct Node;struct Scene;struct Holder;struct Service;}
namespace unit_8003ED18{struct Manager;struct Scene;}
/* One shared view of the global context for the handle code and the handle-using functions. */
struct GContext{char unknown00[0x110];
 union{unit_8003E258::Console*console;unit_8003E444::Arguments*args;};
 Word unknown114;
 union{GManager*manager;unit_8003E444::Manager*m444;part_8003E630::Manager*m630;unit_8003ED18::Manager*mED18;};
 part_8003E630::Node*node;char unknown120[4];
 union{unit_8003E258::Scene*s258;unit_8003E444::Scene*s444;part_8003E630::Scene*s630;unit_8003ED18::Scene*sED18;};
 char unknown128[0x14];
 union{unit_8003E258::Groups*groups;unit_8003E444::Service*service444;part_8003E630::Holder*holder;};
 char unknown140[0xC];void*fonts14C;char unknown150[4];part_8003E630::Service*service630;char unknown158[0xC];unit_8003E444::Input*input164;};
extern "C"{extern GContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(GManager*,const Handle_801F7F10*,int);}
#define OPDEL static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}OPDEL};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){value=0;}Handle_80020B90(const Handle_80020B90&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}Handle_80020B90&operator=(const Handle_80020B90&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}OPDEL};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}OPDEL};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}OPDEL};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}OPDEL
 Handle_80020834&operator=(const Handle_80020478&h){Handle_80020834 copy(h);fn_801F86C8(lbl_801E9D24.manager,this,-1);word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);return*this;}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}OPDEL};
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}OPDEL};
struct LazyBindingZero_ED18:Handle_801F7F10{LazyBindingZero_ED18(){word=0;}~LazyBindingZero_ED18(){}};
struct LazyBindingLayer_ED18:LazyBindingZero_ED18{LazyBindingLayer_ED18(){word=0;}~LazyBindingLayer_ED18(){}};
struct Handle_8002F6B0:LazyBindingLayer_ED18{Handle_8002F6B0(){word=0;}~Handle_8002F6B0(){}OPDEL};
struct Handle_8002F634:Handle_8002F6B0{
 Handle_8002F634(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F634(){}OPDEL
 Handle_8002F634&operator=(const Handle_8002F634&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};

namespace part_8003E198 {
/* Scene numeric argument: when the converted float argument exceeds -1, query the indexed pair from the current scene target and apply it. */
struct Arguments{char opaque00[0x8A5];signed char present8A5;char opaque8A6[0x12];float number8B8;};struct Target{};struct Scene{char opaque00[0x15058];Target*first15058;Target*first(){return first15058;}};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[0x10];Scene*scene;}lbl_801E9D24;
extern "C"{void fn_800596BC(Target*,int,int*,int*);void fn_80057AA0(Target*,int,int);}
extern "C" int fn_8003E198(){int first=-1,second=-1;int value=-1;if(lbl_801E9D24.args->present8A5)value=(int)lbl_801E9D24.args->number8B8;if(value>-1.0f){fn_800596BC(lbl_801E9D24.scene->first(),value,&first,&second);fn_80057AA0(lbl_801E9D24.scene->first(),first,second);}return 1;}
}

extern "C" extern const char lbl_803784F8[6]="WORLD";

namespace unit_8003E258 {
struct Groups{char unknown00[0x1C];Handle_801F7F10*items;};struct Console{char unknown00[0x860];int argc;int unknown864;const char*arg1;};struct Scene{char unknown00[0x15058];void*owner;};
typedef GManager Manager;
extern "C"{Word fn_801F948C(void*,const char*);void fn_801FA014(Console*,const char*,...);Word fn_801F7EB8(const Handle_801F7F10*);int fn_801FE99C(Groups*,const Handle_801F7F10*);void fn_80058F40(void*);extern const char lbl_8029A7A8[];}
struct NameHash{Word word;NameHash(const char*s){word=fn_801F948C(this,s);}};
struct NameType{Word word;NameType(const NameHash&n):word(n.word){}};
extern "C"{Handle_801F7F10 fn_801B5054(Manager*,const NameHash&,const NameType&);Handle_80020478 fn_80260BA4(Scene*,const char*);void fn_800BCCBC(Scene*,const Handle_8003E120*,const Handle_801F7F10*);}
extern "C" int fn_8003E258(){
 const char*pool=lbl_8029A7A8;
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,pool+0xE0);return 0;}
 Handle_80020C04 group(fn_801B5054(lbl_801E9D24.manager,NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_803784F8))));
 if(!fn_801F7EB8(&group)){fn_801FA014(lbl_801E9D24.console,pool+0xF4,lbl_801E9D24.console->arg1);return 0;}
 int index=fn_801FE99C(lbl_801E9D24.groups,&group);
 if(index<0){fn_801FA014(lbl_801E9D24.console,pool+0x110,lbl_801E9D24.console->arg1);return 0;}
 Handle_8003E120 target(fn_80260BA4(lbl_801E9D24.s258,pool+0x124));
 fn_800BCCBC(lbl_801E9D24.s258,&target,&lbl_801E9D24.groups->items[index]);
 fn_80058F40(lbl_801E9D24.s258->owner);return 1;
}
}

namespace unit_8003E444 {
/* Original scene numeric argument selection; see docs/notes/game-engine-scene-argument-setup.md. */
extern "C"{u32 fn_801F948C(void*,const char*);}
struct Key{u32 word;Key(const char*s){word=fn_801F948C(this,s);}};
struct Arguments{char opaque00[0x860];int count860;char opaque864[4];const char*argument868;char opaque86C[0x39];signed char present8A5;char opaque8A6[0x12];float number8B8;};struct Target{};struct Scene{char opaque00[0x15058];Target*first15058;Target*second1505C;Target*first(){return first15058;}void*third15060;void*fourth15064;};struct Service{char opaque00[0x14];int count14;int capacity18;Handle_801F7F10*handles1C;};struct Input{char opaque00[0x4C];void*object4C;};struct Entry{Target*object;u32 opaque04,opaque08;signed char generation0C;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
inline Target*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.m444->entries[h.bits.index];return e->generation0C==h.bits.tag?e->object:0;}
extern "C"{void fn_801FA014(Arguments*,const char*,...);extern const char lbl_8029A888[];void fn_801FEDA0(Service*,int);void fn_801FEE10(Service*,int);void fn_800596BC(Target*,int,int*,int*);void fn_80057AA0(Target*,int,int);}
extern "C" int fn_8003E444(){if(lbl_801E9D24.args->count860!=2){fn_801FA014(lbl_801E9D24.args,lbl_8029A888);return 0;}int first=-1,second=-1;int value=-1;if(lbl_801E9D24.args->present8A5)value=(int)lbl_801E9D24.args->number8B8;if(lbl_801E9D24.service444->count14>0){Handle_8002B67C h(lbl_801E9D24.service444->handles1C[0]);fn_801FEDA0(lbl_801E9D24.service444,0);fn_801FEE10(lbl_801E9D24.service444,0);}Target*t=lbl_801E9D24.s444->first();fn_800596BC(t,value,&first,&second);fn_80057AA0(t,first,second);return 1;}
}

namespace early_misc_event_control {
struct MiscVector{float x,y,z;MiscVector(){}MiscVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}MiscVector(const MiscVector&v):x(v.x),y(v.y),z(v.z){}};
struct MiscTransform{char unknown00[0x30];MiscVector position;};
struct MiscObject{char unknown00[0x124];MiscTransform*transform;};
struct MiscActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];MiscVector velocity;char unknown150[0x1C8];char record[8];int key;char unknown324[0xE3];signed char state407;char unknown408[4];signed char state40C; signed char hasFlag(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct MiscMonitor{char unknown00[0x130];void*first,*second;};
struct MiscControlOwner{char unknown00[8];MiscActor*actor;void*controller;};
struct MiscFlagsArray{char unknown00[0x18];unsigned long long flags;char unknown20[0xC];void**items;};
struct MiscPrefix8{char unknown00[8];};
struct MiscTarget:MiscPrefix8{
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
virtual void slot21(int);
virtual void slot22(int);
char unknown0C[0x2C];unsigned long long flags;
};
struct MiscPrefix4{char unknown00[4];};
struct MiscService:MiscPrefix4{virtual void slot0();virtual void slot1();virtual void slot2();virtual MiscTarget*getTarget();};
struct MiscDispatch{char unknown00[0x860];int mode;char unknown864[4];void*value;};
struct MiscScene{char unknown00[0x15058];void*state;};
struct MiscContext{char unknown00[0x110];MiscDispatch*dispatch;char unknown114[0x10];MiscScene*scene;};
struct MiscTimerOwner{char unknown00[0x1A4];float time;signed char enabled;};
struct MiscAngleOwner{char unknown00[0xD0];int mode;};
struct MiscRelated{char unknown00[0x118];void*value;};
struct MiscController{char unknown00[0x94];MiscRelated*related;};
struct MiscDelayedOwner{char unknown00[0xC];MiscController*controller;float time;signed char complete;};
extern "C"{extern MiscContext lbl_801E9D24;extern MiscMonitor*lbl_803776B8;extern const float lbl_80379350,lbl_8037899C,lbl_803789EC,lbl_80378AA8,lbl_80378AB0,lbl_80379090,lbl_80379094;extern const char lbl_8029A8DC[];void fn_8023D100(MiscObject*,const MiscVector*);void fn_8023DE28(MiscObject*);void fn_80257828(void*,int,int,int);void fn_8006803C(MiscMonitor*,int);void fn_801FA014(MiscDispatch*,const char*,...);void fn_80058AB8(void*,void*);int fn_80092844(MiscActor*);void fn_8007D6A0(void*,int);void fn_80092DAC(MiscActor*,double);void fn_800B4628(MiscTimerOwner*,float);void fn_800B5134(MiscTimerOwner*,int);void fn_800784A8(MiscAngleOwner*,MiscVector*);float fn_80285124(float,float);void fn_8002B780(MiscTarget*);void fn_80072F98(void*);void fn_802603A0(MiscScene*,int,MiscRelated*,float);}

extern "C"int fn_8003E56C(){if(lbl_801E9D24.dispatch->mode!=2){fn_801FA014(lbl_801E9D24.dispatch,lbl_8029A8DC);return 0;}fn_80058AB8(lbl_801E9D24.scene->state,lbl_801E9D24.dispatch->value);return 1;}
}

namespace unit_8003E5D0 {
/* Original scene record stream controls; see docs/notes/game-engine-scene-record-stream.md. */
struct Target{};struct Scene{char opaque00[0x15058];Target*first15058;};extern "C" struct Global{char opaque00[0x124];Scene*scene;}lbl_801E9D24;extern "C"{void fn_80056144(Target*);void fn_80056648(Target*,int);}
extern "C" int fn_8003E5D0(){Target*t=lbl_801E9D24.scene->first15058;for(int i=0;i<9;i++){fn_80056144(t);fn_80056648(t,i);}return 1;}
}

extern "C" extern const char lbl_80378500[6]="Plot1";

namespace part_8003E630 {
/* Scene start placement: resolves StartPos%d / LookPos%d children of the current node,
   builds a yaw quaternion from start to look position and places the player there. */
extern "C" int sprintf(char*,const char*,...);
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}};
inline Vec3 operator*(const Vec3&v,float s){return Vec3(v.x*s,v.y*s,v.z*s);}
struct Quat{float w,x,y,z;Quat(float a,const Vec3&v):w(a),x(v.x),y(v.y),z(v.z){}};

struct Transform{char unknown00[0x30];Vec3 position;};
struct ObjectPrefix{char unknown00[8];};
struct Object:ObjectPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual void vB8();virtual void vBC();virtual void place(Vec3*,Quat*,int);char unknown0C[0x64];Handle_801F7F10 handle70;char unknown74[0x3C];const Handle_801F7F10*handleB0;char unknownB4[0x70];Transform*transform;char unknown128[0x330];float value458;};
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Node{char unknown00[8];const Handle_801F7F10*handle;};
struct Mode{char unknown00[0xF0];int mode,submode;char unknownF8[8];int character;char unknown104[0x1CC];Vec3 position;Quat rotation;char flag2EC;char unknown2ED[3];unsigned int startIndex;};
struct Scene{char unknown00[0x15058];Mode*mode;};
struct Holder{char unknown00[0x1C];const Handle_801F7F10*handle;};
struct ServicePrefix{char unknown00[0x1C];};
struct Service:ServicePrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void set(int,signed char);};

extern "C" {extern const char lbl_8029A7A8[];extern const char lbl_8029ADAC[][15];extern Vec3 lbl_802F4148;
void*fn_801F7EB8(const Handle_801F7F10*);unsigned long fn_801F948C(void*,const char*);
float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);void fn_8005FD28();void*fn_8005E9A0();void fn_802073E8(void*,int,void*,float);}
struct Name{unsigned long value;Name(const char*s){value=fn_801F948C(this,s);}};
struct ModeKey{unsigned long value;ModeKey(const Name&n):value(n.value){}};
extern "C" signed char fn_802017D8(Object*,int,ModeKey,int);
extern "C" Handle_80020B90 fn_8026A494(Object*,const Name&);
struct Entry2{Object*object;char unknown04[8];signed char tag;char unknown0D[3];};struct Manager2{int count,capacity;Entry2*entries;};
inline Object*resolve2(const Handle_801F7F10&h){Entry2*e=&((Manager2*)lbl_801E9D24.m630)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Object*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.m630->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
/* Temp numbering: MWCC expands inlines level by level (CInline_Expand), and frontend temps
   get virtual registers in reverse creation order. player must be coloured before the
   resolve(owner) results (first users of r27), so its value has to live in a level-0
   inline return temp (getObj, body written out) while the owner resolves go through a
   second inline level (ownerObject -> resolve), whose temps are created in the next pass. */
inline Object*getObj(const Handle_801F7F10*h){if(fn_801F7EB8(h)){Entry*e=&lbl_801E9D24.m630->entries[h->bits.index];if(e->tag==h->bits.tag)return e->object;return 0;}return 0;}
inline Object*ownerObject(const Handle_801F7F10&h){return resolve(h);}
extern "C" int fn_8003E630(){
 const char*strings=lbl_8029A7A8;
 Mode*mode=lbl_801E9D24.s630->mode;
 const Handle_801F7F10*h=lbl_801E9D24.node->handle;
 Handle_80020C04 owner(*h);
 Handle_80020B90 start;
 Handle_80020B90 look;
 unsigned int index=mode->startIndex;
 if(mode->character==3)index=0;
 if(index){
  char startName[8];
  sprintf(startName,strings+0x148,index);
  {Object*object=ownerObject(owner);start=fn_8026A494(object,Name(startName));}
  char lookName[8];
  sprintf(lookName,strings+0x154,index);
  {Object*object=ownerObject(owner);look=fn_8026A494(object,Name(lookName));}
 }
 if(!fn_801F7EB8(&start)){Object*object=ownerObject(owner);start=fn_8026A494(object,Name(lbl_80378500));}
 if(!fn_801F7EB8(&look)){Object*object=ownerObject(owner);look=fn_8026A494(object,Name(strings+0x160));}
 Transform*startTransform=resolve(start)->transform;
 Vec3 position(startTransform->position.x,startTransform->position.y,startTransform->position.z);
 Transform*lookTransform=resolve2(look)->transform;
 float half;float c;
 /* look.x/look.z must be materialised (x then z) before the position reloads; the volatile
    reads keep copy propagation from folding them back into the subtraction (plain lfs). */
 float lx=*(volatile float*)&lookTransform->position.x;
 float lz=*(volatile float*)&lookTransform->position.z;
 float angle=fn_80285124(lx-position.x,lz-position.z);
 half=angle;half*=0.5f;
 c=fn_8028506C(half);
 Quat rotation(c,lbl_802F4148*fn_80284FA8(half));
 mode->position=position;
 mode->rotation=rotation;
 ModeKey key(Name(lbl_8029ADAC[mode->character]));
 Object*holder=resolve(*lbl_801E9D24.holder->handle);
 fn_802017D8(holder,1,key,0);
 Handle_801F7F10*playerHandle=&resolve2(*resolve(*lbl_801E9D24.holder->handle)->handleB0)->handle70;
 Object*player=getObj(playerHandle);
 player->place(&position,&rotation,0);
 fn_8005FD28();
 lbl_801E9D24.service630->set(0,mode->flag2EC);
 if(mode->mode==4&&mode->submode==1)fn_802073E8(fn_8005E9A0(),0x91,fn_8005E9A0(),angle);
 player->value458=1.0f;
 return 1;
}
}

namespace unit_8003ED18 {
/* Lazy named-handle binding; verified temporary and node assignment lifetimes.
 * See docs/notes/game-early-lazy-handle-binding.md. */
struct Node;
struct Entry{Node*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Owner;
struct Scene{char opaque[0x15058];Owner*owner;};
extern "C" {Handle_801F7F10 fn_801B52EC(Manager*,const char*);Word fn_801F7EB8(const Handle_801F7F10*);void fn_800A7798(Node*);extern const char lbl_8029A914[],lbl_8029A920[];}
struct Prefix{char opaque[8];};
struct Node:Prefix{
 virtual void unknown08();virtual void unknown0C();virtual void unknown10();virtual void unknown14();virtual void unknown18();virtual void unknown1C();virtual void unknown20();virtual void unknown24();virtual void unknown28();virtual void unknown2C();virtual void unknown30();virtual void unknown34();virtual void unknown38();virtual void unknown3C();virtual void unknown40();virtual void setName(const char*);
 char opaqueC[0x24];Handle_80020834 handle30;
 void setHandle(const Handle_80020478&h){Handle_80020834 copy(h);fn_801F86C8(lbl_801E9D24.manager,&handle30,-1);handle30.word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);}
};
struct Owner{char opaque[4];Handle_801F7F10 self;char opaque8[0x58];Handle_8002F634 target;};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.mED18->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" int fn_8003ED18(void*){
 Owner*owner=lbl_801E9D24.sED18->owner;
 if(!fn_801F7EB8(&owner->target)){
  owner->target=Handle_8002F634(fn_801B52EC(lbl_801E9D24.mED18,lbl_8029A914));
  {const Handle_801F7F10&original=owner->self;resolve(owner->target)->setHandle(Handle_80020478(original));}
  resolve(owner->target)->setName(lbl_8029A920);
 }
 {const Handle_801F7F10&original=owner->self;resolve(owner->target)->setHandle(Handle_80020478(original));}
 fn_800A7798(resolve(owner->target));
 return 1;
}
}

namespace part_8003F040 {
/* Scene argument command: with exactly two arguments, forwards event 0x57 to the
 * current scene target with the optional numeric argument (default -1) as a float.
 * The int->float conversion bias is compiler-generated here; the original
 * references the shared bias at lbl_803784F0 (see DATA-MAP in the report). */
struct Arguments{char opaque00[0x860];int count860;char opaque864[4];const char*argument868;char opaque86C[0x39];signed char present8A5;char opaque8A6[0x12];float number8B8;};
struct Target{};struct Scene{char opaque00[0x15058];Target*target15058;};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[0x10];Scene*scene;}lbl_801E9D24;
extern "C"{void fn_801FA014(Arguments*,const char*,...);extern const char lbl_8029A888[];void fn_802073E8(void*,int,void*,float);}
extern "C" int fn_8003F040(){Target*t=lbl_801E9D24.scene->target15058;if(lbl_801E9D24.args->count860!=2){fn_801FA014(lbl_801E9D24.args,lbl_8029A888);return 0;}int value=-1;if(lbl_801E9D24.args->present8A5)value=(int)lbl_801E9D24.args->number8B8;fn_802073E8(t,0x57,t,(float)value);return 1;}
}
