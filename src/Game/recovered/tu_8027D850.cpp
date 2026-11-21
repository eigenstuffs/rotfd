/* Merged translation unit for .text 0x8027D850-0x8027F178 (fn_8027D850 .. fn_8027EC80).
   .sdata2 0x8037B7B0-0x8037B7D0: pooled literals in first-use order; lbl_8037B7C8 (255.0f)
   stays a named global because fn_8027F178.. reference it. */

extern "C" { extern const float lbl_8037B7C8; }

namespace part_8027D850 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Handle {
    signed int tag : 8, index : 24;
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct Global {
    char unknown00[0x118];
    Manager* manager;
};

struct Camera {
    char unknown00[0xB8];
    float farB8;
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
struct Vec2f {
    float x, y;
};
struct Vec3f {
    float x, y, z;
};
struct TextColorInput {
    float r, g, b;
};
struct TextColorFont {
    u8 r, g, b;
};

struct OwnerBase {
    ViewSlot slots[7];
    char unknown214;
    signed char current215;
    char unknown216[0x52];
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
    virtual void drawText(Vec2f* pos, const char* text, const void* color);
    char unknown27C[0x9DC - 0x27C];
    TextColorFont* font;
};

extern "C" {
extern Global lbl_801E9D24;
extern char lbl_8033E738[];
unsigned int strlen(const char*);
void fn_8027B790(TextColorFont*, float, float, const char*);
}

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

inline void project1(Owner* self, Vec2f& out, float x, float y, float inv) {
    out.x = inv * (x * self->scale268) + (float)self->x270;
    out.y = inv * (y * self->scale26C) + (float)self->y274;
}
inline void project2(Owner* self, Vec2f& out, float x, float y, float z) {
    float inv = 1.0f / z;
    out.x = inv * (x * self->scale268) + (float)self->x270;
    out.y = inv * (y * self->scale26C) + (float)self->y274;
}
inline void project3(Owner* self, Vec2f& out, const Vec3f& p) {
    float inv = 1.0f / p.z;
    float x = p.x * self->scale268;
    float y = p.y;
    out.x = inv * x + (float)self->x270;
    out.y = inv * (y * self->scale26C) + (float)self->y274;
}
inline void project4(Owner* self, Vec2f& out, float x, float y) {
    out.x = x * self->scale268 + (float)self->x270;
    out.y = y * self->scale26C + (float)self->y274;
}
#define BODY \
    Vec2f out; \
    float z = pos.z; \
    if (z < 0.0f) return; \
    Viewport* vp = resolveViewport(self->slots[self->current215].viewport14); \
    Camera* cam = resolveCamera(vp->camera1C); \
    if (z > cam->farB8) return; \
    float inv = 1.0f / z; \
    out.x = inv * (pos.x * self->scale268) + (float)self->x270; \
    out.y = inv * (pos.y * self->scale26C) + (float)self->y274; \
    if (center) out.x -= (float)((strlen(text) * 8) / 2); \
    self->drawText(&out, text, COLOR_ARG);
#define COLOR_ARG color
extern "C" void fn_8027D850(Owner* self, Vec3f pos, const char* text, const void* color, signed char center) {
BODY
}
#undef COLOR_ARG
#define COLOR_ARG lbl_8033E738
extern "C" void fn_8027DA00(Owner* self, Vec3f pos, const char* text, signed char center) {
BODY
}
}

namespace sdata2_def { extern "C" { extern const float lbl_8037B7C8 = 255.0f; } }

namespace part_8027D850 {
extern "C" void fn_8027DBA8(Owner* self, const Vec2f* position, const char* text, const TextColorInput* color) {
    TextColorFont* font = self->font;
    unsigned char red = lbl_8037B7C8 * color->r;
    unsigned char blue = lbl_8037B7C8 * color->b;
    unsigned char green = lbl_8037B7C8 * color->g;
    font->r = red;
    font->g = green;
    font->b = blue;
    fn_8027B790(self->font, (int)position->x, (int)position->y, text);
}
}


// Partial renderer views; unobserved fields retain their original offsets.
namespace TextDisplayDispatch {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3 {
    float x, y, z;
    inline Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    inline Vec3 operator+(const Vec3& v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
};
struct Color { float r, g, b, a; };
struct ByteColor { u8 r, g, b, a; };
struct Mesh {
    void* positions;
    void* normals;
    void* colors;
    void* texcoords;
};
struct Buffer {
    void* data;
    u32 capacity, size;
};
struct Material {
    char pad[0xC];
    Color color;
};
struct Light {
    char pad[0x84];
    Vec3 ambient;
    char pad90[12];
    Vec3 diffuse;
};
struct Record {
    u16 flags, next;
    Buffer* display;
    Mesh* mesh;
    Material* material;
    float matrix[12];
    float texmatrix[16];
    Light* light;
    u32 mode;
    Color color;
    void* positions;
    void* normals;
    void* colors;
    void* texcoords;
};
struct Owner {
    char pad[0x2D0];
    u16 flags2D0, flags2D2;
    char pad2D4[0xD8];
    char* records;
    u32 pending;

