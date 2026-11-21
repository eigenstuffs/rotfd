/* Proximity trigger (fn_80039BC8): after the base update, while the state
   object's link handle at 0x1B0 is not valid, compare each member's matrix
   position with the related owner's position; the first member closer than
   the shared range constant posts event 0x79, notifies the state object
   (slot 0x34) and the owner itself (slot 0x38).

   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, no frsp), written as minimal inline
   asm statements in the vector helper as in range_attach_toggle_80070BCC.cpp.
   The two float constants were literals pooled with the rest of the
   translation unit; the pointer reads keep the shared labels while reloading
   them like literals. The related owner builds its position directly from
   its matrix, while the members go through the matrix accessor and bind the
   result to a const reference (the dead stack copy at 0x8). */
typedef unsigned long Word;

extern "C" {
extern const float lbl_80378420; /* 0.0f */
extern const float lbl_80378470; /* 1.64f */
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const
    {
        Vec3 r(x - o.x, y - o.y, z - o.z);
        return r;
    }
    float length() const
    {
        register float sq = x * x + y * y + z * z;
        register float result = *(const float*)&lbl_80378420;
        if (sq != result) {
            asm { frsqrte f4, sq }
            asm { fres result, f4 }
        }
        return result;
    }
    float distance(const Vec3& o) const { return (*this - o).length(); }
};

struct Matrix {
    float m[16];
    Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); }
};

struct Handle_801F7F10 {
    union {
        Word word;
        struct { signed int tag : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

extern "C" unsigned int fn_801F7EB8(const Handle_801F7F10*);

struct NodePrefix { char unknown00[4]; Handle_801F7F10 self; };
struct Node : NodePrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void notify34();
    virtual void slot38();
    char unknown0C[0x118];
    Matrix* matrix;
    char unknown128[0x88];
    Handle_801F7F10 link1B0;
    Vec3 getPos() const { return Vec3(matrix->m[12], matrix->m[13], matrix->m[14]); }
    signed char linked() const { return fn_801F7EB8(&link1B0) != 0; }
};

struct Member {
    char unknown00[0x124];
    Matrix* matrix;
    Vec3 getPos() const { return matrix->getPos(); }
};

struct Entry {
    Node* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Context { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

inline Node* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

struct Self : NodePrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void trigger38();
    char unknown0C[0x4C];
    Handle_801F7F10 related58;
    char unknown5C[0x14];
    Handle_801F7F10 state70;
    char unknown74[0x18];
    Member* members[20];
    int memberCount;
};

extern "C" {
void fn_8025A244(Self*);
void fn_80255D88(Self*, int, int, int, int);
}

extern "C" void fn_80039BC8(Self* self)
{
    fn_8025A244(self);
    signed char linked = resolve(self->state70)->linked();
    if (linked)
        return;
    Vec3 base = resolve(self->related58)->getPos();
    for (int i = 0; i < self->memberCount; ++i) {
        const Vec3& pos = self->members[i]->getPos();
        if (pos.distance(base) < *(const float*)&lbl_80378470) {
            fn_80255D88(self, 0x79, 0, 0, 0);
            resolve(self->state70)->notify34();
            self->trigger38();
            return;
        }
    }
}
