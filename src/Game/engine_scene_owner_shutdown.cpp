#include "Game/engine_scene_owner_shutdown.h"

struct SceneOwnerShutdownGlobals {
    char unknown00[0x124];
    void* owner;
};

extern "C" {
extern SceneOwnerShutdownGlobals lbl_801E9D24;
extern char lbl_801EF5C8[], lbl_8028F698[], lbl_802ED0C0[];
extern void *lbl_80378028, *lbl_80378018, *lbl_80378080, *lbl_80378030;
extern void *lbl_80378058, *lbl_80378050, *lbl_80378040, *lbl_80378048;
extern void *lbl_80378060, *lbl_80378038, *lbl_80378068, *lbl_80378070;
extern void *lbl_80378078, *lbl_80378020;
void fn_8025FA84(void*, int);
void fn_80285CDC(void*, SceneOwnerShutdownNode*);
void fn_8025F6F4(void*, int);
void fn_80260F08(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_8028FD50(void*, void*, SceneOwnerShutdownWord);
void fn_80208768(void*, int);
void fn_801EF610(void*, void*);
}

struct SceneOwnerShutdownHandleArray {
    int count, capacity;
    SceneOwnerShutdownHandle* data;

    ~SceneOwnerShutdownHandleArray() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~SceneOwnerShutdownHandle();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * 4);
                data = 0;
            }
            data = 0;
        }
    }
};

typedef char SceneOwnerShutdownArraySizeCheck[
    sizeof(SceneOwnerShutdownHandleArray) == 12 ? 1 : -1];

inline void Object_80260C7C::operator delete(void* p) throw() {
    fn_801EF610(lbl_801EF5C8, p);
}

Object_80260C7C::~Object_80260C7C() {
    vtable = lbl_802ED0C0;
    lbl_801E9D24.owner = 0;
    if (lbl_80378028)
        fn_8025FA84(lbl_80378028, 1);
    if (lbl_80378018)
        fn_8025FA84(lbl_80378018, 1);
    if (lbl_80378080)
        fn_8025FA84(lbl_80378080, 1);
    if (lbl_80378030)
        fn_8025FA84(lbl_80378030, 1);
    if (lbl_80378058)
        fn_8025FA84(lbl_80378058, 1);
    if (lbl_80378050)
        fn_8025FA84(lbl_80378050, 1);
    if (lbl_80378040)
        fn_8025FA84(lbl_80378040, 1);
    if (lbl_80378048)
        fn_8025FA84(lbl_80378048, 1);
    if (lbl_80378060)
        fn_8025FA84(lbl_80378060, 1);
    if (lbl_80378038)
        fn_8025FA84(lbl_80378038, 1);
    if (lbl_80378068)
        fn_8025FA84(lbl_80378068, 1);
    if (lbl_80378070)
        fn_8025FA84(lbl_80378070, 1);
    if (lbl_80378078)
        fn_8025FA84(lbl_80378078, 1);
    if (lbl_80378020)
        fn_8025FA84(lbl_80378020, 1);

    while (head) {
        SceneOwnerShutdownNode* node = head;
        head = node->next;
        fn_80285CDC(this, node);
    }
    __destroy_arr(snapshotsA048, fn_8025F6F4, 0x2C, 0x400);
    __destroy_arr(records44, fn_80260F08, 0x14, 0x800);
    ((SceneOwnerShutdownHandleArray*)handles34)->~SceneOwnerShutdownHandleArray();
    fn_80208768(&hash20, -1);
}
