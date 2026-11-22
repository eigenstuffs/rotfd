/* Merged game math translation unit, .text 0x801F1184-0x801F2A4C (random .. math globals).
   .sdata2 0x8037A6E0-0x8037A72C is this unit's literal pool in first-use order. */

/* Reconstructed seeded generator and shuffle state; see unit notes. */
struct ConsoleArguments {
    unsigned char prefix[0x860];
    int argc;
    unsigned char reserved_864[0x8A5-0x864];
    signed char arg1IsNumeric;
    unsigned char reserved_8a6[0x8B8-0x8A6];
    float arg1Value;
};
extern "C" {
extern struct { unsigned char prefix[0x110]; ConsoleArguments *console; } lbl_801E9D24;
extern long game_random_seed;
extern long game_random_selected,game_random_table[32];
extern signed char game_random_initialized;
double floor(double);
float fn_801F12D4(long *);
int fn_801F1184()
{
    ConsoleArguments *console=lbl_801E9D24.console;
    if(console->argc>=1 && console->arg1IsNumeric) {
        int value=(int)console->arg1Value;
        game_random_seed=value<0?value:-value;
        fn_801F12D4(&game_random_seed);
    } else return 0;
    return 1;
}
float fn_801F1200() { return fn_801F12D4(&game_random_seed); }
int fn_801F1224(int minimum,int maximum)
{
    return minimum+(int)floor((maximum-minimum+1)*fn_801F12D4(&game_random_seed));
}
void fn_801F129C(int value)
{
    game_random_seed=value<0?value:-value;
    fn_801F12D4(&game_random_seed);
}
float fn_801F12D4(long *state)
{
    int j; long k;
    // The original compiler guard is retained explicitly so state can live
    // in its own object without changing initialization or code generation.
    if(!game_random_initialized) {
        game_random_selected=0;
        game_random_initialized=1;
    }
    float result;
    if(*state<=0 || !game_random_selected) {
        if(-*state<1) *state=1;
        else *state=-*state;
        for(j=39;j>=0;--j) {
            k=*state/127773;
            *state=16807*(*state-k*127773)-2836*k;
            if(*state<0) *state+=2147483647;
            if(j<32) game_random_table[j]=*state;
        }
        game_random_selected=game_random_table[0];
    }
    k=*state/127773;
    *state=16807*(*state-k*127773)-2836*k;
    if(*state<0) *state+=2147483647;
    j=game_random_selected/67108864;
    game_random_selected=game_random_table[j];
    game_random_table[j]=*state;
    result=(1.0/2147483647)*game_random_selected;
    if(result>(1.0-1.2e-7)) return (1.0-1.2e-7);
    return result;
}
}



namespace part_801F14E0 {
// fn_801F14E0: quaternion turning the forward axis (0,0,1) onto direction a with up axis b
// (yaw about b by acos(flat.z), then pitch about normalize(flat x b) by acos(flat . a);
// result = pitch * yaw).  Original TU is random.cpp (game_math_* are its pooled literals).
// The 0.0f in flat must be a literal (0*0 folds); it is 0.0f in the original.
extern "C" { float fn_80284DD8(float); float fn_8028506C(float); float fn_80284FA8(float); }
struct Vec3{float x,y,z; Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
  Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
  Vec3& operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}
  Vec3 cross(const Vec3&b)const{return Vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);}
};
inline float dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 cross(const Vec3&a,const Vec3&b){return Vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
struct Quat{float w,x,y,z; Quat(){} Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}
  Quat(const Quat&o):w(o.w),x(o.x),y(o.y),z(o.z){}
  Quat& operator=(const Quat&o){w=o.w;x=o.x;y=o.y;z=o.z;return *this;}};
