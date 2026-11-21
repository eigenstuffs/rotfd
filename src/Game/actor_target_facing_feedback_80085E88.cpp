/* Actor target-direction feedback and action toggle (fn_80085E88).
 * Resolves the actor's queried target (slot 0x9C) and takes its matrix
 * position; the fast-normalized direction from it to the owner position
 * (+0x40) is dotted with the actor's forward vector (+0x3C0) and the arc
 * cosine fn_80284DD8 of that dot gives the facing angle. The owner-target
 * distance (engine fast sqrt) is clamped to 30 and a feedback strength
 * 128*(1-d/30) + 127*(1-|angle|/pi) is sent to the feedback object at
 * lbl_801E9D24+0x154 (slot 0x38). After the actor motion update
 * fn_80092DAC, when an action (+0x4C) exists the facing flag (+0x58,
 * dot >= 0) starts or stops it through the controller (+0xC) events
 * 0x82/0x83.
 *
 * Matching notes: the target position is three named locals and the dot is
 * written out (an inline dot() return value colors before them); normalize
 * compares the zero label first with the square sum assigned inside the
 * condition; the second length uses separate squared locals (no fmadds) and
 * binds the difference to a const reference (dead stack stores). The 1.0f
 * label is read through two lvalue forms (the original pooled literal is not
 * CSE'd in the IR), and |angle| uses the __fabs intrinsic directly. */
typedef unsigned long Word;
extern "C" const float lbl_80378AD0;
extern "C" const float lbl_80378ADC;
extern "C" const float lbl_80378B20;
extern "C" const float lbl_80378B24;
extern "C" const float lbl_80378B28;
extern "C" const float lbl_80378B2C;
extern "C" const float lbl_80378B30;

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
    void normalize()
    {
        register float sq;
        if (lbl_80378AD0 != (sq = x * x + y * y + z * z)) {
            register float inv;
            asm { frsqrte inv, sq }
            x *= inv;
            y *= inv;
            z *= inv;
        }
    }
    float length() const
    {
        float x2 = x * x;
        float y2 = y * y;
        float z2 = z * z;
        float sq = x2 + y2 + z2;
        float r = lbl_80378AD0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Matrix {
    float m[16];
};

struct Node {
    char unknown00[0x124];
    Matrix* matrix;
};

struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char pad[3]; };
struct Manager { char unknown00[8]; Entry* entries; };

struct FeedbackPrefix { char unknown00[0x1C]; };
struct Feedback : FeedbackPrefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void feedback(int, unsigned char, unsigned char);
};

extern "C" struct Global {
    char unknown000[0x118];
    Manager* manager;
    char unknown11C[0x154 - 0x11C];
    Feedback* feedback;
} lbl_801E9D24;

inline Node* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->tag == h.bits.tag ? e->object : 0;
}

struct Prefix { char unknown00[8]; };
struct Actor : Prefix {
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
    virtual const Handle& query(int);
    char unknown0C[0x3C0 - 0xC];
    Vec3 forward;
};

struct Action : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void start();
    virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void setRange(int, int);
};

struct Self {
    char unknown00[8];
    Actor* actor;
    void* controller;
    char unknown10[0x40 - 0x10];
    Vec3 position;
    Action* action;
    int first;
    int second;
    signed char mode;
};

extern "C" {
float fn_80284DD8(float);
void fn_80092DAC(Actor*, double);
signed char fn_80255618(Action*);
void fn_80255678(Action*);
void fn_802554F4(Action*);
void fn_80255CBC(void*, int, int);
void fn_80255D88(void*, int, int, int, int);
}

extern "C" void fn_80085E88(Self* self, double delta)
{
    Matrix* m = resolve(self->actor->query(0))->matrix;
    float tx = m->m[12];
    float ty = m->m[13];
    float tz = m->m[14];
    Vec3 target(tx, ty, tz);
    Vec3 forward = self->actor->forward;
    Vec3 direction = self->position - target;
    direction.normalize();
    float cosine = direction.x * forward.x + direction.y * forward.y + direction.z * forward.z;
    float angle = fn_80284DD8(cosine);
    const Vec3& diff = self->position - target;
    float distance = diff.length();
    float clamped = distance;
    if (distance > lbl_80378B20) clamped = lbl_80378B20;
    float turn = __fabs(angle);
    lbl_801E9D24.feedback->feedback(0,
        (int)(lbl_80378B24 * (lbl_80378ADC - lbl_80378B28 * clamped)) +
        (int)(lbl_80378B2C * (*(const float*)&lbl_80378ADC - lbl_80378B30 * turn)), 0);
    fn_80092DAC(self->actor, delta);
    if (self->action) {
        self->mode = cosine >= lbl_80378AD0;
        if (!self->mode && !fn_80255618(self->action)) {
            fn_80255D88(self->controller, 0x83, 15, 0, 0);
            fn_80255CBC(self->controller, 0x82, 0);
            fn_80255678(self->action);
        }
        if (self->mode && fn_80255618(self->action)) {
            fn_80255D88(self->controller, 0x82, 15, 0, 0);
            fn_80255CBC(self->controller, 0x83, 0);
            self->action->start();
            self->action->setRange(self->second, self->first);
            fn_802554F4(self->action);
        }
    }
}
