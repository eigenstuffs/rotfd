// Original TU 801F05D4..801F0980: node world-transform update and the HFog_Z.h
// factory constructor.  Both share the TU literal pool .sdata2 0x8037A6B8..0x8037A6C4
// (1.0f, 0.0f, 0.8f in first-use order); the following 4 bytes are alignment padding
// in front of the next TU's 8-aligned .sdata2.
// Node world-transform update: local = T * R, local *= S, world = parent * local,
// then bounding centre / radius from the local matrix.
extern "C" {
void* memset(void*, int, unsigned long);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float sqrtOrZero(float sq, float zero)
{
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) { }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    float dot() const { return x * x + y * y + z * z; }
    float length(float zero) const { return sqrtOrZero(dot(), zero); }
};
struct Quat { float w, x, y, z; };
struct Matrix4;
extern "C" {
void fn_801F1D90(const Quat*, Matrix4*);
void fn_801F1080(const Matrix4*, const Matrix4*, Matrix4*);
Matrix4* fn_801F2788(Matrix4*, const Matrix4*);
}
struct Matrix4 {
    float m[4][4];
    Matrix4() {}
    void identity()
    {
        memset(this, 0, sizeof(Matrix4));
        m[0][0] = 1.0f;
        m[1][1] = 1.0f;
        m[2][2] = 1.0f;
        m[3][3] = 1.0f;
    }
    Vec3 transformPoint(const Vec3& v) const
    {
        Vec3 p;
        p.x = m[3][0] + (m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z);
        p.y = m[3][1] + (m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z);
        p.z = m[3][2] + (m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z);
        return p;
    }
    Vec3 transformVector(const Vec3& v) const
    {
        float x = v.x;
        float y = v.y;
        float z = v.z;
        float rx = m[0][0] * x + m[1][0] * y + m[2][0] * z;
        float ry = m[0][1] * x + m[1][1] * y + m[2][1] * z;
        float rz = m[0][2] * x + m[1][2] * y + m[2][2] * z;
        return Vec3(rx, ry, rz);
    }
};

static inline Matrix4 product(const Matrix4& left, const Matrix4& right)
{
    Matrix4 result;
    fn_801F1080(&left, &right, &result);
    return result;
}
inline Matrix4 operator*(const Matrix4& left, const Matrix4& right) { Matrix4 result; fn_801F1080(&left, &right, &result); return result; }

struct Parent {
    char unknown00[0x124];
    Matrix4* world;
};
struct Node {
    char unknown00[0xC];
    Vec3 center;
    float radius;
    char unknown1C[0x68];
    Vec3 position;
    Vec3 scale;
    Quat rotation;
    Matrix4 local;
    Matrix4 world;
    void updateLocal() {
    Matrix4 scale;
    Matrix4 translation;
    Matrix4 rotation;
    scale.identity();
    scale.m[0][0] = this->scale.x;
    scale.m[1][1] = this->scale.y;
    scale.m[2][2] = this->scale.z;
    fn_801F1D90(&this->rotation, &rotation);
    translation.identity();
    translation.m[3][0] = position.x;
    translation.m[3][1] = position.y;
    translation.m[3][2] = position.z;
    local = product(translation, rotation);
    fn_801F2788(&local, &scale);
    }
    void updateWorld(Parent* parent) { world = product(*parent->world, local); }
    void updateBounds() {
    Vec3 v(0.0f, 0.8f, 0.0f);
    center = local.transformPoint(v);
    radius = local.transformVector(v).length(0.0f);
    }
};

extern "C" void fn_801F05D4(Node* self, Parent* parent)
{
    self->updateLocal(); self->world = product(*parent->world, self->local); self->updateBounds();
}

/* Observed initialized prefix of the object allocated by the HFog_Z.h
 * factory. The remaining object fields retain their existing state. */
struct FogPrefix_801F0920 {
    char unknown00[8];
    void* table;
    char unknown0C[0x60];
    unsigned short kind;
    unsigned short flags;
    char unknown70[4];
    float field74, field78, field7C;
};

extern "C" {
    void fn_80243F28(FogPrefix_801F0920*);
    extern char lbl_802EA958[];

    FogPrefix_801F0920* fn_801F0920(FogPrefix_801F0920* self) {
        fn_80243F28(self);
        self->table = lbl_802EA958;
        self->kind = 13;
        self->field74 = 1.0f;
        self->field78 = 1.0f;
        self->field7C = 1.0f;
        unsigned short enabledFlags = self->flags;
        enabledFlags |= 0x20;
        self->flags = enabledFlags;
        return self;
    }
}
