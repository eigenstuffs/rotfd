#include "Game/engine_owner_child_reset.h"

typedef unsigned long ChildResetWord;

struct Handle_801F7F10 {
    union {
        ChildResetWord value;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct ChildResetPoint { float x, y, z; };

struct ChildResetOwner {
    char unknown00[0x20];
    int index;
    Handle_801F7F10 related;
    char unknown28[4];
    ChildResetPoint motion;
    char active;
    char unknown39[7];
    float value40, value44, value48, value4C;
    ChildResetPoint position;
    char enabled;
};

struct ChildResetObject {
    char unknown00[0x22C];
    char state22C, state22D;
    char unknown22E[0xC130 - 0x22E];
    int count;
};

struct ChildResetEntry {
    ChildResetObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};

struct ChildResetManager {
    char unknown00[8];
    ChildResetEntry* entries;
};

extern "C" {
    extern struct {
        char unknown00[0x118];
        ChildResetManager* manager;
    } lbl_801E9D24;
    ChildResetWord fn_801F7EB8(const Handle_801F7F10*);
    void fn_801F86C8(ChildResetManager*, const Handle_801F7F10*, int);
    const Handle_801F7F10* fn_80235C08(ChildResetOwner*);
    void fn_80242E44(ChildResetObject*);
    extern ChildResetPoint game_vec3_zero;
    extern const float lbl_8037B2D0, lbl_8037B2A8, lbl_8037B2B0;
}

struct ChildResetHandle1 : Handle_801F7F10 {
    ChildResetHandle1() { value = 0; }
};
struct ChildResetHandle2 : ChildResetHandle1 {
    ChildResetHandle2() { value = 0; }
};
struct ChildResetHandle3 : ChildResetHandle2 {
    ChildResetHandle3() { value = 0; }
};
struct ChildResetHandle4 : ChildResetHandle3 {
    ChildResetHandle4() { value = 0; }
};

extern "C" ChildResetHandle4 fn_80237BC8(ChildResetObject*, int);

struct ChildResetCopy4 : ChildResetHandle4 {
    ChildResetCopy4(const Handle_801F7F10& handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

static inline ChildResetObject* resolveChildReset(const Handle_801F7F10& handle)
{
    int index = handle.bits.index;
    ChildResetManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation)
        return manager->entries[index].object;
    return 0;
}

extern "C" void fn_80237924(ChildResetOwner* self)
{
    if (self->index >= 0 && fn_801F7EB8(fn_80235C08(self))) {
        int count = resolveChildReset(*fn_80235C08(self))->count;
        for (int index = 0; index < count; ++index) {
            ChildResetCopy4 child(fn_80237BC8(
                resolveChildReset(*fn_80235C08(self)), index));
            fn_80242E44(resolveChildReset(child));
        }
    }
    if (fn_801F7EB8(&self->related)) {
        resolveChildReset(self->related)->state22D = 1;
        resolveChildReset(self->related)->state22C = 1;
    }
    self->motion = game_vec3_zero;
    self->active = 0;
    self->value40 = lbl_8037B2D0;
    self->value44 = lbl_8037B2A8;
    self->value48 = lbl_8037B2B0;
    self->value4C = lbl_8037B2B0;
    self->position = game_vec3_zero;
    self->enabled = 1;
}
