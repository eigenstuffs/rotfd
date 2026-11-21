#include "Game/render_pipeline_flags_8027353c.h"

namespace RenderPipeline_8027353C {
typedef unsigned char Byte;
typedef unsigned short Half;
struct Color { Byte r,g,b,a; };
struct Material { Byte unknown[0x18]; float alpha; };
struct Owner { Byte unknown0[0x2d0]; Half requested, cached; Material* material; Byte unknown2D8[0x9ec-0x2d8]; float factor; };
}
using namespace RenderPipeline_8027353C;

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
