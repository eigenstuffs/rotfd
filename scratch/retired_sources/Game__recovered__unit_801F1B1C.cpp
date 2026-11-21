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
