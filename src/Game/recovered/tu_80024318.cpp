#pragma readonly_strings on
/* fn_80024318: activates up to `count` idle selection records. Each pick is a
   random idle record (fn_800248BC) whose actor anchor is far enough from both
   the player and the owner's tracked object (20 tries); the record's object is
   activated and moved to the anchor and a named scene effect is started there. */
typedef unsigned long Word;
typedef unsigned char u8;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Mode;
struct Scene { char unknown00[0x15058]; Mode* first; };
struct Context { char unknown00[0x110]; void* log; char unknown114[4]; Manager* manager; char unknown11C[8]; Scene* scene; };
extern "C" {
extern Context lbl_801E9D24;
extern const struct Strings { char tooMany[0x54]; char noSpot[0x2C]; char effect[0x14]; } lbl_80299BB8;
extern const float lbl_80378240, lbl_80378244, lbl_80378248, lbl_8037824C;
void fn_801F9D68(void*, const char*, ...);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378240;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Body { char unknown00[0x30]; Vec3 position; Vec3 getPosition() const { return Vec3(position.x, position.y, position.z); } };
struct NodePrefix { char unknown00[8]; };
struct Node : NodePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void activate();
    char unknown0C[0x2C];
    unsigned long long flags38;
    char unknown40[0x18];
    Handle_801F7F10 related58;
    char unknown5C[0x14];
    Handle_801F7F10 actor70;
    char unknown74[0x1C];
    int key90;
    char unknown94[0x90];
    Body* body;
    char unknown128[0x270];
    Vec3 anchor;
    Vec3 getAnchor() const { return Vec3(anchor.x, anchor.y, anchor.z); }
    const Vec3& anchorRef() const { return anchor; }
};

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

struct Tracked { int unknown00; virtual void t0(); virtual void t1(); virtual void t2(); virtual Node* get(); };
struct Record { char unknown00[0xC]; Node* value0C; signed char active10; };
struct Owner {
    char unknown00[4];
    signed char pending04;
    char unknown05[3];
    float timer08;
    char unknown0C;
    u8 total0D, used0E;
    char unknown0F;
    Record* records10[30];
    Tracked* tracked88;
};
struct Returned : Handle_801F7F10 { Returned(); ~Returned() {} };
struct Name { Word word; Name(const char*); };
extern "C" {
signed char fn_800248BC(Owner*);
Node* fn_8005E9A0();
void fn_80068FE4(int*, int);
void fn_8023D100(Node*, const Vec3*);
void fn_8023DE28(Node*);
Word fn_801F948C(Name*, const char*);
Returned fn_80058778(Mode*, const Name&, signed char);
void fn_80254BB4(Node*, const Vec3&);
void fn_802554F4(Node*);
}
inline Name::Name(const char* s) { word = fn_801F948C(this, s); }

inline float addh(float a, float b) { if (a == a) return a + b; return a; }
/* Register allocation depends on the order in which the front end creates the
   inline locals: the distance locals must exist before getPosition()'s argument
   temporaries, so getPosition() is called from inside both helpers. */
inline float distanceToBody(const Body* body, const Vec3& b)
{
    register float dz;
    register float dy;
    register float dx;
    register float sq;
    register float r;
    const Vec3& a = body->getPosition();
    dx = a.x - b.x;
    dy = a.y - b.y;
    dz = a.z - b.z;
    sq = dx * dx + dy * dy + dz * dz;
    r = lbl_80378240;
    if (sq != r) { asm { frsqrte f4, sq } asm { fres r, f4 } }
    return r;
}
inline float distanceFromBody(const Vec3& a, const Body* body)
{
    const Vec3& d = a - body->getPosition();
    return d.length();
}
extern "C" void fn_80024318(Owner* self, u8 count)
{
    int n = count;
    u8 available = self->total0D - self->used0E;
    if (n > available) {
        fn_801F9D68(lbl_801E9D24.log, "Karate: nNumToDrop > nTotalOpenSlotCount this used to crash here !!!!!!!!!!!!!!!!!");
        n = available;
    }
    for (int i = 0; i < n; i++) {
        signed char sel = -1;
        u8 tries = 0;
        while (sel == -1 && tries < 20) {
            tries++;
            sel = fn_800248BC(self);
            Vec3 pos = resolve<Node>(self->records10[sel]->value0C->actor70)->anchor;
            if (distanceToBody(resolve<Node>(fn_8005E9A0()->related58)->body, pos) <= lbl_80378244
                || distanceFromBody(pos, resolve<Node>(self->tracked88->get()->related58)->body) <= lbl_80378244) {
                sel = -1;
            }
        }
        if (sel == -1) {
            fn_801F9D68(lbl_801E9D24.log, "Karate: debug Couldn't find good drop point");
            self->timer08 = lbl_80378248;
            return;
        }
        self->records10[sel]->value0C->activate();
        fn_80068FE4(&self->records10[sel]->value0C->key90, 1);
        self->records10[sel]->active10 = 1;
        Vec3 p = resolve<Node>(self->records10[sel]->value0C->actor70)->anchor;
        fn_8023D100(resolve<Node>(self->records10[sel]->value0C->related58), &p);
        fn_8023DE28(resolve<Node>(self->records10[sel]->value0C->related58));
        Node* fx = resolve<Node>(fn_80058778(lbl_801E9D24.scene->first, Name("PFX_BREAKABLE_SPAWN"), 1));
        if (fx) {
            Vec3 q;
            float t;
            t = p.z + lbl_80378240; q.z = t;
            t = p.y + lbl_8037824C; q.y = t;
            t = p.x + lbl_80378240; q.x = t;
            fn_80254BB4(fx, q);
            fx->activate();
            fx->flags38 |= 0x20000ULL;
            fx->v34();
            fn_802554F4(fx);
        }
        self->used0E++;
    }
    self->timer08 = lbl_80378240;
    self->pending04 = 0;
}

