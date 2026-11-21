// fn_8020CA80: free-fly camera update. Reads one pad's stick shorts, turns
// yaw/pitch, moves the bound node along the view direction and aims the
// node's related object at a point one unit ahead.
typedef unsigned long u32;
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
extern "C" { float fn_8028506C(float); float fn_80284FA8(float); }
inline float rsqrt(register float x) { register float r; asm { frsqrte r, x } return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator+(const Vec3& b) const { return Vec3(x + b.x, y + b.y, z + b.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    void normalize() { float s = rsqrt(lengthSquared()); x *= s; y *= s; z *= s; }
};
struct Object;
struct Entry { Object* object; u32 unknown04, unknown08; signed char generation; char pad[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct Slot { char unknown00[0x14]; Handle_801F7F10 node; char unknown18[0x34]; };
struct Slots { Slot slots[7]; signed char count; };
struct Pad { char unknown00[0x10]; short x, y, z; char unknown16[0x2A]; };
struct Pads { int count; int unknown04; Pad* pads; };
struct Globals { char unknown00[0x114]; Slots* slots; Manager* manager; char unknown11C[0x38]; Pads* pads; };
struct Object {
    char unknown00[0x1C];
    Handle_801F7F10 related;
    char unknown20[0x98];
    Vec3 position;
    char unknownC4[0x60];
    Vec3 target;
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
void fn_8023D648(Object*);
void fn_8023DE28(Object*);
}
struct HandleZero : Handle_801F7F10 { HandleZero() { value = 0; } };
struct HandleRef : HandleZero {
    HandleRef(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct HandleZero2 : HandleZero { HandleZero2() { value = 0; } };
struct HandleRef2 : HandleZero2 {
    HandleRef2(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
inline Object* resolve(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->generation == h.bits.generation) return e->object;
    return 0;
}
inline float deadzone(float v) {
    if (v < 10.0f && v > -10.0f) v = 0.0f;
    return v;
}
struct Self {
    char unknown00[0x20];
    int pad;
    int slot;
    float yaw, pitch;
};
extern "C" void fn_8020CA80(Self* self, float dt) {
    if (lbl_801E9D24.slots->count > self->slot && lbl_801E9D24.pads->count > self->pad) {
        Object* object = resolve(HandleRef(lbl_801E9D24.slots->slots[self->slot].node));
        if (object) {
            const Handle_801F7F10& link = object->related;
            Object* related = resolve(HandleRef2(link));
            Pad* pad = &lbl_801E9D24.pads->pads[self->pad];
            Vec3 position = object->position;
            Vec3 in((float)pad->z, (float)pad->x, (float)pad->y);
            if (in.x < 10.0f && in.x > -10.0f) in.x = 0.0f;
            if (in.y < 10.0f && in.y > -10.0f) in.y = 0.0f;
            if (in.z < 10.0f && in.z > -10.0f) in.z = 0.0f;
            float speed = -in.x / 8.0f;
            float yawRate = 3.1415927f * in.y;
            float pitchRate = 3.1415927f * in.z;
            self->yaw += dt * yawRate / 256.0f;
            self->pitch += dt * pitchRate / 256.0f;
            if (self->pitch < -1.0471976f) self->pitch = -1.0471976f;
            if (self->pitch > 1.0471976f) self->pitch = 1.0471976f;
            Vec3 direction;
            direction.x = fn_80284FA8(self->yaw) * fn_8028506C(self->pitch);
            direction.y = -fn_80284FA8(self->pitch);
            direction.z = -fn_8028506C(self->yaw) * fn_8028506C(self->pitch);
            direction.normalize();
            position += direction * speed * dt;
            direction += position;
            related->target = direction;
            object->position = position;
            fn_8023D648(object);
            fn_8023DE28(object);
        }
    }
}

