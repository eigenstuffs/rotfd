// Private four-layer object-handle view, shared by the matching lifetime fragments.
#ifndef GAME_INGAME_MANIPULATOR_HANDLE_INTERNAL_H
#define GAME_INGAME_MANIPULATOR_HANDLE_INTERNAL_H
typedef unsigned long u32;
struct Manager;
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct InGameHandle1 : Handle_801F7F10 {
    InGameHandle1() { value = 0; }
    ~InGameHandle1() {}
};
struct InGameHandle2 : InGameHandle1 {
    InGameHandle2() { value = 0; }
    ~InGameHandle2() {}
};
struct InGameHandle3 : InGameHandle2 {
    InGameHandle3() { value = 0; }
    ~InGameHandle3() {}
};
struct InGameHandle4 : InGameHandle3 {
    InGameHandle4() { value = 0; }
    ~InGameHandle4() {}
    InGameHandle4& operator=(const Handle_801F7F10& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
#endif
