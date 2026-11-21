// Handle registry collection pass.
typedef unsigned long u32;
struct Handle { signed int generation : 8; signed int index : 24; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    virtual ~Object();
    virtual void slotC();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void mark();
};
struct Identity { u32 unknown; Handle handle; };
struct Entry { Identity* object; u32 name; short link, references; signed char generation, flags; char padding[2]; };
struct NameHash { u32 value; NameHash(const char*); };
extern "C" { u32 fn_801F948C(void*, const char*); extern const char lbl_8037A820[1]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*); }
struct ManagerStorage {
    int count, capacity; Entry* entries; u32 unknown0C, unknown10;
    int* freeIndices; u32 unknown18; int freeCount; signed char automatic; char padding[3];
};
struct Manager : ManagerStorage {
    virtual void slot0();
    virtual void cleanup();
    virtual void detach(const void*);
    virtual void slot14();
    virtual void mark();
    template<class T> T& field(int index, int offset) { return *(T*)((char*)entries + index * sizeof(Entry) + offset); }
    int valid(int index, signed char generation) {
        int valid = false;
        if (index < count && generation == field<signed char>(index, 12)) valid = true;
        return valid;
    }
    void setFlags(const Handle& handle, signed char value) {
        signed char generation = handle.generation;
        if (valid(handle.index, generation)) field<signed char>(handle.index, 13) = value;
    }
    void release(const Handle& handle) {
        signed char generation = handle.generation;
        int index = handle.index;
        if (valid(index, generation)) {
            detach((char*)field<Object*>(index, 0) + 4);
            field<signed char>(index, 13) = 0;
            field<short>(index, 8) = -1;
            delete field<Object*>(index, 0);
            field<u32>(index, 4) = NameHash(lbl_8037A820).value;
            field<short>(index, 10) = 0;
            ++field<signed char>(index, 12);
            if (!field<Entry>(index, 0).generation) ++field<Entry>(index, 0).generation;
            field<Object*>(index, 0) = 0;
            int slot = freeCount++;
            freeIndices[slot] = index;
        }
    }
    int collect();
};

typedef u32 Word;
struct ListHandle { Word value; };
struct ListObjectPrefix { char unknown[8]; };
struct ListObject : ListObjectPrefix {
    virtual void slot8(); virtual void slotC(); virtual void slot10(); virtual void slot14(); virtual void slot18();
    virtual void mark();
};
struct GEntry { ListObject* object; char unknown04[8]; signed char generation; char pad[3]; };
struct GManager { char unknown00[8]; GEntry* entries; };
extern "C" int fn_80207B94(void*, int, int);
struct HandleList {
    int size, capacity; Handle* data; char bits[16]; int count;
    int first() { if (count == 0) return -1; return fn_80207B94(bits, 1, 0); }
    int next(int index) { ++index; if (index >= count) return -1; return fn_80207B94(bits, 1, index); }
};
struct SubscriberPrefix { char unknown[0x7C]; };
struct Subscriber : SubscriberPrefix { virtual void slot8(); virtual void mark(); };
struct WorldPrefix { char unknown[0x30]; };
struct World : WorldPrefix { virtual void slot8(); virtual void slotC(); virtual void mark(); };
struct RendererPrefix { char unknown[0x278]; };
struct Renderer : RendererPrefix {
    virtual void slot8(); virtual void slotC(); virtual void slot10(); virtual void slot14(); virtual void slot18();
    virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C();
    virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void slot44(); virtual void slot48(); virtual void slot4C(); virtual void mark();
};
struct Globals {
    char unknown[0x110]; void* logger; Renderer* renderer; Manager* context; HandleList* list; void* system120;
    World* world; char unknown128[0x14]; void* groups; char unknown140[4]; Subscriber* system144;
    char unknown148[4]; void* system14C; void* system150; char unknown154[4]; Subscriber* system158;
};
extern "C" Globals lbl_801E9D24;
extern "C" {
void fn_801FFA58(void*); void fn_80263764(void*); void fn_801E6D24(void*); void fn_8023AB78(void*); void fn_801FB0BC(void*);
}
inline ListObject* resolve(const Handle& h) {
    GEntry* s = &((GManager*)lbl_801E9D24.context)->entries[h.index];
    return s->generation == h.generation ? s->object : 0;
}
inline void markList() {
    HandleList* list = lbl_801E9D24.list;
    if (list) for (int i = list->first(); i >= 0; i = list->next(i)) resolve(list->data[i])->mark();
}
extern "C" int fn_801F8D50(Manager* self) {
    int i;
    int remaining = 1;
    self->automatic = 0;
    while (remaining) {
        remaining = 0;
        for (i = 0; i < self->count; ++i) {
            if (self->entries[i].object) self->setFlags(self->entries[i].object->handle, 0);
        }
        lbl_801E9D24.context->mark();
        if (lbl_801E9D24.system144) lbl_801E9D24.system144->mark();
        if (lbl_801E9D24.system158) lbl_801E9D24.system158->mark();
        markList();
        if (lbl_801E9D24.world) lbl_801E9D24.world->mark();
        if (lbl_801E9D24.groups) fn_801FFA58(lbl_801E9D24.groups);
        if (lbl_801E9D24.system14C) fn_80263764(lbl_801E9D24.system14C);
        if (lbl_801E9D24.system150) fn_801E6D24(lbl_801E9D24.system150);
        if (lbl_801E9D24.system120) fn_8023AB78(lbl_801E9D24.system120);
        if (lbl_801E9D24.renderer) lbl_801E9D24.renderer->mark();
        if (lbl_801E9D24.logger) fn_801FB0BC(lbl_801E9D24.logger);
        self->cleanup();
        for (i = 0; i < self->count; ++i) {
            Entry& e = self->entries[i];
            if (e.object && !e.flags) {
                self->release(e.object->handle);
                ++remaining;
            }
        }
    }
    self->automatic = 1;
    return remaining;
}
