typedef unsigned long Word;
struct Point {
    float x, y, z;
    Point& operator=(const Point& p) { x = p.x; y = p.y; z = p.z; return *this; }
};
extern "C" const float lbl_8037A4E4;
struct Vertex {
    float x, y, z, w;
    Vertex() {}
    Vertex(const Point& p) { x = p.x; y = p.y; z = p.z; w = lbl_8037A4E4; }
    Vertex& operator=(const Point& p) { x = p.x; y = p.y; z = p.z; w = lbl_8037A4E4; return *this; }
};
struct Result { Point point; float distance; Point normal; Word unknown1C; float unknown20, unknown24; Word unknown28, unknown2C; };
struct Hit { Point point; float distance; Point normal; void* object; unsigned long long token; Hit() { object = 0; } };
inline void* operator new(unsigned long, void* p) { return p; }
struct Hits {
    Hit records[256];
    int count;
    int append()
    {
        if (count >= 256) {
            new (&records[255]) Hit;
            return 255;
        }
        new (&records[count++]) Hit;
        return count - 1;
    }
};
typedef char ResultSize[(sizeof(Result) == 48) ? 1 : -1];
typedef char HitSize[(sizeof(Hit) == 40) ? 1 : -1];
struct Query;
extern "C" signed char fn_8027AA38(Query*, const Vertex&, const Vertex&, const Vertex&, Result*);
static inline void store(Hits* out, const Result& result, unsigned long long token)
{
    Hit& hit = out->records[out->append()];
    hit.point = result.point;
    hit.normal = result.normal;
    hit.distance = result.distance;
    hit.token = token;
}
extern "C" signed char fn_801DF9B0(Query* query, const Point* points, short* indices, int count, signed char orientation, Hits* out, unsigned long long token)
{
    signed char found = 0;
    Result result;
    short* indexB = indices + 1;
    short* indexC = indices + 2;
    for (int i = 0; i < count; ++i, ++indices, ++indexB, ++indexC) {
        Vertex a(points[*indices]), b, c;
        if ((i & 1) ^ orientation) {
            b = points[*indexC];
            c = points[*indexB];
        } else {
            b = points[*indexB];
            c = points[*indexC];
        }
        if (fn_8027AA38(query, a, b, c, &result)) {
            store(out, result, token);
            found = 1;
        }
    }
    return found;
}
