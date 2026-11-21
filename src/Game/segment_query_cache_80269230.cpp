/* Segment queries against the collision grid: fn_80269230 is the cached
   query (a 60-entry ring of previous segments/results, compared with the
   engine's 1e-6 vector equality), fn_80269818 the uncached first-hit query.
   Both are deferred by the compiler (the template handle resolve, and the
   compiler-generated HitResult/Segment assignment), and deferred functions
   are emitted in reverse definition order, so fn_80269818 is defined first
   here to produce the original address order. */
#pragma fp_contract on
extern "C" double __fabs(double);
extern "C" const float lbl_8037B658;
inline float absf(float x) { return (float)__fabs(x); }
inline int pairEqual(float x, float y)
{
    int result = 0;
    if ((float)__fabs(x) < lbl_8037B658) {
        if ((float)__fabs(y) < lbl_8037B658) result = 1;
    }
    return result;
}
inline signed char vecEqual(float x, float y, float z)
{
    signed char result = 0;
    if (pairEqual(x, y) && (float)__fabs(z) < lbl_8037B658) result = 1;
    return result;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    signed char close(const Vec3& o) const { return vecEqual(x - o.x, y - o.y, z - o.z); }
};
struct Segment {
    Vec3 origin; float length; Vec3 direction; float radius;
    Segment() {}
    Segment(const Segment& o) : origin(o.origin), length(o.length), direction(o.direction), radius(o.radius) {}
};
/* 0x48-byte segment hit (layout as in camera_bitmap_capture_80235D54.cpp). */
struct HitResult {
    Vec3 point; float distance; Vec3 normal; void* unknown1C;
    float unknown20, unknown24; unsigned long long flags;
    void* object; void* other; void* extra; signed char hit; unsigned long end;
};
struct Pair { float x, y; Pair(float a, float b) : x(a), y(b) {} };
extern "C" float fn_800AA52C(float, float);
extern "C" float fn_800AA53C(float, float);
struct Handle { union { unsigned long value; struct { signed int generation : 8; signed int index : 24; } bits; }; };
struct Candidate {
    char unknown000[0x1C];
    Handle handle;
    Handle peer; char unknown024[0xFC]; unsigned long flags;
};
struct Storage { char unknown00[8]; };
struct Object : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(); virtual void slot38();
    virtual signed char test(Candidate*, Object*, const Segment*, HitResult*, unsigned long long, unsigned long long);
};
struct Entry { Object* object; char unknown04[8]; signed char generation; char unknown0D[3]; signed char getGeneration() const { return generation; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; int fn_80266C78(void*, const Pair*, const Pair*); }
template <class T> inline T* resolve(const Handle& h)
{
    int index = h.bits.index; Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == h.bits.generation) return (T*)manager->entries[index].object;
    return 0;
}
template <class T> inline T* resolvePeer(const Handle& h)
{
    int index = h.bits.index; Manager* manager = lbl_801E9D24.manager;
    Entry& entry = manager->entries[index];
    int generation = entry.getGeneration();
    if (generation == h.bits.generation) return (T*)entry.object;
    return 0;
}
struct Grid { char unknown00[0x40]; Candidate* candidates[4096]; };
/* Collision world: spatial grid at 0x80BC and a 60-entry ring cache of
   segment queries (keys) and their results (values) sharing count/start. */
struct Self {
    char unknown0000[0x80BC]; Grid grid; char unknownC0FC[0xC194 - 0xC0FC];
    Segment keys[60];
    HitResult values[60];
    unsigned long count;
    unsigned long start;
    Grid& getGrid() { return grid; }
    Segment& key(unsigned long i) { return keys[(start + i) % 60]; }
    HitResult& value(unsigned long i) { return values[(start + i) % 60]; }
};

extern "C" signed char fn_80269818(Self* self, const Segment* segment, HitResult* result,
                                   unsigned long long firstMask, unsigned long long secondMask)
{
    result->hit = 0;
    Vec3 start(segment->origin);
    Vec3 end(segment->origin.x + segment->direction.x * segment->length, segment->origin.y + segment->direction.y * segment->length, segment->origin.z + segment->direction.z * segment->length);
    float minX = fn_800AA53C(start.x, end.x);
    float minZ = fn_800AA53C(start.z, end.z);
    Pair minimum(minX, minZ);
    float maxX = fn_800AA52C(start.x, end.x);
    float maxZ = fn_800AA52C(start.z, end.z);
    Pair maximum(maxX, maxZ);
    int count = fn_80266C78(&self->grid, &minimum, &maximum);
    Candidate** current = self->getGrid().candidates;
    for (int j = 0; j < count; ++j) {
        Candidate* candidate = *current++;
        if (candidate->flags & 0x10000) continue;
        if (!(candidate->flags & 0x40000)) continue;
        Object* object = resolve<Object>(candidate->handle);
        if (object) {
            object->test(candidate, resolvePeer<Object>(candidate->peer), segment, result, firstMask, secondMask);
            if (result->hit) return 1;
        }
    }
    return result->hit;
}

extern "C" signed char fn_80269230(Self* self, const Segment* segment, HitResult* result,
                                   unsigned long long firstMask, unsigned long long secondMask)
{
    for (unsigned long i = 0; i < self->count; ++i) {
        if (self->key(i).origin.close(segment->origin) && self->key(i).direction.close(segment->direction)) {
            *result = self->value(i);
            return result->hit;
        }
    }
    if (self->count == 59) self->start++;
    else self->count++;
    self->key(self->count) = *segment;
    result->hit = 0;
    Vec3 start(segment->origin);
    Vec3 end(segment->origin.x + segment->direction.x * segment->length, segment->origin.y + segment->direction.y * segment->length, segment->origin.z + segment->direction.z * segment->length);
    float minX = fn_800AA53C(start.x, end.x);
    float minZ = fn_800AA53C(start.z, end.z);
    Pair minimum(minX, minZ);
    float maxX = fn_800AA52C(start.x, end.x);
    float maxZ = fn_800AA52C(start.z, end.z);
    Pair maximum(maxX, maxZ);
    int count = fn_80266C78(&self->grid, &minimum, &maximum);
    Segment local = *segment;
    Candidate** current = self->getGrid().candidates;
    for (int j = 0; j < count; ++j) {
        Candidate* candidate = *current++;
        if (candidate->flags & 0x10000) continue;
        if (!(candidate->flags & 0x40000)) continue;
        Object* object = resolve<Object>(candidate->handle);
        if (object) {
            if (object->test(candidate, resolvePeer<Object>(candidate->peer), &local, result, firstMask, secondMask))
                local.length = result->distance;
        }
    }
    self->value(self->count) = *result;
    return result->hit;
}

