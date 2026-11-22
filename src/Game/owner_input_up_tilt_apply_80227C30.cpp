/* slot5C__13ObjectThrow_ZFv: owner input apply (calls the base slot5C__12ObjectMove_ZFv first and returns
   its result). Below a pitch limit the input direction is replaced by the up
   axis tilted toward it: axis = normalize(up x direction) with a bare
   reciprocal-square-root estimate, a fixed-angle quaternion
   (cos at +0, axis * sin after it) rotates the up vector (fn_801F1B1C) into
   +0x1C4; otherwise +0x1C4 copies the direction. A band of the direction's y
   sets an owner flag. With input flags 0x60, a sampled point (fn_801D8FD0,
   flag 0x20) or the in-place local point at +0x1E8 (fn_801D8DC0) is rotated
   by the 3x3 part of the input object's matrix (+0x124) and flagged.
   Matching notes: the first up temp reads its z through a pointer and the
   rotated up temp its x (pooled literals, separate CSE expressions); the
   rotation is an inline method whose up local is declared before its output
   so the frame order matches; the sampled point lives in an inline helper. */
extern "C" {
extern const float lbl_8037B13C, lbl_8037B140, lbl_8037B144, lbl_8037B148, lbl_8037B14C, lbl_8037B150, lbl_8037B154;
float fn_8028506C(float);
float fn_80284FA8(float);
}

inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 cross(const Vec3& o) const { return Vec3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x); }
    Vec3& normalize()
    {
        float s = rsqrt(x * x + y * y + z * z);
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct Quat;
extern "C" void fn_801F1B1C(Vec3*, const Quat*, const Vec3*);
struct Quat {
    float w;
    Vec3 v;
    Quat(const Vec3& axis, float angle)
    {
        w = fn_8028506C(angle);
        float s = fn_80284FA8(angle);
        v.x = axis.x * s;
        v.y = axis.y * s;
        v.z = axis.z * s;
    }
    void rotateUp(Vec3& dest) const
    {
        Vec3 up(*(const float*)&lbl_8037B140, lbl_8037B144, lbl_8037B140);
        Vec3 out;
        fn_801F1B1C(&out, this, &up);
        dest = out;
    }
};

struct Matrix {
    float m[3][4];
    Vec3 rotate(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z;
        r.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z;
        r.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z;
        return r;
    }
};

struct Range { float minimum, maximum; };

struct InputObject { char unknown00[0x124]; Matrix* matrix; };

struct Input {
    char unknown00[0x10];
    Vec3 direction;
    int field1C;
    char field20[8];
    unsigned long long flags;
    InputObject* object;
    void* field34;
};

struct Owner {
    char unknown00[0x30];
    unsigned long long flags;
    char unknown38[0x18C];
    Vec3 up;
    char unknown1D0[0xC];
    Vec3 point;
    Vec3 local;
};

extern "C" {
int slot5C__12ObjectMove_ZFv(Owner*, const Input*, const Input*, int);
void fn_801D8FD0(Vec3*, void*, int, const Range*, const void*);
signed char fn_801D8DC0(void*, int, const void*, Vec3*);
}

inline void samplePoint(Vec3& dest, const Matrix* matrix, void* field, const Input* input)
{
    Range range;
    range.minimum = lbl_8037B140;
    range.maximum = lbl_8037B154;
    Vec3 point;
    fn_801D8FD0(&point, field, input->field1C, &range, input->field20);
    dest = matrix->rotate(point);
}

extern "C" int slot5C__13ObjectThrow_ZFv(Owner* self, const Input* input, const Input* comparison, int index)
{
    int result = slot5C__12ObjectMove_ZFv(self, input, comparison, index);
    float y = input->direction.y;
    if (y < lbl_8037B13C) {
        Vec3 axis = Vec3(lbl_8037B140, lbl_8037B144, *(const float*)&lbl_8037B140).cross(input->direction).normalize();
        Quat q(axis, lbl_8037B148);
        q.rotateUp(self->up);
    } else {
        self->up = input->direction;
    }
    if (y < lbl_8037B14C && y > lbl_8037B150) self->flags |= 0x200000000000ULL;
    if (input->flags & 0x60ULL) {
        Matrix* matrix = input->object->matrix;
        void* field = input->field34;
        if (input->flags & 0x20ULL) {
            samplePoint(self->point, matrix, field, input);
            self->flags |= 0x8000000000000ULL;
        } else if (fn_801D8DC0(field, input->field1C, input->field20, &self->local)) {
            self->local = matrix->rotate(self->local);
            self->flags |= 0x10000000000000ULL;
        }
    }
    return result;
}
