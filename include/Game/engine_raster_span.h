#ifndef GAME_ENGINE_RASTER_SPAN_H
#define GAME_ENGINE_RASTER_SPAN_H

struct EngineRasterSpan {
    char unknown00[0xC];
    unsigned short* indices;
    char unknown10[0x20];
    int width, height;
};
struct EngineRasterSpanPoint {
    float x, y;
};

extern const float lbl_8037B2DC, lbl_8037B2D8;
extern int fn_80238900(struct EngineRasterSpan*, const void*);

static inline int engineRasterSpanInteger(float value)
{
    if (value < lbl_8037B2DC)
        return (int)(value - lbl_8037B2D8);
    return (int)value;
}

#endif
