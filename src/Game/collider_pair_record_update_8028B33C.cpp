#pragma readonly_strings on
typedef unsigned long Word;

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    const Vec3& get() const { return *this; }
    Vec3 operator-(const Vec3& o) const { Vec3 r(x - o.x, y - o.y, z - o.z); return r.get(); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Sphere { Vec3 c; float r; };
struct Matrix { float a[16]; };

struct Handle { signed int tag : 8; signed int index : 24; void* get() const; void* get2() const { return get(); } };
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
struct Record30 {
    Word next;
    int index[2];
    char flag[2];
    char pad0E[2];
    Word word[2];
    Word meshWord;
    void* side[2];
    void* object[2];
    void* target;
};
struct RecordStore { char unknown00[0xE8]; Record30* records; char unknownEC[4]; int count; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
    char unknown138[0xC];
    RecordStore* store;
} lbl_801E9D24;
inline void* resolve(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}

inline void* Handle::get() const { return resolve(*this); }
struct Owner {
    char unknown00[0x1C];
    Handle mesh;
    char unknown20[0x100];
    Word flags;
    Matrix* local;
    Matrix* world;
    char unknown12C[2];
    short index;
    Handle target;
    Matrix* getWorld();
    Word getFlags() const { return flags; }
};
struct MeshWord { Word word; char unknown04[8]; Sphere sphere; };
struct Element { Word word; Handle handle; Sphere sphere; };
struct ElementArray { int count, capacity; Element* data;
    int size() const { return count; }
    const Element& operator[](int i) const { return data[i]; }
    const Element& get(Word i) const { return data[i]; }
    const Element* ptr(Word i) const { return &data[i]; }
    const Element* at(int i) const { return &data[i]; } };
inline Owner* ownerOf(const Element* e) { return (Owner*)e->handle.get(); }
inline Owner* ownerOf2(const Element& e) { return (Owner*)resolve(e.handle); }
struct Side { char unknown00[0x40]; ElementArray inner; ElementArray outer; };
struct Pair {
    Word next;
    int index[2];
    char flag[2];
    char pad0E[2];
    Word word[2];
    char unknown18[0xC];
    Owner* object[2];
    char unknown2C[4];
};
struct Target {
    char unknown00[8];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual signed char query(int*);
};
struct PairOut { Word next; int index[2]; unsigned char flag[2]; char pad0E[2]; Word word[2]; char unknown18[0xC]; Owner* object[2]; char unknown2C[4]; };
struct Node { char unknown00[0x18]; signed char enabled; char unknown19[0x1F0 - 0x19]; Handle side; Handle owner; };

extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void* fn_801EF83C(void*, void*, Word, const char*, const char*, Word);
void* fn_801EFA1C(void*, Word, const char*, const char*, Word, Word);
Sphere fn_80099A00(const Matrix*, const Sphere*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_801F230C(const Matrix*, Matrix*);
void fn_80287DF8(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), Word, Word);
void fn_802073E8(void*, int, void*, float);
}

