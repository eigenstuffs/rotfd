#include "recovered/w3_4_query.h"

template <class T> inline int sizeOf(const Array<T>& a) { return a.count; }
static inline void* getPoints(const Node* n) { return n->points; }
static inline u64 getMask(const Material* m) { return m->mask; }

extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
void fn_801E059C(const Sphere*, void*, Collector*, u64);
void fn_801DFE90(const Sphere*, void*, Collector*, u64);
void fn_801E0BA4(const Sphere*, void*, Collector*, u64);
signed char fn_801DF9B0(const Sphere*, void*, short*, int, int, Collector*, u64);
int fn_801DC718(Collector*, void*, Object*);
}

static inline bool overlaps(const Sphere& a, const Sphere& b)
{
    float radius = a.radius + b.radius;
    const Vec3& delta = a.center - b.center;
    return delta.lengthSquared() < radius * radius;
}

extern "C" int fn_802474F8(Node* self, Object* object, const Info* info, const Sphere* sphere, Collector* collector,
                           u64 flags, u64 exclude)
{
    if ((exclude & MASK(0x100)) || (self->flags & 4) || (info->flags & 1))
        return 0;
    if (!(flags & MASK(0x100)))
        return 0;
    int boxCount;
    int matrixCount;
    int sphereCount;
    void* saved;
    saved = collector->record;
    sphereCount = sizeOf(self->spheres);
    matrixCount = sizeOf(self->matrices);
    boxCount = sizeOf(self->boxes);
    Sphere transformed = fn_80099A00(object->getInverse(), sphere);
    if (!overlaps(self->bounds, transformed))
        return 0;
    int i;
    if (sphereCount || matrixCount || boxCount) {
        if (flags & MASK(0x20))
            for (i = 0; i < boxCount; ++i)
                fn_801E059C(&transformed, &self->boxes.data[i], collector, MASK(0x120));
        if (flags & MASK(0x40))
            for (i = 0; i < matrixCount; ++i)
                fn_801DFE90(&transformed, &self->matrices.data[i], collector, MASK(0x140));
        if (flags & MASK(0x80))
            for (i = 0; i < sphereCount; ++i)
                fn_801E0BA4(&transformed, &self->spheres.data[i], collector, MASK(0x180));
    } else {
        void* points = getPoints(self);
        Strip* strip = self->strips.data;
        int count = self->strips.count;
        for (i = 0; i < count; ++i, ++strip) {
            Material* material = resolveMaterial(self->materials.data[self->strips.data[i].material]);
            u64 mask = getMask(material);
            if ((flags & mask) && !(exclude & mask))
                fn_801DF9B0(&transformed, points, strip->indices, strip->count - 2, ((strip->flags >> 1) & 1) ^ 1,
                            collector, mask);
        }
    }
    return fn_801DC718(collector, saved, object);
}

#pragma fp_contract on

