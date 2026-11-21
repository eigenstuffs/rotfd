/* Grid hit-record merging (fn_80268CCC) and swept-sphere segment collection
   (fn_80268FE8), the companions of fn_80268918 (grid_sphere_collect.cpp).
   fn_80268CCC repeatedly picks the nearest remaining hit (distance 10000 =
   consumed) that is not behind an already accepted plane, appends it, and
   averages the normals of all hits within 1e-4 of it.  fn_80268FE8 builds a
   segment (origin, length, unit direction, radius) between two points and
   asks every grid candidate's object to test it.
   The difference vectors are bound through get() (a reference to the
   returned temporary), which keeps their dead stack copies and the
   unfused squared length of the original. */
#pragma fp_contract on
inline void* operator new(unsigned long, void* p) { return p; }
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
extern "C" const float lbl_8037B650;
extern "C" const float lbl_8037B654;
extern "C" const float lbl_8037B65C;
extern "C" const float lbl_8037B660;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    const Vec3& get() const { return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B650;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    void normalize() { float inv = reciprocalSqrt(lengthSquared()); x *= inv; y *= inv; z *= inv; }
};
extern "C" Vec3 game_vec3_zero;
struct Record {
    Vec3 point; float distance; Vec3 normal; void* object; unsigned long long token;
    Record() : object(0) {}
    ~Record() {}
};
struct RecordArray {
    Record data[256]; int count;
    Record& operator[](unsigned int i) { return data[i]; }
    void resize(int n)
    {
        if (n > count) { for (int i = count; i < n; ++i) new (&(*this)[i]) Record; }
        else if (n < count) { for (int i = count - 1; i >= n; --i) data[i].~Record(); }
        count = n;
    }
    void append() { if (count >= 256) new (&(*this)[255]) Record; else new (&(*this)[count++]) Record; }
};

extern "C" void fn_80268CCC(RecordArray* src, RecordArray* dst)
{
    dst->resize(0);
    for (int n = 0;; ++n) {
        int i;
        float best = lbl_8037B65C;
        int bestIndex = 0;
        for (i = 0; i < src->count; ++i) {
            Record& r = (*src)[i];
            if (lbl_8037B65C != r.distance && r.distance < best) {
                int j;
                signed char blocked = 0;
                for (j = 0; j < dst->count; ++j) {
                    Record& o = (*dst)[j];
                    if (o.normal.dot((r.point - o.point).get()) < lbl_8037B660) {
                        r.distance = lbl_8037B65C;
                        blocked = 1;
                        break;
                    }
                }
                if (!blocked) { best = r.distance; bestIndex = i; }
            }
        }
        if (lbl_8037B65C == best) return;
        dst->append();
        Record& out = (*dst)[n];
        Record& s = (*src)[bestIndex];
        out.point = s.point;
        out.distance = s.distance;
        out.object = s.object;
        out.token = s.token;
        out.normal = game_vec3_zero;
        for (int i = 0; i < src->count; ++i) {
            Record& r = (*src)[i];
            if (lbl_8037B65C != r.distance) {
                if ((r.point - out.point).get().length() < lbl_8037B660) {
                    out.normal += r.normal;
                    r.distance = lbl_8037B65C;
                }
            }
        }
        out.normal.normalize();
    }
}

extern "C" float fn_800AA52C(float, float);
extern "C" float fn_800AA53C(float, float);
struct Pair { float x, y; Pair(float a, float b) : x(a), y(b) {} };
struct Segment {
    Vec3 origin; float length; Vec3 direction; float radius;
    Segment(const Vec3& start, const Vec3& end, float r)
    {
        Vec3 o(start);
        Vec3 d = end - start;
        float len = d.length();
        origin = o;
        length = len;
        d *= lbl_8037B654 / len;
        direction = d;
        radius = r;
    }
};
struct Result { char unknown00[0x3C]; unsigned char hit; };
struct Handle { union { unsigned long value; struct { signed int generation : 8; signed int index : 24; } bits; }; };
struct Candidate {
    char unknown000[0x1C];
    Handle handle;
    Handle peer; char unknown024[0xFC]; unsigned long flags;
};
struct Storage { char unknown00[8]; };
struct Object : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void test(Candidate*, Object*, const Segment*, Result*, unsigned long long, unsigned long long);
};
struct Entry { Object* object; char unknown04[8]; signed char generation; char unknown0D[3]; signed char getGeneration() const { return generation; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; int fn_80266C78(void*, const Pair*, const Pair*); }
inline Object* resolve(const Handle& h)
{
    int index = h.bits.index; Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == h.bits.generation) return manager->entries[index].object;
    return 0;
}
inline Object* resolvePeer(const Handle& h)
{
    int index = h.bits.index; Manager* manager = lbl_801E9D24.manager;
    Entry& entry = manager->entries[index];
    int generation = entry.getGeneration();
    if (generation == h.bits.generation) return entry.object;
    return 0;
}
struct Grid { char unknown00[0x40]; Candidate* candidates[4096]; };
struct Self { char unknown0000[0x80BC]; Grid grid; Grid& getGrid() { return grid; } };

extern "C" unsigned char fn_80268FE8(Self* self, const Vec3* a, const Vec3* b, Result* result,
                                     unsigned long long firstMask, unsigned long long secondMask, float radius)
{
    result->hit = 0;
    Pair minimum(fn_800AA53C(a->x, b->x) - radius, fn_800AA53C(a->z, b->z) - radius);
    Pair maximum(radius + fn_800AA52C(a->x, b->x), radius + fn_800AA52C(a->z, b->z));
    Segment segment(*a, *b, radius);
    int count = fn_80266C78(&self->grid, &minimum, &maximum);
    Candidate** current = self->getGrid().candidates;
    for (int i = 0; i < count; ++i) {
        Candidate* candidate = *current++;
        if (candidate->flags & 0x10000) continue;
        if (!(candidate->flags & 0x40000)) continue;
        Object* object = resolve(candidate->handle);
        if (object) object->test(candidate, resolvePeer(candidate->peer), &segment, result, firstMask, secondMask);
    }
    return result->hit;
}
