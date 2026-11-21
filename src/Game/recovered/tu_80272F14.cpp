// GCRenderer_Z.cpp, part: .text 0x80272F14-0x80275990 (matrix load .. renderer init).
// The original translation unit is larger: it starts at or before fn_8027235C (which
// uses the same string pool) and its .sdata2 starts before 0x8037B6F0, so 0.0f
// (lbl_8037B6DC), the cached-color tolerance (lbl_8037B6E8) and 255.0f (lbl_8037B6EC)
// stay external until the earlier functions are merged.
// Owned data: .data 0x802ED540-0x802ED6E8 (cheat button sequences, virtual table), .rodata 0x802AEFD0-0x802AF0FA
// (string pool), .sdata2 0x8037B6F0-0x8037B738 (named constants and the two conversion biases).
inline void* operator new(unsigned long, void* p) { return p; }

// .rodata 0x802AEFD0-0x802AF0FA: the file's string pool.  The five scrambled cheat messages
// are the targets of the .sdata pointers lbl_803774F8..lbl_80377508 and the three resource
// names are used by fn_8027235C; both still live in other units and need the labels, so the
// pool is spelled out as named arrays until those are merged here as well.
#pragma force_active on
namespace StringPool_802AEFD0 {
extern "C" {
extern const char lbl_802AEFD0[] = "Kjn!sfbmmz!mjlft!qpp";
extern const char lbl_802AEFE8[] = "Bnz!Tvf-!Kjn!mpwft!zpv\"\"";
extern const char lbl_802AF004[] = "Zpv!ibwf!npwfe!joup!b!ebsl!qmbdf/";
extern const char lbl_802AF028[] = "Ju!jt!qjudi!cmbdl/!!Zpv!bsf!mjlfmz!up!cf!fbufo!cz!b!Hsvf/";
extern const char lbl_802AF064[] = "Ij![vsjob\"!!J!kvtu!xboufe!up!ufmm!zpv!uibu!J!mpwf!zpv";
extern const char lbl_802AF09C[] = "ShadowBitmap";
extern const char lbl_802AF0AC[] = "ShadowMaterial";
extern const char lbl_802AF0BC[] = "Material";
extern const char lbl_802AF0C8[] = "Anonymous Alloc";
extern const char lbl_802AF0D8[] = "GCRenderer_Z.cpp";
extern const char lbl_802AF0EC[] = "Anonymous New";
}
}
#pragma force_active reset

// .sdata2 0x8037B6F0: 1.0f, the first constant of this part (the signed conversion bias
// pooled by fn_8027301C follows at 0x8037B6F8).  Like the constants below it is defined in
// its own namespace so the functions read it as an external object.
namespace Constants_8037B6F0 {
extern "C" {
extern const float lbl_8037B6F0 = 1.0f;
}
}