/* ---- typed_handle_80024844 ---- */
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
template<int Depth> struct TypedHandleLayer:TypedHandleLayer<Depth-1> {
 ~TypedHandleLayer(){}
};
template<> struct TypedHandleLayer<1>:Handle_801F7F10 {
 ~TypedHandleLayer(){}
};
struct Handle_80024844:TypedHandleLayer<2> {
    ~Handle_80024844();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80024844::~Handle_80024844(){}
inline void*operator new(unsigned long,void*p){return p;}
namespace u_800248BC {
/* Original early selection and type controls; see docs/notes/game-engine-early-selection-controls.md. */
typedef unsigned char u8;struct Record{char opaque00[0xC];void*value0C;signed char active10;};struct Owner{char opaque00[0xD];u8 total0D,used0E;char opaque0F;Record*records10[1];};extern "C" int fn_801F1224(int,int);
extern "C" int fn_800248BC(Owner*self){u8 available=self->total0D-self->used0E;if(!available)return -1;u8 selected=fn_801F1224(1,available);u8 matches=0;for(u8 i=0;i<self->total0D;++i){if(!self->records10[i]->active10){++matches;if(matches==selected)return (signed char)i;}}return -1;}
}
namespace u_80024960 {
/* Original early selection and type controls; see docs/notes/game-engine-early-selection-controls.md. */
typedef unsigned char u8;struct PointerOwner;struct Record{char opaque00[0xC];PointerOwner*value0C;signed char active10;};struct Owner{char opaque00[0xD];u8 total0D,used0E;char opaque0F;Record*records10[1];};extern "C" int fn_801F1224(int,int);
extern "C" PointerOwner*fn_80024960(void*object){Owner*self=(Owner*)object;if(!self->used0E)return 0;u8 selected=fn_801F1224(1,self->used0E);u8 matches=0;for(u8 i=0;i<self->total0D;++i){if(self->records10[i]->active10){++matches;if(matches==selected)return self->records10[i]->value0C;}}return 0;}
}
namespace u_80024A04 {
extern "C" {
/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Countdown {char pad[4];unsigned char state;char pad5[3];float timer;char padc[2];unsigned char count;char padf;void *members[4];};

extern const float lbl_80378240,lbl_80378248;

void fn_80024A04(struct Countdown *object,const void *member) {((unsigned char *)object->members[*((signed char *)member+0x1ec)])[0x10]=0;--object->count;if(object->count<=3){if(lbl_80378240==object->timer)object->timer=lbl_80378248;object->state=4;}}
}
}
/* Last string of the unit; a named 12-byte definition at the end of the file covers the
   alignment byte at 0x80299C67 (a pooled literal would leave the section one byte short). */
extern "C" { __declspec(section ".rodata") extern const char lbl_80299C5C[12]; }
namespace u_80024A5C {
#ifndef GAME_EARLY_SELECTION_EVENT_CONTROL_VIEWS_H
#define GAME_EARLY_SELECTION_EVENT_CONTROL_VIEWS_H
struct SelectionHandle{signed int tag:8;signed int index:24;};
struct SelectionVector{float x,y,z;SelectionVector(){}SelectionVector(const SelectionVector&v):x(v.x),y(v.y),z(v.z){}SelectionVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}SelectionVector&operator=(const SelectionVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct SelectionTransform{char unknown00[0x30];SelectionVector position;};
struct SelectionPrefix{char unknown00[8];};
struct SelectionActor:SelectionPrefix{
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
virtual void slot35(int,int);
virtual void slot36();
virtual const SelectionHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const SelectionVector&,int);
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual const SelectionHandle* slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void setMotion(const SelectionVector&);
char unknown0C[0x24];unsigned long long flags;unsigned long long ownerFlags;char unknown40[0x30];SelectionHandle handle;char unknown74[0xC];SelectionHandle related;char unknown84[0xA0];SelectionTransform*transform;char unknown128[0x1C];SelectionVector velocity;char unknown150[0x48];SelectionVector position;char unknown1A4[0x48];unsigned char recordIndex;char unknown1ED[0x1AB];SelectionVector origin;char unknown3A4[0x6C];float stateTime;unsigned char active;unsigned char state;
inline void setPosition(SelectionVector v){position=v;}
inline void setVelocity(SelectionVector v){velocity=v;}
};
struct SelectionOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x30];SelectionHandle actor;char unknown74[0xC];SelectionHandle related;};
struct SelectionPointerOwner{char unknown00[0x10];SelectionActor*actor;};
struct SelectionResource{char unknown00[0x120];unsigned long property;};
struct SelectionSystemGroup{char unknown00[0xB0];SelectionHandle*next;};
struct SelectionGroup{char unknown00[0x70];SelectionHandle actor;};
struct SelectionSystem{char unknown00[0x1C];SelectionHandle*handle;};
struct SelectionText{char unknown00[0x48];void*text;float time;};
struct SelectionSceneState{char unknown00[0x60];SelectionHandle text;};
struct SelectionScene{char unknown00[0x15068];SelectionOwner*current;};
struct SelectionActorEntry{SelectionActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionActorManager{char unknown00[8];SelectionActorEntry*entries;};
struct SelectionResourceEntry{SelectionResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionResourceManager{char unknown00[8];SelectionResourceEntry*entries;};
struct SelectionSystemGroupEntry{SelectionSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionSystemGroupManager{char unknown00[8];SelectionSystemGroupEntry*entries;};
struct SelectionGroupEntry{SelectionGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionGroupManager{char unknown00[8];SelectionGroupEntry*entries;};
struct SelectionTextEntry{SelectionText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionTextManager{char unknown00[8];SelectionTextEntry*entries;};
struct SelectionContext{char unknown00[0x118];SelectionActorManager*manager;char unknown11C[8];SelectionScene*scene;char unknown128[0x14];SelectionSystem*system;};
extern "C"SelectionContext lbl_801E9D24;
inline SelectionActor*resolveActor(const SelectionHandle&h){int index=h.index;SelectionActorManager*m=(SelectionActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionResource*resolveResource(const SelectionHandle&h){int index=h.index;SelectionResourceManager*m=(SelectionResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionSystemGroup*resolveSystemGroup(const SelectionHandle&h){int index=h.index;SelectionSystemGroupManager*m=(SelectionSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionGroup*resolveGroup(const SelectionHandle&h){int index=h.index;SelectionGroupManager*m=(SelectionGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionText*resolveText(const SelectionHandle&h){int index=h.index;SelectionTextManager*m=(SelectionTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const SelectionHandle*);
inline SelectionActor*validResolve(const SelectionHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
extern "C" const float lbl_80378240;
struct SelectionResetRecord{SelectionVector position;SelectionActor*actor;signed char enabled;SelectionResetRecord():position(lbl_80378240,lbl_80378240,lbl_80378240),actor(0),enabled(0){}};
struct SelectionResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;SelectionResetRecord*records[256];};
struct SelectionTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern SelectionTableRecord lbl_802F4208[300];extern const SelectionVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(SelectionSceneState*,int);void fn_8025A0A4(SelectionOwner*);void fn_80259164(SelectionActor*);}
extern "C"{extern char lbl_801EF5C8[];extern const float lbl_80378420,lbl_80378450,lbl_80378454;void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void fn_8025795C(void*,int,int);void fn_80255D88(void*,int,int,int,int);void fn_800356DC(SelectionOwner*);void fn_80259008(SelectionOwner*);void fn_800E3094(SelectionActor*,SelectionOwner*);signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_8007D6A0(void*,int);}
#endif
extern "C"void fn_80024A5C(SelectionResetOwner*self,SelectionActor*actor){actor->ownerFlags|=0x800000000000ULL;actor->recordIndex=self->count;self->records[self->count]=new(fn_801EFA1C(lbl_801EF5C8,sizeof(SelectionResetRecord),"Anonymous New",lbl_80299C5C,0x162,4))SelectionResetRecord;self->records[self->count]->actor=actor;self->records[self->count]->position=resolveActor(actor->handle)->origin;self->records[self->count]->enabled=0;fn_80068FE4((char*)self->records[self->count]->actor+0x90,0);++self->count;}
}
extern "C" { __declspec(section ".rodata") const char lbl_80299C5C[12] = "Karate.cpp"; }
