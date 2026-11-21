/* Planar (XZ) offset from the matrix position of the resource resolved from
   the target's owner handle (0x58) to the matrix position of the resource
   resolved from virtual getHandle(0) (slot 0x9C), written to *out,
   normalized in place, and the planar length returned. A zero-length offset
   becomes (0, 1e-5). Same Vec2 helpers as
   owner_target_planar_offset_8009F3E8.cpp and fn_8009F558. */
typedef unsigned long Word;
extern "C" const float lbl_80378DD8; /* 0.0f */
extern "C" const float lbl_80378DDC; /* 1.0f */
extern "C" const float lbl_80378E30; /* 1e-5f */

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
    float length() const
    {
        float sq = x * x + y * y;
        float r = lbl_80378DD8;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float normalize()
    {
        float len = length();
        const float zero = *(const float*)&lbl_80378DD8;
        if (zero != len) {
            float inv = lbl_80378DDC / len;
            x *= inv;
            y *= inv;
        } else {
            x = zero;
            y = lbl_80378E30;
        }
        return len;
    }
};

struct Matrix { float m[16]; };

struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Resource {
    char unknown00[0x58];
    Handle owner;                           /* 0x58 */
    char unknown5C[0x124 - 0x5C];
    Matrix* matrix;                         /* 0x124 */
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
};

extern "C" float fn_8009F278(Agent* self, Resource* target, Vec2* out)
{
    Matrix* tm = resolve(target->owner)->matrix;
    Vec2 t(tm->m[12], tm->m[14]);
    Matrix* m = resolve(*self->getHandle(0))->matrix;
    Vec2 s(m->m[12], m->m[14]);
    out->x = s.x - t.x;
    out->y = s.y - t.y;
    return out->normalize();
}
