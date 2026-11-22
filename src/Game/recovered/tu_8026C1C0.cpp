/* Blob-shadow render-to-texture pass (8026C1C0..8026D150).
 *
 * Renders the shadow caster's silhouette into a 64x64 corner of the EFB with
 * an orthographic camera looking along the light direction, copies it into
 * the shadow texture, then draws every receiver with a projective texture
 * matrix.  Types follow the adjacent recovered/unit_8026D184.cpp. */
typedef unsigned long Word;
typedef unsigned short u16;
typedef unsigned char u8;

inline float fastSqrt(register float x, register float zero)
{
    register float r = zero;
    if (x != r) {
        asm { frsqrte f4, x
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 minusR(const Vec3& v) const { Vec3 r; r.x = x - v.x; r.y = y - v.y; r.z = z - v.z; return r; }
    Vec3 minusL(const Vec3& v) const { float a = x - v.x; float b = y - v.y; float c = z - v.z; return Vec3(a, b, c); }
    Vec3 minusZ(const Vec3& v) const { Vec3 r(x - v.x, y - v.y, z - v.z); return r; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float length(float zero) const { return fastSqrt(dot(*this), zero); }
    float getZ() const { return z; }
};
struct Row {
    float x, y, z;
    Row(float a, float b, float c) : x(a), y(b), z(c) {}
    float dot(const Row& v) const { return x * v.x + y * v.y + z * v.z; }
    float length(float zero) const { return fastSqrt(dot(*this), zero); }
};
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
struct Quat {
    float w, x, y, z;
    Quat() {}
    Quat(const Quat& q) : w(q.w), x(q.x), y(q.y), z(q.z) {}
};
struct Matrix {
    float m[16];
    const Vec3& pos() const { return *(const Vec3*)&m[12]; }
    Row column(int i) const { return Row(m[i], m[4 + i], m[8 + i]); }
    Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); }
    Vec3 getPos2() const { return pos(); }
};
struct Mat3 { float m[9]; };

struct Handle {
    union { int word; struct { signed int tag : 8, index : 24; } bits; };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };
struct MatrixPool { Matrix* pages[6]; u8 active; };
struct Registry { char unknown00[0x1C]; Handle* root; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[4];
    Registry* registry;
} lbl_801E9D24;

inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}
#define RES(T, x) ((T*)resolveAny(x))
struct GBox { Global* g; };
struct OBox { int v; };
inline void* resolveG(Global* g, const Handle& h)
{
    int index = h.bits.index;
    Manager* m = g->manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}
#define RESG(T, x) ((T*)resolveG(G.g, x))
#define RESE(T, x) ((T*)resolveG(E.g, x))

