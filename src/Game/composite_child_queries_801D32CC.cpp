// Partial text split: fn_801D32CC, fn_801D345C, fn_801D3614 (composite node
// child forwarding slots). The following vertex re-skin fn_801D38A4 (99.77%,
// two volatile-register swaps) remains original code; full draft in
// scratch/claude_match/auto_03_801D32CC_text/final.cpp.
/* Source order note: CodeWarrior emits these deferred functions in reverse
 * definition order (callers before the shared fn_801D38A4), so the three slot
 * functions are defined 3614, 345C, 32CC to reproduce 32CC, 345C, 3614, 38A4.
 * Build: GC/1.3.2 -O4,p -inline auto -Cpp_exceptions off -RTTI off
 * -use_lmw_stmw on -fp_contract on.
 *
 * Composite spatial node: forwards bounds, sphere and ray queries to paired
 * child nodes after refreshing their skinned vertex buffers.
 * fn_801D32CC/fn_801D345C/fn_801D3614 are vtable slots 0x48/0x44/0x3C of the
 * composite node (lbl_802EC0A0 tables) and call the same slot on each child;
 * fn_801D38A4 re-skins every child's vertices into the shared vertex cache. */
typedef unsigned long long u64;
typedef unsigned short U16;

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    float lengthSquared() const { return x * x + y * y + z * z; }
};
struct Sphere {
    Vec3 c;
    float r;
    Sphere() {}
    Sphere(const Sphere& s) { c.x = s.c.x; c.y = s.c.y; c.z = s.c.z; r = s.r; }
    Sphere& operator=(const Sphere& s) { c.x = s.c.x; c.y = s.c.y; c.z = s.c.z; r = s.r; return *this; }
};
struct Bounds;
struct Matrix { float m[16]; };
struct WorldObject { char unknown00[0x124]; Matrix* matrix; };

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

struct ListEntry { Handle owner; U16 record; char pad06[2]; U16 next, prev; };
struct List {
    int count, capacity;
    ListEntry* entries;
    int stride;
    Vec3* data;
    Vec3* vertices(int slot) { return &data[slot * stride]; }
};
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
    char unknown11C[0x14];
    List* list;
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
    int weightIndex(int k, int v) const { return groups.at(k)->weights.data[v].index; }
    int find(int id) const
    {
        for (int k = 0; k < groups.size(); k++)
            if (groups[k].id == id)
                return k;
        return -1;
    }
};

struct State {
    char unknown00[0x20];
    HandleArray bones;
    char unknown2C[0x10];
    int record;
    char unknown40[0x24];
    HandleArray handles;
};
struct Owner {
    char unknown00[0xC];
    Sphere sphere;
    char unknown1C[0x74 - 0x1C];
    Array<Binding> bindings;
    HandleArray handles;
};
struct Mesh { char unknown00[0x7C]; Vec3* verts; };
struct Transform {
    char unknown00[0x120];
    unsigned long flags;
    Matrix* matrix;
    Matrix* inverse;
    short unknown12C, index;
};

struct Ray {
    Vec3 origin;
    float maxT;
    Vec3 dir;
    float length;
    Ray() {}
    Ray(const Ray& r)
    {
        origin.x = r.origin.x; origin.y = r.origin.y; origin.z = r.origin.z; maxT = r.maxT;
        dir.x = r.dir.x; dir.y = r.dir.y; dir.z = r.dir.z; length = r.length;
    }
};
struct Hit {
    Vec3 point;
    float t;
    Vec3 normal;
    int unknown1C;
    float unknown20, unknown24;
    u64 mask;
    int unknown30, unknown34, unknown38;
    signed char valid;
    int unknown40;
    Hit() { valid = 0; unknown30 = 0; unknown34 = 0; unknown38 = 0; mask = 0; }
    Hit& operator=(const Hit& h)
    {
        point.x = h.point.x; point.y = h.point.y; point.z = h.point.z; t = h.t;
        normal.x = h.normal.x; normal.y = h.normal.y; normal.z = h.normal.z;
        unknown1C = h.unknown1C; unknown20 = h.unknown20; unknown24 = h.unknown24;
        mask = h.mask; unknown30 = h.unknown30; unknown34 = h.unknown34; unknown38 = h.unknown38;
        valid = h.valid; unknown40 = h.unknown40;
        return *this;
    }
};

struct ChildBase { char unknown00[8]; };
struct Child : ChildBase {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38();
    virtual signed char raycast(WorldObject*, Child*, Ray*, Hit*, u64, u64);
    virtual void slot40();
    virtual signed char overlapsSphere(WorldObject*, Child*, const Sphere*, void*, u64, u64);
    virtual signed char overlapsBounds(WorldObject*, Child*, const Bounds*, void*, u64, u64);
    virtual signed char isStatic();
    virtual void cacheVertices(U16, Handle*);
    virtual void release();
};

extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
signed char fn_801B9458(const Sphere&, const Bounds*);
signed char fn_801BA38C(const Ray*, const Sphere&);
U16 fn_801CF7E4(List*, const void*, int);
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801D38A4(Owner*, WorldObject*, State*);
}

extern "C" signed char fn_801D3614(Owner* self, WorldObject* object, State* state, const Ray* query, Hit* out,
                                   u64 flags, u64 flags2)
{
    Sphere sphere;
    sphere = fn_80099A00(object->matrix, &self->sphere);
    if (!fn_801BA38C(query, sphere))
        return 0;
    Ray ray(*query);
    fn_801D38A4(self, object, state);
    signed char result = 0;
    for (int i = 0; i < self->handles.count; ++i) {
        Hit hit;
        Child* child = resolve<Child>(self->handles.data[i]);
        if (child->raycast(object, lookup<Child>(state->handles.data[i]), &ray, &hit, flags, flags2)) {
            result = 1;
            if (!out->valid || !(out->t < hit.t)) {
                *out = hit;
                ray.maxT = out->t;
            }
        }
    }
    return result;
}
extern "C" signed char fn_801D345C(Owner* self, WorldObject* object, State* state, const Sphere* other,
                                   void* context, u64 flags, u64 flags2)
{
    Sphere sphere = fn_80099A00(object->matrix, &self->sphere);
    float radius = sphere.r + other->r;
    const Vec3& delta = sphere.c - other->c;
    if (!(delta.lengthSquared() < radius * radius))
        return 0;
    fn_801D38A4(self, object, state);
    signed char result = 0;
    for (int i = 0; i < self->handles.count; ++i) {
        Child* child = resolve<Child>(self->handles.data[i]);
        if (child->overlapsSphere(object, lookup<Child>(state->handles.data[i]), other, context, flags, flags2))
            result = 1;
    }
    return result;
}
extern "C" signed char fn_801D32CC(Owner* self, WorldObject* object, State* state, const Bounds* bounds,
                                   void* context, u64 flags, u64 flags2)
{
    Sphere sphere;
    sphere = fn_80099A00(object->matrix, &self->sphere);
    if (!fn_801B9458(sphere, bounds))
        return 0;
    fn_801D38A4(self, object, state);
    signed char result = 0;
    for (int i = 0; i < self->handles.count; ++i) {
        Child* child = resolve<Child>(self->handles.data[i]);
        if (child->overlapsBounds(object, lookup<Child>(state->handles.data[i]), bounds, context, flags, flags2))
            result = 1;
    }
    return result;
}

