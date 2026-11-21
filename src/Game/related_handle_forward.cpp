#include "related_handle_forward_internal.h"

extern "C" signed char fn_8025CEA4(RelatedObject* self, const Handle* handle) {
    return fn_801E48EC(resolve(self->related68), handle);
}

extern "C" void fn_8025CF0C(RelatedObject* self, void* context, float value) {
    Object* target = resolve(self->related60);
    fn_801FC26C(target, 11, &self->identity, context, value);
}

extern "C" signed char fn_8025CF84(RelatedObject* self, const void* key,
                                    void* output, signed char firstKeyOnly) {
    return fn_801C4968(resolve(self->related6C), key, output, firstKeyOnly);
}

extern "C" signed char fn_8025CFEC(RelatedObject* self, void* output) {
    return fn_801C4B7C(resolve(self->related6C), output);
}
