extern "C" const char lbl_8037A910[8];
inline void* operator new(unsigned long, void* p) { return p; }
struct Handle_801F7F10 {
    Handle_801F7F10();
    signed char getGen() const { return bits.generation; }
    ~Handle_801F7F10();
    union {
        unsigned long value;
        unsigned long word;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};

struct EmitBarrier0;
namespace ns_p802008C8 {
// fn_802008C8: drops a hierarchy member onto the ground below a point three
// units ahead of its bound node (ray cast 50 units straight down from 5 up).
typedef unsigned long u32;
typedef unsigned long long u64;

// YXZ idx world
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator+(const Vec3& b) const { return Vec3(x + b.x, y + b.y, z + b.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct Basis {
    float v[9];
    Vec3 apply(const Vec3& p) const {
        Vec3 r;
        r.y = v[1] * p.x + v[4] * p.y + v[7] * p.z;
        r.x = v[0] * p.x + v[3] * p.y + v[6] * p.z;
        r.z = v[2] * p.x + v[5] * p.y + v[8] * p.z;
        return r;
    }
};
struct Matrix { float m[16]; };
struct Ray {
    Vec3 origin; float length; Vec3 direction; float unknown1C;
    Ray(const Vec3& o, const Vec3& d, float l) : origin(o), direction(d) { length = l; }
};
struct Result {
    Vec3 point; char unknown0C[0x28 - 12]; u64 flags; u32 object, other, extra; signed char hit; char unknown3D[3];
    Result() { hit = 0; object = 0; other = 0; extra = 0; flags = 0; }
};
struct ObjectStorage { char unknown00[8]; };
struct Object : ObjectStorage {
    virtual void slot8(); virtual void slotC(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual const Handle_801F7F10* getHandle(int);
    char unknown0C[0x24];
    Basis basis;
    char unknown54[0xD0];
    Matrix* matrix;
};
struct Entry { Object* object; u32 unknown04, unknown08; signed char generation; char pad[3]; signed char getGeneration() const { return generation; } Object* getObject() const { return object; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Slot { char unknown00[0x14]; Handle_801F7F10 node; char unknown18[0x34]; };
struct Globals { char unknown00[0x114]; Slot* slots; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(const Handle_801F7F10*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
signed char fn_80269230(Object*, const Ray&, Result*, u64, u64);
void fn_8023D100(Object*, const Vec3*);
}
struct HandleZero : Handle_801F7F10 { HandleZero() { value = 0; } };
struct HandleRef : HandleZero {
    HandleRef(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
inline Object* resolve(const Handle_801F7F10& h) {
    Manager* m = lbl_801E9D24.manager;
    int index = h.bits.index;
    int generation = m->entries[index].getGeneration();
    signed char tag = h.getGen();
    if (generation == tag) return m->entries[index].object;
    return 0;
}
struct List { int count, capacity; Handle_801F7F10* data; };
struct Holder {
    char unknown00[0xC];
    Handle_801F7F10 owner;
    char unknown10[0x80];
    List second, assigned, third;
    char unknownB4[0x30];
    int base;
};
inline Vec3 getForward(Object* o) { return o->basis.apply(Vec3(0.0f, 0.0f, 1.0f)); }
inline Vec3 getPosition(Object* o) { Vec3 r(0.0f, 0.0f, 0.0f); r.z = o->matrix->m[14]; r.y = o->matrix->m[13]; r.x = o->matrix->m[12]; return r; }
inline int castGround(Object* world, const Vec3& origin, Result* result) {
    Ray ray(origin + Vec3(0.0f, 5.0f, 0.0f), Vec3(0.0f, -1.0f, 0.0f), 50.0f);
    return fn_80269230(world, ray, result, 2ULL, 0x400000008ULL);
}
extern "C" void fn_802008C8(Holder* self, int index) {
    if (fn_801F7EB8(&self->assigned.data[index]) && fn_801F7EB8(&self->second.data[index])
        && fn_801F7EB8(&self->owner)) {
        Result result;
        const Handle_801F7F10& source = lbl_801E9D24.slots[self->base + index].node;
        HandleRef node(source);
        if (castGround(resolve(self->owner), getPosition(resolve(node)) + getForward(resolve(node)) * 3.0f, &result)) {
            HandleRef target(*resolve(self->assigned.data[index])->getHandle(0));
            fn_8023D100(resolve(target), &result.point);
        }
    }
}




}

struct EmitBarrier1;
namespace ns_hierarchy_commands {
// Recovered hierarchy command forwarding and member removal.
typedef unsigned long u32;
struct CommandHandleRef {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    CommandHandleRef& operator=(const Handle_801F7F10&);
};

struct CommandObjectStorage { char unused[8]; };
// The two used methods occupy original vtable offsets 0x30 and 0x13C.
struct CommandObject : CommandObjectStorage {
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
    virtual void reset();
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
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
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void command(u32, u32, CommandHandleRef*);
};

struct CommandEntry {
    CommandObject* object;
    u32 unused[2];
    signed char generation;
    char pad[3];
};
struct CommandManagerStorage {
    u32 unknown[2];
    CommandEntry* entries;
    char unusedC[0x24 - 0xC];
};
struct CommandManager : CommandManagerStorage { virtual void flush(); };
struct CommandGlobals { char unused[0x118]; CommandManager* manager; };
struct CommandList { int count, capacity; CommandHandleRef* data; };
struct CommandHolder {
    char unused[0xC];
    CommandHandleRef owner;
    char unused10[0x80];
    CommandList second, assigned, third;
};
extern "C" {
extern CommandGlobals lbl_801E9D24;
u32 fn_801F7EB8(CommandHandleRef*);
void fn_801F86C8(CommandManager*, const void*, short);
void fn_8025BF0C(CommandObject*, CommandHandleRef*);
void fn_801FD3EC(CommandHolder*, CommandHandleRef*);
}
static inline CommandObject* resolve(const CommandHandleRef& handle) {
    CommandEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
struct CommandZeroLayer : Handle_801F7F10 {
    CommandZeroLayer() { value = 0; }
};
struct CommandOwnedHandle : CommandZeroLayer {
    CommandOwnedHandle(const CommandHandleRef& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
template<int N> struct CommandEmptyHandle : CommandEmptyHandle<N - 1> {
    CommandEmptyHandle() { value = 0; }
};
template<> struct CommandEmptyHandle<0> : Handle_801F7F10 {};
// A native nontrivial value parameter uses the compiler's hidden pointer ABI.
extern "C" void fn_801FC514(CommandHolder*, CommandOwnedHandle);
inline CommandHandleRef& CommandHandleRef::operator=(const Handle_801F7F10& source) {
    fn_801F86C8(lbl_801E9D24.manager, this, -1);
    value = source.value;
    fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    return *this;
}

extern "C" u32 fn_80200CBC(CommandHolder* self, int index, signed char flush) {
    resolve(self->second.data[index])->reset();
    if (fn_801F7EB8(&self->third.data[index]))
        resolve(self->third.data[index])->reset();
    if (fn_801F7EB8(&self->third.data[index])) {
        self->assigned.data[index] = CommandEmptyHandle<5>();
        fn_8025BF0C(resolve(self->second.data[index]), &self->assigned.data[index]);
        fn_801FD3EC(self, &self->third.data[index]);
        fn_801FC514(self, CommandOwnedHandle(self->third.data[index]));
        if (flush)
            lbl_801E9D24.manager->flush();
    }
    return 1;
}
extern "C" void fn_80200C38(CommandHolder* self, u32 a, u32 b, int index) {
    resolve(self->assigned.data[index])->command(a, b, &self->owner);
}

}

struct EmitBarrier2;
namespace ns_hierarchy_menu_player_binding_80200EEC {
// Private layout views for menu-player binding; offsets and C identities are verified.
// Only fn_80200EEC is retained. Generated inline backup destructors are uncredited.
typedef unsigned long MenuPlayerWord;

struct MenuPlayerNode;struct MenuPlayerEntry{MenuPlayerNode*object;MenuPlayerWord unknown04[2];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct MenuPlayerManager{MenuPlayerWord unknown00[2];MenuPlayerEntry*entries;};
extern "C"struct MenuPlayerGlobal{char unknown00[0x118];MenuPlayerManager*manager;char unknown11C[8];void*engine;char unknown128[0x24];void*factory;}lbl_801E9D24;
extern "C"{void fn_801F86C8(MenuPlayerManager*,const Handle_801F7F10*,int);MenuPlayerWord fn_801F7EB8(const Handle_801F7F10*);MenuPlayerWord fn_801F948C(void*,const char*);}
struct MenuPlayerZero0:Handle_801F7F10{MenuPlayerZero0(){}MenuPlayerZero0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuPlayerFirstZero:Handle_801F7F10{MenuPlayerFirstZero(){word=0;}};struct MenuPlayerZero1:MenuPlayerFirstZero{MenuPlayerZero1(){}MenuPlayerZero1(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerZero1(const MenuPlayerZero1&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
template<int N>struct MenuPlayerZero:MenuPlayerZero<N-1>{MenuPlayerZero(){this->word=0;}};
template<>struct MenuPlayerZero<1>:Handle_801F7F10{MenuPlayerZero(){word=0;}};
struct MenuPlayerPlayerHandle:MenuPlayerZero<6>{MenuPlayerPlayerHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerPlayerHandle(const MenuPlayerPlayerHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerPlayerHandle&operator=(const MenuPlayerPlayerHandle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct MenuPlayerSetupHandle:MenuPlayerZero<4>{MenuPlayerSetupHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuPlayerDefaultHandle:MenuPlayerZero<2>{};
struct MenuPlayerKey{MenuPlayerWord word;MenuPlayerKey(const char*s){word=fn_801F948C(this,s);}};
struct MenuPlayerNodePrefix{MenuPlayerWord unknown00[2];};
struct MenuPlayerNode:MenuPlayerNodePrefix{
 virtual void slot008();
 virtual void slot00C();
 virtual void slot010();
 virtual void slot014();
 virtual void slot018();
 virtual void slot01C();
 virtual void slot020();
 virtual void slot024();
 virtual void slot028();
 virtual void slot02C();
 virtual void slot030();
 virtual void slot034();
 virtual void slot038();
 virtual void setOwner(const Handle_801F7F10&);
 virtual void setContext(const Handle_801F7F10&);
 virtual void slot044();
 virtual void slot048();
 virtual void slot04C();
 virtual void slot050();
 virtual void slot054();
 virtual void slot058();
 virtual void slot05C();
 virtual void slot060();
 virtual void slot064();
 virtual void slot068();
 virtual void slot06C();
 virtual void slot070();
 virtual void slot074();
 virtual void slot078();
 virtual void slot07C();
 virtual void slot080();
 virtual void setPlayer(const Handle_801F7F10&);
 virtual void slot088();
 virtual void slot08C();
 virtual void slot090();
 virtual void setIndex(int);
 virtual void setMode(int);
 virtual void slot09C();
 virtual void slot0A0();
 virtual void enableIndex(int);
 virtual void slot0A8();
 virtual void slot0AC();
 virtual void slot0B0();
 virtual void slot0B4();
 virtual void slot0B8();
 virtual void slot0BC();
 virtual void slot0C0();
 virtual void slot0C4();
 virtual void slot0C8();
 virtual void slot0CC();
 virtual void slot0D0();
 virtual void slot0D4();
 virtual void slot0D8();
 virtual void slot0DC();
 virtual void slot0E0();
 virtual void slot0E4();
 virtual void slot0E8();
 virtual void slot0EC();
 virtual void slot0F0();
 virtual void slot0F4();
 virtual void slot0F8();
 virtual void slot0FC();
 virtual void slot100();
 virtual void slot104();
 virtual void slot108();
 virtual void slot10C();
 virtual void slot110();
 virtual void slot114();
 virtual void slot118();
 virtual void slot11C();
 virtual void slot120();
 virtual void slot124();
 virtual void slot128();
 virtual void slot12C();
 virtual void slot130();
 virtual void slot134();
 virtual void slot138();
 virtual void slot13C();
 virtual void slot140();
 virtual void setSlot(const Handle_801F7F10*);
 char unknown0C[0x10];Handle_801F7F10 context1C;char unknown20[0x10];Handle_801F7F10 parent30;char unknown34[0x30];char position64[12];Handle_801F7F10 handle70;
};
struct MenuPlayerOwner{MenuPlayerWord unknown00;Handle_801F7F10 context04;MenuPlayerWord unknown08;Handle_801F7F10 owner0C;char unknown10[0x88];Handle_801F7F10*slots98;char unknown9C[8];Handle_801F7F10*actorsA4;char unknownA8[8];Handle_801F7F10*playersB0;};
extern "C"{MenuPlayerZero0 fn_80263308(void*,const MenuPlayerKey&);void fn_8023E994(MenuPlayerNode*,MenuPlayerDefaultHandle&,int);void fn_802072D4(MenuPlayerNode*,const MenuPlayerKey&,int);void fn_802408BC(MenuPlayerNode*,MenuPlayerZero1,int);void fn_80269FE0(MenuPlayerNode*);void fn_8023DE28(MenuPlayerNode*);MenuPlayerZero0 fn_80260868(void*,const MenuPlayerKey&,int);MenuPlayerZero0 fn_80260BA4(void*,const char*);void fn_802002A4(MenuPlayerOwner*,int,const void*,const MenuPlayerSetupHandle&);void fn_8025BF0C(MenuPlayerNode*,const Handle_801F7F10*);int sprintf(char*,const char*,...);extern const char lbl_802AD8F8[],lbl_802AD904[];}
inline MenuPlayerNode*resolve(const Handle_801F7F10&h){int i=h.bits.index;MenuPlayerManager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();if(tag==h.bits.generation)return m->entries[i].object;return 0;}
inline void assign(Handle_801F7F10&target,const Handle_801F7F10&source){fn_801F86C8(lbl_801E9D24.manager,&target,-1);target.word=source.word;fn_801F86C8(lbl_801E9D24.manager,&source,1);}
inline void configurePlayer(MenuPlayerNode*node,MenuPlayerOwner*self,int number,const Handle_801F7F10&selected){node->setOwner(selected);const Handle_801F7F10&originalSetup=node->handle70;fn_802002A4(self,number-1,node->position64,MenuPlayerSetupHandle(originalSetup));}
extern "C"int fn_80200EEC(MenuPlayerOwner*self,int number,const MenuPlayerKey&name,int mode){
 if(fn_801F7EB8(self->actorsA4+(number-1)))return 0;
 MenuPlayerZero1 resource(fn_80263308(lbl_801E9D24.factory,name));if(!fn_801F7EB8(&resource))return 0;
 MenuPlayerDefaultHandle selected;fn_8023E994(resolve(resource),selected,0);
 MenuPlayerZero1 context(resolve(selected)->context1C);
 char label[128];sprintf(label,lbl_802AD8F8,number);
 MenuPlayerNode*named=resolve(selected);fn_802072D4(named,MenuPlayerKey(label),0);
 fn_802408BC(resolve(resolve(self->owner0C)->parent30),MenuPlayerZero1(selected),0);
 fn_80269FE0(resolve(self->owner0C));fn_8023DE28(resolve(resolve(self->owner0C)->parent30));
 MenuPlayerPlayerHandle player((MenuPlayerPlayerHandle(fn_80260868(lbl_801E9D24.engine,name,0))));
 const Handle_801F7F10&originalContext=self->context04;MenuPlayerZero0 owner(originalContext);
 if(fn_801F7EB8(&player)){
  resolve(player)->setOwner(selected);resolve(player)->setIndex(number-1);resolve(player)->setMode(mode-1);resolve(player)->enableIndex(number-1);resolve(player)->setContext(owner);
 }else{
  player=MenuPlayerPlayerHandle(fn_80260BA4(lbl_801E9D24.engine,lbl_802AD904));
  configurePlayer(resolve(player),self,number,selected);
 }
 assign(self->playersB0[number-1],player);
 resolve(self->actorsA4[number-1])->setPlayer(selected);
 resolve(self->actorsA4[number-1])->setSlot(self->slots98+(number-1));
 fn_8025BF0C(resolve(self->slots98[number-1]),self->actorsA4+(number-1));
 return 1;
}

}

struct EmitBarrier3;
namespace ns_hierarchy_plot {
// Reconstructed hierarchy plot lookup and command dispatch from original instructions.
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}



struct PlotFoundHandle : Handle_801F7F10 {};
struct NameHash { u32 value; NameHash(const char*); };
extern "C" {
u32 fn_801F948C(void*, const char*);
void fn_801F86C8(Manager*, const void*, short);
PlotFoundHandle fn_8026A494(Object*, const NameHash&);
extern const char lbl_802AD910[];
int sprintf(char*, const char*, ...);
}
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct PlotZeroHandle : Handle_801F7F10 { PlotZeroHandle() { value = 0; } };
struct PlotOwnedHandle : PlotZeroHandle {
    PlotOwnedHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct PlotObject : Object {
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
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
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void command(const PlotOwnedHandle&, const PlotOwnedHandle&, Handle*);
};
struct HierarchyPlot {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x8C];
    HandleList assigned;
};
struct PlotSetupKey:Handle {PlotSetupKey(const Handle&h){value=h.value;}};
extern "C" int fn_80200EEC(HierarchyPlot*, int, const Handle&, int);
extern "C" signed char fn_802017D8(HierarchyPlot* self, int index, Handle source, int mode) {
    signed char initialized = fn_80200EEC(self, index, PlotSetupKey(source), mode);
    if (!initialized)
        return 0;
    char name[64];
    sprintf(name, "%s%d", "Plot", index);
    Object* owner = resolve(self->owner);
    PlotOwnedHandle plot(fn_8026A494(owner, NameHash(name)));
    owner = resolve(self->owner);
    PlotOwnedHandle base(fn_8026A494(owner, NameHash(lbl_802AD910)));
    ((PlotObject*)resolve(self->assigned.data[index - 1]))->command(plot, base, &self->owner);
    return 1;
}

}

struct EmitBarrier4;
namespace ns_hierarchy_entry_actions {
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}


struct HierarchyEntries {
    char unknown00[0x90];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
};
extern "C" void fn_80201A14(HierarchyEntries* self, int index) {
    resolve(self->primary.data[index])->slot10();
    if (fn_801F7EB8(&self->secondary.data[index]))
        resolve(self->secondary.data[index])->slot10();
}
extern "C" void fn_80201B14(HierarchyEntries* self, int index) {
    resolve(self->primary.data[index])->slot11();
    if (fn_801F7EB8(&self->secondary.data[index]))
        resolve(self->secondary.data[index])->slot11();
}

}

struct EmitBarrier5;
namespace ns_hierarchy_reset {
// Reconstructed hierarchy reset and list dispatch from the original instructions.
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}



struct HierarchyReset {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    char unknownB4[0x0C];
    Handle root;
    HandleList fourth;
    HandleList third;
    int secondaryCount;
};
extern "C" {
void fn_8026A63C(Object*);
void fn_801FBFD0(HierarchyReset*, int, int, float);
}
extern "C" void fn_80201C14(HierarchyReset* self) {
    fn_8026A63C(resolve(self->owner));
    resolve(self->root)->slot11();
    int i;
    for (i = 0; i < self->primary.count; ++i)
        if (fn_801F7EB8(&self->primary.data[i]))
            resolve(self->primary.data[i])->slot12();
    for (i = 0; i < self->secondaryCount; ++i)
        if (fn_801F7EB8(&self->secondary.data[i]))
            resolve(self->secondary.data[i])->slot12();
    for (i = 0; i < self->third.count; ++i)
        if (fn_801F7EB8(&self->third.data[i]))
            resolve(self->third.data[i])->slot12();
    for (i = 0; i < self->fourth.count; ++i)
        resolve(self->fourth.data[i])->slot12();
    fn_801FBFD0(self, 15, 82, -1612.0f);
}

}

struct EmitBarrier6;
namespace ns_hierarchy_relative_action {
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}


extern "C" void fn_80201F10(Object* self, int index) {
    resolve(self->second.data[index - self->state])->slot10();
}

}

struct EmitBarrier7;
namespace ns_hierarchy_entry_assignment {
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}



extern "C" void fn_801F86C8(Manager*, const void*, short);
struct ZeroHandle : Handle_801F7F10 { ZeroHandle() { value = 0; } };
struct OwnedHandle : ZeroHandle {
    OwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct GameEntry {
    char unused[0x14]; Handle target; char unused18[0x34];
    void setTarget(const Handle& source) {
        fn_801F86C8(lbl_801E9D24.manager, &target, -1);
        target.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct AssignmentHolder {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x18];
    HandleList assigned;
    char unknownC0[0x24];
    int offset;
};
inline GameEntry& gameEntry(int index) { return ((GameEntry*)lbl_801E9D24.game)[index]; }
extern "C" void fn_8003125C(Game*, int, OwnedHandle);
extern "C" void fn_80201F94(AssignmentHolder* self, int index) {
    int relative = index - self->offset;
    gameEntry(index).setTarget(self->assigned.data[relative]);
    fn_8003125C(lbl_801E9D24.game, index, OwnedHandle(self->owner));
    resolve(self->primary.data[relative])->slot11();
}

}

struct EmitBarrier8;
namespace ns_hierarchy_batch_assign {
// Reconstructed from the original GSQE78 hierarchy instructions.
// Private layouts for the recovered hierarchy batch actions.

// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}


struct HierarchyBatch {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    HandleList assigned;
    Handle related;
    char unknownC4[0x0C];
    HandleList third;
    int count, activeCount, offset;
};



extern "C" void fn_801F86C8(Manager*, const void*, short);
struct BatchZeroHandle : Handle_801F7F10 { BatchZeroHandle() { value = 0; } };
struct BatchOwnedHandle : BatchZeroHandle {
    BatchOwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct BatchGameEntry {
    char unused[0x14]; Handle target; char unused18[0x34];
    void setTarget(const Handle& source) {
        fn_801F86C8(lbl_801E9D24.manager, &target, -1);
        target.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
inline BatchGameEntry& gameEntry(int index) { return ((BatchGameEntry*)lbl_801E9D24.game)[index]; }
extern "C" void fn_8003125C(Game*, int, BatchOwnedHandle);
static inline void assignEntry(HierarchyBatch* self, int index) {
    int relative = index - self->offset;
    gameEntry(index).setTarget(self->assigned.data[relative]);
    fn_8003125C(lbl_801E9D24.game, index, BatchOwnedHandle(self->owner));
    resolve(self->primary.data[relative])->slot11();
}
extern "C" void fn_80213A18(Object*);
extern "C" void fn_802020AC(HierarchyBatch* self) {
    int index;
    for (index = 0; index < self->activeCount; ++index)
        assignEntry(self, self->offset + index);
    for (index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot11();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot11();
    }
    fn_80213A18(resolve(self->related));
}

}

struct EmitBarrier9;
namespace ns_hierarchy_list_actions {
// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}


struct HierarchyEntries {
    char unknown00[0x90];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    char unknownB4[0x0C];
    Handle related;
    char unknownC4[0x18];
    int count;
};
extern "C" void fn_802139D8(Object*);
extern "C" void fn_802022FC(HierarchyEntries* self) {
    for (int index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot10();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot10();
    }
    fn_802139D8(resolve(self->related));
}

}

struct EmitBarrier10;
namespace ns_hierarchy_batch_clear {
// Reconstructed from the original GSQE78 hierarchy instructions.
// Private layouts for the recovered hierarchy batch actions.

// Private recovered layouts shared by the bounded group query/update fragments.

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
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
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
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
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}


struct HierarchyBatch {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    HandleList assigned;
    Handle related;
    char unknownC4[0x0C];
    HandleList third;
    int count, activeCount, offset;
};


struct HierarchyBatchObject : Object {
    virtual void setPrimary(int);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void setSecondary(int);
};
struct HierarchyRelatedState { char unknown00[0x24]; int state; };
extern "C" void fn_802139D8(Object*);
static inline void resetLists(HierarchyBatch* self) {
    for (int index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot10();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot10();
    }
    fn_802139D8(resolve(self->related));
}

extern "C" void fn_80202464(HierarchyBatch* self) {
    int index;
    for (index = 0; index < self->count; ++index) {
        if (fn_801F7EB8(&self->secondary.data[index]))
            ((HierarchyBatchObject*)resolve(self->secondary.data[index]))->setSecondary(-1);
        if (fn_801F7EB8(&self->primary.data[index]))
            ((HierarchyBatchObject*)resolve(self->primary.data[index]))->setPrimary(-1);
    }
    for (index = 0; index < self->third.count; ++index)
        if (fn_801F7EB8(&self->third.data[index]))
            resolve(self->third.data[index])->slot10();
    self->offset = -1;
    ((HierarchyRelatedState*)resolve(self->related))->state = self->offset;
    resetLists(self);
}

}

struct EmitBarrier11;
namespace ns_hierarchy_distribution {
// Recovered from GSQE78; the observed hierarchy range-distribution method.
// Private layouts describe only the fields and virtual slots this method uses.
typedef unsigned long u32;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct HandleList { int count, capacity; Handle* data; };

struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
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
    virtual void slot29(int);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37(int);
    char unknown0C[0x24-0x0C];
    int offset;
};
struct ResourceEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Dispatcher;
struct Globals {
    char unknown[0x118]; Manager* manager;
    char unknown11C[8]; Dispatcher* dispatcher;
    char unknown128[0x14]; void* groups;
};
extern "C" Globals lbl_801E9D24;
extern "C" void fn_801F86C8(Manager*, const void*, short);
struct DistributionHandle : Handle_801F7F10 {
    DistributionHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct DispatcherStorage { char unknown[0x30]; };
struct Dispatcher : DispatcherStorage {
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
    virtual void slot12(DistributionHandle);
};
struct HierarchyDistribution {
    u32 unused; Handle owner;
    char unknown08[0x90-8];
    HandleList first;
    HandleList second;
    HandleList third;
    HandleList fourth;
    Handle related;
    char unknownC4[0xDC-0xC4];
    int count, width, offset;
    const Handle& getOwner() const { return owner; }
};
static inline Object* resolve(const Handle& h) {
    ResourceEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
extern "C" {
signed char fn_80206A20(HierarchyDistribution*);
int fn_801FF9C8(void*);
u32 fn_801F7EB8(Handle*);
void fn_8022CEA4(Object*, int);
void fn_802020AC(HierarchyDistribution*);
void fn_801FBFD0(HierarchyDistribution*, int, int, float);
void fn_8020279C(HierarchyDistribution* self, int offset, int width) {
    fn_80206A20(self);
    int available = self->second.count;
    if (available <= fn_801FF9C8(lbl_801E9D24.groups)) {
        self->width = width;
        self->offset = offset;
        for (int i = 0; i < self->count; ++i) {
            if (fn_801F7EB8(&self->third.data[i]))
                resolve(self->third.data[i])->slot37(self->offset + i % self->width);
            if (fn_801F7EB8(&self->first.data[i]))
                resolve(self->first.data[i])->slot29(self->offset + i % self->width);
        }
        fn_8022CEA4(resolve(self->related), self->width);
        resolve(self->related)->offset = self->offset;
        fn_802020AC(self);
        lbl_801E9D24.dispatcher->slot12(DistributionHandle(self->getOwner()));
        fn_801FBFD0(self, 15, 0x51, -1612.0f);
    }
}
}

}

struct EmitBarrier12;
namespace ns_hierarchy_camera_list_setup_80202A18 {
// Hierarchy camera/list setup (GSQE78 0x80202A18): sizes the per-view lists and
// creates a camera agent, viewport node and camera node for each view.
// Hierarchy handle array specializations reconstructed from GSQE78.
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}

template<int Depth> struct HierarchyResizeHandle : HierarchyResizeHandle<Depth - 1> {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<> struct HierarchyResizeHandle<1> : Handle_801F7F10 {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<class T> struct ResizeArray {
    int count, capacity;
    T* data;
    void storage(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * sizeof(T), size * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
};

struct Object;
struct Entry { Object* object; u32 unknown[2]; signed char generation; char padding[3]; };
struct Manager { u32 unknown[2]; Entry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; char unknown11C[8]; void* dispatcher; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
u32 fn_801F948C(void*,const char*);
u32 fn_801F7EB8(const void*);
void fn_8023D648(Object*);
}
struct NameHash { u32 value; NameHash(const char* s) { value = fn_801F948C(this,s); } };
struct FoundHandle : Handle_801F7F10 {};
template<int N> struct SetupOwnedHandle : HierarchyResizeHandle<N> {
    SetupOwnedHandle() {}
    SetupOwnedHandle(const Handle_801F7F10& h) {
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    SetupOwnedHandle& operator=(const SetupOwnedHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
        return *this;
    }
    void assign(const SetupOwnedHandle<1>& h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
template<class T> struct SetupArray : ResizeArray<T> {
    void resize(int n, char keepCapacity) {
        void*p;
        int i;
        if(n>count) {
            if(n>capacity || !keepCapacity) {storage(n);capacity=n;}
            for(i=count;i<n;++i){p=&data[i];new(p) T;}
            count=n;
        } else if(n<count) {
            for(i=count-1;i>=n;--i)data[i].~T();
            if(keepCapacity)count=n;
            else {storage(n);capacity=n;count=n;}
        }
    }
};
struct Vec3 { float x,y,z; void set(float a,float b,float c){x=a;y=b;z=c;} };
struct Object {
    char unknown00[0x1C];
    SetupOwnedHandle<1> child;
    char unknown20[0x10];
    Handle_801F7F10 parent;
    char unknown34[0xB8-0x34];
    Vec3 position;
    void setChild(const SetupOwnedHandle<1>& h) {child=h;fn_8023D648(this);}
};
inline Object* resolve(const Handle_801F7F10& h) {
    Entry* e=lbl_801E9D24.manager->entries+h.bits.index;
    if(e->generation==h.bits.generation)return e->object;
 return 0;
}
struct OwnerManager {u32 unused[2];Entry* entries;};
inline Object* resolveOwner(const Handle_801F7F10&h) {
 Entry* e=((OwnerManager*)lbl_801E9D24.manager)->entries+h.bits.index;
 if(e->generation==h.bits.generation)return e->object;
 return 0;
}
struct HierarchySetup {
    char unknown00[0x0C]; Handle_801F7F10 owner;
    char name[0x80];
    ResizeArray<Handle_801F7F10> first;
    ResizeArray<HierarchyResizeHandle<5> > second;
    ResizeArray<HierarchyResizeHandle<7> > third;
    SetupArray<HierarchyResizeHandle<2> > fourth;
    char unknownC0[0x1C];
    int count, width, offset;
};
struct HierarchyStringPool {
    char player[12]; char lod[12]; char start[12];
    char cameraAgent[12]; char cameraClass[16]; char viewportFormat[16];
};
extern "C" {
extern const HierarchyStringPool lbl_802AD8F8;
void fn_802032B8(ResizeArray<HierarchyResizeHandle<5> >*,int,char);
void fn_802030C4(ResizeArray<HierarchyResizeHandle<7> >*,int,char);
FoundHandle fn_80260868(void*,const NameHash&,const char*);
Handle_801F7F10 fn_801B550C(Manager*,const NameHash&,const NameHash&);
void fn_801FC998(HierarchySetup*,const SetupOwnedHandle<2>&);
void fn_801BA714(char*,const char*,...);
void fn_802408BC(Object*,SetupOwnedHandle<1>,int);
void fn_80269FE0(Object*);
inline void assign(HierarchyResizeHandle<2>& destination,const SetupOwnedHandle<1>& h) {
 fn_801F86C8(lbl_801E9D24.manager,&destination,-1);
 destination.value=h.value;
 fn_801F86C8(lbl_801E9D24.manager,&h,1);
}
void fn_80202A18(HierarchySetup* self,int count,signed char shared,const NameHash& cameraType) {
    const HierarchyStringPool& pool=lbl_802AD8F8;
    if(self->count)return;
    self->count=count;
    fn_802032B8(&self->second,self->count,0);
    fn_802030C4(&self->third,self->count,0);
    self->fourth.resize(self->count,0);
    self->width=shared?1:self->count;
    for(int i=0;i<self->count;++i) {
        SetupOwnedHandle<2> camera(fn_80260868(lbl_801E9D24.dispatcher,cameraType,pool.cameraAgent));
        if(!fn_801F7EB8(&camera))
            camera=SetupOwnedHandle<2>(fn_80260868(lbl_801E9D24.dispatcher,NameHash(pool.cameraClass),pool.cameraAgent));
        fn_801FC998(self,camera);
        char name[128];
        fn_801BA714(name,pool.viewportFormat,self->name,i);
        assign(self->fourth.data[i],SetupOwnedHandle<1>(fn_801B550C(lbl_801E9D24.manager,NameHash("Node"),NameHash(name))));
        resolve(self->fourth.data[i])->position.set(0.0f,0.0f,4.0f);
        resolve(self->fourth.data[i])->setChild(SetupOwnedHandle<1>(fn_801B550C(lbl_801E9D24.manager,NameHash(lbl_8037A910),NameHash(name))));
        fn_8023D648(resolve(self->fourth.data[i]));
        fn_802408BC(resolve(resolveOwner(self->owner)->parent),SetupOwnedHandle<1>(self->fourth.data[i]),0);
    }
    fn_80269FE0(resolve(self->owner));
}
}

}

extern "C" __declspec(section ".sdata2") const char lbl_8037A910[8] = "Camera";