struct Handle_801F7F10 {
    Word word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" void fn_801F86C8(Manager*, const void*, int);
struct ZeroHandle : Handle_801F7F10 {
    ZeroHandle() { word = 0; }
    ~ZeroHandle() {}
};
struct HandleCopy : ZeroHandle {
    HandleCopy(const Handle& h)
    {
        word = *(const Word*)&h;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~HandleCopy() {}
    HandleCopy(Global* g, const Handle& h)
    {
        word = *(const Word*)&h;
        fn_801F86C8(g->manager, &h, 1);
    }
};

struct GXColor { u8 r, g, b, a; };

struct Transform {
    char unknown00[0x1C];
    Handle owner;
    char unknown20[0x10];
    Mat3 rotation;
    char unknown54[0x120 - 0x54];
    Word flags;
    Matrix* matrix;
    Matrix* inverse;
    short unknown12C, index;
};
struct RendererStorage { char unknown00[0x21C]; int height; char unknown220[0x58]; };
struct Renderer : RendererStorage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98(); virtual void slot9C();
    virtual void setTexture(const Handle_801F7F10&);
    char unknown27C[0x54];
    u16 flags2D0;
    u16 mask2D2;
};
struct Record { char unknown00[0x48]; Renderer* renderer; };
struct Context {
    Record* record;
    char unknown04[8];
    Transform* camera;
    Transform* object;
    char unknown14[0x4C];
    Matrix matrix;
    Vec3 offset;
    char unknownAC[0xBCC - 0xAC];
    int pass;
    char unknownBD0[0xC];
    Word wordBDC;
};
struct Lod { char unknown00[0xC]; float range; };
struct OwnerStorage { char unknown00[8]; };
struct Owner : OwnerStorage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C();
    virtual void drawShadow(Context*, void*, const Handle_801F7F10&, Matrix*, float);
    char unknown0C[0x60];
    u16 kind;
    char unknown6E[0x3E];
    Word lodCount;
    Lod* lods;
    char unknownB4[0x14];
    Handle* states;
    Lod* firstLod()
    {
        if (lodCount != 0)
            return lods;
        return 0;
    }
};
struct State {
    char unknown00[0x6C];
    u16 kind;
    char unknown6E[0xE];
    Word word7C;
};
struct Texture { char unknown00[0xC]; void* image; };
struct Target { char unknown00[0x74]; Handle texture; };
struct TargetMaterial { char unknown00[0x18]; float alpha; };
struct NodeStorage { char unknown00[8]; };
struct Node : NodeStorage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual Handle* getObject(int);
};
struct World { char unknown00[0x70]; Handle node; };
struct Scene { char unknown00[0xB0]; Handle* world; };
struct Shadow {
    char unknown00[0x20];
    int passCount;
    char unknown24[4];
    Handle* materials;
    char unknown2C[0xC];
    Vec3 normal;
    float radius;
    char unknown48[0xC8];
    Word receiverCount;
    char unknown114[4];
    Transform** receivers;
    int meshCount;
    char unknown120[4];
    void** meshes;
};

