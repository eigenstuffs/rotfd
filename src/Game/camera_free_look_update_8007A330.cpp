/* Camera free-look update (fn_8007A330): raises the context position by the
   camera height, tests segment visibility from the camera point (fn_800793D0)
   and, while blocked, queries the steering inputs (fn_8007963C).  The
   dominant input axis accelerates the yaw (0x13C) or pitch (0x138) rate,
   which is damped once the view is clear, clamped symmetrically and applied
   through fn_80078284 / fn_80078194; the camera point then follows its target
   (same body as fn_8007A864) and the moved flags at 0x224/0x225 are returned.
   The absolute values are double temporaries converted at the comparison,
   which gives the original register choice; the stack slots follow the
   local declaration order. */
extern "C" double __fabs(double);
inline bool absLE(float a, float b)
{
    double da = __fabs(a);
    double db = __fabs(b);
    return (float)da <= (float)db;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    bool operator!=(const Vec3& v) const { return x != v.x || y != v.y || z != v.z; }
};

struct Camera {
    char unknown00[0xD0];
    int state;
    char unknownD4[4];
    Vec3 up;
    char unknownE4[5];
    signed char flagE9;
    char unknownEA[0xA];
    Vec3 current;
    Vec3 direction;
    char unknown10C[0xC];
    Vec3 desired;
    char unknown124[0xC];
    signed char flag130;
    char unknown131[7];
    float roll138;
    float roll13C;
    char unknown140[0xC];
    Vec3 target;
    char unknown158[0x1D];
    signed char enabled;
    char unknown176[0x26];
    float speed19C;
    float speed1A0;
    char unknown1A4[0x78];
    float height;
    float timer;
    signed char moved224;
    signed char moved225;
    signed char busy;
};

extern "C" {
struct Global { char unknown0[0x164]; void* settings; };
extern Global lbl_801E9D24;
void fn_80076D98(Camera*, Vec3*);
void fn_800B742C(void*, int, float*, int, int);
signed char fn_800793D0(Camera*, const Vec3*, const Vec3*);
float fn_80079CB8(Camera*);
void fn_8007963C(Camera*, Vec3*, float*, float*, signed char*, signed char*);
void fn_80078284(Camera*, float);
void fn_80078194(Camera*, float);
signed char fn_8007ACAC(Camera*);
signed char fn_8007AA9C(Camera*, float);
void fn_8007D4B4(Vec3*, const Vec3*, Vec3*, float, float);
extern const float lbl_8037899C, lbl_803789A4, lbl_803789A8, lbl_803789AC, lbl_803789C4, lbl_803789F8,
    lbl_80378A04, lbl_80378A28, lbl_80378A4C, lbl_80378A50, lbl_80378A58;
}

extern "C" signed char fn_8007A330(Camera* self, float delta)
{
    self->busy = 1;
    if (self->state == 0 && self->enabled) {
        signed char hasSecond, hasFirst;
        float first, second;
        float input;
        Vec3 position;
        first = lbl_8037899C;
        second = lbl_8037899C;
        hasSecond = 0;
        hasFirst = 0;
        fn_80076D98(self, &position);
        position.y += self->height;
        fn_800B742C(lbl_801E9D24.settings, 2, &input, 0, 0);
        signed char visible = fn_800793D0(self, &self->current, &position);
        if (!visible) {
            self->busy = 0;
            self->timer += delta;
            self->flagE9 = 0;
            self->flag130 = 1;
            fn_80079CB8(self);
            fn_8007963C(self, &position, &first, &second, &hasSecond, &hasFirst);
        } else {
            self->timer = lbl_8037899C;
        }
        if (hasSecond && (!hasFirst || absLE(first, second))) {
            if (first > lbl_8037899C)
                self->speed19C += -(lbl_80378A50 * delta) * (lbl_80378A04 * delta);
            else
                self->speed19C += (lbl_80378A50 * delta) * (lbl_80378A04 * delta);
            self->roll13C += self->speed19C;
        }
        if (visible) {
            self->speed19C = lbl_8037899C;
            float damping = lbl_80378A58 * delta;
            if (damping > lbl_803789A8)
                self->roll13C /= damping;
            else
                self->roll13C *= lbl_803789C4;
        }
        double absRoll = __fabs(self->roll13C);
        float limit = lbl_803789F8 * delta;
        if ((float)absRoll > limit) {
            if (self->roll13C > lbl_8037899C)
                self->roll13C = limit;
            else
                self->roll13C = -limit;
        }
        if (lbl_8037899C != self->roll13C)
            fn_80078284(self, self->roll13C);
        if (self->current.x != self->target.x || self->current.y != self->target.y || self->current.z != self->target.z) {
            if (fn_8007ACAC(self) == 1) {
                if (self->state == 0) {
                    self->up = Vec3(lbl_8037899C, lbl_803789A4, lbl_8037899C);
                    fn_8007D4B4(&self->direction, &self->up, &self->direction, lbl_80378A28, delta);
                }
                self->desired = self->target;
                self->current = self->target;
                self->moved224 = 1;
            } else {
                self->moved224 = fn_8007AA9C(self, delta);
            }
        }
        if (hasFirst && (!hasSecond || absLE(second, first))) {
            if (second > lbl_8037899C)
                self->speed1A0 += -(lbl_803789AC * delta) * (lbl_80378A04 * delta);
            else
                self->speed1A0 += (lbl_803789AC * delta) * (lbl_80378A04 * delta);
            self->roll138 += self->speed1A0;
        }
        if (visible) {
            self->speed1A0 = lbl_8037899C;
            float damping = lbl_80378A4C * delta;
            if (damping > lbl_803789A8)
                self->roll138 /= damping;
            else
                self->roll138 *= lbl_803789C4;
        }
        if ((float)__fabs(self->roll138) > limit) {
            if (self->roll138 > lbl_8037899C)
                self->roll138 = limit;
            else
                self->roll138 = -limit;
        }
        if (lbl_8037899C != self->roll138)
            fn_80078194(self, self->roll138);
        if (self->current.x != self->target.x || self->current.y != self->target.y || self->current.z != self->target.z) {
            if (fn_8007ACAC(self) == 1) {
                if (self->state == 0) {
                    self->up = Vec3(lbl_8037899C, lbl_803789A4, lbl_8037899C);
                    fn_8007D4B4(&self->direction, &self->up, &self->direction, lbl_80378A28, delta);
                }
                self->desired = self->target;
                self->current = self->target;
                self->moved225 = 1;
            } else {
                self->moved225 = fn_8007AA9C(self, delta);
            }
        }
    }
    return self->moved224 || self->moved225;
}
