/* Quaternion <-> rotation-matrix conversions (engine math, 801F1CD8..801F20F4).
 *
 *   fn_801F1CD8  unit quaternion (w,x,y,z) -> 3x3 rotation matrix
 *   fn_801F1D90  unit quaternion (w,x,y,z) -> 4x4 homogeneous rotation matrix
 *   fn_801F1E78  3x3 rotation matrix -> quaternion (trace / largest-diagonal
 *                branches, MSL-style Newton sqrt, fast frsqrte normalization)
 *
 * Matching notes:
 * - The original translation unit used pooled float literals (now the shared
 *   game_math_* objects owned by random.cpp).  The 1-xx term of the diagonal
 *   is a separate pooled-literal read (distinct read form, kept in a local)
 *   so the compiler merges the two loads of 1.0f the way it did for the
 *   original literal; the sqrt helper's zero test uses a distinct read form
 *   for the same reason.
 * - `component()` reads a raw quaternion component; it keeps the original
 *   (doubled, raw) operand order of the products, which the compiler would
 *   otherwise canonicalize to (raw, doubled).
 * - The final normalization uses the engine's bare frsqrte estimate
 *   (reciprocalSqrt helper, as in other matched engine math units).
 * - lbl_802EAA70 is the {1,2,0} next-axis table, lbl_8037A718/lbl_8037A720 the
 *   0.5/3.0 doubles of the inlined sqrt; all are referenced, not owned. */
extern "C" {
extern const float game_math_zero, game_math_one, game_math_half, game_math_two;
extern const double lbl_8037A718, lbl_8037A720;
extern int lbl_802EAA70[];
}

struct Quat { float w, x, y, z; };
struct Matrix3 { float m[3][3]; };
struct Matrix4 { float m[4][4]; };

inline float component(float v) { return v; }

extern "C" void fn_801F1CD8(const Quat *q, Matrix3 *dst)
{
    float oneMinusXX;
    float w = q->w, x = q->x, y = q->y, z = q->z;
    float xx = game_math_two * x * component(x), yy = game_math_two * y * component(y),
          zz = game_math_two * z * component(z), xy = game_math_two * x * component(y),
          xz = game_math_two * x * component(z), yz = game_math_two * z * component(y),
          wx = game_math_two * w * component(x), wy = game_math_two * w * component(y),
          wz = game_math_two * w * component(z);
    dst->m[0][0] = game_math_one - yy - zz;
    dst->m[1][0] = xy - wz;
    dst->m[2][0] = xz + wy;
    dst->m[0][1] = xy + wz;
    oneMinusXX = *(const float *)&game_math_one - xx;
    dst->m[1][1] = oneMinusXX - zz;
    dst->m[2][1] = yz - wx;
    dst->m[0][2] = xz - wy;
    dst->m[1][2] = yz + wx;
    dst->m[2][2] = oneMinusXX - yy;
}

extern "C" void fn_801F1D90(const Quat *q, Matrix4 *dst)
{
    float oneMinusXX;
    float w = q->w, x = q->x, y = q->y, z = q->z;
    float xx = game_math_two * x * component(x), yy = game_math_two * y * component(y),
          zz = game_math_two * z * component(z), xy = game_math_two * x * component(y),
          xz = game_math_two * x * component(z), yz = game_math_two * z * component(y),
          wx = game_math_two * w * component(x), wy = game_math_two * w * component(y),
          wz = game_math_two * w * component(z);
    dst->m[0][0] = game_math_one - yy - zz;
    dst->m[1][0] = xy - wz;
    dst->m[2][0] = xz + wy;
    dst->m[3][0] = game_math_zero;
    dst->m[0][1] = xy + wz;
    oneMinusXX = *(const float *)&game_math_one - xx;
    dst->m[1][1] = oneMinusXX - zz;
    dst->m[2][1] = yz - wx;
    dst->m[3][1] = game_math_zero;
    dst->m[0][2] = xz - wy;
    dst->m[1][2] = yz + wx;
    dst->m[2][2] = oneMinusXX - yy;
    dst->m[3][2] = game_math_zero;
    dst->m[0][3] = game_math_zero;
    dst->m[1][3] = game_math_zero;
    dst->m[2][3] = game_math_zero;
    dst->m[3][3] = game_math_one;
}

inline float squareRoot(float x)
{
    volatile float y;
    if (x > *(const float *)&game_math_zero) {
        const double _half = lbl_8037A718;
        const double _three = lbl_8037A720;
        double guess = __frsqrte((double)x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        y = (float)(x * guess);
        return y;
    }
    return x;
}

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

inline void normalize(Quat *q)
{
    float length = q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w;
    float scale = game_math_zero;
    if (length != scale)
        scale = reciprocalSqrt(length);
    q->x *= scale;
    q->y *= scale;
    q->z *= scale;
    q->w *= scale;
}

extern "C" void fn_801F1E78(Quat *q, const Matrix3 *m)
{
    float trace = m->m[0][0] + m->m[1][1] + m->m[2][2];
    float s;
    if (trace > game_math_zero) {
        s = squareRoot(game_math_one + trace);
        float inv = game_math_half / s;
        q->w = game_math_half * s;
        q->x = inv * (m->m[1][2] - m->m[2][1]);
        q->y = inv * (m->m[2][0] - m->m[0][2]);
        q->z = inv * (m->m[0][1] - m->m[1][0]);
    } else {
        int i = 0;
        if (m->m[1][1] > m->m[0][0])
            i = 1;
        if (m->m[2][2] > m->m[i][i])
            i = 2;
        int j = lbl_802EAA70[i], k = lbl_802EAA70[j];
        s = squareRoot(game_math_one + (m->m[i][i] - m->m[j][j] - m->m[k][k]));
        (&q->x)[i] = game_math_half * s;
        s = (game_math_zero != s) ? game_math_half / s : s;
        q->w = s * (m->m[j][k] - m->m[k][j]);
        (&q->x)[j] = s * (m->m[i][j] + m->m[j][i]);
        (&q->x)[k] = s * (m->m[i][k] + m->m[k][i]);
    }
    normalize(q);
}
