/* Camera collision push-out (fn_80079D3C). The camera point at 0xF4 is
   tested against the target's collision with a sphere query (fn_80268918,
   mask 0x00008FE000000004, radius lbl_803789D0). On a hit the up vector is
   reset and the direction eased (fn_8007D4B4), the camera is pushed away
   from the nearest hit by 0.1 * delta, and a second query with radius 0.5
   is made from the moved point. On a second hit it is pushed out along the
   nearest contact normal by the penetration, and if the segment from just
   outside the contact to the raised target position (fn_80076D98 + height
   at 0x21C) is blocked (fn_800793D0) it is pushed along the probe-to-contact
   direction by the penetration again; the flag at 0x131 is set and 1 is
   returned. The collected-object arrays (stride 0x28, count at +0x2800) and
   the counted target handle produce the extab cleanup actions. The fast
   normalize uses a minimal inline asm frsqrte (no Newton step, no frsp),
   which no compiler built-in emits.

   The segment-start scale is the pooled 0.1f literal lbl_803789C0 (shared
   with fn_8007622C). The original's literal uses were not CSE'd, so each
   component reads the label in a distinct form (plain,
   *(const float*)&lbl, *(const float*)(unsigned long)&lbl), which
   reproduces the original FPR assignment with the extern label only. */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
extern "C" {
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
void fn_801EF610(void*, void*);
extern char lbl_801EF5C8[];
extern const float lbl_803789D0, lbl_8037899C, lbl_803789A4, lbl_80378A28, lbl_80378A54, lbl_803789C0, lbl_803789C4;
}
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020C04 : Handle_8001FF78 { Handle_80020C04(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_80020C04() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };

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
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec3& normalize() { float inv = reciprocalSqrt(lengthSquared()); x *= inv; y *= inv; z *= inv; return *this; }
};

/* v * 0.1f, one read form of the pooled literal per component. */
inline Vec3 scaleTenth(const Vec3& v) { return Vec3(v.x * lbl_803789C0, v.y * (*(const float*)&lbl_803789C0), v.z * (*(const float*)(unsigned long)&lbl_803789C0)); }
struct Collected { Vec3 point; float distance; Vec3 normal; char unknown1C[0xC]; ~Collected() {} };
struct Object_8007A280 {
    Word storage[0xA00];
    int count;
    Object_8007A280() : count(0) {}
    ~Object_8007A280() { for (int i = 0; i < count; ++i) reinterpret_cast<Collected*>(storage)[i].~Collected(); }
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
    Collected* nearest()
    {
        float best = lbl_80378A54;
        Collected* found = 0;
        Collected* c = reinterpret_cast<Collected*>(storage);
        for (int i = 0; i < count; ++i, ++c) {
            float d = c->distance;
            if (d < best) { best = d; found = c; }
        }
        return found;
    }
};
struct Sphere : Vec3 { float radius; Sphere(const Vec3& p, float r) { x = p.x; y = p.y; z = p.z; radius = r; } };

struct Camera {
    char unknown00[0xD0];
    int state;
    char unknownD4[4];
    Vec3 up;
    char unknownE4[5];
    signed char flagE9;
    char unknownEA[0xA];
    Vec3 current;
    Vec3 direction;
    char unknown10C[0x25];
    signed char flag131;
    char unknown132[0xEA];
    float height;
};

inline Node* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    if (tag == h.bits.tag) return m->entries[index].object;
    return 0;
}

extern "C" {
const Handle_801F7F10* fn_80235C08(Camera*);
int fn_80268918(Node*, const Sphere*, Object_8007A280*, unsigned long long, unsigned long long);
void fn_8007D4B4(Vec3*, const Vec3*, Vec3*, float, float);
void fn_80076D98(Camera*, Vec3*);
signed char fn_800793D0(Camera*, const Vec3&, const Vec3&);
}

extern "C" signed char fn_80079D3C(Camera* self, float delta)
{
    Handle_80020C04 target(*fn_80235C08(self));
    Object_8007A280 results;
    Sphere sphere(self->current, lbl_803789D0);
    if ((signed char)fn_80268918(resolve(target), &sphere, &results, 0x00008FE000000004ULL, 0ULL)) {
        self->flagE9 = 0;
        if (self->state == 0) {
            self->up = Vec3(lbl_8037899C, lbl_803789A4, lbl_8037899C);
            fn_8007D4B4(&self->direction, &self->up, &self->direction, lbl_80378A28, delta);
        }
        Collected* hit = results.nearest();
        self->current += (self->current - hit->point).normalize() * (lbl_803789C0 * delta);
        Object_8007A280 again;
        Sphere probe(self->current, lbl_803789C4);
        if ((signed char)fn_80268918(resolve(target), &probe, &again, 0x00008FE000000004ULL, 0ULL)) {
            self->flagE9 = 0;
            if (self->state == 0) {
                self->up = Vec3(lbl_8037899C, lbl_803789A4, lbl_8037899C);
                fn_8007D4B4(&self->direction, &self->up, &self->direction, lbl_80378A28, delta);
            }
            Collected* contact = again.nearest();
            self->current += contact->normal * (lbl_803789C4 - contact->distance);
            Vec3 position;
            fn_80076D98(self, &position);
            position.y += self->height;
            if (!fn_800793D0(self, contact->point + scaleTenth((contact->point - position).normalize()), position)) {
                const Vec3& push = probe - contact->point;
                const_cast<Vec3&>(push).normalize();
                self->current += push * (lbl_803789C4 - contact->distance);
            }
            self->flag131 = 1;
            return 1;
        }
    }
    return 0;
}
