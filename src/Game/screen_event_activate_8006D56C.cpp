#include "Game/early_callback_controller_views.h"
// Screen activation event. These partial handle/array views agree with the
// adjacent accepted camera controls at 8006D174 and 8006D684.
struct ScreenIndex {
    int value;
    ScreenIndex(int v) : value(v) {}
    operator const int&() const { return value; }
};
struct ScreenControlHandle { struct { signed int tag : 8; signed int index : 24; } bits; };
struct ScreenControlEntry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char expected) const { return tag == expected; }
};
struct ScreenEntryArray {
    ScreenControlEntry* data;
    ScreenControlEntry& operator[](int index) const { return data[index]; }
};
struct ScreenControlManager { int count, capacity; ScreenEntryArray entries; };
struct ScreenControlScreen { char unknown00[0x60]; ScreenControlHandle handle; };
struct ScreenControlWorld { char unknown00[0x15058]; ScreenControlScreen* screen; };
struct ScreenControlContext {
    char unknown00[0x118]; ScreenControlManager* manager;
    char unknown11C[8]; ScreenControlWorld* world;
};
extern "C" ScreenControlContext lbl_801E9D24;
inline void* resolveScreenControl(const ScreenControlHandle& handle) {
    ScreenControlManager* manager = lbl_801E9D24.manager;
    ScreenIndex index(handle.bits.index);
    signed char generation = handle.bits.tag;
    if (manager->entries[index].matchesTag(generation))
        return manager->entries[index].object;
    return 0;
}
extern "C" unsigned long fn_801F948C(void*, const char*);
struct ScreenControlName {
    unsigned long value;
    ScreenControlName(const char* text) { value = fn_801F948C(this, text); }
    ScreenControlName(const ScreenControlName& name) : value(name.value) {}
};
struct ScreenActor {
    char unknown00[0x318]; EarlyCallbackController controller;
};
extern "C" {
    void* fn_8005E90C();
    signed char fn_8007D604(EarlyCallbackController*, int);
    signed char fn_8007D6A0(EarlyCallbackController*, int);
    void fn_800A64E0(void*, signed char);
    void fn_800A6234(void*, signed char, ScreenControlName);
    extern const char lbl_80378810[4];
}
inline ScreenActor* currentScreenActor() {
    return static_cast<ScreenActor*>(fn_8005E90C());
}

struct NativeVoidView_800D78E4;
extern "C" void fn_8006D56C(NativeVoidView_800D78E4*, unsigned char) {
    if (!fn_8007D604(&currentScreenActor()->controller, 0x33))
        fn_8007D6A0(&currentScreenActor()->controller, 6);
    fn_800A64E0(resolveScreenControl(lbl_801E9D24.world->screen->handle), 1);
    void* owner = resolveScreenControl(lbl_801E9D24.world->screen->handle);
    ScreenControlName name(lbl_80378810);
    fn_800A6234(owner, 1, name);
}
