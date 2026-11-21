/* Original owner spatial transform, bounds and scalar application.
 * See docs/notes/game-engine-owner-spatial-apply.md. */
#pragma fp_contract on
#include "Game/engine_owner_spatial_apply.h"

extern "C" void fn_80248D20(SpatialApplyOwner* self,
                            SpatialApplyObject* object,
                            const SpatialApplyVec3* point,
                            const SpatialApplyRecord* record) {
    int index = object->resource.index;
    SpatialApplyManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    SpatialApplyResource* resource;
    if (generation == object->resource.generation)
        resource = manager->entries[index].object;
    else resource = 0;

    float factor = lbl_8037B418 - fn_800A8E8C(
        point->y - record->position.y, lbl_8037B41C, lbl_8037B420) /
        lbl_8037B420;
    self->output->position = object->getMatrix()->transform(record->position);
    self->output->direction = record->direction;

    SpatialApplyVec3 points[3];
    points[0] = *resource->position;
    points[1] = points[0] + resource->bounds->min;
    points[2] = points[0] + resource->bounds->max;
    fn_801F0C68(self->getSphere(), points, 3);

    SpatialApplyOutput* output = self->output;
    output->scalar = fn_800A8E8C(
        factor * self->getSphere()->radius,
        lbl_8037B424 * self->getSphere()->radius,
        self->getSphere()->radius);
    *self->status |= 0x20;
    object->flags |= 0x80000;
}
