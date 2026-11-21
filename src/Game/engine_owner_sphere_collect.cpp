/* Original owner sphere-overlap collection.
 * See docs/notes/game-engine-owner-sphere-collect.md. */
#include "Game/engine_owner_sphere_collect.h"

extern "C" int fn_8024890C(SphereCollectOwner* self,
                           SphereCollectObject* object,
                           const SphereCollectSphere* sphere,
                           const void* unused,
                           SphereCollectResult* output,
                           int maximum, SphereCollectFlags flags) {
    if (!(flags & 0x1000000000ULL)) return 0;

    SphereCollectMaterial* material;
    int count;
    int offset;
    SphereCollectResource* resource;
    int collected;
    SphereCollectVec3* point;
    SphereCollectBounds* bounds;
    unsigned short* status;
    SphereCollectResult* first;
    int i;

    SphereCollectSphere transformed = fn_80099A00(object->getMatrix(), sphere);
    resource = (SphereCollectResource*)resolveSphereCollect(object->resource);
    count = self->count;
    point = self->points;
    bounds = self->bounds;
    status = resource->status;
    SphereCollectSphere bound(game_vec4_zero, lbl_8037B410);
    first = output;
    collected = 0;
    for (i = 0, offset = 0; i < count && collected < maximum;
         offset += 4, ++i, ++status, ++point) {
        if (!(*status & 8)) {
            material = (SphereCollectMaterial*)resolveSphereCollect(
                self->materials[*(int*)(self->indicesBytes + offset)]);
            if (material->flags & 0x200) {
                SphereCollectVec3 points[3];
                points[0] = *point;
                points[1] = points[0] + bounds->min;
                points[2] = points[0] + bounds->max;
                ++bounds;
                fn_801F0C68(&bound, points, 3);
                float radius = transformed.radius + bound.radius;
                if ((transformed.center - bound.center).lengthSquared() <
                    radius * radius) {
                    output->index = i;
                    ++collected;
                    output->owner = self;
                    output->resource = resource;
                    output->point = points[0];
                    output->enabled = 1;
                    output->flags2C = material->flags;
                    output->flags28 = 0x10;
                    output->type = material->type;
                    ++output;
                }
            }
        }
    }
    if (collected) fn_801DC784(first, collected, object);
    return collected;
}
