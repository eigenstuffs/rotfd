// Remove the hierarchy whose related owner resolves to the requested world.
#include "group_runtime_internal.h"
struct RemoveGame : Game {
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
 };
struct RemoveDispatcherStorage { char unknown[0x30]; };
struct RemoveDispatcher : RemoveDispatcherStorage {
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
    char unknown[0x114]; RemoveGame* game; Manager* manager;
    void* worldContext; char unknown120[4]; RemoveDispatcher* dispatcher;
};
inline RemoveGlobals& removalGlobals() { return (RemoveGlobals&)lbl_801E9D24; }
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
extern "C" {
void fn_801F86C8(Manager*, const void*, short);
void fn_80201C14(Object*);
void fn_80202464(Object*);
void fn_80200CBC(Object*, int, char);
void fn_8026B560(void*, const void*);
void* memcpy(void*, const void*, unsigned long);
}
struct RemoveZeroHandle : Handle_801F7F10 { RemoveZeroHandle() { value = 0; } };
struct RemoveOwnedHandle : RemoveZeroHandle {
    RemoveOwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct RemoveEntryView { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct RemoveManagerView { u32 unused[2]; RemoveEntryView* entries; };
inline bool sameOwner(const Handle& owner, const Handle& requested) {
    Object* a = resolve(owner);
    RemoveEntryView* entry = ((RemoveManagerView*)lbl_801E9D24.manager)->entries + requested.bits.index;
    Object* b = entry->generation == requested.bits.generation ? entry->object : 0;
    return a == b;
}
struct RemoveObject : Object { const Handle& getOwner() const { return related; } int getCount() const { return maximum; }
    void detachAll() { for (int i = 0; i < maximum; ++i) fn_80200CBC(this, i, 0); } };
inline int findOwner(Group* self, const Handle& requested) {
    for (int i = 0; i < self->entries.count; ++i) {
        Object* const object = resolve(self->entries.data[i]);
        if (object && fn_801F7EB8(&object->related) &&
            sameOwner(object->related, requested))
            return i;
    }
    return -1;
}
inline void eraseEntry(HandleList& list, int index) {
    ((RemoveZeroHandle*)&list.data[index])->~RemoveZeroHandle();
    Handle* target = list.data + index;
    int count = --list.count;
    memcpy(target, target + 1, (count - index) * sizeof(Handle));
}
extern "C" void fn_801FF24C(Group* self, const Handle& world) {
    int index = findOwner(self, world);
    removalGlobals().game->slot26();
    removalGlobals().game->slot8();
    Object* object = resolve(self->entries.data[index]);
    fn_80201C14(object);
    fn_80202464(object);
    removalGlobals().dispatcher->remove(&self->entries.data[index]);
    ((RemoveObject*)object)->detachAll();
    RemoveOwnedHandle owner(((RemoveObject*)object)->getOwner());
    eraseEntry(self->entries, index);
    fn_8026B560(removalGlobals().worldContext, &owner);
    removalGlobals().dispatcher->finish();
}
