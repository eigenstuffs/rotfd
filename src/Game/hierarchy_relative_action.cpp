#include "group_runtime_internal.h"
extern "C" void fn_80201F10(Object* self, int index) {
    resolve(self->second.data[index - self->state])->slot10();
}
