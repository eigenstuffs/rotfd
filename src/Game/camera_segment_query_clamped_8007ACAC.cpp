/* Camera segment query from the base point (0x14C) toward the camera point
   (0xF4) (fn_8007ACAC). When the point lies closer to the base than the
   minimum distance (lbl_80378A60), it is pushed out along the fast-normalized
   direction to lbl_803789BC. The service handle is copied with a counted
   handle (extab cleanup), and the masked segment query's signed low byte is
   returned as 0/1. Reading the scale label through a pointer orders its load
   before the reciprocal square root, which fixes the f0/f1 allocation of the
   inverse length and the scale. Ray/HitResult shapes are copied from the
   matched fn_800793D0 (camera_segment_visibility_800793D0.cpp). */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Service { char unknown00[8]; const Handle_801F7F10* handle; };
struct Context { char unknown00[0x118]; Manager* manager; Service* service; };
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
extern const float lbl_8037899C, lbl_80378A48, lbl_803789A8, lbl_80378A60, lbl_803789BC;
}
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020C04 : Handle_8001FF78 { Handle_80020C04(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_80020C04() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec3 normalized() const { float inv = reciprocalSqrt(lengthSquared()); return Vec3(x * inv, y * inv, z * inv); }
    void normalize() { *this = normalized(); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray(const Vec3& from, const Vec3& to) : origin(from), direction(to - from)
    {
        length = direction.length();
        if (length > lbl_80378A48) direction *= lbl_803789A8 / length;
    }
};

struct HitResult {
    char unknown00[0x28];
    int value28, value2C, value30, value34, value38;
    signed char flag3C;
    unsigned long long mask40;
    HitResult() { flag3C = 0; value30 = 0; value34 = 0; value38 = 0; value2C = 0; value28 = 0; }
};

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

struct Camera {
    char unknown00[0xF4];
    Vec3 current;
    char unknown100[0x4C];
    Vec3 base;
};

extern "C" signed char fn_80269818(Node*, const Ray*, HitResult*, unsigned long long, unsigned long long);

extern "C" int fn_8007ACAC(Camera* self)
{
    Vec3 point = self->current;
    Vec3 delta = self->current - self->base;
    if (delta.length() < lbl_80378A60) {
        delta.normalize();
        delta *= *(const float*)&lbl_803789BC;
        point = self->base + delta;
    }
    HitResult result;
    Handle_80020C04 held(*lbl_801E9D24.service->handle);
    Ray ray(self->base, point);
    if (fn_80269818(resolve<Node>(held), &ray, &result, 0x00008FE000000004ULL, 0ULL)) return 1;
    return 0;
}
