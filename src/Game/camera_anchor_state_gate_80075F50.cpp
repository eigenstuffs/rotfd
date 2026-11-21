/* Camera anchor gate (fn_80075F50): when the context position (fn_80076D98)
   is within the external radius of the anchor at 0x158, any of six target
   control states blocks the gate. The offset is a reference-bound temporary,
   which keeps its original stack copy. The engine square root is the bare
   reciprocal of a reciprocal-square-root estimate (frsqrte into f4, then
   fres, with no frsp), which no compiler built-in produces; it is written as
   a minimal inline asm statement in the math helper. */
extern "C" const float lbl_8037899C, lbl_803789BC;
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
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Handle { union { unsigned long value; struct { signed int tag : 8; signed int index : 24; } bits; }; };
struct Node { char unknown00[0x318]; char stateData; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" Context lbl_801E9D24;
inline Node* resolve(const Handle& h) { Entry* e = &lbl_801E9D24.manager->entries[h.bits.index]; if (e->tag == h.bits.tag) return e->object; return 0; }
struct Camera { char unknown00[0x24]; Handle target; char unknown28[0x130]; Vec3 anchor; };
extern "C" { signed char fn_8007D604(void*, int); void fn_80076D98(Camera*, Vec3*); }
extern "C" signed char fn_80075F50(Camera* self)
{
    Vec3 position;
    fn_80076D98(self, &position);
    const Vec3& offset = position - self->anchor;
    if (offset.length() < lbl_803789BC) {
        if (fn_8007D604(&resolve(self->target)->stateData, 0) ||
            fn_8007D604(&resolve(self->target)->stateData, 13) ||
            fn_8007D604(&resolve(self->target)->stateData, 6) ||
            fn_8007D604(&resolve(self->target)->stateData, 24) ||
            fn_8007D604(&resolve(self->target)->stateData, 53) ||
            fn_8007D604(&resolve(self->target)->stateData, 51))
            return 0;
    }
    return 1;
}