namespace Projection_80272F14 {
typedef float Mtx[3][4];
struct Matrix44 { float m[4][4]; };
struct Handle {
    signed int tag : 8, index : 24;
};
struct Camera {
    char unknown00[0x11C];
    float fov11C;
};
struct Viewport {
    char unknown00[0x1C];
    Handle camera1C;
};
struct ViewSlot {
    char unknown00[0x14];
    Handle viewport14;
    char unknown18[0x34];
};
struct ViewportEntry {
    Viewport* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct ViewportManager {
    int count, capacity;
    ViewportEntry* entries;
};
struct CameraEntry {
    Camera* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct CameraManager {
    int count, capacity;
    CameraEntry* entries;
};
struct Global {
    char unknown00[0x118];
    void* manager;
};
struct OwnerBase {
    ViewSlot slots[7];
    char unknown214;
    signed char current215;
    char unknown216[2];
    int width218;
    int height21C;
    char unknown220[0x48];
    float scale268;
    float scale26C;
    int x270;
    int y274;
};
struct Owner : OwnerBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void overlap(int x, int y, int w, int h);
    char unknown27C[0x2E0 - 0x27C];
    Mtx mtx2E0;
    char unknown310[0x10];
    float proj320[4][4];
    float ortho360[4][4];
};
extern "C" {
void fn_800F6D38(Mtx, Mtx);
void fn_800F6D6C(Mtx, Mtx);
void GXLoadPosMtxImm(Mtx, unsigned long);
void GXLoadTexMtxImm(Mtx, unsigned long, int);
void GXLoadNrmMtxImm(Mtx, unsigned long);
void GXSetCurrentMtx(unsigned long);
extern Global lbl_801E9D24;
extern const float lbl_8037B6DC, lbl_8037B6F0, lbl_8037B700, lbl_8037B704, lbl_8037B708, lbl_8037B70C, lbl_80377FA8;
void fn_801E2E70(ViewSlot*, int*, int*, int*, int*);
void* fn_801F7EB8(const void*);
void fn_801E15A4(Owner*, int);
int fn_801EC778(int, int);
int fn_801EC764(int, int);
void GXDrawDone();
void GXSetProjection(const float (*)[4], int);
void GXSetViewport(float, float, float, float, float, float);
void GXSetScissor(unsigned long, unsigned long, unsigned long, unsigned long);
void MTXPerspective(float (*)[4], float, float, float, float);
void MTXOrtho(float (*)[4], float, float, float, float, float, float);
}
inline Viewport* resolveViewport(const Handle& h) {
    int index = h.index;
    ViewportManager* m = (ViewportManager*)lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}
inline Camera* resolveCamera(const Handle& h) {
    int index = h.index;
    CameraManager* m = (CameraManager*)lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}
inline float neg(double x) { return -(float)x; }
extern "C" void fn_80272F14(Owner* self, Matrix44* src) {
    Mtx m __attribute__((aligned(32)));
    float a, b, c, d;
    for (int i = 0; i < 3; i++) {
        a = src->m[0][i];
        m[i][0] = a;
        b = src->m[1][i];
        m[i][1] = b;
        c = src->m[2][i];
        m[i][2] = c;
        d = src->m[3][i];
        m[i][3] = d;
    }
    float* r = m[2];
    r[0] = neg(r[0]); r[1] = neg(r[1]); r[2] = neg(r[2]); r[3] = neg(r[3]);
    fn_800F6D38(m, self->mtx2E0);
    GXLoadPosMtxImm(m, 0);
    GXLoadTexMtxImm(m, 0x21, 1);
    fn_800F6D6C(m, m);
    GXLoadNrmMtxImm(m, 0);
    GXSetCurrentMtx(0);
}

extern "C" void fn_8027301C(Owner* self) {
    int x, y, w, h;
    if (self->current215 != -1) {
        fn_801E2E70(&self->slots[self->current215], &x, &y, &w, &h);
    } else {
        x = 0;
        y = 0;
        w = self->width218;
        h = self->height21C;
    }
    GXSetProjection(self->proj320, 0);
    GXSetViewport((float)x, (float)y, (float)w, (float)h, lbl_8037B6DC, lbl_8037B6F0);
    GXSetScissor(x, y, w, h);
}

}

// Named constants of this unit, in pool order after the signed conversion bias that
// fn_8027301C pools at 0x8037B6F8.  They are defined in their own namespace so the
// functions below read them as external objects (their recovered forms depend on that).
namespace Constants_8037B700 {
extern "C" {
extern const float lbl_8037B700 = 57.2957763671875f;
extern const float lbl_8037B704 = 60.0f;
extern const float lbl_8037B708 = 0.01f;
extern const float lbl_8037B70C = 600.0f;
extern const float lbl_8037B710 = 128.0f;
extern const float lbl_8037B714 = 640.0f;
extern const float lbl_8037B718 = 448.0f;
extern const float lbl_8037B71C = 0.5f;
extern const float lbl_8037B720 = 6.0f;
extern const float lbl_8037B724 = 10.0f;
extern const float lbl_8037B728 = 20.0f;
extern const float lbl_8037B72C = 400.0f;
}
}

namespace Projection_80272F14 {
extern "C" void fn_80273124(Owner* self, int index) {
    int x, y, w, h;
    float fov;
    fn_801E15A4(self, index);
    self->scale26C = -self->scale26C;
    GXDrawDone();
    if (index != -1) {
        ViewSlot* slot = &self->slots[index];
        fn_801E2E70(slot, &x, &y, &w, &h);
        if (fn_801F7EB8(&slot->viewport14)) {
            for (int i = 0; i < index; i++) {
                int x2, y2, w2, h2;
                fn_801E2E70(&self->slots[i], &x2, &y2, &w2, &h2);
                int dx = fn_801EC778(x + w, x2 + w2) - fn_801EC764(x, x2);
                int dy = fn_801EC778(y + h, y2 + h2) - fn_801EC764(y, y2);
                if (dx > 0 && dy > 0) {
                    self->overlap(x, y, w, h);
                    break;
                }
            }
            fov = lbl_8037B700 * resolveCamera(resolveViewport(slot->viewport14)->camera1C)->fov11C;
        } else {
            fov = lbl_8037B704;
        }
    } else {
        x = 0;
        y = 0;
        w = self->width218;
        h = self->height21C;
        fov = lbl_8037B704;
    }
    MTXPerspective(self->proj320, fov / lbl_80377FA8, lbl_80377FA8, lbl_8037B708, lbl_8037B70C);
    MTXOrtho(self->ortho360, (float)y, (float)h, (float)x, (float)w, lbl_8037B6F0, lbl_8037B70C);
    GXSetProjection(self->proj320, 0);
    GXSetViewport((float)x, (float)y, (float)w, (float)h, lbl_8037B6DC, lbl_8037B6F0);
    GXSetScissor(x, y, w, h);
}
}

namespace DepthClear_80273448 {
extern "C" void GXPokeZMode(int, int, int);

extern "C" void fn_80273448(void*, int x, int y, int width, int height) {
    GXPokeZMode(1, 7, 1);
    volatile unsigned long* data = (volatile unsigned long*)0xC8400000 + x + y * 1024;
    int stride = 1024 - width;
    int row = y;
    int xend = x + width;
    int yend = y + height;
    for (; row < yend; ++row) {
        for (int column = x; column < xend; ++column) *data++ = 0xFFFFFF;
        data += stride;
    }
}
}


namespace RenderPipeline_8027353C {
typedef unsigned char Byte;
typedef unsigned short Half;
struct Color { Byte r,g,b,a; };
struct Material { Byte unknown[0x18]; float alpha; };
struct Owner { Byte unknown0[0x2d0]; Half requested, cached; Material* material; Byte unknown2D8[0x9ec-0x2d8]; float factor; };

extern "C" {
extern const float lbl_8037B6EC,lbl_8037B710;
void GXSetBlendMode(int, int, int, int);
void GXSetAlphaCompare(int, int, int, int, int);
void GXSetZCompLoc(Byte);
void GXSetZMode(int, int, int);
void GXSetTevKAlphaSel(int, int);
void GXSetTevKColor(int, Color);
void GXSetTexCoordGen2(int, int, int, int, int, int);
void GXClearVtxDesc();
void GXSetVtxDesc(int, int);
void GXSetNumChans(Byte);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevColorIn(int, int, int, int, int);
void GXSetTevAlphaIn(int, int, int, int, int);
void GXSetTevColorOp(int, int, int, int, int, int);
void GXSetTevAlphaOp(int, int, int, int, int, int);
void GXSetNumTevStages(Byte);
void GXSetTevKColorSel(int, int);
void GXSetNumTexGens(Byte);
}
extern "C" void fn_8027353C(Owner* self) {
    if (self->requested == self->cached) return;
    self->cached = self->requested;
    Color color;
    if (self->requested & 4) {
        GXSetBlendMode(1,1,1,0);
        GXSetAlphaCompare(4,0,0,3,255);
        GXSetZCompLoc(1);
        GXSetZMode(1,3,0);
        GXSetTevKAlphaSel(1,0);
        color.a=255;
        GXSetTevKColor(1,color);
    } else if (self->requested & 1) {
        GXSetBlendMode(1,4,5,0);
        GXSetAlphaCompare(4,0,0,3,255);
        GXSetZCompLoc(1);
        GXSetZMode(1,3,0);
        color.r=255; color.g=255; color.b=255;
        color.a=(Byte)(self->material ? lbl_8037B6EC*self->material->alpha : lbl_8037B6EC);
        GXSetTevKColor(3,color);
        GXSetTevKAlphaSel(1,31);
    } else if (self->requested & 2) {
        GXSetBlendMode(0,1,1,0);
        GXSetAlphaCompare(4,220,0,3,255);
        GXSetZCompLoc(0);
        GXSetZMode(1,3,1);
        GXSetTevKAlphaSel(1,0);
        color.a=255;
        GXSetTevKColor(1,color);
    } else {
        GXSetBlendMode(0,1,0,0);
        GXSetAlphaCompare(4,0,0,3,255);
        GXSetZCompLoc(1);
        GXSetZMode(1,3,1);
        GXSetTevKAlphaSel(1,0);
        color.a=255;
        GXSetTevKColor(1,color);
    }
    int numTex=0;
    int nextCoord=0;
    int textureCoord,textureMap,colorInput,alphaInput;
    if(self->requested & 8) {
        textureCoord=0;textureMap=0;colorInput=8;alphaInput=4;
        GXSetTexCoordGen2(numTex++,0,12,30,0,125);
        nextCoord=1;
    } else {
        textureCoord=255;textureMap=255;colorInput=12;alphaInput=6;
    }
    int lightMask;
    if(self->requested&0x400) lightMask=3;
    else if(self->requested&0x800) lightMask=7;
    else if(self->requested&0x1000) lightMask=15;
    else lightMask=1;
    if(self->requested & 0x10) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 2);
    GXSetVtxDesc(10, 2);
    GXSetVtxDesc(11, 2);
    GXSetVtxDesc(13, 2);
    GXSetNumChans(2);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetChanCtrl(5, 1, 0, 0, lightMask, 2, 1);
    GXSetTevOrder(0, 255, 255, 5);
    GXSetTevColorIn(0, 15, 10, 12, 2);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, 255, 255, 0);
    GXSetTevColorIn(1, 15, 0, 10, 15);
    GXSetTevAlphaIn(1, 7, 0, 6, 7);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevOrder(2, textureCoord, textureMap, 255);
    GXSetTevColorIn(2, 15, 0, colorInput, 15);
    GXSetTevAlphaIn(2, 7, 0, alphaInput, 7);
    GXSetTevColorOp(2, 0, 0, 1, 1, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    if(self->requested & 0x8000) {
    GXSetNumTevStages(4);
    GXSetTevOrder(3, 255, 255, 2);
    GXSetTevColorIn(3, 4, 0, 11, 15);
    GXSetTevAlphaIn(3, 7, 7, 7, 0);
    GXSetTevColorOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    } else { GXSetNumTevStages(3); }
    } else if(self->requested & 0x20) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 3);
    GXSetVtxDesc(10, 3);
    GXSetVtxDesc(11, 3);
    GXSetVtxDesc(13, 3);
    GXSetNumChans(2);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetChanCtrl(5, 1, 0, 0, lightMask, 2, 1);
    GXSetTevOrder(0, 255, 255, 5);
    GXSetTevColorIn(0, 15, 10, 12, 2);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, textureCoord, textureMap, 255);
    GXSetTevColorIn(1, 15, 0, colorInput, 15);
    GXSetTevAlphaIn(1, 7, 0, alphaInput, 7);
    GXSetTevColorOp(1, 0, 0, 1, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    if(self->requested & 0x4000) {
        Color factor;
        factor.r=factor.g=factor.b=factor.a=(Byte)(lbl_8037B710*self->factor);
        GXSetTevKColor(2,factor);
    GXSetTevKColorSel(2, 18);
    GXSetTexCoordGen2(nextCoord, 1, 1, 33, 0, 125);
    GXSetTevOrder(2, nextCoord, 2, 255);
    GXSetTevColorIn(2, 15, 8, 14, 0);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    ++numTex;
    if(self->requested & 0x8000) {
    GXSetNumTevStages(4);
    GXSetTevOrder(3, 255, 255, 2);
    GXSetTevColorIn(3, 4, 0, 11, 15);
    GXSetTevAlphaIn(3, 7, 7, 7, 0);
    GXSetTevColorOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    } else { GXSetNumTevStages(3); }
    } else if(self->requested & 0x8000) {
    GXSetNumTevStages(3);
    GXSetTevOrder(2, 255, 255, 2);
    GXSetTevColorIn(2, 4, 0, 11, 15);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    } else { GXSetNumTevStages(2); }
    } else if(self->requested & 0x40) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetNumChans(2);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetChanCtrl(5, 1, 0, 0, 0, 2, 2);
    GXSetTevOrder(0, 255, 255, 5);
    GXSetTevColorIn(0, 15, 10, 12, 2);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, textureCoord, textureMap, 255);
    GXSetTevColorIn(1, 15, 0, colorInput, 15);
    GXSetTevAlphaIn(1, 7, 0, alphaInput, 7);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    if(self->requested & 0x8000) {
    GXSetNumTevStages(3);
    GXSetTevOrder(2, 255, 255, 4);
    GXSetTevColorIn(2, 4, 0, 11, 15);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    } else { GXSetNumTevStages(2); }
    } else if(self->requested & 0x80) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 1, 0, 1, 0, 2, 2);
    GXSetNumTevStages(2);
    GXSetTevOrder(0, 255, 255, 4);
    GXSetTevColorIn(0, 15, 10, 12, 2);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, textureCoord, textureMap, 255);
    GXSetTevColorIn(1, 15, 0, colorInput, 15);
    GXSetTevAlphaIn(1, 7, 0, alphaInput, 7);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    } else if(self->requested & 0x100) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 2);
    GXSetVtxDesc(13, 2);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 1, 0, 0, 2, 2);
    GXSetNumTevStages(2);
    GXSetTevOrder(0, 255, 255, 4);
    GXSetTevColorIn(0, 15, 10, 12, 2);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(1, textureCoord, textureMap, 255);
    GXSetTevColorIn(1, 15, 0, colorInput, 15);
    GXSetTevAlphaIn(1, 7, 0, alphaInput, 7);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetBlendMode(0, 1, 0, 0);
    GXSetAlphaCompare(4, 0, 0, 3, 255);
    GXSetZCompLoc(1);
    GXSetZMode(0, 7, 0);
    } else if(self->requested & 0x2000) {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    }
    GXSetNumTexGens((Byte)numTex);
}
}

