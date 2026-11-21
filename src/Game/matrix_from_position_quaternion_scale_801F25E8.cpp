/* fn_801F25E8: compose a 4x4 transform from a unit quaternion (w,x,y,z),
   per-row scale and translation: the inlined quaternion->matrix body of
   fn_801F1D90 (row-vector layout, last column 0,0,0,1), rows scaled by
   scale, translation row = position.
   Matching notes: game_math_* are the pooled float literals of the original
   TU. The distinct read forms of game_math_two emulate the original's
   separate literal loads (merged by the backend), and z2/w2/oneMinusXX are
   declared locals; together they reproduce the original FPR colouring
   (w2 f31, 1-xx f30). component() keeps the (doubled, raw) product order.
   Flags as quaternion_matrix_conversions_801F1CD8.cpp (-O4,p, no EH). */
extern "C" { extern const float game_math_zero, game_math_one, game_math_two; }
struct Vec3{float x,y,z;};
struct Quat{float w,x,y,z;};
struct Matrix4{float m[4][4];};
inline float component(float v) { return v; }
inline void setRotation(Matrix4* dst, const Quat* q) {
    float oneMinusXX;
    float w2;
    float z2;
    float x = q->x;
    float w = q->w;
    float y = q->y;
    float z = q->z;
    z2 = *(const float *)(unsigned int)&game_math_two * z;
    w2 = *(const float *)(long)&game_math_two * w;
    float xx = *(const float *)(long)&game_math_two * x * component(x);
    float yy = *(const float *)&game_math_two * y * component(y);
    float zz = z2 * component(z);
    float yz = z2 * component(y);
    float xy = *(const float *)(long)&game_math_two * x * component(y);
    float xz = *(const float *)(long)&game_math_two * x * component(z);
    float wx = w2 * component(x);
    float wy = w2 * component(y);
    float wz = w2 * component(z);
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
extern "C" void fn_801F25E8(Matrix4* dst, const Vec3* p, const Quat* q, const Vec3* s) {
  setRotation(dst,q);
  dst->m[0][0] *= s->x; dst->m[1][0] *= s->y; dst->m[2][0] *= s->z; dst->m[3][0] = p->x;
  dst->m[0][1] *= s->x; dst->m[1][1] *= s->y; dst->m[2][1] *= s->z; dst->m[3][1] = p->y;
  dst->m[0][2] *= s->x; dst->m[1][2] *= s->y; dst->m[2][2] *= s->z; dst->m[3][2] = p->z;
  dst->m[0][3] = game_math_zero; dst->m[1][3] = game_math_zero; dst->m[2][3] = game_math_zero; dst->m[3][3] = game_math_one;
}