extern "C" {
extern const float lbl_8037B66C, lbl_8037B670, lbl_8037B674, lbl_8037B678, lbl_8037B67C, lbl_8037B680,
    lbl_8037B684, lbl_8037B688, lbl_8037B68C, lbl_8037B690, lbl_8037B694;
extern const GXColor lbl_8037B668;
extern Vec4 game_vec4_zero;
Handle* fn_8027269C(Renderer*);
float fn_800A8E8C(float, float, float);
void fn_80246710(Owner*, Transform*, Vec4*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801F230C(const Matrix*, Matrix*);
Quat fn_801F27BC(const Vec3*, const Vec3*);
void fn_801F1D90(const Quat*, Matrix*);
Matrix* fn_801F2788(Matrix*, const Matrix*);
void fn_80272F14(Renderer*, Matrix*);
void fn_8027301C(Renderer*);
void fn_8027353C(Renderer*);
void fn_802828FC(State*, Context*, void*);
void fn_80280174(State*, Context*, void*);
Word fn_801F7EB8(const Handle*);
void GXSetViewport(float, float, float, float, float, float);
void GXSetScissor(Word, Word, Word, Word);
void MTXOrtho(float (*)[4], float, float, float, float, float, float);
void GXSetProjection(float (*)[4], int);
void GXSetPixelFmt(int, int);
void GXSetBlendMode(int, int, int, int);
void GXSetAlphaCompare(int, int, int, int, int);
void GXSetZCompLoc(int);
void GXSetZMode(int, int, int);
void GXSetNumChans(int);
void GXSetChanCtrl(int, int, int, int, int, int, int);
void GXSetChanMatColor(int, GXColor);
void GXSetNumTexGens(int);
void GXSetNumTevStages(int);
void GXSetTevOrder(int, int, int, int);
void GXSetTevColorIn(int, int, int, int, int);
void GXSetTevAlphaIn(int, int, int, int, int);
void GXSetTevColorOp(int, int, int, int, int, int);
void GXSetTevAlphaOp(int, int, int, int, int, int);
void GXTexModeSync();
void GXInvalidateTexAll();
void GXSetCopyClear(GXColor, Word);
void GXSetTexCopySrc(u16, u16, u16, u16);
void GXSetTexCopyDst(u16, u16, int, int);
void GXDrawDone();
void GXCopyTex(void*, int);
void GXPixModeSync();
}

inline float getScale(const Matrix* m)
{
    Row c = m->column(0);
    return c.length(0.0f);
}
inline Matrix product(const Matrix& a, const Matrix& b)
{
    Matrix m;
    fn_801F1080(&a, &b, &m);
    return m;
}
inline Matrix* getInverse(Transform* object)
{
    if (object->flags & 0x20) {
        object->inverse = &lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];
        fn_801F230C(object->matrix, object->inverse);
        object->flags &= ~0x20;
    }
    return object->inverse;
}
inline Vec3 transform(const Matrix& m, const Vec3& v)
{
    float x = m.m[12] + (m.m[8] * v.z + (m.m[0] * v.x + m.m[4] * v.y));
    float y = m.m[13] + (m.m[9] * v.z + (m.m[1] * v.x + m.m[5] * v.y));
    float z = m.m[14] + (m.m[10] * v.z + (m.m[2] * v.x + m.m[6] * v.y));
    return Vec3(x, y, z);
}
inline void transformInPlace(const Matrix& m, Vec3& v)
{
    float x = m.m[12] + (m.m[8] * v.z + (m.m[0] * v.x + m.m[4] * v.y));
    float y = m.m[13] + (m.m[9] * v.z + (m.m[1] * v.x + m.m[5] * v.y));
    float z = m.m[14] + (m.m[10] * v.z + (m.m[2] * v.x + m.m[6] * v.y));
    v = Vec3(x, y, z);
}
inline Vec3 transformR(const Matrix& m, const Vec3& v)
{
    Vec3 r;
    r.x = m.m[12] + (m.m[8] * v.z + (m.m[0] * v.x + m.m[4] * v.y));
    r.y = m.m[13] + (m.m[9] * v.z + (m.m[1] * v.x + m.m[5] * v.y));
    r.z = m.m[14] + (m.m[10] * v.z + (m.m[2] * v.x + m.m[6] * v.y));
    return r;
}
inline Vec3 rotateR(const Mat3& m, const Vec3& v)
{
    Vec3 r;
    r.x = m.m[6] * v.z + (m.m[0] * v.x + m.m[3] * v.y);
    r.y = m.m[7] * v.z + (m.m[1] * v.x + m.m[4] * v.y);
    r.z = m.m[8] * v.z + (m.m[2] * v.x + m.m[5] * v.y);
    return r;
}
inline Vec3 rotate(const Mat3& m, const Vec3& v)
{
    float x = m.m[6] * v.z + (m.m[0] * v.x + m.m[3] * v.y);
    float y = m.m[7] * v.z + (m.m[1] * v.x + m.m[4] * v.y);
    float z = m.m[8] * v.z + (m.m[2] * v.x + m.m[5] * v.y);
    return Vec3(x, y, z);
}

