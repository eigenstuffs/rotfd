/* Allocate and register three scene callbacks for the owning object. */
#include "Game/scene_vector_owner_800E2288.h"
#include "Game/scene_record_owner_800E1A28.h"

typedef unsigned long Word;

struct SceneCallbackGroup {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10(int);
    char unknown04[0x28];
    void** entries;
};

struct SceneCallbackOwner {
    char unknown00[0x30];
    unsigned long long flags;
    char unknown38[0x1C0];
    SceneCallbackGroup group;
};

extern "C" {
extern const char lbl_802AAFA8[], lbl_802AAFB8[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void fn_8007D6A0(void*, int);
void* fn_800E17B4(void*, unsigned int, unsigned int);
}

inline void* operator new(unsigned long, void* p) throw() { return p; }

struct SelectionActor;
struct SelectionOwner;

extern "C" void fn_800E3094(SelectionActor* actor, SelectionOwner* owner) {
    void* argument = owner;
    SceneCallbackOwner* self = (SceneCallbackOwner*)actor;
    void* first = fn_801EFA1C(lbl_801EF5C8, 16, lbl_802AAFA8,
                            lbl_802AAFB8, 164, 4);
    if (first) {
        first = fn_800E17B4(first, (unsigned int)self, (unsigned int)argument);
    }
    self->group.entries[0] = first;
    self->group.entries[1] =
        new (fn_801EFA1C(lbl_801EF5C8, 44, lbl_802AAFA8, lbl_802AAFB8, 165, 4))
            Object_800E2288((Word)self, (Word)argument);
    self->group.entries[2] =
        new (fn_801EFA1C(lbl_801EF5C8, 0xA8, lbl_802AAFA8, lbl_802AAFB8, 166, 4))
            Object_800E1A28((Word)self, (Word)argument);
    self->group.slot10(3);
    fn_8007D6A0(&self->group, 0);
}
