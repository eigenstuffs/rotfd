/* fn_801D38A4: composite-mesh skin into the shared vertex cache (same family
 * as fn_8026F79C). */
typedef unsigned short U16;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
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
struct LinkNode {
    unsigned int owner;
    U16 record;
    U16 pad;
    U16 next, prev;
};
struct VertexCache {
    int count;
    int capacity;
    LinkNode* entries;
    int stride;
    Vec3* data;
    LinkNode& at(int i) { return entries[i]; }
    void touch(int n) {
        entries[at(n).next].prev = at(n).prev;
        entries[at(n).prev].next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        entries[at(0).prev].next = n;
        at(0).prev = n;
    }
    Vec3* get(U16 index) {
        touch(index + 1);
        return &data[index * stride];
    }
};
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x14];
    VertexCache* cache;
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
struct ChildBase { char unknown00[8]; };
struct Child : ChildBase {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48();
    virtual char isCached();
    virtual void setCache(U16 index, Handle* h);
    virtual void prepare();
};
struct State {
    char unknown00[0x20];
    HandleArray bones;
    char unknown2C[0x10];
    int record;
    char unknown40[0x24];
    HandleArray children;
};
struct Owner {
    char unknown00[0x74];
    Array<Binding> bindings;
    HandleArray handles;
};
struct Mesh {
    char unknown00[0x74];
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
void fn_801F230C(const Matrix*, Matrix*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
U16 fn_801CF7E4(VertexCache*, Child*, int);
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
    float x = m.m[12] + (m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z);
    float y = m.m[13] + (m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z);
    float z = m.m[14] + (m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z);
    return Vec3(x, y, z);
}

extern "C" void fn_801D38A4(Owner* self, int unused, State* state)
{
    Record* record = lbl_801E9D24.table->get(state->record);
    for (int i = 0; i < self->handles.count; i++) {
        Child* child = lookup<Child>(state->children.data[i]);
        if (child->isCached())
            continue;
        child->prepare();
        U16 slot = fn_801CF7E4(lbl_801E9D24.cache, child, 0);
        Vec3* out = lbl_801E9D24.cache->get(slot);
        Mesh* mesh = lookup<Mesh>(self->handles.data[i]);
        for (int j = 0; j < self->bindings.size(); j++) {
            Binding* binding = &self->bindings[j];
            int k = binding->find(i);
            if (k < 0)
                continue;
            Transform* a = resolve<Transform>(state->bones.data[binding->bone]);
            Transform* b = resolve<Transform>(record->handles.data[binding->bone]);
            refreshInverse(b);
            Matrix m = product(*a->matrix, *b->inverse);
            for (int v = 0; v < self->bindings[j].weightCount(k); v++) {
                const Weight& w = self->bindings[j].weightAt(k, v);
                unsigned int index = w.index;
                out[index] = transform(m, mesh->verts[index]);
            }
        }
        child->setCache(slot, &self->handles.data[i]);
    }
}
