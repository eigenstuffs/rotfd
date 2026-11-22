namespace pool_head { extern "C" { extern const float lbl_8037A2F0 = 1e-6f; } }
namespace part_801BD02C {
typedef unsigned long Word_801BD02C;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline void* operator new(unsigned long, void* p) { return p; }

extern "C" {
    extern const float lbl_8037A2D8;
    extern const float lbl_8037A2DC;
    extern const float lbl_8037A2E0;
    extern const float lbl_8037A2E8;
    extern const float lbl_8037A2EC;
    extern const float lbl_8037A2F0;
    extern const float lbl_8037A2F4;
}

struct Vec3_801BD02C {
    float x, y, z;
    Vec3_801BD02C() {}
    Vec3_801BD02C(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3_801BD02C(const Vec3_801BD02C& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3_801BD02C operator*(float s) const { return Vec3_801BD02C(x * s, y * s, z * s); }
    void operator+=(const Vec3_801BD02C& v) { x += v.x; y += v.y; z += v.z; }
    float dot(const Vec3_801BD02C& v) const { return x * v.x + y * v.y + z * v.z; }
    float length() const
    {
        float ax = x;
        float sq = ax * ax + y * y + z * z;
        float r;
        if (sq != lbl_8037A2D8) r = fastSqrt(sq);
        else r = lbl_8037A2D8;
        return r;
    }
};

inline Vec3_801BD02C operator+(const Vec3_801BD02C& a, const Vec3_801BD02C& b) { return Vec3_801BD02C(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3_801BD02C operator-(const Vec3_801BD02C& a, const Vec3_801BD02C& b) { return Vec3_801BD02C(a.x - b.x, a.y - b.y, a.z - b.z); }

extern "C" const Vec3_801BD02C game_vec3_zero;
extern "C" const Vec3_801BD02C game_vec4_zero;

struct Handle_801BD02C {
    union {
        Word_801BD02C word;
        struct { signed int tag : 8, index : 24; } bits;
    };
};

struct Entry_801BD02C {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};

struct Manager_801BD02C {
    char unknown00[8];
    Entry_801BD02C* entries;
};

extern "C" struct {
    char unknown00[0x118];
    Manager_801BD02C* manager;
} lbl_801E9D24;

inline void* resolve_801BD02C(const Handle_801BD02C& h)
{
    int index = h.bits.index;
    Manager_801BD02C* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    if (tag == h.bits.tag) return m->entries[index].object;
    return 0;
}

struct Ray_801BD02C {
    Vec3_801BD02C origin;
    float length;
    Vec3_801BD02C direction;
    float unknown1C;
    Ray_801BD02C(const Vec3_801BD02C& o, const Vec3_801BD02C& d, float l) : origin(o), direction(d) { length = l; }
    Ray_801BD02C() {}
};

struct HitObject_801BD02C {
    char unknown00[4];
    Handle_801BD02C handle;
    char unknown08[0x120 - 8];
    unsigned long flags;
};

struct HitOwner_801BD02C {
    char unknown00[0xC];
    Handle_801BD02C handle;
};

struct HitResult_801BD02C {
    Vec3_801BD02C point;
    char unknown0C[0x28 - 12];
    unsigned long long flags;
    HitObject_801BD02C* object;
    Word_801BD02C other, extra;
    signed char hit;
    char unknown3D[3];
    Word_801BD02C end;
    HitResult_801BD02C()
    {
        hit = 0;
        object = 0;
        other = 0;
        extra = 0;
        flags = 0;
    }
};

struct Storage_801BD02C { Word_801BD02C unknown00, unknown04; };

struct Owner_801BD02C : Storage_801BD02C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual Handle_801BD02C* owners(int);
    virtual void slotA0(); virtual void slotA4();
    virtual void slotA8(); virtual void slotAC(); virtual void slotB0(); virtual void slotB4();
    virtual void slotB8(); virtual void slotBC(); virtual void slotC0(); virtual void slotC4();
    virtual void slotC8(); virtual void slotCC(); virtual void slotD0(); virtual void slotD4();
    virtual void slotD8(); virtual void slotDC(); virtual void slotE0(); virtual void slotE4();
    virtual void slotE8(); virtual void slotEC(); virtual void slotF0(); virtual void slotF4();
    virtual void slotF8(); virtual void slotFC(); virtual void slot100(); virtual void slot104();
    virtual void slot108(); virtual void slot10C();
    virtual Vec3_801BD02C move(const Vec3_801BD02C&, void*, void*, int);
    virtual void contact(HitResult_801BD02C*, void*, int);
    virtual void setState(int, int);
};

inline bool differs_801BD02C(Owner_801BD02C* self, int index, const HitResult_801BD02C& hit)
{
    HitOwner_801BD02C* owner = (HitOwner_801BD02C*)resolve_801BD02C(*self->owners(index));
    return resolve_801BD02C(hit.object->handle) != resolve_801BD02C(owner->handle);
}

extern "C" signed char fn_80269230(void*, const Ray_801BD02C&, HitResult_801BD02C*, unsigned long long, unsigned long long);

#pragma fp_contract off
extern "C" Vec3_801BD02C fn_801BD02C(Owner_801BD02C* self, void* world, const Vec3_801BD02C& pos,
                                     const Vec3_801BD02C& offset, void* arg8, void* arg9, int index,
                                     signed char direct)
{
    if (direct) return self->move(pos, arg8, arg9, index);
    self->setState(1, index);
    HitResult_801BD02C hit;
    float len = offset.length();
    Ray_801BD02C ray;
    ray.origin = pos + offset;
    ray.direction.x = *(const float*)&lbl_8037A2D8; ray.direction.y = lbl_8037A2DC; ray.direction.z = *(const float*)(unsigned long)&lbl_8037A2D8;
    ray.length = lbl_8037A2E0 + len;
    if (fn_80269230(world, ray, &hit, 0x0001860000000002ULL, 8ULL)) {
        hit.point.x -= offset.x;
        hit.point.z -= offset.z;
        if ((hit.object->flags & 0x200) && differs_801BD02C(self, index, hit)) {
            self->contact(&hit, arg8, index);
        } else if (hit.object->flags & 0x800) {
            self->contact(&hit, arg8, index);
        }
    }
    return game_vec3_zero;
}
#pragma fp_contract reset

struct Sphere_801BD02C {
    Vec3_801BD02C center;
    float radius;
    Sphere_801BD02C(const Vec3_801BD02C& c, float r) : center(c), radius(r) {}
};

struct Record_801BD02C {
    char unknown00[0xC];
    float depth;
    Vec3_801BD02C normal;
    char unknown1C[0x28 - 0x1C];
    ~Record_801BD02C() {}
};

struct Pool_801BD02C {
    unsigned long storage[0xA00];
    int count;
    Pool_801BD02C() : count(0) {}
    Record_801BD02C* records() { return reinterpret_cast<Record_801BD02C*>(storage); }
    Record_801BD02C& operator[](unsigned int i) { return records()[i]; }
    ~Pool_801BD02C() { for (int i = 0; i < count; ++i) (*this)[i].~Record_801BD02C(); }
};

struct Candidate_801BD02C {
    char unknown00[0x1C];
    Handle_801BD02C handle;
    Handle_801BD02C peer;
};

struct CollectObject_801BD02C : Storage_801BD02C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void test(Candidate_801BD02C*, CollectObject_801BD02C*, const Sphere_801BD02C*, Pool_801BD02C*,
                      unsigned long long, unsigned long long);
};

struct Collider_801BD02C : Storage_801BD02C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual signed char bounds(Sphere_801BD02C*, int, int);
};

extern "C" void fn_80268CCC(Pool_801BD02C*, Pool_801BD02C*);


}
namespace part_801BD2F8 {
/* fn_801BD2F8: sweep the owner's two bound spheres (scaled by 1.2) against the
 * candidate's collision object, merge the hits and push `out` away along the
 * first contact normal.  Second half of the 801BD02C translation unit.
 *
 * Probe: GC/1.3.2 --opt p --flags "-fp_contract on"  ->  EXACT-MOD-POOL.
 * The 2.0f literal is load-bearing (an extern colours the scale factor after
 * the penetration temp): the unit must own lbl_8037A2F4 (.sdata2 0x8037A2F4,
 * 4 bytes, 2.0f).  Other constants stay extern.
 *
 * Load-bearing spellings:
 *  - Manager::get() reads the entry through at(i) twice (tag test via
 *    Entry::is(), then object).  That reproduces the original's sharing of the
 *    handle resolves: the first resolve after each bounds() call keeps its own
 *    manager->entries load, later ones share one reload, entry tags are
 *    reloaded every time, and the address of the peer entry is evaluated
 *    after the stack argument stores.
 *  - `handle` is a non-const pointer (keeps its loads below the stack stores).
 *  - sphere centre adjusted with operator+=; hit record re-read through
 *    merged[0] at every use; if/else with `return 1` in the else arm.
 */
typedef unsigned long Word_801BD02C;

extern "C" {
    extern const float lbl_8037A2E8; /* 1.0f */
    extern const float lbl_8037A2EC; /* 1.2f */
    extern const float lbl_8037A2F0; /* 1e-6f */
}

struct Vec3_801BD02C {
    float x, y, z;
    Vec3_801BD02C() {}
    Vec3_801BD02C(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3_801BD02C(const Vec3_801BD02C& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3_801BD02C operator*(float s) const { return Vec3_801BD02C(x * s, y * s, z * s); }
    void operator+=(const Vec3_801BD02C& v) { x += v.x; y += v.y; z += v.z; }
    float dot(const Vec3_801BD02C& v) const { return x * v.x + y * v.y + z * v.z; }
};

inline Vec3_801BD02C operator+(const Vec3_801BD02C& a, const Vec3_801BD02C& b) { return Vec3_801BD02C(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3_801BD02C operator-(const Vec3_801BD02C& a, const Vec3_801BD02C& b) { return Vec3_801BD02C(a.x - b.x, a.y - b.y, a.z - b.z); }

extern "C" const Vec3_801BD02C game_vec4_zero;

struct Handle_801BD02C {
    signed char tag;
    signed int index : 24;
};

struct Entry_801BD02C {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char is(signed char t) const { return tag == t; }
};

struct Manager_801BD02C {
    char unknown00[8];
    Entry_801BD02C* entries;
    Entry_801BD02C* at(int i) { return &entries[i]; }
    void* get(const Handle_801BD02C& h)
    {
        int i = h.index;
        if (at(i)->is(h.tag)) return at(i)->object;
        return 0;
    }
};

extern "C" struct {
    char unknown00[0x118];
    Manager_801BD02C* manager;
} lbl_801E9D24;

#define RES(h) lbl_801E9D24.manager->get(h)

struct Storage_801BD02C { Word_801BD02C unknown00, unknown04; };

struct Sphere_801BD02C {
    Vec3_801BD02C center;
    float radius;
    Sphere_801BD02C(const Vec3_801BD02C& c, float r) : center(c), radius(r) {}
};

struct Record_801BD02C {
    char unknown00[0xC];
    float depth;
    Vec3_801BD02C normal;
    char unknown1C[0x28 - 0x1C];
    ~Record_801BD02C() {}
};

struct Pool_801BD02C {
    unsigned long storage[0xA00];
    int count;
    Pool_801BD02C() : count(0) {}
    Record_801BD02C* records() { return reinterpret_cast<Record_801BD02C*>(storage); }
    Record_801BD02C& operator[](unsigned int i) { return records()[i]; }
    ~Pool_801BD02C() { for (int i = 0; i < count; ++i) (*this)[i].~Record_801BD02C(); }
};

struct Candidate_801BD02C {
    char unknown00[0x1C];
    Handle_801BD02C handle;
    Handle_801BD02C peer;
};

struct CollectObject_801BD02C : Storage_801BD02C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void test(Candidate_801BD02C*, CollectObject_801BD02C*, const Sphere_801BD02C*, Pool_801BD02C*,
                      unsigned long long, unsigned long long);
};

struct Collider_801BD02C : Storage_801BD02C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual signed char bounds(Sphere_801BD02C*, int, int);
};

extern "C" void fn_80268CCC(Pool_801BD02C*, Pool_801BD02C*);


extern "C" signed char fn_801BD2F8(Collider_801BD02C* self, Handle_801BD02C* handle, const Vec3_801BD02C* from,
                                   const Vec3_801BD02C* to, Vec3_801BD02C* out)
{
    Sphere_801BD02C s(game_vec4_zero, lbl_8037A2E8);
    if (!self->bounds(&s, 0, 0)) return 0;
    s.center += *to - *from;
    s.radius *= lbl_8037A2EC;
    Pool_801BD02C collected;
    CollectObject_801BD02C* obj = (CollectObject_801BD02C*)RES(((Candidate_801BD02C*)RES(*handle))->handle);
    if (obj == 0) return 0;
    obj->test((Candidate_801BD02C*)RES(*handle),
              (CollectObject_801BD02C*)RES(((Candidate_801BD02C*)RES(*handle))->peer),
              &s, &collected, 0x00008E0000000000ULL, 0);
    Sphere_801BD02C s2(game_vec4_zero, lbl_8037A2E8);
    if (self->bounds(&s2, 1, 0)) {
        s2.center += *to - *from;
        s2.radius *= lbl_8037A2EC;
        obj->test((Candidate_801BD02C*)RES(*handle),
                  (CollectObject_801BD02C*)RES(((Candidate_801BD02C*)RES(*handle))->peer),
                  &s2, &collected, 0x00008E0000000000ULL, 0);
    }
    Pool_801BD02C merged;
    fn_80268CCC(&collected, &merged);
    if (merged.count != 0) {
        if (out->dot(merged[0].normal) <= lbl_8037A2F0 || out->x * out->x + out->z * out->z < lbl_8037A2F0) {
            float depth = merged[0].depth;
            if (depth < *(const volatile float*)&lbl_8037A2F0) {
                *out += merged[0].normal * 2.0f * (s.radius - depth);
            } else {
                *out += merged[0].normal * 2.0f * depth;
            }
        }
    } else {
        return 1;
    }
    return 0;
}

}
extern "C" {
/* Partial original text: only observed empty hooks and scalar results. */

int fn_801BD948(void* receiver) { (void)receiver; return 0; }

}
