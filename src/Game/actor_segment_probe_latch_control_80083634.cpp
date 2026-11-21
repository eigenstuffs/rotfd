/* fn_80083634: per-frame actor control step (sibling of fn_80081D88). Runs
   fn_80092DAC(actor, dt); on the first frame actor flag 0x409 is set, fires
   controller events 0x79 (fn_80285ED8) and 0x41 (fn_8025795C) and latches
   owner flag 0x40. While actor flag 0x40A and the latch are set, fires 0x70
   and runs a segment query (fn_80269818, mask 0x400) from the related body
   position to that position raised by the actor height (+0x430). A miss
   forwards the current state (fn_80092844) to the actor record; a hit in
   state 3 sends record event 4, otherwise triggers controller effect 0x70
   (fn_802073E8). Class shapes copied from actor_segment_probe_control_80081D88. */
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
extern const float lbl_80378AD0, lbl_80378AD8, lbl_80378ADC, lbl_80378AE0;
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
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378AD0;
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
        if (length > lbl_80378AD8) direction *= lbl_80378ADC / length;
    }
};

struct HitResult {
    char unknown00[0x28];
    int value28, value2C, value30, value34, value38;
    signed char flag3C;
    unsigned long long mask40;
    HitResult() { flag3C = 0; value30 = 0; value34 = 0; value38 = 0; value2C = 0; value28 = 0; }
};

struct Body { char unknown00[0x30]; Vec3 position; Vec3 getPosition() const { return Vec3(position.x, position.y, position.z); } };
struct Target { char unknown00[0x124]; Body* body; };

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
    char unknown0C[0x30C];
    Record record;
    char unknown324[0xE5];
    signed char flag409;
    signed char enabled40A;
    char unknown40B[0x25];
    float height;
};

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

struct Owner { char unknown00[8]; Actor* actor; void* controller; char unknown10[0x30]; signed char flag40; };

extern "C" {
signed char fn_80269818(Node*, const Ray*, HitResult*, unsigned long long, unsigned long long);
int fn_80092844(Actor*);
void fn_8007D6A0(Record*, int);
void fn_80092DAC(Actor*, float);
void fn_802073E8(void*, int, void*, float);
void fn_80285ED8(void*, int, int);
void fn_8025795C(void*, int, int);
}

extern "C" void fn_80083634(Owner* self, float dt)
{
    fn_80092DAC(self->actor, dt);
    if (self->actor->flag409 && !self->flag40) {
        fn_80285ED8(self->controller, 0x79, 0);
        fn_8025795C(self->controller, 0x41, 0);
        self->flag40 = 1;
    }
    if (self->actor->enabled40A && self->flag40) {
        fn_80285ED8(self->controller, 0x70, 0);
        HitResult result;
        Handle_80020C04 held(*lbl_801E9D24.service->handle);
        float zero = lbl_80378AD0;
        float height = self->actor->height;
        const Vec3& pos = resolve<Target>(*self->actor->slot37(0))->body->getPosition();
        Ray ray(resolve<Target>(*self->actor->slot37(0))->body->getPosition(), Vec3(pos.x + zero, pos.y + height, pos.z + zero));
        if (fn_801F7EB8(&held)) {
            if (!fn_80269818(resolve<Node>(held), &ray, &result, 0x400ULL, 0ULL)) {
                fn_8007D6A0(&self->actor->record, fn_80092844(self->actor));
            } else if (fn_80092844(self->actor) == 3) {
                fn_8007D6A0(&self->actor->record, 4);
            } else {
                fn_802073E8(self->controller, 0x70, self->controller, lbl_80378AE0);
            }
        }
    }
}
