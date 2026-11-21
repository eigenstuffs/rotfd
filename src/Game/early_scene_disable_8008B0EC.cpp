// Resolve the actor's resource, disable it, then send the scene-disable event.
struct SceneHandleIndex {
    int value;
    SceneHandleIndex(int index) : value(index) {}
    operator int() const { return value; }
};

struct SceneHandle {
    union {
        unsigned long value;
        struct {
            signed int generation : 8;
            signed int index : 24;
        } bits;
    };
};

struct SceneResource {
    char unknown00[0x88];
    unsigned char enabled;
};

struct SceneEntry {
    SceneResource* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];

    signed char getGeneration() const { return generation; }
};

struct SceneManager {
    int count;
    int capacity;
    SceneEntry* entries;
};

struct SceneActor {
    char unknown00[0x24];
    SceneHandle handle;
};

struct SceneOwner {
    char unknown00[8];
    SceneActor* actor;
};

extern "C" {
extern struct {
    char unknown00[0x118];
    SceneManager* manager;
} lbl_801E9D24;
void fn_80255CBC(SceneResource*, int event, int value);
}

inline SceneResource* resolveSceneResource(const SceneHandle& handle) {
    const SceneHandleIndex index(handle.bits.index);
    SceneManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    return generation == handle.bits.generation
               ? manager->entries[index].object
               : 0;
}

extern "C" void fn_8008B0EC(SceneOwner* self) {
    resolveSceneResource(self->actor->handle)->enabled = 0;
    fn_80255CBC(resolveSceneResource(self->actor->handle), 0x79, 0);
}
