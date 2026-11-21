// Release one group's game range, then reactivate the remaining assigned groups.
typedef unsigned long u32;

struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Object {
    char unknown[0xE0];
    int width, offset;
};
struct Entry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { u32 unused[2]; Entry* entries; };
struct Game;
struct Globals { char unknown[0x114]; Game* game; Manager* manager; };
struct HandleList { int count, capacity; Handle* data; };
struct Groups { char unknown[0x14]; HandleList entries; };
extern "C" Globals lbl_801E9D24;

struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct StateZeroHandle : Handle_801F7F10 {
    StateZeroHandle() { value = 0; }
};
struct StateHandle : StateZeroHandle {
    StateHandle() { value = 0; }
};

inline Object* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == h.bits.generation)
        return manager->entries[index].object;
    return 0;
}

extern "C" {
void fn_80202464(Object*);
void fn_801E1658(Game*, int);
void fn_8003125C(Game*, int, StateHandle);
void fn_801FEF6C(Groups*, int);

void fn_801FEE10(Groups* self, int index) {
    fn_80202464(resolve(self->entries.data[index]));
    fn_801E1658(lbl_801E9D24.game, 1);
    fn_8003125C(lbl_801E9D24.game, 0, StateHandle());
    for (int i = 0; i < self->entries.count; ++i) {
        Object* object = resolve(self->entries.data[i]);
        if (object && object->offset >= 0)
            fn_801FEF6C(self, i);
    }
}
}