struct PtrArray {
    typedef void T;
    Word count, capacity;
    T** items;
    void setStorage(Word n)
    {
        if (n) {
            if (items)
                items = (T**)fn_801EF83C(lbl_801EF5C8, items, n * sizeof(T*), "Anonymous Alloc", "DynPtrArray_Z.h", 0xC4);
            else
                items = (T**)fn_801EFA1C(lbl_801EF5C8, n * sizeof(T*), "Anonymous Alloc", "DynPtrArray_Z.h", 0xC6, 4);
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
    T* operator[](Word i) const { return items[i]; }
    T* at(int i) const { return items[i]; }
    T*& ref(Word i) { return items[i]; }
    Word size() const { return count; }
    Word push_back(T* p)
    {
        if (count + 1 > capacity) {
            capacity += 32;
            setStorage(capacity);
        }
        items[count] = p;
        return count++;
    }
};

inline Matrix* Owner::getWorld()
{
    if (flags & 0x20) {
        world = &lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][index];
        fn_801F230C(local, world);
        flags &= ~0x20;
    }
    return world;
}
inline Matrix product(const Matrix& a, const Matrix& b) { Matrix r; fn_801F1080(&a, &b, &r); return r; }

struct Collider {
    char unknown00[0x60];
    int nodeCount;
    char unknown64[4];
    Handle* nodes;
    char unknown6C[0xC];
    PtrArray sides;
    PtrArray owners;
    PtrArray targets;
};

extern "C" int fn_8028B03C(Collider* self, const ElementArray* a, const ElementArray* b, const Matrix* m, PairOut* out);

extern "C" void fn_8028B33C(Collider* self)
{
    self->sides.resize(0);
    self->owners.resize(0);
    self->targets.resize(0);
    int n = self->nodeCount;
    for (int i = 0; i < n; i++) {
        Node* node = (Node*)self->nodes[i].get();
        if (!node->enabled) continue;
        Owner* owner = (Owner*)node->owner.get();
        Target* target = (Target*)resolve(owner->target);
        if (!target) continue;
        Side* side = (Side*)node->side.get();
        self->sides.push_back(side);
        self->owners.push_back(owner);
        int k = self->targets.push_back(target);
        while (--k >= 0) {
            Owner* other = (Owner*)self->owners[k];
            Matrix* ownerLocal = owner->local;
            Matrix* otherLocal = other->local;
            const Sphere s1 = fn_80099A00(ownerLocal, &((MeshWord*)resolve(owner->mesh))->sphere);
            Sphere s2 = fn_80099A00(otherLocal, &((MeshWord*)resolve(other->mesh))->sphere);
            float rs = s1.r + s2.r;
            const Vec3 d = s1.c - s2.c;
            if (!(d.dot(d) < rs * rs)) continue;
            Matrix m;
            m = product(*owner->getWorld(), *otherLocal);
            Side* otherSide = (Side*)self->sides[k];
            Target* otherTarget = (Target*)self->targets[k];
            Pair pairs[32];
            __construct_array(pairs, fn_80287DF8, 0, sizeof(Pair), 32);
            int count = fn_8028B03C(self, &side->outer, &otherSide->outer, &m, (PairOut*)pairs);
            if (count) {
                RecordStore* store = lbl_801E9D24.store;
                Pair* p = pairs;
                int idx = store->count;
                Record30* rec = &store->records[idx];
                Record30* prevA = 0;
                Record30* prevB = 0;
                int firstA = -1;
                int firstB = -1;
                for (int q = 0; q < count; q++, p++) {
                    if (p->flag[0] || p->flag[1]) {
                        if (p->flag[0]) {
                            if (prevA) prevA->next = idx; else firstA = idx;
                            rec->next = 0;
                            rec->flag[0] = p->flag[1];
                            rec->index[0] = p->index[1];
                            rec->word[0] = p->word[1];
                            rec->flag[1] = 1;
                            rec->index[1] = p->index[0];
                            rec->word[1] = p->word[0];
                            rec->target = target;
                            rec->side[0] = otherSide;
                            rec->side[1] = side;
                            rec->object[0] = p->object[1];
                            rec->object[1] = p->object[0];
                            rec->meshWord = ((MeshWord*)resolve(owner->mesh))->word;
                            prevA = rec;
                            idx++;
                            rec++;
                            lbl_801E9D24.store->count++;
                        }
                        if (p->flag[1]) {
                            if (prevB) prevB->next = idx; else firstB = idx;
                            rec->next = 0;
                            rec->flag[0] = 1;
                            rec->index[0] = p->index[0];
                            rec->word[0] = p->word[0];
                            rec->flag[1] = p->flag[0];
                            rec->index[1] = p->index[1];
                            rec->word[1] = p->word[1];
                            rec->target = otherTarget;
                            rec->side[0] = side;
                            rec->side[1] = otherSide;
                            rec->object[0] = p->object[0];
                            rec->object[1] = p->object[1];
                            rec->meshWord = ((MeshWord*)resolve(other->mesh))->word;
                            prevB = rec;
                            idx++;
                            rec++;
                            lbl_801E9D24.store->count++;
                        }
                    }
                }
                int event;
                if (firstA >= 0 && target->query(&event))
                    fn_802073E8(self, event, otherTarget, (float)firstA);
                if (firstB >= 0 && otherTarget->query(&event))
                    fn_802073E8(self, event, target, (float)firstB);
            }
            count = fn_8028B03C(self, &side->inner, &otherSide->inner, &m, (PairOut*)pairs);
            if (count) {
                RecordStore* store = lbl_801E9D24.store;
                Pair* p = pairs;
                int idx = store->count;
                Record30* rec = &store->records[idx];
                Record30* prevA = 0;
                Record30* prevB = 0;
                int firstA = -1;
                int firstB = -1;
                for (int q = 0; q < count; q++, p++) {
                    if (prevA) prevA->next = idx; else firstA = idx;
                    rec->next = 0;
                    rec->flag[0] = p->flag[1];
                    rec->index[0] = p->index[1];
                    rec->word[0] = p->word[1];
                    rec->flag[1] = p->flag[0];
                    rec->index[1] = p->index[0];
                    rec->word[1] = p->word[0];
                    rec->target = target;
                    rec->meshWord = ((MeshWord*)resolve(owner->mesh))->word;
                    rec->side[0] = otherSide;
                    rec->side[1] = side;
                    rec->object[0] = p->object[1];
                    rec->object[1] = p->object[0];
                    if (prevB) prevB->next = idx; else firstB = idx;
                    rec->next = 0;
                    rec->flag[0] = p->flag[0];
                    rec->index[0] = p->index[0];
                    rec->word[0] = p->word[0];
                    rec->flag[1] = p->flag[1];
                    rec->index[1] = p->index[1];
                    rec->word[1] = p->word[1];
                    rec->target = otherTarget;
                    rec->meshWord = ((MeshWord*)resolve(other->mesh))->word;
                    rec->side[0] = side;
                    rec->side[1] = otherSide;
                    rec->object[0] = p->object[0];
                    rec->object[1] = p->object[1];
                    prevA = rec;
                    idx++;
                    rec++;
                    lbl_801E9D24.store->count++;
                }
                fn_802073E8(self, 0x1A, target, (float)firstB);
                fn_802073E8(self, 0x1A, otherTarget, (float)firstA);
            }
        }
    }
}

