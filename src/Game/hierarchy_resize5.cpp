// Reconstructed native handle-array resize specialization.
#include "hierarchy_resize_internal.h"
extern "C" void fn_802032B8(ResizeArray<HierarchyResizeHandle<5> >* self, int count, char keepCapacity) {
    int i;
    if (count > self->count) {
        if (count > self->capacity || !keepCapacity) {
            self->storage(count);
            self->capacity = count;
        }
        for (i = self->count; i < count; ++i)
            new (self->data + i) HierarchyResizeHandle<5>;
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; --i)
            self->data[i].~HierarchyResizeHandle<5>();
        if (keepCapacity)
            self->count = count;
        else {
            self->storage(count);
            self->capacity = count;
            self->count = count;
        }
    }
}