extern "C" void fn_8026C1C0(Shadow* self, Context* ctx)
{
    Target* target;
    OBox o;
    GBox G;
    Transform* saved;
    Handle* targetHandle;
    Transform* camera;
    signed char isCaster;
    Renderer* renderer;
    Owner* owner;
    State* state;
    Texture* material;

    o.v = 0;
    isCaster = 0;
    renderer = ctx->record->renderer;
    targetHandle = fn_8027269C(renderer);
    GBox E;
    E.g = (Global*)((Word)&lbl_801E9D24);
    Scene* scene = RESE(Scene, *E.g->registry->root);
    World* world = RESE(World, *scene->world);
    Node* node = RESE(Node, world->node);
    Transform* caster = RESE(Transform, *node->getObject(0));
    if (caster == ctx->object) {
        isCaster = 1;
        G.g = E.g;
    } else
        G.g = E.g;
    if (!((ctx->object->flags & 0x80000) && ctx->offset.z > 2.0f && ctx->offset.z < 7.0f) && !isCaster)
        return;
    if (!targetHandle)
        return;
    target = RESE(Target, *targetHandle);
    ctx->pass = self->passCount - 1;
    saved = ctx->object;
    owner = RESE(Owner, saved->owner);
    state = RESE(State, owner->states[ctx->pass]);
    material = RESE(Texture, self->materials[ctx->pass]);
    Lod* lod;
    if (owner->lodCount != 0)
        lod = owner->lods;
    else
        return;
    float alpha;
    if (isCaster || ctx->offset.z < 5.0f) {
        alpha = fn_800A8E8C(self->radius / lod->range, 0.0f, 1.0f);
        if (alpha < 0.05f)
            return;
    } else {
        alpha = fn_800A8E8C(self->radius / lod->range, 0.0f, 1.0f);
        alpha = alpha * ((7.0f - ctx->offset.z) / 2.0f);
        if (alpha < 0.05f)
            return;
    }
    Vec4 dir(game_vec4_zero.x, game_vec4_zero.y, game_vec4_zero.z, 1.0f);
    fn_80246710(owner, ctx->object, &dir);
    int height = renderer->height;
    float size = dir.w;
    float zero = 0.0f;
    float extent = 64.0f;
    GXSetViewport(zero, (float)height, extent, extent, zero, 1.0f);
    GXSetScissor(0, height, 0x40, 0x40);
    float projection[4][4];
    float half = 32.0f;
    MTXOrtho(projection, -half, half, -half, half, 1.0f, 100.0f);
    GXSetProjection(projection, 1);
    GXSetPixelFmt(1, 0);
    GXSetBlendMode(0, 1, 1, 0);
    GXSetAlphaCompare(4, 0, 0, 3, 0xFF);
    GXSetZCompLoc(0);
    GXSetZMode(1, 7, 1);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 1, 0, 0, 2, 2);
    GXColor white = {0, 0, 0, 0xFF};
    GXColor color = white;
    GXSetChanMatColor(4, color);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetTevColorIn(0, 15, 15, 15, 10);
    GXSetTevAlphaIn(0, 7, 7, 7, 5);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);

    Matrix a, b, c;
    float scale = getScale(ctx->object->matrix);
    Vec3 offset = rotateR(ctx->object->rotation, *(Vec3*)&dir);
    float texel = 64.0f / (4.0f * scale * size);
    a.m[0] = texel;
    a.m[3] = a.m[2] = a.m[1] = 0.0f;
    a.m[5] = a.m[4] = 0.0f;
    a.m[6] = texel;
    a.m[8] = a.m[7] = 0.0f;
    a.m[9] = texel;
    a.m[13] = a.m[12] = a.m[11] = a.m[10] = 0.0f;
    a.m[15] = a.m[14] = 1.0f;
    b = *ctx->object->matrix;
    Vec3 local = transformR(b, *(Vec3*)&dir);
    Vec3 delta;
    delta = ctx->object->matrix->getPos().minusZ(local);
    b.m[12] = delta.x;
    b.m[13] = 0.0f;
    b.m[14] = delta.z;
    b.m[15] = 1.0f;
    b = product(a, b);
    fn_80272F14(renderer, &b);
    switch (state->kind) {
    case 6:
        ctx->wordBDC = state->word7C;
        fn_802828FC(state, ctx, material);
        break;
    case 3:
        fn_80280174(state, ctx, material);
        break;
    }
    GXTexModeSync();
    GXInvalidateTexAll();
    GXSetZCompLoc(1);
    color.a = 0;
    GXSetCopyClear(color, 0);
    GXSetTexCopySrc(0, height, 0x40, 0x40);
    GXSetTexCopyDst(0x40, 0x40, 6, 0);
    GXDrawDone();
    GXCopyTex(RESG(Texture, target->texture)->image, 1);
    GXSetPixelFmt(0, 0);
    fn_8027301C(renderer);

    Vec3 center = transformR(*ctx->object->matrix, *(Vec3*)&dir);
    camera = ctx->camera;
    a = *getInverse(camera);
    Vec3 up(0.0f, 1.0f, 0.0f);
    Quat rotation(fn_801F27BC(&up, &self->normal));
    fn_801F1D90(&rotation, &b);
    b.m[12] = center.x;
    b.m[13] = center.y;
    b.m[14] = center.z;
    fn_801F2788(&a, &b);
    GXPixModeSync();
    RESG(TargetMaterial, *targetHandle)->alpha = alpha;
    fn_80272F14(renderer, &a);
    renderer->flags2D0 = 0;
    renderer->mask2D2 = 0xFFFF;
    renderer->setTexture(HandleCopy(G.g, *targetHandle));
    renderer->flags2D0 |= 0x2000;
    renderer->flags2D0 |= 1;
    fn_8027353C(renderer);

    Vec3 scaled = offset * scale;
    /* named tx/ty/tz: the z value gets a low vreg, so it and the named depth
     * both colour f21 and the depth copy disappears (w25). */
    float tx = ctx->matrix.m[12] + (ctx->matrix.m[8] * center.z + (ctx->matrix.m[0] * center.x + ctx->matrix.m[4] * center.y));
    float ty = ctx->matrix.m[13] + (ctx->matrix.m[9] * center.z + (ctx->matrix.m[1] * center.x + ctx->matrix.m[5] * center.y));
    float tz = ctx->matrix.m[14] + (ctx->matrix.m[10] * center.z + (ctx->matrix.m[2] * center.x + ctx->matrix.m[6] * center.y));
    float depth = Vec3(tx, ty, tz).z;
    Vec3 point = ctx->object->matrix->getPos() + scaled;
    float inverse = 1.0f / (4.0f * dir.w * scale);
    float px = point.x;
    float py = point.y;
    float pz = point.z;
    c.m[0] = inverse;
    c.m[4] = 0.0f;
    c.m[8] = 0.0f;
    c.m[12] = -px * inverse + 0.5f;
    c.m[1] = 0.0f;
    c.m[5] = 0.0f;
    c.m[9] = inverse;
    c.m[13] = -pz * inverse + 0.5f;
    c.m[2] = 0.0f;
    c.m[6] = inverse;
    c.m[10] = 0.0f;
    c.m[14] = -py * inverse + 0.5f;
    c.m[3] = 0.0f;
    c.m[7] = 0.0f;
    c.m[11] = 0.0f;
    c.m[15] = 1.0f;
    a = c;
    for (Word i = 0; i < self->receiverCount; i++) {
        Transform* receiver = self->receivers[(int)i];
        ctx->object = receiver;
        if (fn_801F7EB8(&receiver->owner)) {
            Owner* receiverOwner = RESG(Owner, receiver->owner);
            if (receiverOwner->kind == 1) {
                c = product(a, *receiver->matrix);
                int j;
                for (j = 0, o.v = 0; j < self->meshCount; o.v += 4, j++) {
                    receiverOwner->drawShadow(ctx, *(void**)((char*)self->meshes + o.v), HandleCopy(G.g, *targetHandle), &c, depth);
                }
            }
        }
    }
    ctx->object = saved;
}

