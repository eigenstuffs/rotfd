/* Group completion step: notify the owner target, bump the selected group's
 * completion count, dispatch event 0x23F0 and, at nine completions, mark the
 * group finished, select its reward level, flag the player actor record,
 * and post the resulting score.  Private layout views by observed offset;
 * the counter layout continues event_counter_update.cpp.  The compiler owns
 * the 8-entry switch table (original jumptable_802B4BEC) and the int->float
 * bias double (original lbl_803785B8). */
typedef unsigned long u32;

struct Handle_801F7F10 {
    union { u32 word; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
u32 fn_801F948C(void*, const char*);
u32 fn_801F7EB8(const Handle_801F7F10*);
}
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { word = 0; }
    ~Handle_80020478() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_80020834 : Handle_80020478 {
    Handle_80020834() { word = 0; }
    ~Handle_80020834() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct System { char unknown00[0x1C]; Handle_801F7F10* handle; };
struct Input { char unknown00[0x2D]; signed char enabled; };
struct Context {
    char unknown00[0x118]; Manager* manager;
    char unknown11C[8]; void* scene;
    char unknown128[0x14]; System* system;
    char unknown140[0x24]; Input* input;
};
extern "C" { extern Context lbl_801E9D24; }

inline void* resolve(const Handle_801F7F10& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag)
        return e->object;
    return 0;
}

struct CounterName {
    u32 value;
    CounterName(const char* text) { value = fn_801F948C(this, text); }
    CounterName(const CounterName& other) { value = other.value; }
};

struct ActorRecord { char unknown00; };
struct Actor { char unknown00[0x318]; ActorRecord record; };
struct Group {
    char unknown00[0x70]; Handle_801F7F10 actor;
    const Handle_801F7F10& getActor() { return actor; }
};
struct SystemGroup { char unknown00[0xB0]; Handle_801F7F10* next; };
struct ActorEntry { Actor* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct ActorManager { char unknown00[8]; ActorEntry* entries; };
struct GroupEntry { Group* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct GroupManager { char unknown00[8]; GroupEntry* entries; };
struct SystemGroupEntry { SystemGroup* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct SystemGroupManager { char unknown00[8]; SystemGroupEntry* entries; };

inline Actor* resolveActor(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    ActorManager* m = (ActorManager*)lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline Group* resolveGroup(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    GroupManager* m = (GroupManager*)lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline SystemGroup* resolveSystemGroup(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    SystemGroupManager* m = (SystemGroupManager*)lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline Actor* optionalActor(const Handle_801F7F10& h)
{
    if (fn_801F7EB8(&h))
        return resolveActor(h);
    return 0;
}

struct CounterGroup {
    int count, peakPatties, peakJellies, peakSandDollars;
    int completed;
    char unknown14[0x15];
    signed char finished;
    char unknown2A[2];
    void* items;
    char unknown30[0x64];
};
struct CounterOwner {
    char unknown00[0x60]; Handle_801F7F10 handle;
    char unknown64[0x8C]; int group, item;
    char unknownF8[0x40]; CounterGroup* groups;
};

extern "C" {
extern const char lbl_803785B0[4];
extern const float lbl_803785B4;
void fn_800A6234(void*, signed char, const CounterName&);
void fn_80058CB8(CounterOwner*, int, const Handle_80020834&);
void fn_8007D6A0(ActorRecord*, int);
void fn_800596BC(CounterOwner*, int, int*, int*);
int fn_800596E4(CounterOwner*, short, short);
void fn_802602B8(void*, int, CounterOwner*, float, float);
}

extern "C" void fn_80056144(CounterOwner* self)
{
    void* target = resolve(self->handle);
    fn_800A6234(target, 0, CounterName(CounterName(lbl_803785B0)));
    self->groups[self->group].completed++;
    fn_80058CB8(self, 0x23F0, Handle_80020834());
    if (self->groups[self->group].completed == 9) {
        int first = -1, second = -1;
        int level = -1;
        switch (self->group) {
        case 1: level = 2; break;
        case 2: level = 7; break;
        case 3: level = 25; break;
        case 4: level = 26; break;
        case 5: level = 27; break;
        case 6: level = 28; break;
        case 0: level = 24; break;
        case 7: level = 2; break;
        }
        self->groups[self->group].finished = 1;
        fn_8007D6A0(&optionalActor(resolveGroup(*resolveSystemGroup(*lbl_801E9D24.system->handle)->next)->getActor())->record, 0x39);
        lbl_801E9D24.input->enabled = 0;
        fn_800596BC(self, level, &first, &second);
        int score = fn_800596E4(self, first, second);
        fn_802602B8(lbl_801E9D24.scene, 0xE3, self, lbl_803785B4, score);
    }
}
