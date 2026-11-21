#include "group_runtime_internal.h"
struct HierarchyEntries {
    char unknown00[0x90];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
};
extern "C" void fn_80201A14(HierarchyEntries* self, int index) {
    resolve(self->primary.data[index])->slot10();
    if (fn_801F7EB8(&self->secondary.data[index]))
        resolve(self->secondary.data[index])->slot10();
}
extern "C" void fn_80201B14(HierarchyEntries* self, int index) {
    resolve(self->primary.data[index])->slot11();
    if (fn_801F7EB8(&self->secondary.data[index]))
        resolve(self->secondary.data[index])->slot11();
}
