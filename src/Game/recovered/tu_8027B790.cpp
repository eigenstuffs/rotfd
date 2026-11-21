/* Merged translation unit: Game/font_atlas_constants.c, part_8027B790, Game/paired_buffer_destroy.cpp, part_8027BB64. */
/* ---- part_8027B790 ---- */
namespace part_8027B790 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2f {
    float x, y;
    Vec2f() {}
    Vec2f(float x_, float y_) : x(x_), y(y_) {}
};
struct Color4f {
    float r, g, b, a;
    Color4f() {}
    Color4f(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

struct DisplayList {
    void* data;
    u32 capacity;
    u32 size;
};

struct RendererBase {
    char unknown000[0x218];
    int width218;
    int height21C;
    char unknown220[0x58];
};

struct Renderer : RendererBase {
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
    virtual void drawRect(Vec2f* pos, Vec2f* size, Color4f* color, float alpha);
};

struct Glyph {
    float u0, v0, u1, v1;
    float width;
    float height;
    signed char valid;
};

struct Font {
    u8 r, g, b;
    Glyph glyphs[256];
    int unknown1C04;
    Renderer* renderer;

    int countValid(const char* text) {
        int count = 0;
        for (int i = 0; text[i]; i++) {
            if (glyphs[text[i]].valid) {
                count++;
            }
        }
        return count;
    }
    Glyph* getGlyph(char c) { return &glyphs[c]; }
};

extern "C" {
extern char lbl_8028F698[];
DisplayList* fn_80271BB8(Renderer*);
void* fn_8028F8AC(void*, void*, u32, u32);
void* fn_8028FACC(void*, u32);
void DCInvalidateRange(void*, u32);
void DCStoreRange(void*, u32);
void GXBeginDisplayList(void*, u32);
u32 GXEndDisplayList();
void GXResetWriteGatherPipe();
void GXBegin(int, int, u16);
}

#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U8 (*(volatile u8*)0xCC008000)

inline void Position(float x, float y) {
    WGPIPE_F32 = x;
    WGPIPE_F32 = y;
    WGPIPE_F32 = -1.0f;
}
inline void Color(const u8 r, const u8 g, const u8 b, const u8 a) {
    WGPIPE_U8 = r;
    WGPIPE_U8 = g;
    WGPIPE_U8 = b;
    WGPIPE_U8 = a;
}
inline void ColorF(Font* f) { Color(f->r, f->g, f->b, 0xFF); }
#define Color(r,g,b,a) ColorF(self)

extern "C" void fn_8027B790(Font* self, float x, float y, const char* text) {
    int count = self->countValid(text);
    DisplayList* dl = fn_80271BB8(self->renderer);
    if (dl->data) {
        u32 size = (count * 0x60 + 0x42) & ~0x1F;
        dl->data = fn_8028F8AC(lbl_8028F698, dl->data, dl->capacity, size);
        dl->capacity = size;
    } else {
        dl->capacity = (count * 0x60 + 0x42) & ~0x1F;
        dl->data = fn_8028FACC(lbl_8028F698, dl->capacity);
    }
    DCInvalidateRange(dl->data, dl->capacity);
    GXBeginDisplayList(dl->data, dl->capacity);
    GXResetWriteGatherPipe();
    GXBegin(0x80, 1, count * 4);
    for (int i = 0; text[i]; i++) {
        if (self->glyphs[text[i]].valid) {
            Glyph* g = self->getGlyph(text[i]);
            float scale = 1.0f;
            float h = g->height * scale;
            float x1 = g->width * scale + x;
            float y0 = y - h;
            float y1 = y0 + h;
            Position(x, y0);
            Color(self->r, self->g, self->b, 0xFF);
            { float v_ = g->v0; float u_ = g->u0; WGPIPE_F32 = u_; WGPIPE_F32 = v_; }
            Position(x1, y0);
            Color(self->r, self->g, self->b, 0xFF);
            { float v_ = g->v0; float u_ = g->u1; WGPIPE_F32 = u_; WGPIPE_F32 = v_; }
            Position(x1, y1);
            Color(self->r, self->g, self->b, 0xFF);
            { float v_ = g->v1; float u_ = g->u1; WGPIPE_F32 = u_; WGPIPE_F32 = v_; }
            Position(x, y1);
            Color(self->r, self->g, self->b, 0xFF);
            { float v_ = g->v1; float u_ = g->u0; WGPIPE_F32 = u_; WGPIPE_F32 = v_; }
            float adv = g->width * scale;
            x += adv;
        }
    }
    dl->size = GXEndDisplayList();
    DCStoreRange(dl->data, dl->capacity);
}

extern "C" void fn_8027BA1C(Font* self, signed char enable) {
    Renderer* r = self->renderer;
    Vec2f pos;
    Vec2f size;
    Color4f color;
    int iw = r->width218;
    int ih = r->height21C;
    pos.x = 32.0f;
    pos.y = 32.0f;
    size.x = (float)(iw - 0x20);
    size.y = (float)(ih - 0x20);
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.25f;
    color.a = 0.5f;
    if (enable) {
        r->drawRect(&pos, &size, &color, 1.0f);
    }
}

}

/* ---- Game/paired_buffer_destroy.cpp ---- */
#pragma push
#pragma fp_contract off
namespace paired_buffer_destroy {
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

struct PairedBufferView {
    char unknown00[0x1C38];
    void* first;
    void* second;
};

extern "C" PairedBufferView* fn_8027BAD4(PairedBufferView* self, int deleting)
{
    if (self) {
        if (self->first)
            fn_801EF610(lbl_801EF5C8, self->first);
        if (self->second)
            fn_801EF610(lbl_801EF5C8, self->second);
        self->first = 0;
        self->second = 0;
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}

}

#pragma pop
/* ---- part_8027BB64 ---- */
namespace part_8027BB64 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Renderer;
struct Glyph {
    float u0, v0, u1, v1;
    float width;
    float height;
    signed char valid;
};
struct TexObj { u32 w[8]; };
struct TlutObj { u32 w[3]; };
struct Font {
    u8 r, g, b;
    Glyph glyphs[256];
    int unknown1C04;
    Renderer* renderer;
    TexObj tex;
    TlutObj tlut;
    u8* texData;
    u16* tlutData;
};

extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802AF360[];
extern const char lbl_802AF370[];
extern u8 lbl_802EDCD0[];
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
void DCStoreRange(void*, u32);
void GXInitTexObjCI(TexObj*, void*, u16, u16, int, int, int, u8, u32);
void GXInitTexObjLOD(TexObj*, int, int, float, float, float, u8, u8, int);
void GXInitTlutObj(TlutObj*, void*, int, u16);
}

extern "C" Font* fn_8027BB64(Font* self, Renderer* renderer) {
    long i;
    self->renderer = renderer;
    self->texData = (u8*)fn_801EFA1C(lbl_801EF5C8, 0x2000, lbl_802AF360, lbl_802AF370, 0x2F, 0x20);
    self->tlutData = (u16*)fn_801EFA1C(lbl_801EF5C8, 0x20, lbl_802AF360, lbl_802AF370, 0x30, 0x20);
    self->r = 0xFF;
    self->g = 0xFF;
    self->b = 0xFF;
    self->renderer = renderer;
    for (i = 0; i < 16; i++) {
        self->tlutData[i] = 0;
    }
    self->tlutData[i - 1] = 0x7FFF;
    for (i = 0; i < 256; i++) {
        self->glyphs[i].valid = 0;
    }
    int c;
    u8* dst;
    int x;
    int y;
    int col;
    int row;
    dst = self->texData;
    for (c = 0; c < 0xDF; c++) {
        row = (c >> 4) * 8;
        col = (c & 15) * 8;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 4; x++) {
                *dst = 0;
                if (lbl_802EDCD0[c * 64 + y * 8 + x * 2]) *dst |= 0xF0;
                if (lbl_802EDCD0[c * 64 + y * 8 + x * 2 + 1]) *dst |= 0x0F;
                dst++;
            }
        }
        int ch = c + 0x20;
        self->glyphs[ch].u0 = (0.5f + col) / 128.0f;
        self->glyphs[ch].u1 = (col + 8) / 128.0f;
        self->glyphs[ch].v0 = (0.5f + row) / 128.0f;
        self->glyphs[ch].v1 = (row + 8) / 128.0f;
        self->glyphs[ch].valid = 1;
        self->glyphs[ch].width = 8.0f;
        self->glyphs[ch].height = 8.0f;
    }
    DCStoreRange(self->texData, 0x2000);
    GXInitTexObjCI(&self->tex, self->texData, 0x80, 0x80, 8, 0, 0, 1, 0);
    GXInitTexObjLOD(&self->tex, 0, 0, 1.0f, 1.0f, 0.0f, 0, 0, 0);
    GXInitTlutObj(&self->tlut, self->tlutData, 2, 0x10);
    return self;
}

