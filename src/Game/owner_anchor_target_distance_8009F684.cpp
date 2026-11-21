/* Planar (XZ) distance from the agent's anchor at 0x398 to the matrix
   position of the resource resolved from virtual getHandle(0) (slot 0x9C).
   The anchor coordinates are read into locals before the virtual call
   (x first, then z). The engine square root is the bare reciprocal of a
   reciprocal-square-root estimate (frsqrte into f4, then fres), written
   as the shared minimal inline asm math helper. */
typedef unsigned long Word;
extern "C" const float lbl_80378DD8;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec2 {
    float x, y;
    Vec2(float ax, float ay) : x(ax), y(ay) {}
    float distance(const Vec2& o) const
    {
        float dy = y - o.y;
        float dx = x - o.x;
        float sq = dx * dx + dy * dy;
        float r = lbl_80378DD8;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Vec3 { float x, y, z; };

struct Matrix {
    float m[16];
};

struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Resource { char unknown00[0x124]; Matrix* matrix; };
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
    virtual const Handle* getHandle(int);
    char unknown0C[0x398 - 0xC];
    Vec3 anchor;
};

extern "C" float fn_8009F684(Agent* self)
{
    float ax = self->anchor.x;
    float az = self->anchor.z;
    Vec2 a(ax, az);
    Matrix* m = resolve(*self->getHandle(0))->matrix;
    return a.distance(Vec2(m->m[12], m->m[14]));
}
