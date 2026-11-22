/* Actor move input (slot1A0__14CJellyfishMoveFPCf): store the input vector at 0x3B8; when the
   planar (XZ) speed of the velocity at 0x15C is below the threshold at 0x3B4
   and neither control 0 nor 1 is active (fn_8007D604 query), stop controls 1
   and 2 (fn_8007D7F4) and start control 0 (fn_8007D6A0); while control 1 is
   active, add the input scaled by 0x370 (read before the calls) to the vector
   at 0x358. The Vec3 operator* temporary keeps the three products ahead of
   the adds (no fmadds). The engine square root is the bare reciprocal of a
   reciprocal-square-root estimate (frsqrte into f4, then fres), written as the
   established minimal inline asm math helper. */
extern "C" const float lbl_80378D10;
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
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    float planarLength() const
    {
        float sq = x * x + z * z;
        float r = lbl_80378D10;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Node {
    char unknown0[0x15C];
    Vec3 velocity;
    char unknown168[0x318 - 0x168];
    char control;
    char unknown319[0x358 - 0x319];
    Vec3 offset;
    char unknown364[0x370 - 0x364];
    float scale;
    char unknown374[0x3B4 - 0x374];
    float threshold;
    Vec3 input;
};
extern "C" {
signed char fn_8007D604(void*, int);
void fn_8007D7F4(void*, int);
void fn_8007D6A0(void*, int);
}
extern "C" void slot1A0__14CJellyfishMoveFPCf(Node* self, const Vec3* v)
{
    self->input = *v;
    float scale = self->scale;
    if (self->velocity.planarLength() < self->threshold && !fn_8007D604(&self->control, 0) && !fn_8007D604(&self->control, 1)) {
        fn_8007D7F4(&self->control, 1);
        fn_8007D7F4(&self->control, 2);
        fn_8007D6A0(&self->control, 0);
    }
    if (fn_8007D604(&self->control, 1)) {
        self->offset += *v * scale;
    }
}
