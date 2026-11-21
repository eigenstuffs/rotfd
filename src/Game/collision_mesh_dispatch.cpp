#include "Game/state_collision_controls.h"

struct CollisionMesh_80242C34 {
    char unknown00[0xA0];
    int countA0;
};

extern "C" {
int fn_80242A24(CollisionMesh_80242C34*, void*, const void*, void*);
int fn_8024222C(CollisionMesh_80242C34*, void*, const void*, const void*, void*);
}

extern "C" int fn_80242C34(CollisionMesh_80242C34* self, void* context,
                          const void* first, const void* second, void* result)
{
    if (self->countA0 <= 2)
        return fn_80242A24(self, context, second, result);
    return fn_8024222C(self, context, first, second, result);
}
