#include "Game/sphere_box_first_hit_801dfbc4.h"

extern "C" signed char fn_801DFBC4(void* self, const SphereBoxMatrix* matrix,
                                   SphereBoxResult* result, SphereBoxMask flags)
{
    SphereBoxPoint points[8];
    SphereBoxHit hit;
    const int (*face)[4] = lbl_802EAA10;
    int i;
    for (i = 0; i < 8; ++i)
        points[i] = matrix->transform(lbl_80340AC0[i]);
    for (i = 0; i < 6; ++i) {
        SphereBoxVertex a(points[(*face)[0]]);
        SphereBoxVertex b(points[(*face)[1]]);
        SphereBoxVertex c(points[(*face)[2]]);
        SphereBoxVertex d(points[(*face)[3]]);
        ++face;
        signed char collided = fn_801B7C18(self, a, b, c, d, &hit);
        if (collided) {
            if (!result->valid || hit.distance < result->distance) {
                result->valid = 1;
                result->point = hit.point;
                result->normal = hit.normal;
                result->distance = hit.distance;
                result->flags = flags;
                return 1;
            }
        }
    }
    return 0;
}
