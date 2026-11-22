/* slot128__13ObjectThrow_ZFv: owner contact response. The velocity (+0x144) is reflected
   off the contact normal when moving into it; on steep or flagged contacts
   it is scaled by +0x178, otherwise the owner's attached basis yields a yaw
   quaternion that is combined with the up->normal rotation, and the
   velocity is scaled by +0x170. A stop result (small speed or zero scale)
   releases the owner and may detach it (fn_8021FD9C).
   slot64__13ObjectThrow_ZFv: contact event dispatch between this owner, the other body's
   owner and the related owners (+0x24, +0x180, +0x184): a contact record is
   pushed (fn_8021F518), an optional receiver (other owner +0x70, flag
   0x400000) supplies the event scale (int -> float, owns the bias double),
   then events 0x37..0x3E are sent with retained identity copies.
   Matching notes: pooled 0.0f/1.0f reads use distinct spellings where the
   original literals were separate loads; event1 is a long (int->long copy
   keeps the original mr); the receiver query and the per-event identity
   copies are inline helpers (their locals colour like the original). */
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Entry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" {
extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
void fn_801F86C8(void*, const void*, int);
void* fn_801F7EB8(const void*);
}
inline char* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[index].getGeneration();
    if (generation == h.bits.generation) return m->entries[index].object;
    return 0;
}
inline signed char valid(const Handle_801F7F10& h) { return fn_801F7EB8(&h) != 0; }

