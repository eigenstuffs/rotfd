/* Array resource placement from an owner matrix (fn_80248358). */
typedef unsigned long u32;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

extern "C" const float lbl_8037B400;
extern "C" const float lbl_8037B404;
extern "C" const float lbl_8037B408;
extern "C" const float lbl_8037B40C;
extern "C" float fn_800A8E8C(float value, float lower, float upper);

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B404;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    void operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; }
};

struct Matrix {
    float a[16];
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = a[0] * v.x + a[4] * v.y + a[8] * v.z + a[12];
        r.y = a[1] * v.x + a[5] * v.y + a[9] * v.z + a[13];
        r.z = a[2] * v.x + a[6] * v.y + a[10] * v.z + a[14];
        return r;
    }
    float scaleX() const { return Vec3(a[0], a[4], a[8]).length(); }
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
extern "C" void fn_801F230C(const Matrix*, Matrix*);

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

struct Sphere {
    Vec3 center;
    float radius;
};

struct Placement {
    Vec3 point;
    char unknown0C[4];
    Vec3 direction;
};

struct Prefix {
    char unknown00[8];
};

struct ArrayResource : Prefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual Sphere* getBounds();
    char unknown0C[4];
    Sphere bounds;
    char unknown20[4];
    Vec3 position;
    Vec3 direction;
    float value;
};

extern "C" void fn_80248358(ArrayResource* self, Object* object, const Vec3* origin,
                            const Placement* placement, float scale)
{
    float t = fn_800A8E8C(origin->y - placement->point.y, lbl_8037B404, lbl_8037B408) / lbl_8037B408;
    float fraction = lbl_8037B400 - t;
    Matrix* matrix = object->getMatrix();
    self->position = matrix->transform(placement->point);
    self->direction = placement->direction;
    float radius = scale * matrix->scaleX();
    self->getBounds()->radius = radius;
    self->getBounds()->center = self->position;
    self->value = fn_800A8E8C(scale * fraction, lbl_8037B40C * scale, scale);
    object->flags |= 0x80000;
}
