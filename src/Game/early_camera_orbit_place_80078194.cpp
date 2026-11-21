/* Places the camera point at 0xF4 on the horizontal circle around the
   context position: the yaw (fn_80079024) advanced by the given delta, at
   the horizontal length of the camera-relative vector (fn_800784A8).  The
   engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in
   the math helper. */
struct QueryVector;
struct QueryCamera;

extern "C" {
float fn_80079C34(QueryCamera*);
float fn_80079024(QueryCamera*);
void fn_800784A8(QueryCamera*, QueryVector*);
void fn_80076D98(QueryCamera*, QueryVector*);
float fn_8028506C(float);
float fn_80284FA8(float);
extern const float lbl_8037899C, lbl_803789E8;
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct QueryVector {
    float x, y, z;
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct QueryCamera {
    char unknown00[0xF4];
    QueryVector current;
};

extern "C" void fn_80078194(QueryCamera* self, float delta)
{
    fn_80079C34(self);
    float angle = fn_80079024(self);
    angle += delta;
    QueryVector v;
    fn_800784A8(self, &v);
    v.y = lbl_8037899C;
    float length = v.length();
    angle = lbl_803789E8 * angle;
    self->current.x = length * fn_8028506C(angle);
    self->current.z = length * fn_80284FA8(angle);
    QueryVector position;
    fn_80076D98(self, &position);
    self->current.x += position.x;
    self->current.z += position.z;
}
