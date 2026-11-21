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
