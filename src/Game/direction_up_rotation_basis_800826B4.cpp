/* fn_800826B4: builds an up-to-direction rotation from the owned object's
   direction vector (+0x1B8). Unless the direction already equals the up
   axis (0,1,0) within 1e-6 per component, it is normalized with a bare
   reciprocal-square-root estimate. The rotation axis is up x dir and a
   second basis vector is axis x dir (both normalized in their returned
   temporaries, hence the dead stack stores); the half angle is
   acos(dir . up) * 0.5 and its cosine/sine are computed (fn_8028506C /
   fn_80284FA8) but the results are unused.
   Matching notes: the equality test copies the pooled 0.0f/1.0f into float
   locals; the axis cross product reads the labels directly so the shared
   0*dir.y product is CSE'd; the absolute x difference is held as a double
   local before the float compare (fabs/frsp in separate registers). */
extern "C" {
extern const float lbl_80378AD0, lbl_80378AD8, lbl_80378ADC, lbl_80378AEC;
double acos(double);
double __fabs(double);
float fn_8028506C(float);
float fn_80284FA8(float);
}

inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

inline bool pairEqual(float x, float y)
{
    bool result = false;
    double ax = __fabs(x);
    if ((float)ax < lbl_80378AD8) {
        if ((float)__fabs(y) < lbl_80378AD8) result = true;
    }
    return result;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    Vec3 cross(const Vec3& o) const { return Vec3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x); }
    signed char equals(const Vec3& o) const { return (*this - o).isZero(); }
    signed char isZero() const
    {
        signed char result = 0;
        if (pairEqual(x, y) && (float)__fabs(z) < lbl_80378AD8) result = 1;
        return result;
    }
    Vec3& normalize()
    {
        float s = rsqrt(x * x + y * y + z * z);
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct Object { char unknown00[0x1B8]; Vec3 direction; };
struct Owner { char unknown00[8]; Object* object; };

extern "C" void fn_800826B4(Owner* self)
{
    Vec3 dir = self->object->direction;
    float zero = lbl_80378AD0;
    float one = lbl_80378ADC;
    if (!dir.equals(Vec3(zero, one, zero))) dir.normalize();
    Vec3 up(lbl_80378AD0, lbl_80378ADC, lbl_80378AD0);
    Vec3 axis = Vec3(lbl_80378ADC * dir.z - lbl_80378AD0 * dir.y,
                     lbl_80378AD0 * dir.x - lbl_80378AD0 * dir.z,
                     lbl_80378AD0 * dir.y - lbl_80378ADC * dir.x).normalize();
    Vec3 side = axis.cross(dir).normalize();
    float angle = acos(dir.dot(up));
    float half = angle * lbl_80378AEC;
    fn_8028506C(half);
    fn_80284FA8(half);
}
