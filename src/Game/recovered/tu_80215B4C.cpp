/* Merged translation unit: part_80215B4C, Game/menu2d_item_text.cpp, part_80216228.
 * .sdata2 of the span (100.0f, unsigned and signed int->float bias) is compiler-pooled. */
/* ---- shared declarations (global: Handle_801F7F10 keeps its mangled names) ---- */
#include "menu_item_text_internal.h"

/* ---- part_80215B4C ---- */
namespace menu_layout_80215B4C {
// Menu item record as seen by the 2D/3D menu layout functions (size 0xBC).
struct MenuLayoutName {
    unsigned long value;
};
struct MenuLayoutPosition {
    float x, y;
};
struct MenuLayoutItem {
    char name[128];
    MenuLayoutName keyword, next, previous;
    unsigned short flags;       /* 0x8C */
    MenuLayoutName parameters[8];
    unsigned char center0;      /* 0xB0 */
    unsigned char center1;      /* 0xB1 */
    unsigned char parameterCount;
    unsigned char lineUp;       /* 0xB3 */
    MenuLayoutPosition position; /* 0xB4 */

    bool isHidden() const { return flags & 2; }
    bool isGrouped() const { return (flags & 0x38) == 0x38; }
    unsigned char low() const { return flags; }
};
struct MenuLayoutItemArray {
    MenuLayoutItem* data;
    MenuLayoutItem& operator[](int i) { return data[i]; }
};


struct FontInfo_80215B4C {
    int height;
};
struct FontEntry_80215B4C {
    char unknown00[8];
    FontInfo_80215B4C* info;
};
struct FontTable_80215B4C {
    char unknown00[0x24];
    FontEntry_80215B4C* fonts;
};
struct Globals_80215B4C {
    char unknown00[0x14C];
    FontTable_80215B4C* fontTable;
};
extern "C" Globals_80215B4C lbl_801E9D24;
extern "C" const float lbl_8037AD74;

struct Menu2DLayoutView {
    char unknown00[0x2C];
    short firstItem;        /* 0x2C */
    char unknown2E[0x18];
    unsigned short itemCount; /* 0x46 */
    char unknown48[8];
    unsigned char lineCount; /* 0x50 */
    char unknown51[3];
    float left;             /* 0x54 */
    float top;              /* 0x58 */
    float right;            /* 0x5C */
    float bottom;           /* 0x60 */
    char unknown64[0xC];
    MenuLayoutItemArray items; /* 0x70 */
    char unknown74[8];
    unsigned char font;     /* 0x7C */
    FontEntry_80215B4C* getFont() { return &lbl_801E9D24.fontTable->fonts[font]; }
};

extern "C" void fn_80215B4C(Menu2DLayoutView* self)
{
    FontEntry_80215B4C* font = self->getFont();
    int groups[8][4];
    int counts[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int i;
    int groupCount = 0;
    float x, y;

    for (i = self->firstItem; i < self->firstItem + self->itemCount; i++) {
        if (!self->items[i].isHidden() && self->items[i].isGrouped()) {
            char found = 0;
            for (int g = 0; g < groupCount; g++) {
                for (int k = 0; k < counts[g]; k++) {
                    if (self->items[i].center0 == self->items[groups[g][k]].center0 &&
                        self->items[i].center1 == self->items[groups[g][k]].center1) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    groups[g][counts[g]++] = i;
                }
            }
            if (!found) {
                groups[groupCount][counts[groupCount]++] = i;
                groupCount++;
            }
        }
    }

    for (int g = 0; g < groupCount; g++) {
        MenuLayoutItem* item = &self->items[groups[g][0]];
        int n = counts[g];
        int total = n * font->info->height;
        float h = self->bottom - self->top;
        float w = self->right - self->left;
        y = self->top + h * item->center1 / 100.0f - (float)(total / 2);
        x = self->left + w * item->center0 / 100.0f;
        item->position.x = x;
        item->position.y = y;
        for (int k = 1; k < counts[g]; k++) {
            n = font->info->height;
            y += (float)n;
            total = groups[g][k];
            item = &self->items[total];
            MenuLayoutPosition* p = &item->position;
            p->x = x;
            p->y = y;
        }
    }

    y = self->top + (float)self->lineCount * (float)lbl_801E9D24.fontTable->fonts->info->height;
    for (i = self->firstItem; i < self->firstItem + self->itemCount; i++) {
        if (self->items[i].isHidden()) continue;
        unsigned char low = self->items[i].low();
        if (!self->items[i].isGrouped() && !(low & 0x80)) {
            MenuLayoutItem* item = &self->items[i];
            y -= (float)(item->lineUp - 1) * (float)font->info->height;
            if ((low & 0x18) == 0x18) {
                float sum = self->left + self->right;
                x = sum * lbl_8037AD74;
            } else if (low & 8) {
                x = self->left;
            } else if (low & 0x10) {
                x = self->right;
            }
            item->position.x = x;
            item->position.y = y;
        }
    }
}

}

/* ---- Game/menu2d_item_text.cpp ---- */
extern "C" int fn_80216150(MenuItemTextView*self,int index,char*output) {
    u32 arguments[8];
    MenuItem* item;
    for(int i=0;i<(item=&self->items[index])->parameterCount;i++) {
        arguments[i]=self->resolver.get()->slot70(
            item->keyword,item->parameters[i]);
    }
    return fn_801F44DC(output,item->name,arguments);
}

/* ---- part_80216228 ---- */
namespace menu_bounds_80216228 {
// Shared body of the 2D/3D menu screen-bounds functions (fn_80216228 / fn_8021894C).
typedef unsigned long MBWord;
struct MBVec3 {
    float x, y, z;
    MBVec3() {}
    MBVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct MBMatrix4 { float m[4][4]; };
struct MBManager;
extern "C" void fn_801F86C8(MBManager*, const Handle_801F7F10*, short);
struct MBEntry {
    void* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; }
};
struct MBManager { char unknown00[8]; MBEntry* entries; };
struct MBViewport { char unknown[0x4C]; };
extern "C" struct MBGlobal {
    char unknown00[0x114];
    MBViewport* viewports;
    MBManager* manager;
} lbl_801E9D24;
struct MBHandleBase : Handle_801F7F10 {
    MBHandleBase() { value = 0; }
};
struct MBHandleCopy : MBHandleBase {
    MBHandleCopy(const Handle_801F7F10& v) { value = v.value; fn_801F86C8(lbl_801E9D24.manager, &v, 1); }
};
inline void* mb_resolveRaw(const Handle_801F7F10& h) {
    int index = h.bits.index; MBManager* m = lbl_801E9D24.manager;
    signed char tag = h.bits.generation;
    signed char entryTag = m->entries[index].getTag();
    if (entryTag == tag) return m->entries[index].object;
    return 0;
}
struct MBTexture { char unknown00[0x30]; int halfWidth; int halfHeight; };
struct MBMaterial { char unknown00[0x74]; Handle_801F7F10 texture; };
struct MBFrame { char unknown00[0xB8]; Handle_801F7F10 material; };
struct MBMesh { char unknown00[0x6C]; unsigned short kind; };
struct MBMeshNode {
    char unknown00[0x1C]; Handle_801F7F10 mesh;
    char unknown20[0x104]; MBMatrix4* transform;
};
struct MBQuery {
    char hit;
    MBVec3 from;
    MBVec3 to;
    float fov;
    char rest[0x20];
};
struct MenuBoundsView {
    char unknown00[0x20];
    Handle_801F7F10 owner;      /* 0x20 */
    char unknown24[0x10];
    unsigned char viewport;     /* 0x34 */
    char unknown35[0x17];
    Handle_801F7F10 node;       /* 0x4C */
    char unknown50[4];
    float left, top, right, bottom; /* 0x54 */
    float nearZ;                /* 0x64 */
    char unknown68[0xC];
    Handle_801F7F10 frame;      /* 0x74 */
    void setMin(float x, float y) { left = x; top = y; }
    void setMax(float x, float y) { right = x; bottom = y; }
    void setBounds(float l, float t, float r, float b) { left = l; top = t; right = r; bottom = b; }
};
extern "C" {
extern const MBVec3 game_vec3_zero;
void fn_801E2E70(MBViewport*, int*, int*, int*, int*);
void* fn_801F7EB8(const Handle_801F7F10*);
void fn_801D8980(MBMesh*, MBVec3*);
signed char fn_80269A64(void*, const Handle_801F7F10&, const MBVec3*, MBQuery*);
void fn_801F18D0(const MBVec3*, const MBVec3*, MBMatrix4*);
void fn_801F230C(const MBMatrix4*, MBMatrix4*);
MBMatrix4* fn_801F2788(MBMatrix4*, const MBMatrix4*);
float fn_80284E34(float);
}
inline MBVec3 operator-(const MBVec3& a, const MBVec3& b) { return MBVec3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline MBVec3 operator*(const MBMatrix4& m, const MBVec3& v) {
    MBVec3 r;
    r.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0];
    r.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1];
    r.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2];
    return r;
}
inline float mbFrsqrte(register float x) { register float r; asm { frsqrte r, x } return r; }
inline MBFrame* mb_getFrame(const Handle_801F7F10& h) { return (MBFrame*)mb_resolveRaw(h); }
inline MBMaterial* mb_getMaterial(const Handle_801F7F10& h) { return (MBMaterial*)mb_resolveRaw(h); }
inline MBTexture* mb_getTexture(const Handle_801F7F10& h) { return (MBTexture*)mb_resolveRaw(h); }
inline MBMeshNode* mb_getNode(const Handle_801F7F10& h) { return (MBMeshNode*)mb_resolveRaw(h); }
inline MBMesh* mb_getMesh(const Handle_801F7F10& h) { return (MBMesh*)mb_resolveRaw(h); }

