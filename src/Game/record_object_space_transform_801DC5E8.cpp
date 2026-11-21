/* Transform a run of 0x28-byte sphere/direction records into an object's
   space (fn_801DC5E8): each record's point goes through the 4x4 matrix at
   object +0x124, its direction through the object's 3x3 basis at +0x30, its
   radius is scaled by the length of the matrix's first column, and the
   record remembers the object. Called from fn_801DC718.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as the same minimal inline asm statement
   in the math helper as src/Game/owner_position_distance_80066DA4.cpp.
   The zero is the shared lbl_8037A4E0 (0.0f). Both transforms build their
   result in a named local; returning a constructed temporary instead changes
   the load order and register allocation. Vec3 needs its user-declared empty
   default constructor: without it the code no longer matches (and gains an
   exception-table record under -Cpp_exceptions on). */
extern "C" const float lbl_8037A4E0;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float vectorLength(float x, float y, float z)
{
    float sq = x * x + y * y + z * z;
    float r = lbl_8037A4E0;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
};

struct Matrix {
    float m[16];
    float scale() const { return vectorLength(m[0], m[4], m[8]); }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
};

struct Basis {
    float m[9];
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0] * v.x + m[3] * v.y + m[6] * v.z;
        r.y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
        r.z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
        return r;
    }
};

struct Object {
    char unknown00[0x30];
    Basis basis;
    char unknown54[0x124 - 0x54];
    Matrix* matrix;
};

struct Record {
    Vec3 point;
    float radius;
    Vec3 direction;
    Object* object;
    char unknown20[8];
};

typedef char RecordSize[sizeof(Record) == 0x28 ? 1 : -1];
typedef char ObjectSize[sizeof(Object) == 0x128 ? 1 : -1];

extern "C" void fn_801DC5E8(Record* records, int count, Object* object)
{
    Matrix* matrix = object->matrix;
    float scale = matrix->scale();
    for (int i = 0; i != count; i++) {
        records->point = matrix->transform(records->point);
        records->direction = object->basis.transform(records->direction);
        records->radius *= scale;
        records->object = object;
        records++;
    }
}