extern "C" const Quat game_quat_identity;
inline float fastSqrt(register float x){register float r=0.0f;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
inline float frsqrte(register float x){register float r;asm{frsqrte r,x}return r;}
inline float clampUnit(float c){if(c>1.0f)c=1.0f;if(c<-1.0f)c=-1.0f;return c;}
inline Quat axisAngle(const Vec3&axis,float angle){float half=angle/2.0f;Quat q;q.w=fn_8028506C(half);float s=fn_80284FA8(half);q.x=axis.x*s;q.y=axis.y*s;q.z=axis.z*s;return q;}
inline Quat mul(const Quat&l,const Quat&r){
    return Quat(
        l.w * r.w - l.x * r.x - l.y * r.y - l.z * r.z,
        l.w * r.x + l.x * r.w + l.y * r.z - l.z * r.y,
        l.w * r.y + l.y * r.w + l.z * r.x - l.x * r.z,
        l.w * r.z + l.z * r.w + l.x * r.y - l.y * r.x);
}

extern "C" void fn_801F14E0(const Vec3* a, const Vec3* b, Quat* out)
{
    Vec3 flat(a->x, 0.0f, a->z);
    float len = dot(flat, flat);
    if (len < 0.000001f) {
        *out = game_quat_identity;
        return;
    }
    Quat yaw;
    if (len > 0.000001f) {
        float inv = 1.0f / fastSqrt(len);
        flat.x *= inv; flat.y *= inv; flat.z *= inv;
        float angle = fn_80284DD8(clampUnit(flat.z));
        if (dot(*b, Vec3(0.0f, 0.0f, 1.0f).cross(flat)) < 0.0f) angle *= -1.0f;
        yaw = axisAngle(*b, angle);
    } else {
        flat = Vec3(0.0f, 0.0f, 1.0f);
        yaw = game_quat_identity;
        len = dot(*a, *a);
    }
    Quat pitch;
    if (len > 0.000001f) {
        Vec3 h = cross(flat, *b);
        float angle = fn_80284DD8(clampUnit(dot(flat, *a)));
        if (0.0f == h.x && 0.0f == h.y && 0.0f == h.z) {
            pitch = axisAngle(*b, angle);
        } else {
            Vec3 n;
            float lsq = dot(h, h);
            float s = frsqrte(lsq);
            n = Vec3(h.x * s, h.y * s, h.z * s);
            if (dot(n, cross(flat, *a)) < 0.0f) angle *= -1.0f;
            pitch = axisAngle(n, angle);
        }
    } else {
        *out = yaw;
        return;
    }
    *out = mul(pitch, yaw);
}
}

extern "C" { double __fabs(double); }

namespace part_801F18D0 {
/* Engine quaternion/basis helpers at 0x801F14E0..0x801F1C64 (part of the
   original math translation unit that follows random.cpp).
   - fn_801F14E0: quaternion turning the forward axis (0,0,1) onto direction a
     with up axis b: yaw about b by acos(flat.z) (sign from b . (fwd x flat)),
     then pitch about normalize(h x b) by acos(h . a), result = pitch * yaw.
   - fn_801F18D0: basis matrix (rows right, up, forward) from direction/up.
   - fn_801F1AAC: fast in-place quaternion normalization.
   - fn_801F1B1C: rotates a vector by a quaternion (q * v * conj(q)).
   - fn_801F1BB0: in-place quaternion product (a = a * b).
   Matching notes: the game_math_* labels are the original TU's pooled float
   literals; reads through *(const float*)& / (unsigned long) casts keep a use
   as a separate load as a literal was. Vec3/Quat have user-declared copy
   operations: with compiler-generated struct copies this compiler defers
   fn_801F14E0/fn_801F18D0 and emits them after the leaf functions, and the
   copies also change fn_801F14E0's register allocation. The temporary
   Vec3(0,0,1) receiving a member call is materialized at sp+8 (and the cross
   result at sp+0x14), as in the original. fn_801F18D0 needs expression
   propagation off; fn_801F1BB0 is closest with common subexpressions off.
   The fast sqrt / rsqrt helpers are the established inline asm ones. */
extern "C" { void* memset(void*,int,unsigned long); float fn_80284DD8(float); float fn_8028506C(float); float fn_80284FA8(float); }
struct Vec3{float x,y,z; Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
  Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
  Vec3& operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}
  Vec3 cross(const Vec3&b)const{return Vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);}
};
extern "C" const Vec3 game_vec3_zero;
inline float dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 cross(const Vec3&a,const Vec3&b){return Vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
struct Quat{float w,x,y,z; Quat(){} Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}
  Quat(const Quat&o):w(o.w),x(o.x),y(o.y),z(o.z){}
  Quat& operator=(const Quat&o){w=o.w;x=o.x;y=o.y;z=o.z;return *this;}};
