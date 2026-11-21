/* Camera heading turn (fn_80076B38): reads the turn input (in mode 3 from the
   analog axis or the two digital buttons), accumulates the scaled turn angle,
   and in mode 3 clears it once the facing and desired directions agree.
   The engine fast normalize uses a raw frsqrte estimate (no frsp), which no
   compiler built-in emits, so the math helper uses a minimal inline asm
   statement. */
extern "C" {
void fn_800B742C(void*, int, float*, int, int);
void fn_800B7214(void*, int, unsigned char*, int);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_80285124(float, float);
extern const float lbl_8037899C, lbl_803789A8, lbl_803789E4, lbl_803789E8, lbl_803789EC;
}
inline float reciprocalSqrt(register float value) { register float result; asm { frsqrte result, value } return result; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    float lengthSquared() const { return x * x + y * y + z * z; }
    void normalize()
    {
        if (lbl_8037899C != z || lbl_8037899C != x) {
            float inverse = reciprocalSqrt(lengthSquared());
            x *= inverse; y *= inverse; z *= inverse;
        }
    }
};
extern "C" float fn_8005EC08(const Vec3*, const Vec3*);
extern "C" struct Global { char unknown0[0x164]; void* settings; } lbl_801E9D24;
struct Self {
    char unknown0[0xD0];
    int kind;
    char unknownD4[0x100 - 0xD4];
    float x100;
    char unknown104[4];
    float x108;
    char unknown10C[0x114 - 0x10C];
    float angle;
    char unknown118[0x1C8 - 0x118];
    float heading;
    char unknown1CC[0x1D8 - 0x1CC];
    float limit;
};
extern "C" void fn_80076B38(Self* self, float delta)
{
    float direction = lbl_8037899C;
    if (self->kind == 3) {
        fn_800B742C(lbl_801E9D24.settings, 0, &direction, 0, 0);
        if (direction == lbl_8037899C) {
            unsigned char left = 0, right = 0;
            fn_800B7214(lbl_801E9D24.settings, 8, &left, 0);
            fn_800B7214(lbl_801E9D24.settings, 7, &right, 0);
            if (left) direction = lbl_803789E4;
            else if (right) direction = lbl_803789A8;
        }
    } else {
        fn_800B742C(lbl_801E9D24.settings, 2, &direction, 0, 0);
    }
    delta *= direction;
    if (direction < lbl_8037899C) self->angle += delta;
    if (direction > lbl_8037899C) self->angle += delta;
    if (self->kind == 3) {
        Vec3 facing;
        facing.x = fn_8028506C(lbl_803789E8 * self->heading);
        facing.y = lbl_8037899C;
        facing.z = fn_80284FA8(lbl_803789E8 * self->heading);
        float offset = lbl_8037899C;
        if (lbl_8037899C != self->x108 || lbl_8037899C != self->x100)
            offset = lbl_803789EC * fn_80285124(self->x108, self->x100);
        offset += self->angle;
        float a = lbl_803789E8 * offset;
        Vec3 wanted;
        wanted.x = fn_8028506C(a);
        wanted.y = lbl_8037899C;
        wanted.z = fn_80284FA8(a);
        wanted.normalize();
        if (lbl_803789EC * fn_8005EC08(&facing, &wanted) >= self->limit)
            self->angle = lbl_8037899C;
    }
}
