/* fn_8022A830: owner contact pass. Builds up to eight (collision shape,
   world matrix) pairs from the owner's record range (refreshing a record's
   world matrix from the current matrix table when its dirty bit 0x20 is set,
   fn_801F230C), then tests three object lists against the pairs with
   fn_8026C028: the +0x34 handles (skipping those flagged in +0x40) with a
   zero-centred probe sphere after their own virtual overlap test (0x80), the
   +0x5C handles with their resource bounds transformed by fn_80099A00, and
   the +0x74 links with their parent's bounds (virtual 0x3C). A hit calls the
   resolved owner's virtual 0x34 (or fn_80213A18 when there is none), a miss
   0x30 (or fn_802139D8).
   Matching notes: two lookup shapes are needed: the typed lookup keeps its
   result in a local assigned on both paths, the plain one returns early; the
   first list keeps its pair scan inline, the other two lists use small
   scan helpers. */
struct Handle { signed int generation : 8; signed int index : 24; };
struct Entry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { char unknown00[8]; Entry* entries; };
struct Record { char unknown00[0x14]; Handle handle; char unknown18[0x34]; };
struct MatrixTable { char* matrices[6]; unsigned char current; };
struct Matrix44 { float m[16]; };
extern "C" {
extern struct {
    char unknown00[0x114];
    Record* records;
    Manager* manager;
    char unknown11C[0x18];
    MatrixTable* matrices;
} lbl_801E9D24;
}
inline char* resolve(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[index].getGeneration();
    if (generation == h.generation) return m->entries[index].object;
    return 0;
}
template <class T> inline T* resolveAs(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    T* result;
    int generation = m->entries[index].getGeneration();
    if (generation == h.generation) result = (T*)m->entries[index].object;
    else result = 0;
    return result;
}

struct Vec3 { float x, y, z; };
struct Sphere {
    float x, y, z, radius;
    Sphere() {}
    Sphere(const Vec3& c, float r) : x(c.x), y(c.y), z(c.z), radius(r) {}
};
struct Storage { char unknown00[8]; };
struct Node : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void contactEnd(); virtual void contactBegin();
    virtual void slot38(); virtual const Sphere* getBounds(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual signed char overlaps(const Sphere*);
};
struct Object {
    char unknown00[0x1C];
    Handle resource, parent;
    char unknown24[0xFC];
    unsigned long flags;
    void* matrix;
    Matrix44* world;
    char unknown12C[2];
    short worldIndex;
    Handle owner;
};
struct Target : Node { char unknown0C[0x18]; Handle owner; };
struct Pair { void* shape; Matrix44* world; };
struct Self {
    char unknown00[0x20];
    int pairCount, pairBase;
    char unknown28[4];
    int targetCount, targetCapacity;
    Handle* targets;
    char unknown38[8];
    unsigned long* targetFlags;
    char unknown44[0x10];
    int objectCount, objectCapacity;
    Handle* objects;
    char unknown60[0xC];
    int linkCount, linkCapacity;
    Handle* links;
};
extern "C" {
extern const Vec3 game_vec4_zero;
extern const float lbl_8037B184;
void fn_801F230C(void*, Matrix44*);
signed char fn_8026C028(void*, Matrix44*, const Sphere*, float*);
void fn_80213A18(void*);
void fn_802139D8(void*);
Sphere fn_80099A00(const void*, const Sphere*);
}

inline signed char hitsAny(Self* self, Pair* pairs, const Sphere* s, float* t)
{
    int j;
    for (j = 0; j < self->pairCount; j++) {
        if (fn_8026C028(pairs[j].shape, pairs[j].world, s, t)) break;
    }
    return j != self->pairCount;
}
inline signed char hitsAnyBounds(Self* self, Pair* pairs, Node* shape, float* t)
{
    int j;
    for (j = 0; j < self->pairCount; j++) {
        if (fn_8026C028(pairs[j].shape, pairs[j].world, shape->getBounds(), t)) break;
    }
    return j != self->pairCount;
}

extern "C" void fn_8022A830(Self* self)
{
    Pair pairs[8];
    float t;
    int i;
    int n = self->targetCount;
    for (i = 0; i < self->pairCount; i++) {
        Object* object = resolveAs<Object>(lbl_801E9D24.records[self->pairBase + i].handle);
        pairs[i].shape = resolve(object->resource) + 0x74;
        if (object->flags & 0x20) {
            object->world = (Matrix44*)lbl_801E9D24.matrices->matrices[lbl_801E9D24.matrices->current] + object->worldIndex;
            fn_801F230C(object->matrix, object->world);
            object->flags &= ~0x20;
        }
        pairs[i].world = object->world;
    }
    for (i = 0; i < n; i++) {
        if (self->targetFlags[i] & 1) continue;
        Target* target = resolveAs<Target>(self->targets[i]);
        Node* owner = resolveAs<Node>(target->owner);
        Sphere probe(game_vec4_zero, lbl_8037B184);
        int j;
        if (target->overlaps(&probe)) {
            for (j = 0; j < self->pairCount; j++) {
                if (fn_8026C028(pairs[j].shape, pairs[j].world, &probe, &t)) break;
            }
            if (j != self->pairCount) {
                if (owner) owner->contactBegin();
                else fn_80213A18(target);
                continue;
            }
        }
        if (owner) owner->contactEnd();
        else fn_802139D8(target);
    }
    n = self->objectCount;
    for (i = 0; i < n; i++) {
        Object* object = resolveAs<Object>(self->objects[i]);
        Node* owner = resolveAs<Node>(object->owner);
        if (owner) {
            char* resource = resolve(object->resource);
            if (resource) {
                Sphere bounds = fn_80099A00(object->matrix, (const Sphere*)(resource + 0xC));
                if (hitsAny(self, pairs, &bounds, &t)) owner->contactBegin();
                else owner->contactEnd();
            }
        }
    }
    n = self->linkCount;
    for (i = 0; i < n; i++) {
        Object* link = (Object*)resolve(self->links[i]);
        Object* object = resolveAs<Object>(link->parent);
        Node* owner = resolveAs<Node>(object->owner);
        if (owner) {
            Node* shape = resolveAs<Node>(object->parent);
            if (hitsAnyBounds(self, pairs, shape, &t)) owner->contactBegin();
            else owner->contactEnd();
        }
    }
}
