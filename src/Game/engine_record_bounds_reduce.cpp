#include "Game/engine_record_bounds_reduce.h"

extern "C" void fn_80249D58(RecordBoundsOwner* self, signed char empty) {
    RecordBoundsSphere sphere(game_vec4_zero.x, game_vec4_zero.y,
                              game_vec4_zero.z, lbl_8037B428);
    if (empty) sphere.r = lbl_8037B42C;
    else sphere = *self->getSphere();

    int i;
    for (i = 0; i < self->secondCount; ++i) {
        RecordBoundsRecord record(self->second[i]);
        sphere = fn_801F0A20(sphere,
            fn_80099A00(((RecordBoundsObject*)resolve(record.handle))->matrix,
                        &record.sphere));
    }
    for (i = 0; i < self->firstCount; ++i) {
        RecordBoundsRecord record(self->first[i]);
        sphere = fn_801F0A20(sphere,
            fn_80099A00(((RecordBoundsObject*)resolve(record.handle))->matrix,
                        &record.sphere));
    }
    self->sphere = sphere;
}
