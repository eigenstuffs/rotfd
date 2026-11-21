/* fn_800804EC: actor ground probe below anchor offset. */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Service { char unknown00[8]; const Handle_801F7F10* handle; };
struct Context { char unknown00[0x118]; Manager* manager; Service* service; };
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
unsigned long fn_801F7EB8(const Handle_801F7F10*);
extern const float lbl_80378AA8, lbl_80378AAC, lbl_80378AB8, lbl_80378ABC;
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
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378AA8;
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
        if (length > lbl_80378ABC) direction *= lbl_80378AAC / length;
    }
};

struct Ray2 {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray2(Vec3 from, Vec3 to) : origin(from), direction(to - from)
    {
        length = direction.length();
        if (length > lbl_80378ABC) direction *= lbl_80378AAC / length;
    }
};
struct Ray3 {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray3(const Vec3& from, const Vec3& to)
    {
        origin = from;
        direction = to - from;
        length = direction.length();
        if (length > lbl_80378ABC) direction *= lbl_80378AAC / length;
    }
};
struct Ray4 {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray4(const Vec3& from, const Vec3& delta) : origin(from), direction((from + delta) - from)
    {
        length = direction.length();
        if (length > lbl_80378ABC) direction *= lbl_80378AAC / length;
    }
};

struct HitResult {
    char unknown00[0x28];
    int value28, value2C, value30, value34, value38;
    signed char flag3C;
    unsigned long long mask40;
    HitResult() { flag3C = 0; value30 = 0; value34 = 0; value38 = 0; value2C = 0; value28 = 0; }
};


struct Body { char unknown00[0x30]; Vec3 position; Vec3 getPosition() const { return Vec3(position.x, position.y, position.z); } const Vec3& getPosRef() const { return position; } };
struct Target { char unknown00[0x120]; unsigned long flags; Body* body;
  Vec3 bodyPosition() const { return Vec3(body->position.x, body->position.y, body->position.z); }
  Vec3 getPosition() const { return bodyPosition(); }
};
struct Offset { float x, y, z, drop; };
struct Anchor { char unknown00[0x74]; Offset* offset; };

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
    virtual void slot36();
    virtual const Handle_801F7F10* slot37(int);
};

struct Actor : Node {
    char unknown0C[0x15C];
    Handle_801F7F10 anchor;
    char unknown16C[0x44];
    Handle_801F7F10 handle1B0;
    char unknown1B4[0x164];
    Record record;
};

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

struct Owner { char unknown00[8]; Actor* actor; };

extern "C" {
signed char fn_80269818(Node*, const void*, HitResult*, unsigned long long, unsigned long long);
void fn_8007D6A0(Record*, int);
}

extern "C" void fn_800804EC(Owner* self)
{
    if (fn_801F7EB8(&self->actor->handle1B0)) {
        fn_8007D6A0(&self->actor->record, 1);
        return;
    }
    resolve<Target>(*self->actor->slot37(0))->flags &= ~0x40000;
    Handle_80020C04 held(*lbl_801E9D24.service->handle);
    Offset* off = resolve<Anchor>(self->actor->anchor)->offset;
    Target* target = resolve<Target>(*self->actor->slot37(0));
    float drop = lbl_80378AB8 + off->drop;
    Vec3 pos = target->getPosition();
    Vec3 from(off->x + pos.x, off->y + pos.y, off->z + pos.z);
    float zero = lbl_80378AA8;
    Ray ray(from, from + Vec3(zero, -drop, zero));
    HitResult result;
    if (!fn_80269818(resolve<Node>(held), &ray, &result, 0xFFFFFFFFFFFFFFFFULL, 0ULL)) {
        fn_8007D6A0(&self->actor->record, 3);
    }
    resolve<Target>(*self->actor->slot37(0))->flags |= 0x40000;
}
