/* Camera orbit pitch update (fn_80078284): adds the pitch delta to the current
   camera pitch (fn_800785E0); when the pitch cosine turns negative the yaw
   (fn_80079024) flips by 180 degrees and the two orientation signs at 0x13C
   and 0x19C are negated. The pitch is clamped at 80 degrees and the camera
   point at 0xF4 is rebuilt from the spherical angles, scaled by the camera
   distance (fn_80079C34) and offset by the raised context position.
   The parameter is reused for the pitch and then for the horizontal
   magnitude: the absolute cosine stays a double until after the sine
   argument is formed, which keeps the parameter, pitch and magnitude in one
   register (f29) with the double temporary in f2, as in the original. The
   yaw radians are a separate local (scaling yaw in place swaps f28/f29).
   The raise vector reads one zero through a pointer (see
   camera_query_offset_vector_800784A8.cpp). */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    void operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
};

struct Camera {
    char unknown00[0xDC];
    float height;
    char unknownE0[0x14];
    Vec3 current;
    char unknown100[0x3C];
    float sign13C;
    char unknown140[0x5C];
    float sign19C;
};

extern "C" {
float fn_80079C34(Camera*);
float fn_80079024(Camera*);
float fn_800785E0(Camera*);
void fn_80076D98(Camera*, Vec3*);
float fn_8028506C(float);
float fn_80284FA8(float);
double __fabs(double);
extern const float lbl_803789E8, lbl_8037899C, lbl_803789A0, lbl_80378A0C;
}

extern "C" void fn_80078284(Camera* self, float pitch)
{
    float distance = fn_80079C34(self);
    float yaw = fn_80079024(self);
    float current = fn_800785E0(self);
    pitch = current + pitch;
    float cosPitch = fn_8028506C(lbl_803789E8 * pitch);
    if (cosPitch < lbl_8037899C) {
        yaw += lbl_803789A0;
        self->sign13C = -self->sign13C;
        self->sign19C = -self->sign19C;
    }
    if (pitch >= lbl_80378A0C) pitch = lbl_80378A0C;
    double horizontal = __fabs(cosPitch);
    float pitchRadians = lbl_803789E8 * pitch;
    pitch = (float)horizontal;
    float vertical = fn_80284FA8(pitchRadians);
    float yawRadians = lbl_803789E8 * yaw;
    self->current.x = pitch * fn_8028506C(yawRadians);
    self->current.y = vertical;
    self->current.z = pitch * fn_80284FA8(yawRadians);
    self->current *= distance;
    Vec3 position;
    fn_80076D98(self, &position);
    self->current += position + Vec3(lbl_8037899C, self->height, *(const float*)&lbl_8037899C);
}
