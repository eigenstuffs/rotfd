#include "Game/sphere_box_hit_collect_801dfe90.h"

extern "C" signed char fn_801DFE90(void* self, const SphereBoxMatrix* matrix,
                                   SphereBoxCollection* hits, SphereBoxMask flags)
{
    SphereBoxPoint points[8];
    SphereBoxHit hit;
    const int (*face)[4] = lbl_802EAA10;
    int i;
    for (i = 0; i < 8; ++i)
        points[i] = matrix->transform(lbl_80340AC0[i]);
    signed char found = 0;
    for (i = 0; i < 6; ++i) {
        SphereBoxVertex a(points[(*face)[0]]);
        SphereBoxVertex b(points[(*face)[1]]);
        SphereBoxVertex c(points[(*face)[2]]);
        SphereBoxVertex d(points[(*face)[3]]);
        ++face;
        if (fn_801B7C18(self, a, b, c, d, &hit)) {
            SphereBoxRecord& record = hits->records[hits->append()];
            record.point = hit.point;
            record.normal = hit.normal;
            record.distance = hit.distance;
            record.flags = flags;
            found = 1;
        }
    }
    return found;
}
