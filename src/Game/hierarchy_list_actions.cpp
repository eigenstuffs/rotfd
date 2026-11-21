#include "group_runtime_internal.h"
struct HierarchyEntries {
    char unknown00[0x90];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    char unknownB4[0x0C];
    Handle related;
    char unknownC4[0x18];
    int count;
};
extern "C" void fn_802139D8(Object*);
extern "C" void fn_802022FC(HierarchyEntries* self) {
    for (int index = 0; index < self->count; ++index) {
        resolve(self->primary.data[index])->slot10();
        if (fn_801F7EB8(&self->secondary.data[index]))
            resolve(self->secondary.data[index])->slot10();
    }
    fn_802139D8(resolve(self->related));
}
