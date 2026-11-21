/* Camera offset from the raised context position (fn_800784A8).
   Snapshots the current camera point at 0xF4, queries the context position
   (fn_80076D98), raises it by the height at 0xDC and outputs the current
   point minus that raised position (same family as fn_80078550).

   The raise vector's zero components are the original pooled literal 0.0f,
   lbl_8037899C. The original literal was loaded once per component and the
   back end merged the two loads, so the shared register is numbered after the
   position.z load (f3, with position.z in f4). Reading the label the same way
   twice lets the front-end optimizer hoist one common load into a temporary,
   which swaps f3/f4; reading one component through a pointer keeps the two
   loads distinct until the back end merges them, as with the literal. */
struct QueryVector {
    float x, y, z;
    QueryVector() {}
    QueryVector(float a, float b, float c) : x(a), y(b), z(c) {}
    QueryVector operator+(const QueryVector& o) const { return QueryVector(x + o.x, y + o.y, z + o.z); }
    QueryVector operator-(const QueryVector& o) const { return QueryVector(x - o.x, y - o.y, z - o.z); }
    QueryVector& operator=(const QueryVector& o) { x = o.x; y = o.y; z = o.z; return *this; }
};

struct QueryCamera {
    char unknown00[0xDC];
    float height;
    char unknownE0[0x14];
    QueryVector current;
};

extern "C" {
void fn_80076D98(QueryCamera*, QueryVector*);
extern const float lbl_8037899C;
}

extern "C" void fn_800784A8(QueryCamera* self, QueryVector* out) {
    QueryVector current = self->current;
    QueryVector position;
    fn_80076D98(self, &position);
    *out = current - (position + QueryVector(lbl_8037899C, self->height, *(const float*)&lbl_8037899C));
}
