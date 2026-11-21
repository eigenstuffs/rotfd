#include "Game/engine_renderer_rectangle_controls.h"

using namespace RendererRectangleControls;

extern "C" {
    extern const float lbl_8037B7C8;

    void GXSetCurrentMtx(unsigned int);
    void GXSetProjection(const float*, int);
    void fn_80272968(Owner*, void*, int);
    void fn_8027353C(Owner*);

    void GXClearVtxDesc();
    void GXSetVtxDesc(int, int);
    void GXSetNumChans(u8);
    void GXSetNumTexGens(u8);
    void GXSetNumTevStages(u8);
    void GXSetChanCtrl(int, int, int, int, unsigned int, int, int);

    void GXSetTevOrder(int, int, int, int);
    void GXSetTevColorIn(int, int, int, int, int);
    void GXSetTevAlphaIn(int, int, int, int, int);
    void GXSetTevColorOp(int, int, int, int, int, int);
    void GXSetTevAlphaOp(int, int, int, int, int, int);
    void GXSetZMode(u8, int, u8);
    void GXSetZCompLoc(u8);
    void GXBegin(u8, u8, u16);
}

static inline void position(float x, float y, float z) {
    *(volatile float*)0xCC008000 = x;
    *(volatile float*)0xCC008000 = y;
    *(volatile float*)0xCC008000 = z;
}

static inline void color(u8 r, u8 g, u8 b, u8 a) {
    *(volatile u8*)0xCC008000 = r;
    *(volatile u8*)0xCC008000 = g;
    *(volatile u8*)0xCC008000 = b;
    *(volatile u8*)0xCC008000 = a;
}

static inline void texcoord(float u, float v) {
    *(volatile float*)0xCC008000 = u;
    *(volatile float*)0xCC008000 = v;
}

static inline void plainSetup(int colorScale) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetTevOrder(0, 255, 255, 4);
    GXSetTevColorIn(0, 15, 15, 15, 10);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, colorScale, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetZMode(1, 3, 1);
}

static inline void texturedSetup() {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetZMode(1, 3, 1);
}

extern "C" void fn_8027F178(Owner* self, const Vec2* start, const Vec2* end, const Color* top, const Color* bottom,
    float depth) {
    GXSetCurrentMtx(60);
    GXSetProjection(self->screen, 1);

    u8 tr = lbl_8037B7C8 * top->r, tg = lbl_8037B7C8 * top->g, tb = lbl_8037B7C8 * top->b, ta = lbl_8037B7C8 * top->a;

    u8 br = lbl_8037B7C8 * bottom->r, bg = lbl_8037B7C8 * bottom->g, bb = lbl_8037B7C8 * bottom->b, ba = lbl_8037B7C8 * bottom->a;

    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    fn_80272968(self, 0, 4);
    if (ta < 255 || ba < 255) self->flags2D0 |= 1;
    fn_8027353C(self);

    plainSetup(0);
    GXBegin(0x80, 2, 4);

    position(start->x, start->y, -depth);
    color(tr, tg, tb, ta);

    position(end->x, start->y, -depth);
    color(tr, tg, tb, ta);

    position(end->x, end->y, -depth);
    color(br, bg, bb, ba);

    position(start->x, end->y, -depth);
    color(br, bg, bb, ba);

    GXSetProjection(self->projection, 0);
}

extern "C" void fn_8027F460(Owner* self, const Vec2* start, const Vec2* end, const Vec2* uvStart, const Vec2* uvEnd, const Color* input,
    float depth) {
    u8 r = lbl_8037B7C8 * input->r, g = lbl_8037B7C8 * input->g, b = lbl_8037B7C8 * input->b;

    GXSetCurrentMtx(60);
    GXSetProjection(self->screen, 1);
    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    fn_8027353C(self);

    texturedSetup();
    GXSetZCompLoc(0);
    GXBegin(0x80, 1, 4);

    position(start->x, start->y, -depth);
    color(r, g, b, 255);
    texcoord(uvStart->x, uvStart->y);

    position(end->x, start->y, -depth);
    color(r, g, b, 255);
    texcoord(uvEnd->x, uvStart->y);

    position(end->x, end->y, -depth);
    color(r, g, b, 255);
    texcoord(uvEnd->x, uvEnd->y);

    position(start->x, end->y, -depth);
    color(r, g, b, 255);
    texcoord(uvStart->x, uvEnd->y);

    GXSetProjection(self->projection, 0);
    GXSetZCompLoc(1);
}

extern "C" void fn_8027F710(Owner* self, const Vec2* start, const Vec2* end, const Color* input,
    float depth) {
    u8 r = lbl_8037B7C8 * input->r, g = lbl_8037B7C8 * input->g, b = lbl_8037B7C8 * input->b, a = lbl_8037B7C8 * input->a;

    GXSetCurrentMtx(60);
    GXSetProjection(self->screen, 1);
    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    fn_80272968(self, 0, 4);
    if (a < 255) self->flags2D0 |= 1;
    fn_8027353C(self);

    plainSetup(1);
    GXBegin(0x98, 2, 4);

    position(start->x, start->y, -depth);
    color(r, g, b, a);

    position(end->x, start->y, -depth);
    color(r, g, b, a);

    position(start->x, end->y, -depth);
    color(r, g, b, a);

    position(end->x, end->y, -depth);
    color(r, g, b, a);

    GXSetProjection(self->projection, 0);
}
