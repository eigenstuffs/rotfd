#include "group_runtime_internal.h"

extern "C" int fn_801FF834(Group* self, int id) {
    for (int i = 0; i < self->entries.count; ++i) {
        Object* object = resolve(self->entries.data[i]);
        if (object && fn_801F7EB8(&object->related)) {
            for (int j = 0; j < object->maximum; ++j) {
                if (fn_801F7EB8(&object->second.data[j])) {
                    Handle* returned = resolve(object->second.data[j])->get(-1);
                    if (id == resolve(*returned)->identifier)
                        return i;
                }
            }
        }
    }
    return -1;
}