namespace part_8026D150 {
#include "Game/engine_mesh_owner_controls.h"

extern "C" signed char fn_802460F8(EngineHandleApplyPrimary*);

extern "C" signed char fn_8026D150(EngineHandleApplyPrimary* self)
{
    return (signed char)(fn_802460F8(self) ? 1 : 0);
}

}
namespace part_8026D184 {
typedef unsigned long Word;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
};
struct Quat { float w, x, y, z; Quat(const Quat& q) : w(q.w), x(q.x), y(q.y), z(q.z) {} };
struct Matrix { float m[16]; const Vec3& pos() const { return *(const Vec3*)&m[12]; } };

struct Handle {
    union { int word; struct { signed int tag : 8, index : 24; } bits; };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
} lbl_801E9D24;

inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}
inline void* lookupAny(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->getTag() == h.getTag())
        return e->object;
    return 0;
}
#define RES(T, x) ((T*)resolveAny(x))
#define RESX(h) (lbl_801E9D24.manager->entries[(h).bits.index].getTag() == (h).getTag() ? lbl_801E9D24.manager->entries[(h).bits.index].object : 0)

struct Transform {
    char unknown00[0xC];
    Handle parent;
    char unknown10[0xB8 - 0x10];
    Vec3 position;
    char unknownC4[4];
    Quat rotation;
    Vec3 scale;
    char unknownE4[0x120 - 0xE4];
    unsigned long flags;
    Matrix* matrix;
    Matrix* inverse;
    short unknown12C, index;
};
struct Context {
    char unknown00[0xC];
    Transform* camera;
    Transform* object;
    void* material;
    char unknown18[8];
    Matrix matrix;
    char unknown60[0xBCC - 0x60];
    int pass;
};
struct Node {
    char unknown00[0xC];
    Word flags;
    char unknown10[0x18];
    Handle* materials;
    Vec3 point;
    Vec3 normal;
    char unknown44[8];
    char defaultMaterial[0x108 - 0x4C];
    Handle a, b;
};
struct StateBase { char unknown00[8]; };
struct State : StateBase {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C();
    virtual void draw(Context*, void*);
    void drawWith(Context* c, const Handle& h) { draw(c, resolveAny(h)); }
    char unknown0C[0x60];
    unsigned short kind;
};
struct Owner {
    char unknown00[0xC0];
    int count, capacity;
    Handle* states;
};
extern "C" {
void fn_801CBB0C();
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801F25E8(Matrix*, const Vec3*, const Quat*, const Vec3*);
}
inline void compose(Matrix* dst, const Vec3* p, const Quat* q, const Vec3* s, Matrix& saved)
{
    saved = *dst;
    fn_801F25E8(dst, p, q, s);
}
inline Matrix product(const Matrix& a, const Matrix& b) { Matrix m; fn_801F1080(&a, &b, &m); return m; }
inline Matrix* getInverse(Transform* object)
{
    if (object->flags & 0x20) {
        object->inverse = &lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];
        fn_801F230C(object->matrix, object->inverse);
        object->flags &= ~0x20;
    }
    return object->inverse;
}
inline void transform(const Matrix& m, Vec3& v)
{
    float x = m.m[12] + (m.m[8] * v.z + (m.m[0] * v.x + m.m[4] * v.y));
    float y = m.m[13] + (m.m[9] * v.z + (m.m[1] * v.x + m.m[5] * v.y));
    float z = m.m[14] + (m.m[10] * v.z + (m.m[2] * v.x + m.m[6] * v.y));
    v = Vec3(x, y, z);
}

