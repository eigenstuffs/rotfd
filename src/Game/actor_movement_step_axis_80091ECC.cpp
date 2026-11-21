/* Actor movement step (fn_80091ECC).
 * Clears the transient flag bits (keeps 0x1000003FFFFFFE3F); while any of 0x7E000000 is set the
 * step is delegated to fn_8021EC10. Otherwise the next position is position + velocity (+0x144)
 * * delta, and the direction is either the override vector (+0x44C, when +0x448 == 1) or the
 * local z axis (0, 0, 1) transformed by the basis at +0x30 of the object whose handle the
 * virtual slot 0x9C returns.
 * Matching notes: the original multiplied the basis by pooled literals, which the compiler
 * reloads per use; common subexpression elimination is off for this function and the axis
 * constants are read at each use, so the backend merges them into the original two loads.
 * With CSE off the handle resolve keeps the entry pointer (&entries[index]) explicitly. */
#pragma fp_contract on
typedef unsigned long Word;
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec operator*(float v) const { return Vec(x * v, y * v, z * v); }
    Vec operator+(const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
    Vec& operator=(const Vec& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
struct Handle { signed int tag : 8; signed int index : 24; };
extern "C" {
extern const float lbl_80378BAC; /* 0.0f */
extern const float lbl_80378BE8; /* 1.0f */
}
struct Matrix {
    float m[9];
    Vec axisZ() const {
        float x = m[0] * lbl_80378BAC + m[3] * lbl_80378BAC + m[6] * lbl_80378BE8;
        float y = m[1] * lbl_80378BAC + m[4] * lbl_80378BAC + m[7] * lbl_80378BE8;
        float z = m[2] * lbl_80378BAC + m[5] * lbl_80378BAC + m[8] * lbl_80378BE8;
        return Vec(x, y, z);
    }
};
struct Node { char unknown00[0x30]; Matrix matrix; };
struct Entry { Node* object; Word unknown04, unknown08; signed char generation; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; }
inline Node* resolve(const Handle& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.index];
    if (e->generation == h.tag) return e->object;
    return 0;
}
struct Header { char unknown00[8]; };
struct Actor : Header {
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
    virtual const Handle* getHandle(int);
    char unknown0C[0x24];
    unsigned long long flags;
    char unknown38[0x10C];
    Vec velocity;
    char unknown150[0x2F8];
    unsigned char overrideEnabled;
    char unknown449[3];
    Vec overrideDirection;
};
extern "C" void fn_8021EC10(Actor*, const Vec*, Vec*, Vec*, float);
#pragma opt_common_subs off
extern "C" void fn_80091ECC(Actor* self, const Vec* position, Vec* next, Vec* direction, float delta) {
    self->flags &= 0x1000003FFFFFFE3FULL;
    if (self->flags & 0x7E000000ULL) {
        fn_8021EC10(self, position, next, direction, delta);
    } else {
        *next = *position + self->velocity * delta;
        if ((int)self->overrideEnabled == 1) {
            *direction = self->overrideDirection;
        } else {
            Node* object = resolve(*self->getHandle(0));
            *direction = object->matrix.axisZ();
        }
    }
}
#pragma opt_common_subs reset