    inline Record* at(u16 i) { return (Record*)(records + i * 0xA8); }
    inline Mesh* mesh(u16 i) { return *(Mesh**)(records + i * 0xA8 + 8); }
    inline Material* material(u16 i)
    {
        return *(Material**)(records + i * 0xA8 + 0xC);
    }
    inline Light* light(u16 i)
    {
        return *(Light**)(records + i * 0xA8 + 0x80);
    }
    inline void* array(u16 i, int offset)
    {
        return *(void**)(records + i * 0xA8 + offset);
    }
    inline float* transform(u16 i)
    {
        return (float*)(records + i * 0xA8 + 0x10);
    }
    inline Color* color(u16 i)
    {
        return (Color*)(records + i * 0xA8 + 0x88);
    }
};
}

extern "C" void fn_8027DC70(TextDisplayDispatch::Owner* self);



using namespace TextDisplayDispatch;

extern "C" {

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
                ambient.r = fn_800A8E8C(red, 0.0f, lbl_8037B7C8);
                ambient.g = fn_800A8E8C(green, 0.0f, lbl_8037B7C8);
                ambient.b = fn_800A8E8C(blue, 0.0f, lbl_8037B7C8);
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


struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct {
            signed int tag : 8;
            signed int index : 24;
        } bits;
    };
    Handle_801F7F10() {
        bits.index = 0;
        bits.tag = 0;
    }
    ~Handle_801F7F10();
};

namespace part_8027E1A0 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
struct Bitmap {
    char unknown00[0xC];
    u8* data0C;
    char unknown10[0x20];
    int width30;
    int height34;
    char unknown38[4];
    u8 format3C;
};

struct Entry {
    Bitmap* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct Global {
    char unknown00[0x110];
    void* logger;
    char unknown114[4];
    Manager* manager;
};

struct RendererBase {
    char unknown000[0x218];
    int width218;
    int height21C;
    char unknown220[0x10];
    signed char inFrame230;
    char unknown231[0x47];
};
struct Renderer : RendererBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void beginFrame();
    virtual void endFrame();
};

extern "C" {
extern Global lbl_801E9D24;
extern const char lbl_802AF388[];
extern const char lbl_802AF3B4[];
void fn_801FA014(void*, const char*, ...);
void* fn_801F7EB8(const void*);
void GXDrawDone();
void DCStoreRange(void*, u32);
}

inline Bitmap* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

// The 'ori' has a dead virtual destination: MWCC deletes it before register
// allocation, but while it exists the alias pass (propagate_alias_to_use) sees
// the address of *out used by a non-load/store instruction and adds the object
// to the worst-case alias set. That is what makes the EFB store depend on the
// stw below in the scheduler, as in the original.
inline void rdC(register u32* out, register const void* p) {
    register u32 t;
    asm { ori t, out, 0
 li r14, 0
 lwbrx r0, p, r14
 stw r0, 0(out) } }
inline bool same2(Bitmap* a, Bitmap* b) { return b == a; }
inline void rdLoad(register const void* p) { asm { li r14, 0
 lwbrx r0, p, r14 } }
inline void rdStore(register u32* out) { asm { stw r0, 0(out) } }
#define EFB ((u32*)0xC8000000)

extern "C" void fn_8027E1A0(Renderer* self, Handle_801F7F10* handle) {
    int y;
    Bitmap* bmp;
    int x;
    int w;
    u8 format;
    int h;
    u32* efb;
    u8* src;
    u32 c;
    signed char began;
    if (same2(resolve(Handle_801F7F10()), resolve(*handle))) {
        GXDrawDone();
        fn_801FA014(lbl_801E9D24.logger, lbl_802AF388);
        if (!self->inFrame230) {
            self->beginFrame();
            began = 1;
        } else {
            began = 0;
        }
        fn_801FA014(lbl_801E9D24.logger, lbl_802AF3B4);
        w = self->width218;
        h = self->height21C;
        efb = EFB;
        for (y = 0; y < h; y++) {
            for (x = w; x > 0; x--) {
                *efb++ = 0xFF000000;
            }
            efb = (u32*)((u8*)efb + (0x1000 - w * 4));
        }
        GXDrawDone();
        if (began) {
            self->endFrame();
        }
    } else if (fn_801F7EB8(handle)) {
        if (!self->inFrame230) {
            self->beginFrame();
            began = 1;
        } else {
            began = 0;
        }
        GXDrawDone();
        bmp = resolve(*handle);
        w = bmp->width30;
        h = bmp->height34;
        if (w > self->width218) {
            w = self->width218;
        }
        if (h > self->height21C) {
            h = self->height21C;
        }
        format = bmp->format3C;
        DCStoreRange(bmp->data0C, h * (w * sizeof(u32)));
        src = bmp->data0C;
        efb = EFB;
        switch (format) {
        case 13:
            for (c = 0, y = 0; y < h; y++) {
                for (x = w; x > 0; x--) {
                    rdC(&c, src);
                    src += 3;
                    *efb++ = c | 0xFF000000;
                }
                efb = (u32*)((u8*)efb + (0x1000 - w * 4));
            }
            break;
        case 8:
            for (y = 0; y < h; y++) {
                for (x = w; x > 0; x--) {
                    u16 p = *(u16*)src;
                    src += 2;
                    *efb++ = ((p & 0x1F) << 3) | (0xFF000000 | ((p & 0xF800) << 5) | ((p & 0x7E0) << 3));
                }
                efb = (u32*)((u8*)efb + (0x1000 - w * 4));
            }
            break;
        }
        GXDrawDone();
        if (began) {
            self->endFrame();
        }
    }
}
}