namespace Renderer_80274448 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct GXColor {
    u8 r, g, b, a;
};
struct Vec3 {
    float x, y, z;
};
struct Vec2 {
    float x, y;
};
struct Color4 {
    float r, g, b, a;
};

struct DisplayList {
    void* data;
    u32 capacity;
    u32 size;
};

struct PairedBufferView;
struct DisplayListObj : DisplayList { DisplayListObj() { data = 0; capacity = 0; size = 0; } };

struct RenderMode {
    u32 viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    u32 xFBmode;
    u8 field_rendering;
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
};

struct RendererBase {
    char unknown000[0x218];
    int width218;
    int height21C;
    char unknown220[0x10];
    char active230;
    char unknown231[0x278 - 0x231];
};

struct Renderer : RendererBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void beginFrame();
    virtual void endFrame();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void textSize(Vec2*, Vec2*, Color4*, Color4*);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void drawText(Vec2*, const char*, void*);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void initFormats();
    void* fifo27C;
    void* buffer280;
    void* buffer284;
    void* buffer288;
    void* xfb28C;
    u32 frame290;
    RenderMode mode294;
    u16 flags2D0;
    u16 mask2D2;
    int value2D4;
    char unknown2D8[0x360 - 0x2D8];
    float ortho360[4][4];
    Vec3 color3A0;
    void* records3AC;
    int count3B0;
    DisplayList lists3B4[3];
    DisplayList lists3D8[128];
    u32 count9D8;
    PairedBufferView* font9DC;
    char black9E0;
    char unknown9E1[3];
    DisplayList* dyn9E4;
    u32 count9E8;
    char unknown9EC[4];
    void* buffer9F0;
    void* buffer9F4;
    int value9F8;
    int value9FC;
};

