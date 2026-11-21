/* Paired side-target placement (fn_800E41B4).

   The actor at +0x08 gives its matrix node (virtual slot 0x9C, handle
   resolved through the engine manager); the node's 3x3 basis at +0x30 is the
   parent basis.  For each side node (+0x4C, +0x50) the side's transform
   translation (+0x124, translation at +0x30) and the side basis' Y axis
   (basis * (0,1,0)) are rotated into the parent basis; the direction is
   scaled by 0.3333.  The effects behind targets[0] and targets[1] (handle
   array at +0x48) are then placed (fn_80254BB4) at actor position (virtual
   slot 0xB0) + scaled direction + rotated translation.

   Pooled literals: the original used float literals 0.0f/1.0f/0.3333f from
   the shared .sdata2 pool (lbl_803797C8, lbl_803797CC, lbl_803797D0).  Each
   literal use was its own pool load, merged only by the backend, and the
   second side reloads them.  Every use before the first call is therefore
   written with its own read form: within one side the forms only need to be
   locally distinct, while the two sides use disjoint CSE classes (plain /
   *(const float*)& and pointer casts / (int)& for the first side; the
   (unsigned long)&, (long)& and (unsigned int)& families for the second). */
#pragma fp_contract on

extern "C" const float lbl_803797C8, lbl_803797CC, lbl_803797D0;

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
    Vec operator+(const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
};

struct Matrix {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vec transform(float x, float y, float z) const
    {
        Vec r;
        r.x = m00 * x + m10 * y + m20 * z;
        r.y = m01 * x + m11 * y + m21 * z;
        r.z = m02 * x + m12 * y + m22 * z;
        return r;
    }
    /* transform(0.0f, 1.0f, 0.0f) for the first side, one pool read per use. */
    Vec firstYAxis() const
    {
        Vec r;
        r.x = m00 * lbl_803797C8 + m10 * lbl_803797CC + m20 * *(const float*)(int)&lbl_803797C8;
        r.y = m01 * *(const float*)&lbl_803797C8 + m11 * *(const float*)&lbl_803797CC +
              m21 * ((const float*)&lbl_803797C8)[0];
        r.z = m02 * *(const float*)(const void*)&lbl_803797C8 + m12 * *(const float*)(int)&lbl_803797CC +
              m22 * *(const float*)(const char*)&lbl_803797C8;
        return r;
    }
    /* transform(0.0f, 1.0f, 0.0f) for the second side (reloaded pool values). */
    Vec secondYAxis() const
    {
        Vec r;
        r.x = m00 * *(const float*)(unsigned long)&lbl_803797C8 + m10 * *(const float*)(unsigned long)&lbl_803797CC +
              m20 * *(const float*)(long)&lbl_803797C8;
        r.y = m01 * *(const float*)(unsigned int)&lbl_803797C8 + m11 * *(const float*)(long)&lbl_803797CC +
              m21 * *(const float*)((unsigned long)&lbl_803797C8 | 0);
        r.z = m02 * *(const float*)(char*)(unsigned long)&lbl_803797C8 + m12 * *(const float*)(unsigned int)&lbl_803797CC +
              m22 * *(const float*)(unsigned long)(unsigned int)&lbl_803797C8;
        return r;
    }
};

struct Transform {
    char unknown00[0x30];
    Vec translation;
};

struct Handle {
    union {
        unsigned long value;
        struct {
            signed int tag : 8, index : 24;
        } bits;
    };
};

struct Prefix {
    unsigned long unknown00;
    Handle identity;
};

struct Node : Prefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual const Handle& matrixHandle(int);
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual Vec position(int);
    char unknown0C[0x24];
    Matrix basis;
    char unknown54[0xD0];
    Transform* transform;
};

struct Entry {
    Node* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};

struct Manager {
    int count, capacity;
    Entry* entries;
    Node* resolve(const Handle& h)
    {
        int index = h.bits.index;
        int tag = entries[index].getTag();
        return tag == h.bits.tag ? entries[index].object : 0;
    }
};

struct Context {
    char unknown00[0x118];
    Manager* manager;
};
extern "C" Context lbl_801E9D24;

inline Node* resolve(const Handle& h) { return lbl_801E9D24.manager->resolve(h); }

struct Control {
    char unknown00[8];
    Node* actor;
    char unknown0C[0x3C];
    Handle* targets;
    Node* first;
    Node* second;
};

extern "C" void fn_80254BB4(Node*, const Vec&);

extern "C" void fn_800E41B4(Control* self)
{
    Matrix parent = resolve(self->actor->matrixHandle(0))->basis;
    const Matrix firstBasis = self->first->basis;
    Vec firstPosition = parent.transform(self->first->transform->translation.x, self->first->transform->translation.y,
                                         self->first->transform->translation.z);
    Vec firstAxis = firstBasis.firstYAxis();
    Vec firstDirection = parent.transform(firstAxis.x, firstAxis.y, firstAxis.z);
    firstDirection.x *= lbl_803797D0;
    firstDirection.y *= *(const float*)&lbl_803797D0;
    firstDirection.z *= *(const float*)(int)&lbl_803797D0;
    const Matrix secondBasis = self->second->basis;
    Vec secondPosition = parent.transform(self->second->transform->translation.x, self->second->transform->translation.y,
                                          self->second->transform->translation.z);
    Vec secondAxis = secondBasis.secondYAxis();
    Vec secondDirection = parent.transform(secondAxis.x, secondAxis.y, secondAxis.z);
    secondDirection.x *= *(const float*)(unsigned long)&lbl_803797D0;
    secondDirection.y *= *(const float*)(long)&lbl_803797D0;
    secondDirection.z *= *(const float*)(unsigned int)&lbl_803797D0;
    Node* firstTarget = resolve(self->targets[0]);
    fn_80254BB4(firstTarget, self->actor->position(0) + firstDirection + firstPosition);
    Node* secondTarget = resolve(self->targets[1]);
    fn_80254BB4(secondTarget, self->actor->position(0) + secondDirection + secondPosition);
}
