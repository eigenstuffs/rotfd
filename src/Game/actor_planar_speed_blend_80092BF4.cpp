/* fn_80092BF4: blend the actor's planar speed toward the mode's target speed.
   Mode 1 targets +0x36C, mode 2 +0x3E8, modes 3/4 +0x370 (blend factor
   1.75 * dt); modes 5 and 9..12 target +0x374 (factor 3 * dt). The flag at
   +0x404 forces the +0x36C target. The new speed (+0x3CC) is
   planarLength(previous) * (1 - k) + target * inputMagnitude * k (input
   magnitude at lbl_801E9D24+0x164 -> +0x48, as in fn_80092844); while the
   actor record is in state 9, 10, 0x1A or 0xC and |+0x3D0| is between 2.618
   and 3.665 the speed is cut to 10%. The velocity becomes direction * speed.

   Matching notes: the locals are declared C-style at the top in this order
   (magnitude, x, z, target, blend) - other orders permute f1/f3/f5/f6. The
   planar length x*x + 0 + z*z (the original folded a literal 0*0 from a
   Vec3(x, 0, z)) is written with the shared zero label added explicitly and
   register copies of x/z so -fp_contract fuses it into two fmadds; the
   length helper uses the second read form of lbl_80378BAC so the switch's
   initial target load stays separate. */
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
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};

struct Record { char unknown00[8]; int key; };

struct Actor {
    char unknown00[0x144];
    Vec3 velocity;
    char unknown150[0xC];
    Vec3 previous;
    char unknown168[0x1B0];
    Record record;
    char unknown324[0x48];
    float speed36C;
    float speed370;
    float speed374;
    char unknown378[0x48];
    Vec3 direction;
    float speed;
    float angle;
    char unknown3D4[0x14];
    float speed3E8;
    char unknown3EC[0x18];
    signed char flag404;
};

struct Input { char unknown00[0x48]; float magnitude; };
struct Context { char unknown00[0x164]; Input* input; };

extern "C" {
extern Context lbl_801E9D24;
extern const float lbl_80378BAC, lbl_80378BBC, lbl_80378BD4, lbl_80378BE8;
extern const float lbl_80378C14, lbl_80378C18, lbl_80378C1C;
double __fabs(double);
signed char fn_8007D604(Record*, int);
}

inline float planarLength(float x, float z)
{
    float sq = x * x + *(const float*)&lbl_80378BAC + z * z;
    float r = *(const float*)&lbl_80378BAC;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

extern "C" void fn_80092BF4(Actor* self, int mode, float dt)
{
    float magnitude;
    float x, z;
    float target = lbl_80378BAC;
    float blend;
    switch (mode) {
    case 1:
        blend = lbl_80378C14 * dt;
        target = self->speed36C;
        break;
    case 2:
        blend = lbl_80378C14 * dt;
        target = self->speed3E8;
        break;
    case 3:
    case 4:
        blend = lbl_80378C14 * dt;
        target = self->speed370;
        break;
    case 5:
    case 9:
    case 10:
    case 11:
    case 12:
        blend = lbl_80378BBC * dt;
        target = self->speed374;
        break;
    }
    if (self->flag404) target = self->speed36C;
    magnitude = lbl_801E9D24.input->magnitude;
    x = self->previous.x;
    z = self->previous.z;
    float len = planarLength(x, z);
    float goal = target * magnitude;
    self->speed = len * (lbl_80378BE8 - blend) + goal * blend;
    float angle = (float)__fabs(self->angle);
    if (fn_8007D604(&self->record, 9) || fn_8007D604(&self->record, 10) ||
        fn_8007D604(&self->record, 0x1A) || fn_8007D604(&self->record, 0xC)) {
        if (angle > lbl_80378C18 && angle < lbl_80378C1C) self->speed = self->speed * lbl_80378BD4;
    }
    self->velocity = self->direction * self->speed;
}