struct InputManager;
struct GlobalContext {
    char unknown000[0x154];
    InputManager* input154;
    char unknown158[0x184 - 0x158];
    void* sound184;
};

extern "C" {
extern GlobalContext lbl_801E9D24;
extern const GXColor lbl_8037B6D8;
extern const float lbl_8037B6DC, lbl_8037B6E8, lbl_8037B6EC, lbl_8037B6F0;
extern const float lbl_8037B714, lbl_8037B718, lbl_8037B71C, lbl_8037B720, lbl_8037B724, lbl_8037B728, lbl_8037B72C;
extern char* lbl_803774F8;
extern char* lbl_803774FC;
extern char* lbl_80377500;
extern char* lbl_80377504;
extern char* lbl_80377508;
extern char* lbl_8037750C;
extern char lbl_8033E738[];
extern char lbl_803780A8;
extern int lbl_803780AC;
extern char lbl_803780B0;
extern volatile int lbl_803780E0;
extern Vec3 game_vec3_zero;
extern char lbl_8028F698[];
extern char lbl_801EF5C8[];
char fn_80275BA4(InputManager*, int, const u32*);
void fn_80275B94(InputManager*);
void fn_8027353C(Renderer*);
void fn_801E1378(Renderer*);
void fn_802816D0(void*);
void fn_8028F8F0(void*, void*, u32);
void* fn_8028FACC(void*, u32);
void fn_801EF610(void*, void*);
PairedBufferView* fn_8027BAD4(PairedBufferView*, int);
void DCInvalidateRange(void*, u32);
void DCStoreRange(void*, u32);
void GXBeginDisplayList(void*, u32);
u32 GXEndDisplayList();
void GXResetWriteGatherPipe();
void GXBegin(int, int, u16);
void GXFlush();
void GXDrawDone();
void GXAbortFrame();
void VIFlush();
void VIWaitForRetrace();
void VISetNextFrameBuffer(void*);
void VISetBlack(int);
u32 VIGetNextField();
void GXSetViewport(float, float, float, float, float, float);
void GXSetViewportJitter(float, float, float, float, float, float, u32);
void GXSetScissor(u32, u32, u32, u32);
void GXSetProjection(const float (*)[4], int);
void GXSetCurrentMtx(u32);
void GXLoadTlut(void*, u32);
void GXLoadTexObj(void*, int);
void GXClearVtxDesc();
void GXSetVtxDesc(int, int);
void GXSetNumTexGens(u8);
void GXSetTexCoordGen2(int, int, int, u32, u8, u32);
void GXSetNumChans(u8);
void GXSetChanCtrl(int, u8, int, int, u32, int, int);
void GXSetNumTevStages(u8);
void GXSetTevOrder(int, int, int, int);
void GXSetTevColorIn(int, int, int, int, int);
void GXSetTevAlphaIn(int, int, int, int, int);
void GXSetTevColorOp(int, int, int, int, u8, int);
void GXSetTevAlphaOp(int, int, int, int, u8, int);
void GXSetZMode(u8, int, u8);
void GXCallDisplayList(void*, u32);
void GXSetCopyClear(GXColor, u32);
void GXSetColorUpdate(u8);
void GXCopyDisp(void*, u8);
void GXSetTevColor(int, GXColor);
}

