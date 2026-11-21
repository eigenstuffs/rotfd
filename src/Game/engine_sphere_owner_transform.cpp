#include "Game/engine_sphere_return_layers.h"

extern "C" int fn_8024673C(SphereReturnOwner* self, SphereReturnObject* object, SphereReturnValue* out)
{
    *out = fn_80099A00(object->matrix, self->sphere);
    return 1;
}
