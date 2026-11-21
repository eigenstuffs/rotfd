/* Camera orbit pitch set (fn_80078660): with the camera vector at 0x100
   lowered by the height at 0xDC, the yaw (degrees, atan2(z, x)) and the full
   vector length are taken; when the flag is set the current pitch
   (fn_80078414, inlined: the height is restored around it) is added to the
   pitch parameter. The vector is then rebuilt from the spherical angles at
   the same length (vertical = len * sin(pitch); horizontal = sqrt|len^2 - y^2|
   through the MSL Newton square root on the shared 0.0/0.5/3.0 doubles
   lbl_80378A10/18/20, also used by fn_8007963C) and raised again.
   The length's zero is read through a pointer so the pitch default reloads
   it (the original literal was not reused); the yaw radians reuse the pitch
   parameter, and the sine is a separate local (fmuls sin, len). */
extern "C" const float lbl_8037899C, lbl_803789EC, lbl_803789E8;
extern "C" const double lbl_80378A10, lbl_80378A18, lbl_80378A20;
extern "C" {
extern int __float_nan[], __float_huge[];
double __frsqrte(double);
float fn_80285124(float, float);
float fn_8028506C(float);
float fn_80284FA8(float);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline double squareRoot(double x)
{
    if (x > lbl_80378A10) {
        double guess = __frsqrte(x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        return x * guess;
    } else if (lbl_80378A10 == x)
        return lbl_80378A10;
    else if (x != lbl_80378A10)
        return *(float*)__float_nan;
    return *(float*)__float_huge;
}

struct Vec3 {
    float x, y, z;
    float length() const
    {
        float dz = z;
        float dx = x;
        float dy = y;
        float sq = dx * dx + dy * dy + dz * dz;
        float r = *(const float*)&lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float flatLength(float flatY) const
    {
        float dx = x;
        float dz = z;
        float sq = dx * dx + flatY + dz * dz;
        float r = flatY;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Camera {
    char unknown00[0xDC];
    float height;
    char unknownE0[0x20];
    Vec3 offset;
};

inline float cameraPitch(Camera* self)
{
    float flatY = lbl_8037899C;
    self->offset.y -= self->height;
    float len = self->offset.flatLength(flatY);
    float result = lbl_8037899C;
    if (result != self->offset.y || result != len) result = lbl_803789EC * fn_80285124(self->offset.y, len);
    self->offset.y += self->height;
    return result;
}

extern "C" void fn_80078660(Camera* self, char flag, float pitch)
{
    float yaw = lbl_8037899C;
    self->offset.y -= self->height;
    if (yaw != self->offset.z || yaw != self->offset.x)
        yaw = lbl_803789EC * fn_80285124(self->offset.z, self->offset.x);
    float len = self->offset.length();
    float current = lbl_8037899C;
    if (flag) {
        self->offset.y += self->height;
        current = cameraPitch(self);
        self->offset.y -= self->height;
    }
    pitch += current;
    float s = fn_80284FA8(lbl_803789E8 * pitch);
    self->offset.y = s * len;
    float y = self->offset.y;
    float horizontal = len * len - y * y;
    if (horizontal < lbl_8037899C) horizontal = -horizontal;
    float h = squareRoot(horizontal);
    pitch = lbl_803789E8 * yaw;
    self->offset.x = fn_8028506C(pitch);
    self->offset.z = fn_80284FA8(pitch);
    self->offset.x *= h;
    self->offset.z *= h;
    self->offset.y += self->height;
}