extern "C" void fn_8027E648(void) { }
extern "C" void fn_8027E64C(void) { }

namespace part_8027E650 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2f {
    float x, y;
};

struct Color4f {
    float r, g, b, a;
};

struct Color4b {
    u8 r, g, b, a;
};

struct Material;

struct Owner8027E650 {
    char unk0[0x270];
    int x270;
    int y274;
    char unk278[0x58];
    u16 flags2D0;
    u16 flags2D2;
    char unk2D4[0x4C];
    float proj320[4][4];
    float proj360[4][4];
};

extern "C" {
void fn_80272968(Owner8027E650* self, Material* material, int channel);
void fn_8027353C(Owner8027E650* self);
void GXSetCurrentMtx(u32);
void GXSetProjection(const float (*)[4], int);
void GXBegin(int, int, u16);
}

volatile union {
    u8 u8v;
    float f32v;
} WGPIPE : 0xCC008000;

inline void Vertex(float x, float y) {
    WGPIPE.f32v = x;
    WGPIPE.f32v = y;
    WGPIPE.f32v = -1.0f;
}

inline void Color(u8 r, u8 g, u8 b, u8 a) {
    WGPIPE.u8v = r;
    WGPIPE.u8v = g;
    WGPIPE.u8v = b;
    WGPIPE.u8v = a;
}

