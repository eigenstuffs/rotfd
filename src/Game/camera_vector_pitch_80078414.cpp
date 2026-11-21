/* Camera pitch (fn_80078414): the elevation angle, in degrees, of the camera
   vector at 0x100 after lowering it by the height at 0xDC; the vector is
   restored before returning. The yaw sibling is fn_80079024.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in the
   math helper, as in the other camera distance units. The flattened Y term
   is the shared 0.0f constant. The original's literal 0.0f is not reused
   across blocks, so the pitch default reloads it. Reading the flattened term
   before the height store ends that value's availability, which reproduces
   the reload with the shared label. */
extern "C" const float lbl_8037899C, lbl_803789EC;
extern "C" float fn_80285124(float, float);

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec3 {
    float x, y, z;
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

extern "C" float fn_80078414(Camera* self)
{
    float flatY = lbl_8037899C;
    self->offset.y -= self->height;
    float len = self->offset.flatLength(flatY);
    float result = lbl_8037899C;
    if (result != self->offset.y || result != len) result = lbl_803789EC * fn_80285124(self->offset.y, len);
    self->offset.y += self->height;
    return result;
}
