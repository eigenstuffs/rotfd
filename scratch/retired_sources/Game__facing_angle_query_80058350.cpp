/* Angle between an owner's forward axis and the direction to another owner
   (fn_80058350): the owner's rotation rows (+0x30) transform the unit Z axis
   and the result is normalized; the vector from the owner's matrix position
   (+0x124, translation row) to the other owner's is fast-normalized and then
   normalized; the result is fn_80284DD8 (arc cosine) of their dot product.
   The engine fast normalizations use a bare reciprocal-square-root estimate
   (frsqrte with no frsp), which no compiler built-in emits, so it is written
   as a minimal inline asm statement.
   The original 0.0f and 1.0f literals were pooled into the shared .sdata2
   labels lbl_8037859C and lbl_803785AC. The compiler reuses a loaded literal
   only within a basic block but keeps a loaded label for the whole function,
   so the second normalize re-reads the zero through a volatile access (the
   original literal reload), and one axis component is read through a pointer,
   which keeps the original register order of the two pooled constants. */
extern "C" float fn_80284DD8(float);
extern "C" const float lbl_8037859C;
extern "C" const float lbl_803785AC;

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    Vec3& fastNormalize()
    {
        float x2 = x * x;
        float y2 = y * y;
        float z2 = z * z;
        register float sq = x2 + y2 + z2;
        register float inv;
        asm { frsqrte inv, sq }
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }
    void normalize()
    {
        register float sq = x * x + y * y + z * z;
        if (sq != lbl_8037859C) {
            register float inv;
            asm { frsqrte inv, sq }
            x *= inv;
            y *= inv;
            z *= inv;
        }
    }
    void normalizeReloaded()
    {
        register float sq = x * x + y * y + z * z;
        if (sq != *(const volatile float*)&lbl_8037859C) {
            register float inv;
            asm { frsqrte inv, sq }
            x *= inv;
            y *= inv;
            z *= inv;
        }
    }
};

struct FacingMatrix {
    float m[16];
    Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); }
};

struct FacingRotation {
    Vec3 r0, r1, r2;
    Vec3 transform(const Vec3& v) const
    {
        Vec3 result;
        result.x = r0.x * v.x + r1.x * v.y + r2.x * v.z;
        result.y = r0.y * v.x + r1.y * v.y + r2.y * v.z;
        result.z = r0.z * v.x + r1.z * v.y + r2.z * v.z;
        return result;
    }
};

struct FacingOwner {
    char unknown00[0x30];
    FacingRotation rotation;
    char unknown54[0x124 - 0x54];
    FacingMatrix* matrix;
    Vec3 getPos() const { return matrix->getPos(); }
};

extern "C" float fn_80058350(void* self, FacingOwner* owner, FacingOwner* other)
{
    Vec3 forward;
    forward = owner->rotation.transform(
        Vec3(*(const float*)&lbl_8037859C, lbl_8037859C, lbl_803785AC));
    forward.normalize();
    Vec3 direction = (other->getPos() - owner->getPos()).fastNormalize();
    direction.normalizeReloaded();
    return fn_80284DD8(forward.dot(direction));
}
