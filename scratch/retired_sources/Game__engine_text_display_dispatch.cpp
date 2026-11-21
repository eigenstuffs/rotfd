#include "Game/engine_text_display_dispatch.h"

using namespace TextDisplayDispatch;

extern "C" {
extern const float lbl_8037B7B0, lbl_8037B7C8;
u16 fn_80271BD8(Owner*);
void fn_80272968(Owner*, Material*, int);
void fn_8027FC80(Owner*, Light*, float*, u32);
void fn_80272EA0(Owner*, float*);
void GXInvalidateVtxCache();
void GXSetArray(int, void*, u8);
void GXSetChanAmbColor(int, ByteColor);
void GXSetCurrentMtx(u32);
float fn_800A8E8C(float, float, float);
void fn_80272708(Owner*, const Color*);
void fn_8027353C(Owner*);
void GXCallDisplayList(const void*, u32);
}

static inline void lightSetup(Owner* self, u16 index)
{
    Record* r = self->at(index);
    fn_8027FC80(self, r->light, r->texmatrix, r->mode);
}

static inline void directArrays(Owner* self, u16 index)
{
    GXSetArray(9, self->array(index, 0x98), 12);
    GXSetArray(10, self->array(index, 0x9C), 12);
    GXSetArray(11, self->array(index, 0xA0), 4);
    GXSetArray(13, self->array(index, 0xA4), 8);
}

static inline void fillColor(ByteColor& out, const Color& c)
{
    out.r = lbl_8037B7C8 * c.r;
    out.g = lbl_8037B7C8 * c.g;
    out.b = lbl_8037B7C8 * c.b;
    out.a = lbl_8037B7C8 * c.a;
}

static inline void callDisplay(Buffer* display)
{
    if (display->data && display->capacity)
        GXCallDisplayList(display->data, display->size);
}

extern "C" void fn_8027DC70(Owner* self)
{
    ByteColor ambient;
    u32 previousFlags = -1;
    Material* previousMaterial = 0;
    if (self->pending) {
        u16 index = fn_80271BD8(self);
        for (; index != 0xFFFF; index = self->at(index)->next) {
            Record* record = self->at(index);
            if (previousFlags != record->flags ||
                previousMaterial != record->material) {
                self->flags2D0 = 0;
                self->flags2D2 = 0xFFFF;
            }
            if (self->at(index)->flags & 0x10) {
                fn_80272968(self, self->at(index)->material, 5);
                lightSetup(self, index);
                fn_80272EA0(self, self->transform(index));
                GXInvalidateVtxCache();
                GXSetArray(9, self->mesh(index)->positions, 12);
                GXSetArray(10, self->mesh(index)->normals, 12);
                GXSetArray(11, self->mesh(index)->colors, 4);
                GXSetArray(13, self->mesh(index)->texcoords, 8);
            } else if (self->at(index)->flags & 0x20) {
                fn_80272968(self, self->at(index)->material, 5);
                lightSetup(self, index);
                fn_80272EA0(self, self->transform(index));
                directArrays(self, index);
            } else if (self->at(index)->flags & 0x80) {
                fn_80272968(self, self->at(index)->material, 4);
                fillColor(ambient, self->material(index)->color);
                GXSetChanAmbColor(4, ambient);
                GXSetCurrentMtx(60);
            } else if (self->at(index)->flags & 0x2000) {
                fn_80272968(self, self->at(index)->material, 4);
                fn_80272EA0(self, self->transform(index));
            } else if (self->at(index)->flags & 0x40) {
                fn_80272968(self, self->at(index)->material, 5);
                Light* light = self->light(index);
                const Vec3& sum = light->diffuse + light->ambient;
                float red = sum.x * lbl_8037B7C8;
                float green = sum.y * lbl_8037B7C8;
                float blue = sum.z * lbl_8037B7C8;
                ambient.r = fn_800A8E8C(red, lbl_8037B7B0, lbl_8037B7C8);
                ambient.g = fn_800A8E8C(green, lbl_8037B7B0, lbl_8037B7C8);
                ambient.b = fn_800A8E8C(blue, lbl_8037B7B0, lbl_8037B7C8);
                GXSetChanAmbColor(1, ambient);
                fn_80272EA0(self, self->transform(index));
            } else {
                fn_80272968(self, self->at(index)->material, 5);
                lightSetup(self, index);
                fn_80272EA0(self, self->transform(index));
                GXInvalidateVtxCache();
                directArrays(self, index);
            }
            fn_80272708(self, self->color(index));
            record = self->at(index);
            if (previousFlags != record->flags ||
                previousMaterial != record->material) {
                self->flags2D0 |= record->flags;
                fn_8027353C(self);
            }
            record = self->at(index);
            previousFlags = record->flags;
            previousMaterial = record->material;
            callDisplay(record->display);
        }
        self->pending = 0;
    }
}
