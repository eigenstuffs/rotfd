#ifndef GAME_ENGINE_VIEWPORT_LAYOUT_H
#define GAME_ENGINE_VIEWPORT_LAYOUT_H

struct ViewportLayout {
    char unknown00[0x20];
    float x, y, width, height;
    float horizontal, vertical;
};
struct ViewportLayoutMode {
    char unknown00[0x218];
    int width, height;
};
struct ViewportLayoutScreen {
    char unknown00[0x48];
    ViewportLayoutMode* mode;
};
extern "C" {
    extern const float lbl_8037AC18, lbl_8037AC1C, lbl_8037AC20;
    extern const float lbl_8037AC24, lbl_8037AC28;
    extern char lbl_802AE560[];
    int printf(const char*, ...);
    void fn_801E2E70(ViewportLayoutScreen*, int*, int*, int*, int*);
    void fn_8021239C(ViewportLayout*, ViewportLayoutScreen*, int*, int*, int*, int*, float*, float*);
}

typedef char ViewportLayoutSize[sizeof(ViewportLayout) == 0x38 ? 1 : -1];
typedef char ViewportLayoutModeSize[sizeof(ViewportLayoutMode) == 0x220 ? 1 : -1];
#endif
