#include "Game/engine_viewport_layout.h"

extern "C" void fn_8021239C(ViewportLayout* self, ViewportLayoutScreen* screen,
                           int* x, int* y, int* width, int* height,
                           float* horizontal, float* vertical) {
    ViewportLayoutMode* mode = screen->mode;
    int overflow = 0;
    if (self->x + self->width > lbl_8037AC18 || self->y + self->height > lbl_8037AC18)
        overflow = 1;
    if (overflow) {
        printf(lbl_802AE560);
        self->height = lbl_8037AC1C;
        self->width = lbl_8037AC1C;
        self->y = lbl_8037AC20;
        self->x = lbl_8037AC20;
    }
    float aspect = (float)mode->width / (float)mode->height;
    int left, top, w, h;
    fn_801E2E70(screen, &left, &top, &w, &h);
    *x = left + (int)(self->x * (float)w);
    *y = top + (int)(self->y * (float)h);
    *width = (int)(self->width * (float)w);
    *height = (int)(self->height * (float)h);
    float halfWidth = lbl_8037AC24 * (lbl_8037AC28 * (float)*width);
    *horizontal = halfWidth * self->horizontal;
    float halfHeight = lbl_8037AC24 * (lbl_8037AC28 * (float)*height);
    *vertical = halfHeight * self->vertical;
    *vertical *= aspect;
}
