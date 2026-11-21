#include "Game/engine_raster_span.h"

void fn_802385C0(struct EngineRasterSpan* self,
    const struct EngineRasterSpanPoint* point, const void* color)
{
    int x = engineRasterSpanInteger(point->x), y = engineRasterSpanInteger(point->y);
    unsigned short* indices;
    if (x < 0 || x > self->width)
        return;
    if (y < 0 || y > self->height)
        return;
    indices = self->indices;
    indices[x + y * self->width] = fn_80238900(self, color);
}
