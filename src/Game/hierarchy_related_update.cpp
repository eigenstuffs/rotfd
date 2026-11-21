#include "group_runtime_internal.h"
extern "C" void fn_8026A690(Object*, float);
extern "C" void fn_8020349C(Object* self, float delta) {
    if (self->state >= 0)
        fn_8026A690(resolve(self->related), delta);
}
