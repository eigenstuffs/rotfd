// Partial text split: fn_80283EB8 only. fn_8028437C after it (97.8%:
// callee-saved FPR order and induction registers) remains original code;
// its draft: scratch/claude_match/auto_03_80283EB8_text/wip_fn_8028437C_both.cpp.
// Sphere-marker quad builder (fn_80283EB8): for each enabled item, place a
// world matrix from the item's direction and radius and record a four-vertex
// GX display list. Only fn_80283EB8 of this original unit is reconstructed;
// fn_8028437C (the following function) is still outside this source.
//
// The 0.0/1.0/0.01 constants are referenced through their existing labels.
// They are declared without const so that each display-list write reloads
// them after the preceding volatile FIFO store, which reproduces the original
// literal-pool loads; the fastSqrt default reads through a const view.
typedef unsigned long Word;
typedef unsigned char Byte;
typedef unsigned short Half;
extern "C" float lbl_8037B828, lbl_8037B82C, lbl_8037B830;
#define WGPIPE_F32 (*(volatile float*)0xCC008000)
#define WGPIPE_U32 (*(volatile Word*)0xCC008000)

inline float fastSqrt(register float x)
{
    register float r = *(const float*)&lbl_8037B828;
    if (x != r) {
        asm { frsqrte f4, x
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Quat {
    float x, y, z, w;
    Quat() {}
    Quat& operator=(const Quat& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Matrix {
    float a[16];
    Vec3 transform(const Vec3& p) const {
        Vec3 r;
        r.x = a[12] + (a[8] * p.z + (a[0] * p.x + a[4] * p.y));
        r.y = a[13] + (a[9] * p.z + (a[1] * p.x + a[5] * p.y));
        r.z = a[14] + (a[10] * p.z + (a[2] * p.x + a[6] * p.y));
        return r;
    }
};
struct Handle { signed generation:8; signed index:24; };
struct Handle_801F7F10 {
    Word word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Resource {
    char unknown00[0x120];
    Word flags120;
    Matrix* local124;
    Matrix* world128;
    char unknown12C[2];
    short index12E;
    Matrix* getWorld();
};
struct MatrixPool { Matrix* banks[6]; Byte active18; };
struct HandleHolder { char unknown00[0x280]; Handle handle; };
struct Manager;
struct Globals {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[0x14];
    HandleHolder* holder;
};
struct Buffer { void* data; Word capacity, size; };
struct ContextPrefix { char unknown00[0x278]; };
struct Context : ContextPrefix {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void apply(const Handle*);
    char unknown27C[0x54];
    Half flags2D0, flags2D2;
};
struct Model { char unknown00[0x48]; Context* context; };
struct RenderRecord {
    Model* model;
    char unknown04[8];
    Resource* resource;
    Resource* source;
};
struct SphereItem { Vec3 position; Vec3 direction; float radius; };
struct SphereOwner {
    char unknown00[0x2C];
    Half* flags;
    int count;
    char unknown34[4];
    SphereItem* items;
    Buffer buffer;
    int getCount() const { return count; }
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F230C(const Matrix*, Matrix*);
Quat fn_801F27BC(const Vec3*, const Vec3*);
void* memset(void*, int, unsigned long);
void fn_801F1D90(const Quat*, Matrix*);
void fn_801F2788(Matrix*, const Matrix*);
void fn_80272F14(Context*, const Matrix*);
void fn_801F86C8(Manager*, const void*, int);
void fn_8027353C(Context*);
void DCInvalidateRange(void*, Word);
void DCStoreRange(void*, Word);
void GXBeginDisplayList(void*, Word);
void GXResetWriteGatherPipe();
void GXBegin(int, int, unsigned short);
Word GXEndDisplayList();
void fn_8027210C(Context*, RenderRecord*, Buffer*, float);
}
inline Matrix* Resource::getWorld()
{
    Resource* r = this;
    if (r->flags120 & 0x20) {
        MatrixPool* p = lbl_801E9D24.pool;
        r->world128 = p->banks[p->active18] + r->index12E;
        fn_801F230C(r->local124, r->world128);
        r->flags120 &= ~0x20;
    }
    return r->world128;
}
struct SphereZero : Handle_801F7F10 {
    SphereZero() { word = 0; }
    ~SphereZero() {}
};
struct SphereCopy : SphereZero {
    SphereCopy(const Handle& source) {
        word = *(const Word*)&source;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    ~SphereCopy() {}
};

extern "C" void fn_80283EB8(SphereOwner* self, RenderRecord* record)
{
    int count;
    int i;
    Context* context;
    Matrix world;
    Matrix m;
    Quat q;
    Vec3 up(lbl_8037B828, lbl_8037B82C, lbl_8037B828);
    if (!(record->source->flags120 & 0x80000)) return;
    context = record->model->context;
    count = self->getCount();
    for (i = 0; i < count; ++i) {
        Half f = self->flags[i];
        if (f & 8) continue;
        if (!(f & 0x20)) continue;
        m = *record->source->local124;
        world = *record->resource->getWorld();
        Vec3 p = m.transform(self->items[i].position);
        Vec3 col(m.a[0], m.a[4], m.a[8]);
        float sq = col.dot(col);
        float scale = fastSqrt(sq);
        float r = scale * self->items[i].radius;
        q = fn_801F27BC(&up, &self->items[i].direction);
        memset(&m, 0, sizeof(Matrix));
        m.a[0] = lbl_8037B82C;
        m.a[5] = lbl_8037B82C;
        m.a[10] = lbl_8037B82C;
        m.a[15] = lbl_8037B82C;
        fn_801F1D90(&q, &m);
        m.a[12] = p.x;
        m.a[13] = p.y;
        m.a[14] = p.z;
        fn_801F2788(&world, &m);
        fn_80272F14(context, &world);
        context->flags2D0 = 0;
        context->flags2D2 = 0xFFFF;
        {
            SphereCopy copy(lbl_801E9D24.holder->handle);
            context->apply((const Handle*)&copy);
        }
        context->flags2D0 |= 0x2000;
        fn_8027353C(context);
        DCInvalidateRange(self->buffer.data, self->buffer.capacity);
        GXBeginDisplayList(self->buffer.data, self->buffer.capacity);
        GXResetWriteGatherPipe();
        GXBegin(0x80, 1, 4);
        float n = -r;
        WGPIPE_F32 = n;
        WGPIPE_F32 = lbl_8037B830;
        WGPIPE_F32 = n;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = lbl_8037B828;
        WGPIPE_F32 = lbl_8037B828;
        WGPIPE_F32 = r;
        WGPIPE_F32 = lbl_8037B830;
        WGPIPE_F32 = n;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = lbl_8037B82C;
        WGPIPE_F32 = lbl_8037B828;
        WGPIPE_F32 = r;
        WGPIPE_F32 = lbl_8037B830;
        WGPIPE_F32 = r;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = lbl_8037B82C;
        WGPIPE_F32 = lbl_8037B82C;
        WGPIPE_F32 = n;
        WGPIPE_F32 = lbl_8037B830;
        WGPIPE_F32 = r;
        WGPIPE_U32 = 0x7F;
        WGPIPE_F32 = lbl_8037B828;
        WGPIPE_F32 = lbl_8037B82C;
        self->buffer.size = GXEndDisplayList();
        DCStoreRange(self->buffer.data, self->buffer.capacity);
        fn_8027210C(context, record, &self->buffer, lbl_8037B828);
    }
}
