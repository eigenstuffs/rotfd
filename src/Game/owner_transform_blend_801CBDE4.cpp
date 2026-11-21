/* fn_801CBDE4: blend an owner's transform from its previous to its current
 * resource over 0.2 s (lbl_8037A44C); handles are reference counted.
 * EXACT-WEAK (retry3).  The block after the phase reset resolves
 * self->current three ways: resolveSigned (signed char generation local and a
 * (signed char) cast on the handle generation), lookup for self->previous,
 * and lookupSigned (int local, cast handle generation) for the comparison;
 * the matching casts let the generation and index be shared between the
 * first and third resolve with the original register colouring. */
typedef unsigned long Word;
struct Handle_801F7F10 {
    union { Word value; struct { signed int generation:8; signed int index:24; } packed; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Resource;
struct Entry {
    Resource* object; char unknown04[8]; signed char generation; char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" {
extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
Resource* fn_801F7EB8(const Handle_801F7F10*);
extern const float lbl_8037A448, lbl_8037A44C, lbl_8037A450;
}
struct ZeroHandle1 : Handle_801F7F10 { ZeroHandle1() { value = 0; } };
struct Handle1 : ZeroHandle1 {
    Handle1() {}
    Handle1(const Handle1& v) { value = v.value; fn_801F86C8(lbl_801E9D24.manager, &v, 1); }
};
struct ZeroHandle2 : ZeroHandle1 { ZeroHandle2() { value = 0; } };
struct Handle2 : ZeroHandle2 {
    Handle2() {}
    Handle2(const Handle2& v) { value = v.value; fn_801F86C8(lbl_801E9D24.manager, &v, 1); }
};
inline void assign(Handle_801F7F10& a, const Handle_801F7F10& b) {
    fn_801F86C8(lbl_801E9D24.manager, &a, -1);
    a.value = b.value;
    fn_801F86C8(lbl_801E9D24.manager, &b, 1);
}
inline Resource* resolve(const Handle_801F7F10& h) {
    int index = h.packed.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[index].getGeneration();
    return generation == h.packed.generation ? m->entries[index].object : 0;
}
inline Resource* lookup(const Handle_801F7F10& h) {
    Manager* m = lbl_801E9D24.manager;
    Entry* entries = m->entries;
    int index = h.packed.index;
    int generation = entries[index].getGeneration();
    return generation == h.packed.generation ? entries[index].object : 0;
}
inline Resource* resolveSigned(const Handle_801F7F10& h) {
    int index = h.packed.index;
    Manager* m = lbl_801E9D24.manager;
    signed char generation = m->entries[index].getGeneration();
    return generation == (signed char)h.packed.generation ? m->entries[index].object : 0;
}
inline Resource* lookupSigned(const Handle_801F7F10& h) {
    Entry* entries = lbl_801E9D24.manager->entries;
    int index = h.packed.index;
    int generation = entries[index].getGeneration();
    return generation == (signed char)h.packed.generation ? entries[index].object : 0;
}
struct Point {
    float x, y, z;
    Point() {}
    Point(float a, float b, float c) { x = a; y = b; z = c; }
    Point(const Point& p) : x(p.x), y(p.y), z(p.z) {}
    Point& operator=(const Point& p) { x = p.x; y = p.y; z = p.z; return *this; }
    Point operator-(const Point& p) const { float dz = z - p.z; dz = dz; return Point(x - p.x, y - p.y, dz); }
    Point operator+(const Point& p) const {return Point(x + p.x, y + p.y, z + p.z);}
    Point operator*(float k) const { return Point(x * k, y * k, z * k); }
    Point& operator*=(float k) { x *= k; y *= k; z *= k; return *this; }
};
struct Quaternion {
    float x, y, z, w;
    Quaternion() {}
    Quaternion(const Quaternion& q) : x(q.x), y(q.y), z(q.z), w(q.w) {}
    Quaternion& operator=(const Quaternion& q) { x = q.x; y = q.y; z = q.z; w = q.w; return *this; }
};
extern "C" {
extern const Point game_vec3_zero;
Quaternion fn_801F27BC(const Point&, const Point&);
Quaternion fn_8008D420(const Quaternion&, const Quaternion&, float);
Point fn_801F1B1C(const Quaternion&, const Point&);
}
struct TransformPrefix { char unknown00[8]; };
struct Transform : TransformPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30();
    virtual void setPosition(const Point*);
    char unknown0C[0x84];
};
struct Resource { char unknown00[0x84]; Point position, direction, scale; };
struct Owner {
    char unknown00[0x48];
    float phase;
    Transform transform;
    Point direction, scale;
    char unknownF4[0x10];
    Handle1 reference;
    Handle2 current, previous;
};
struct Registry { char unknown00[0x28]; Handle_801F7F10 handle; };
struct Input {
    char unknown00[4];
    Handle1 first;
    char unknown08[0x1C];
    Handle2 related;
    Handle_801F7F10 other;
};
inline void apply(Owner* self, const Resource* r) {
    self->direction = r->direction;
    self->scale = r->scale;
    self->transform.setPosition(&r->position);
}
inline const Handle_801F7F10& otherHandle(Input* self) { return self->other; }
inline const Handle1& firstHandle(Input* self) { return self->first; }
inline const Handle2& relatedHandle(Input* self) { return self->related; }

extern "C" void fn_801CBDE4(Owner* self, Registry* registry, Input* input, float delta) {
    assign(self->reference, Handle1(firstHandle(input)));
    assign(registry->handle, otherHandle(input));
    Handle2 handle(relatedHandle(input));
    Resource* current = resolve(handle);
    if (!fn_801F7EB8(&self->current)) {
        assign(self->current, handle);
        assign(self->previous, self->current);
        if (current) apply(self, current);
        return;
    }
    Resource* selected = resolve(handle);
    if (selected != resolve(self->current)) {
        assign(self->current, handle);
        self->phase = lbl_8037A448;
    }
    current = resolveSigned(self->current);
    Resource* prior = lookup(self->previous);
    if (prior != lookupSigned(self->current)) {
        self->phase += delta;
        if (self->phase < lbl_8037A44C) {
            Resource* previous = resolve(self->previous);
            float fraction = self->phase / *(const float*)&lbl_8037A44C;
            Point position, scale, blendedPosition;
            Quaternion oldRotation, rotation;
            if (current) {
                position = current->position;
                scale = current->scale;
                rotation = fn_801F27BC(current->direction, Point(lbl_8037A448, lbl_8037A448, lbl_8037A450));
            } else {
                position = game_vec3_zero;
                scale = game_vec3_zero;
                rotation = fn_801F27BC(game_vec3_zero, Point(lbl_8037A448, lbl_8037A448, lbl_8037A450));
            }
            if (previous) {
                Point p0(previous->position.x, previous->position.y, previous->position.z);
                blendedPosition = p0 + (position - p0) * fraction;
                Point s0(previous->scale.x, previous->scale.y, previous->scale.z);
                scale = s0 + (scale - s0) * fraction;
                oldRotation = fn_801F27BC(previous->direction, Point(*(const float*)&lbl_8037A448, lbl_8037A448, lbl_8037A450));
            } else {
                blendedPosition = position * fraction;
                scale *= fraction;
                oldRotation = rotation;
            }
            Point direction = fn_801F1B1C(fn_8008D420(oldRotation, rotation, fraction),
                                          Point(lbl_8037A448, lbl_8037A448, lbl_8037A450));
            self->direction = direction;
            self->scale = scale;
            self->transform.setPosition(&blendedPosition);
        } else {
            assign(self->previous, self->current);
            if (current) apply(self, current);
        }
    }
}