#define MENU_BOUNDS_BODY(FN, ZERO, ONE, HALF, TWO, BIG, MINV, MAXV, EPS) \
extern "C" void FN(MenuBoundsView* self) \
{ \
    int x, y, width, height; \
    fn_801E2E70(&lbl_801E9D24.viewports[self->viewport], &x, &y, &width, &height); \
    self->setMin((float)(x + 16), (float)(y + 16)); \
    self->setMax((float)(width - 16), (float)(height - 16)); \
    if (fn_801F7EB8(&self->frame)) { \
        MBHandleCopy texture(mb_getMaterial(mb_getFrame(self->frame)->material)->texture); \
        MBTexture* t = mb_getTexture(texture); \
        int tw = t->halfWidth; \
        int th = t->halfHeight; \
        int cx = width >> 1; \
        int cy = height >> 1; \
        self->left = (float)(cx - tw); \
        self->top = (float)(cy - th); \
        self->right = (float)(cx + tw); \
        self->bottom = (float)(cy + th); \
    } \
    if (fn_801F7EB8(&self->node) && fn_801F7EB8(&mb_getNode(self->node)->mesh) && \
        mb_getMesh(mb_getNode(self->node)->mesh)->kind == 1) { \
        MBVec3 corners[4]; \
        MBQuery query; \
        MBMatrix4 view; \
        MBMatrix4 inverse; \
        MBVec3 out[4]; \
        fn_801D8980(mb_getMesh(mb_getNode(self->node)->mesh), corners); \
        query.hit = 0; \
        fn_80269A64(mb_resolveRaw(self->owner), self->node, &game_vec3_zero, &query); \
        MBVec3 dir = query.from - query.to; \
        MBVec3 up(*(const float*)&ZERO, ONE, ZERO); \
        float s = mbFrsqrte(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z); \
        dir.x *= s; dir.y *= s; dir.z *= s; \
        fn_801F18D0(&dir, &up, &view); \
        view.m[3][0] = query.to.x; view.m[3][1] = query.to.y; view.m[3][2] = query.to.z; \
        fn_801F230C(&view, &inverse); \
        fn_801F2788(&inverse, mb_getNode(self->node)->transform); \
        float scale = (float)height / (TWO * fn_80284E34(query.fov * HALF)); \
        self->nearZ = BIG; \
        self->left = MINV; \
        self->top = MINV; \
        self->right = MAXV; \
        self->bottom = MAXV; \
        for (int i = 0; i < 4; i++) { \
            out[i] = inverse * corners[i]; \
            if (out[i].z < self->nearZ) self->nearZ = out[i].z; \
            float inv = ONE / out[i].z; \
            out[i].x = inv * (scale * out[i].x) + (float)(width / 2); \
            out[i].y = inv * (scale * -out[i].y) + (float)(height / 2); \
            if (out[i].x < self->left) self->left = out[i].x; \
            if (out[i].y < self->top) self->top = out[i].y; \
            if (out[i].x > self->right) self->right = out[i].x; \
            if (out[i].y > self->bottom) self->bottom = out[i].y; \
        } \
        self->nearZ -= EPS; \
    } \
}

extern "C" const float lbl_8037AD6C, lbl_8037AD70, lbl_8037AD74, lbl_8037AD90, lbl_8037AD94, lbl_8037AD98, lbl_8037AD9C, lbl_8037ADA0;
MENU_BOUNDS_BODY(fn_80216228, lbl_8037AD90, lbl_8037AD6C, lbl_8037AD74, lbl_8037AD70, lbl_8037AD94, lbl_8037AD98, lbl_8037AD9C, lbl_8037ADA0)

}
