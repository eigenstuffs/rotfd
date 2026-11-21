/* fn_800E5610: effect position update for an effect owner.
 * When the primary effect exists, it takes the position of the actor's
 * query(0) node's parent, transforms it by the query(0) node's world matrix,
 * raises it by lbl_803797DC and moves the effect there. The secondary effect
 * is then started (fn_80255678) while the global state mode is 1 or 2 and
 * stopped (fn_80255588) otherwise. */
#pragma fp_contract on
typedef unsigned long Word;
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Matrix { float m[16]; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Prefix { char unknown00[8]; };
struct Node : Prefix {
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
    virtual const Handle& query(int); /* 0x9C */
    char unknown0C[0x14];
    Handle parent; /* 0x20 */
    char unknown24[8];
    Vec3 position; /* 0x2C */
    char unknown38[0x124 - 0x38];
    Matrix* matrix; /* 0x124 */
};
struct Entry {
    Node* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
inline Node* resolve(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
struct Self {
    char unknown00[8];
    Node* actor;
    char unknown0C[0x3C];
    void* effect;    /* 0x48 */
    void* secondary; /* 0x4C */
};
struct State {
    char unknown00[0xD0];
    int mode;
    bool active() const
    {
        bool result = false;
        if (mode == 1 || mode == 2)
            result = true;
        return result;
    }
};
extern "C" {
void fn_80254BB4(void*, const Vec3&);
State* fn_8007D074();
void fn_80255678(void*);
void fn_80255588(void*);
extern const float lbl_803797DC;
}
extern "C" void fn_800E5610(Self* self)
{
    if (self->effect) {
        Vec3 position = resolve(resolve(self->actor->query(0))->parent)->position;
        const Matrix* M = resolve(self->actor->query(0))->matrix;
        const Vec3& v = position;
        float x = M->m[12] + (M->m[0] * v.x + M->m[4] * v.y + M->m[8] * v.z),
              y = M->m[13] + (M->m[1] * v.x + M->m[5] * v.y + M->m[9] * v.z),
              z = M->m[14] + (M->m[2] * v.x + M->m[6] * v.y + M->m[10] * v.z);
        position = Vec3(x, y, z);
        position.y += lbl_803797DC;
        fn_80254BB4(self->effect, position);
    }
    if (self->secondary) {
        if (fn_8007D074()->active())
            fn_80255678(self->secondary);
        else
            fn_80255588(self->secondary);
    }
}
