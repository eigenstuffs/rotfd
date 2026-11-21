#include "Game/engine_raster_span.h"

void fn_802383D8(struct EngineRasterSpan* self,
    const struct EngineRasterSpanPoint* first,
    const struct EngineRasterSpanPoint* last, const void* color)
{
    int x0 = (int)first->x, y0 = (int)first->y;
    int x1, y1, c;
    unsigned short* indices;
    int y;
    int x;
    if (x0 < 0 || x0 > self->width)
        return;
    if (y0 < 0 || y0 > self->height)
        return;
    x1 = (int)last->x;
    y1 = (int)last->y;
    if (x1 < 0 || x1 > self->width)
        return;
    if (y1 < 0 || y1 > self->height)
        return;
    c = fn_80238900(self, color);
    indices = self->indices;
    for (y = y0; y < y1; y++) {
        for (x = x0; x < x1; x++)
            indices[x + y * self->width] = c;
    }
}