static u32 sCheat0[13] = {0x8,0x8,0x4,0x4,0x1,0x2,0x1,0x2,0x200,0x100,0x200,0x100,0x1000};
static u32 sCheat1[13] = {0x8,0x8,0x4,0x4,0x1,0x2,0x1,0x2,0x100,0x200,0x200,0x100,0x1000};
static u32 sCheat2[6] = {0x10,0x10,0x800,0x10,0x800,0x400};
static u32 sCheat3[13] = {0x4,0x4,0x8,0x8,0x2,0x1,0x2,0x1,0x100,0x200,0x100,0x200,0x1000};
static u32 sCheat4[12] = {0x200,0x100,0x200,0x100,0x1,0x1,0x2,0x2,0x8,0x4,0x8,0x4};
inline int decode(char* out, const char* in) {
    int n = 0;
    char* p = out;
    const char* s = in;
    while (*s) {
        n++;
        *p = *s - 1;
        p++;
        s++;
    }
    return n;
}
inline void freeDisplayList(DisplayList* dl) {
    if (dl->data) {
        fn_8028F8F0(lbl_8028F698, dl->data, dl->capacity);
    }
    dl->data = 0;
    dl->capacity = 0;
    dl->size = 0;
}
// Second-line variant: advances the caller's pointer and reports the length.
inline void decodeAdvance(char*& out, const char* in, int& len) {
    len = 0;
    const char* s = in;
    while (*s) {
        len++;
        *out = *s - 1;
        out++;
        s++;
    }
}
/* Register/order note for the four cheat-text blocks: the target loads 0.0, 1.0, 640, 448
   (in that order) into f3, f1, f2, f0 and stores pos, size, c.bgr, c.a. FPRs are coloured in
   descending virtual-register order and the scheduler keeps the original order of equal
   priority loads, so 0.0/640/1.0 must sit in named locals (declared one, w, z; assigned
   z, one, w) while 448 is a codegen temp. The volatile reads stop the optimizer from
   forward-substituting the single-use locals into their stores (they still emit plain lfs). */
#define VOLATILE_F(x) (*(const volatile float*)&(x))
#define ZERO_1 lbl_8037B6DC
#define ZERO_2 (*(const float*)(unsigned long)&lbl_8037B6DC)
#define ZERO_3 ((*(const float(*)[1])&lbl_8037B6DC)[0])
extern "C" void fn_80274448(Renderer* self) {
    if (!self->active230) {
        self->beginFrame();
    }
    GXColor clear = lbl_8037B6D8;
    if (fn_80275BA4(lbl_801E9D24.input154, 0xd, sCheat0)) {
        char buf[512];
        Color4 c;
        Vec2 pos;
        Vec2 size;
        float one, w, z;
        z = lbl_8037B6DC;
        one = VOLATILE_F(lbl_8037B6F0);
        w = VOLATILE_F(lbl_8037B714);
        pos.y = pos.x = z;
        size.x = w;
        size.y = lbl_8037B718;
        c.r = c.g = c.b = z;
        c.a = one;
        self->textSize(&pos, &size, &c, &c);
        pos.x = size.x * lbl_8037B71C;
        pos.y = size.y * lbl_8037B71C;
        GXDrawDone();
        GXFlush();
        buf[decode(buf, lbl_803774F8)] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
    } else if (fn_80275BA4(lbl_801E9D24.input154, 0xd, sCheat1)) {
        char buf[512];
        Color4 c;
        Vec2 pos;
        Vec2 size;
        float one, w, z;
        z = lbl_8037B6DC;
        one = VOLATILE_F(lbl_8037B6F0);
        w = VOLATILE_F(lbl_8037B714);
        pos.y = pos.x = z;
        size.x = w;
        size.y = lbl_8037B718;
        c.r = c.g = c.b = z;
        c.a = one;
        self->textSize(&pos, &size, &c, &c);
        pos.x = size.x * lbl_8037B71C;
        pos.y = size.y * lbl_8037B71C;
        GXDrawDone();
        GXFlush();
        buf[decode(buf, lbl_803774FC)] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
    } else if (fn_80275BA4(lbl_801E9D24.input154, 6, sCheat2)) {
        char buf[512];
        Color4 c;
        Vec2 pos;
        Vec2 size;
        float one, w, z;
        z = lbl_8037B6DC;
        one = VOLATILE_F(lbl_8037B6F0);
        w = VOLATILE_F(lbl_8037B714);
        pos.y = pos.x = z;
        size.x = w;
        size.y = lbl_8037B718;
        c.r = c.g = c.b = z;
        c.a = one;
        self->textSize(&pos, &size, &c, &c);
        pos.x = size.x / lbl_8037B720;
        pos.y = size.y * lbl_8037B71C;
        GXDrawDone();
        GXFlush();
        char* t = buf;
        buf[decode(t, lbl_80377500)] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
        pos.y += lbl_8037B724;
        int len;
        decodeAdvance(t, lbl_80377504, len);
        buf[len] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
    } else if (fn_80275BA4(lbl_801E9D24.input154, 0xd, sCheat3)) {
        char buf[512];
        Color4 c;
        Vec2 pos;
        Vec2 size;
        float one, w, z;
        z = lbl_8037B6DC;
        one = VOLATILE_F(lbl_8037B6F0);
        w = VOLATILE_F(lbl_8037B714);
        pos.y = pos.x = z;
        size.x = w;
        size.y = lbl_8037B718;
        c.r = c.g = c.b = z;
        c.a = one;
        self->textSize(&pos, &size, &c, &c);
        pos.x = size.x / lbl_8037B720;
        pos.y = size.y * lbl_8037B71C;
        GXDrawDone();
        GXFlush();
        buf[decode(buf, lbl_80377508)] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
    } else if (fn_80275BA4(lbl_801E9D24.input154, 0xc, sCheat4)) {
        lbl_803780A8 = !lbl_803780A8;
        fn_80275B94(lbl_801E9D24.input154);
    }
    if (lbl_803780A8) {
        char buf[512];
        Vec2 pos;
        pos.x = lbl_8037B728;
        pos.y = lbl_8037B72C;
        buf[decode(buf, lbl_8037750C)] = 0;
        self->drawText(&pos, buf, lbl_8033E738);
    }
    if (self->count9D8) {
        GXSetViewport(ZERO_1, ZERO_2, self->width218, self->height21C, ZERO_3, lbl_8037B6F0);
        GXSetScissor(0, 0, self->width218, self->height21C);
        GXSetProjection(self->ortho360, 1);
        GXSetCurrentMtx(0x3c);
        self->flags2D0 = 0;
        self->mask2D2 = 0xffff;
        self->flags2D0 |= 0xa;
        fn_8027353C(self);
        GXLoadTlut((char*)self->font9DC + 0x1c2c, 0);
        GXLoadTexObj((char*)self->font9DC + 0x1c0c, 0);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xb, 1);
        GXSetVtxDesc(0xd, 1);
        GXSetNumTexGens(1);
        GXSetTexCoordGen2(0, 1, 0xc, 0x3c, 0, 0x7d);
        GXSetNumChans(1);
        GXSetChanCtrl(4, 0, 0, 1, 0, 2, 2);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0, 0, 4);
        GXSetTevColorIn(0, 0xf, 0xa, 8, 0xf);
        GXSetTevAlphaIn(0, 7, 7, 7, 4);
        GXSetTevColorOp(0, 0, 0, 1, 1, 0);
        GXSetTevAlphaOp(0, 0, 0, 1, 1, 0);
        GXSetZMode(0, 7, 0);
        for (u32 i = 0; i < self->count9D8; i++) {
            if (self->lists3D8[i].data && self->lists3D8[i].capacity) {
                GXCallDisplayList(self->lists3D8[i].data, self->lists3D8[i].size);
            }
        }
    }
    GXFlush();
    fn_801E1378(self);
    GXSetCopyClear(clear, 0xffffff);
    GXSetZMode(1, 7, 1);
    if (!self->black9E0) {
        GXSetColorUpdate(0);
    }
    GXCopyDisp(self->xfb28C, 1);
    GXDrawDone();
    if (self->black9E0) {
        self->black9E0 = 0;
    }
    VISetNextFrameBuffer(self->xfb28C);
    VIFlush();
    for (u32 i = 0; i < self->count9E8; i++) {
        freeDisplayList(&self->dyn9E4[i]);
    }
    self->count9E8 = 0;
    self->value9FC = 0;
    if (!lbl_803780B0) {
        lbl_803780AC = -1;
        lbl_803780B0 = 1;
    }
    lbl_803780E0;
    VIWaitForRetrace();
    lbl_803780AC = lbl_803780E0 + 1;
    if (self->frame290 == 2) {
        self->black9E0 = 1;
        VISetBlack(0);
        VIFlush();
    }
    self->frame290++;
    if (self->frame290 & 1) {
        self->xfb28C = self->buffer288;
    } else {
        self->xfb28C = self->buffer284;
    }
    fn_802816D0(lbl_801E9D24.sound184);
    self->active230 = 0;
}