extern "C" void fn_8027E650(Owner8027E650* self, Vec2f* p0, Vec2f* p1, Color4f* color) {
    int r = (int)(lbl_8037B7C8 * color->r);
    int g = (int)(lbl_8037B7C8 * color->g);
    int b = (int)(lbl_8037B7C8 * color->b);
    int a = (int)(lbl_8037B7C8 * color->a);
    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    fn_80272968(self, 0, 4);
    if ((u8)a < 0xFF) {
        self->flags2D0 |= 1;
    }
    fn_8027353C(self);
    GXSetCurrentMtx(0x3C);
    GXSetProjection(self->proj360, 1);
    GXBegin(0xA8, 2, 2);
    Vertex(p0->x + (float)self->x270, p0->y + (float)self->y274);
    WGPIPE.u8v = r;
    WGPIPE.u8v = g;
    WGPIPE.u8v = b;
    WGPIPE.u8v = a;
    Vertex(p1->x + (float)self->x270, p1->y + (float)self->y274);
    WGPIPE.u8v = r;
    WGPIPE.u8v = g;
    WGPIPE.u8v = b;
    WGPIPE.u8v = a;
    GXSetProjection(self->proj320, 0);
}
}

extern "C" void fn_8027E810(void) { }

namespace part_8027E814 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Handle {
    signed int tag : 8, index : 24;
};

struct Vec2f {
    float x, y;
};
struct Vec3f {
    float x, y, z;
};

struct ViewSlot {
    char unknown00[0x4C];
};

struct FadeTarget {
    char unknown00[0x3F];
    u8 mode3F;
};

struct FadeObject {
    char unknown00[0x18];
    float alpha18;
    char unknown1C[0x4C];
    u32 flags68;
    char unknown6C[8];
    Handle target74;
};

struct Owner8027E814 {
    ViewSlot slots[7];
    char unknown214;
    signed char current215;
    char unknown216[0xA];
    Handle fade220;
    char unknown224[0xAC];
    u16 flags2D0;
    u16 flags2D2;
    char unknown2D4[0x4C];
    float proj320[4][4];
    float proj360[4][4];
};

struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct Global {
    char unknown00[0x118];
    Manager* manager;
};

