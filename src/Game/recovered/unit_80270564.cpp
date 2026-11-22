struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2& operator=(const Vec2& o) { x = o.x; y = o.y; return *this; }
};
struct Vec3 { float x, y, z; };
struct Vector3_801D5330 {
    float x, y, z;
    Vector3_801D5330();
};
struct Slot { Vec3 v; float pad; };
struct Row_80271060 { Slot s[4]; };
typedef Row_80271060 Row;
struct Grid { Row a, b, c, d; Row& operator[](int i) { return (&a)[i]; } };
struct Vertex {
    Vec3 normal;
    Vec3 color;
    Vec2 uv;
};
struct Patch {
    Vec2 uv[4];
    Vec3 color[4];
    unsigned short index[4];
};
struct Surface {
    char unknown00[0x6E];
    unsigned short flags;
};
struct Context {
    char unknown00[0xBCC];
    int steps;
    char unknownBD0[8];
    Vec3* normals;
    int stride;
};
struct Output {
    Vec3* positions;
    Vec3* normals;
    unsigned long* colors;
    Vec2* uvs;
};
struct Material {
    char unknown00[0x18];
    float alpha;
};
extern "C" {
extern const float lbl_8037B6A8;
extern const float lbl_8037B6AC;
extern const float lbl_8037B6B0;
extern const float lbl_8037B6B4;
extern const float lbl_8037B6B8;
Vec2 fn_801D7EFC(const Vec2&, float);
Vec2 fn_801D7F18(const Vec2&, const Vec2&);
void fn_801D7F3C(Vec3*, const Vec3*);
Vec3 fn_801D7F70(const Vec3&, const Vec3&);
Vec3 fn_801D7FA4(const Vec3&, float);
Vec3 fn_801D7FCC(const Vec3&);
Vec2 fn_801D7FF4(const Vec2&, const Vec2&);
void fn_801D8018(Vec3*, const Vec3&);
Vec3 fn_801D8034(const Vec3&, const Vec3&);
void fn_801D8068(Surface*, const Patch*, Vector3_801D5330*, int);
void fn_801D8458(Surface*, const Patch*, Vector3_801D5330*, int);
void fn_80270F34(Vertex*, const Vertex*);
void fn_80271060(Row_80271060*);
signed char fn_80270F78(Material*, int);
}
#define MUL fn_801D7FA4
#define ADD fn_801D8034
#define SUB fn_801D7F70
#define NEG fn_801D7FCC
#define SET fn_801D8018
#define ACC fn_801D7F3C

inline void addUV(Vec2& a, const Vec2& b) { a.x += b.x; a.y += b.y; }
inline void accumulate(Vertex& a, Vertex& b)
{
    addUV(a.uv, b.uv);
    ACC(&a.color, &b.color);
    ACC(&a.normal, &b.normal);
}