inline int cachedColorPairEqual(float x,float y){int result=0;if((float)__fabs(x)<lbl_8037B6E8){if((float)__fabs(y)<lbl_8037B6E8)result=1;}return result;}
inline signed char cachedColorEqual(float x,float y,float z){signed char result=0;if(cachedColorPairEqual(x,y)&&(float)__fabs(z)<lbl_8037B6E8)result=1;return result;}
// setCachedColor(self, &white) with white = (1, 1, 1): with literals the compiler reloads
// 1.0f after the comparison and folds 255.0f * 1.0f; the named constants need both spelled out.
inline void setCachedWhite(Renderer* self) {
    float v = VOLATILE_F(lbl_8037B6F0);
    self->color3A0.x = v; self->color3A0.y = v; self->color3A0.z = v;
    GXColor c; c.a = 255; c.r = lbl_8037B6EC; c.g = lbl_8037B6EC; c.b = lbl_8037B6EC;
    GXSetTevColor(2, c);
}
extern "C" void fn_80274D0C(Renderer* self) {
    if (self->active230) {
        self->endFrame();
    }
    if (self->mode294.field_rendering) {
        u32 field = VIGetNextField();
        GXSetViewportJitter(ZERO_1, ZERO_2, self->mode294.fbWidth, self->mode294.efbHeight, ZERO_3, lbl_8037B6F0, field);
    } else {
        GXSetViewport(ZERO_1, ZERO_2, self->mode294.fbWidth, self->mode294.efbHeight, ZERO_3, lbl_8037B6F0);
    }
    GXSetScissor(0, 0, (u32)(float)self->mode294.fbWidth, (u32)(float)self->mode294.efbHeight);
    self->value2D4 = 0;
    self->count9D8 = 0;
    self->flags2D0 = 0;
    self->mask2D2 = 0xffff;
    fn_8027353C(self);
    self->color3A0 = game_vec3_zero;
    float x = self->color3A0.x - lbl_8037B6F0;
    float z = self->color3A0.z;
    z -= lbl_8037B6F0;
    float y = self->color3A0.y - lbl_8037B6F0;
    if (!cachedColorEqual(x, y, z)) {
        setCachedWhite(self);
    }
    GXSetColorUpdate(1);
    self->active230 = 1;
}

#define WGPIPE_U8 (*(volatile u8*)0xCC008000)

inline void Index4(u8 i) {
    WGPIPE_U8 = i;
    WGPIPE_U8 = i;
    WGPIPE_U8 = i;
    WGPIPE_U8 = i;
}

inline void freeLists(Renderer* self) {
    for (int i = 0; i < 3; i++) {
        if (self->lists3B4[i].data) {
            fn_8028F8F0(lbl_8028F698, self->lists3B4[i].data, self->lists3B4[i].capacity);
        }
        self->lists3B4[i].data = 0;
        self->lists3B4[i].capacity = 0;
        self->lists3B4[i].size = 0;
    }
}

