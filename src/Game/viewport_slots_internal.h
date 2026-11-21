#ifndef GAME_VIEWPORT_SLOTS_INTERNAL_H
#define GAME_VIEWPORT_SLOTS_INTERNAL_H
#include "viewport_storage_internal.h"
#include "game_engine.h"
struct ViewportSlotsView;
struct ViewportRenderObject : Activable_Z {
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40(ViewportSlotsView*);
};
struct ViewportSlotHandle : ViewportHandle2 {
    ViewportSlotHandle() { value = 0; }
    ~ViewportSlotHandle() {}
    ViewportSlotHandle(const ViewportSlotHandle& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ViewportSlotHandle& operator=(const ViewportSlotHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    ViewportRenderObject* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? (ViewportRenderObject*)m->entries[index].object : 0;
    }
};
struct ViewportSlotsView {
    int bounds[4];
    OwnerHandle world;
    ViewportHandle2 camera;
    float horizontal, vertical;
    ViewportRecord_801E2EA8* records;
    int recordCount;
    ViewportSlotHandle slots[8];
    Engine* engine;
};
struct ViewportContext { ViewportSlotsView* viewport; };
extern "C" void fn_801E8274(Activable_Z*, ViewportContext*);
#endif
