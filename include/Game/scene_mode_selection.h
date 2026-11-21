#ifndef GAME_SCENE_MODE_SELECTION_H
#define GAME_SCENE_MODE_SELECTION_H

extern "C" void fn_801F7CB4(void*, const void*);
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    Handle_801F7F10(const Handle_801F7F10& other) { fn_801F7CB4(this, &other); }
    ~Handle_801F7F10();
};

namespace SceneModeSelection {
struct Entry { void* object; char unknown04[8]; signed char generation; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Mode { char unknown00[0xF0]; int category, state; };
struct Scene { char unknown00[0x15058]; Mode* mode; };
struct Context { char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene; };
struct Owner { char unknown00[0x78]; void* selected; char unknown7C[0x10]; int value8C; };
}

extern "C" SceneModeSelection::Context lbl_801E9D24;

// The returned value is a four-byte typed Handle. Its temporary destroys the
// base subobject with the native nondeleting flag after the pointer is stored.
struct ModeSelectionHandle : Handle_801F7F10 {
    void* get() const {
        SceneModeSelection::Entry* entry = &lbl_801E9D24.manager->entries[bits.index];
        if (entry->generation == bits.generation) return entry->object;
        return 0;
    }
};

extern "C" {
void fn_80056014(SceneModeSelection::Mode*, int);
void fn_80056540(SceneModeSelection::Mode*, int);
ModeSelectionHandle fn_8005863C(SceneModeSelection::Mode*);
void fn_8002B0A8(void*);
}

#endif
