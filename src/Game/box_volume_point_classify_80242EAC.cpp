/* fn_80242EAC: box-volume point classification. Requires flag bit 35; refreshes the
   object's cached world matrix (flags 0x20), then for each box (0x80-byte records,
   inverse matrix at +0x40) transforms points a and b into box space and sets a bit
   when a lies strictly inside / b lies inside-or-on the [-0.5, 0.5] cube.
   Matching note: the first point's transformed coordinates must be members of a
   Vec3 local (pa) while the second point's stay scalars; that is what reproduces
   the original floating-point register assignment. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Vec3 {
    float x, y, z;
};
struct Matrix {
    float a[16];
};
struct MatrixCache {
    Matrix* arrays[6];
    unsigned char active;
};
struct Globals {
    char unknown[0x134];
    MatrixCache* cache;
};
extern "C" Globals lbl_801E9D24;
extern "C" {
void fn_801F230C(const Matrix*, Matrix*);
Matrix* fn_801F2788(Matrix*, const Matrix*);
extern const float lbl_8037B370, lbl_8037B374;
}
struct Object {
    char unknown[0x120];
    u32 flags;
    Matrix *matrix, *cached;
    char unknown12C[2];
    short index;
    Matrix* getMatrix()
    {
        if (flags & 0x20) {
            cached = lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active] + index;
            fn_801F230C(matrix, cached);
            flags &= ~0x20;
        }
        return cached;
    }
};
struct Box {
    char unknown00[0x40];
    Matrix inverse;
};
struct Mesh {
    char unknown00[0x74];
    int count, capacity;
    Box* boxes;
};
struct Result {
    char unknown00[0x1C];
    int index1C;
    char unknown20[8];
    int kind28;
    int value2C;
    Object* object;
    Mesh* mesh;
    char unknown38[4];
    unsigned char valid;
    char unknown3D[3];
    int side;
};
extern "C" int fn_80242EAC(Mesh* self, Object* object, const Vec3* a, const Vec3* b, Result* result, u64 flags)
{
    if (!(flags & 0x800000000ULL))
        return 0;
    Matrix* world = object->getMatrix();
    u32 inside = 0;
    u32 touching = 0;
    u32 bit = 1;
    for (int i = 0; i < self->count; i++) {
        Matrix m = self->boxes[i].inverse;
        fn_801F2788(&m, world);
        Vec3 pa;
        pa.x = m.a[0] * a->x + m.a[4] * a->y + m.a[8] * a->z + m.a[12];
        pa.y = m.a[1] * a->x + m.a[5] * a->y + m.a[9] * a->z + m.a[13];
        pa.z = m.a[2] * a->x + m.a[6] * a->y + m.a[10] * a->z + m.a[14];
        float bx = m.a[0] * b->x + m.a[4] * b->y + m.a[8] * b->z + m.a[12];
        float by = m.a[1] * b->x + m.a[5] * b->y + m.a[9] * b->z + m.a[13];
        float bz = m.a[2] * b->x + m.a[6] * b->y + m.a[10] * b->z + m.a[14];
        if (pa.x > lbl_8037B370 && pa.x < lbl_8037B374 && pa.y > lbl_8037B370 && pa.y < lbl_8037B374 && pa.z > lbl_8037B370 && pa.z < lbl_8037B374)
            inside |= bit;
        if (bx >= lbl_8037B370 && bx <= lbl_8037B374 && by >= lbl_8037B370 && by <= lbl_8037B374 && bz >= lbl_8037B370 && bz <= lbl_8037B374)
            touching |= bit;
        bit <<= 1;
    }
    if (inside && !touching)
        result->side = 3;
    else if (touching && !inside)
        result->side = 1;
    else if (inside)
        result->side = 2;
    else
        return 0;
    result->value2C = 0;
    result->kind28 = 8;
    result->index1C = -1;
    result->object = object;
    result->mesh = self;
    result->valid = 1;
    return 1;
}
