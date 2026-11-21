/* fn_8008D420: quaternion spherical interpolation (w at +0, vector at +4).
   The cosine is the 4D dot product clamped to [-1, 1]; when it is negative
   the second quaternion is negated in place (its parameter is a mutable
   reference) and the cosine flipped.  For a non-zero angle the result is
   (a*sin((1-t)*angle) + b*sin(t*angle)) / sin(angle), otherwise a copy of b;
   it is normalized by fn_801F1AAC and returned through the hidden pointer.

   Matching notes (GC/1.3): the clamp's 1.0f assignment reads the pooled label
   through a pointer so it stays a distinct expression from the compare; the
   (1 - t) factor is a named local, and the zero label is compared first. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3 operator*(float a) const { return Vec3(x * a, y * a, z * a); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
};

struct Quat {
    float w;
    Vec3 v;
    Quat() {}
    Quat(const Quat& q) { w = q.w; v.x = q.v.x; v.y = q.v.y; v.z = q.v.z; }
    Quat& operator=(const Quat& q) { w = q.w; v.x = q.v.x; v.y = q.v.y; v.z = q.v.z; return *this; }
};

extern "C" {
extern const float lbl_80378ADC; /* 1.0f */
extern const float lbl_80378B74; /* -1.0f */
extern const float lbl_80378AD0; /* 0.0f */
double acos(double);
float fn_80284FA8(float);
void fn_801F1AAC(Quat*);
}

extern "C" Quat fn_8008D420(const Quat& a, Quat& b, float t)
{
    float c = a.w * b.w + a.v.dot(b.v);
    if (c >= lbl_80378ADC) c = *(const float*)&lbl_80378ADC;
    else if (c <= lbl_80378B74) c = lbl_80378B74;
    float cosine = c;
    if (c < lbl_80378AD0) {
        b.v = -b.v;
        b.w = -b.w;
        cosine = -c;
    }
    float angle = acos(cosine);
    Quat r;
    if (lbl_80378AD0 != angle) {
        float inv = lbl_80378ADC / fn_80284FA8(angle);
        float u = lbl_80378ADC - t;
        float s1 = fn_80284FA8(u * angle);
        float s2 = fn_80284FA8(t * angle);
        r.v = (a.v * s1 + b.v * s2) * inv;
        r.w = inv * (a.w * s1 + b.w * s2);
    } else {
        r = b;
    }
    fn_801F1AAC(&r);
    return r;
}
