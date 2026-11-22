#include "gx_abi.h"
// GXLightObj private data
struct __GXLightObjInt_struct {
    u32 reserved[3];
    GXColor Color;
    f32 a[3];
    f32 k[3];
    f32 lpos[3];
    f32 ldir[3];
};

void GXInitLightAttn(GXLightObj* lt_obj, f32 a0, f32 a1, f32 a2, f32 k0,
                     f32 k1, f32 k2)
{
    struct __GXLightObjInt_struct* obj;

    ASSERTMSGLINE(0x62, lt_obj != NULL, "Light Object Pointer is null");
    obj = (struct __GXLightObjInt_struct*) lt_obj;
    CHECK_GXBEGIN(0x63, "GXInitLightAttn");
    obj->a[0] = a0;
    obj->a[1] = a1;
    obj->a[2] = a2;
    obj->k[0] = k0;
    obj->k[1] = k1;
    obj->k[2] = k2;
}

void GXInitLightPos(GXLightObj* lt_obj, f32 x, f32 y, f32 z)
{
    struct __GXLightObjInt_struct* obj;

    ASSERTMSGLINE(0x129, lt_obj != NULL, "Light Object Pointer is null");
    obj = (struct __GXLightObjInt_struct*) lt_obj;
    CHECK_GXBEGIN(0x12B, "GXInitLightPos");

    obj->lpos[0] = x;
    obj->lpos[1] = y;
    obj->lpos[2] = z;
}

void GXInitLightDir(GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz)
{
    struct __GXLightObjInt_struct* obj;

    ASSERTMSGLINE(0x149, lt_obj != NULL, "Light Object Pointer is null");
    obj = (struct __GXLightObjInt_struct*) lt_obj;

    obj->ldir[0] = -nx;
    obj->ldir[1] = -ny;
    obj->ldir[2] = -nz;
}

void GXInitLightColor(GXLightObj* lt_obj, GXColor color)
{
    struct __GXLightObjInt_struct* obj;

    ASSERTMSGLINE(0x1A8, lt_obj != NULL, "Light Object Pointer is null");
    obj = (struct __GXLightObjInt_struct*) lt_obj;
    CHECK_GXBEGIN(0x1A9, "GXInitLightColor");

    obj->Color = color;
}