extern "C" void fn_80270564(Surface* self, Context* ctx, const Patch* patch, Output* out, Material* material)
{
    Vector3_801D5330 pts[16];
    Grid fd;
    fn_80271060(&fd.a);
    fn_80271060(&fd.b);
    fn_80271060(&fd.c);
    fn_80271060(&fd.d);
    Vec3 nrm[4];
    Vertex cur;
    Vertex dV;
    Vertex dU;
    Vertex dUV;
    Vertex work;
    Vec3 q0, q1, q2, q3;
    Vec3 a, b, c, d;
    int alpha;
    const Vec3* p;
    int i, j, k, m;
    Row* row;

    if (fn_80270F78(material, 0)) alpha = (int)(lbl_8037B6A8 * material->alpha);
    else alpha = 0xFF;
    if (self->flags & 4) fn_801D8068(self, patch, pts, ctx->stride);
    else fn_801D8458(self, patch, pts, ctx->stride);
    int n = ctx->steps;
    float du = lbl_8037B6AC / (float)n;
    float du2 = du * du;
    float du3 = du2 * du;
    row = &fd.a;
    p = (const Vec3*)pts;
    for (i = 0; i < 4; i++) {
        SET(&a, ADD(SUB(ADD(NEG(p[0]), MUL(p[4], lbl_8037B6B0)), MUL(p[8], lbl_8037B6B0)), p[12]));
        SET(&b, ADD(SUB(MUL(p[0], lbl_8037B6B0), MUL(p[4], lbl_8037B6B4)), MUL(p[8], lbl_8037B6B0)));
        SET(&c, ADD(MUL(NEG(p[0]), lbl_8037B6B0), MUL(p[4], lbl_8037B6B0)));
        SET(&d, p[0]);
        SET(&row->s[0].v, d);
        SET(&row->s[1].v, ADD(ADD(MUL(a, du3), MUL(b, du2)), MUL(c, du)));
        SET(&row->s[3].v, MUL(MUL(a, du3), lbl_8037B6B4));
        SET(&row->s[2].v, ADD(row->s[3].v, MUL(MUL(b, lbl_8037B6B8), du2)));
        p++;
        row++;
    }
    k = 0;
    i = n + 1;
    do {
        SET(&a, ADD(SUB(ADD(NEG(fd[0].s[0].v), MUL(fd[1].s[0].v, lbl_8037B6B0)), MUL(fd[2].s[0].v, lbl_8037B6B0)), fd[3].s[0].v));
        SET(&b, ADD(SUB(MUL(fd[0].s[0].v, lbl_8037B6B0), MUL(fd[1].s[0].v, lbl_8037B6B4)), MUL(fd[2].s[0].v, lbl_8037B6B0)));
        SET(&c, ADD(MUL(NEG(fd[0].s[0].v), lbl_8037B6B0), MUL(fd[1].s[0].v, lbl_8037B6B0)));
        SET(&d, fd[0].s[0].v);
        SET(&q0, d);
        SET(&q1, ADD(ADD(MUL(a, du3), MUL(b, du2)), MUL(c, du)));
        SET(&q2, MUL(MUL(b, lbl_8037B6B8), du2));
        SET(&q3, MUL(MUL(a, lbl_8037B6B4), du3));
        j = n + 1;
        do {
            SET(&out->positions[k++], q0);
            ACC(&q0, &q1);
            ACC(&q2, &q3);
            ACC(&q1, &q2);
        } while (--j);
        for (j = 0, row = &fd.a; j < 4; j++) {
            ACC(&row->s[0].v, &row->s[1].v);
            ACC(&row->s[1].v, &row->s[2].v);
            ACC(&row->s[2].v, &row->s[3].v);
            row++;
        }
    } while (--i);
    SET(&nrm[0], ctx->normals[patch->index[0]]);
    SET(&nrm[1], ctx->normals[patch->index[1]]);
    SET(&nrm[2], ctx->normals[patch->index[2]]);
    SET(&nrm[3], ctx->normals[patch->index[3]]);
    SET(&cur.normal, nrm[0]);
    SET(&dU.normal, MUL(SUB(nrm[1], nrm[0]), du));
    SET(&dV.normal, MUL(SUB(nrm[3], nrm[0]), du));
    SET(&dUV.normal, MUL(SUB(ADD(nrm[2], nrm[0]), ADD(nrm[1], nrm[3])), du2));
    cur.uv = patch->uv[0];
    dU.uv = fn_801D7EFC(fn_801D7F18(patch->uv[1], patch->uv[0]), du);
    dV.uv = fn_801D7EFC(fn_801D7F18(patch->uv[3], patch->uv[0]), du);
    dUV.uv = fn_801D7EFC(fn_801D7F18(fn_801D7FF4(patch->uv[2], patch->uv[0]), fn_801D7FF4(patch->uv[1], patch->uv[3])), du2);
    SET(&cur.color, patch->color[0]);
    SET(&dU.color, MUL(SUB(patch->color[1], patch->color[0]), du));
    SET(&dV.color, MUL(SUB(patch->color[3], patch->color[0]), du));
    SET(&dUV.color, MUL(SUB(ADD(patch->color[2], patch->color[0]), ADD(patch->color[1], patch->color[3])), du2));
    k = 0;
    i = n + 1;
    m = 0;
    do {
        fn_80270F34(&work, &cur);
        j = n + 1;
        do {
            out->uvs[k] = work.uv;
            SET(&out->normals[k], work.normal);
            out->colors[m++] = ((int)(lbl_8037B6A8 * work.color.x) << 24) | ((int)(lbl_8037B6A8 * work.color.y) << 16) | ((int)(lbl_8037B6A8 * work.color.z) << 8) | (alpha & 0xFF);
            k++;
            accumulate(work, dU);
        } while (--j);
        accumulate(cur, dV);
        accumulate(dU, dUV);
    } while (--i);
}