struct Handle1 : Handle_801F7F10 { Handle1() { value = 0; } };
struct CopyZ : Handle1 {
    CopyZ(const Handle_801F7F10& input)
    {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct CopyN : Handle_801F7F10 {
    CopyN(const Handle_801F7F10& input)
    {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};

extern "C" {
extern const float lbl_8037B138, lbl_8037B140, lbl_8037B144, lbl_8037B164, lbl_8037B170, lbl_8037B174;
extern const double lbl_8037B168;
double __fabs(double);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_80285124(float, float);
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float length() const
    {
        register float sq = x * x + y * y + z * z;
        register float result = lbl_8037B140;
        if (sq != result) {
            asm { frsqrte f4, sq }
            asm { fres result, f4 }
        }
        return result;
    }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
};

struct Quat {
    float w;
    Vec3 v;
    Quat() {}
    void fromY(float angle)
    {
        float half = angle * lbl_8037B170;
        w = fn_8028506C(half);
        float sine = fn_80284FA8(half);
        v.x = lbl_8037B140 * sine;
        v.y = lbl_8037B144 * sine;
        v.z = lbl_8037B140 * sine;
    }
};
struct Basis { float m[3][3]; };
extern "C" {
void fn_801F27BC(Quat*, const Vec3*, const Vec3*);
void fn_801F1BB0(Quat*, const Quat*);
void fn_801F20F4(Quat*, const float*);
void fn_801F2124(const float*, float*);
}

struct Node {
    char unknown00[0xC];
    Handle_801F7F10 parent;
    char unknown10[0x20];
    Basis basis;
    float matrix[9];
    char unknown78[0xA8];
    unsigned long flags;
};

struct Input {
    Vec3 position;
    float field0C;
    Vec3 direction;
    int field1C;
    char field20[8];
    unsigned long long flags;
    void* object;
};

struct Storage { char unknown00[4]; Handle_801F7F10 identity; };
struct Owner : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual signed char getEvent(int*);
    virtual signed char getOtherEvent(int*); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98(); virtual const Handle_801F7F10* getHandle(int);
    virtual void slotA0(); virtual void slotA4(); virtual void slotA8(); virtual void slotAC();
    virtual void slotB0(); virtual void slotB4(); virtual void slotB8(); virtual void slotBC();
    virtual void slotC0(); virtual void slotC4(); virtual void slotC8(); virtual void slotCC();
    virtual void slotD0(); virtual void slotD4(); virtual void slotD8(); virtual void slotDC();
    virtual void slotE0(); virtual void slotE4(); virtual void slotE8(); virtual void slotEC();
    virtual void slotF0(); virtual void slotF4(); virtual void slotF8(); virtual void release();
    char unknown0C[0x18];
    Handle_801F7F10 related24, controller28;
    char unknown2C[0xC];
    unsigned long long flags38;
    char unknown40[0x30];
    Handle_801F7F10 handle70;
    char unknown74[0xAC];
    unsigned long flags120;
    char unknown124[0xC];
    Handle_801F7F10 handle130;
    char unknown134[0x10];
    Vec3 velocity;
    char unknown150[0x20];
    float scale170;
    char unknown174[4];
    float scale178;
    float speed17C;
    Handle_801F7F10 handle180, handle184;
};

struct Record {
    Vec3 position;
    char unknown0C[4];
    unsigned long long flags;
    Vec3 velocity;
};

struct Receiver : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual int receive(const Handle_801F7F10*, const Record*);
};

extern "C" {
void fn_802073E8(void*, int, void*, float);
void fn_8021F518(Owner*, const Record*, int);
signed char fn_8021F308(Owner*);
void fn_8021FD9C(Owner*, const Handle_801F7F10*, void*, int);
}

extern "C" signed char slot128__13ObjectThrow_ZFv(Owner* self, const Input* info)
{
    Vec3& v = self->velocity;
    float speed = v.length();
    signed char result = 0;
    float d = v.dot(info->direction);
    if (d < lbl_8037B138) v = v - info->direction * (lbl_8037B164 * d);
    else v = v;
    if (info->direction.y < lbl_8037B168 || (info->flags & 0x80000000000ULL)) {
        float f = self->scale178;
        v.x *= f;
        v.y *= f;
        v.z *= f;
        if (valid(self->controller28) != 0) return 0;
        if ((float)__fabs(self->scale178) <= lbl_8037B138) result = 1;
        else result = 0;
    } else {
        Node* obj = (Node*)resolve(*self->getHandle(0));
        const Basis& B = obj->basis;
        float rx = B.m[0][0] * lbl_8037B140 + B.m[1][0] * *(const float*)&lbl_8037B140 + B.m[2][0] * lbl_8037B144;
        float rz = B.m[0][2] * *(const float*)(unsigned long)&lbl_8037B140 + B.m[1][2] * *(const float*)(long)&lbl_8037B140
            + B.m[2][2] * *(const float*)&lbl_8037B144;
        Vec3 dir(rx, lbl_8037B140, rz);
        Quat q;
        q.fromY(fn_80285124(dir.x, dir.z));
        Vec3 up(*(const float*)&lbl_8037B140, *(const float*)&lbl_8037B144, *(const float*)&lbl_8037B140);
        Quat m;
        fn_801F27BC(&m, &up, &info->direction);
        fn_801F1BB0(&m, &q);
        Node* node = (Node*)resolve(((Node*)resolve(*self->getHandle(0)))->parent);
        if (node->flags & 0x40) {
            fn_801F2124(node->basis.m[0], node->matrix);
            node->flags &= ~0x40;
        }
        Quat r;
        fn_801F20F4(&r, node->matrix);
        fn_801F1BB0(&r, &m);
        if (valid(self->controller28) != 0) return 0;
        float f = self->scale170;
        v.x *= f;
        v.y *= f;
        v.z *= f;
        if (speed < self->speed17C || (float)__fabs(self->scale170) <= lbl_8037B138) result = 1;
    }
    if (result) {
        self->release();
        if (!fn_8021F308(self)) {
            if (!(info->flags & 0x80000000000ULL))
                fn_8021FD9C(self, self->getHandle(0), info->object, 0);
        }
    }
    return result;
}

inline void sendEvent(Owner* target, int event, Owner* source, float scale)
{
    const Handle_801F7F10& identity = source->identity;
    CopyN copy(identity);
    fn_802073E8(target, event, resolve(copy), scale);
}

inline void sendEventR(Owner* target, const int& event, Owner* source, float scale)
{
    const Handle_801F7F10& identity = source->identity;
    CopyN copy(identity);
    fn_802073E8(target, event, resolve(copy), scale);
}
inline float queryScale(Receiver* receiver, Owner* other, Owner* self, const Vec3& position, unsigned long long flags)
{
    const Handle_801F7F10& identity = other->identity;
    CopyZ copy(identity);
    Record rec2;
    rec2.flags = flags;
    rec2.position = position;
    rec2.velocity = self->velocity;
    return receiver->receive(&copy, &rec2);
}
extern "C" void slot64__13ObjectThrow_ZFv(Owner* self, Owner* other, const Vec3& position, int unused, unsigned long long flags)
{
    Owner* a = (Owner*)resolve(other->handle130);
    Owner* b = (Owner*)resolve(self->handle184);
    Owner* c = (Owner*)resolve(self->handle180);
    Owner* d = (Owner*)resolve(self->related24);
    Owner* bt;
    if (b) bt = (Owner*)resolve(b->related24); else bt = 0;
    Owner* ct;
    if (c) ct = (Owner*)resolve(c->related24); else ct = 0;
    long event1 = (flags & 0x800000000000ULL) ? 0x39 : ((flags & 0x8ULL) ? 0 : 0x3a);
    int event2;
    if (flags & 0x800000000000ULL) event2 = 0x3b; else if (flags & 0x8ULL) event2 = 0; else event2 = 0x3c;
    if (d) {
        Record rec;
        rec.flags = flags;
        rec.position = position;
        rec.velocity = self->velocity;
        fn_8021F518(self, &rec, 0);
        Receiver* receiver;
        if (a && (a->flags38 & 0x400000ULL)) receiver = (Receiver*)resolve(a->handle70);
        else receiver = 0;
        float scale = lbl_8037B174;
        int event;
        if (receiver) scale = queryScale(receiver, other, self, position, flags);
        if (a) {
            if (d->getEvent(&event)) {
                if (bt) sendEventR(bt, event, a, scale);
                else sendEventR(d, event, a, scale);
            }
            if (a->getOtherEvent(&event)) sendEventR(a, event, d, scale);
            sendEvent(a, event1, d, scale);
            if ((other->flags120 & 0x100400) == 0x400) sendEvent(d, 0x3e, a, scale);
            if (ct == a) {
                sendEvent(ct, 0x37, d, lbl_8037B174);
                if (bt) sendEvent(ct, 0x37, bt, lbl_8037B174);
            }
        } else {
            sendEvent(d, event1, d, scale);
        }
        if (bt) sendEvent(d, event2, bt, scale);
        if (ct && ct == a) {
            sendEvent(self, 0x38, d, scale);
            if (bt) sendEvent(self, 0x38, bt, scale);
        }
    }
}
