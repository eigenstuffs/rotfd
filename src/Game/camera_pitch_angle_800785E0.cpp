/* Pitch of the camera-relative vector (fn_800785E0): fn_800784A8 fills the
   vector, its height is kept and cleared, and the result is the degree angle
   (radians-to-degrees scale lbl_803789EC) of atan2(height, horizontal XZ
   length); zero when both are zero. The heading sibling is
   early_misc_event_control_80079024.cpp and the horizontal-length use is
   early_camera_orbit_place_80078194.cpp.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in the
   math helper. The original zero was a literal that the compiler reloads
   after the square-root branch; with the shared label lbl_8037899C that
   reload needs common-subexpression elimination off for this function (as
   in platform_trig.cpp). No multiply-add contraction occurs (fp_contract
   off, the default of the neighboring early_camera_query units). */
#pragma fp_contract off

extern "C" const float lbl_8037899C;
extern "C" const float lbl_803789EC;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec3 {
    float x, y, z;
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

extern "C" {
void fn_800784A8(void*, Vec3*);
float fn_80285124(float, float);
}

#pragma opt_common_subs off
extern "C" float fn_800785E0(void* self)
{
    Vec3 v;
    fn_800784A8(self, &v);
    float y = v.y;
    v.y = lbl_8037899C;
    float horizontal = v.length();
    float result = lbl_8037899C;
    if (result != y || result != horizontal)
        result = lbl_803789EC * fn_80285124(y, horizontal);
    return result;
}
#pragma opt_common_subs on
