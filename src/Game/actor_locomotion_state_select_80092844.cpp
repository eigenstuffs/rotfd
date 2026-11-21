/* fn_80092844: choose the actor's locomotion state from the input magnitude
   (lbl_801E9D24+0x164 -> +0x48): <= 0.1 idle (0), <= 0.5 walk (1), <= 0.9
   jog (2, or 1 when +0x434 is set), above run (3, or 2). Unless flag bit
   0x8000000000 is set, a downward segment query (fn_80269818) runs from the
   actor's probe point (virtual +0xB0) to that point lowered by 0.5; a miss
   selects the falling state 0xC. With +0x404 set, magnitude above 0.1 and no
   fall, a |+0x3D0| above 0.785 while the record (+0x318) is in state 0
   keeps state 0, otherwise 1. With a valid +0x1AC handle the state maps to
   0 -> 0x18, 1..3 -> 0x19, 0xC -> 0x1B. Ray/HitResult/handle shapes follow
   fn_80081D88.

   Matching notes: both probePoint() calls sit in the Ray constructor's
   argument list (the lowered end via the inline Vec3::below()); that gives
   the original stack order of the two by-value temporaries (end point at
   0xC, start at 0x18) and loads the offset constants after the first call. */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Service { char unknown00[8]; const Handle_801F7F10* handle; };
struct Input { char unknown00[0x48]; float magnitude; };
struct Context { char unknown00[0x118]; Manager* manager; Service* service; char unknown120[0x44]; Input* input; };
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
unsigned long fn_801F7EB8(const Handle_801F7F10*);
extern const float lbl_80378BAC, lbl_80378BD4, lbl_80378BDC, lbl_80378BE8, lbl_80378BEC;
extern const float lbl_80378C08, lbl_80378C0C, lbl_80378C10;
double __fabs(double);
}
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020C04 : Handle_8001FF78 { Handle_80020C04(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_80020C04() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 below() const { return Vec3(x + lbl_80378BAC, y + lbl_80378C08, z + lbl_80378BAC); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378BAC;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray(const Vec3& from, const Vec3& to) : origin(from), direction(to - from)
    {
        length = direction.length();
        if (length > lbl_80378C0C) direction *= lbl_80378BE8 / length;
    }
};

struct HitResult {
    char unknown00[0x28];
    int value28, value2C, value30, value34, value38;
    signed char flag3C;
    unsigned long long mask40;
    HitResult() { flag3C = 0; value30 = 0; value34 = 0; value38 = 0; value2C = 0; value28 = 0; }
};

struct Record { char unknown00[8]; int key; };
struct NodePrefix { char unknown00[8]; };
struct Node : NodePrefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41();
    virtual Vec3 probePoint(int);
};

struct Actor : Node {
    char unknown0C[0x24];
    unsigned long long flags;
    char unknown38[0x174];
    Handle_801F7F10 handle1AC;
    char unknown1B0[0x168];
    Record record;
    char unknown324[0xAC];
    float angle;
    char unknown3D4[0x30];
    signed char flag404;
    char unknown405[0x2F];
    signed char flag434;
};

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

extern "C" {
signed char fn_80269818(Node*, const Ray*, HitResult*, unsigned long long, unsigned long long);
signed char fn_8007D604(Record*, int);
}

extern "C" int fn_80092844(Actor* self)
{
    int state = -1;
    float magnitude = lbl_801E9D24.input->magnitude;
    if (magnitude <= lbl_80378BD4) {
        state = 0;
    } else if (magnitude > lbl_80378BD4 && magnitude <= lbl_80378BEC) {
        state = 1;
    } else if (magnitude > lbl_80378BEC && magnitude <= lbl_80378BDC) {
        if (!self->flag434) state = 2;
        else state = 1;
    } else if (magnitude > lbl_80378BDC) {
        if (!self->flag434) state = 3;
        else state = 2;
    }
    if (!(self->flags & 0x8000000000ULL)) {
        HitResult result;
        Handle_80020C04 held(*lbl_801E9D24.service->handle);
        Ray ray(self->probePoint(0), self->probePoint(0).below());
        if (fn_801F7EB8(&held)) {
            if (!fn_80269818(resolve<Node>(held), &ray, &result, 0xFFFFFFFFFFFFFFFFULL, 0ULL)) state = 0xC;
        }
    }
    float angle = (float)__fabs(self->angle);
    if (self->flag404 && magnitude > lbl_80378BD4 && state != 0xC) {
        if (angle > lbl_80378C10 && fn_8007D604(&self->record, 0)) state = 0;
        else state = 1;
    }
    if (fn_801F7EB8(&self->handle1AC)) {
        switch (state) {
        case 0: state = 0x18; break;
        case 1: case 2: case 3: state = 0x19; break;
        case 0xC: state = 0x1B; break;
        }
    }
    return state;
}