extern "C" void fn_8026D184(Owner* self, Context* ctx, Node* node)
{
    if (self->count == 0) return;
    fn_801CBB0C();
    State* state = RES(State, self->states[ctx->pass]);
    void* a = resolveAny(node->a);
    void* b = resolveAny(node->b);
    if (a == b) {
        if (a) ctx->material = a;
    } else {
        ctx->material = node->defaultMaterial;
    }
    if (ctx->material == 0) ctx->material = node->defaultMaterial;
    state->draw(ctx, lookupAny(node->materials[ctx->pass]));
    if ((node->flags & 0x10) && (state->kind == 3 || state->kind == 6)) {
        Vec3 pos = node->point;
        Transform* t = ctx->object;
        float nx = node->normal.x;
        Matrix* m = t->matrix;
        float ny = node->normal.y;
        float nz = node->normal.z;
        transform(*m, pos);
        float oz = nz;
        float d = 2.0f * (nx * (m->m[12] - pos.x) + ny * (m->m[13] - pos.y) + nz * (m->m[14] - pos.z));
        oz *= d; pos = ctx->object->position - Vec3(nx * d, ny * d, oz);
        Vec3 scale;
        Quat q(ctx->object->rotation);
        q.x = -q.x;
        q.z = -q.z;
        scale.x = ctx->object->scale.x; scale.y = ctx->object->scale.y; scale.z = ctx->object->scale.z;
        scale.y = -scale.y;
        Matrix saved = ctx->matrix;
        fn_801F25E8(&ctx->matrix, &pos, &q, &scale);
        ctx->matrix = product(*RES(Transform, ctx->object->parent)->matrix, ctx->matrix);
        Transform* camera = ctx->camera;
        ctx->matrix = product(*getInverse(camera), ctx->matrix);
        state->draw(ctx, lookupAny(node->materials[ctx->pass]));
        ctx->matrix = saved;
    }
}

}
