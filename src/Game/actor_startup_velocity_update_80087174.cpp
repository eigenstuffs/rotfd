// fn_80087174: actor startup/update step.
// Clears the actor reset flag (and two controller states); while not started,
// a high actor flag triggers an animation event, a mode-dependent controller
// action, a half-intensity color push on the scene mode's resource and
// controller action 0x14. Then adds (0, rate, 0) to the velocity and forwards
// delta to fn_80092DAC.
typedef unsigned long Word;

struct Handle {
    union {
        Word value;
        struct {
            signed int tag : 8, index : 24;
        } bits;
    };
};

struct Color {
    float x, y, z, w;
    Color(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
};

struct Resource;
struct Entry {
    Resource* object;
    char unknown4[8];
    signed char tag;
    char unknownD[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
};

struct Mode {
    char unknown0[0x60];
    Handle handle;
    char unknown64[0xF0 - 0x64];
    int kind;
};
struct Scene {
    char unknown0[0x15058];
    Mode* mode;
};

struct EventPrefix {
    char unknown0[0x1C];
};
struct Events : EventPrefix {
    virtual void slot8();
    virtual void slotC();
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
    virtual void send(int, int, int);
};

extern "C" struct Global {
    char unknown0[0x118];
    Manager* manager;
    char unknown11C[8];
    Scene* scene;
    char unknown128[0x2C];
    Events* events;
} lbl_801E9D24;

inline Resource* resolve(const Handle& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->tag == h.bits.tag ? e->object : 0;
}

struct Vec3 {
    float x, y, z;
};

struct Actor {
    char unknown0[0x30];
    unsigned long long flags;
    char unknown38[0x318 - 0x38];
    char controller[0x40];
    Vec3 velocity;
    char unknown364[0x3F4 - 0x364];
    float rate;
    char unknown3F8[0x40E - 0x3F8];
    signed char reset;
};

struct Self {
    char unknown0[8];
    Actor* actor;
    void* controller;
    char unknown10[0x30];
    signed char started;
};

extern "C" {
void fn_80285ED8(void*, int, int);
void fn_8025795C(void*, int, int);
void* fn_8007D074();
void fn_8007622C(void*, float, float);
void fn_80255D88(void*, int, int, int, int);
void fn_800A846C(Resource*, Color, float);
void fn_8007D6A0(void*, int);
void fn_80092DAC(Actor*, double);
extern const float lbl_80378AF4, lbl_80378AF8, lbl_80378AEC, lbl_80378AD0;
}

extern "C" void fn_80087174(Self* self, double delta) {
    if (self->actor->reset) {
        self->actor->reset = 0;
        fn_80285ED8(self->controller, 0x78, 0);
        fn_8025795C(self->controller, 0x44, 0);
        self->started = 0;
    }
    if (!self->started) {
        if (self->actor->flags & 0x8000000000ULL) {
            fn_8007622C(fn_8007D074(), lbl_80378AF4, lbl_80378AF8);
            lbl_801E9D24.events->send(0, 0xC4, 0);
            if (lbl_801E9D24.scene->mode->kind == 6)
                fn_80255D88(self->controller, 0x9B, 0xF, 0, 0);
            else
                fn_80255D88(self->controller, 0x84, 0xF, 0, 0);
            {
                Color c(lbl_80378AEC, lbl_80378AEC, lbl_80378AEC, lbl_80378AEC);
                Resource* r = resolve(lbl_801E9D24.scene->mode->handle);
                // Pointer read keeps the original's second pooled 0.5f load.
                fn_800A846C(r, c, *(const float*)&lbl_80378AEC);
            }
            fn_8007D6A0(self->actor->controller, 0x14);
        }
        Actor* actor = self->actor;
        float zero = lbl_80378AD0, rate = actor->rate;
        actor->velocity.x += zero;
        actor->velocity.y += rate;
        actor->velocity.z += zero;
        fn_80092DAC(self->actor, delta);
    }
}
