/* fn_801DEF20: nearest hit of a query against a (n+1)x(n+1) height-grid
   patch: every vertex (fn_801B6DD4), the first row's edges, each cell's
   vertical / horizontal / diagonal edges (fn_801B85B0), then the two
   triangles of every cell whose plane record (w != lbl_8037A4E0) is valid
   (fn_80279D64, planes stored after the vertices).  keep() records the
   closest hit and shrinks the query distance.
   Matching detail (saved-register picks): all locals are declared at the top
   without initializers; the GPR colouring follows this declaration order
   (cell-loop pointers descend from r30, last-loop pointers ascend from r23),
   and the last loop advances the `vertices` parameter and the shared row-1
   pointer `row1` directly.
   Flags: -O4,p, -Cpp_exceptions off, -use_lmw_stmw on (GC/1.3.2), as the
   neighbouring index_strip_triangle_hits_801DF9B0.cpp. */
struct Vector {
    float x, y, z;
    Vector() {}
    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}
    Vector& operator=(const Vector& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};
struct Vertex {
    float x, y, z, w;
};
struct Query {
    Vector position;
    float distance;
    Vector direction;
    float unknown1C;
    Query(const Query& q) : position(q.position), distance(q.distance), direction(q.direction), unknown1C(q.unknown1C) {}
};
struct Result {
    Vector position;
    float distance;
    Vector normal;
    char unknown1C[20];
};
extern "C" {
extern const float lbl_8037A4E0;
signed char fn_801B6DD4(Query*, const Vertex*, Result*);
signed char fn_801B85B0(Query*, const Vertex*, const Vertex*, Result*);
signed char fn_80279D64(Query*, const Vertex*, const Vertex*, const Vertex*, const Vertex*, Result*);
}
inline void keep(Result* output, const Result& hit, Query& query, signed char& found)
{
    if (!found || hit.distance < output->distance) {
        found = 1;
        output->normal = hit.normal;
        output->position = hit.position;
        output->distance = hit.distance;
        query.distance = output->distance;
    }
}
extern "C" signed char fn_801DEF20(const Query* input, const Vertex* vertices, Result* output, int n)
{
    Query query(*input);
    Result hit;
    const Vertex* q00;
    int col;
    int row;
    const Vertex* q01;
    const Vertex* row1;
    signed char found;
    const Vertex* q10;
    const Vertex* q11;
    int col2;
    int row2;
    const Vertex* a;
    const Vertex* b;
    const Vertex* p;
    const Vertex* p00;
    int i;
    const Vertex* e0;
    int j;
    const Vertex* e1;
    found = 0;
    p00 = vertices;
    for (i = 0; i < (n + 1) * (n + 1); ++i, ++p00) {
        if (fn_801B6DD4(&query, p00, &hit)) keep(output, hit, query, found);
    }
    e0 = vertices;
    e1 = vertices + 1;
    for (j = 0; j < n; ++j) {
        if (fn_801B85B0(&query, e0, e1, &hit)) keep(output, hit, query, found);
        ++e0;
        ++e1;
    }
    row1 = vertices + n + 1;
    q00 = vertices;
    q01 = vertices + 1;
    q10 = row1;
    q11 = row1 + 1;
    for (row = 0; row < n; ++row) {
        if (fn_801B85B0(&query, q00, q10, &hit)) keep(output, hit, query, found);
        for (col = 0; col < n; ++col) {
            if (fn_801B85B0(&query, q01, q11, &hit)) keep(output, hit, query, found);
            if (fn_801B85B0(&query, q10, q11, &hit)) keep(output, hit, query, found);
            if (fn_801B85B0(&query, q01, q10, &hit)) keep(output, hit, query, found);
            ++q00;
            ++q10;
            ++q01;
            ++q11;
        }
        ++q00;
        ++q10;
        ++q01;
        ++q11;
    }
    a = vertices + 1;
    b = row1 + 1;
    p = vertices + (n + 1) * (n + 1);
    for (row2 = 0; row2 < n; ++row2) {
        for (col2 = 0; col2 < n; ++col2) {
            if (p[0].w != lbl_8037A4E0 && fn_80279D64(&query, vertices, row1, a, p, &hit)) keep(output, hit, query, found);
            if (p[1].w != lbl_8037A4E0 && fn_80279D64(&query, a, row1, b, p + 1, &hit)) keep(output, hit, query, found);
            p += 2;
            ++vertices;
            ++row1;
            ++a;
            ++b;
        }
        ++vertices;
        ++row1;
        ++a;
        ++b;
    }
    return found;
}
