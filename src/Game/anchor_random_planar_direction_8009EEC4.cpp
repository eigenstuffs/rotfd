/* fn_8009EEC4: pick a random point within distance (0x3B0) of the anchor
 * (0x398) on the XZ plane and store the planar unit direction from the
 * owner geometry position to it at 0x3A4. The original literal 0.0f is the
 * pooled label lbl_80378DD8; the y term of the length (0*0) was folded by the
 * compiler, so the source adds the label directly. reciprocalSqrt is the
 * engine frsqrte helper (see owner_planar_direction_8009A6D4.cpp). */
typedef unsigned long Word;
extern "C" const float lbl_80378DD8; /* 0.0f */
extern "C" const float lbl_80378E28; /* 2*pi */
extern "C" {
float fn_801F1200();          /* random float */
float fn_8028506C(float);     /* cosf */
float fn_80284FA8(float);     /* sinf */
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
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    void normalize()
    {
        float inv = reciprocalSqrt(lengthSquared());
        x *= inv;
        y *= inv;
        z *= inv;
    }
};


struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Geometry { char unknown00[0x30]; Vec3 position; };
struct Resource {
    char unknown00[0x120];
    unsigned int flags;                     /* 0x120 */
    Geometry* geometry;                     /* 0x124 */
};
struct Entry { Resource* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

inline Resource* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

struct Prefix { char unknown00[8]; };
struct Agent : Prefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual const Handle* getHandle(int);   /* vtable +0x9C */
    char unknown0C[0x398 - 0xC];
    Vec3 anchor;                            /* 0x398 */
    Vec3 direction;                         /* 0x3A4 */
    float distance;                         /* 0x3B0 */
};

extern "C" void fn_8009EEC4(Agent* self)
{
    if (!(resolve(*self->getHandle(0))->flags & 0x10000)) {
        float radius = self->distance;
        float u = fn_801F1200();
        float r = u * radius;
        float angle = lbl_80378E28 * fn_801F1200();
        Vec3 o;
        o.x = r * fn_8028506C(angle);
        o.y = lbl_80378DD8;
        o.z = r * fn_80284FA8(angle);
        Vec3 t(self->anchor.x + o.x, self->anchor.y + o.y, self->anchor.z + o.z);
        float tx = t.x; float tz = t.z;
        Geometry* g = resolve(*self->getHandle(0))->geometry;
        Vec3 d(tx - g->position.x, lbl_80378DD8, tz - g->position.z);
        float inv = reciprocalSqrt(d.x * d.x + d.y + d.z * d.z);
        d.x *= inv; d.y *= inv; d.z *= inv;
        self->direction = d;
    }
}
