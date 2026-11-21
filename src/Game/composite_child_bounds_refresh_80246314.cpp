/* auto_03_80246314_text: fn_80246314, composite bounds refresh.
 *
 * For every valid child handle of the owner whose node type is 3 (composite),
 * looks up the matching per-instance state (h -> +0x20 info handle -> info's
 * handle array [i]) and, for each binding of that child whose first group id
 * names a valid, enabled sub-node, transforms the sub-node sphere by the bound
 * bone's world matrix (fn_80099A00) and accumulates it into the owner's bounds
 * (first hit assigns, later hits merge via fn_801F0A20).  Ends with
 * fn_80246798(self).
 *
 * Allocation-sensitive spellings (all verified):
 * - handle resolves use a non-template inline (RES macro casts the void*
 *   result); the template form reorders callee-saved registers;
 * - the bounds pointer is taken through the inline accessor sphere();
 *   &self->bounds gives the same code with three saved registers rotated;
 * - the sub-node id is read as groups.data->id in the validity/flag tests and
 *   as groups[0].id (operator[]) for the sphere lookup, which keeps the
 *   original reload of the id in both branches.
 * Flags: GC/1.3.2 -O4,p -inline auto -Cpp_exceptions off (no extab). */
struct Handle {
    union { unsigned long word; struct { signed int tag : 8, index : 24; } bits; };
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
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
} lbl_801E9D24;

#define RES(T, x) ((T*)resolveAny(x))
inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}

struct Sphere {
    float x, y, z, r;
    Sphere& operator=(const Sphere& o) { x = o.x; y = o.y; z = o.z; r = o.r; return *this; }
};
struct Matrix { float m[16]; };

struct HandleArray { int count, capacity; Handle* data; };
struct Group { short id; char pad02[2]; int count, capacity; void* data; char unknown10[0xC]; };
struct GroupArray {
    int count, capacity;
    Group* data;
    Group& operator[](int i) { return data[i]; }
    const Group& operator[](int i) const { return data[i]; }
};
struct Binding { int bone; GroupArray groups; };
struct BindingArray { int count, capacity; Binding* data; };

struct Flagged { char unknown00[0xC]; unsigned long flags; };
struct WorldObject { char unknown00[0x124]; Matrix* matrix; };
struct State {
    char unknown00[0x20];
    HandleArray bones;
    char unknown2C[0x64 - 0x2C];
    HandleArray handles;
};
struct Info { char unknown00[0x20]; HandleArray handles; };
struct Target { char unknown00[0x20]; Handle info; };
struct Owner {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x6C - 0x1C];
    unsigned short type;
    char unknown6E[0x74 - 0x6E];
    BindingArray bindings;
    HandleArray handles;
    char unknown8C[0xC0 - 0x8C];
    HandleArray children;
    Sphere* sphere() { return &bounds; }
};

extern "C" {
unsigned long fn_801F7EB8(const Handle*);
Sphere fn_80099A00(const Matrix*, const Sphere*);
Sphere fn_801F0A20(const Sphere&, const Sphere&);
void fn_80246798(Owner*);
}

extern "C" void fn_80246314(Owner* self, const Handle& h)
{
    Sphere* bounds = self->sphere();
    signed char found = 0;
    for (int i = 0; i < self->children.count; ++i) {
        if (fn_801F7EB8(&self->children.data[i]) && RES(Owner, self->children.data[i])->type == 3) {
            State* state = RES(State, RES(Info, RES(Target, h)->info)->handles.data[i]);
            Owner* child = RES(Owner, self->children.data[i]);
            for (int j = 0; j < child->bindings.count; ++j) {
                if (fn_801F7EB8(&child->handles.data[child->bindings.data[j].groups.data->id])) {
                    if (!(RES(Flagged, state->handles.data[child->bindings.data[j].groups.data->id])->flags & 1)) {
                        if (!found) {
                            Matrix* m = RES(WorldObject, state->bones.data[child->bindings.data[j].bone])->matrix;
                            *bounds = fn_80099A00(m, &RES(Owner, child->handles.data[child->bindings.data[j].groups[0].id])->bounds);
                        } else {
                            Matrix* m = RES(WorldObject, state->bones.data[child->bindings.data[j].bone])->matrix;
                            *bounds = fn_801F0A20(*bounds, fn_80099A00(m, &RES(Owner, child->handles.data[child->bindings.data[j].groups[0].id])->bounds));
                        }
                        found = 1;
                    }
                }
            }
        }
    }
    fn_80246798(self);
}