extern "C" const Quat game_quat_identity;
struct Matrix4{float m[4][4];};
inline float fastSqrt(register float x){register float r=0.0f;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
inline float frsqrte(register float x){register float r;asm{frsqrte r,x}return r;}
inline float rsqrt(register float x){register float r=0.0f;if(x!=r){asm{frsqrte r,x}}return r;}
inline float clampUnit(float c){if(c>1.0f)c=1.0f;if(c<-1.0f)c=-1.0f;return c;}
inline Quat axisAngle(const Vec3&axis,float angle){float half=angle/2.0f;Quat q;q.w=fn_8028506C(half);float s=fn_80284FA8(half);q.x=axis.x*s;q.y=axis.y*s;q.z=axis.z*s;return q;}
inline Quat mul(const Quat&l,const Quat&r){
    return Quat(
        l.w * r.w - l.x * r.x - l.y * r.y - l.z * r.z,
        l.w * r.x + l.x * r.w + l.y * r.z - l.z * r.y,
        l.w * r.y + l.y * r.w + l.z * r.x - l.x * r.z,
        l.w * r.z + l.z * r.w + l.x * r.y - l.y * r.x);
}
inline int pairEqual(float x,float y){int result=0;if((float)__fabs(x)<0.000001f){if((float)__fabs(y)<0.000001f)result=1;}return result;}
inline signed char vecEqual(float x,float y,float z){signed char result=0;if(pairEqual(x,y)&&(float)__fabs(z)<0.000001f)result=1;return result;}


#pragma opt_propagation off
extern "C" void fn_801F18D0(const Vec3* dir, const Vec3* up, Matrix4* out) {
Vec3 c = cross(*dir, *up); Vec3 r;
  if (vecEqual(c.x-game_vec3_zero.x, c.y-game_vec3_zero.y, c.z-game_vec3_zero.z)) { r = Vec3(1.0f, 0.0f, 0.0f); }
  else { float s = frsqrte(c.x*c.x + c.y*c.y + c.z*c.z); r.x = c.x*s; r.y = c.y*s; r.z = c.z*s; }
  Vec3 u = cross(r, *dir);
  memset(out, 0, sizeof(Matrix4));
  out->m[0][0] = 1.0f; out->m[1][1] = 1.0f; out->m[2][2] = 1.0f; out->m[3][3] = 1.0f;
  out->m[0][0] = r.x; out->m[0][1] = r.y; out->m[0][2] = r.z;
  out->m[1][0] = u.x; out->m[1][1] = u.y; out->m[1][2] = u.z;
  out->m[2][0] = dir->x; out->m[2][1] = dir->y; out->m[2][2] = dir->z;
}
#pragma opt_propagation reset

extern "C" void fn_801F1AAC(Quat*q){
  float r = rsqrt(q->x*q->x + q->y*q->y + q->z*q->z + q->w*q->w);
  q->x*=r; q->y*=r; q->z*=r; q->w*=r;
}
}