inline void buildGrids(Renderer* self) {
    short n;
    short j;
    short idx;
    int m;
    short k;
    DisplayList* dl;
    for (n = 0, k = 1; n < 3; n++, k++) {
        dl = &self->lists3B4[n];
        dl->capacity = (k * ((k + 1) * 8 + 3) + 0x3F) & ~0x1F;
        dl->data = fn_8028FACC(lbl_8028F698, dl->capacity);
        DCInvalidateRange(dl->data, dl->capacity);
        GXBeginDisplayList(dl->data, dl->capacity);
        GXResetWriteGatherPipe();
        for (j = 0; j < k; j++) {
            idx = j * (k + 1);
            GXBegin(0x98, 0, (k + 1) * 2);
            for (m = 0; (short)m < k + 1; m++) {
                Index4(idx);
                idx += k + 1;
                Index4(idx);
                idx -= k;
            }
        }
        dl->size = GXEndDisplayList();
        DCStoreRange(dl->data, dl->capacity);
    }
}

extern "C" void fn_80274F68(Renderer* self) {
    freeLists(self);
    GXFlush();
    buildGrids(self);
}

extern "C" void fn_802750F8(Renderer* self) {
    freeLists(self);
    if (self->font9DC) {
        fn_8027BAD4(self->font9DC, 1);
    }
    self->font9DC = 0;
    GXAbortFrame();
    VIFlush();
    VIWaitForRetrace();
    if (self->buffer284) {
        fn_801EF610(lbl_801EF5C8, self->buffer284);
    }
    self->buffer284 = 0;
    if (self->buffer288) {
        fn_801EF610(lbl_801EF5C8, self->buffer288);
    }
    self->buffer288 = 0;
    if (self->buffer280) {
        fn_801EF610(lbl_801EF5C8, self->buffer280);
    }
    self->buffer280 = 0;
    if (self->dyn9E4) {
        fn_801EF610(lbl_801EF5C8, self->dyn9E4);
        self->dyn9E4 = 0;
        self->count9E8 = 0;
    }
    if (self->records3AC) {
        fn_801EF610(lbl_801EF5C8, self->records3AC);
        self->records3AC = 0;
        self->count3B0 = 0;
    }
    if (self->buffer9F0) {
        fn_801EF610(lbl_801EF5C8, self->buffer9F0);
        self->buffer9F0 = 0;
    }
    if (self->buffer9F4) {
        fn_801EF610(lbl_801EF5C8, self->buffer9F4);
        self->buffer9F4 = 0;
    }
}
}

namespace RenderState_80275280 {
extern "C" {
void GXSetCullMode(int);
void GXSetClipMode(int);
void GXSetZMode(unsigned char, int, unsigned char);
void GXSetTexCoordGen2(int, int, int, unsigned int, unsigned char, unsigned int);
void GXSetColorUpdate(unsigned char);
void GXSetVtxAttrFmt(int, int, int, int, unsigned char);
}
struct RenderInitView { char unknown00[0x2D0]; unsigned short flags, mask; };

extern "C" void fn_80275280(RenderInitView* self) {
    GXSetCullMode(0);
    GXSetClipMode(0);
    GXSetZMode(1, 3, 1);
    GXSetTexCoordGen2(0, 0, 12, 30, 0, 125);
    GXSetColorUpdate(1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 10, 0, 4, 0);
    GXSetVtxAttrFmt(0, 11, 1, 5, 0);
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);
    GXSetVtxAttrFmt(1, 9, 1, 4, 0);
    GXSetVtxAttrFmt(1, 11, 1, 5, 0);
    GXSetVtxAttrFmt(1, 13, 1, 4, 0);
    GXSetVtxAttrFmt(2, 9, 1, 4, 0);
    GXSetVtxAttrFmt(2, 11, 1, 5, 0);
    GXSetVtxAttrFmt(3, 9, 1, 4, 0);
    GXSetVtxAttrFmt(3, 13, 1, 4, 0);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    self->flags = 0;
    self->mask = 65535;
}
}

