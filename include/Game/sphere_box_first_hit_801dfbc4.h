#ifndef GAME_SPHERE_BOX_FIRST_HIT_801DFBC4_H
#define GAME_SPHERE_BOX_FIRST_HIT_801DFBC4_H

typedef unsigned long long SphereBoxMask;

struct SphereBoxPoint {
    float x, y, z;
    SphereBoxPoint() {}
    SphereBoxPoint(float a, float b, float c) : x(a), y(b), z(c) {}
    SphereBoxPoint(const SphereBoxPoint& p) : x(p.x), y(p.y), z(p.z) {}
    SphereBoxPoint& operator=(const SphereBoxPoint& p) {
        x = p.x; y = p.y; z = p.z;
        return *this;
    }
};

extern "C" const float lbl_8037A4E4;
struct SphereBoxVertex {float x,y,z,w; SphereBoxVertex(const SphereBoxPoint& p) {x=p.x; y=p.y; z=p.z; w=lbl_8037A4E4;} };

struct SphereBoxMatrix {
    float m[4][4];
    SphereBoxPoint transform(const SphereBoxPoint& p) const {
        float x = m[3][0] + (m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z);
        float y = m[3][1] + (m[0][1] * p.x + m[1][1] * p.y + m[2][1] * p.z);
        float z = m[3][2] + (m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
        return SphereBoxPoint(x, y, z);
    }
};

struct SphereBoxHit {
    SphereBoxPoint point;
    float distance;
    SphereBoxPoint normal;
    unsigned int unknown1C;
    float unknown20, unknown24;
    unsigned int unknown28, unknown2C;
};

struct SphereBoxResult {
    SphereBoxPoint point;
    float distance;
    SphereBoxPoint normal;
    char unknown1C[0x28 - 0x1C];
    SphereBoxMask flags;
    unsigned int unknown30, unknown34, unknown38;
    signed char valid;
};

extern "C" {
extern SphereBoxPoint lbl_80340AC0[8];
extern const int lbl_802EAA10[6][4];
signed char fn_801B7C18(void*, const SphereBoxVertex&, const SphereBoxVertex&, const SphereBoxVertex&, const SphereBoxVertex&, SphereBoxHit*);
}


// Fields after the normal are observed stores in fn_8027B140. Their meanings are unknown.
extern "C" signed char fn_801DFBC4(void*, const SphereBoxMatrix*, SphereBoxResult*, SphereBoxMask);
typedef char SphereBoxPointSize[sizeof(SphereBoxPoint) == 12 ? 1 : -1];
typedef char SphereBoxVertexSize[sizeof(SphereBoxVertex) == 16 ? 1 : -1];
typedef char SphereBoxHitSize[sizeof(SphereBoxHit) == 48 ? 1 : -1];
typedef char SphereBoxMatrixSize[sizeof(SphereBoxMatrix) == 64 ? 1 : -1];

#endif
