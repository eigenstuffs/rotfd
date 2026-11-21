// Activable list mode filter and update traversal; all cursor references are borrowed.
#include "owner_list_internal.h"

extern "C" void fn_80212904(OwnerList_80213824* self) {
    self->mode8Only = 0;
}
extern "C" void fn_80212910(OwnerList_80213824* self) {
    self->mode8Only = 1;
}
extern "C" void fn_8021291C(OwnerList_80213824* self, float delta) {
    ListObject* current = self->head.get();
    if (self->mode8Only) {
        while (current) {
            if (current->active && current->mode == 8)
                current->update(delta);
            current = current->next.get();
        }
    } else {
        while (current) {
            if (current->active)
                current->update(delta);
            current = current->next.get();
        }
    }
}