extern "C" {
extern Global lbl_801E9D24;
u32 fn_801F7EB8(const Handle*);
void fn_8027353C(Owner8027E814* self);
void fn_801E2E70(const ViewSlot*, int*, int*, int*, int*);
void GXSetCurrentMtx(u32);
void GXSetProjection(const float (*)[4], int);
void GXBegin(int, int, u16);
void GXClearVtxDesc(void);
void GXSetVtxDesc(int, int);
void GXSetNumChans(u8);
void GXSetNumTexGens(u8);
void GXSetNumTevStages(u8);
void GXSetChanCtrl(int, u8, int, int, u32, int, int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevColorIn(int, int, int, int, int);
void GXSetTevAlphaIn(int, int, int, int, int);
void GXSetTevColorOp(int, int, int, int, u8, int);
void GXSetTevAlphaOp(int, int, int, int, u8, int);
void GXSetZMode(u8, int, u8);
void GXSetZCompLoc(u8);
}

volatile union {
    u8 u8v;
    float f32v;
} WGPIPE : 0xCC008000;

inline void Vertex(float x, float y, float z) {
    WGPIPE.f32v = x;
    WGPIPE.f32v = y;
    WGPIPE.f32v = z;
}
inline void Color(u8 r, u8 g, u8 b, u8 a) {
    WGPIPE.u8v = r;
    WGPIPE.u8v = g;
    WGPIPE.u8v = b;
    WGPIPE.u8v = a;
}
inline void TexCoord(float s, float t) {
    WGPIPE.f32v = s;
    WGPIPE.f32v = t;
}

inline void* resolve(const Handle& h) {
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}

inline signed char isFading(FadeObject* obj) {
    if (fn_801F7EB8(&obj->target74) && ((FadeTarget*)resolve(obj->target74))->mode3F == 2) {
        return 1;
    }
    if (obj->alpha18 < 1.0f) {
        return 1;
    }
    if (obj->flags68 & 8) {
        return 1;
    }
    return 0;
}

inline void setupTev() {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(11, 1);
    GXSetVtxDesc(13, 1);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetChanCtrl(4, 0, 1, 1, 0, 2, 2);
    GXSetTevOrder(0, 0, 0, 4);
}

extern "C" void fn_8027E814(Owner8027E814* self, Vec2f* pos, Vec3f* color, Vec2f* uv, float z) {
    int alpha;
    FadeObject* obj;
    GXSetCurrentMtx(0x3C);
    GXSetProjection(self->proj360, 1);
    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    obj = (FadeObject*)resolve(self->fade220);
    if (obj && isFading(obj)) {
        alpha = (int)(lbl_8037B7C8 * obj->alpha18);
    } else {
        alpha = 0xFF;
    }
    fn_8027353C(self);
    setupTev();
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetZMode(1, 3, 1);
    GXSetZCompLoc(0);
    GXBegin(0x98, 1, 4);
    u8 a = alpha;
    Vertex(pos[0].x, pos[0].y, -z);
    Color((int)(lbl_8037B7C8 * color[0].x), (int)(lbl_8037B7C8 * color[0].y), (int)(lbl_8037B7C8 * color[0].z), a);
    TexCoord(uv[0].x, uv[0].y);
    Vertex(pos[1].x, pos[1].y, -z);
    Color((int)(lbl_8037B7C8 * color[1].x), (int)(lbl_8037B7C8 * color[1].y), (int)(lbl_8037B7C8 * color[1].z), a);
    TexCoord(uv[1].x, uv[1].y);
    Vertex(pos[2].x, pos[2].y, -z);
    Color(lbl_8037B7C8 * color[2].x, lbl_8037B7C8 * color[2].y, lbl_8037B7C8 * color[2].z, a);
    TexCoord(uv[2].x, uv[2].y);
    Vertex(pos[3].x, pos[3].y, -z);
    Color(lbl_8037B7C8 * color[3].x, lbl_8037B7C8 * color[3].y, lbl_8037B7C8 * color[3].z, a);
    TexCoord(uv[3].x, uv[3].y);
    GXSetZCompLoc(1);
    GXSetProjection(self->proj320, 0);
}

extern "C" void fn_8027EC80(Owner8027E814* self, Vec2f* p0, Vec2f* p1, Vec2f* t0, Vec2f* t1,
                            Vec3f* c0, Vec3f* c1, float z) {
    int x, y, w, h;
    FadeObject* obj;
    int alpha;
    GXSetCurrentMtx(0x3C);
    GXSetProjection(self->proj360, 1);
    fn_801E2E70(&self->slots[self->current215], &x, &y, &w, &h);
    int r0 = (int)(lbl_8037B7C8 * c0->x);
    int g0 = (int)(lbl_8037B7C8 * c0->y);
    int b0 = (int)(lbl_8037B7C8 * c0->z);
    int r1 = (int)(lbl_8037B7C8 * c1->x);
    int g1 = (int)(lbl_8037B7C8 * c1->y);
    int b1 = (int)(lbl_8037B7C8 * c1->z);
    self->flags2D0 = 0;
    self->flags2D2 = 0xFFFF;
    obj = (FadeObject*)resolve(self->fade220);
    if (obj && isFading(obj)) {
        alpha = (int)(lbl_8037B7C8 * obj->alpha18);
        self->flags2D0 |= 1;
    } else {
        alpha = 0xFF;
    }
    fn_8027353C(self);
    setupTev();
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 1, 1, 0);
    GXSetZMode(1, 3, 1);
    GXSetZCompLoc(0);
    GXBegin(0x80, 1, 4);
    u8 a = alpha;
    Vertex(p0->x + (float)x, p0->y + (float)y, -z);
    Color(r0, g0, b0, a);
    TexCoord(t0->x, t0->y);
    Vertex(p1->x + (float)x, p0->y + (float)y, -z);
    Color(r0, g0, b0, a);
    TexCoord(t1->x, t0->y);
    Vertex(p1->x + (float)x, p1->y + (float)y, -z);
    Color(r1, g1, b1, a);
    TexCoord(t1->x, t1->y);
    Vertex(p0->x + (float)x, p1->y + (float)y, -z);
    Color(r1, g1, b1, a);
    TexCoord(t0->x, t1->y);
    GXSetProjection(self->proj320, 0);
    GXSetZCompLoc(1);
    self->flags2D0 = 0xFFFF;
    self->flags2D2 = 0xFFFF;
}
}
