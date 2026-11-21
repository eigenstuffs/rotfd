/* fn_801FF24C: remove the group entry whose object's related owner resolves
 * to the requested world handle (neighbor of fn_801FF18C, group_lookup.cpp).
 * Finds the entry index, notifies the game, detaches the object, keeps a
 * retained copy of its owner while the entry is destroyed and the array
 * compacted with memcpy, then passes that owner to the world context.
 * Register note: the search writes the shared `object` through a reference
 * parameter and the later lookup uses the if/return resolve form; together
 * they give the original r25 for both object values (r26 for the detach
 * counter). Separate locals or the ternary form leave the search object in
 * r26. */
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; int getCount() const { return count; } Handle& at(int i) { return data[i]; } };
struct Object {
    char unknown00[0xC];
    Handle related;
    char unknown10[0xDC - 0x10];
    int maximum;
};
struct Group {
    char unknown00[0x14];
    HandleList entries;
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
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
    virtual void pause();
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
    virtual void prepare();
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
    virtual void remove(const Handle*);
    virtual void finish();
};
struct RemoveGlobals {
    char unknown[0x114]; Game* game; Manager* manager;
    void* worldContext; char unknown120[4]; Dispatcher* dispatcher;
};
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_801F86C8(Manager*, const void*, short);
void fn_80201C14(Object*);
void fn_80202464(Object*);
void fn_80200CBC(Object*, int, char);
void fn_8026B560(void*, const void*);
void* memcpy(void*, const void*, unsigned long);
}
inline RemoveGlobals& removalGlobals() { return (RemoveGlobals&)lbl_801E9D24; }
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline Object* resolveEntry(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    if (entry->generation == handle.bits.generation) return entry->object;
    return 0;
}
struct ZeroHandle : Handle_801F7F10 { ZeroHandle() { value = 0; } };
struct OwnedHandle : ZeroHandle {
    OwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
// A distinct manager view keeps the original second entry-array reload.
struct RequestedEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct RequestedManager { u32 unused[2]; RequestedEntry* entries; };
inline bool sameOwner(const Handle& owner, const Handle& requested) {
    Object* a = resolve(owner);
    RequestedEntry* entry = ((RequestedManager*)lbl_801E9D24.manager)->entries + requested.bits.index;
    Object* b = entry->generation == requested.bits.generation ? entry->object : 0;
    return a == b;
}
struct OwnerQuery {
    const Handle* requested;
    OwnerQuery(const Handle& r) : requested(&r) {}
    bool same(const Handle& owner) const { return sameOwner(owner, *requested); }
};
struct RemoveObject : Object {
    const Handle& getOwner() const { return related; }
    void detachAll() { for (int i = 0; i < maximum; ++i) fn_80200CBC(this, i, 0); }
};
inline int findOwner(Group* self, const Handle& requested, Object*& object) {
    OwnerQuery query(requested);
    for (int i = 0; i < self->entries.getCount(); ++i) {
        object = resolve(self->entries.at(i));
        if (object && fn_801F7EB8(&object->related) && query.same(object->related))
            return i;
    }
    return -1;
}
inline void eraseEntry(HandleList& list, int index) {
    ((ZeroHandle*)&list.data[index])->~ZeroHandle();
    Handle* target = list.data + index;
    int count = --list.count;
    memcpy(target, target + 1, (count - index) * sizeof(Handle));
}
extern "C" void fn_801FF24C(Group* self, const Handle& world) {
    Object* object;
    int index = findOwner(self, world, object);
    removalGlobals().game->prepare();
    removalGlobals().game->pause();
    object = resolveEntry(self->entries.data[index]);
    fn_80201C14(object);
    fn_80202464(object);
    removalGlobals().dispatcher->remove(&self->entries.data[index]);
    ((RemoveObject*)object)->detachAll();
    OwnedHandle owner(((RemoveObject*)object)->getOwner());
    eraseEntry(self->entries, index);
    fn_8026B560(removalGlobals().worldContext, &owner);
    removalGlobals().dispatcher->finish();
}
