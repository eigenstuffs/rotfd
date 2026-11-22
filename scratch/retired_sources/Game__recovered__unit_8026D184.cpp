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
extern const float lbl_8037B66C;
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
        float d = lbl_8037B66C * (nx * (m->m[12] - pos.x) + ny * (m->m[13] - pos.y) + nz * (m->m[14] - pos.z));
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
