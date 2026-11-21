/* Actor tri-point pose update (fn_800E4CCC).

   The actor at +0x08 is active in states 0x30 and 0x11 (its +0x320).  When it
   just became inactive (flag +0x59 still set) fn_800E517C releases the effect
   handles.  While active, the actor's matrix node (virtual slot 0x9C, handle
   resolved through the engine manager) gives the parent 3x3 basis at +0x30.
   The side node at +0x54 contributes its transform translation (+0x124,
   translation at +0x30) rotated into the parent basis, and its own Z axis
   (basis * (0,0,1)) rotated into the parent basis and normalized.  Three
   offsets along that direction (scales at +0x60) place the effects in
   handles[2..4] at actor position + rotated translation + offset, with the
   parent basis as quaternion (fn_801F1E78).  fn_800E5254 activates the three
   effects first.  The handle[6] effect gets the first offset with the
   quaternion rotated by a quarter turn (sin/cos of pi/2, fn_801F1BB0).  The
   active flag is stored back to +0x59.

   Pooled literals: the original used float literals 0.0f/1.0f/(pi/2) that
   live in the shared .sdata2 pool (lbl_803797C8, lbl_803797CC,
   lbl_803797D8).  Each literal use was a separate pool load that only the
   backend merged, so every use of a label before the first call is written
   with its own read form (plain, *(const float*)&, and the integer address
   casts).  The quarter-turn axis is read through references after the cosine
   call, as the literal version loaded it there. */
#pragma fp_contract on

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

extern "C" {
extern const float lbl_803797C8, lbl_803797CC, lbl_803797D8;
float fn_8028506C(float);
float fn_80284FA8(float);
}

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
    Vec operator+(const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
    Vec operator*(float k) const { return Vec(x * k, y * k, z * k); }
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec normalized() const
    {
        float inv = reciprocalSqrt(lengthSquared());
        return Vec(x * inv, y * inv, z * inv);
    }
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
    /* transform(0.0f, 0.0f, 1.0f) with one pool read per literal use. */
    Vec zAxis() const
    {
        Vec r;
        r.x = m00 * lbl_803797C8 + m10 * *(const float*)&lbl_803797C8 + m20 * lbl_803797CC;
        r.y = m01 * *(const float*)(unsigned long)&lbl_803797C8 + m11 * *(const float*)(long)&lbl_803797C8 +
              m21 * *(const float*)&lbl_803797CC;
        r.z = m02 * *(const float*)(unsigned int)&lbl_803797C8 + m12 * *(const float*)(int)&lbl_803797C8 +
              m22 * *(const float*)(unsigned long)&lbl_803797CC;
        return r;
    }
};

struct Quat {
    float x, y, z, w;
    Quat() {}
    /* Rotation by angle about (ax, ay, az): x = sin, (y, z, w) = axis * cos. */
    Quat(const float& angle, const float& ax, const float& ay, const float& az)
    {
        x = fn_8028506C(angle);
        float c = fn_80284FA8(angle);
        const Vec v(ax * c, ay * c, az * c);
        setVector(v);
    }
    void setVector(const Vec& v)
    {
        y = v.x;
        z = v.y;
        w = v.z;
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
    char unknown128[0x1F8];
    int state;
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
    Handle* handles;
    char unknown4C[8];
    Node* side;
    char unknown58;
    char active;
    char unknown5A[6];
    float scales[3];
};

extern "C" {
void fn_800E517C(Control*);
void fn_800E5254(Control*, int);
void fn_80254AF4(Node*, const Vec&, const Quat&);
void fn_801F1E78(Quat*, const Matrix*);
void fn_801F1BB0(Quat*, const Quat*);
}

inline bool isActiveState(Node* node)
{
    bool result = true;
    if (node->state != 0x30 && node->state != 0x11) result = false;
    return result;
}

extern "C" void fn_800E4CCC(Control* self)
{
    char active = isActiveState(self->actor);
    if (!active && self->active) fn_800E517C(self);
    else if (active) {
        Matrix parent = resolve(self->actor->matrixHandle(0))->basis;
        Vec position = parent.transform(self->side->transform->translation.x, self->side->transform->translation.y,
                                        self->side->transform->translation.z);
        const Matrix basis = self->side->basis;
        Vec axis = basis.zAxis();
        Vec direction = parent.transform(axis.x, axis.y, axis.z);
        direction = direction.normalized();
        Vec offsets[3];
        for (int i = 0; i < 3; ++i) offsets[i] = direction * self->scales[i];
        Quat rotation;
        fn_801F1E78(&rotation, &parent);
        fn_800E5254(self, 3);
        for (int j = 0; j < 3; ++j) {
            Node* target = resolve(self->handles[j + 2]);
            fn_80254AF4(target, self->actor->position(0) + position + offsets[j], rotation);
        }
        fn_801F1BB0(&rotation, &Quat(lbl_803797D8, lbl_803797C8, lbl_803797CC, lbl_803797C8));
        Node* target = resolve(self->handles[6]);
        fn_80254AF4(target, self->actor->position(0) + position + offsets[0], rotation);
    }
    self->active = active;
}
