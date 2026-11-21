// Partial text split: fn_80242A24 only. fn_8024222C before it (96.9%:
// register colouring in its colour-blend loops) remains original code;
// full draft: scratch/claude_match/auto_03_8024222C_text/final.cpp.
typedef unsigned long Word;
extern "C" {
extern const float lbl_8037B358, lbl_8037B35C, lbl_8037B360, lbl_8037B364, lbl_8037B368, lbl_8037B36C;
}
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    float length() const
    {
        const float& a = x;
        const float& b = y;
        const float& c = z;
        float sq = a * a + b * b + c * c;
        float r = lbl_8037B358;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Edge {
    int first, second;
    char unknown08[0xF0];
};
inline const int& secondVertex(const Edge& e) { return e.second; }
struct Polygon {
    int kind;
    Word unknown04;
    unsigned short* edges;
    char unknown0C[12];
    int edgeAt(int n) const { return edges[n]; }
    unsigned short flags;
    char unknown1A[6];
};
struct Mesh {
    char unknown00[0x7C];
    Vec3* vertices;
    char unknown80[8];
    Edge* edges;
    char unknown8C[0x14];
    int count, capacity;
    Polygon* polygons;
};
struct Record {
    float angle;
    float radius;
    float deltaY;
    float distance;
    float unknown10;
    float value14;
    float value18;
    float color[4];
    unsigned short flags;
    unsigned short edge;
    unsigned short vertex;
    unsigned short unknown32;
    float length;
    Vec3 dir;
};
struct Readback {
    int index;
    Word handle;
    int count;
    int indices[4];
    Record records[4];
};
struct Result {
    unsigned char active;
    Vec3 first;
    Vec3 second;
    float radius;
    float value20;
    float value24;
    float color[4];
    float deltaY;
    float distance;
};
extern "C" int fn_80242A24(Mesh* self, const Vec3* pos, const Readback* faces, Result* out)
{
    out->active = 0;
    int i;
    for (i = 0; i < self->count; i++)
        if (self->polygons[i].kind == 3)
            break;
    if (self->count != 2)
        return 0;
    if (i == self->count)
        return 0;
    const Record& rec = faces->records[0];
    int k;
    for (k = 0; k < 3; k++)
        if (rec.edge == self->polygons[i].edgeAt(k))
            break;
    int next = (k + 1) % 3;
    const Polygon& poly = self->polygons[i];
    unsigned short mask = 1 << next;
    unsigned short edge = poly.edges[next];
    if (mask & poly.flags)
        out->second = self->vertices[secondVertex(self->edges[edge])];
    else
        out->second = self->vertices[self->edges[edge].first];
    out->radius = rec.radius + lbl_8037B36C;
    out->value20 = rec.value14;
    out->first = self->vertices[rec.vertex];
    out->deltaY = out->second.y - out->first.y;
    out->distance = (out->second - out->first).length();
    return 1;
}
