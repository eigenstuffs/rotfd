/* Actor movement step with a pinned-velocity case (fn_8009DC60).
 * Resolves the handle from virtual slot 0x9C; unless the resolved object's word at +0x120 has
 * bit 0x10000 set, runs fn_8021F5BC, then (when any of flags 0x7E000000 is set) delegates to
 * fn_8021EC10, else next = position + velocity (+0x144) * delta and direction = the local z
 * axis transformed by the basis at +0x30 of the re-resolved object. With bit 0x10000 set the
 * velocity is first reset to game_vec3_zero. Same body shape as fn_80091ECC.
 * Matching notes: the original read pooled literals (0.0f at lbl_80378DD8, 1.0f at
 * lbl_80378DDC); each use in the axis transform takes a distinct read form so it is not CSE'd. */
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
extern const float lbl_80378DD8; /* 0.0f */
extern const float lbl_80378DDC; /* 1.0f */
extern Vec game_vec3_zero;
}
struct Matrix {
    float m[9];
    Vec axisZ() const {
        float x = m[0] * lbl_80378DD8 + m[3] * *(const float*)&lbl_80378DD8 + m[6] * lbl_80378DDC;
        float y = m[1] * *(const float*)(unsigned long)&lbl_80378DD8 + m[4] * *(const float*)(long)&lbl_80378DD8 + m[7] * *(const float*)&lbl_80378DDC;
        float z = m[2] * *(const float*)(unsigned int)&lbl_80378DD8 + m[5] * *(const float*)(int)&lbl_80378DD8 + m[8] * *(const float*)(unsigned long)&lbl_80378DDC;
        return Vec(x, y, z);
    }
};
struct Node { char unknown00[0x30]; Matrix matrix; char unknown54[0xCC]; Word flags; };
struct Entry { Node* object; Word unknown04, unknown08; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; }
inline Node* resolve(const Handle& h) {
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
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
};
extern "C" void fn_8021F5BC(Actor*, const Vec*, Vec*, Vec*, int, float);
extern "C" void fn_8021EC10(Actor*, const Vec*, Vec*, Vec*, float);
extern "C" void fn_8009DC60(Actor* self, const Vec* position, Vec* next, Vec* direction, int mode, float delta) {
    if (!(resolve(*self->getHandle(0))->flags & 0x10000)) {
        fn_8021F5BC(self, position, next, direction, mode, delta);
        if (self->flags & 0x7E000000ULL) {
            fn_8021EC10(self, position, next, direction, delta);
        } else {
            *next = *position + self->velocity * delta;
            *direction = resolve(*self->getHandle(0))->matrix.axisZ();
        }
    } else {
        self->velocity = game_vec3_zero;
        *next = *position + self->velocity * delta;
        *direction = resolve(*self->getHandle(0))->matrix.axisZ();
    }
}