struct Vec3 {
    float x, y, z;
};
struct Vec4 {
    float x, y, z, w;
};
struct Matrix {
    float m[4][4];
};
struct Handle {
    signed int tag : 8, index : 24;
};
struct MatrixPool {
    Matrix* banks[6];
    u8 active18;
};
struct Resource {
    char unknown00[0x120];
    u32 flags120;
    Matrix* local124;
    Matrix* world128;
    char unknown12C[2];
    short index12E;
    Matrix* getWorld();
};
struct Material {
    char unknown00[0x18];
    float alpha18;
};
struct MaterialEntry {
    Material* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct MaterialManager {
    int count, capacity;
    MaterialEntry* entries;
};
struct DisplayList {
    void* data;
    u32 capacity;
    u32 size;
};
struct VertexBuffer {
    Vec3* positions;
    void* normals;
    void* colors;
    void* texcoords;
};
struct CacheNode { char unknown00[8]; u16 prev; u16 next; };
struct CacheBase {
    char unknown00[8];
    CacheNode* nodes;
    int stride;
    VertexBuffer* buffers;
};
struct Cache : CacheBase {
    virtual u16 allocate(Handle*, u16);
    u16& prev(int i) { return nodes[i].prev; }
    u16& next(int i) { return nodes[i].next; }
    /* CacheNode& binding per unlink statement gives the target's r6/r7 order */
    void touch(int n) {
        { CacheNode& c = nodes[n]; next(c.prev) = c.next; }
        { CacheNode& c = nodes[n]; prev(c.next) = c.prev; }
        next(n) = nodes[0].next;
        prev(n) = 0;
        prev(nodes[0].next) = n;
        nodes[0].next = n;
    }
    VertexBuffer* buffer(int slot) { return &buffers[slot * stride]; }
    VertexBuffer* get3(int slot) { int n = slot + 1; touch(n); return &buffers[slot * stride]; }
};
struct Context {
    char unknown00[0x9E4];
    DisplayList* lists9E4;
    int count9E8;
};
struct Record0 {
    char unknown00[0x48];
    Context* context48;
};
struct Global {
    char unknown00[0x118];
    MaterialManager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[0x40];
    Cache* cache178;
    Cache* cache17C;
};
struct DrawRenderer {
    Record0* record0;
    char unknown04[8];
    Resource* resC;
    Resource* res10;
    char unknown14[0xBCC - 0x14];
    int lodBCC;
    char unknownBD0[8];
    int valueBD8;
    int valueBDC;
    Cache* cacheBE0;
    Handle handleBE4;
};
struct State {
    u16 slot;
    u16 lod;
};
struct Model {
    char unknown00[4];
    Handle handle04;
    char unknown08[0x74];
    int value7C;
    char unknown80[0x44];
    int valueC4;
    char unknownC8[0x3C];
    State* states104;
    char unknown108[0xC];
    int maxLod114;
};

extern "C" {
extern Global lbl_801E9D24;
extern char lbl_8028F698[];
void fn_801F7914(void*, const void*);
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
Vec4 fn_801F295C(const Matrix*, const Vec3*);
void fn_80272F14(Context*, const Matrix*);
void fn_8027210C(Context*, DrawRenderer*, DisplayList*, float);
void* fn_8028FACC(void*, u32);
void DCInvalidateRange(void*, u32);
void GXBeginDisplayList(void*, u32);
u32 GXEndDisplayList();
void GXResetWriteGatherPipe();
void GXBegin(int, int, u16);
}

inline Matrix* Resource::getWorld() {
    if (flags120 & 0x20) {
        MatrixPool* p = lbl_801E9D24.pool;
        world128 = p->banks[p->active18] + index12E;
        fn_801F230C(local124, world128);
        flags120 &= ~0x20;
    }
    return world128;
}
inline Matrix product(const Matrix* a, const Matrix* b) {
    Matrix r;
    fn_801F1080(a, b, &r);
    return r;
}

#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U32 (*(volatile u32*)0xCC008000)

struct Vertex {
    float x, y, z, w;
    Vertex& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vertex& operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
};

/* Register colouring is sensitive to: the declaration order below, `& 0xFF`
 * (not a (u8) cast) for lod, and dl taken directly (not via an inline). */
extern "C" void fn_8027BF44(Model* model, DrawRenderer* r, int part, Handle* materialHandle, Matrix* texMtx, float depth) {
    Context* ctx;
    VertexBuffer* vb;
    int n;
    int k;
    int lod;
    DisplayList* dl;
    int i;
    Resource* resC;
    u16 slot;
    u32 color;
    Matrix* local;
    ctx = r->record0->context48;
    r->valueBDC = model->value7C;
    r->valueBD8 = model->valueC4;
    r->cacheBE0 = lbl_801E9D24.cache178;
    fn_801F7914(&r->handleBE4, &model->handle04);
    lod = model->maxLod114 & 0xFF;
    r->lodBCC = lod;
    resC = r->resC;
    local = r->res10->local124;
    Matrix shifted;
    shifted = product(resC->getWorld(), local);
    shifted.m[3][3] -= 0.01f;
    fn_80272F14(ctx, &shifted);
    slot = model->states104[part].slot;
    if (slot != 0xFFFF) {
        vb = r->cacheBE0->get3(slot);
    } else {
        return;
    }
    color = 0xFFFFFF00;
    MaterialEntry* e = &lbl_801E9D24.manager->entries[materialHandle->index];
    /* ternary (not an if) keeps the 100.0f load ahead of the tag-compare branch */
    color |= (u8)(int)(100.0f * (e->tag == materialHandle->tag ? e->object : 0)->alpha18);
    n = lod + 1;
    dl = ctx->lists9E4 + ctx->count9E8++;
    dl->capacity = (lod * (n * 0x30 + 3) + 0x3F) & ~0x1F;
    dl->data = fn_8028FACC(lbl_8028F698, dl->capacity);
    DCInvalidateRange(dl->data, dl->capacity);
    GXBeginDisplayList(dl->data, dl->capacity);
    GXResetWriteGatherPipe();
    Vertex v;
    for (i = 0; i < lod; i++) {
        GXBegin(0x98, 1, n * 2);
        for (k = 0; k < n; k++) {
            v.x = vb->positions[i * n + k].x;
            v.y = vb->positions[i * n + k].y;
            v.z = vb->positions[i * n + k].z;
            WGPIPE_F32 = v.x;
            WGPIPE_F32 = v.y;
            WGPIPE_F32 = v.z;
            WGPIPE_U32 = color;
            v = fn_801F295C(texMtx, (Vec3*)&v);
            WGPIPE_F32 = v.x;
            WGPIPE_F32 = v.y;
            v.x = vb->positions[i * n + lod + 1 + k].x;
            v.y = vb->positions[i * n + lod + 1 + k].y;
            v.z = vb->positions[i * n + lod + 1 + k].z;
            WGPIPE_F32 = v.x;
            WGPIPE_F32 = v.y;
            WGPIPE_F32 = v.z;
            WGPIPE_U32 = color;
            v = fn_801F295C(texMtx, (Vec3*)&v);
            WGPIPE_F32 = v.x;
            WGPIPE_F32 = v.y;
        }
    }
    dl->size = GXEndDisplayList();
    DCStoreRange(dl->data, dl->capacity);
    fn_8027210C(ctx, r, dl, depth);
}

}

struct Flush1; /* forces emission of the deferred fn_8027BF44 (and its pooled literals) here */

/* ---- Game/font_atlas_constants.c (tail) ----
 * 0x8037B760-0x8037B78C are compiler-pooled literals of the functions above
 * (first-use order). The following constants are referenced by later units
 * (renderer_model_light_draw_8027C4D8, auto_03_8027C720) and stay named globals. */
extern "C" {
extern const float lbl_8037B790 = 0.0f;
extern const float lbl_8037B794 = 0.8999999761581421f;
extern const float lbl_8037B798 = 3.0f;
extern const float lbl_8037B79C = 1.0f;
extern const double lbl_8037B7A0 = 1.75;
}
