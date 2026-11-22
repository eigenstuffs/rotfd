struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
};
struct Face {
    char unknown00[0x58];
    unsigned short edges[4];
    unsigned long flags;
    char unknown64[0x2C];
};
struct Edge {
    unsigned short ends[2];
    unsigned short ctrl[2];
    int End(int s) const { return ends[s]; }
    int Ctrl(int s) const { return ctrl[s]; }
};
template <class T> struct Arr {
    T* items;
    T& operator[](int i) { return items[i]; }
};
struct Owner {
    char unknown00[0xB8];
    Arr<Edge> edges;
};
#pragma inline_max_size(100000)
#define ENDS(e, s) self->edges[e].End(s)
#define CTRL(e, s) self->edges[e].Ctrl(s)
inline void Build(Owner* self, Face* face, Vec3* out, Vec3* pts, int s0, int s1, int s2, int s3) {
    int e;
    e = face->edges[0];
    out[0] = pts[ENDS(e, s0)];
    out[1] = pts[CTRL(e, s0)];
    out[2] = pts[CTRL(e, s0 ^ 1)];
    e = face->edges[1];
    out[3] = pts[ENDS(e, s1)];
    out[7] = pts[CTRL(e, s1)];
    out[11] = pts[CTRL(e, s1 ^ 1)];
    e = face->edges[2];
    out[15] = pts[ENDS(e, s2)];
    out[14] = pts[CTRL(e, s2)];
    out[13] = pts[CTRL(e, s2 ^ 1)];
    e = face->edges[3];
    out[12] = pts[ENDS(e, s3)];
    out[8] = pts[CTRL(e, s3)];
    out[4] = pts[CTRL(e, s3 ^ 1)];

}
#undef ENDS
#undef CTRL
#define ENDS(e, s) self->edges[e].End(s)
#define CTRL(e, s) self->edges[e].Ctrl(s)
extern "C" void fn_801D8068(Owner* self, Face* face, Vec3* out, Vec3* pts) {
    int s1 = (face->flags & 4) >> 2;
    int s2 = (face->flags & 8) >> 3;
    int s3 = (face->flags & 16) >> 4;
    Build(self, face, out, pts, (face->flags & 2) >> 1, s1, s2, s3);
    out[5] = out[4] + out[1] - out[0];
    out[6] = out[2] + out[7] - out[3];
    out[10] = out[11] + out[14] - out[15];
    out[9] = out[13] + out[8] - out[12];
}
