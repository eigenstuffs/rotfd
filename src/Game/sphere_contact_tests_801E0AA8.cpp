/* auto_03_801E0AA8_text: three sphere contact tests from the collision-query
   TU (same flags as engine_collision_results_801E04DC/09E8: -O4,p, no C++
   exceptions, GC/1.3.2).

   fn_801E0AA8  sphere a against sphere b, nearest-result form: keeps the
                contact when the result is unset or the new depth is smaller.
   fn_801E0BA4  sphere a against sphere b, appended to a 256-record
                collection (same record view as sphere_box_hit_collect).
   fn_801E0CD4  ray (origin, length, unit direction) against a sphere,
                nearest-result form with a fast reciprocal-sqrt normal.

   Shared float labels: lbl_8037A4E0 (0.0f), lbl_8037A4E4 (1.0f),
   lbl_8037A4E8 (epsilon).  Allocation-sensitive spellings: the separation
   vector is built with the 3-argument constructor and copied to floats,
   and its squared length is written twice (CSE'd); the ray projection goes
   through the inline dot() so its value is a temporary; oc/proj/closest/n
   are kept as stack copies by reference bindings, as in the original. */
typedef unsigned long long Mask;

extern "C" {
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
}

inline float sqrtOrZero(register float sq)
{
    register float r = lbl_8037A4E0;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}

inline float reciprocalSqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    const Vec3& get() const { return *this; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    Vec3& normalize() { float xx = x * x, yy = y * y, zz = z * z; float inv = reciprocalSqrt(xx + yy + zz); x *= inv; y *= inv; z *= inv; return *this; }
};


struct Sphere {
    Vec3 center;
    float radius;
};

struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
};

struct Result {
    Vec3 point;
    float distance;
    Vec3 normal;
    char unknown1C[0x28 - 0x1C];
    Mask flags;
    char unknown30[0x3C - 0x30];
    signed char valid;
};

struct Record {
    Vec3 point;
    float distance;
    Vec3 normal;
    void* object;
    Mask flags;
    Record() { object = 0; }
};

inline void* operator new(unsigned long, void* p) { return p; }

struct Collection {
    Record records[256];
    int count;
    int append() {
        if (count >= 256) { new (&records[255]) Record; return 255; }
        new (&records[count++]) Record; return count - 1;
    }
};

extern "C" signed char fn_801E0AA8(const Sphere* a, const Sphere* b, Result* result, void*, Mask flags)
{
    Vec3 d(a->center.x - b->center.x, a->center.y - b->center.y, a->center.z - b->center.z);
    float dx = d.x, dy = d.y, dz = d.z;
    float r = a->radius + b->radius;
    if (dx * dx + dy * dy + dz * dz < r * r) {
        float dist = sqrtOrZero(dx * dx + dy * dy + dz * dz);
        float depth = dist - b->radius;
        if (!result->valid || depth < result->distance) {
            result->valid = 1;
            result->distance = depth;
            float inv = lbl_8037A4E4 / dist;
            result->normal = Vec3(dx * inv, dy * inv, dz * inv);
            result->point = b->center + result->normal * b->radius;
            result->flags = flags;
            return 1;
        }
    }
    return 0;
}

extern "C" signed char fn_801E0BA4(const Sphere* a, const Sphere* b, Collection* hits, void*, Mask flags)
{
    Vec3 d(a->center.x - b->center.x, a->center.y - b->center.y, a->center.z - b->center.z);
    float dx = d.x, dy = d.y, dz = d.z;
    float r = a->radius + b->radius;
    if (dx * dx + dy * dy + dz * dz < r * r) {
        Record& record = hits->records[hits->append()];
        float dist = sqrtOrZero(dx * dx + dy * dy + dz * dz);
        float inv = lbl_8037A4E4 / dist;
        record.normal = Vec3(dx * inv, dy * inv, dz * inv);
        record.point = b->center + record.normal * b->radius;
        record.distance = dist - b->radius;
        record.flags = flags;
        return 1;
    }
    return 0;
}

extern "C" signed char fn_801E0CD4(const Ray* ray, const Sphere* sphere, Result* result, void*, Mask flags)
{
    Vec3 oc = sphere->center - ray->origin;
    const Vec3& ocr = oc;
    float t = ocr.dot(ray->direction);
    float r2 = sphere->radius * sphere->radius;
    Vec3 closest;
    Vec3 proj = ray->direction * t;
    closest = proj.get() + ray->origin;
    const Vec3& cr = closest.get();
    Vec3 diff(cr.x - sphere->center.x, cr.y - sphere->center.y, cr.z - sphere->center.z);
    float dx = diff.x, dy = diff.y, dz = diff.z;
    float dsq = dx * dx + dy * dy + dz * dz;
    if (dsq > r2) return 0;
    float h = sqrtOrZero(r2 - dsq);
    float hit = t - h;
    if (hit > lbl_8037A4E8 && hit < ray->length) {
        if (!result->valid || hit < result->distance) {
            result->valid = 1;
            result->distance = hit;
            result->point = ray->origin + ray->direction * hit;
            Vec3 n = result->point - sphere->center;
            result->normal = n.normalize();
            result->flags = flags;
            return 1;
        }
    }
    return 0;
}
