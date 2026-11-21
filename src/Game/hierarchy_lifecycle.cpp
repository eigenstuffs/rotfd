// Reconstructed from the original GSQE78 instructions.
#include "hierarchy_lifecycle_internal.h"
signed char Hierarchy_80200478::slot1C() {
    if (!BaseObject_Z::slot1C())
        return false;
    int index;
    for (index = 0; index < count; ++index) {
        if (fn_801F7EB8(&second.data[index]))
            resolve(second.data[index])->slot5();
        if (fn_801F7EB8(&primary.data[index]))
            resolve(primary.data[index])->slot5();
        if (fn_801F7EB8(&secondary.data[index]))
            resolve(secondary.data[index])->slot5();
        if (fn_801F7EB8(&assigned.data[index]))
            resolve(assigned.data[index])->slot5();
    }
    for (index = 0; index < fourth.count; ++index)
        if (fn_801F7EB8(&fourth.data[index]))
            resolve(fourth.data[index])->slot5();
    for (index = 0; index < third.count; ++index)
        if (fn_801F7EB8(&third.data[index]))
            resolve(third.data[index])->slot5();
    resolve(related)->slot5();
    return true;
}
