#include "Game/engine_raster_span.h"

int fn_80238310(const struct EngineRasterSpan* self,
    const struct EngineRasterSpanPoint* point, unsigned short* output)
{
    int x = engineRasterSpanInteger(point->x), y = engineRasterSpanInteger(point->y);
    if (x < 0 || x > self->width)
        return 0;
    if (y < 0 || y > self->height)
        return 0;
    *output = self->indices[x + y * self->width];
    return 1;
}
