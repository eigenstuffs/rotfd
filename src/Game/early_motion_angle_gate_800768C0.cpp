/* Angular motion gate (fn_800768C0): reads the movement direction and, for
   either sign, optionally requires the wrapped degree difference between the
   current yaw (fn_80079024) and the input heading (fn_80077BDC) to pass a
   threshold before advancing the amount and resetting the motion state.
   The full circle is the shared pooled constant lbl_80378998 (360.0f). The
   original reloads it for the 0 and 180 corrections; reading those two uses
   through a pointer keeps the compiler from reusing the first load. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Self {
    char unknown0[0xD0];
    int kind;
    float amount;
    char unknownD8[0xE8 - 0xD8];
    signed char flagE8, flagE9;
    char unknownEA[6];
    float timer;
    Vec3 target;
    char unknown100[0xC];
    signed char changed;
    char unknown10D[0x21C - 0x10D];
    float height;
    Vec3 position() const;
    float angle() const;
};
extern "C" struct Global { char unknown0[0x164]; void* settings; } lbl_801E9D24;
extern "C" {
void fn_80076D98(const Self*, Vec3*);
void fn_800B742C(void*, int, float*, int, int);
float fn_80077BDC(const Self*, Vec3*);
float fn_80079024(const Self*);
signed char fn_800793D0(Self*, const Vec3*, const Vec3*);
extern const float lbl_80378998, lbl_8037899C, lbl_803789A0, lbl_803789D8, lbl_803789DC;
}
inline Vec3 Self::position() const { Vec3 result; fn_80076D98(this, &result); return result; }
inline float Self::angle() const
{
    Vec3 vector;
    float base = fn_80077BDC(this, &vector);
    float difference = fn_80079024(this) - base;
    if (difference >= lbl_80378998) difference -= lbl_80378998;
    if (difference <= lbl_8037899C) difference += *(const float*)&lbl_80378998;
    if (difference > lbl_803789A0) difference -= *(const float*)&lbl_80378998;
    return difference;
}
extern "C" void fn_800768C0(Self* self, float delta)
{
    Vec3 raw;
    fn_80076D98(self, &raw);
    Vec3 position = raw;
    position.y += self->height;
    float direction = lbl_8037899C;
    fn_800B742C(lbl_801E9D24.settings, 2, &direction, 0, 0);
    if (direction < lbl_8037899C) {
        if (self->kind == 2) {
            if (self->angle() > lbl_803789D8) {
                if (fn_800793D0(self, &self->target, &position)) self->amount += delta;
            }
        } else if (fn_800793D0(self, &self->target, &position)) self->amount += delta;
        self->flagE9 = 0;
        self->flagE8 = 0;
        self->timer = lbl_8037899C;
        self->changed = 1;
    }
    if (direction > lbl_8037899C) {
        if (self->kind == 2) {
            if (self->angle() < lbl_803789DC) {
                if (fn_800793D0(self, &self->target, &position)) self->amount -= delta;
            }
        } else if (fn_800793D0(self, &self->target, &position)) self->amount -= delta;
        self->flagE9 = 0;
        self->flagE8 = 0;
        self->timer = lbl_8037899C;
        self->changed = 1;
    }
}
