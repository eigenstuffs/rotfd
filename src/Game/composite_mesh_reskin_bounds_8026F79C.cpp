/* fn_8026F79C: composite-mesh re-skin + bounds refresh (same family as
 * fn_801D38A4).  Allocation-sensitive choices: state resolve via non-template
 * RES, mesh via lookup<>, transforms via resolve<>; transform computes y, z, x
 * in that order reading v directly; Vec3::operator* holds only the y product
 * in a named local (closes the y/z weight-product colouring). */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator*(float s) const { float py = y * s; return Vec3(x * s, py, z * s); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
};
struct Sphere {
    Vec3 c;
    float r;
    Sphere() {}
    Sphere(const Vec3& center, float radius) : c(center), r(radius) {}
    Sphere& operator=(const Sphere& s) { c.x = s.c.x; c.y = s.c.y; c.z = s.c.z; r = s.r; return *this; }
};
struct Matrix { float m[16]; };

struct Handle {
    union { int word; struct { signed int tag : 8, index : 24; } bits; };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };

struct MatrixPool { Matrix* pages[6]; unsigned char active; };
struct HandleArray { int count, capacity; Handle* data; };
struct Record { HandleArray handles; char unknown0C[8]; };
struct RecordTable {
    char unknown00[0xB8];
    Record* records;
    Record* get(int i) { return &records[i]; }
};
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[0xC];
    RecordTable* table;
} lbl_801E9D24;

template <class T> inline T* resolve(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? (T*)m->entries[index].object : 0;
}

inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}
#define RES(T, x) ((T*)resolveAny(x))

template <class T> inline T* lookup(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->getTag() == h.getTag())
        return (T*)e->object;
    return 0;
}
template <class T> struct Array {
    int count, capacity;
    T* data;
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
    const T* at(int i) const { return data + i; }
    int size() const { return count; }
};
struct Weight { int index; float weight; };
struct Group { short id; char pad02[2]; Array<Weight> weights; char unknown10[0xC]; };
struct Binding {
    int bone;
    Array<Group> groups;
    int weightCount(int k) const { return groups.at(k)->weights.count; }
    const Weight& weightAt(int k, int v) const { return groups.at(k)->weights.data[v]; }
    int find(int id) const
    {
        for (int k = 0; k < groups.size(); k++)
            if (groups[k].id == id)
                return k;
        return -1;
    }
};

struct StateBase { char unknown00[8]; };
struct State : StateBase {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38();
    virtual const Sphere* bounds();
    char unknown0C[0x14];
    HandleArray bones;
    char unknown2C[0x10];
    int record;
};
struct Owner {
    char unknown00[0xC];
    Sphere sphere;
    char unknown1C[0x74 - 0x1C];
    Array<Binding> bindings;
    HandleArray handles;
};
struct Mesh {
    char unknown00[0xC];
    Sphere sphere;
    char unknown1C[0x74 - 0x1C];
    Array<Vec3> verts;
};
struct Transform {
    char unknown00[0x120];
    unsigned long flags;
    Matrix* matrix;
    Matrix* inverse;
    short unknown12C, index;
};

extern "C" {
extern Vec3 lbl_80341360[];
extern const Vec3 game_vec4_zero;
extern const float lbl_8037B6A0;
void fn_80280158(Vec3*, int);
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801F0C68(Sphere*, const Vec3*, int);
Sphere fn_801F0A20(const Sphere&, const Sphere&);
void fn_80249D58(State*, signed char);
}

inline void refreshInverse(Transform* object)
{
    if (object->flags & 0x20) {
        object->inverse = &lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];
        fn_801F230C(object->matrix, object->inverse);
        object->flags &= ~0x20;
    }
}
inline Matrix product(const Matrix& a, const Matrix& b)
{
    Matrix r;
    fn_801F1080(&a, &b, &r);
    return r;
}
inline Vec3 transform(const Matrix& m, const Vec3& v)
{
    float y = m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13];
    float z = m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14];
    float x = m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12];
    return Vec3(x, y, z);
}

extern "C" void fn_8026F79C(Owner* self, const Handle& h, signed char flag)
{
    State* state; Record* record; int i; Mesh* mesh; int j; Binding* binding; int k; Transform* a; Transform* b; int v; int index;
    state = RES(State, h);
    record = lbl_801E9D24.table->get(state->record);
    for (i = 0; i < self->handles.count; i++) {
        mesh = lookup<Mesh>(self->handles.data[i]);
        fn_80280158(lbl_80341360, 0x1000);
        for (j = 0; j < self->bindings.size(); j++) {
            binding = &self->bindings[j];
            k = binding->find(i);
            if (k < 0)
                continue;
            a = resolve<Transform>(state->bones.data[binding->bone]);
            b = resolve<Transform>(record->handles.data[binding->bone]);
            refreshInverse(b);
            Matrix m = product(*a->matrix, *b->inverse);
            for (v = 0; v < binding->weightCount(k); v++) {
                const Weight& w = binding->weightAt(k, v);
                index = w.index;
                lbl_80341360[index] += transform(m, mesh->verts[index]) * w.weight;
            }
        }
        Sphere s(game_vec4_zero, lbl_8037B6A0);
        fn_801F0C68(&s, lbl_80341360, mesh->verts.count);
        if (!flag)
            s = fn_801F0A20(mesh->sphere, s);
        mesh->sphere = s;
        if (i != 0 || !flag)
            s = fn_801F0A20(s, self->sphere);
        self->sphere = s;
    }
    fn_80249D58(state, flag);
    Sphere t = fn_801F0A20(self->sphere, *state->bounds());
    self->sphere = t;
}