namespace part_801F1B1C {
// fn_801F1B1C: rotate a vector by a quaternion (q * v * conj(q)).
// fn_801F1BB0: in-place quaternion product (a = a * b), vector formulation.
// Part of the random.cpp / game_math TU (-O4,p -fp_contract on, exceptions off).
// These two use plain (compiler-copied) vector structs; with the user-declared
// copy operations of the neighbouring functions' Vec3 the temporaries of
// fn_801F1BB0 are stored to the stack, so the types are kept separate here.
struct QVec3 {
    float x, y, z;
    QVec3() {}
    QVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct QuatWXYZ { float w, x, y, z; };
struct QuatWV { float w; QVec3 v; };

inline QVec3 operator*(const QVec3& a, float s) { return QVec3(a.x * s, a.y * s, a.z * s); }
inline QVec3 operator+(const QVec3& a, const QVec3& b) { return QVec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline QVec3& operator+=(QVec3& a, const QVec3& b) { a.x += b.x; a.y += b.y; a.z += b.z; return a; }
inline float dot(const QVec3& a, const QVec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline QVec3 cross(const QVec3& a, const QVec3& b)
{
    return QVec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

// Register allocation is declaration-order sensitive: results first
// (tx, ty, tw, nw, tz), then vx, the quaternion, vy, vz. Propagation must be
// off so tw stays a separate value from its negation nw.
#pragma opt_propagation off
extern "C" QVec3 fn_801F1B1C(const QuatWXYZ* q, const QVec3* v)
{
    float tx, ty, tw, nw, tz;
    float vx = v->x;
    float qw = q->w, qx = q->x, qy = q->y, qz = q->z;
    float vy = v->y, vz = v->z;
    tw = -qx * vx - qy * vy - qz * vz;
    tx = qw * vx + qy * vz - qz * vy;
    ty = qw * vy + qz * vx - qx * vz;
    tz = qw * vz + qx * vy - qy * vx;
    nw = -tw;
    return QVec3(
        nw * qx + tx * qw - ty * qz + tz * qy,
        nw * qy + ty * qw - tz * qx + tx * qz,
        nw * qz + tz * qw - tx * qy + ty * qx);
}
#pragma opt_propagation reset

extern "C" void fn_801F1BB0(QuatWV* a, const QuatWV* b)
{
    QVec3 t1 = b->v * a->w;
    QVec3 t2 = a->v * b->w;
    QVec3 s = t1 + t2;
    s += cross(a->v, b->v);
    a->w = a->w * b->w - dot(a->v, b->v);
    a->v = s;
}
}

namespace part_801F1C64 {
struct EngineQuaternionProduct {
    float w;
    float x;
    float y;
    float z;

    EngineQuaternionProduct(float a, float b, float c, float d)
        : w(a), x(b), y(c), z(d) {}
};

extern "C" EngineQuaternionProduct fn_801F1C64(
    const EngineQuaternionProduct* left, const EngineQuaternionProduct* right);



extern "C" EngineQuaternionProduct fn_801F1C64(
    const EngineQuaternionProduct* left, const EngineQuaternionProduct* right)
{
    return EngineQuaternionProduct(
        left->w * right->w - left->x * right->x - left->y * right->y - left->z * right->z,
        left->w * right->x + left->x * right->w + left->y * right->z - left->z * right->y,
        left->w * right->y + left->y * right->w + left->z * right->x - left->x * right->z,
        left->w * right->z + left->z * right->w + left->x * right->y - left->y * right->x);
}
}

namespace part_801F1CD8 {
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
 * - lbl_802EAA70 is the {1,2,0} next-axis table, 0.5/3.0 the
 *   0.5/3.0 doubles of the inlined sqrt; all are referenced, not owned. */
extern "C" {
extern int lbl_802EAA70[];
}

struct Quat { float w, x, y, z; };
struct Matrix3 { float m[3][3]; };
struct Matrix4 { float m[4][4]; };

/* Quaternion -> 3x3 / 4x4 rotation matrix. Product declaration order (.., xy, yz, xz, ..)
   is load-bearing for fn_801F25E8, which inlines fn_801F1D90. */
extern "C" void fn_801F1CD8(const Quat *q, Matrix3 *dst)
{
    float w = q->w, x = q->x, y = q->y, z = q->z;
    float xx = 2.0f * x * x, yy = 2.0f * y * y,
          zz = 2.0f * z * z, xy = 2.0f * x * y,
          yz = 2.0f * z * y, xz = 2.0f * x * z,
          wx = 2.0f * w * x, wy = 2.0f * w * y,
          wz = 2.0f * w * z;
    dst->m[0][0] = 1.0f - yy - zz;
    dst->m[1][0] = xy - wz;
    dst->m[2][0] = xz + wy;
    dst->m[0][1] = xy + wz;
    dst->m[1][1] = 1.0f - xx - zz;
    dst->m[2][1] = yz - wx;
    dst->m[0][2] = xz - wy;
    dst->m[1][2] = yz + wx;
    dst->m[2][2] = 1.0f - xx - yy;
}
extern "C" void fn_801F1D90(const Quat *q, Matrix4 *dst)
{
    float w = q->w, x = q->x, y = q->y, z = q->z;
    float xx = 2.0f * x * x, yy = 2.0f * y * y,
          zz = 2.0f * z * z, xy = 2.0f * x * y,
          yz = 2.0f * z * y, xz = 2.0f * x * z,
          wx = 2.0f * w * x, wy = 2.0f * w * y,
          wz = 2.0f * w * z;
    dst->m[0][0] = 1.0f - yy - zz;
    dst->m[1][0] = xy - wz;
    dst->m[2][0] = xz + wy;
    dst->m[3][0] = 0.0f;
    dst->m[0][1] = xy + wz;
    dst->m[1][1] = 1.0f - xx - zz;
    dst->m[2][1] = yz - wx;
    dst->m[3][1] = 0.0f;
    dst->m[0][2] = xz - wy;
    dst->m[1][2] = yz + wx;
    dst->m[2][2] = 1.0f - xx - yy;
    dst->m[3][2] = 0.0f;
    dst->m[0][3] = 0.0f;
    dst->m[1][3] = 0.0f;
    dst->m[2][3] = 0.0f;
    dst->m[3][3] = 1.0f;
}

inline float squareRoot(float x)
{
    volatile float y;
    if (x > 0.0f) {
        const double _half = 0.5;
        const double _three = 3.0;
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
    float scale = 0.0f;
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
    if (trace > 0.0f) {
        s = squareRoot(1.0f + trace);
        float inv = 0.5f / s;
        q->w = 0.5f * s;
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
        s = squareRoot(1.0f + (m->m[i][i] - m->m[j][j] - m->m[k][k]));
        (&q->x)[i] = 0.5f * s;
        s = (0.0f != s) ? 0.5f / s : s;
        q->w = s * (m->m[j][k] - m->m[k][j]);
        (&q->x)[j] = s * (m->m[i][j] + m->m[j][i]);
        (&q->x)[k] = s * (m->m[i][k] + m->m[k][i]);
    }
    normalize(q);
}
}

namespace part_quaternion_matrix_assign {
struct Vec3 { float x,y,z; };
struct Quat { float w; Vec3 v; };
struct Matrix3 { float m[3][3]; };
extern "C" void fn_801F1E78(Quat *,const Matrix3 *);
extern "C" Quat *fn_801F20F4(Quat *q,const Matrix3 *m)
{
    fn_801F1E78(q,m);
    return q;
}
}

namespace part_matrix3 {
static inline float dot(float x0,float x1,float x2,float y0,float y1,float y2) { return x0*y0+x1*y1+x2*y2; }
struct Matrix3 { float m[9]; };
static inline void multiply(Matrix3 *out,const Matrix3 *left,const Matrix3 *right)
{
    Matrix3 temp;
    for(int i=0;i<3;++i) {
        temp.m[i]=dot(right->m[0],left->m[i+3],left->m[i+6],left->m[i],right->m[1],right->m[2]);
        temp.m[i+3]=dot(right->m[3],left->m[i+3],left->m[i+6],left->m[i],right->m[4],right->m[5]);
        temp.m[i+6]=dot(right->m[6],left->m[i+3],left->m[i+6],left->m[i],right->m[7],right->m[8]);
    }
    *out=temp;
}
extern "C" {
void fn_801F2124(const Matrix3 *self,Matrix3 *out)
{
    out->m[0]=self->m[0];
    out->m[1]=self->m[3];
    out->m[2]=self->m[6];
    out->m[3]=self->m[1];
    out->m[4]=self->m[4];
    out->m[5]=self->m[7];
    out->m[6]=self->m[2];
    out->m[7]=self->m[5];
    out->m[8]=self->m[8];
}
void fn_801F2170(Matrix3 *out,const Matrix3 *left,const Matrix3 *right) { multiply(out,left,right); }
void fn_801F223C(Matrix3 *self,const Matrix3 *right) { multiply(self,self,right); }
}
}

namespace part_math_inverse {
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F230C(const Matrix4 *a, Matrix4 *b)
{
    float d=0.0f;
    d+=a->m[0][0]*a->m[1][1]*a->m[2][2];
    d+=a->m[1][0]*a->m[2][1]*a->m[0][2];
    d+=a->m[2][0]*a->m[0][1]*a->m[1][2];
    d-=a->m[2][0]*a->m[1][1]*a->m[0][2];
    d-=a->m[1][0]*a->m[0][1]*a->m[2][2];
    d-=a->m[0][0]*a->m[2][1]*a->m[1][2];
    float inv=1.0f/d;
    b->m[0][0]=inv*(a->m[1][1]*a->m[2][2]-a->m[2][1]*a->m[1][2]);
    b->m[0][1]=inv*-(a->m[0][1]*a->m[2][2]-a->m[2][1]*a->m[0][2]);
    b->m[0][2]=inv*(a->m[0][1]*a->m[1][2]-a->m[1][1]*a->m[0][2]);
    b->m[1][0]=inv*-(a->m[1][0]*a->m[2][2]-a->m[2][0]*a->m[1][2]);
    b->m[1][1]=inv*(a->m[0][0]*a->m[2][2]-a->m[2][0]*a->m[0][2]);
    b->m[1][2]=inv*-(a->m[0][0]*a->m[1][2]-a->m[1][0]*a->m[0][2]);
    b->m[2][0]=inv*(a->m[1][0]*a->m[2][1]-a->m[2][0]*a->m[1][1]);
    b->m[2][1]=inv*-(a->m[0][0]*a->m[2][1]-a->m[2][0]*a->m[0][1]);
    b->m[2][2]=inv*(a->m[0][0]*a->m[1][1]-a->m[1][0]*a->m[0][1]);
    b->m[3][0]=-(b->m[0][0]*a->m[3][0]+b->m[1][0]*a->m[3][1]+b->m[2][0]*a->m[3][2]);
    b->m[3][1]=-(b->m[0][1]*a->m[3][0]+b->m[1][1]*a->m[3][1]+b->m[2][1]*a->m[3][2]);
    b->m[3][2]=-(b->m[0][2]*a->m[3][0]+b->m[1][2]*a->m[3][1]+b->m[2][2]*a->m[3][2]);
    b->m[0][3]=0.0f;b->m[1][3]=0.0f;b->m[2][3]=0.0f;b->m[3][3]=1.0f;
}
void fn_801F250C(const Matrix4 *a, Matrix4 *b)
{
for(int i=0;i<3;++i) for(int j=0;j<3;++j) b->m[i][j]=a->m[j][i];
    b->m[3][0]=-(b->m[0][0]*a->m[3][0]+b->m[1][0]*a->m[3][1]+b->m[2][0]*a->m[3][2]);
    b->m[3][1]=-(b->m[0][1]*a->m[3][0]+b->m[1][1]*a->m[3][1]+b->m[2][1]*a->m[3][2]);
    b->m[3][2]=-(b->m[0][2]*a->m[3][0]+b->m[1][2]*a->m[3][1]+b->m[2][2]*a->m[3][2]);
    b->m[0][3]=0.0f;b->m[1][3]=0.0f;b->m[2][3]=0.0f;b->m[3][3]=1.0f;
}
}
}

namespace part_801F1CD8 {
/* fn_801F25E8: rotation (inlined fn_801F1D90), per-row scale, translation row. */
struct Vec3{float x,y,z;};
extern "C" void fn_801F25E8(Matrix4* dst, const Vec3* p, const Quat* q, const Vec3* s) {
  fn_801F1D90(q,dst);
  dst->m[0][0] *= s->x; dst->m[1][0] *= s->y; dst->m[2][0] *= s->z; dst->m[3][0] = p->x;
  dst->m[0][1] *= s->x; dst->m[1][1] *= s->y; dst->m[2][1] *= s->z; dst->m[3][1] = p->y;
  dst->m[0][2] *= s->x; dst->m[1][2] *= s->y; dst->m[2][2] *= s->z; dst->m[3][2] = p->z;
  dst->m[0][3] = 0.0f; dst->m[1][3] = 0.0f; dst->m[2][3] = 0.0f; dst->m[3][3] = 1.0f;
}
}

namespace part_math_multiply_assign {
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F1080(Matrix4 *,const Matrix4 *,Matrix4 *);
Matrix4 *fn_801F2788(Matrix4 *dst,const Matrix4 *rhs)
{
    fn_801F1080(dst,rhs,dst);
    return dst;
}
}
}

namespace part_quaternion_between_vectors_801F27BC {
/* fn_801F27BC: quaternion rotating direction u onto direction v.
   The axis is cross(u, v); its fast length (frsqrte/fres) is sin of the angle,
   and asin is taken on the far branch when dot(u, v) <= 0. Degenerate (near
   parallel) inputs give the identity rotation. The game_math_* labels are the
   original translation unit's pooled float literals: the second zero use is
   read through a cast so it stays a separate load, as a literal was. The
   (c * s) temporary is materialized on the stack because the member operator
   is called on it. */
extern "C" { double asin(double); double cos(double); double sin(double); }
struct Vec3{float x,y,z; Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
  Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
  Vec3 operator/(float d)const{float r=1.0f/d;return Vec3(x*r,y*r,z*r);}
};
extern "C" const Vec3 game_vec3_zero;
inline float dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 cross(const Vec3&a,const Vec3&b){return Vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
inline float fastSqrt(register float x){register float r=0.0f;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
struct Quat{float w; Vec3 v;};
extern "C" Quat* fn_801F27BC(Quat* q, const Vec3* u, const Vec3* v) {
  Vec3 c = cross(*u, *v);
  float len = fastSqrt(dot(c, c));
  if (len < 0.000001f) {
    q->w = 1.0f; q->v = game_vec3_zero;
  } else {
    float half;
    if (dot(*u, *v) > 0.0f) { float angle = (float)asin(len); half = angle / 2.0f; }
    else { float angle = 3.1415927f - (float)asin(len); half = angle / 2.0f; }
    q->w = (float)cos(half);
    q->v = (c * (float)sin(half)) / len;
  }
  return q;
}
}

namespace part_math_transform {
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Matrix4 { float m[4][4]; };
extern "C" {
void fn_801F295C(Vec4 *dst,const Matrix4 *m,const Vec3 *v)
{
    float x=m->m[0][0]*v->x+m->m[1][0]*v->y+m->m[2][0]*v->z+m->m[3][0];
    float y=m->m[0][1]*v->x+m->m[1][1]*v->y+m->m[2][1]*v->z+m->m[3][1];
    float z=m->m[0][2]*v->x+m->m[1][2]*v->y+m->m[2][2]*v->z+m->m[3][2];
    dst->x=x;dst->y=y;dst->z=z;dst->w=1.0f;
}
}
}

namespace part_math_globals {
struct Int3 { int x,y,z; Int3(int a,int b,int c):x(a),y(b),z(c){} };
struct Vec2 { float x,y; Vec2(float a,float b):x(a),y(b){} };
struct Vec3 { float x,y,z; Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Vec4 { float x,y,z,w; Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){} };
struct Quat { float w,x,y,z; Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){} };
extern "C" {
Int3 game_int3_zero(0,0,0);
Vec2 game_vec2_zero(0.0f,0.0f);
Vec3 game_vec3_zero(0.0f,0.0f,0.0f);
Vec4 game_vec4_zero(0.0f,0.0f,0.0f,0.0f);
Quat game_quat_identity(1.0f,0.0f,0.0f,0.0f);
}
}