extern "C" const float lbl_8037B3F0; /* 0.0f */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec(const Vec& o) : x(o.x), y(o.y), z(o.z) {}
    Vec& operator=(const Vec& o) { x = o.x; y = o.y; z = o.z; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B3F0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct RayMatrix {
    float m[4][4];
    Vec transform(const Vec& p) const
    {
        float x = m[3][0] + (m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z);
        float y = m[3][1] + (m[0][1] * p.x + m[1][1] * p.y + m[2][1] * p.z);
        float z = m[3][2] + (m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
        return Vec(x, y, z);
    }
    float scale() const { return Vec(m[0][0], m[1][0], m[2][0]).length(); }
};
struct Rotation {
    Vec row[3];
    Vec rotate(const Vec& p) const
    {
        float x = row[0].x * p.x + row[1].x * p.y + row[2].x * p.z;
        float y = row[0].y * p.x + row[1].y * p.y + row[2].y * p.z;
        float z = row[0].z * p.x + row[1].z * p.y + row[2].z * p.z;
        return Vec(x, y, z);
    }
};
struct Ray {
    Vec origin;
    float maxT;
    Vec dir;
    float length;
    Ray() {}
    Ray(const Ray& r) : origin(r.origin), maxT(r.maxT), dir(r.dir), length(r.length) {}
};
struct RayObject {
    char unknown00[0x30];
    Rotation rotation;
};
struct Hit {
    Vec point;
    float t;
    Vec normal;
    int unknown1C;
    float unknown20, unknown24;
    u64 mask;
    void* object;
    void* owner;
    void* info;
    signed char valid;
    int unknown40;
    Hit() { valid = 0; object = 0; owner = 0; info = 0; mask = 0; }
};
struct Result {
    Vec point;
    float t;
    Vec normal;
    char unknown1C[0x14];
};

extern "C" {
Ray fn_80245250(const Matrix*, const Ray*);
signed char fn_801BA38C(const Ray*, const Sphere*);
void fn_801E09E8(const Ray*, void*, Hit*, u64);
signed char fn_801E0188(const Ray*, void*, Hit*, u64);
void fn_801E0CD4(const Ray*, void*, Hit*, u64);
signed char fn_801B9108(const Ray*, void*, short*, int, int, Result*);
}


extern "C" signed char fn_80247890(Node* self, Object* object, const Info* info, const Ray* ray, Hit* out, u64 flags,
                                   u64 exclude)
{
    if ((exclude & MASK(0x100)) || (self->flags & 4) || (info->flags & 1))
        return 0;
    if (!(flags & MASK(0x100)))
        return 0;
    Ray local(fn_80245250(object->getInverse(), ray));
    if (!fn_801BA38C(&local, &self->bounds))
        return 0;
    int sphereCount;
    int matrixCount;
    int boxCount;
    int i;
    void* points;
    Material* material;
    u64 mask;
    Strip* strip;
    int count;
    sphereCount = sizeOf(self->spheres);
    matrixCount = sizeOf(self->matrices);
    boxCount = sizeOf(self->boxes);
    Hit hit;
    if (sphereCount || matrixCount || boxCount) {
        if (flags & MASK(0x20))
            for (i = 0; i < boxCount; ++i)
                fn_801E09E8(&local, &self->boxes.data[i], &hit, MASK(0x120));
        if (flags & MASK(0x40))
            for (i = 0; i < matrixCount; ++i)
                if (fn_801E0188(&local, &self->matrices.data[i], &hit, MASK(0x140)))
                    hit.unknown1C = i;
        if (flags & MASK(0x80))
            for (i = 0; i < sphereCount; ++i)
                fn_801E0CD4(&local, &self->spheres.data[i], &hit, MASK(0x180));
    } else {
        points = getPoints(self);
        strip = self->strips.data;
        count = self->strips.count;
        for (i = 0; i < count; ++i, ++strip) {
            material = resolveMaterial(self->materials.data[strip->material]);
            mask = getMask(material);
            if ((flags & mask) && !(exclude & mask)) {
                Result result;
                if (fn_801B9108(&local, points, strip->indices, strip->count - 2, ((strip->flags >> 1) & 1) ^ 1,
                                &result)) {
                    if (!hit.valid || result.t < hit.t) {
                        hit.valid = 1;
                        hit.normal = result.normal;
                        hit.point = result.point;
                        hit.t = result.t;
                        hit.mask = mask;
                    }
                }
            }
        }
    }
    if (hit.valid) {
        RayMatrix* m = (RayMatrix*)object->matrix;
        if (!out->valid || out->t > hit.t * m->scale()) {
            out->valid = 1;
            out->object = object;
            out->owner = self;
            out->info = (void*)info;
            out->t = hit.t * m->scale();
            out->point = m->transform(hit.point);
            out->normal = ((RayObject*)object)->rotation.rotate(hit.normal);
            out->mask = hit.mask;
            out->unknown1C = hit.unknown1C;
            out->unknown40 = hit.unknown40;
        }
    }
    return out->valid;
}
