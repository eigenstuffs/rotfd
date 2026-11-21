#ifndef GAME_VIEWPORT_STORAGE_INTERNAL_H
#define GAME_VIEWPORT_STORAGE_INTERNAL_H
#include "objects_owner_internal.h"
struct ViewportHandle1 : Handle_801F7F10 {
    ViewportHandle1() { value = 0; }
    ~ViewportHandle1() {}
};
struct ViewportHandle2 : ViewportHandle1 {
    ViewportHandle2() { value = 0; }
    ~ViewportHandle2() {}
    ViewportHandle2& operator=(const ViewportHandle2& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Handle_8002F6B0 : ViewportHandle2 {
    Handle_8002F6B0();
    ~Handle_8002F6B0();
};
struct Vector2_800C3BC4 {
    float x, y;
    Vector2_800C3BC4();
};
struct ViewportEntry_801E2F08 {
    u32 unknown[5];
    ViewportEntry_801E2F08();
};
extern "C" {
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
extern const char lbl_802ACEAC[], lbl_802ACEBC[];
}
struct ViewportRecord_801E2EA8 {
    Vector2_800C3BC4 points[16];
    ViewportEntry_801E2F08 entries[16];
    u32 unknown1C0;
    ViewportRecord_801E2EA8();
    static void* operator new[](u32 size) {
        return fn_801EFA1C(lbl_801EF5C8, size, lbl_802ACEAC, lbl_802ACEBC, 33, 4);
    }
    static void operator delete[](void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct Viewport_801E300C {
    int left, top, right, bottom;
    ViewportHandle2 handle10, handle14;
    u32 unknown18[2];
    ViewportRecord_801E2EA8* records;
    u32 unknown24;
    Handle_8002F6B0 handles[8];
    u32 field48;
    Viewport_801E300C();
    ~Viewport_801E300C();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
typedef char CheckViewportSize[sizeof(Viewport_801E300C)==0x4C?1:-1];
typedef char CheckViewportRecordSize[sizeof(ViewportRecord_801E2EA8)==0x1C4?1:-1];
#endif
