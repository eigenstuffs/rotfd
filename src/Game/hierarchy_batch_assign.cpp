// Reconstructed from the original GSQE78 hierarchy instructions.
#include "hierarchy_batch_internal.h"
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
extern "C" void fn_801F86C8(Manager*, const void*, short);
struct BatchZeroHandle : Handle_801F7F10 { BatchZeroHandle() { value = 0; } };
struct BatchOwnedHandle : BatchZeroHandle {
    BatchOwnedHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct BatchGameEntry {
    char unused[0x14]; Handle target; char unused18[0x34];
    void setTarget(const Handle& source) {
        fn_801F86C8(lbl_801E9D24.manager, &target, -1);
        target.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
inline BatchGameEntry& gameEntry(int index) { return ((BatchGameEntry*)lbl_801E9D24.game)[index]; }
extern "C" void fn_8003125C(Game*, int, BatchOwnedHandle);
static inline void assignEntry(HierarchyBatch* self, int index) {
    int relative = index - self->offset;
    gameEntry(index).setTarget(self->assigned.data[relative]);
    fn_8003125C(lbl_801E9D24.game, index, BatchOwnedHandle(self->owner));
    resolve(self->primary.data[relative])->slot11();
}
extern "C" void fn_80213A18(Object*);
extern "C" void fn_802020AC(HierarchyBatch* self) {
    int index;
    for (index = 0; index < self->activeCount; ++index)
        assignEntry(self, self->offset + index);
    for (index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot11();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot11();
    }
    fn_80213A18(resolve(self->related));
}
