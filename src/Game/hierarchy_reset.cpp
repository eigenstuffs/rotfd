// Reconstructed hierarchy reset and list dispatch from the original instructions.
#include "group_runtime_internal.h"

struct HierarchyReset {
    char unknown00[0x0C];
    Handle owner;
    char unknown10[0x80];
    HandleList primary;
    char unknown9C[0x0C];
    HandleList secondary;
    char unknownB4[0x0C];
    Handle root;
    HandleList fourth;
    HandleList third;
    int secondaryCount;
};
extern "C" {
void fn_8026A63C(Object*);
void fn_801FBFD0(HierarchyReset*, int, int, float);
extern const float lbl_8037A900;
}
extern "C" void fn_80201C14(HierarchyReset* self) {
    fn_8026A63C(resolve(self->owner));
    resolve(self->root)->slot11();
    int i;
    for (i = 0; i < self->primary.count; ++i)
        if (fn_801F7EB8(&self->primary.data[i]))
            resolve(self->primary.data[i])->slot12();
    for (i = 0; i < self->secondaryCount; ++i)
        if (fn_801F7EB8(&self->secondary.data[i]))
            resolve(self->secondary.data[i])->slot12();
    for (i = 0; i < self->third.count; ++i)
        if (fn_801F7EB8(&self->third.data[i]))
            resolve(self->third.data[i])->slot12();
    for (i = 0; i < self->fourth.count; ++i)
        resolve(self->fourth.data[i])->slot12();
    fn_801FBFD0(self, 15, 82, lbl_8037A900);
}