namespace Renderer_80274448 {
struct GXFifoObj;
struct GXRenderModeObj;
extern "C" {
char fn_801E1818(Renderer*, int, int);
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
GXFifoObj* GXInit(void*, u32);
void VIInit();
void PADInit();
void VIConfigure(RenderMode*);
extern RenderMode GXNtsc480IntDf;
void GXAdjustForOverscan(RenderMode*, RenderMode*, u16, u16);
void GXSetDispCopySrc(u16, u16, u16, u16);
u32 GXSetDispCopyYScale(float);
void GXSetDispCopyDst(u16, u16);
void GXSetCopyFilter(u8, u8 (*)[2], u8, u8*);
void GXSetPixelFmt(int, int);
void GXSetDither(u8);
void GXSetFieldMode(u8, u8);
PairedBufferView* fn_8027BB64(void*, Renderer*);
extern int lbl_803778B8;
extern const int lbl_80379830;
extern float lbl_803780A0;
extern float lbl_803780A4;
extern const float lbl_8037B704, lbl_8037B738;
extern const char lbl_802AEFD0[];
}

#define POOL_ANONYMOUS_ALLOC (pool + 0xF8)  /* "Anonymous Alloc" */
#define POOL_FILE (pool + 0x108)            /* "GCRenderer_Z.cpp" */
#define POOL_ANONYMOUS_NEW (pool + 0x11C)   /* "Anonymous New" */
#define ALLOC(size, line, align) fn_801EFA1C(lbl_801EF5C8, size, POOL_ANONYMOUS_ALLOC, POOL_FILE, line, align)
inline PairedBufferView* newFont2(Renderer* r, int line, const char* pool) {
    void* mem = fn_801EFA1C(lbl_801EF5C8, 0x1c40, POOL_ANONYMOUS_NEW, POOL_FILE, line, 4);
    PairedBufferView* f = (PairedBufferView*)mem;
    if (mem) f = fn_8027BB64(mem, r);
    return f;
}

extern "C" int fn_80275420(Renderer* self, int width, int height) {
    const char* pool = lbl_802AEFD0;
    if (!fn_801E1818(self, width, height)) {
        return 0;
    }
    self->buffer280 = ALLOC(0x40000, 0x79, 0x20);
    self->fifo27C = GXInit(self->buffer280, 0x40000);
    VIInit();
    PADInit();
    lbl_803778B8 = lbl_80379830;
    lbl_803780A0 = lbl_8037B704;
    lbl_803780A4 = lbl_8037B738;
    GXAdjustForOverscan(&GXNtsc480IntDf, &self->mode294, (640 - self->width218) / 2, (480 - self->height21C) / 2);
    self->mode294.viWidth = 640;
    self->mode294.viXOrigin = 40;
    VIConfigure(&self->mode294);
    GXSetScissor(0, 0, self->width218, self->height21C);
    GXSetDispCopySrc(0, 0, self->width218, self->height21C);
    u32 lines = GXSetDispCopyYScale((float)self->mode294.viHeight / (float)self->mode294.efbHeight);
    GXSetDispCopyDst(self->width218, lines);
    GXSetCopyFilter(0, self->mode294.sample_pattern, 1, self->mode294.vfilter);
    GXSetPixelFmt(0, 0);
    GXSetDither(1);
    GXSetFieldMode(self->mode294.field_rendering, self->mode294.xfbHeight < self->mode294.viHeight);
    self->buffer284 = ALLOC((u16)((u16)self->width218 + 15 & 0xfff0) * lines * 2, 0xd3, 0x20);
    self->buffer288 = ALLOC((u16)((u16)self->width218 + 15 & 0xfff0) * lines * 2, 0xd4, 0x20);
    self->initFormats();
    self->xfb28C = self->buffer284;
    self->frame290 = 0;
    VISetNextFrameBuffer(self->xfb28C);
    VIFlush();
    VIWaitForRetrace();
    self->xfb28C = self->buffer288;
    self->frame290 = 1;
    self->black9E0 = 1;
    self->font9DC = newFont2(self, 0xe4, pool);
    GXFlush();
    buildGrids(self);
    self->dyn9E4 = (DisplayList*)ALLOC(0x1800, 0xec, 0x20);
    for (int i = 0; i < 512; i++) {
        new (&self->dyn9E4[i]) DisplayListObj;
    }
    self->count9E8 = 0;
    self->active230 = 0;
    self->records3AC = ALLOC(0x15000, 0xf5, 0x20);
    self->count3B0 = 0;
    self->buffer9F0 = ALLOC(0x80, 0xf9, 0x20);
    self->buffer9F4 = ALLOC(0x80, 0xfa, 0x20);
    self->value9FC = 0;
    self->value9F8 = 0;
    return 1;
}
}

// .data 0x802ED624: the renderer's virtual table, emitted after the cheat tables above.
// It stays a plain address table until the class and its remaining members are recovered.
namespace VirtualTable_802ED624 {
extern "C" {
void fn_801E0EC4();
void fn_801E0ECC();
void fn_801E0ED0();
void fn_801E0ED4();
void fn_801E0ED8();
void fn_801E0EDC();
void fn_801E0EE0();
void fn_801E0EE4();
void fn_801E0EF0();
void fn_801E0F08();
void fn_801E0F0C();
void fn_801E0F14();
void fn_801E0F34();
void fn_80271B98();
void fn_8027224C();
void fn_802726E0();
void fn_80272704();
void fn_80272820();
void fn_80272828();
void fn_80272854();
void fn_80272DE8();
void fn_80273124();
void fn_80273448();
void fn_80274448();
void fn_80274D0C();
void fn_80274F68();
void fn_802750F8();
void fn_80275280();
void fn_80275420();
void fn_80275990();
void fn_80275AF4();
void fn_80275B28();
void fn_80275B3C();
void fn_8027D850();
void fn_8027DA00();
void fn_8027DBA8();
void fn_8027DC70();
void fn_8027E1A0();
void fn_8027E648();
void fn_8027E64C();
void fn_8027E650();
void fn_8027E810();
void fn_8027E814();
void fn_8027EC80();
void fn_8027F178();
void fn_8027F460();
void fn_8027F710();
extern __declspec(section ".data") const void* const lbl_802ED624[49] __attribute__((aligned(4))) = {
    0,
    0,
    (const void*)fn_80275990,
    (const void*)fn_80275420,
    (const void*)fn_802750F8,
    (const void*)fn_80274F68,
    (const void*)fn_80274D0C,
    (const void*)fn_80274448,
    (const void*)fn_801E0EC4,
    (const void*)fn_80272704,
    (const void*)fn_801E0ECC,
    (const void*)fn_801E0ED0,
    (const void*)fn_801E0ED4,
    (const void*)fn_801E0ED8,
    (const void*)fn_801E0EDC,
    (const void*)fn_801E0EE0,
    (const void*)fn_801E0EE4,
    (const void*)fn_80272820,
    (const void*)fn_801E0EF0,
    (const void*)fn_802726E0,
    (const void*)fn_8027224C,
    (const void*)fn_8027E810,
    (const void*)fn_8027E650,
    (const void*)fn_801E0F08,
    (const void*)fn_801E0F0C,
    (const void*)fn_8027E648,
    (const void*)fn_801E0F14,
    (const void*)fn_8027E1A0,
    (const void*)fn_80271B98,
    (const void*)fn_8027DC70,
    (const void*)fn_8027E64C,
    (const void*)fn_8027EC80,
    (const void*)fn_8027F178,
    (const void*)fn_8027F710,
    (const void*)fn_8027F460,
    (const void*)fn_8027E814,
    (const void*)fn_8027DBA8,
    (const void*)fn_8027DA00,
    (const void*)fn_8027D850,
    (const void*)fn_801E0F34,
    (const void*)fn_80272DE8,
    (const void*)fn_80272854,
    (const void*)fn_80272828,
    (const void*)fn_80273124,
    (const void*)fn_80273448,
    (const void*)fn_80275B3C,
    (const void*)fn_80275AF4,
    (const void*)fn_80275B28,
    (const void*)fn_80275280,
};
}
}
