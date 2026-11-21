// Reconstructed from the original GSQE78 hierarchy instructions.
#include "hierarchy_batch_internal.h"
struct HierarchyBatchObject : Object {
    virtual void setPrimary(int);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void setSecondary(int);
};
struct HierarchyRelatedState { char unknown00[0x24]; int state; };
extern "C" void fn_802139D8(Object*);
static inline void resetLists(HierarchyBatch* self) {
    for (int index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot10();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot10();
    }
    fn_802139D8(resolve(self->related));
}

extern "C" void fn_80202464(HierarchyBatch* self) {
    int index;
    for (index = 0; index < self->count; ++index) {
        if (fn_801F7EB8(&self->secondary.data[index]))
            ((HierarchyBatchObject*)resolve(self->secondary.data[index]))->setSecondary(-1);
        if (fn_801F7EB8(&self->primary.data[index]))
            ((HierarchyBatchObject*)resolve(self->primary.data[index]))->setPrimary(-1);
    }
    for (index = 0; index < self->third.count; ++index)
        if (fn_801F7EB8(&self->third.data[index]))
            resolve(self->third.data[index])->slot10();
    self->offset = -1;
    ((HierarchyRelatedState*)resolve(self->related))->state = self->offset;
    resetLists(self);
}
