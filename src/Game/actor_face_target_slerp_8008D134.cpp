/* fn_8008D134: turns the actor toward its target (+0x440).  The current yaw
   comes from the resolved entity basis (+0x30) applied to the forward axis
   (0, 0, 1), flattened to the XZ plane and normalized with a bare
   reciprocal-square-root estimate; the wanted yaw from the planar direction
   between the entity and target node positions (node at +0x124, position at
   +0x30).  Both half yaws become rotations about lbl_802F4148, the slerp
   (fn_8008D420) by 1.75 * delta goes to the actor's facing slot (0xC0) with
   the third argument, and once the two rotations' w components are within
   0.002 the actor counter (+0x318) is refreshed with the value at +0x444.

   Matching notes (GC/1.3, also exact under GC/1.3.2): lbl_80378AD0 (0.0f),
   lbl_80378ADC (1.0f) were pooled literals; the forward-axis factors and the
   folded 0*0 term of the planar length use the three distinct label read
   forms so they are merged the way the literal loads were.  The planar
   direction is a temporary normalized in place (bound by reference, hence
   the stack stores); its positions are by-value copies from getPosition. */
extern "C" const float lbl_80378AD0, lbl_80378ADC, lbl_80378AEC, lbl_80378B6C, lbl_80378B70;

struct Handle { signed int tag : 8; signed int index : 24; };

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3 operator*(float a) const { return Vec3(x * a, y * a, z * a); }
    Vec3& normalize()
    {
        float s = reciprocalSqrt(x * x + y * y + z * z);
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct Quat {
    float w;
    Vec3 v;
    Quat() {}
    Quat(const Quat& q) { w = q.w; v.x = q.v.x; v.y = q.v.y; v.z = q.v.z; }
};

struct Matrix { Vec3 r0, r1, r2; };
struct Node {
    char unknown00[0x30];
    Vec3 position;
    Vec3 getPosition() const { return Vec3(position.x, position.y, position.z); }
};
struct Entity { char unknown00[0x30]; Matrix basis; char unknown54[0x124 - 0x54]; Node* node; };
struct Entry {
    Entity* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Context { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

inline Entity* resolve(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}

struct Counter { int value; };
struct Prefix { char unknown00[8]; };
struct Actor : Prefix {
    virtual void s02(); virtual void s03(); virtual void s04(); virtual void s05();
    virtual void s06(); virtual void s07(); virtual void s08(); virtual void s09();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25();
    virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
    virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37();
    virtual void s38();
    virtual const Handle* getHandle(int);                  /* 0x9C */
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void setFacing(void*, const Quat*, int);       /* 0xC0 */
    char unknown0C[0x318 - 0xC];
    Counter counter;
    char unknown31C[0x440 - 0x31C];
    Entity* target;
    int state;
};
struct Owner { char unknown00[8]; Actor* actor; };

extern "C" {
extern const Vec3 lbl_802F4148;
float fn_80285124(float, float);
float fn_8028506C(float);
float fn_80284FA8(float);
double __fabs(double);
Quat fn_8008D420(const Quat&, Quat&, float);
void fn_8007D6A0(Counter*, int);
}

extern "C" void fn_8008D134(Owner* self, void*, void* second, void*, void*, float delta)
{
    Entity* target = self->actor->target;
    const Matrix& m = resolve(*self->actor->getHandle(0))->basis;
    float x = m.r0.x * lbl_80378AD0 + m.r1.x * *(const float*)&lbl_80378AD0 + m.r2.x * lbl_80378ADC;
    float z = m.r0.z * *(const float*)&lbl_80378AD0 + m.r1.z * *(const float*)(unsigned long)&lbl_80378AD0
            + m.r2.z * *(const float*)(unsigned long)&lbl_80378ADC;
    float s = reciprocalSqrt(x * x + *(const float*)&lbl_80378AD0 + z * z);
    float half = fn_80285124(x * s, z * s);
    half *= lbl_80378AEC;
    float c = fn_8028506C(half);
    float sn = fn_80284FA8(half);
    Quat from;
    from.w = c;
    from.v = lbl_802F4148 * sn;

    Entity* e = resolve(*self->actor->getHandle(0));
    Vec3 p0 = e->node->getPosition();
    Vec3 p1 = target->node->getPosition();
    Vec3 d = Vec3(p1.x - p0.x, lbl_80378AD0, p1.z - p0.z).normalize();
    float half2 = fn_80285124(d.x, d.z);
    half2 *= lbl_80378AEC;
    float c2 = fn_8028506C(half2);
    float sn2 = fn_80284FA8(half2);
    Quat to;
    to.w = c2;
    to.v = lbl_802F4148 * sn2;

    Quat r = fn_8008D420(from, to, lbl_80378B6C * delta);
    self->actor->setFacing(second, &r, 0);
    if ((float)__fabs(to.w - from.w) < lbl_80378B70)
        fn_8007D6A0(&self->actor->counter, self->actor->state);
}
