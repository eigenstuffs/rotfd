// Partial collision views preserve the observed vertex, matrix and result ABI.
struct BoxVector3 {
    float x, y, z;
    BoxVector3() {}
    BoxVector3(float a, float b, float c) : x(a), y(b), z(c) {}
    BoxVector3& operator=(const BoxVector3& other) {
        x = other.x; y = other.y; z = other.z;
        return *this;
    }
};

struct BoxVector4 {
    float x, y, z, w;
    BoxVector4(const BoxVector4& other)
        : x(other.x), y(other.y), z(other.z), w(other.w) {}
    BoxVector4(const BoxVector3& point, float fourth)
        : x(point.x), y(point.y), z(point.z), w(fourth) {}
};

struct BoxMatrix {
    float a[16];
    BoxVector3 transform(const BoxVector3& point) const {
        BoxVector3 result;
        result.x = a[12] + (a[8] * point.z + (a[0] * point.x + a[4] * point.y));
        result.y = a[13] + (a[9] * point.z + (a[1] * point.x + a[5] * point.y));
        result.z = a[14] + (a[10] * point.z + (a[2] * point.x + a[6] * point.y));
        return result;
    }
};

struct BoxContact {
    BoxVector3 position;
    float distance;
    BoxVector3 normal;
    char unknown1C[20];
};

struct BoxHit {
    BoxVector3 position;
    float distance;
    BoxVector3 normal;
    char unknown1C[12];
    unsigned long long identity;
    char unknown30[12];
    signed char valid;
};
struct BoxEdge { int a, b; };
struct BoxFace { int a, b, c, d; };

extern "C" {
extern BoxVector3 lbl_80340AC0[8];
extern BoxEdge lbl_802EA9B0[12];
extern BoxFace lbl_802EAA10[6];
extern const float lbl_8037A4E4;
signed char fn_801B6DD4(void*, BoxVector4, BoxContact*);
signed char fn_801B85B0(void*, BoxVector4, BoxVector4, BoxContact*);
signed char fn_801B74D8(void*, BoxVector4, BoxVector4, BoxVector4, BoxVector4, BoxContact*);
}

inline void boxKeepHit(BoxHit* output, const BoxContact& hit,
                       unsigned long long identity, int& result) {
    if (!output->valid || hit.distance < output->distance) {
        output->valid = 1;
        result = 1;
        output->identity = identity;
        output->normal = hit.normal;
        output->position = hit.position;
        output->distance = hit.distance;
    }
}

extern "C" int fn_801DDBFC(void* self, const BoxMatrix* matrix,
                            BoxHit* output, unsigned long long identity) {
    const BoxFace* faces = lbl_802EAA10;
    int result;
    BoxVector3 points[8];
    BoxContact hit;
    int i;
    for (i = 0; i < 8; ++i)
        points[i] = matrix->transform(lbl_80340AC0[i]);
    result = 0;
    for (i = 0; i < 8; ++i) {
        if (fn_801B6DD4(self, BoxVector4(points[i], lbl_8037A4E4), &hit))
            boxKeepHit(output, hit, identity, result);
    }
    for (i = 0; i < 12; ++i) {
        if (fn_801B85B0(self,
                       BoxVector4(points[lbl_802EA9B0[i].a], lbl_8037A4E4),
                       BoxVector4(points[lbl_802EA9B0[i].b], lbl_8037A4E4), &hit))
            boxKeepHit(output, hit, identity, result);
    }
    for (i = 0; i < 6; ++i) {
        if (fn_801B74D8(self,
                       BoxVector4(points[faces[i].a], lbl_8037A4E4),
                       BoxVector4(points[faces[i].b], lbl_8037A4E4),
                       BoxVector4(points[faces[i].c], lbl_8037A4E4),
                       BoxVector4(points[faces[i].d], lbl_8037A4E4), &hit))
            boxKeepHit(output, hit, identity, result);
    }
    return result;
}

typedef char BoxPointSize[sizeof(BoxVector3) == 12 ? 1 : -1];
typedef char BoxVertexSize[sizeof(BoxVector4) == 16 ? 1 : -1];
typedef char BoxMatrixSize[sizeof(BoxMatrix) == 64 ? 1 : -1];
typedef char BoxContactSize[sizeof(BoxContact) == 48 ? 1 : -1];
typedef char BoxResultSize[sizeof(BoxHit) == 64 ? 1 : -1];
