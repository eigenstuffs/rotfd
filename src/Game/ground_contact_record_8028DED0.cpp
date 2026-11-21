// Record a ground contact: transform the hit point into the actor's local
// space, refresh the contact sphere, and collect the touched object and the
// mesh faces (the hit face and its adjacent faces) around the hit.
typedef unsigned long Word;
typedef unsigned long long Flags;

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
struct Matrix { float m[16]; };
struct Sphere { Vec3 center; float radius; };

struct Handle { signed int tag : 8; signed int index : 24; };
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; char unknown11C[0x18]; MatrixPool* pool; } lbl_801E9D24;
inline void* resolve(const Handle& h) { int index = h.index; Manager* m = lbl_801E9D24.manager; int tag = m->entries[index].getTag(); return tag == h.tag ? m->entries[index].object : 0; }

struct Actor { char unknown00[0x120]; Word flags; Matrix* matrix; Matrix* inverse; short unknown12C, index; };
struct FaceOwner { char unknown00[0xB8]; Handle object; };
struct FaceObject { char unknown00[0x64]; Word flags; };
struct Face { char unknown00[0x84]; Word adjacency; Handle owner; char unknown8C[4]; };
struct Mesh { char unknown00[0x6C]; unsigned short type; char unknown6E[0x3E]; Face* faces; char unknownB0[0x2C]; unsigned short* adjacency; };
struct Result { Vec3 point; char unknown0C[4]; Vec3 normal; Word index; char unknown20[8]; Flags flags; void* object; Mesh* mesh; };

extern "C" {
extern char lbl_801EF5C8[], lbl_802AF8E8[], lbl_802AF8F8[], lbl_8028F698[];
extern const float lbl_8037B930, lbl_8037B934, lbl_8037B938, lbl_8037B93C;
float fn_800A8E8C(float, float, float);
void fn_801F230C(const Matrix*, Matrix*);
void fn_801EF610(void*, void*);
void* fn_801EF83C(void*, void*, Word, const char*, const char*, Word);
void* fn_801EFA1C(void*, Word, const char*, const char*, Word, Word);
void* fn_8028FAF4(void*, void*, Word, Word);
void* fn_8028FF24(void*, Word);
void fn_8028FD50(void*, void*, Word);
}

inline void* operator new(unsigned long, void* p) { return p; }

template <class T> struct DynPtrArray {
    Word count, capacity;
    T** items;
    void setStorage(Word n)
    {
        if (n) {
            if (items)
                items = (T**)fn_801EF83C(lbl_801EF5C8, items, n * sizeof(T*), lbl_802AF8E8, lbl_802AF8F8, 0xC4);
            else
                items = (T**)fn_801EFA1C(lbl_801EF5C8, n * sizeof(T*), lbl_802AF8E8, lbl_802AF8F8, 0xC6, 4);
        } else if (items) {
            fn_801EF610(lbl_801EF5C8, items);
            items = 0;
        }
    }
    void resize(Word n)
    {
        if (n > count) {
            if (n > capacity) {
                setStorage(n);
                capacity = n;
            }
            capacity = n;
            count = n;
        } else if (n < count) {
            count = n;
        }
    }
    void push_back(T* p)
    {
        if (count + 1 > capacity) {
            capacity += 32;
            setStorage(capacity);
        }
        items[count] = p;
        ++count;
    }
};

template <class T> struct DynArray {
    int count, capacity;
    T* items;
    void setStorage(int n)
    {
        if (n) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items, capacity * sizeof(T), n * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }
    void resize(int n)
    {
        int i;
        if (n > count) {
            if (n > capacity) {
                setStorage(n);
                capacity = n;
            }
            for (i = count; i < n; ++i)
                new (items + i) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i)
                items[i].~T();
            count = n;
        }
    }
    void push_back(const T& v)
    {
        if (count + 1 > capacity) {
            setStorage(capacity + 4);
            capacity += 4;
        }
        new (items + count++) T(v);
    }
};

inline void refreshInverse(Actor* t)
{
    if (t->flags & 0x20) {
        t->inverse = &lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][t->index];
        fn_801F230C(t->matrix, t->inverse);
        t->flags &= ~0x20;
    }
}
// Length with the engine square root (fres of the frsqrte estimate in f4).
inline float length(float x, float y, float z)
{
    register float sq = x * x + y * y + z * z;
    register float r = lbl_8037B934;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
inline Vec3 transformPoint(const Matrix& m, const Vec3& v)
{
    float X = m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12];
    float Y = m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13];
    float Z = m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14];
    return Vec3(X, Y, Z);
}

struct ContactStorage { char unknown00[8]; };
struct Contact : ContactStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual Sphere* getSphere();
    char unknown0C[0x20];
    Vec3 point;
    Vec3 normal;
    float weight;
    char unknown48[0xC8];
    DynPtrArray<void> objects;
    DynArray<Word> faces;
};

extern "C" void fn_8028DED0(Contact* self, Actor* actor, const Vec3& point, Result* result, float w)
{
    float t = lbl_8037B930 - fn_800A8E8C(point.y - result->point.y, lbl_8037B934, lbl_8037B938) / lbl_8037B938;
    refreshInverse(actor);
    const Matrix* inverse = actor->inverse;
    self->point = transformPoint(*inverse, result->point);
    self->normal = result->normal;
    float len = length(inverse->m[0], inverse->m[4], inverse->m[8]);
    float radius = w * len;
    self->getSphere()->radius = radius;
    self->getSphere()->center = self->point;
    self->weight = fn_800A8E8C(w * t, lbl_8037B93C * w, w);
    actor->flags |= 0x80000;
    self->objects.resize(0);
    self->faces.resize(0);
    self->objects.push_back(result->object);
    Mesh* mesh = result->mesh;
    if (mesh->type == 1) {
        Face* faces = mesh->faces;
        Word index = result->index;
        Face* face = &faces[index];
        unsigned short* adjacent = &mesh->adjacency[face->adjacency];
        unsigned short n = *adjacent++;
        do {
            FaceOwner* owner = (FaceOwner*)resolve(face->owner);
            FaceObject* object = (FaceObject*)resolve(owner->object);
            if (!(object->flags & 0x408))
                self->faces.push_back(index);
            index = *adjacent++;
            face = &faces[index];
        } while (n--);
    } else if (result->flags & 0x0000044000000000ULL) {
        self->faces.push_back(result->index);
    }
}
